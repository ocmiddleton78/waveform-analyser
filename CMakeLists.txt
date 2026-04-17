cmake_minimum_required(VERSION 3.21)
project(Code C)

set(CMAKE_C_STANDARD 99)

add_executable(Code main.c waveform.c io.c waveform.h io.h)
