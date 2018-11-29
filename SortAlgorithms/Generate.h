#pragma once
#include <vector>
#include <memory>

class Generate
{
public:
	static std::unique_ptr<std::vector<int>> RandomVector(int nrOfElements, int highestNumber);

private:
	Generate();
};