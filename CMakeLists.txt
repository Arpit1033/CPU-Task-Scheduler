cmake_minimum_required(VERSION 3.10)
project(cpu-task-scheduler VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Create executables for each scheduling algorithm
add_executable(fcfs fcfs.cpp)
add_executable(round_robin round_robin.cpp)
add_executable(priority_scheduling priority_scheduling.cpp)
add_executable(sjf sjf.cpp)
add_executable(srtf srtf.cpp)
add_executable(multilevel_queue multilevel_queue.cpp)

# Optional: Install targets
install(TARGETS fcfs round_robin priority_scheduling sjf srtf multilevel_queue
        RUNTIME DESTINATION bin)
