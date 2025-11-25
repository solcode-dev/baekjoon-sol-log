#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

  string line;
  getline(cin, line);
  stack<int> s; // 스택의 크기: 현재 진행 중인 쇠막대기 개수
  int ans = 0;

  // 0. 입력문자열(str)은 각 문자별로 인덱스를 갖는다.
  for (int i = 0; i < line.length(); i++) {
    // 경우1. ( 을 만났을 때
    if (line[i] == '(') {
      s.push(i);

    } else { // 경우2. ) 을 만났을 때
      // 레이저인 경우
      if (i == s.top() + 1) {
        s.pop();
        ans += s.size(); // 현재 놓여져 있는 쇠막대기들이 모두 잘린다

      } else { // 쇠막대기인 경우
        s.pop();
        ans += 1;
      }
    }
  }

  cout << ans;
}