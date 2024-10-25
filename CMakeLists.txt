cmake_minimum_required(VERSION 3.21)
project(bm-gui LANGUAGES C CXX)

# Set target directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin/)

# Find slint installation
find_package(${CMAKE_CURRENT_LIST_DIR}/deps/slint-1.8/lib/cmake/Slint/Slint REQUIRED)

add_executable(bm-gui 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/bm.cpp
    )

target_link_libraries(bm-gui PRIVATE 
    Slint::Slint
    ${CMAKE_SOURCE_DIR}/deps/ddc-driver/lib/libemacepl.a)

slint_target_sources(bm-gui ui/app-window.slint)

target_include_directories(bm-gui PUBLIC ${INCLUDEDIRS}
    ${CMAKE_SOURCE_DIR}/deps/ddc-driver/include/emacepl
    ${CMAKE_SOURCE_DIR}/deps/ddc-driver/include/ddcacex)