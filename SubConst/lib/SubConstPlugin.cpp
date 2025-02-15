#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "SubConst.h"

using namespace llvm;

void registerAnalyses(FunctionAnalysisManager &FAM) {
        FAM.registerPass([] {
                return subconst::SubConstAnalysis();
        });
}

bool registerPipeline(StringRef Name, FunctionPassManager &FPM,
        ArrayRef<PassBuilder::PipelineElement>) {
                if(Name == "print<sub-const>") {
                        FPM.addPass(subconst::SubConstPrinterPass());
                        return true;
                }
                return false;
}

PassPluginLibraryInfo getAddConstPluginInfo() {
        return {LLVM_PLUGIN_API_VERSION, "SubConst",
                        LLVM_VERSION_STRING, [](PassBuilder &PB) {
                PB.registerAnalysisRegistrationCallback(registerAnalyses);
                PB.registerPipelineParsingCallback(registerPipeline);
                        }};
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
        return getAddConstPluginInfo();
}

