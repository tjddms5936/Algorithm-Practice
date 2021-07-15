// Q&A 5-7 : 실습 5-6의 MOVE함수를 비재귀적으로 수정하세요.

// 하노이의 탑

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

/*--- �썝諛�[1] ~ �썝諛�[no]�쓣 x 湲곕뫁�뿉�꽌 y 湲곕뫁�쑝濡� �씠�룞 ---*/
void move(int no, int x, int y)
{
	int sw = 0;
	IntStack xstk, ystk, sstk;		/* �뒪�깮 */

	Initialize(&xstk, 100);
	Initialize(&ystk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (sw == 0 && no > 1) {
			Push(&xstk, x);				/* x 媛믪쓣 �뫖�떆 */
			Push(&ystk, y);				/* y 媛믪쓣 �뫖�떆 */
			Push(&sstk, sw);			/* sw 媛믪쓣 �뫖�떆 */
			no = no - 1;
			y = 6 - x - y;
			continue;
		}

		printf("�썝諛�[%d]瑜� %d 湲곕뫁�뿉�꽌 %d 湲곕뫁�쑝濡� �씠�룞\n", no, x, y);

		if (sw == 1 && no > 1) {
			Push(&xstk, x);				/* x 媛믪쓣 �뫖�떆 */
			Push(&ystk, y);				/* y 媛믪쓣 �뫖�떆 */
			Push(&sstk, sw);			/* sw 媛믪쓣 �뫖�떆 */
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2) sw = 0;
			continue;
		}
		do {
			if (IsEmpty(&xstk))			/* �뒪�깮�씠 鍮꾩뼱�엳�뒗 �긽�깭�씪硫� */
				return;
			Pop(&xstk, &x);				/* x瑜� �뙘 */
			Pop(&ystk, &y);				/* y瑜� �뙘 */
			Pop(&sstk, &sw);			/* sw瑜� �뙘 */
			sw++;
			no++;
		} while (sw == 2);
	}

	Terminate(&xstk);
	Terminate(&ystk);
	Terminate(&sstk);
}

int main(void){
	int n; // 원반의 개수
	printf("하노이의 탑\n원반 개수 :"); scanf("%d", &n);
	move(n, 1, 3); 
	return 0;
}  
