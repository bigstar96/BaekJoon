//����� ������ �¾� ģ���鿡�� ����Ƽ���� N�� �����޾Ҵ�.
// � ����Ƽ���� ���� ���� �� ��ȹ�� ���س��µ�, 
// ��û�� ����� ����Ƽ�ܿ� ������ �ִٴ� ����� ��İ� �ذ� �־���.
// ������ ����Ƽ�ܿ��� ���� ���� ����� �ִ�.
// �� ����Ƽ���� �� �� ������ ������ ������ 30�Ͼ� �þ��.
//
//����� ����Ƽ���� ���� ������ �ʹ� �������ϱ� ������, 
// ���� ������ �ּ������� �ϰ� �;��Ѵ�.
// �׸��� ����� �������� �־, 
// ���� ����Ƽ�� �� ������ ���� ���� ���� ����Ƽ�ܸ� ����� �� �ִ�.
// ��, ������ ���� ���� ���� ����Ƽ���� ���� ����� �� �� �ƹ��ų� ������ �� �ִ�.
// �Ϸ翡 ���� ����Ƽ���� ����ϰų� �����ϴ� �� ��� �����ϴ�.
//
//�ּ� Ƚ���� ���� ������ �ϸ鼭 ����Ƽ���� �� �� �� �ֵ��� ���츦 ��������.

#include <iostream>

int Plustime{ 30 };
int A[1000]{};
int B[1000]{};
bool chk[1000]{};



int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);


	int N;
	std::cin >> N;
	if (N < 1 && 1000 < N)
	{
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		std::cin >> A[i];
	}
	for (int i = 0; i < N; ++i)
	{
		std::cin >> B[i];
	}

	int count{};
	int deleteGifticon{};
	int day{};
	int min{ N - 1 };
	

	while (deleteGifticon != N)
	{
		for (int i = 0; i < N; ++i)
		{
			// ���� ���� ��ߵǴ� ���� ã��
			if (B[min] > B[i] && B[i] != 0 && min < N && chk[i] == 0)
			{
				min = i;
			}
			else if (B[min] == 0 && min < N)
			{
				min = i;
				for (int j = 0; j < N; ++j)
				{
					if (A[min] > A[j] && B[j] != -1 && chk[j] == 0 && B[min] >= B[j] && min != j)
					{
						min = j;
						break;
					}
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			// �Ⱓ ����
			if (A[i] < B[i] && chk[i] == 0)
			{
				A[i] += Plustime;
				count++;
			}
			if ((A[min] > A[i]) && (chk[i] == 0))
			{
				while (A[min] > A[i] && chk[i] == 0)
				{
					A[i] += Plustime;
					count++;
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			// ���� ���� ��ߵǴ� ���� ��� �� �����
			if (A[i] >= B[i] && B[min] >= B[i] && B[i] != 0 && min < N && chk[i] == 0)
			{
				if (min == i)
				{
					deleteGifticon++;
					A[i] = 0;
					B[i] = 0;
					min = 0;
					chk[i] = 1;
				}
			}
		}
	}

	std::cout << count;
}