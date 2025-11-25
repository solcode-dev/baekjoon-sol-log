// 소수와 관련된 알고리즘
// 1. 어떤수 n이 소수인지 아닌지 판별하는 방법
// 2. n이하의 모든 자연수 중에서 소수를 찾아내는 방법
#include <vector>
using namespace std;

// 어떤 수 n이 소수인지 아닌지 판별하는 방법
bool prime_func(int n) {
  if (n < 2) {
    return false;
  }
  // for (int i = 2; i <= n / 2; i++) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// n이하의 모든 자연수 중에서 소수를 찾아내는 방법 : 에라토스테네스의 체
vector<int> get_primes(int n) {
  n = 100;
  vector<int> prime;                // 소수를 저장할 벡터
  vector<bool> check(n + 1, false); // 지워졌으면 true
  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      prime.push_back(i);
      for (int j = i * 2; j <= n; j += i) {
        check[j] = true;
      }
    }
  }
  return prime;
}
