#include "AddConst.h"

using namespace llvm;

namespace addconst {
	AnalysisKey AddConstAnalysis::Key;

	bool isConstantIntOnly(Instruction &I) {
		for(Use &Op : I.operands()) {
			if(!isa<ConstantInt>(Op)) return false;
		}
		return true;
	}

	AddConstAnalysis::Result AddConstAnalysis::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		SmallVector<BinaryOperator *, 0> AddInsts;
		for(BasicBlock &BB : F) {
			for(Instruction &I : BB) {
				if(!I.isBinaryOp()) {
					continue;
				}
				else {
					if(!I.getOpcode() == Instruction::BinaryOps::Add) {
						continue;
					}
					else {
						if(!isConstantIntOnly(I)) {
							continue;
						}
						else {
							AddInsts.push_back(&cast<BinaryOperator>(I));
						}
					}
				}
			}
		}
		return AddInsts;
	}

	PreservedAnalyses AddConstPrinterPass::run(llvm::Function &F, llvm::FunctionAnalysisManager &FAM) {
		auto &AddInsts = FAM.getResult<AddConstAnalysis>(F);
		OS_ << F.getName() << "\n";
		OS_ << "======================\n";
		for(auto &Add : AddInsts) {
			OS_ << *Add << "\n" ;
		}
		OS_ << "=========+============\n";
		return PreservedAnalyses::all();
	}
}