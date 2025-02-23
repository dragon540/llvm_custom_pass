#include "SubConstTransform.h"

namespace subconstTransform
{
	llvm::AnalysisKey SubConstTransformAnalysis::Key;
	SubConstTransformAnalysis::Result SubConstTransformAnalysis::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		SubConstTransformAnalysis::Result res;
		for(llvm::BasicBlock & BB : F) {
			for(llvm::Instruction & I : BB) {
				if(I.getOpcode() == llvm::Instruction::Sub)
					res.push_back(&llvm::cast<llvm::BinaryOperator>(I));
			}
		}

		return res;
	}


	llvm::PreservedAnalyses SubConstTransformPrinterPass::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		//llvm::SmallVector<llvm::Instruction> fin;
		auto & fin = FAM.getResult<SubConstTransformAnalysis>(F);
		for(auto &i : fin) {
			llvm::outs() << i->getOpcodeName() << "\n";
		}

		return llvm::PreservedAnalyses::all();
	}

};
