#include <algorithm>
#include <iostream>
#include "SortingAlgorithms.h"


void SortingAlgorithms::BubbleSort(std::vector<int>& list)
{
	const int lastIndex = list.size() - 1;
	const int tenPercent = list.size() / 10;
	int percent = 0;

	std::cout << std::endl << "Bubble sort O(n^2):" << std::endl;
	for (int i = 0; i < lastIndex; i++)
	{
		if (i % tenPercent == 0)
		{
			std::cout << percent << "% ";
			percent += 10;
		}
			
		for (int j = 0; j < lastIndex - i; j++)
		{
			if (list[j] > list[j + 1])
			{
				int smallest = list[j + 1];
				list[j + 1] = list[j];
				list[j] = smallest;
			}
		}
	}
	std::cout << "100%" << std::endl;
}


void SortingAlgorithms::SelectionSort(std::vector<int>& list)
{
	const int length = list.size();
	const int tenPercent = (length) / 10;
	int percent = 0;

	std::cout << std::endl << std::endl << "Selection sort O(n^2):" << std::endl;
	for (int i = 0; i < length - 1; i++)
	{
		int indexOfSmallestNumber = i;

		if (i % tenPercent == 0)
		{
			std::cout << percent << "% ";
			percent += 10;
		}

		for (int j = i + 1; j < length; j++)
		{
			if (list[j] < list[indexOfSmallestNumber])
				indexOfSmallestNumber = j;
		}

		if (indexOfSmallestNumber != i)
		{
			int temporary = list[i];
			list[i] = list[indexOfSmallestNumber];
			list[indexOfSmallestNumber] = temporary;
		}
	}
	std::cout << "100%" << std::endl;
}


void SortingAlgorithms::InsertionSort(std::vector<int>& list)
{
	const int length = list.size();
	const int tenPercent = (length - 1) / 10;
	int percent = 0;

	std::cout << std::endl << std::endl << "Insertion sort O(n^2):" << std::endl;
	for (int i = 1; i < length; i++)
	{
		int valueToInsert = list[i];
		int holePosition = i;

		if (i % tenPercent == 0)
		{
			std::cout << percent << "% ";
			percent += 10;
		}

		while (holePosition > 0 && (list[holePosition - 1] > valueToInsert))
		{
			list[holePosition] = list[holePosition - 1];
			holePosition--;
		}

		if (holePosition != i)
		{
			list[holePosition] = valueToInsert;
		}
	}
	std::cout << "100%" << std::endl;
}


void SortingAlgorithms::StlSort(std::vector<int>& list)
{
	std::cout << std::endl << std::endl << "STL sort O(n log n):" << std::endl;
	std::sort(list.begin(), list.end());
}