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
#define pop_cnt(n) __builtin_popcount(n) // Assign it to a value to find the number of 1 in a binary number
#define numBits(n) log2(n) + 1           // Assign it to a value to get the number of bits in an integer
#define DigitNum(n) log10(n) + 1         // Assign it to a value to get the number of digit in an integer
#define _celi(x, y) (x + y - 1) / (y)

// Containers
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
// #define pi pair<int, int>
#define pb push_back

// debug
#define cpoint cout << "_________________CHECK POINT_________________\n";
#define _debug(x) cout << x << endl
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")

using namespace std;

ll dp[10007];
ll k;

ll bnc(ll n, ll p)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }

    if (p > n)
    {
        dp[n] = 0;
        return 0;
    }

    ll save = 0;
    for (ll i = 1; i <= p; i++)
    {
        save += bnc(n - i, p) + 1;
    }
    dp[n] = save;
    return save;
}

pair<ll, ll> ans = {-1, -1};

/*void caller(ll n, ll p){
    //if(p>n) return;

    if(dp[n]<k){

        k -= dp[n];
        return;
    }

    if(k==0){
        ans.second = n;
        return;
    }

    for (ll i = 1; i <= p; i++)
    {
        if(k==1) {
            ans.first = n;
        }
        k--;
        caller(n - i, p);
    }
    return;
}*/

void caller(ll n, ll p)
{
    // cout << "OK" << endl;
    if (k == 0)
    {
        ans.second = n;
        return;
    }

    if (n < p)
    {
        return;
    }

    if (dp[n] < k)
    {
        k -= dp[n];
        return;
    }

    for (int i = 1; i <= p; i++)
    {
        if (k == 1)
        {
            ans.first = n;
        }
        k--;
        caller(n - i, p);
    }
    return;
}

void solve()
{
    ll n, p;
    cin >> n >> p >> k;

    fill(dp, dp + n + 1, -1);

    // cout << "OK" << endl;
    bnc(n, p);

    cout << dp[n] << " ok " << endl;
    if (dp[n] < k)
    {
        cout << "Invalid" << endl;
        return;
    }

    // cout << "OK" << endl;
    caller(n, p);

    cout << ans.first << " " << ans.second << endl;

    ans = {-1, -1};
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
        cout << "Case " << ca << ": ";
        solve();
        ca++;
    }

    // #ifndef ONLINE_JUDGE
    //     double time = (clock() - start) / CLOCKS_PER_SEC;
    //     cerr << "Running Time : "<< time << "\n";
    // #endif
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