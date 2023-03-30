# CMakeList.txt : CMake project for radio_propt, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (radio_propt "radio_propt.cpp" "radio_propt.h" "loop.h" "loop.cpp" "loopElem.h" "loopElem.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET radio_propt PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
