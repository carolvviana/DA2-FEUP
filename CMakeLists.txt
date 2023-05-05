cmake_minimum_required(VERSION 3.10)
project(Projeto_DA_2)
set(CMAKE_CXX_STANDARD 14)

#enable sanitizers
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer")
#set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer")

add_executable(
        Projeto_DA_2
        main.cpp

        src/Menu.cpp src/Menu.h

        src/TSP.h src/TSP.cpp
        src/Graph.h src/Graph.cpp
        src/VertexEdge.h src/VertexEdge.cpp)

