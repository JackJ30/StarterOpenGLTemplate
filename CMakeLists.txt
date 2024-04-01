cmake_minimum_required(VERSION 3.1.0)
project(StarterOpenGL VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES) # Enforce the C++17 standard

add_subdirectory(lib/external/glad/)
add_subdirectory(lib/external/glfw/)
add_subdirectory(lib/external/glm/)

find_package(OpenGL REQUIRED)

set(SOURCE_FILES
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glad glfw glm)