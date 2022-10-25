class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int mini = INT_MAX, ans, n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            int comp = nums[i];

            int start = i + 1, end = n - 1;

            while (start < end)
            {
                int sum = nums[start] + nums[end] + comp;

                if (abs(sum - target) < mini)
                {
                    mini = abs(sum - target);
                    ans = sum;
                }

                if (sum > target)
                    end--;
                else if (sum < target)
                    start++;
                else
                    return target;
            }
        }

        return ans;
    }
};