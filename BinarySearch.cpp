#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr,int target)
{
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int mid = (start + end) / 2;
        if(target > arr[mid]){
            start = mid + 1;
        }else if(target < arr[mid]){
            end = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 9, 12};
    int target = 12;

    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found LOL!" << endl;
    }

    return 0;
}
