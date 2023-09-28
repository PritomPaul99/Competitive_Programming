//#include <iostream>
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
#define mems(a, x) memset(a, x, sizeof(a))          // Works only for 0 and -1
#define ass_vel(ar, n, x) fo(i, n) ar[i] = x      // Set value in array
#define a_sort(ar, size) sort(ar, ar + size)
#define d_sort(arr, size) sort(arr, arr + size, greater<int>())
#define min_el(arr, size) *min_element(arr, arr + size)
#define max_el(arr, size) *max_element(arr, arr + size)
#define ain(arr, n) fo(i, n) cin >> arr[i]
#define aout(arr, n) fo(i, n) {cout << arr[i] << " ";} cout << nl;
#define find_(a, n, x) find(a, a + n, x) - a

#define nl '\n'
#define eol cout << endl
// cout << fixed << setprecision(__n) << x << endl;
#define FSP(x) fixed << setprecision(x)
#define pop_cnt(n) __builtin_popcount(n) //Assign it to a value to find the number of 1 in a binary number
#define numBits(n) log2(n) + 1 //Assign it to a value to get the number of bits in an integer
#define DigitNum(n) log10(n) + 1 //Assign it to a value to get the number of digit in an integer

// Vector
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define pb push_back

// debug
#define cpoint cout << "_________________CHECK POINT_________________\n";
#define _debug(x) cout << x << endl
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")

using namespace std;

bool primeNum[1000000 + 1];
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
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    ain(a, n);

    int mn = *min_element(a.begin(), a.end());

    // ll prod = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     ll x = 1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if(i == j)
    //         {
    //             x = x * (a[j] + 1);
    //         }
    //         else
    //         {
    //             x = x * a[j];
    //         }
            
    //     }
    //     // cout << x << nl;
    //     ll prod = max(prod, x);
    // }
    // cout << prod << nl;

    int cnt = 0;
    ll x = 1;
    for (int i = 0; i < n; i++)
    {
        if(cnt == 0 && a[i] == mn)
        {
            x = x * (a[i] + 1);
            cnt++;
        }
        else
        {
            x = x * a[i];
        }
    }
    cout << x << nl;
}

int main()
{
    FastIO;
#ifndef ONLINE_JUDGE
    double start = clock();
    f_input;
    f_output;
#endif

    int ttt = 1, ca = 1;
    cin >> ttt;
    while (ttt--)
    {
        //cout << "Case " << ca << ": ";
        solve();
        //ca++;
    }

#ifndef ONLINE_JUDGE
    double time = (clock() - start) / CLOCKS_PER_SEC;
    cerr << "Running Time : "<< time << "\n";
#endif
    return 0;
}

/***************************************************************************************************\
*                                            Written by:                                            *
*                                                                                                   *
*     ██▓███   ██▀███   ██▓▄▄▄█████▓ ▒█████   ███▄ ▄███▓     ██▓███   ▄▄▄       █    ██  ██▓        *
*    ▓██░  ██▒▓██ ▒ ██▒▓██▒▓  ██▒ ▓▒▒██▒  ██▒▓██▒▀█▀ ██▒    ▓██░  ██▒▒████▄     ██  ▓██▒▓██▒        *
*    ▓██░ ██▓▒▓██ ░▄█ ▒▒██▒▒ ▓██░ ▒░▒██░  ██▒▓██    ▓██░    ▓██░ ██▓▒▒██  ▀█▄  ▓██  ▒██░▒██░        *
*    ▒██▄█▓▒ ▒▒██▀▀█▄  ░██░░ ▓██▓ ░ ▒██   ██░▒██    ▒██     ▒██▄█▓▒ ▒░██▄▄▄▄██ ▓▓█  ░██░▒██░        *
*    ▒██▒ ░  ░░██▓ ▒██▒░██░  ▒██▒ ░ ░ ████▓▒░▒██▒   ░██▒    ▒██▒ ░  ░ ▓█   ▓██▒▒▒█████▓ ░██████▒    *
*    ▒▓▒░ ░  ░░ ▒▓ ░▒▓░░▓    ▒ ░░   ░ ▒░▒░▒░ ░ ▒░   ░  ░    ▒▓▒░ ░  ░ ▒▒   ▓▒█░░▒▓▒ ▒ ▒ ░ ▒░▓  ░    *
*    ░▒ ░       ░▒ ░ ▒░ ▒ ░    ░      ░ ▒ ▒░ ░  ░      ░    ░▒ ░       ▒   ▒▒ ░░░▒░ ░ ░ ░ ░ ▒  ░    *
*    ░░         ░░   ░  ▒ ░  ░      ░ ░ ░ ▒  ░      ░       ░░         ░   ▒    ░░░ ░ ░   ░ ░       *
*                ░      ░               ░ ░         ░                      ░  ░   ░         ░  ░    *
*                                           ╔╗╔╔═╗╦ ╦╔╗                                             *
*                                        ───║║║║╣ ║ ║╠╩╗───                                         *
*                                           ╝╚╝╚═╝╚═╝╚═╝                                            *
*                                 ╔╦╗┌─┐┌─┐┌┬┐   ┌─┐┌─┐  ╔═╗╔═╗╔═╗                                  *
*                              ─── ║║├┤ ├─┘ │    │ │├┤   ║  ╚═╗║╣ ───                               *
*                                 ═╩╝└─┘┴   ┴ o  └─┘└    ╚═╝╚═╝╚═╝                                  *
\***************************************************************************************************/