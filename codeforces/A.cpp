#include <iostream>
using namespace std;
int main(){
    int t ;
    cin>> t;
    while(t--){
        int x ,y ;
        cin >> x >> y;
        if(x%y == 0){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
       
    }
     return 0;
}