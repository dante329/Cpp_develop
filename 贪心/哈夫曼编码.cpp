#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int n;
priority_queue<LL,vector<LL>,greater<LL>> pq;
int main()
{
    cin >> n;
    while(n--)
    {
        LL x; cin >> x;
        pq.push(x);
    }
    LL ret = 0;
    while(pq.size() > 1)
    {
        LL x = pq.top(); pq.pop();
        LL y = pq.top(); pq.pop();
        ret += x + y;
        pq.push(x + y);
    }
    cout << ret << endl;
    return 0;
}
