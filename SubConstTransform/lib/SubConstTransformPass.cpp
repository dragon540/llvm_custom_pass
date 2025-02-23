#include "SubConstTransform.h"
#include "llvm/IR/Constants.h"

namespace subconstTransform
{
	llvm::PreservedAnalyses SubConstTransformPass::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		auto &res = FAM.getResult<SubConstTransformAnalysis>(F);
		for(auto &i : res) {
			auto first = llvm::cast<llvm::ConstantInt>(i->getOperand(0));
			auto second = llvm::cast<llvm::ConstantInt>(i->getOperand(1));
			auto diff = llvm::ConstantExpr::getSub(first, second);
			i->replaceAllUsesWith(diff);
			i->eraseFromParent();
		}
		auto PA = llvm::PreservedAnalyses::all();
		PA.abandon<SubConstTransformAnalysis>();
		return PA;
	}
}
