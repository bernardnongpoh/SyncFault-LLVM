//
// Created by bernard on 25/9/18.
//

#include "SharedVarDiscoEngine.h"

void SharedVarDiscoEngine::initialize( llvm::Module *module) {
    this->module=module;


    collectThreadFunctionNames();
    processPthreadAnalysis();
    collectGlobalThreadSharedVariables();

}

void SharedVarDiscoEngine::processPthreadAnalysis() {

    for(auto &F:*module){
        for(auto &B:F){
            for(auto &I:B){
                if (CallInst *callInst = dyn_cast<CallInst>(&I)) {
                    processCallInst(callInst);

                }
            }
        }
    }
}

void SharedVarDiscoEngine::collectGlobalThreadSharedVariables() {

    for (Module::global_iterator I = module->global_begin(), E = module->global_end();
         I != E; ++I) {


        for (auto U : I->users()) {

            if (auto ins = dyn_cast<Instruction>(U)) {

                if(threadfunctionNames.find(ins->getFunction()->getName())!=threadfunctionNames.end()){
                    // Shared Global Variable
                    if( GlobalValue *G=dyn_cast<GlobalValue>(I)){
                        globalThreadSharedVariables[G->getName()]=G;
                    }


                }
            }
            // Todo : printf is not an instruction fo @str user
        }

    }



}

void SharedVarDiscoEngine::collectThreadFunctionNames() {

    for (Module::const_iterator I = module->begin(), E = module->end(); I != E; ++I) {

       // I->dump();
    }

}

 GlobalValue* SharedVarDiscoEngine::getGlobalValueByName(StringRef varName) {
       // Loop through all and
    return this->globalThreadSharedVariables[varName];
}

void SharedVarDiscoEngine::processCallInst(CallInst *callInst) {

    /*
     *   int pthread_create(pthread_t * thread,const pthread_attr_t * attr,void * (*start_routine)(void *),void *arg);
    */

    if(!callInst->getCalledValue()->getName().equals("pthread_create"))
        return;

    StringRef calledFunctionName=callInst->getOperand(2)->getName();
    // Insert into a set
    threadfunctionNames.insert(calledFunctionName);


}

void SharedVarDiscoEngine::processThreadRoutines() {

    for(StringRef functionName:threadfunctionNames){

        Function *function=this->module->getFunction(functionName);
        for(auto &B:*function){
            B.dump();
        }

    }






}

void  SharedVarDiscoEngine::convertGlobalThreadVarsToLocalThreadVars() {


}

bool SharedVarDiscoEngine::isThreadRoutine(StringRef functionName) {
    if(this->threadfunctionNames.find(functionName)!=this->threadfunctionNames.end())
        return true;
    return false;
}

std::map<StringRef,GlobalValue*> SharedVarDiscoEngine::getGlobalThreadSharedVariables() {
    return globalThreadSharedVariables;
}


