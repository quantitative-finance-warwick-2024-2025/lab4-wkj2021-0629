#ifndef EXERCISES_H
#define EXERCISES_H
#include <string>

std::string day_to_name(int day_number);

void swap(int* x, int* y);
void print_swap();

void swap_in_place(int* x, int* y);
void print_swap_in_place();

void add_vector(int* a, int* b, int* result, int size);
void print_add_vector();

void swap_vector(int** a, int** b);
void print_swap_vector();

void matrix_multiplication(int* a, int* b, size_t a_rows, size_t a_cols, size_t b_cols, int* result);
void print_matrix_multiplication();

#endif // EXERCISES_H
