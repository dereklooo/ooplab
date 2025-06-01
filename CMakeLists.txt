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
        src/App/App.cpp
        src/App/main.cpp
        src/Mario/Mario.cpp
        src/Monster/Mushroom.cpp
        src/Monster/Turtle.cpp

        include/Object/SceneObject.hpp
        include/Object/Object.hpp
        include/Object/ItemObject.hpp

        include/Monsters/Black_turtle.hpp
        include/Monsters/Fly_turtle.hpp
        include/Monsters/Eat_flower.hpp
        include/Monsters/Kooper.hpp

        include/Block/Pipe_64_128.hpp
        include/Block/LuckyBlock.hpp
        include/Block/LuckyBlock.hpp
        include/Block/FootBlock.hpp
        include/Block/Pipe_64_96.hpp
        include/Block/Pipe_64_64.hpp
        include/Block/OriginalBlock.hpp
        include/Block/AirBlock.hpp

        include/Manager/MapManager.hpp
        include/Manager/GravityManager.hpp
        include/Manager/MarioManager.hpp
        include/Manager/MonsterManager.hpp
        include/Manager/BlockManager.hpp
        include/Manager/ManagerManager.hpp
        include/Manager/ItemManager.hpp
        include/Manager/flagManager.hpp

        include/Item/Mushroom_Item.hpp
        include/Item/Coin_Item.hpp

        include/Mario/Mario.hpp
        src/Manager/BlockManager.cpp
        src/Manager/MonsterManager.cpp
        src/Manager/ItemManager.cpp
        src/Manager/MarioManager.cpp
        include/Object/GravityObject.hpp
        src/Manager/GravityManager.cpp
        src/Manager/MapManager.cpp
        src/Manager/flagManager.cpp
        include/Item/Star_Item.hpp
        src/Item/Mushroom_Item.cpp
        src/Item/Coin_Item.cpp
        src/Item/Star_Item.cpp
        include/Monsters/Turtle.hpp
        include/Block/Pipe.hpp
        src/Block/AirBlock.cpp
        src/Block/FootBlock.cpp
        src/Block/LuckyBlock.cpp
        src/Block/OriginalBlock.cpp
        src/Block/Pipe64_96.cpp
        src/Block/Pipe64_64.cpp
        src/Block/Pipe64_128.cpp
        include/Block/FloorBlock.hpp
        src/Block/FloorBlock.cpp
        include/TimeScore/Timer.hpp
        include/TimeScore/Score.hpp
        include/Manager/TImeScoreManager.hpp
        src/Manager/TimeScoreManager.cpp
        src/TimeScore/Timer.cpp
        src/TimeScore/Score.cpp
        include/Mario/FireBall.hpp
        include/Mario/FireBall.hpp
        src/Mario/FireBall.cpp
        include/Item/FireFlower_Item.hpp
        src/Item/FireFlower_Item.cpp
        include/Manager/FireBallManager.hpp
        src/Manager/FireBallManager.cpp
        include/Block/BlueFloorBlock.hpp
        src/Block/BlueFloorBlock.cpp
        include/Block/BlueFootBlock.hpp
        src/Block/BlueFootBlock.cpp
        include/Block/BlueOriginalBlock.hpp
        src/Block/BlueOriginalBlock.cpp
        include/Block/LongPipe.hpp
        src/Block/LongPipe.cpp
        include/Item/OutSideCoin_Item.hpp
        src/Item/OutSideCoin_Item.cpp
        include/Block/HorizontalPipe_64_64.hpp
        src/Block/HorizontalPipe_64_64.cpp
        include/Map/Map.hpp
        src/Map/Map.cpp
        include/Block/FlagBall.hpp
        include/Block/flagpole.hpp
        src/Block/FlagPole.cpp
        src/Block/FlagBall.cpp
        include/Block/Flag.hpp
        src/Block/Flag.cpp
        include/Block/GrassFloorLeft.hpp
        include/Block/grassfloormid.hpp
        include/Block/GrassFloorRight.hpp
        src/Block/GrassFloorRight.cpp
        src/Block/GrassFloorLeft.cpp
        src/Block/GrassFloorMid.cpp
        include/Block/TreeWall.hpp
        src/Block/TreeWall.cpp
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
