#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
vector<long long> a(n);
for(int  i = 0 ;i<n ;i++){

    cin>>a[i];
    
}
long long extra = 0;
long long need =1;

for(int i = 0;i<n;i++){
    long long have = a[i] +extra;

    if(have <need ){
        cout<<"NO\n";
        return;
    }
    extra = have -need;
    need ++;
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