cmake_minimum_required(VERSION 3.10)
project(Composer)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Composer
    src/main.cpp
    src/Project.cpp
    src/Layer.cpp
    src/Image.cpp
    src/Pixel.cpp
    src/filter/Filter.cpp
    src/BlendMode.cpp
    src/Commands.cpp
)