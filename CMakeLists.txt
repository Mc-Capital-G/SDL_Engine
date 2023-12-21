cmake_minimum_required(VERSION 3.26.0)

project(SDL_Engine)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

add_executable(${PROJECT_NAME} main.cpp ${SRC} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer SDL2_ttf::SDL2_ttf)

