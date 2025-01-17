// Given a sorted array of integers, implement a function to find the first occurrence of a given target value using binary search. After finding the first occurrence, implement an extension to return the count of occurrences of the target value in the array. If the target is not found, return -1.

#include <iostream>
using namespace std;

pair<int, int> findFirstAndCount(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int first = -1, count = 0;

  
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first = mid;
            right = mid - 1; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (first == -1) {
        return make_pair(-1, -1); 
    }

  
    for (int i = first; i < n && arr[i] == target; ++i) {
        count++;
    }

    return make_pair(first, count);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

   
    int* arr = new int[n];
    cout << "Enter " << n << " sorted integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    pair<int, int> result = findFirstAndCount(arr, n, target);

    if (result.first == -1) {
        cout << -1 << " (Target not found)" << endl;
    } else {
        cout << "(" << result.first << ", " << result.second << ") (The first occurrence is at index " << result.first
             << ", and there are " << result.second << " occurrences of " << target << ")" << endl;
    }

   
    delete[] arr;

    return 0;
}
