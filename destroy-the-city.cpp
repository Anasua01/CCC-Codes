#include <bits/stdc++.h>
using namespace std;

int mincuts(int a[],int l, int r, int x)
{
    if(l>r) return 0;
    int m=INT_MAX;
    for(int i=l;i<=r;i++)
    {
        if(a[i]==x){
            m=mincuts(a,l,i-1,x)+mincuts(a,i+1,r,x);
            break;
        }
    }
    if(m==INT_MAX)m=1+mincuts(a,l,r,x+1);
    return min(m,r-l+1);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<mincuts(a,0,n-1,0)<<'\n';
    }
    return 0;
}
