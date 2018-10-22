//
// Created by Bernard on 25/9/18.
//

#ifndef PROJECT_SHAREDFAULTENGINE_H
#define PROJECT_SHAREDFAULTENGINE_H
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
#include "llvm/ADT/SmallVector.h"

using namespace llvm;

#define PTHREAD_CREATE pthread_create

class SharedFaultEngine{

private:
     llvm::Module *module;
    std::set<StringRef> globalVariableNames;
    std::map<StringRef, GlobalValue*> globalThreadSharedVariables; // This Set is a collection of global shared variable which is used in Thread routine

    std::set<StringRef> threadfunctionNames;
    std::map<StringRef,GlobalVariable&> globalVariableMap;
    void collectGlobalThreadSharedVariables();
    void collectThreadFunctionNames();
    void processPthreadAnalysis();


public:
    void initialize( llvm::Module *module);
    void processCallInst(CallInst *callInst);
    void processThreadRoutines();
    void convertGlobalThreadVarsToLocalThreadVars();
    bool isThreadRoutine(StringRef functionName);
    GlobalValue * getGlobalValueByName(StringRef varName);



};



#endif //PROJECT_SHAREDFAULTENGINE_H
