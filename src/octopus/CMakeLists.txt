file(GLOB_RECURSE OCTOPUS_SOURCE  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE OCTOPUS_HEADER  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

#Building Octopus Game Engine
add_library(octopus SHARED ${OCTOPUS_SOURCE} ${OCTOPUS_HEADER})
target_link_libraries(octopus PUBLIC ${GLFW_LIBRARIES}
                                     ${GLEW_LIBRARIES}
                                     ${OPENGL_LIBRARIES}
                                     ${ASSIMP_LIBRARIES}
                                     ${GLM_LIBRARIES}
                                     ${SPDLOG_LIBRARIES}
                                     ${YAML_LIBRARIES})

target_precompile_headers(octopus PUBLIC OctopusPCH.h)