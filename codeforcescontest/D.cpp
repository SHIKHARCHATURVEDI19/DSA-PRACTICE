#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; 
    cin>>t;

    while(t--){
        int k ;
        cin >> k;

        int mx = 0, cnt =0;
        for(int i = 0;i<k ;i++){
            int x ;
            cin>>x;
            mx = max(mx,x);
            if(x>=2)cnt++;
        }
        if(mx>=3 || cnt >= 2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}