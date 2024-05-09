#include <bits/stdc++.h>

#define nl endl
// Array
#define mems(a, x) memset(a, x, sizeof(a))   // Works only for 0 and -1
#define ass_vel(ar, n, x) fo(i, n) ar[i] = x // Set value in array
#define a_sort(ar, size) sort(ar, ar + size)
#define d_sort(arr, size) sort(arr, arr + size, greater<int>())
#define min_el(arr, size) *min_element(arr, arr + size)
#define max_el(arr, size) *max_element(arr, arr + size)
#define ain(arr, n) fo(i, n) cin >> arr[i]
#define aout(arr, n)                    \
    fo(i, n) { cout << arr[i] << " "; } \
    cout << nl;
#define find_(a, n, x) find(a, a + n, x) - a
// Loops
#define fs(i, s, e) for (int i = s; i < e; i++)
#define fo(i, e) for (int i = 0; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define fi(n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    vector<char> chars = {'a', 'b', 'c','c','c','c','c','c','c','c','c','c','c','c','c',};

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

    for (int i = 0; i < chars.size(); i++)
    {
        cout << chars[i] << " ";
    }

    return 0;
}
