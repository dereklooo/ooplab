cmake_minimum_required(VERSION 3.16)
project(REPLACE_WITH_YOUR_PROJECT_NAME)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    ptsd

    URL         https://github.com/ntut-open-source-club/practical-tools-for-simple-design/archive/refs/tags/v0.2.zip

    # Or alternatively if you want to use a specific git commit instead of a release:
    # GIT_REPOSITORY  https://github.com/ntut-open-source-club/practical-tools-for-simple-design.git
    # GIT_TAG         <git_tag>

    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/PTSD
)

FetchContent_MakeAvailable(ptsd)

include(files.cmake)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)

# file(GLOB_RECURSE SRC_FILES src/*)
# file(GLOB_RECURSE HEADER_FILES include/*)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Mario_big.cpp
    ${SRC_DIR}/Mario_small.cpp
    ${SRC_FILES}
    ${HEADER_FILES}
        include/Monsters/Black_turtle.hpp
        include/Monsters/Fly_turtle.hpp
        include/Monsters/Eat_flower.hpp
        include/Monsters/Kooper.hpp
        src/Mushroom.cpp
        src/Turtle.cpp
        include/Object/SceneObject.hpp
        include/Block/Pipe_64_128.hpp
        include/Block/LuckyBlock.hpp
        include/Block/LuckyBlock.hpp
        include/Block/FootBlock.hpp
        include/Block/Pipe_64_96.hpp
        include/Block/Pipe_64_64.hpp
        include/Block/OriginalBlock.hpp
        include/Mario/Mario_fire.hpp
        include/Mario/Mario_big.hpp
        include/Mario/Mario_small.hpp
        src/Mario_small.cpp
        src/Mario_big.cpp
        include/Manager/MapManager.hpp
        include/Manager/GravityManager.hpp
        include/Object/Object.hpp
        include/Block/AirBlock.hpp
        src/Mario.cpp
        include/Object/ItemObject.hpp
        "include/Item/Mushroom_Item .hpp"
        include/Item/Coin_Item.hpp
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    message(FATAL_ERROR "relative RESOURCE_DIR is WIP, Please use `-DCMAKE_BUILD_TYPE=Debug` build for now.")
    # target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2main
    PTSD
)
