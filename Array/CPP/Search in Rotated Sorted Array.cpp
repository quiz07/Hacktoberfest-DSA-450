#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bs1(vector<int> nums, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
        }
        return -1;
    }
    int minindex(vector<int> &nums)
    {
        int mid, prev, next;
        int low = 0;
        int high = nums.size() - 1;
        int n = high - low + 1;
        int index = -1;
        while (low <= high)
        {
            if (nums[low] <= nums[high])
            {
                return low;
            }
            mid = low + (high - low) / 2;
            prev = (mid + n - 1) % n;
            next = (mid + 1) % n;
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return mid;
            else if (nums[low] <= nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int index = minindex(nums);
        int idx1 = bs1(nums, target, start, index - 1);
        int idx2 = bs1(nums, target, index, end);
        if (idx1 == -1)
            return idx2;
        if (idx2 == -1)
            return idx1;
        return -1;
    }
};