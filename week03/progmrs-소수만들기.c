#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
  
  //1. 세 수의 합의 길이만큼을 담을 배열을 만든다
  #define MAX_SUM 3000
  bool check[MAX_SUM] = {false};

  //2. 에라토스테네스의 체를 만든다
  for(int i = 2; i < MAX_SUM; i++) {
    if(check[i] == false) {
      if( i * i > MAX_SUM ) continue;
      for(int j = i * i; j <= MAX_SUM; j += i) {
        check[j] = true;  // 배수를 지운다
      }
    }
  }

  // 3. nums에 있는 수 3개를 더한 수 중 소수의 개수를 구한다.
  // 아이디어: 조합 (중복없이 k개 선택하기 위해 인덱스에 순서를 강제한다)
  int count = 0;
  for(int i = 0; i < nums_len - 2; i++) {
    for(int j = i + 1; j < nums_len - 1; j++) {
      for(int k = j + 1; k < nums_len; k++) {
        int sum = nums[i] + nums[j] + nums[k];
        if(check[sum] == false)
          count++;
      }
    }
  }
  
  return count;
}