#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> sum_table{1, n};
        int bit_square_sum;
        int temp;
        temp = n;
        while (n!=1)
        {
            bit_square_sum = 0;
            while (temp!=0)
            {
                bit_square_sum += (temp%10) * (temp%10);
                temp /= 10;
            }
            if (bit_square_sum==1) break;
            auto res = sum_table.insert(bit_square_sum);
            if (!res.second)
            {
                return false;
            }
            temp = bit_square_sum;
        }
        return true;
    }
};

int main(void)
{
    Solution s{};
    s.isHappy(19);
    return 0;
}
