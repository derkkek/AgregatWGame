cmake_minimum_required(VERSION 3.14...3.31)

project( Agregat-42 LANGUAGES CXX C )

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.0
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog/
    GIT_TAG v1.15.3
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    )
FetchContent_MakeAvailable( spdlog )

add_library(Agregat-42 STATIC src/Engine.cpp)
set_target_properties( Agregat-42 PROPERTIES CXX_STANDARD 20 )

target_include_directories(Agregat-42 PUBLIC src)
target_link_libraries(Agregat-42 PUBLIC raylib)
target_link_libraries( Agregat-42 PRIVATE spdlog::spdlog )

add_executable(BoxOvertop Game/game.cpp)
set_target_properties(BoxOvertop PROPERTIES CXX_STANDARD 20)
target_link_libraries(BoxOvertop PRIVATE Agregat-42)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()