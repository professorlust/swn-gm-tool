include_directories(${PROJECT_SOURCE_DIR}/Models/include)

set(SOURCES src/FactionAssetMap.cpp 
    src/FactionControl.cpp)

add_library(FactionControl SHARED ${SOURCES})