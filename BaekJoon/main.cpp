


#include <iostream>


int main()
{
	int arr[6]{ 500,100,50,10,5,1 };
	int num{};
	std::cin >> num;
	int count{}, i{};

	num = 1000 - num;

	while (num != 0)
	{
		if (num >= arr[i])
		{
			num -= arr[i];
			count++;
		}
		else
		{
			i++;
		}
	}

	std::cout << count;
}