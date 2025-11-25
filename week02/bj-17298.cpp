#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  // 1. 입력배열 A와 오큰수 배열 NGE을 만든다.
  int a_size;
  cin >> a_size;
  vector<int> a(a_size, 0);
  vector<int> NEG(a_size, 0);
  for (int k = 0; k < a_size; k++) {
    cin >> a[k];
  }

  // 1. 아직 오큰수를 찾지 못한 원소의 "인덱스"를 스택에 저장한다.
  stack<int> s;
  s.push(0); // 첫번째 요소는 오큰수가 아직 없으니까.

  // 2. 현재 원소가 스택 top의 원소보다 크면? 그게 바로 top의 오큰수.
  for (int i = 1; i < a_size; i++) {
    while (!s.empty() && a[s.top()] < a[i]) {
      NEG[s.top()] = a[i];
      s.pop();
    }
    s.push(i);
  }

  // 3. 스택에 남은 인덱스는 오큰수가 없는 수이므로 -1
  while (!s.empty()) {
    NEG[s.top()] = -1;
    s.pop();
  }

  // 4. 공백으로 구분해서 출력
  for (int i = 0; i < NEG.size(); i++) {
    cout << NEG[i] << " ";
  }
}