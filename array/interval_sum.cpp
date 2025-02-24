#include <iostream>
#include <vector>

void interval_sum()
{
    int n, a, b, temp;
    std::cin >> n;
    auto v = std::vector<int>(n);
    auto sum = std::vector<int>(n);
    for (int i=0; i<n; i++)
    {
        std::cin >> v[i];
    }
    for (int i=0; i<n; i++)
    {
        if (i==0) 
        {
            sum[i] = v[i];
        }
        else
        {
            sum[i] = sum[i-1] + v[i];
        }
    }
    while (std::cin >> a >> b)
    {
        if (a==0)
        {
            std::cout << sum[b] << std::endl;
        }
        else
        {
            std::cout << sum[b] - sum[a-1] << std::endl;
        }
    }
}

int main(void)
{
    interval_sum();
    return 0;
}
