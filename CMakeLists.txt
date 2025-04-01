# Example call of HiGHS from another cmake project.

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)

project(LOAD_HIGHS LANGUAGES CXX)


# set(HIGHS_DIR /Users/ivet/installs/highs/lib/cmake/highs/)

# find_package(Threads REQUIRED)
find_package(HIGHS REQUIRED)

add_executable(main call_from_cpp.cc)

target_link_libraries(main highs::highs)