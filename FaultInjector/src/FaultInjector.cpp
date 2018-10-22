/* This fault injector is for Bayesian Fault Injector */
#define DEBUG_TYPE "Bernard's Fault Injector for Bayesian Fault Model"
#include <iostream>
#include <fstream>
#include "llvm/Pass.h"
#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Metadata.h"
#include "llvm/Support/Debug.h"
#include <cxxabi.h>
#include <llvm/Analysis/AliasAnalysis.h>
#include <llvm/Analysis/MemoryDependenceAnalysis.h>
#include <llvm/Analysis/DependenceAnalysis.h>
#include "boost/algorithm/string.hpp"
#include "SharedFaultEngine.h"

/** TODO:
 *

 *
 * */

using namespace llvm;
namespace {
    class FaultInjector: public ModulePass{
    public:

        static char ID;
        SharedFaultEngine *sharedFaultEngine;
        FaultInjector():ModulePass(ID){

        }
       bool runOnModule(Module &M);
        bool runOnFunction(Function &F);
        std::string demangle(std::string name);

        bool doInitialization(Module &module) override;

        bool doFinalization(Module &module) override;

        void getAnalysisUsage(AnalysisUsage &AU) const override {
            AU.setPreservesAll();
        }
    };
}





std::string FaultInjector::demangle(std::string name) {
    int status;
    std::string demangled;
    char* tmp = abi::__cxa_demangle(name.c_str(), NULL, NULL, &status);
    if (tmp == NULL)
        return name;

    demangled = tmp;
    free(tmp);
    /* drop the parameter list as we only need the function name */
    return demangled.find("(") == std::string::npos ? demangled : demangled.substr(0, demangled.find("("));

}

bool FaultInjector::runOnModule(Module &M) {


    for(Module::iterator F=M.begin(), E = M.end();F!=E;++F){

            runOnFunction(*F);
    }

    return false;
}

bool FaultInjector::runOnFunction(Function &F) {


    bool  isModified= false;
    std::string functionName = demangle(F.getName().str());
    StringRef originalFunctionName=F.getName();

    if(!sharedFaultEngine->isThreadRoutine(originalFunctionName))
        return false;


    // Target GloBal Var
    GlobalValue *GV=sharedFaultEngine->getGlobalValueByName("count");
    std::set<Instruction*> worklist;
    for(auto U:GV->users()){
        if(Instruction *instruction= dyn_cast<Instruction>(U)){
            if(instruction->getFunction()->getName().equals(originalFunctionName))
            worklist.insert(instruction);
        }
    }

    /*
     * Instruction Builder
     *
     */

    BasicBlock &EntryBB=F.getEntryBlock();

    Instruction &entryIns=  EntryBB.front();



    AllocaInst *GV_local=new AllocaInst(GV->getValueType(),0,GV->getName()+"_local",&entryIns);




    // Blacklist function : Skip instrumentation on the following functions, need to shift to a file and proper data structure
  //  if(functionName.compare("srand")==0 || functionName.compare("SRAND")==0 || functionName.compare("LOAD")==0 || functionName.compare("main")==0  || functionName.compare("STORE")==0 || functionName.compare("injectError32IntData")==0 ||  functionName.compare("PRINT")==0  ||  functionName.compare("flipBitOnIntegerValue") ==0|| functionName.compare("randr")==0 || functionName.compare("flipBits")==0 || functionName.compare("srand")==0 || functionName.compare("rand")==0 || functionName.compare("time")==0 || functionName.compare("llvm.dbg.declare")==0) return false;

    LLVMContext &Context = F.getContext();



    // return true if change made to IR else false

    // Create a local variable for the global data

    // Locate usage of global variable within a function

    // Create local variable of the same type as the GV
    GV->dump();
if ( GlobalVariable *G = dyn_cast<GlobalVariable>(GV)) {
     Constant *constant = G->getInitializer();

    if(constant->getType()->isIntegerTy()){
         ConstantInt* constInt = cast<ConstantInt>( constant);
        int64_t constIntValue = constInt->getSExtValue();
        errs()<<"Val="<<constIntValue;
    }
    constant->dump();
}
else{
    GV->getType()->dump();
    GV_local->getType()->dump();
    // Load the Global Variable some where here and Store it to GV Local
    LoadInst * loadInst = new LoadInst(GV,GV->getName()+"_load",GV_local->getNextNode());

    Value* loadedValue = new StoreInst(loadInst,GV_local,loadInst->getNextNode());

    loadedValue->dump();
    errs()<<"Not constant";

/*
 *
 * clang  -std=c++11  -g -emit-llvm -c hello.c -o hello.bc
llvm-link  runtime.bc hello.bc -S -o insthello.bc

 *
 *
 */



    // Worklist ready

        for(Instruction *instruction:worklist){

            // Modify the instruction
            for(int i=0;i<instruction->getNumOperands();i++){

                if(instruction->getOperand(i)->getName().equals(GV->getName()))
                {
                    instruction->setOperand(i,GV_local);

                }
            }

        }


}
    //GV->getValueType()->dump();



    // Load instruction copy values form  GV

    // For every accurent of GV replace it with GV_local




    F.dump();




    // Insert the last assignment here, GV = GV_local
    Instruction *lastIns=&F.back().back();
    lastIns->dump();
    // Need to load Data and the use store
    LoadInst * loadInstLocal = new LoadInst(GV_local,GV_local->getName()+"_load",lastIns);
    StoreInst *st=new StoreInst(loadInstLocal,GV,lastIns);

// Succeed Hurray!

    return isModified;

}





bool FaultInjector::doFinalization(Module &module) {
    // Here write to a file
    std::ofstream myfile;
    myfile.open ("varinfo.out");



    myfile.close();

    return true;
}

bool FaultInjector::doInitialization(Module &module) {

    // Find Global Variable Declaration

    sharedFaultEngine=new SharedFaultEngine();

    sharedFaultEngine->initialize(&module);

    sharedFaultEngine->processThreadRoutines();

    return Pass::doInitialization(module);
}


char FaultInjector::ID = 0;
static RegisterPass<FaultInjector> X("FaultInjector","LLVM fault Injector",false, true);




