# 프로그래머스: 최대공약수와 최소공배수 - 오답노트

## 문제 정보
- **문제 출처**: 프로그래머스
- **문제명**: 최대공약수와 최소공배수
- **난이도**: Level 1
- **알고리즘**: 유클리드 호제법

## 문제 요약
두 수를 입력받아 최대공약수(GCD)와 최소공배수(LCM)를 배열에 담아 반환하는 문제

### 입출력 예시
```
입력: n = 3, m = 12
출력: [3, 12]  // [최대공약수, 최소공배수]

입력: n = 2, m = 5
출력: [1, 10]
```

## 핵심 개념

### 1. 기본 용어
```
공약수: 두 수를 모두 나누어떨어지게 하는 수
공배수: 두 수의 배수가 동시에 되는 수

예) 12와 18의 경우
공약수: 1, 2, 3, 6
최대공약수(GCD): 6

공배수: 36, 72, 108, ...
최소공배수(LCM): 36
```

### 2. 유클리드 호제법 (Euclidean Algorithm)

**원리**: 
```
gcd(a, b) = gcd(b, r)  (단, r = a % b)
```
두 수 a, b의 최대공약수는 b와 a를 b로 나눈 나머지 r의 최대공약수와 같다.

**예시**: gcd(24, 18)
```
24 % 18 = 6  →  gcd(24, 18) = gcd(18, 6)
18 % 6 = 0   →  gcd(18, 6) = gcd(6, 0)
6 % 0 = 불가능 → gcd(6, 0) = 6

따라서 gcd(24, 18) = 6
```

**동작 과정 (60, 48)**:
```
Step 1: gcd(60, 48)
  60 % 48 = 12  →  gcd(48, 12)

Step 2: gcd(48, 12)
  48 % 12 = 0   →  gcd(12, 0)

Step 3: b == 0이므로 종료
  결과: 12
```

### 3. 최소공배수 공식
```
a × b = gcd(a, b) × lcm(a, b)

따라서,
lcm(a, b) = (a × b) / gcd(a, b)
```

**예시**: lcm(12, 18)
```
gcd(12, 18) = 6
lcm(12, 18) = (12 × 18) / 6 = 216 / 6 = 36
```

## 풀이 코드

### 방법 1: 재귀함수 사용
```cpp
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
```

**장점**: 코드가 간결하고 직관적  
**단점**: 재귀 깊이가 깊어지면 스택 오버플로우 가능 (드물긴 하지만)

### 방법 2: 반복문 사용 (채택) ✅
```cpp
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
```

**장점**: 재귀 호출 없이 안전하게 동작  
**단점**: 재귀보다 코드가 약간 길어짐

### 최종 풀이
```cpp
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
  
  // 최소공배수
  int lcm = (n * m) / gcd_num;
  
  // 결과 반환
  vector<int> answer = {gcd_num, lcm};
  return answer;
}
```

## 구현 포인트

### Vector 초기화 방법
```cpp
// 방법 1: 초기화 리스트 (간결) ✅
vector<int> answer = {gcd_num, lcm};

// 방법 2: 선언 후 할당
vector<int> answer(2);
answer[0] = gcd_num;
answer[1] = lcm;

// 방법 3: push_back 사용
vector<int> answer;
answer.push_back(gcd_num);
answer.push_back(lcm);
```

## 시간복잡도 분석

### 유클리드 호제법
- **시간복잡도**: O(log(min(a, b)))
- 매우 효율적: 큰 수에도 빠르게 동작

### 다른 방법과 비교
```cpp
// ❌ 브루트포스 (비효율적)
int gcd_bruteforce(int a, int b) {
  int result = 1;
  for (int i = 1; i <= min(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      result = i;
    }
  }
  return result;
}
// 시간복잡도: O(min(a, b)) → 매우 느림
```

## 배운 점
- 유클리드 호제법은 GCD를 O(log n) 시간에 구하는 효율적인 알고리즘
- `a × b = gcd × lcm` 관계를 이용하면 LCM도 쉽게 구할 수 있음
- 재귀와 반복문 두 가지 방법 모두 가능하지만, 반복문이 더 안전
- Vector 초기화 리스트(`{a, b}`)를 사용하면 코드가 간결해짐
