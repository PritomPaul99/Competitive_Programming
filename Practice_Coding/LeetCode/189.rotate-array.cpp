/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        vector<int> a(nums.begin(), nums.begin() + k+1), b(nums.begin() + k+1, nums.end());

        nums.clear();
        nums.insert(nums.begin(), b.begin(), b.end());
        nums.insert(nums.end(), a.begin(), a.end());
    }
};
// @lc code=end
