cmake_minimum_required(VERSION 3.26)
project(Blops_Internal)

set(CMAKE_CXX_STANDARD 20)

set(LIBRARY_OUTPUT_PATH "../")
include_directories(include)

add_library(${PROJECT_NAME} SHARED main.cpp
        src/Utils/MemUtils.cpp
        src/Utils/UiUtils.cpp
        src/MainHackThread.cpp
        src/Utils/HelperUtils.cpp
        src/Utils/ProcessUtils.cpp
        src/HackList.cpp


)