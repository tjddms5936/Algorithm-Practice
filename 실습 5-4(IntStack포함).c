// 재귀 알고리즘의 비재귀적 표현
// 함수 recur(꼬리 재귀를 제거)
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int max;		/* 스택 용량 */
	int ptr;		/* 스택 포인터 */
	int *stk;		/* 스택의 첫 요소에 대한 포인터 */
} IntStack;

int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;							
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack *s, int x)
{
	if (s->ptr >= s->max)					
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

/*--- �뒪�깮�뿉�꽌 �뜲�씠�꽣瑜� �뙘 ---*/
int Pop(IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* �뒪�깮�씠 鍮꾩뼱 �엳�쓬 */
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

/*--- �뒪�깮�뿉�꽌 �뜲�씠�꽣瑜� �뵾�겕 ---*/
int Peek(const IntStack *s, int *x)
{
	if (s->ptr <= 0)							/* �뒪�깮�씠 鍮꾩뼱 �엳�쓬 */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

/*--- �뒪�깮 鍮꾩슦湲� ---*/
void Clear(IntStack *s)
{
	s->ptr = 0;
}

/*--- �뒪�깮 �슜�웾 ---*/
int Capacity(const IntStack *s)
{
	return s->max;
}

/*--- �뒪�깮�뿉 �뙎�뿬 �엳�뒗 �뜲�씠�꽣 �닔 ---*/
int Size(const IntStack *s)
{
	return s->ptr;
}

/*--- �뒪�깮�씠 鍮꾩뼱 �엳�뒗媛�? ---*/
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
}

/*--- �뒪�깮��� 媛��뱷 李쇰뒗媛�? ---*/
int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
}

/*--- �뒪�깮�뿉�꽌 寃��깋 ---*/
int Search(const IntStack *s, int x)
{
	int i;

	for (i = s->ptr - 1; i >= 0; i--)	/* 瑗����湲�(top) �넂 諛붾떏(bottom)�쑝濡� �꽑�삎 寃��깋 */
		if (s->stk[i] == x)
			return i;		/* 寃��깋 �꽦怨� */
	return -1;				/* 寃��깋 �떎�뙣 */
}

/*--- 紐⑤뱺 �뜲�씠�꽣 �몴�떆 ---*/
void Print(const IntStack *s)
{
	int i;

	for (i = 0; i < s->ptr; i++)		/* 諛붾떏(bottom) �넂 瑗����湲�(top)濡� �뒪罹� */
		printf("%d ", s->stk[i]);
	putchar('\n');
}

/*--- �뒪�깮 醫낅즺 ---*/
void Terminate(IntStack *s)
{
	if (s->stk != NULL)
		free(s->stk);		/* 諛곗뿴�쓣 �궘�젣 */
	s->max = s->ptr = 0;
}

void recur(int n){
	IntStack stk; // 스택 
	Initialize(&stk, 100);
	Top :
		if(n>0){
			Push(&stk, n); // n의 값을 푸쉬
			n = n-1;
			goto Top; 
		}
		if(!IsEmpty(&stk)){ // 스택이 비어있지 않으면 
			Pop(&stk, &n); // 저장했던 n을 팝. 이때 선입후출임. 
			printf("%d\n", n);
			n = n-2;
			goto Top; 
		}
		Terminate(&stk); // 여기까지 왔다는 것은 빈스택 -> 푸쉬 -> 팝 -> 빈스택 인 상태 
}

int main(void){
	int x;
	printf("정수를 입력하세요 :"); scanf("%d", &x);
	recur(x);
	return 0;
} 
