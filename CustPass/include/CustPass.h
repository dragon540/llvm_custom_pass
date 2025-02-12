#include "llvm/IR/PassManager.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Support/Casting.h"

namespace custpass
{
	// print all binary instructions
	struct CustPassAnalysis : public llvm::AnalysisInfoMixin<CustPassAnalysis> {
		using Result = llvm::SmallVector<llvm::BinaryOperator *, 0>;
		//bool isBinOp(llvm::Instruction &I);
		Result run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
		static llvm::AnalysisKey Key;
	};

	struct CustPassPrinterPass : public llvm::PassInfoMixin<CustPassPrinterPass> {
		explicit CustPassPrinterPass() {}
		llvm::PreservedAnalyses run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM);
	};
}
