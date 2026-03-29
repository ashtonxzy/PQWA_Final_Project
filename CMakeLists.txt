cmake_minimum_required(VERSION 4.1)
project(PQWA_Final_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(PQWA_Final_Project main.c
        waveform.c
        waveform.h
        io.c
        io.h
)
