/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max1 = -1, max2 = -1;
        int f = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
                f = i;
            }
            if (nums[i] > max2 && i != f)
            {
                max2 = nums[i];
            }
            // cout << max1 << " " << max2 << "" << endl;
        }
        return (max1 - 1) * (max2 - 1);
    }
};
// @lc code=end
