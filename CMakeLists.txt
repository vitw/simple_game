cmake_minimum_required(VERSION 3.5)

project(game)

include_directories("./")
add_executable(game main.cpp Creature.cpp Monster.cpp Player.cpp)
