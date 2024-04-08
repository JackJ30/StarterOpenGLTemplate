cmake_minimum_required(VERSION 3.1.0)
project(SecondAttemptOpenGL VERSION 1.0.0)
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

add_executable(${PROJECT_NAME} ${SOURCE_FILES} lib/external/stb/stb_image_implementation.cpp)

# copy resources folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)

# link and inculde
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL glad glfw glm)
target_include_directories(${PROJECT_NAME} PUBLIC lib/external/stb)