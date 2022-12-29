#include <iostream>
//#define myTest 1
using namespace std;

void print(int arr[], const int size) 
{
    int i; 
    for (i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;
}

int main()
{
    #ifndef myTest
    int i, n = 3, s1[3]{2, 3, 1}, s2[n]{2, 1,3}, s1s2[n], s2s1[n];
    cout << "s1 = "; print(s1, n); cout << "s2 = "; print(s2, n);
    #endif
    
    #if (myTest)
    int n, i;
    cout << "Please enter the permutation's size: "; cin >> n; 
    int s1[n], s2[n], s1s2[n], s2s1[n];
    cout<< "Please enter the first permutation: "; for (i = 0; i < n; i++) cin >> s1[i];
    cout<< "Please enter the second permutation: "; for (i = 0; i < n; i++) cin >> s2[i];
    #endif
    
    for (i = 0; i < n; i++) s1s2[i] = s1[s2[i] - 1];
    for (i = 0; i < n; i++) s2s1[i] = s2[s1[i] - 1];
    cout << "s1 * s2 = "; print(s1s2, n);
    cout << "s2 * s1 = "; print(s2s1, n);
    cout << "So, s1*s2 is not equal to s2*s1\n";
    
    for(i = 0; i < n; i++) s2[s1[i]-1] = i + 1;
    cout << "Inverse permutation = "; print(s2, n);
    return 0;
}