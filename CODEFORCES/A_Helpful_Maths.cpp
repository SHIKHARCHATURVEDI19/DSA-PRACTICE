#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;


    cin>>s;

    vector<char>v;
    for(char c:s){
        if(isdigit(c))v.push_back(c);
    }
sort(v.begin(),v.end());
for(int i = 0 ;i<v.size();i++){
    cout<<v[i];
    if(i!=v.size()-1)cout<<"+";
}
  return 0;
}