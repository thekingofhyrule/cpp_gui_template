#----------------------------------------
#----------Created by TheKingOfHyrule----
#----------05/05/2020--------------------

cmake_minimum_required(VERSION 3.2)
project(CPP_GUI_TEMPLATE
        VERSION 1.0.0.0
        LANGUAGES C CXX
        )
#----------SUBDIRECTORIES----------------
add_subdirectory(external/IMGUI)
add_subdirectory(external/SDL)
#----------------------------------------

add_executable(${PROJECT_NAME} src/main.cpp src/main.cpp)