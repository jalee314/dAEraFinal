CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(dAEraGame)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/header)

ADD_EXECUTABLE(dAEra
    src/main.cpp
    src/Basar.cpp
    src/battleActions.cpp
    src/Enemy.cpp
    src/Environment.cpp
    src/Room.cpp
    src/Hallway.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/Journal.cpp
    src/MainMenu.cpp
    src/Map.cpp
    src/NPC.cpp
    src/Page.cpp
    src/playerCharacter.cpp    
)

TARGET_COMPILE_OPTIONS(dAEra PRIVATE -O0 -std=c++11) 
