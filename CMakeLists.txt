cmake_minimum_required(VERSION 3.10)
project(Projeto_DA_2)
set(CMAKE_CXX_STANDARD 14)

#enable sanitizers
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer")
#set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer")

add_executable(
        Projeto_DA_2
        ../aed-project-2/main.cpp

        ../Projeto_DA_1/src/Menu.cpp ../Projeto_DA_1/src/Menu.h
        #../Projeto_DA_1/src/Railway.cpp ../Projeto_DA_1/src/Railway.h
        #../Projeto_DA_1/src/VertexEdge.cpp ../Projeto_DA_1/src/VertexEdge.h
        #../Projeto_DA_1/src/Graph.h ../Projeto_DA_1/src/Graph.cpp
)

