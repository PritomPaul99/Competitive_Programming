// #include <iostream>
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
#define _debug(x) cout << x << endl
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")

using namespace std;

/*bool primeNum[1000000 + 1];
void siv(int N)
{
    int sq = sqrt(N);
    for (int i = 4; i <= N; i += 2)
    {
        primeNum[i] = 1;
    }
    for (int i = 3; i <= sq; i += 2)
    {
        if (primeNum[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
                primeNum[j] = 1;
        }
    }
    primeNum[1] = 1;
}*/

typedef pair<int, int> Pair;

int x = 2;
int binarySearch(const vector<pair<int, int>> &arr, int target)
{
    int left = 0;
    int right = arr.size() - x;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid].first == target)
        {
            return mid;
        }
        if (arr[mid].first < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int ans = INT_MIN;
// Function to find the pairs as per the conditions
void find_pairs(const vector<Pair> &a, const vector<Pair> &b)
{
    vector<Pair> result;
    for (const auto &it : a)
    {
        int key = it.first;
        int res = binarySearch(b, key);
        cerr << 
        if (res >= 0)
        {
            ans = max(ans, res + it.second);
        }
    }
    // return result;
}

void solve()
{
    int n;
    cin >> n;

    vi arr(n);
    ain(arr, n);

    vector<pair<int, int>> a, b;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        a.push_back({sum, i});
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += arr[i];

        b.push_back({sum, i});
    }

    // sort(all(a));
    // sort(all(b));

    // for (auto &&it : a)
    // {
    //     cout << "{" << it.first << " " << it.second << "}, ";
    // }
    // cout << nl;
    // for (auto &&it : b)
    // {
    //     cout << "{" << it.first << " " << it.second << "}, ";
    // }
    // cout << nl << nl;
    find_pairs(a, b);

    cout << ans << nl;
}

int main()
{
    FastIO;
#ifndef ONLINE_JUDGE
    f_input;
    f_output;
#endif

    int ttt = 1, ca = 1;
    cin >> ttt;
    while (ttt--)
    {
        // cout << "Case " << ca++ << ": ";
        solve();
    }

    return 0;
}

/*
Cautions, Tips & Tricks:
    1. Any square number when divided by 4 must have a remainder of either 0 or 1.
    2. Floating point numbers numbers are equal if the difference between them is less than 1e-9
       [better way to compare floating point numbers]
    3. Remember: ((a + b) mod a) = b, for 0 ≤ b < a.
    4. Remember: Any square number when divided by 4 must have a remainder of either 0 or 1.
*/
