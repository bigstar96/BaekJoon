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

	std::sort(A.begin(), A.end());

	std::vector<bool> chk(num);
	int sum{};

	for (int i = 0; i < num; ++i)
	{
		int temp = 0;
		int idx = 0;
		for (int j = 0; j < num; ++j)
		{
			if (temp < B[j] && chk[j] == 0)
			{
				temp = B[j];
				idx = j;
			}
		}
		chk[idx] = 1;
		sum += A[i] * temp;
	}

	std::cout << sum;
}