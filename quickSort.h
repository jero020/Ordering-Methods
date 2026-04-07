#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>

int partition(std::vector<std::string>& arr, int low, int high);
std::vector<std::string> quickSort(std::vector<std::string>& arr, int low, int high);
void printArrayQ(std::vector<std::string> arr, int size);

#endif
