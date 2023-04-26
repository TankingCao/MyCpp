cmake_minimum_required(VERSION 3.25)
project(MyCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(OS)
include_directories(OS/disk)
include_directories(OS/page)

add_executable(FIFO OS/page/FIFO.cpp)

add_executable(LRU OS/page/LRU.cpp)
add_executable(disk_FIFO OS/disk/disk_FIFO.cpp OS/disk/print.h)
add_executable(SSTF OS/disk/SSTF.cpp)
add_executable(SCAN OS/disk/SCAN.cpp)
add_executable(CSCAN OS/disk/CSCAN.cpp)
add_executable(autodiaodu OS/Test/dynamicPriority.cpp)
add_executable(processFIFO OS/Test/FCFS.cpp)
add_executable(FPF OS/Test/FPF.cpp OS/Test/FPF.cpp)
add_executable(TimeDemo OS/Test/RR.cpp)
add_executable(FPF_Rob OS/Test/FPF_Rob.cpp)
add_executable(SPF OS/Test/SPF.cpp)
add_executable(HRN OS/Test/HRN.cpp)