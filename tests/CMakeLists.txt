add_executable(hash-vectors_tests test_core.cpp)
target_link_libraries(hash-vectors_tests PRIVATE work)
target_include_directories(hash-vectors_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND hash-vectors_tests)
