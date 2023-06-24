cmake_minimum_required(VERSION 3.18)
project(oled) 
set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_C_COMPILER gcc)
# 设置编译选项

option(USE_BCM2835_LIB "Use BCM2835 library" OFF)   #OK
option(USE_WIRINGPI_LIB "Use WiringPi library" ON) #OK
option(USE_DEV_LIB "Use DEV library" OFF)#仍有错误不能运行

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall ${DEBUG}")
# 设置编译器
set(BCM2835_LIB_NAME bcm2835)
set(WIRINGPI_LIB_NAME wiringPi)

find_library(BCM2835_LIB ${BCM2835_LIB_NAME})

find_library(WIRINGPI_LIB ${WIRINGPI_LIB_NAME})



# 添加依赖库

# if(USE_BCM2835_LIB)
#     add_definitions(-DUSE_BCM2835_LIB)
#     target_link_libraries(oled ${BCM2835_LIB} m)
# elseif(USE_WIRINGPI_LIB)
#     add_definitions(-DUSE_WIRINGPI_LIB)
#     target_link_libraries(oled wiringPi m) 
# elseif(USE_DEV_LIB)
#     add_definitions(-DUSE_DEV_LIB)
#     target_link_libraries(oled your_dev_lib)
# endif()






file(GLOB_RECURSE srcs-c CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.c include/*.h)
file(GLOB_RECURSE srcs-cpp CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp )

message("源文件：" ${srcs})

add_library(oled STATIC ${srcs-c} ${srcs-cpp})
# target_sources(oled PUBULIC ${srcs})

 

if(USE_BCM2835_LIB)
    # add_definitions(-DUSE_BCM2835_LIB)
    # add_compile_definitions(-DUSE_BCM2835_LIB)
    target_compile_definitions(oled PRIVATE USE_BCM2835_LIB)
    target_link_libraries(oled ${BCM2835_LIB} m)
elseif(USE_WIRINGPI_LIB)
    # add_definitions(-DUSE_WIRINGPI_LIB)
    # add_compile_definitions(-DUSE_WIRINGPI_LIB)
    target_compile_definitions(oled PRIVATE USE_WIRINGPI_LIB)
    target_link_libraries(oled ${WIRINGPI_LIB} m)
    # target_link_libraries(oled wiringPi m)
elseif(USELIB STREQUAL USE_DEV_LIB)
    add_definitions(-DUSE_DEV_LIB)
    target_link_libraries(oled m)
endif()


target_include_directories(oled PUBLIC include)