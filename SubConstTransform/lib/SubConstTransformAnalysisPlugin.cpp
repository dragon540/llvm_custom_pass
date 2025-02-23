#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "SubConstTransform.h"

using namespace llvm;

void registerAnalyses(FunctionAnalysisManager &FAM) {
	        FAM.registerPass([] {
				                return subconstTransform::SubConstTransformAnalysis();
						        });
}

bool registerPipeline(StringRef Name, FunctionPassManager &FPM,
		        ArrayRef<PassBuilder::PipelineElement>) {
	                if(Name == "print<sub-const-transform-analysis>") {
				                        FPM.addPass(subconstTransform::SubConstTransformPrinterPass());							                        return true;
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

