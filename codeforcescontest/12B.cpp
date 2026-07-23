#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
if(n==1){
    cout<<1<<"\n";
    return ;
}
if(n==2){
    cout<<-1<<"\n";
    return;
}
vector<long long> a={1,2,3};
long long curr = 6;

      for(int i = 3 ;i < n;i++){
        a.push_back(curr);
        curr *=2;
}
for(int i = 0 ;i<n;i++){
    cout<<a[i]<<(i==n-1? "":" ");
}
        cout<<"\n";
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