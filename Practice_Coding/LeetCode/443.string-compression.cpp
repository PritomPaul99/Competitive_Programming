/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        string s;

        int cnt = 0;
        char temp = chars[0];

        for (int i = 0; i < n; i++)
        {
            if (chars[i] == temp)
            {
                cnt++;

                // if(cnt == 10)
                // {
                //     s += temp;
                //     s += to_string(cnt);
                //     cnt = 0;
                // }

                if (i == n - 1)
                {
                    s += temp;
                    if (cnt > 1)
                    {
                        s += to_string(cnt);
                    }
                }
            }
            else
            {

                s += temp;
                if (cnt > 1)
                {
                    s += to_string(cnt);
                }
                temp = chars[i];
                cnt = 1;

                if (i == n - 1)
                {
                    s += chars[i];
                }
            }
        }

        chars.clear();

        for (int i = 0; i < s.size(); i++)
        {
            chars.push_back(s[i]);
        }

        return chars.size();
    }
};
// @lc code=end
