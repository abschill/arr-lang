cmake_minimum_required(VERSION 3.10)
set(project_name arrl)

project(${project_name} VERSION 1.0)

add_executable(${project_name} include/arrlang.c)
set_target_properties(${project_name} PROPERTIES LINKER_LANGUAGE C)

target_include_directories(${project_name} PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/pstyle/lib>
  $<INSTALL_INTERFACE:pstyle/lib>  # <prefix>/include/mylib
)