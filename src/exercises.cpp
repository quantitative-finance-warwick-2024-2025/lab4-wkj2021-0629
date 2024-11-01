#include <iostream>
#include <array>
#include <vector>

/*
day_to_name takes an integer as a parameter and returns the day of the week
corresponding to that number.
For example: day 1 is Monday, day 7 is Sunday.

Write the return statement to complete the day_to_name function.
*/
std::string day_to_name(int day_number)
{
    const std::string invalid = "Invalid number";
    const std::array<std::string, 7> days =
        {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"};

    return invalid;
}

/*
Implement the function swap(int* x, int* y), which copies the value of
x to the value of y and the value of y to the value of x.

Use print_swap to check your implementation.
*/
void swap(int *x, int *y)
{
}

void print_swap()
{
    int x = 123, y = 456;
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    swap(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';
}

/*
Implement the function swap_in_place(int* x, int* y), which performs the same
operation as swap(), but does not declare any new variables to achieve this.

Use print_swap_in_place to check your implementation.
*/
void swap_in_place(int *x, int *y)
{
}

void print_swap_in_place()
{
    int x = 123, y = 456;
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    swap_in_place(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << '\n';
}

/*
Implement the function add_vector(int* a, int* b, int* result, int size), which performs
vector addition on two arrays 'a' and 'b' of a given size. The result should be stored in
the 'result' array.

Use print_add_vector to check your implementation.
*/
void add_vector(int *a, int *b, int *result, int size)
{
}

void print_add_vector()
{
    std::array<int, 4> a = {1, 2, 3, 4};
    std::array<int, 4> b = {5, 6, 7, 8};
    int result[4];
    int size = 4;
    add_vector(a.data(), b.data(), result, size);
    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i] << ' '; // should print 6, 8, 10, 12
    }
    std::cout << '\n';
}

/*
Implement the function swap_vector(int** a, int** b), which swaps the contents of vectors
which are pointed at by the parameters a and b.

Hint: you do not need to copy/swap every single value in the vectors.

Use print_swap_vector to check your implementation.
*/
void swap_vector(int **a, int **b)
{
}

void print_swap_vector()
{
    std::array<int, 4> a = {1, 2, 3, 4};
    std::array<int, 4> b = {5, 6, 7, 8};

    // obtain pointers to the start of each array
    int *pa = a.data();
    int *pb = b.data();
    swap_vector(&pa, &pb);
    for (int i = 0; i < 4; ++i)
    {
        std::cout << pa[i] << ' '; // Should print 5 6 7 8
    }
    std::cout << '\n';
    for (int i = 0; i < 4; ++i)
    {
        std::cout << pb[i] << ' '; // Should print 1 2 3 4
    }
    std::cout << '\n';
}

/*
Implement the function matrix_multiplication(int* a, int* b, int a_cols, int b_cols, int* result),
which multiplies two matrices 'a' and 'b' and stores the result in the 'result' matrix.
It should work for matrices of any dimension where a_cols == b_rows.
a, b and c are all correctly sized before calling the function

Note: 
result[i * b_cols + j] is the element at the ith row and jth column of the result matrix.
result_i_j = sum(a_i_k * b_k_j) for k = 0 to k = b_rows - 1
*/
void matrix_multiplication(int *a, int *b, size_t a_rows, size_t a_cols, size_t b_cols, int *result)
{
}

void print_matrix_multiplication()
{
    size_t a_cols = 2, b_cols = 2;
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {5, 6, 7, 8};
    size_t a_rows = a.size() / a_cols;
    std::vector<int> result(a_rows * b_cols);

    matrix_multiplication(a.data(), b.data(), a_rows, a_cols, b_cols, result.data());

    for (size_t i = 0; i < b_cols; ++i)
    {
        for (size_t j = 0; j < a_rows; ++j)
        {
            std::cout << result[j * a_rows + i] << ' ';
        }
        std::cout << '\n';
    }
}