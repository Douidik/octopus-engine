file(GLOB_RECURSE APP_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE APP_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(application ${APP_SOURCE} ${APP_HEADER})

target_include_directories(application PUBLIC ${PROJECT_SOURCE_DIR}/src/octopus)