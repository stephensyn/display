cmake_minimum_required(VERSION 3.18)
project(distest C CXX)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(oled)
file(GLOB srcs CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp include/*.h)
add_executable(distest ${srcs}) 
target_include_directories(oled PUBLIC include)#这样才能找到同级的INCLUDE文件夹
# # target_link_directories(distest include)
# # target_sources(distest  ${srcs})                 #SSource是主程序    PBULIC后面跟的是子程序或者库
# # # target_link_libraries(SSource PUBLIC b205)
target_link_libraries(distest PUBLIC oled)