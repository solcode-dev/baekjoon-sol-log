#include <vector>
using namespace std;

int solution(int n) {
  vector<bool> check(n + 1, false); // 지워졌으면 true

  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      for (int j = i * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }

  int result = 0;
  for (int i = 2; i <= n; i++) {
    if (!check[i])
      result += 1;
  }

  return result;
}