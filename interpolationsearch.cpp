#include <iostream>
using namespace std;

// Function to perform Interpolation Search
int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }

        // Calculate the position using the interpolation formula
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Check if the element at pos is the target
        if (arr[pos] == x)
            return pos;

        // If x is larger, it is in the upper part
        if (arr[pos] < x)
            low = pos + 1;
        // If x is smaller, it is in the lower part
        else
            high = pos - 1;
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 70; // Element to search for

    int result = interpolationSearch(arr, n, x);

    if (result != -1)
        cout << "Element " << x << " found at index " << result << endl;
    else
        cout << "Element " << x << " not found in the array" << endl;

    return 0;
}
