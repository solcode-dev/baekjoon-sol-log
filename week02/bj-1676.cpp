#include <iostream>
using namespace std;

/* n!에서 뒤에서부터 확인했을 때, 처음으로 0이 아닌 숫자가 나올 때까지 0의
 * 개수를 구하는 문제 예)_ 10! = 3,628,800 >> 뒤에 0이 2개
 */
int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 5; i <= n; i *= 5) {
    ans += n / i; // 5의 거듭제곱으로 나눈 몫
  }

  cout << ans << '\n';
  return 0;
}