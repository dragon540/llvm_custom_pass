#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "AddConst.h"

using namespace llvm;

void registerAnalyses(FunctionAnalysisManager &FAM) {
	FAM.registerPass([] {
		return addconst::AddConstAnalysis();
	});
}

bool registerPipeline(StringRef Name, FunctionPassManager &FPM,
	ArrayRef<PassBuilder::PipelineElement>) {
		if(Name == "print<add-const>") {
			FPM.addPass(addconst::AddConstPrinterPass(errs()));
			return true;
		}
		return false;
}

PassPluginLibraryInfo getAddConstPluginInfo() {
	return {LLVM_PLUGIN_API_VERSION, "AddConst",
			LLVM_VERSION_STRING, [](PassBuilder &PB) {
		PB.registerAnalysisRegistrationCallback(registerAnalyses);
		PB.registerPipelineParsingCallback(registerPipeline);	
			}};   
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
	return getAddConstPluginInfo();
}