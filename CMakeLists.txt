cmake_minimum_required(VERSION 4.1)
project(PQWA_Final_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(PQWA_Final_Project src/main.c
        src/waveform.c
        include/waveform.h
        src/io.c
        include/io.h
)
