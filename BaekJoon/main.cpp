//���� ������ ������ �׻� ū ��ĩ�Ÿ����� ���� �־���.
// �� ������ ���� �������� ������ ���� ������ ���� ū ����� �ɾ���.
//
//���̰� N�� ���� �迭 A�� B�� �ִ�.������ ���� �Լ� S�� ��������.
//
//S�� ���� ���� �۰� ����� ���� A�� ���� ��迭����.��, B�� �ִ� ���� ��迭�ϸ� �� �ȴ�.
//
//S�� �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//ù° �ٿ� N�� �־�����.��° �ٿ��� A�� �ִ� N���� ���� ������� �־�����, 
// ��° �ٿ��� B�� �ִ� ���� ������� �־�����.N�� 50���� �۰ų� ���� �ڿ����̰�, 
// A�� B�� �� ���Ҵ� 100���� �۰ų� ���� ���� �ƴ� �����̴�.
//


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::cin >> num;

	std::vector<int> A;
	for (int i = 0; i < num; ++i)
	{
		int a;
		std::cin >> a;
		A.push_back(a);
	}

	std::vector<int> B;
	for (int i = 0; i < num; ++i)
	{
		int a;
		std::cin >> a;
		B.push_back(a);
	}

	std::vector<int> rank;
	for (int i = 0; i < num; ++i)
	{
		int a{};
		for (int j = 0; j < num; ++j)
		{
			if (B[i] < B[j]) a++;
		}
		rank.push_back(a);
	}

	std::sort(A.begin(), A.end());

	for (auto& e : A)
	{
		std::cout << e << " ";
	}
	std::cout << "\n";
	for (auto& e : B)
	{
		std::cout << e << " ";
	}
	std::cout << "\n";
	for (auto& e : rank)
	{
		std::cout << e << " ";
	}
	std::cout << "\n";

	int sum{};

	for (int i = 0; i < num; ++i)
	{
		sum += A[rank[i]] * B[i];
	}

	std::cout << sum;
}