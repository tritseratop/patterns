# CMakeList.txt : CMake project for singletone, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (template_method "static_template_method.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET strategy PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
