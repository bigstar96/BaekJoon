#include <iostream>

int main()
{
	int t;
	std::cin >> t;

	int n = t;

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j < n; j++)
		{
			std::cout << " ";
		}
		for (int j = 1; j <= i; j++)
		{
			std::cout << "*";
		}
		n--;
		std::cout << std::endl;
	}
}