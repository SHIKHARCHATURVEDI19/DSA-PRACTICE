#include<iostream>
using namespace std;
  



/* 
Number Pyramid Pattern
Your task is to generate a pyramid-shaped pattern of numbers based on a given integer n. The pyramid will contain n rows, and each row i will have numbers starting from 1 up to i. The numbers in each row should be centrally aligned to form a pyramid shape.

Example:
If n is 4, the output should be:


      1
    1 2
  1 2 3
1 2 3 4
Details:
The pyramid is built from a series of rows with each subsequent row having increasing numbers.
Align each row in a centered format, filling the space to the left with necessary spaces to maintain the pyramid structure.
Example 1:

Input:

n = 1

Output:

1
Explanation:Single row with one number

Example 2:

Input:

n = 2

Output:

 1 
1 2 
Explanation:Two rows showing progression of numbers

Example 3:

Input:

n = 3

Output:

  1 
 1 2 
1 2 3 
Explanation:Three rows with proper spacing

Constraints

1 <= n <= 20
*/





class Solution {
public:
  void printNumberPyramid(int n) {
    // Implement the pattern printing logic here
    // it over rows
    for (int r = 1; r <= n; r++) {
      // spaces
      for (int j = 1; j <= (n- r); j++) {
        cout << " ";
      }

      // digits j
      for (int j = 1; j <= r; j++) {
        cout<< j << " ";
      }
      cout << endl;
    }
  }
};