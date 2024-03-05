#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void top_down_merge(int *array, int begin, int end, int *copy);
void top_down_split_merge(int *array, int begin, int end, int *copy);
void swap1(listint_t *tprev, listint_t *tnext);
void swap2(listint_t *tnext, listint_t *tprev);
void quick_sort(int *array, size_t size);
void swap3(listint_t **list, listint_t *tprev, listint_t *tnext);
void radix_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
int get_digits_radix(int *array2, size_t size, int count, int *new_array);
int obtain_digit(long num, int count);
int get_digit(long number, int digit);
int radix_pass(int *array, ssize_t size, int digit, int *new_array);
void get_digits_radix2(int *array, size_t size, size_t *count, size_t digits);
void heap_sort(int *array, size_t size);
void heap_swap(int *array, size_t size, int i, size_t size2);
void swap_heapsort(int *array, int min, int max, size_t size);
#endif
