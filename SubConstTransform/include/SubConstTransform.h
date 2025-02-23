#include "llvm/IR/PassManager.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Support/raw_ostream.h"

namespace subconstTransform
{
	// for carrying out analysis
	class SubConstTransformAnalysis : public llvm::AnalysisInfoMixin<SubConstTransformAnalysis> {
		public:
		using Result = llvm::SmallVector<llvm::Instruction*, 0>;
		Result run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
		static llvm::AnalysisKey Key;
	};

	// for printing result
	class SubConstTransformPrinterPass : public llvm::PassInfoMixin<SubConstTransformPrinterPass> {
		public:
		llvm::PreservedAnalyses run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
	};
}
