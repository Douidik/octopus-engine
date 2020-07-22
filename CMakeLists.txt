cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(octopus)
project(application)

include(vendor/RedirectOutputTo.cmake)
RedirectOutputTo("bin")

find_package(PkgConfig)

pkg_search_module(GLEW REQUIRED glew)
include_directories(${GLEW_INCLUDE_DIRS})

pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

pkg_search_module(GLM REQUIRED glm)
include_directories(${GLM_INCLUDE_DIRS})

pkg_search_module(ASSIMP REQUIRED assimp)
include_directories(${ASSIMP_INCLUDE_DIRS})

include_directories(vendor/spdlog/include src/octopus src/application)

add_definitions(-DOCTO_BUILD_DLL)
add_subdirectory(src/octopus)

remove_definitions(-DOCTO_BUILD_DLL)
add_subdirectory(src/application)

target_link_libraries(application PUBLIC octopus)

