# CMakeList.txt : CMake project for wite-cmake-example, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include(FetchContent) # once in the project to include the module

FetchContent_Declare(wite
	URL https://github.com/kevinchannon/wite.git
	GIT_TAG v0.12.0
)

FetchContent_MakeAvailable(wite)

# Add source to this project's executable.
add_executable (wite-cmake-example
	"wite-cmake-example.cpp"
)
set_property(TARGET wite-cmake-example PROPERTY CXX_STANDARD 20)

target_include_directories(wite-cmake-example
	PRIVATE
		${wite_SOURCE_DIR}
)

