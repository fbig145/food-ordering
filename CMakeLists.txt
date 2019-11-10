cmake_minimum_required(VERSION 3.15)
project(food-ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food-ordering main.c index.h index.c DisplayCustomer.h DisplayCustomer.c DisplayItems.c DisplayItems.h DisplayItems.c)