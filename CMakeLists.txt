# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("patterns")

# Include sub-projects.
add_subdirectory ("singletone")
add_subdirectory ("strategy")
add_subdirectory ("template_method")
