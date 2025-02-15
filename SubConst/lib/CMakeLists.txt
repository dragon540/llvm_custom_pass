add_library(SubConst MODULE
	SubConstAnalysis.cpp
	SubConstPlugin.cpp)

target_include_directories(SubConst PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/../include")


