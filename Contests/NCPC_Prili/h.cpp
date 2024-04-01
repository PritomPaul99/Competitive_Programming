// AL-HAMDULILLAH
//  #include <iostream>
#include <bits/stdc++.h>

// Data Types
#define ll long long
#define lli long long int
#define ld long double
typedef unsigned long int uint32;
typedef unsigned long long int uint64;

// Constant Values
#define pi acos(-1)
const ll Mod = 1e9 + 7;

// File handling
#define f_input freopen("input.txt", "r", stdin)
#define f_output freopen("output.txt", "w", stdout)
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL)

// Loops
#define fs(i, s, e) for (int i = s; i < e; i++)
#define fo(i, e) for (int i = 0; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define fi(n) for (int i = 0; i < n; i++)

// Strings
#define all(x) x.begin(), x.end()
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())

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

#define nl '\n'
#define eol cout << endl
// cout << fixed << setprecision(__n) << x << endl;
#define FSP(x) fixed << setprecision(x)
#define pop_cnt(n) __builtin_popcount(n) // Assign it to a value to find the numbers of 1's
                                         // in a binary number
#define numBits(n) log2(n) + 1           // Assign it to a value to get the number of bits
                                         // in an integer
#define DigitNum(n) log10(n) + 1         // Assign it to a value to get the number of digits
                                         // in an integer
#define _celi(x, y) (x + y - 1) / (y)
#define isPow2(x) (ceil(log2(x)) == floor(log2(x)))

// Containers
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pb push_back

// debug
#define cpoint cout << "_________________CHECK POINT_________________\n";
#define _debug(x) cout << x << endl
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")

using namespace std;

int cal[5][7];

bool checkYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "|";
        for (size_t j = 0; j < 7; j++)
        {
            if (cal[i][j] == -1)
            {
                cout << " - ";
            }
            else
            {
                if (cal[i][j] >= 10)
                    cout << " " << cal[i][j];
                else
                    cout << "  " << cal[i][j];
            }

            cout << "|";
        }
        cout << nl;
        cout << "|---------------------------|" << nl;
    }
}

void solve()
{
    string date;
    string week;

    cin >> date >> week;

    string a, b, c;
    a.append(date.begin(), date.begin() + 2);
    b.append(date.begin() + 3, date.begin() + 5);
    c.append(date.begin() + 6, date.end());
    int d = stoi(a), m = stoi(b), y = stoi(c);

    int w;

    if (week == "Sun")
    {
        w = 1;
    }
    else if (week == "Mon")
    {
        w = 2;
    }
    else if (week == "Tue")
    {
        w = 3;
    }
    else if (week == "Wed")
    {
        w = 4;
    }
    else if (week == "Thu")
    {
        w = 5;
    }
    else if (week == "Fri")
    {
        w = 6;
    }
    else if (week == "Sat")
    {
        w = 7;
    }

    for (int i = d; i >= 1; i--)
    {
        w--;
        if (w < 1)
        {
            w = 7;
        }
    }
    w += 1;

    int total_day;
    if (m == 1)
    {
        total_day = 31;
    }
    else if (m == 2)
    {
        if (checkYear(y))
        {
            total_day = 29;
        }
        else
        {
            total_day = 28;
        }
    }
    else if (m == 3)
    {
        total_day = 31;
    }
    else if (m == 4)
    {
        total_day = 30;
    }
    else if (m == 5)
    {
        total_day = 31;
    }
    else if (m == 6)
    {
        total_day = 30;
    }
    else if (m == 7)
    {
        total_day = 31;
    }
    else if (m == 8)
    {
        total_day = 31;
    }
    else if (m == 9)
    {
        total_day = 30;
    }
    else if (m == 10)
    {
        total_day = 31;
    }
    else if (m == 11)
    {
        total_day = 30;
    }
    else
    {
        total_day = 30;
    }

    // cout << w << nl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cal[i][j] = -1;
        }
    }

    int k = 0, flag = 0;
    // cout << w <<" "<<total_day<< endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == 0 && j >= w - 1)
            {
                // cout << i << " " << j << endl;
                cal[i][j] = ++k;
                flag = 1;
            }
            else if (flag == 1 && k < total_day)
            {
                cal[i][j] = ++k;
            }
            else
                cal[i][j] = -1;
        }
    }

    // cout << k << endl;
    if (k != total_day)
    {
        for (int i = 0; i < 7 && k < total_day; i++)
        {
            cal[0][i] = ++k;
        }
    }

    /*for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << cal[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << "|---------------------------|" << nl;
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << nl;
    cout << "|---------------------------|" << nl;
    print();
    // cout << nl;
}

int main()
{
    FastIO;
    // #ifndef ONLINE_JUDGE
    //     f_input;
    //     f_output;
    // #endif

    int ttt = 1, ca = 1;
    cin >> ttt;
    while (ttt--)
    {
        // cout << "Case " << ca++ << ": ";
        solve();
    }

    return 0;
}