#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string line;
  getline(cin, line);
  // cout << "입력: " << line << '\n';

  bool tag = false;
  string ans;
  stack<char> s;

  for (char ch : line) {
    if (ch == '<') {
      while (!s.empty()) {
        ans += s.top();
        s.pop();
      }
      tag = true;
    }

    if (tag) {
      ans += ch;
    } else {
      if (ch == ' ') {
        while (!s.empty()) {
          ans += s.top();
          s.pop();
        }
        ans += ch;
      } else {
        s.push(ch);
      }
    }

    if (ch == '>') {
      tag = false;
    }
  }

  while (!s.empty()) {
    ans += s.top();
    s.pop();
  }
  cout << ans;
}