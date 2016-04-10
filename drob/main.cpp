#include <iostream>
#include <vector>
#include "algo_drob.h"
#include "gtest\gtest.h"


TEST(ASSERt) //Тест исключения
{
	algo_drob tst;
	std::vector<drob> mas_drob;
	ASSERT_THROW(tst.calc(-3.02384534005, 1.0e-10, &mas_drob), char*);
}

TEST(drob) //Тест вывода дроби
{
	drob tst(3, 5, 5e-10);
	std::ostringstream test_str;
	test_str << tst;
	EXPECT_EQ("3/5 epsilon = 5e-10", test_str.str());
}
TEST (calc) //Тест расчета алгоритма
{
	std::vector<drob> mas_drob;
	algo_drob tst_algo;
	std::ostringstream test_str;
	tst_algo.calc(3.1, 1.0e-1, &mas_drob);
	for (const auto& elem : mas_drob)
	{
		test_str << elem;
	}
	EXPECT_EQ("3/1 epsilon = 0.0322581", test_str.str());
}

int main(int argc, char* argv[])
{
	try
	{
		algo_drob algo;
		std::vector<drob> mas_drob;

		algo.calc(3.1, 1.0e-1, &mas_drob);
		for (const auto& elem : mas_drob)
		{
			std::cout << elem<< std::endl;
		}
		::testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
		std::cin.get();
	}
	catch(char* string)
	{
		std::cout << string << std::endl;
		std::cin.get();
	}
	
}
