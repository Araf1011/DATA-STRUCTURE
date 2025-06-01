//Bit++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s.find("++") != string::npos)
        {
            count++;
        }
        else if(s.find("--") != string::npos)
        {
            count--;
        }
    }
    cout << count << endl;
    return 0;
}