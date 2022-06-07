#include <iostream>

int main()
{
    int N{}, X{};
    std::cin >> N >> X;

    int arr[10000];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        if (arr[i] < X)
        {
            printf("%d ", arr[i]);
        }
    }
}