#include <iostream>
using namespace std;
int main()
{
    int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	

	int target;
	cout << "Enter the  number to search :";
	cin >> target;

	for (int i=0; i<n ;i++)
	{
		if(arr[i] == target){
			cout << "Element found in index: " << i << endl;
			return 0;
		}
	}
	cout <<  "Element not found" << endl;
	return 0;
}
