#include <bits/stdc++.h>

using namespace std;

int numIdenticalPairs(vector<int> nums)
{
    int ret = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (nums[i] == nums[j])
                ret++;
        }
    }

    return ret;
}

int main()
{
    assert(numIdenticalPairs({1,2,3,1,1,3}) == 4);
    return 0;
}