#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);//cout.tie(NULL);
#define mod 1000000007

int F[1000000];

int cost(int n, int k, int* h)
{
    if(n==2)
        F[n] = abs(h[2] - h[1]);
    else
    {
        if(F[n]==-1)
        {
            F[n] = INT_MAX;
            for(int i = 1; (i <= min(k,n)) && (n-i >= 1); i++)
                F[n] = min(F[n], cost(n-i,k,h) + abs(h[n] - h[n-i]));
        }
    }
    return F[n];
}

int main()
{
    //io
    memset(F, -1, sizeof(F));
    int n,k;
    cin>>n>>k;
    int h[n+1];
    for(int i=1;i<=n;i++) cin>>h[i];
    h[0]  = F[1] = 0;
    cout<<cost(n,k,h);
    return 0;
}

