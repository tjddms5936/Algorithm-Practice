// Q&A 5-5 : recur3 함수를 다시 비재귀적으로 구현하세요 
/*
void recur3(int n){
	if(n>0){
		recur3(n-1);
		recur3(n-2);
		printf("%d\n", n);
	}
}
*/ 

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

void recur3(int n)
{
	int sw = 0;
	IntStack nstk, sstk;			/* 스택 */

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (n > 0) {
			Push(&nstk, n);
			Push(&sstk, sw);

			if (sw == 0)
				n = n - 1;
			else if (sw == 1) {
				n = n - 2;
				sw = 0;
			}
			continue;
		}
		do {
			Pop(&nstk, &n);
			Pop(&sstk, &sw);
			sw++;

			if (sw == 2) {
				printf("%d\n", n);
				if (IsEmpty(&nstk))
					return;
			}
		} while (sw == 2);
	}

	Terminate(&nstk);
	Terminate(&sstk);
}

int main(void)
{
	int x;

	printf("정수를 입력하세요. : ");
	scanf("%d", &x);

	recur3(x);

	return 0;
}
