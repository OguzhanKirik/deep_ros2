cmake_minimum_required(VERSION 3.5)
project(br2_clearpath)

find_package(ament_cmake REQUIRED)

install(DIRECTORY  launch
        DESTINATION share/${PROJECT_NAME})

ament_package()
