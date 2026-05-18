#include <iostream>
using namespace std;

int search(int arr[], int l, int r, int target) {
    if(l > r) return -1;

    int mid = l + (r - l) / 2;
if(arr[mid] == target) 
    return mid;
    
    
 else if(target < arr[mid])
     return search(arr, l, mid - 1, target);
   
     else 
     return search(arr, mid + 1, r, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = search(arr, 0, n - 1, target);

    cout << result << endl;

    return 0;
}