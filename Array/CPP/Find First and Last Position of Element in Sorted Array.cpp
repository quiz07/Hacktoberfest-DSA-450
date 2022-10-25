#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fp(vector<int> nums, int s, int e, int target)
    {
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return ans;
    }
    int lp(vector<int> nums, int s, int e, int target)
    {
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int s = 0;
        int e = nums.size() - 1;
        ans.push_back(fp(nums, s, e, target));
        ans.push_back(lp(nums, s, e, target));
        return ans;
    }
};