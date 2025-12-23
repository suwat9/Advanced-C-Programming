#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int A[10]= {10,2,7,4,9,5,3,1,6,8}, x;

    for (const auto &x : A){
        cout << x << " ";
    };
    sort(A, A + 10, greater<int>());
    cout << "\nAfter sorting (Descending order): \n";
    for (const auto &x : A){
        cout << x << " ";
    };
}
