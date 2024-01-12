/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        int carry = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i] += carry;
                carry = 0;
            }
            else if (carry == 1)
            {
                if (i == 0)
                {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                }
                else
                {
                    digits[i] = 0;
                    carry = 1;
                }
            }
        }
        return digits;
    }
};
// @lc code=end
