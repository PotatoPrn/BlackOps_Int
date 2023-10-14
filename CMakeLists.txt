cmake_minimum_required(VERSION 3.26)
project(Blops_Internal)

set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH "../")
include_directories(include)

# Include Graphics Stuff
# Blops uses DirectX9
include_directories("C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include")
link_directories("C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86")

set (Utils
        src/Utils/MemUtils.cpp
        src/Utils/UiUtils.cpp
        src/Utils/HelperUtils.cpp
        src/Utils/ProcessUtils.cpp
)

set (MainRoutine
        main.cpp
        src/MainHackThread.cpp
        src/HackList.cpp
)

set (GraphicsUtils
        src/GraphicsUtils/Draw.cpp
        src/Utils/HookUtil.cpp
        src/GraphicsUtils/Directx.cpp
)

add_library(${PROJECT_NAME} SHARED
        ${MainRoutine}
        ${Utils}
        ${GraphicsUtils}

)