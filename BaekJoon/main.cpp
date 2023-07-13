//정우는 생일을 맞아 친구들에게 기프티콘을 N개 선물받았다.
// 어떤 기프티콘을 언제 쓸지 다 계획을 정해놨는데, 
// 멍청한 정우는 기프티콘에 기한이 있다는 사실을 까맣게 잊고 있었다.
// 다행히 기프티콘에는 기한 연장 기능이 있다.
// 한 기프티콘을 한 번 연장할 때마다 기한이 30일씩 늘어난다.
//
//정우는 기프티콘의 기한 연장을 너무 귀찮아하기 때문에, 
// 기한 연장을 최소한으로 하고 싶어한다.
// 그리고 정우는 강박증이 있어서, 
// 남은 기프티콘 중 기한이 가장 적게 남은 기프티콘만 사용할 수 있다.
// 단, 기한이 가장 적게 남은 기프티콘이 여러 개라면 그 중 아무거나 선택할 수 있다.
// 하루에 여러 기프티콘을 사용하거나 연장하는 것 모두 가능하다.
//
//최소 횟수로 기한 연장을 하면서 기프티콘을 다 쓸 수 있도록 정우를 도와주자.

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
			// 가장 먼저 써야되는 깊콘 찾기
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
			// 기간 연장
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
			// 가장 먼저 써야되는 깊콘 사용 및 지우기
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