import sys

input = sys.stdin.readline
# word = str.lower(input())
word = input().strip().lower()

# 1. 각 글자 세기

# {}: 빈 딕셔너리(dictionary) 생성
# 딕셔너리는 {키: 값} 형태로 데이터를 저장 (예: {'a': 3, 'b': 2})
cnt = {}

# for ... in ...: 반복문 (word의 각 문자를 하나씩 꺼냄)
for ch in word:  # ch: 현재 문자를 담는 변수
    cnt[ch] = (
        cnt.get(ch, 0) + 1
    )  # cnt.get(ch, 0): 딕셔너리에서 ch 키의 값을 가져오되, 없으면 0 반환

# 2. 가장 큰 value 찾기
# cnt.values(): 딕셔너리의 모든 값들을 가져옴
# max(): 최댓값 찾기
# 가장 많이 나온 횟수를 찾음
max_val = max(cnt.values())

# 3. 리스트 컴프리헨션
# [ ... for ... in ... if ... ]: 리스트 컴프리헨션 (리스트를 간결하게 만드는 문법)
# cnt.items(): 딕셔너리의 (키, 값) 쌍들을 가져옴
# k, v: 키와 값을 각각 변수에 할당 (언패킹)
# if v == max_val: 조건문 (값이 최댓값인 경우만)
# 결과: 최댓값을 가진 모든 키들의 리스트
tops = [k for k, v in cnt.items() if v == max_val]

# 조건A if 조건 else 조건B: 삼항 연산자 (조건에 따라 다른 값 선택)
# len(tops): 리스트의 길이
# tops[0]: 리스트의 첫 번째 요소 (인덱스는 0부터 시작!)
# print(): 화면에 출력
print("?" if len(tops) > 1 else tops[0].upper())
