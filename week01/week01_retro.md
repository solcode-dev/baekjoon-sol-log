# Week 01 알고리즘 학습 복기

## 학습 기간
Week 01

## 풀이한 문제 목록

### 백준
- [bj-1157.py](bj-1157.py) - 단어 공부 (문자열, 딕셔너리)

### 구름 문제 (총 22문제)
1. [goorm-0채우기.py](goorm-0채우기.py)
2. [goorm-8진수계산기.py](goorm-8진수계산기.py)
3. [goorm-A+B.py](goorm-A+B.py)
4. [goorm-A+B(2).py](goorm-A+B(2).py)
5. [goorm-Queue.py](goorm-Queue.py)
6. [goorm-m배배열.py](goorm-m배배열.py)
7. [goorm-거스름돈.py](goorm-거스름돈.py)
8. [goorm-구름스퀘어.py](goorm-구름스퀘어.py)
9. [goorm-구름아이돌.py](goorm-구름아이돌.py)
10. [goorm-단어필터.py](goorm-단어필터.py)
11. [goorm-대소문자바꾸기.py](goorm-대소문자바꾸기.py)
12. [goorm-밀도정렬.py](goorm-밀도정렬.py)
13. [goorm-수열.py](goorm-수열.py)
14. [goorm-숫자배열.py](goorm-숫자배열.py)
15. [goorm-숫자제거배열.py](goorm-숫자제거배열.py)
16. [goorm-숫자제거정렬.py](goorm-숫자제거정렬.py)
17. [goorm-연속점수.py](goorm-연속점수.py)
18. [goorm-정수의길이.py](goorm-정수의길이.py)
19. [goorm-출석부.py](goorm-출석부.py)
20. [goorm-카드모으기.py](goorm-카드모으기.py)
21. [goorm-큰수식찾기.py](goorm-큰수식찾기.py)
22. [goorm-큰팩토리얼.py](goorm-큰팩토리얼.py)

**총 풀이 문제 수: 23문제**

---

## 주요 학습 내용

### 1. 자료구조
#### 딕셔너리 (Dictionary)
- 문제: [bj-1157.py](bj-1157.py)
- 학습 내용:
  - `{}`: 빈 딕셔너리 생성
  - `.get(key, default)`: 키가 없을 때 기본값 반환
  - `.items()`: (키, 값) 쌍 접근
  - `.values()`: 값들만 접근
- 활용: 문자 빈도수 계산

#### 큐 (Queue)
- 문제: [goorm-Queue.py](goorm-Queue.py)
- 학습 내용:
  - 리스트로 큐 구현
  - `append()`: 큐에 삽입 (rear)
  - `pop(0)`: 큐에서 제거 (front)
  - Overflow/Underflow 처리
- 주의: `pop(0)`는 O(n) 시간복잡도 (실무에서는 `collections.deque` 사용 권장)

#### 집합 (Set)
- 문제: [goorm-숫자제거정렬.py](goorm-숫자제거정렬.py)
- 학습 내용:
  - `set()`: 중복 제거
  - `sorted()`: 정렬된 리스트 반환

### 2. 정렬 (Sorting)
#### 기본 정렬
- 문제: [goorm-출석부.py](goorm-출석부.py)
- 학습 내용:
  - `sort()` vs `sorted()` 차이
  - `lambda` 함수를 이용한 커스텀 정렬
  - 튜플 정렬 (여러 기준)

#### 조건부 정렬
- 문제: [goorm-밀도정렬.py](goorm-밀도정렬.py)
- 학습 내용:
  - 우선순위가 있는 정렬 로직
  - 조건문을 통한 최적값 찾기
  - 밀도 > 무게 > 번호 순 우선순위

### 3. 알고리즘 패턴
#### 연속된 값 처리
- 문제: [goorm-연속점수.py](goorm-연속점수.py)
- 학습 내용:
  - 연속된 수열 판별: `scores[i] == scores[i-1] + 1`
  - 누적 합 계산
  - 최댓값 갱신 로직
  - 마지막 구간 처리 주의

#### 리스트 컴프리헨션
- 문제: [bj-1157.py](bj-1157.py)
- 학습 내용:
  - `[k for k, v in dict.items() if 조건]`
  - 간결한 리스트 생성
  - 조건부 필터링

### 4. Python 기초 문법
#### 입력 처리
- `input()` vs `sys.stdin.readline()`
- `.strip()`: 공백 제거
- `.split()`: 문자열 분리
- `map(int, input().split())`: 여러 정수 입력

#### 출력 처리
- `print(*list)`: 언패킹을 통한 공백 구분 출력
- 삼항 연산자: `A if 조건 else B`

#### 자료형
- `Decimal`: 정밀한 소수점 계산 ([goorm-출석부.py](goorm-출석부.py))

---

## 배운 점

### 긍정적인 점
1. **주석 작성 습관**: 코드에 상세한 주석을 작성하여 로직을 명확히 이해
2. **다양한 문제 유형**: 자료구조, 정렬, 구현 등 다양한 유형 경험
3. **Python 기초 강화**: 딕셔너리, 리스트 컴프리헨션 등 Python 문법 숙달
4. **문제 해결 과정 기록**: 주석으로 사고 과정 정리

### 개선이 필요한 점
1. **시간복잡도 고려**: Queue에서 `pop(0)` 사용 → `deque` 사용 필요
2. **엣지 케이스 처리**: 마지막 구간, 빈 입력 등 예외 상황 체크
3. **코드 최적화**: 불필요한 변수나 반복 줄이기

---

## 다음 주 학습 계획
- [ ] 더 복잡한 자료구조 (스택, 덱) 활용 문제
- [ ] 시간복잡도를 고려한 최적화 연습
- [ ] C++ 문제 풀이 시작 (week02에서 진행 중)

---

## 통계
- 총 문제 수: 23문제
- 사용 언어: Python
- 주요 주제: 자료구조, 정렬, 구현