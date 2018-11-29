#pragma once
#include <vector>

class SortingAlgorithms
{
public:
	static void BubbleSort(std::vector<int>& list);
	static void SelectionSort(std::vector<int>& list);
	static void InsertionSort(std::vector<int>& list);
	static void StlSort(std::vector<int>& list);

private:
	SortingAlgorithms();
};