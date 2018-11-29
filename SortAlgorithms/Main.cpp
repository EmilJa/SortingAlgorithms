#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <limits>
#include "Generate.h"
#include "SortingAlgorithms.h"

typedef std::chrono::high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

template<typename T>
void measureExecutionTime(T function, std::vector<int>& list);
void printExecutionTime(ClockTime startTime, ClockTime endTime);

int main()
{
	int nrOfElements;
	std::cout << "Enter how many elements to sort: ";
	std::cin >> nrOfElements;

	std::unique_ptr<std::vector<int>> numbers_1 = Generate::RandomVector(nrOfElements, INT_MAX);
	std::vector<int> numbers_2 = *numbers_1;
	std::vector<int> numbers_3 = *numbers_1;
	std::vector<int> numbers_4 = *numbers_1;

	measureExecutionTime(SortingAlgorithms::BubbleSort, *numbers_1);
	measureExecutionTime(SortingAlgorithms::SelectionSort, numbers_2);
	measureExecutionTime(SortingAlgorithms::InsertionSort, numbers_3);
	measureExecutionTime(SortingAlgorithms::StlSort, numbers_4);

	_getwch();
	return 0;
}

template<typename T>
void measureExecutionTime(T function, std::vector<int>& list)
{
	ClockTime startTime = Clock::now();
	function(list);
	ClockTime endTime = Clock::now();
	printExecutionTime(startTime, endTime);
}


void printExecutionTime(ClockTime startTime, ClockTime endTime)
{
	auto executionTime_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
	auto executionTime_ms = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	auto executionTime_sec = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
	auto executionTime_min = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime).count();
	auto executionTime_hour = std::chrono::duration_cast<std::chrono::hours>(endTime - startTime).count();

	if (executionTime_hour > 0)
		std::cout << "" << executionTime_hour << " Hours, ";
	if (executionTime_min > 0)
		std::cout << "" << executionTime_min % 60 << " Minutes, ";
	if (executionTime_sec > 0)
		std::cout << "" << executionTime_sec % 60 << " Seconds, ";
	if (executionTime_ms > 0)
		std::cout << "" << executionTime_ms % long(1E+3) << " MicroSeconds, ";
	if (executionTime_ns > 0)
		std::cout << "" << executionTime_ns % long(1E+6) << " NanoSeconds, ";
}