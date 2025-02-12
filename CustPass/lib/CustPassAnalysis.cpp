#include "CustPass.h"

namespace custpass
{
	llvm::AnalysisKey CustPassAnalysis::Key;


        bool isBinOp(llvm::Instruction &I) {
                if(I.isBinaryOp())
                        return true;
                return false;
        }

	CustPassAnalysis::Result CustPassAnalysis::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		llvm::errs() << F.getName() << "\n";
		llvm::SmallVector<llvm::BinaryOperator *, 0> res;
		for(llvm::BasicBlock &BB : F) {
			for(llvm::Instruction &I : BB) {
				if(isBinOp(I)) {
					res.push_back(&llvm::cast<llvm::BinaryOperator>(I));
				}
				else {
					llvm::errs() << "Encountered instruction is not binary\n";
				}
			}
		}
		return res;
	}

/**	bool isBinOp(llvm::Instruction &I) {
               if(I.isBinaryOp())
                        return true;
                return false;
        }
**/

	llvm::PreservedAnalyses CustPassPrinterPass::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		auto &res = FAM.getResult<CustPassAnalysis>(F);
		for(auto &i : res) {
			llvm::errs() << *i << "\n";
		}
		return llvm::PreservedAnalyses::all();
	}	
}
