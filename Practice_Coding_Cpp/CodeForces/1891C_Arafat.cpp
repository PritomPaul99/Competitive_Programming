#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll k = n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (k--)
        {
            ll x;
            cin >> x;
            pq.push(x);
        }
        ll ans = 0;
        ll xl = 0;
        while (!pq.empty())
        {
            

            ll tp = pq.top();
            if (tp == 1)
            {
                ans++;
                pq.pop();
                xl++;
            }
            else
            {
                vector<ll> temp;
                while (pq.empty() == false && pq.top() <= xl)
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                if (temp.back() > xl)
                {
                    ans++;
                    xl = temp.back() - xl;
                    pq.push(xl);
                    temp.pop_back();
                    ll sz = temp.size() - 1;
                    while (!temp.empty() && sz)
                    {
                        pq.push(temp[sz]);
                        sz--;
                    }
                }
                else
                {
                    temp.pop_back();
                    ans++;
                    xl = 0;
                    ll sz = temp.size() - 1;
                    while (!temp.empty() && sz)
                    {
                        cout << "bal";
                        pq.push(temp[sz]);
                        sz--;
                    }
                }
            }
        }
        cout << pq.top() << endl;
        cout << "---" <<ans << endl;
    }
}