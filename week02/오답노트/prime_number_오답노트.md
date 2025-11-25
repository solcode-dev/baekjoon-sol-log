# 소수 알고리즘 - 오답노트

## 문제 정보
- **주제**: 소수 판별 및 에라토스테네스의 체
- **사용 자료구조**: Vector
- **관련 문제**: 프로그래머스 - 소수찾기

## 학습 내용

### 1. 소수 판별 알고리즘
어떤 수 n이 소수인지 아닌지 판별하는 방법

#### 최적화 전 (O(n/2))
```cpp
for (int i = 2; i <= n / 2; i++) {
  if (n % i == 0) {
    return false;
  }
}
```

#### 최적화 후 (O(√n)) ✅
```cpp
for (int i = 2; i * i <= n; i++) {
  if (n % i == 0) {
    return false;
  }
}
```

**핵심 아이디어**:
- n이 합성수라면, n = a × b로 표현 가능
- 만약 a > √n 이고 b > √n 이면, a × b > n (모순)
- 따라서 **√n 까지만 확인**하면 충분함

---

### 2. 에라토스테네스의 체
n 이하의 모든 소수를 찾는 효율적인 알고리즘

## 발견한 오류들

### 오류 1: Vector 배열과 Vector 타입 혼동 ⚠️

#### ❌ 잘못된 코드 (컴파일 에러)
```cpp
vector<int> prime[n];  // ← vector<int> 타입의 배열 (벡터가 n개)
int prime_cnt = 0;
bool check[n];

for (int i = 2; i <= n; i++) {
  if (check[i] == false) {
    prime[prime_cnt++] = i;  // ❌ vector<int>에 int를 대입할 수 없음!
  }
}
```

**에러 메시지**:
```
No viable overloaded '='
```

**문제점**:
- `prime[prime_cnt++]`는 `vector<int>` 타입
- `i`는 `int` 타입
- `vector<int>` 객체에 `int` 값을 직접 대입(=) 불가능

#### ✅ 올바른 코드
```cpp
vector<int> prime;  // ← 단일 vector (정수를 저장하는 벡터)
bool check[n];

for (int i = 2; i <= n; i++) {
  if (check[i] == false) {
    prime.push_back(i);  // ✅ push_back() 메서드로 값 추가
  }
}
```

**해결 방법**:
1. `vector<int> prime[n]` → `vector<int> prime` 변경
2. `prime[prime_cnt++] = i` → `prime.push_back(i)` 변경
3. `prime_cnt` 변수 제거 (필요 없음)

---

### 오류 2: 함수 반환값 누락 ⚠️

#### ❌ 잘못된 코드 (경고 발생)
```cpp
vector<int> get_primes(int n) {
  vector<int> prime;
  // ... 로직 ...
}  // ❌ return 문 없음!
```

**경고 메시지**:
```
Non-void function does not return a value
```

#### ✅ 올바른 코드
```cpp
vector<int> get_primes(int n) {
  vector<int> prime;
  // ... 로직 ...
  return prime;  // ✅ 결과 반환
}
```

---

### 오류 3: C 스타일 배열을 Vector로 변경 ⚠️

#### ❌ C 스타일 배열 (초기화 문제)
```cpp
bool check[n];  // ❌ 초기화되지 않음 (쓰레기 값 포함 가능)

for (int i = 2; i <= n; i++) {
  if (check[i] == false) {  // 초기화 안 된 값 참조
    // ...
  }
}
```

**문제점**:
- C 스타일 배열은 자동 초기화되지 않음
- 쓰레기 값으로 인해 예상치 못한 동작 발생 가능

#### ✅ Vector로 초기화
```cpp
vector<bool> check(n + 1, false);  // ✅ n+1 크기, 모두 false로 초기화

for (int i = 2; i <= n; i++) {
  if (check[i] == false) {
    // ...
  }
}
```

**장점**:
- 자동 초기화로 안전성 보장
- 크기 조정 용이
- 현대 C++ 권장 방식

---

## 에라토스테네스의 체 - 완전한 구현

### 최종 코드
```cpp
vector<int> get_primes(int n) {
  vector<int> prime;                // 소수 저장 벡터
  vector<bool> check(n + 1, false); // false: 소수, true: 합성수
  
  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {  // i가 소수라면
      prime.push_back(i);     // 소수 목록에 추가
      
      // i의 배수들을 모두 합성수로 표시
      for (int j = i * 2; j <= n; j += i) {
        check[j] = true;
      }
    }
  }
  
  return prime;
}
```

### 알고리즘 동작 과정 (n=20)

```
초기: check = [F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F]
인덱스:        0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

i=2 (소수):
  prime = [2]
  2²=4부터 4,6,8,10,12,14,16,18,20을 true로 표시
  
i=3 (소수):
  prime = [2, 3]
  3²=9부터 9,12,15,18을 true로 표시
  
i=4: check[4]=true (건너뜀)

i=5 (소수):
  prime = [2, 3, 5]
  5²=25 > 20 (범위 초과, 배수 처리 안 함)
  
i=6: check[6]=true (건너뜀)
i=7 (소수):
  prime = [2, 3, 5, 7]
  7²=49 > 20 (범위 초과)
  
i=8~10: 모두 합성수 (건너뜀)
i=11 (소수):
  prime = [2, 3, 5, 7, 11]
  11²=121 > 20 (범위 초과)
  
i=12: check[12]=true (건너뜀)
i=13 (소수):
  prime = [2, 3, 5, 7, 11, 13]
  
...

최종 결과: prime = [2, 3, 5, 7, 11, 13, 17, 19]
```

---

## 핵심 체크포인트

### ✅ Vector 사용법
```cpp
// 선언 방법
vector<int> v;              // 빈 벡터
vector<int> v(n);           // 크기 n, 기본값(0)으로 초기화
vector<int> v(n, val);      // 크기 n, val로 초기화

// 값 추가
v.push_back(value);         // 맨 뒤에 추가

// 값 대입 (인덱스 접근)
v[i] = value;               // i번째 위치에 대입 (크기 확인 필요)
```

### ✅ 에라토스테네스의 체 최적화 포인트

1. **배수 시작점**: `j = i * i`부터 시작
   - i의 작은 배수(2i, 3i, ...)는 이미 체크됨
   - 예: i=5일 때, 10(=2×5), 15(=3×5)는 이미 제거됨

2. **범위 체크**: `i * i <= n`
   - √n 이후의 소수는 배수 제거 불필요
   - 해당 범위의 합성수는 이미 제거됨

3. **초기화**: `vector<bool> check(n+1, false)`
   - n까지 확인하려면 n+1 크기 필요 (인덱스 0~n)
   - 모두 false로 초기화 (소수 가정)

### 🔑 시간복잡도

| 알고리즘 | 시간복잡도 | 설명 |
|---------|-----------|------|
| 단일 소수 판별 (√n) | O(√n) | 하나의 수가 소수인지 확인 |
| n까지 소수 찾기 (브루트포스) | O(n√n) | 1~n까지 각각 소수 판별 |
| **에라토스테네스의 체** | **O(n log log n)** | **가장 효율적** |

---

## 실전 적용: 프로그래머스 - 소수찾기

### 문제
1부터 n까지의 수 중 소수의 개수를 구하라.

### 풀이 코드
```cpp
int solution(int n) {
  vector<bool> check(n + 1, false);
  
  // 에라토스테네스의 체로 합성수 표시
  for (int i = 2; i <= n; i++) {
    if (check[i] == false) {
      for (int j = i * 2; j <= n; j += i) {
        check[j] = true;
      }
    }
  }
  
  // 소수 개수 카운트
  int result = 0;
  for (int i = 2; i <= n; i++) {
    if (!check[i])
      result += 1;
  }
  
  return result;
}
```

---

## 배운 점

1. **Vector 배열 vs 단일 Vector**
   - `vector<int> arr[n]`: 벡터가 n개 있는 배열
   - `vector<int> arr`: 정수를 저장하는 단일 벡터
   - 대입 연산자(=)는 같은 타입끼리만 가능

2. **함수 반환값 필수**
   - 반환 타입이 `void`가 아니면 반드시 `return` 문 필요
   - 컴파일러 경고를 무시하지 말 것

3. **Vector 초기화의 중요성**
   - C 배열보다 Vector 사용 권장 (안전성, 편의성)
   - 생성자를 통한 초기화로 버그 예방

4. **에라토스테네스의 체 최적화**
   - `i * i`부터 시작: 작은 배수는 이미 제거됨
   - `i * i <= n`: √n 이후는 배수 제거 불필요
   - 시간복잡도 O(n log log n)로 매우 효율적

5. **소수 판별 최적화**
   - √n까지만 확인하면 충분
   - `i * i <= n` 조건이 `i <= sqrt(n)`보다 빠름 (sqrt 함수 호출 불필요)
