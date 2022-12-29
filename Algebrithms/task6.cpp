#include <iostream>
//#define myTest 1
using namespace std;

void print(int arr[], const int size) 
{
    int i; 
    for (i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;
}

void cycle(int i, int j, int k, int s1[], int s2[])
{
        int tmp = s1[k];
        s1[k] = s1[j];
        s1[j] = s1[i];
        s1[i] = tmp;

        s2[s1[i]] = i;
        s2[s1[j]] = j;
        s2[s1[k]] = k;
};

int main()
{
    #ifndef myTest
    int i, j, n = 5, s[5]{1, 5, 4, 2, 3}, s1[n], s2[n];
    cout << "s = "; print(s, n); 
    #endif
    
    #if (myTest)
    int n, i, j;
    cout << "Please enter the permutation's size: "; cin >> n; 
    int s[n], s1[n], s2[n];
    cout<< "Please enter the permutation: "; for (i = 0; i < n; i++) cin >> s[i];
    #endif

    for (i = 0; i < n; i++) { s[i] = s[i] - 1; s1[i] = i; s2[i] = i;}
    
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s[i]) 
        {
            j = s2[s[i]];
            if (j != n - 1) cycle(n - 1, j, i, s1, s2);
            else cycle(n - 2, j, i, s1, s2);
        }
    }
    
    if (s1[n - 1] == s[n - 1]) cout << "Even\n";
    else cout << "Odd\n";

    return 0;
}