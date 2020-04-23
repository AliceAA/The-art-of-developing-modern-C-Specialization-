#include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;


#include <bits/stdc++.h> 
using namespace std; 
  
// Function to display the array 
void display(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << a[i] << "  "; 
    } 
    cout << endl; 
} 
  
// Function to find the permutations 
void findPermutations(int a[], int n) 
{ 
  
    // Sort the given array 
    sort(a, a + n, greater<int>()); 
  
    // Find all possible permutations 
    //cout << "Possible permutations are:\n"; 
    do { 
        display(a, n); 
    } while (prev_permutation(a, a + n)); 
} 
  
// Driver code 
int main() 
{ 
    int choose;
    cin>>choose;
    //vector<int> a;
    int a[choose];// = { 10, 20, 30, 40 }
    for( int i = 1; i <= choose; i++ )
      {a[i-1] = i;}
  
    int n = sizeof(a) / sizeof(a[0]); 
  
    findPermutations(a, n); 
  
    return 0; 
} 