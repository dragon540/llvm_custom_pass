add_library(CustPass MODULE
	CustPassAnalysis.cpp  
	CustPassPlugin.cpp)

target_include_directories(CustPass PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/../include")

