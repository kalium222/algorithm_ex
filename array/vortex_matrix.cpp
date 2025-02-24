#include <iostream>
#include <vector>

auto vortex_matrix(int n)
{
    auto res = std::vector<std::vector<int>>(n, std::vector<int>(n));
    int num = 1;
    int i = 0, j = 0;
    while (num<=n*n)
    {
        res[i][j] = num;
        if (i+1>=j && i+j<n-1)
        {
            i++;
        }
        else if (i+j>=n-1 && i>j)
        {
            j++;
        }
        else if (i+j>n-1 &&  i<=j)
        {
            i--;
        }
        else j--;
        num++;
    }
    return res;
}

int main(void)
{
    auto m = vortex_matrix(4);
    for (auto row : m)
    {
        for (auto num : row)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
