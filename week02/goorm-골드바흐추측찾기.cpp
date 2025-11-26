// 골드바흐의 추측: 4이상의 모든 짝수는 두 소수의 합으로 나타낼 수 있다
// 주어진 짝수 n을 두 소수의 합으로 나타내는 골드바흐 파티션의 개수구하기
// 단, 두 소수의 순서만 다른 것은 같은 파티션으로 간주한다.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  // 1. 에라토스테네스의 체를 사용해 n이하의 소수를 구한다.
  vector<bool> check(n + 1, false); // 지워졌으면 true
  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      if (n < (long long)i * i)
        break;
      for (int j = i * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }

  // 골드바흐 파티션: n을 두 소수의 합으로 나타내는것
  // 2. n - (해당소수) == 소수 인지 확인한다.
  int cnt = 0;
  for (int i = 2; i <= n / 2; i++) {
    if (!check[i]) {
      int index = n - i;
      if (!check[index]) {
        cnt++;
      }
    }
  }

  cout << cnt;
}
