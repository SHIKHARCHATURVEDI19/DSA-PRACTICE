#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T ; 
    cin>>T;

    while(T--){
        int n ; 
        cin >> n;

        vector<int> prefA(n),prefB(n);
        int c1=0,c2=0,c3=0;
        for(int i = 0 ; i<n ;i++){
            int x ;
            cin >> x;
            if(x==1)c1++;
            else if(x==2)c2++;
            else c3++;

            prefA[i]=c1-c2-c3;
            prefB[i]=c1+c2-c3;
        }
        bool ok = false ;
        int maxi = -1e9;
        for(int i =n-3 ; i>= 0;i--){
           maxi =max(maxi,prefB[i+1]);
            if(prefA[i]>=0 && maxi >= prefB[i]){
                ok = true;
                break;
            }
        }
        cout<<(ok?"YES\n" : "NO\n");
    }
}