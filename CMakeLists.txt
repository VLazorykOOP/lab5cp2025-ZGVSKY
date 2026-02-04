cmake_minimum_required(VERSION 3.29)
project(practice)

set(CMAKE_CXX_STANDARD 17)


include_directories(op_lab_5) #  laba4 op_lab_1 op_lab_2

# Збираємо проект, перелічуючи ВСІ файли
add_executable(MainProject
        main.cpp
        #op_lab_1/Lab1.cpp
        #op_lab_1/lab1_main.cpp
        #op_lab_2/Building.cpp
        #op_lab_2/lab2_entry.cpp
        op_lab_5/lab5_entry.cpp
        op_lab_5/Lab5_Math.cpp

)

target_link_libraries(MainProject gdi32 user32)