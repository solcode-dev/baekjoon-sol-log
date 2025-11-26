#include <iostream>
#include <vector>
using namespace std;

/* m~n(포함)의 소수를 모두 출력하는 프로그램을 작성 */
int main() {
  int n, m;
  // cin >> m;
  // cin >> n;

  // ==== TEST 용
  n = 16;
  m = 3;
  // ====

  // 소수 체크
  vector<bool> check(n + 1, false); // 지워졌으면 true

  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      if ((long long)i * i > n)
        break; // i*i가 n을 초과하면 더 이상 체크 불필요
      for (int j = i * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }

  for (int i = m; i <= n; i++) {
    // 지워지지 않았으면 소수 (단, 2 이상이어야 함)
    if (i >= 2 && !check[i]) {
      cout << i << "\n";
    }
  }
}