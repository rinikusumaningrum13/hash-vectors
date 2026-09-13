add_library(work STATIC work.cpp)
target_include_directories(work PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(hash-vectors main.cpp)
target_link_libraries(hash-vectors PRIVATE work)
