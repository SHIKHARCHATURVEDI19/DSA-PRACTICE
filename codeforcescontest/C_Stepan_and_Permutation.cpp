#include <bits/stdc++.h>
#include <numeric>
using namespace std;

void solve(){
    int n ,x,y;
    cin>>n>>x>>y;
vector<int>pos(n+1);
      for(int i = 0;i < n;i++){
        int val;
        cin>>val;
        
        pos[val] = i;
}
        int g = __gcd(x,y);
        for(int val = 1;val <=n;val++ ){
            if((pos[val] %  g)!=((val-1)%g)){
                cout<<"NO\n";
                return ;
            }
        }
        cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T ; 
    cin>>T;

    while(T--){
      

        
      solve();
     
    }
return 0;
}