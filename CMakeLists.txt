cmake_minimum_required(VERSION 3.14)
project(commerce)

set(CMAKE_CXX_STANDARD 14)

add_executable(commerce main.cpp Produit.cpp Produit.h Magasin.cpp Magasin.h Livre.cpp Livre.h Cd.cpp Cd.h)