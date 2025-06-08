cmake_minimum_required(3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(TBB REQUIRED)


add_executable(pathTrace
    src/main.cpp
    src/camera.cpp
    src/mathUtil.cpp
    src/mats.cpp
    src/objs.cpp
    src/render.cpp
    src/bvh.cpp
)

target_include_directories(pathTrace PRIVATE src)
target_link_libraries(pathtTrace PRIVATE TBB::tbb)


