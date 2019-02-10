cmake_minimum_required(VERSION 2.8)
project( videoprocessing )

find_package( OpenCV REQUIRED )

include_directories( include )

set(SOURCES src/frameVideo.cpp src/fvideo.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable( frameVideo ${SOURCES} )

target_link_libraries( frameVideo ${OpenCV_LIBS} )
