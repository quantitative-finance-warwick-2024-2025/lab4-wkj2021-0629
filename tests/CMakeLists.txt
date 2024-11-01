set(SRC_FILES test_exercises.cpp ${CMAKE_SOURCE_DIR}/src/exercises.cpp)
add_executable(test_exercises ${SRC_FILES})
target_include_directories(test_exercises PUBLIC ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/extern/catch2)
add_test(NAME test_exercises COMMAND test_exercises)