#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <string>

std::vector<std::string> mergeSort(std::vector<std::string>& arr, int left, int right);
void merge(std::vector<std::string>& arr, int left, int mid, int right);
void printArrayM(std::vector<std::string> arr, int size);

#endif
