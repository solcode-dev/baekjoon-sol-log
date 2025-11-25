#include <vector>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

vector<int> solution(int n, int m) {

  // 최대공약수
  int gcd_num = gcd(n, m);

  // 최소 공배수
  int lcm = (n * m) / gcd_num;

  vector<int> answer = {gcd_num, lcm};
  // answer[0] = gcd_num;
  // answer[1] = lcm;
  return answer;
}