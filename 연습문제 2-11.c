// 한 해의 지난 날 수를 구합니다.
// Q : dayofyear 함수를 변수 i와 days를 사용하지 않고 구현해 보세요. 또한 for문이 아닌 while문을 사용하세요. 
#include <stdio.h>

// 각 달의 날 수 
int mdays[][12] ={
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// year년이 윤년인가?
int isleap(int year){
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
// y년 m월 d일의 그 해 지난 난 수를 구합니다.

int dayofyear(int y, int m, int d){
	while (--m)
		d += mdays[isleap(y)][m - 1];
	return (d);
} 

int main(void){
	int year, month, day;
	int retry; // 다시?
	do{
		printf("년 : "); scanf("%d", &year);
		printf("월 : "); scanf("%d", &month);
		printf("일 : "); scanf("%d", &day);
		printf("%d년의 %d일째입니다.\n", year, dayofyear(year,month,day));
		printf("다시 할까요?(1...예, 2...아니오) :"); scanf("%d", &retry); 
	}while(retry==1);	
	return 0;
}
