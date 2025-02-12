//#include "llvm/Passes/PassPlugin.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "CustPass.h"

using namespace llvm;

void registerAnalyses(llvm::FunctionAnalysisManager &FAM) {
	FAM.registerPass([] {
			return custpass::CustPassAnalysis();
			});
}

bool registerPipeline(llvm::StringRef Name, llvm::FunctionPassManager &FPM, ArrayRef<PassBuilder::PipelineElement>) {
	if(Name=="print<cust-pass>") {
		FPM.addPass(custpass::CustPassPrinterPass());
		return true;
	}
	return false;
}

PassPluginLibraryInfo getCustPluginInfo() {
	return {LLVM_PLUGIN_API_VERSION, "CustPass", LLVM_VERSION_STRING, [](PassBuilder &PB) {
		PB.registerAnalysisRegistrationCallback(registerAnalyses);
		PB.registerPipelineParsingCallback(registerPipeline);
	}};
}

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
	return getCustPluginInfo();
}
