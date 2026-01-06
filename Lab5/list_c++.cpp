#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {
  stack<char> s;
  cout << s.empty() << endl;                     // currently s is empty, true (1)
  cout << "==================" << endl;
  s.push('a');
  s.push('b');
  s.push('c');
  // stack is LIFO, thus the content of s is currently like this:
  // c <- top
  // b
  // a
  cout << s.top() << endl;                       // output 'c'
  s.pop();                                       // pop topmost
  cout << s.top() << endl;                       // output 'b'
  cout << s.empty() << endl;                     // output false (0)
  cout << "==================" << endl;
  queue<char> q;
  cout << q.empty() << endl;                     // output true (1)
  cout << "==================" << endl;
  while (!s.empty()) {                           // s has 2 more items
    q.push(s.top());                             // enqueue 'b' and 'a'
    s.pop();
  }
  q.push('z');                                   // add one more item
  cout << q.front() << endl;                     // prints 'b'
  cout << q.back() << endl;                      // prints 'z'
  // output 'b', 'a', then 'z' (until queue is empty), according to the insertion order above
  cout << "==================" << endl;
  while (!q.empty()) {
    cout << q.front() << endl;                   // take the front first
    q.pop();                                     // before popping it
  }
  cout << "==================" << endl;
  deque<char> d;
  d.push_back('a');
  d.push_back('b');
  d.push_back('c');
  cout << d.front() << " - " << d.back() << endl;  // prints 'a - c'
  d.push_front('d');
  cout << d[0] << d[1] << d[2] << d[3] << endl;    // only in C++, 'dabc'
  cout << d.front() << " - " << d.back() << endl;  // prints 'd - c'
  d.pop_back();
  cout << d.front() << " - " << d.back() << endl;  // prints 'd - b'
  d.pop_front();
  cout << d.front() << " - " << d.back() << endl;  // prints 'a - b'
  return 0;
}
