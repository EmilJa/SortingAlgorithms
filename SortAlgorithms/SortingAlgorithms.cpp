#include <algorithm>
#include "SortingAlgorithms.h"


void SortingAlgorithms::BubbleSort(std::vector<int>& list)
{
	const int lastIndex = list.size() - 1;

	for (int i = 0; i < lastIndex; i++)
	{
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
}


void SortingAlgorithms::SelectionSort(std::vector<int>& list)
{
	const int length = list.size();

	for (int i = 0; i < length - 1; i++)
	{
		int indexOfSmallestNumber = i;

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
}


void SortingAlgorithms::InsertionSort(std::vector<int>& list)
{
	const int length = list.size();

	for (int i = 1; i < length; i++)
	{
		int valueToInsert = list[i];
		int holePosition = i;

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
}


void SortingAlgorithms::StlSort(std::vector<int>& list)
{
	std::sort(list.begin(), list.end());
}