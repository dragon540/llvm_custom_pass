add_library(SubConstTransform MODULE
	SubConstTransformAnalysis.cpp
	SubConstTransformPass.cpp
	SubConstTransformAnalysisPlugin.cpp)

target_include_directories(SubConstTransform PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/../include")
