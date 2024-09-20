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
#define cpoint cout << "_________________CHECK POINT_________________\n";
#define _debug(x) cout << x << endl
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")

using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;

        a[i].first %= k;

        if(a[i].first == 0){
            a[i].first = k;
        }

        a[i].second = -1 * (i + 1);
    }

    sort(all(a), greater<pair<ll, ll>>());

    for (ll i = 0; i < n; i++)
    {
        cout << -1 * a[i].second << " ";
    }
    cout << nl;
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
*/
 