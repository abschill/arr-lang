cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(arrl C)
add_subdirectory(pstyle)
add_executable(arrl include/arrlang.c)