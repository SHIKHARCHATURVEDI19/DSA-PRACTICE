/*Symmetric Number Pyramid
Given an integer n, write a function to print a symmetric number pyramid pattern. The pyramid has n rows, and each row i (where i ranges from 1 to n) is formed as follows:

Print numbers incrementing from 1 to i.
Then print numbers decrementing from i back down to 1.
Each row should be centered relative to the pyramid to maintain alignment.
For example, if n = 4, the resulting pyramid will be:


1      1
12    21
123  321
12344321
This pattern illustrates increasing numbers from the left, decreasing numbers to the right, while spaces are used to center the rows in relation to the overall height of the pyramid.

Example 1:

Input:

n = 1

Output:

11
Explanation:Single row with just 1 and 1

Example 2:

Input:

n = 2

Output:

1  1
1221
Explanation:Two rows following the pattern rules

Example 3:

Input:

n = 3

Output:

1    1
12  21
123321
Explanation:Three rows with proper spacing

Constraints

1 <= n <= 9*/


#include<iostream>
using namespace std;
class Solution {
public:
    void printPattern(int n) {
        // row iterate 
        for (int i=1;i<=n;i++){
            //loop1:counting
            for(int j=1;j<=i;j++){
                cout<<j;
            }
            //loop2:spaces
            for(int j=1;j<=2*(n-i);j++){
                cout<<" ";
            }
            //;oop3 : back counting
            for(int j=i;j>=1;j--){
                cout<<j;
            }
            cout<<endl;
        }
        
        
    }
};