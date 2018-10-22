/* Shared Variable Discovery for Multithreaded application implemented using POSIX/PThread C++ API */
#define DEBUG_TYPE "Shared Variable Discovery for Multithreaded application implemented using POSIX/PThread C++ API"
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
#include "SharedVarDiscoEngine.h"

/** TODO:
 *

 *
 * */

using namespace llvm;
namespace {
    class SharedVarDisco: public ModulePass{
    public:

        static char ID;
        SharedVarDiscoEngine *sharedVarDiscoEngine;

        SharedVarDisco():ModulePass(ID){

        }
       bool runOnModule(Module &M);

        std::string demangle(std::string name);

        bool doInitialization(Module &module) override;

        bool doFinalization(Module &module) override;

        void getAnalysisUsage(AnalysisUsage &AU) const override {
            AU.setPreservesAll();
        }
    };
}





std::string SharedVarDisco::demangle(std::string name) {
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

bool SharedVarDisco::runOnModule(Module &M) {


    for(Module::iterator F=M.begin(), E = M.end();F!=E;++F){


    }

    return false;
}





bool SharedVarDisco::doFinalization(Module &module) {
    // Here write to a file
    std::ofstream myfile;

    // This file is the output of this pass. It output all shared variables discovered during the pass
    myfile.open ("sharedvariables.dat");
    std::map<StringRef,GlobalValue*> sharedVars = sharedVarDiscoEngine->getGlobalThreadSharedVariables();

    std::map<StringRef,GlobalValue*>::iterator it;

    // Todo: Need to identify at the Class Scope, Function scope as well to avoid ambiguity.

    for(it=sharedVars.begin();it!=sharedVars.end();it++){
        myfile<<(*it).first.str()<<"";
    }


    myfile.close();

    return true;
}

bool SharedVarDisco::doInitialization(Module &module) {

    sharedVarDiscoEngine=new SharedVarDiscoEngine();

    sharedVarDiscoEngine->initialize(&module);
    sharedVarDiscoEngine->processThreadRoutines();



    return Pass::doInitialization(module);
}


char SharedVarDisco::ID = 0;
static RegisterPass<SharedVarDisco> X("SharedVarDisco","Shared Variable Discovery for multithreaded application implemented using POSIX/PThread C++ API",false, true);




