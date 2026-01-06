#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> myList;

    // Adding elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Displaying the elements of the list
    cout << "Elements in the list: ";
    for (int value : myList) {
        cout << value << " ";
    }
    cout << endl;

    // Removing an element from the list
    myList.remove(20);

    // Displaying the elements after removal
    cout << "Elements in the list after removal: ";
    for (int value : myList) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
