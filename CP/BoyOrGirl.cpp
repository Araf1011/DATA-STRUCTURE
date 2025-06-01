#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test ;
    while (test--)
    {
        string s;
        cin >> s;

        int length = s.length();
        if(length % 2 == 0)
        {
            cout << " CHAT WITH HER!" <<endl;
        }
        else 
        {
            cout << " IGNORE HIM!" <<endl;
        }
    }
    return 0;
}