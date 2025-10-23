# Example call of HiGHS from another cmake project.

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 11)

project(LOAD_HIGHS LANGUAGES CXX)


# set(HIGHS_DIR /Users/ivet/installs/highs/lib/cmake/highs/)

# find_package(Threads REQUIRED)
option(USE_HIPO OFF)
if (USE_HIPO)
    message(STATUS "HIPO IS ON")
    find_package(BLAS REQUIRED)
    if (BLAS_FOUND)
        message(STATUS "BLAS FOUND")
        message(STATUS "BLAS_LIBRARIES: " ${BLAS_LIBRARIES})
    endif()
endif()

find_package(HIGHS REQUIRED)

add_executable(main call_from_cpp.cc)

target_link_libraries(main highs::highs)

install(TARGETS main)