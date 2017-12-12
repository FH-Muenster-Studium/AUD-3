cmake_minimum_required(VERSION 3.9)
project(AUD_3 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-fsanitize=address -fsanitize-address-use-after-scope -O1 -fno-omit-frame-pointer")

add_executable(AUD_3 main.c aud-3.c aud-3.h)