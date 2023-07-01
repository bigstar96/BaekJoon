// backjoon 9012 °ýÈ£


#include <iostream>
#include <string>

int main()
{
	int num{};
	std::cin >> num;

	if (2 > num && num > 50)
	{
		return 0;
	}

	for (int i = 0; i < num; ++i)
	{
		std::string a;
		std::cin >> a;

		int count{};

		if (a[0] == ')')
		{
			count--;
		}
		
		for (int j = 0; a[j] != '\0'; ++j)
		{
			if (count < 0)
			{
				break;
			}
			if (a[j] == '(')
			{
				count++;
			}
			else if (a[j] == ')')
			{
				count--;
			}
			else
			{
				break;
			}
		}

		if (count == 0)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
}