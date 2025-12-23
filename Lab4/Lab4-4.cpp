#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9};

    if (binary_search(arr, arr + 5, 7))
        cout << "Found";
    else
        cout << "Not found";

    return 0;
}
