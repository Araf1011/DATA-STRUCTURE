#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    cout << "enter the numbers of the array: ";
    for (int i = 0; i < n; i++)
    {
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for(int j = 0;j<n;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    
}

/*
    1 2 3
    4 5 6
    7 8 9

    1 2 3 
    4 5 6
    7 8 9

    1 4 7 
    2 5 8 
    3 6 9

*/
