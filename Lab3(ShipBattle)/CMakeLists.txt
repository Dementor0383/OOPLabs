cmake_minimum_required(VERSION 3.17)
project(Lab3_ShipBattle_)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Lab3_ShipBattle_ main.cpp optionparser.h Map.cpp Map.h Helpfunction.cpp Helpfunction.h Define.h Ships.cpp Ships.h Player.cpp Player.h GameCore.cpp GameCore.h RandomPlayer.cpp RandomPlayer.h OptionalPlayer.cpp OptionalPlayer.h ConsolePlayer.cpp ConsolePlayer.h)
target_link_libraries(Lab3_ShipBattle_ ${CMAKE_EXE_LINKER_FLAGS})