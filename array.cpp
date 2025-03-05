#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << endl;
    int q;
    cin >> q;
    bool flag = false;
    //for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == q)
    //     {
    //         flag = true;
    //     }
    // }
    // if (flag)
    // {
    //     cout << "Found";
    // }
    // else
    // {
    //     cout << "Not Found";
    // }
    sort(v.begin(), v.end());
    int low = 0;
    int high = n - 1;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (v[mid] == q)
        {
            flag = true;
            break;
        }
        else if (v[mid] > q)
        {
            high = mid - 1;
        }
        else if (v[mid] < q)
        {
            low = mid + 1;
        }
    }
    if (flag)
    {
        cout << "found";
    }
    else
    {
        cout << "Not found";
    }
}
