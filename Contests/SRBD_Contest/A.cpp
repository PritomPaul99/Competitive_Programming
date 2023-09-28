#include <bits/stdc++.h>

// Data Types
#define ll long long
#define lli long long int
#define ld long double
typedef unsigned long int uint32;
typedef unsigned long long int uint64;


#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL)


#define pop_cnt(n) __builtin_popcount(n) // Assign it to a value to find the number of 1 in a binary number
#define numBits(n) log2(n) + 1           // Assign it to a value to get the number of bits in an integer
#define DigitNum(n) log10(n) + 1         // Assign it to a value to get the number of digit in an integer




ll log2_(ll i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

using namespace std;


void solve()
{
    ll B, c;
    cin >> B >> c;
    //ll y = 100;

    ll low = 0, r = 58, ans = 0;
    while (low <= r)
    {
        ll mid = low + (r - low) / 2;

        ll cost = (mid * c) + (mid / 2) * (mid / 2) + ((mid + 2 - 1) / 2) * ((mid + 2 - 1) / 2);
        if (cost <= B)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;

    }

    ll x = pow(2, ans);
    cout <<x<< endl;
}

int main()
{
    FastIO;


    int ttt = 1;
    cin >> ttt;
    while (ttt--)
    {

            solve();


    }
    return 0;
}
