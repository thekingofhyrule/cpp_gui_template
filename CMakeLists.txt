#----------------------------------------
#----------Created by TheKingOfHyrule----
#----------05/05/2020--------------------
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")
#----------Fetch Libraries---------------
include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

project(CPP_GUI_TEMPLATE
        VERSION 1.0.0.0
        LANGUAGES C CXX
        )
#----------Get SDL2----------------------
FetchContent_Declare(
        sdl2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG release-2.0.20
        GIT_PROGRESS    TRUE
        )
if(NOT sdl2_POPULATED)
        FetchContent_Populate(sdl2)
        set(SDL_SHARED 0FF)
        set(SDL_STATIC ON)

endif()
FetchContent_GetProperties(sdl2)
FetchContent_MakeAvailable(sdl2)
#----------Get SDL2_IMAGE----------------
#----------SUBDIRECTORIES----------------
add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR} )
#----------------------------------------

add_executable(${PROJECT_NAME} src/main.cpp src/Game.cpp src/Game.h)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${sdl2_SOURCE_DIR}/include
)
target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        -static
        SDL2-static
)
