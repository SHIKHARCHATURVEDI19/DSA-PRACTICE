#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        if(n==1){
            long long x,y;
            cin>>x;
            cin>>y;
            cout<<(x==y?"YES":"NO")<<'\n';
            continue;
        }
        vector<long long > a(n),b(n);
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0 ; i <n ; i++){
            cin>>b[i];
        }
    
        bool ok= true;
        long long suma = 0,sumb=0;
        
        for(int i = 0; i<n;i++){
        suma+=a[i];
        sumb+=b[i];
        if(suma>sumb){
            ok=false;
            break;
        }
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}