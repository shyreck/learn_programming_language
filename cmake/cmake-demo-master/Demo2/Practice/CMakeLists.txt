cmake_minimum_required(VERSION 2.8) 
project(add_two_int)
aux_source_directory(. DIR_SRCS)    
add_executable(add_two_int ${DIR_SRCS})
