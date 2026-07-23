#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T ; 
    cin>>T;

    while(T--){
      int n ;
      cin>>n;
      string s;
      cin>>s;
      int cur = 0,mx=0;
      for(char c : s){
        if(c == '#'){
            cur++;
        }
        else{
            mx = max(mx,cur);
            cur=0;
        }
      }
      mx = max(mx,cur);

      cout<<(mx+1)/2<<'\n';

        
      
     
    }
return 0;
}