cmake_minimum_required(VERSION 2.8)

if(NOT CMAKE_BUILD_TYPE)
    message("** CMAKE_BUILD_TYPE not passed. Assuming Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG("-std=c++11" CXX_HAS_CPP11)
if(CXX_HAS_CPP11)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")
endif()

CHECK_CXX_COMPILER_FLAG("-pedantic" CXX_HAS_PENDANTIC)
if(CXX_HAS_PENDANTIC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -pedantic")
endif()

CHECK_CXX_COMPILER_FLAG("-Wall" CXX_HAS_WALL)
if(CXX_HAS_WALL)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
endif()

CHECK_CXX_COMPILER_FLAG("-Wextra" CXX_HAS_WEXTRA)
if(CXX_HAS_WEXTRA)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wextra")
endif()

CHECK_CXX_COMPILER_FLAG("-g" CXX_HAS_G)
if(CXX_HAS_G)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

CHECK_CXX_COMPILER_FLAG("-g0" CXX_HAS_g0)
if(CXX_HAS_g0)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g0")
endif()

CHECK_CXX_COMPILER_FLAG("-O3" CXX_HAS_O3)
if(CXX_HAS_O3)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()


add_subdirectory(ArrayPairSum)
add_subdirectory(MatrixRegionSum)
add_subdirectory(LargestContinuousSum)
add_subdirectory(FindMissingElement)