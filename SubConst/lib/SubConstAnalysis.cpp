#include "SubConst.h"

namespace subconst
{
	llvm::AnalysisKey SubConstAnalysis::Key;
	SubConstAnalysis::Result SubConstAnalysis::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		SubConstAnalysis::Result res_;
		for(llvm::BasicBlock &BB : F) {
			for(llvm::Instruction &I : BB) {
				if(I.isBinaryOp()) {
					if(I.getOpcode() == llvm::Instruction::BinaryOps::Sub) {
						if(llvm::isa<llvm::Constant>(I.getOperand(0)) && llvm::isa<llvm::Constant>(I.getOperand(1))) {
							res_.push_back(&llvm::cast<llvm::BinaryOperator>(I));
						}
					}
				}
			}
		}
	   return res_;
	}

	llvm::PreservedAnalyses SubConstPrinterPass::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		llvm::SmallVector<llvm::BinaryOperator *, 0> &result = FAM.getResult<SubConstAnalysis>(F);
		for(auto &i : result) {
			llvm::errs() << *i << "\n";
		}

		return llvm::PreservedAnalyses::all();

	}
}

