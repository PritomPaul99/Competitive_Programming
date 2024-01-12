/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int time = 0;

        for (int i = 0; i < colors.size(); i++)
        {
            // cout << colors[i] << " - ";
            int sum = neededTime[i],
                mx = neededTime[i];

            if (i < (colors.size() - 1))
            {
                for (int j = i + 1; (colors[i] == colors[j] && j < colors.size()); j++)
                {
                    sum += neededTime[j];
                    mx = max(mx, neededTime[j]);
                    // cout << colors[j] << " ";
                    i = j;
                }

                time += (sum - mx);
            }
        }

        return time;
    }
};
// @lc code=end
