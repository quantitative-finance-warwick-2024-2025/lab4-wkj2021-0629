#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "exercises.h"

TEST_CASE("day to name correct", "[tests]")
{
    REQUIRE(std::string(day_to_name(0)) == "Invalid number");
    REQUIRE(std::string(day_to_name(1)) == "Monday");
    REQUIRE(std::string(day_to_name(2)) == "Tuesday");
    REQUIRE(std::string(day_to_name(3)) == "Wednesday");
    REQUIRE(std::string(day_to_name(4)) == "Thursday");
    REQUIRE(std::string(day_to_name(5)) == "Friday");
    REQUIRE(std::string(day_to_name(6)) == "Saturday");
    REQUIRE(std::string(day_to_name(7)) == "Sunday");
    REQUIRE(std::string(day_to_name(8)) == "Invalid number");
}

TEST_CASE("Testing swap function", "[swap]") {
    int x = 123, y = 456;
    swap(&x, &y);
    REQUIRE(x == 456);
    REQUIRE(y == 123);

    // try swapping back to original values
    swap(&x, &y);
    REQUIRE(x == 123);
    REQUIRE(y == 456);
}

TEST_CASE("Testing swap_in_place function", "[swap_in_place]") {
    int x = 123, y = 456;
    swap_in_place(&x, &y);
    REQUIRE(x == 456);
    REQUIRE(y == 123);

    // try swapping back to original values
    swap_in_place(&x, &y);
    REQUIRE(x == 123);
    REQUIRE(y == 456);
}

TEST_CASE("Testing add_vector function", "[add_vector]") {
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int result[4];
    int size = 4;
    add_vector(a, b, result, size);
    int expected_result[] = {6, 8, 10, 12};
    for (int i = 0; i < size; ++i) {
        REQUIRE(result[i] == expected_result[i]);
    }
}

TEST_CASE("Testing swap_vector function", "[swap_vector]") {
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int* pa = a;
    int* pb = b;
    swap_vector(&pa, &pb);
    for (int i = 0; i < 4; ++i) {
        REQUIRE(pa[i] == b[i]);
        REQUIRE(pb[i] == a[i]);
    }
}

TEST_CASE("Matrix multiplication with 1x4 matrices", "[matrix_multiplication]") {
    // 1x4 * 4x1 matrices
    // [1 2 3 4] * [5] = [70]
    //               [6]
    //               [7]
    //               [8]
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {5, 6, 7, 8};
    size_t a_rows = 1;
    size_t a_cols = 4;
    size_t b_cols = 1;
    std::vector<int> result(a_rows * b_cols);
    
    matrix_multiplication(a.data(), b.data(), a_rows, a_cols, b_cols, result.data());
    
    REQUIRE(result[0] == 70);
}

TEST_CASE("Matrix multiplication with 2x2 matrices", "[matrix_multiplication]") {
    // 2x2 matrices
    // [1 2] * [5 6] = [19 22]
    // [3 4]   [7 8]   [43 50]
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {5, 6, 7, 8};
    size_t a_rows = 2;
    size_t a_cols = 2;
    size_t b_cols = 2;
    std::vector<int> result(a_rows * b_cols);
    
    matrix_multiplication(a.data(), b.data(), a_rows, a_cols, b_cols, result.data());
    
    std::vector<int> expected = {19, 22, 43, 50};
    REQUIRE(result.size() == expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        REQUIRE(result[i] == expected[i]);
    }
}

TEST_CASE("Matrix multiplication with 4x1 and 1x4 matrices", "[matrix_multiplication]") {
    // 4x1 * 1x4 matrices
    // [1]    * [5 6 7 8] = [5  6  7  8]
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {5, 6, 7, 8};
    size_t a_rows = 1;
    size_t a_cols = 4;
    size_t b_cols = 1;
    std::vector<int> result(a_rows * b_cols);
    
    matrix_multiplication(a.data(), b.data(), a_rows, a_cols, b_cols, result.data());
    
    std::vector<int> expected = {70};  // 1*5 + 2*6 + 3*7 + 4*8 = 70
    REQUIRE(result.size() == expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        REQUIRE(result[i] == expected[i]);
    }
}

TEST_CASE("Matrix multiplication with 3x2 and 2x3 matrices", "[matrix_multiplication]") {
    // 3x2 * 2x3 matrices
    // [1 2] * [7  8  9] = [27 30 33]
    // [3 4]   [10 11 12] [61 68 75]
    // [5 6]               [95 106 117]
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    std::vector<int> b = {7, 8, 9, 10, 11, 12};
    size_t a_rows = 3;
    size_t a_cols = 2;
    size_t b_cols = 3;
    std::vector<int> result(a_rows * b_cols);
    
    matrix_multiplication(a.data(), b.data(), a_rows, a_cols, b_cols, result.data());

    std::vector<int> expected = {27, 30, 33, 61, 68, 75, 95, 106, 117};
    REQUIRE(result.size() == expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        REQUIRE(result[i] == expected[i]);
    }
}