project(hw_02_library)

add_library(hw_02_library "hwexpressions.cpp" "hwexpressions.h")
add_executable(hw_02_exe "main.cpp" "hwexpressions.cpp")




