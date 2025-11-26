#include <vector>
using namespace std;

/* 에라토스테네스의 체로 소수 찾기 */
int solution(int n) {
  vector<bool> check(n + 1, false); // 지워졌으면 true

  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      for (int j = i * i; j <= n; j += i) {
        // 2의 배수에서 2씩 더해간다.
        // 3의 배수에서 3씩 더해간다.
        // 4의 배수에서 4씩 더해간다.
        check[j] = true; // 배수를 지운다
      }
    }
  }

  int result = 0;
  for (int i = 2; i <= n; i++) {
    // 지워지지 않았으면 소수
    if (!check[i])
      result += 1;
  }

  return result;
}