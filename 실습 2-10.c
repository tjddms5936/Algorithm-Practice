#include <stdio.h>

int main(void){
	int i, n;
	int prime[500]; // 소수를 저장하는 배열 
	int ptr = 0; // 이미 얻은 소수의 개수
	unsigned long counter = 0; // 나눗셈 횟수
	prime[ptr++] = 2; // 2는 소수입니다. 
	for(n=3; n<=1000; n+=2){ // 홀수만 조사 할 것임
		for(i=1; i<ptr; i++){ // 이미 얻은 소수로 나눕니다. 
			counter++;
			if(n % prime[i] == 0){ // 나누어 떨어지므로 n은 소수가 아닙니다. 
				break;
			}
		}
		if(ptr == i){ // 마지막까지 나누어 떨어지지 않았다면 n은 소수입니다. 
			prime[ptr++] = n; // 배열에 저장합니다.  
		} 
	}
	for(i=0; i<ptr; i++){
		printf("%d\n", prime[i]);
	} 
	printf("나눗셈을 실행한 횟수 : %lu", counter);
	
	return 0;
}
