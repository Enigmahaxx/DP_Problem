#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);//cout.tie(NULL);
#define mod 1000000007

int F[1000000];

int cost(int n, int* h){
    if(n>2) for(int i=3;i<=n;i++) F[i] = min(F[i-1] + abs(h[i]-h[i-1]) ,F[i-2] + abs(h[i]-h[i-2]));
}

int main()
{
    //io
    memset(F, -1, sizeof(F));
    int n;
    cin>>n;
    int h[n+1];
    for(int i=1;i<=n;i++) cin>>h[i];
    h[0]  = F[1] = 0;
    F[2] = abs(h[2] - h[1]);
    cost(n,h);
    cout<<F[n];
    return 0;
}

