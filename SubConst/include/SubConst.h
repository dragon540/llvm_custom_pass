#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/PassManager.h"

namespace subconst
{

	struct SubConstAnalysis : public llvm::AnalysisInfoMixin<SubConstAnalysis> {
		using Result = llvm::SmallVector<llvm::BinaryOperator *, 0>;
		Result run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
		static llvm::AnalysisKey Key;	
	};

	struct SubConstPrinterPass : public llvm::PassInfoMixin<SubConstPrinterPass> {
		llvm::PreservedAnalyses run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
	};
}


