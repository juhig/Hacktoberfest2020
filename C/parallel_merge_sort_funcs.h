#ifndef _PARALLEL_4WAY_MERGE_SORT_H_
#define _PARALLEL_4WAY_MERGE_SORT_H_

#include <stdbool.h>

// array utils
int  rand();
int* generateIntArray(int size);
void printArray(int* array, int low, int high);

// merge sort: tutorial 1
void merge_4_way(int* array, int low, int mid1, int mid2, int mid3, int high);
void mergesort_4_way_rec(int* array, int low, int high);

// bubble sort
void bubble_sort(int *array, int size);     
bool verifySortResults(int* array_bubble, int* array_mergesort, int size);  // verify merge sort by bubble sort

/***** 
	Don't modify functions above.
*****/

// merge sort
void recursiveMergesort(int* array, int low, int high, int max_num);
void mergesort4Way4Processes(int* array, int low, int high);


#endif





