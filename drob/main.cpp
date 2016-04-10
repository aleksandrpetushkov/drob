#include <iostream>
#include <vector>
#include "algo_drob.h"



int main()
{
	//std::cout << "Hello";

	algo_drob algo;
	std::vector<drob> mas_drob;

	algo.calc(3.02384534005, 1.0e-10, &mas_drob);
	//std::cout << mas_drob.size();
	for (const auto& elem : mas_drob)
	{
		std::cout << elem;
	}
	std::cin.get();
}
