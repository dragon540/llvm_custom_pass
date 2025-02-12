#include "llvm/IR/PassManager.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Support/Casting.h"
#include "llvm/IR/Constants.h"

using namespace llvm;

namespace addconst {
	struct AddConstAnalysis : public AnalysisInfoMixin<AddConstAnalysis> {
		using Result = llvm::SmallVector<llvm::BinaryOperator *, 0>;
		Result run(llvm::Function &, llvm::FunctionAnalysisManager &);
		static llvm::AnalysisKey Key;
	};

	struct AddConstPrinterPass : public PassInfoMixin<AddConstPrinterPass> {
		explicit AddConstPrinterPass(llvm::raw_ostream &OS)
			:OS_(OS) {} 
		llvm::PreservedAnalyses run(llvm::Function &, llvm::FunctionAnalysisManager &);

	private:
		llvm::raw_ostream &OS_;
	};
}