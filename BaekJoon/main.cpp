#include <iostream>

int main()
{
	unsigned int N{};
	std::cin >> N;
	int min{1000000}, max{-1000000};
	int input{};
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		if (min > input) min = input;

		if (max < input) max = input;
	}
	std::cout << min << " " << max;
}