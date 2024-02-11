#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;

namespace {
struct alias_c : public FunctionPass {
  static char ID;
  alias_c() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override {
    // write your code here
    return false;
  }
}; // end of struct alias_c
}  // end of anonymous namespace

char alias_c::ID = 0;
static RegisterPass<alias_c> X("alias_lib_given", "Alias Analysis Pass for Assignment",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
