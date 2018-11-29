#include <algorithm>
#include <ctime>
#include "Generate.h"


std::unique_ptr<std::vector<int>> Generate::RandomVector(int nrOfElements, int highestNumber)
{
	std::srand((int)time(0));
	std::vector<int> randomNumberVector(nrOfElements);
	std::generate(randomNumberVector.begin(), randomNumberVector.end(), [=] { return std::rand() % highestNumber; });

	return std::make_unique<std::vector<int>>(randomNumberVector);
}