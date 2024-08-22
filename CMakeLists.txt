# Example call of HiGHS from another cmake project.

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)

project(LOAD_HIGHS LANGUAGES CXX)

# WIP
# # Make project-provided Find modules available
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# set(HiGHS_DIR /Users/ivet/installs/highs)
set(HIGHS_DIR /home/ivet/installs/highs/lib/cmake/highs)

find_package(HIGHS REQUIRED)

add_executable(main call_highs_instance.cc)

target_link_libraries(main highs::highs)