#include <stdio.h>
#include <stdlib.h>

// 단순 삽입 정렬 함수
void insertion(int a[], int n){
    int i, j;
    for(i=1; i<n; i++){
        int tmp = a[i];
        for(j = i; j>0 && a[j-1] > tmp; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

int main(void){
    int i, nx;
    int *x;
    printf("Number of Elements :"); scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i=0; i<nx; i++){
        printf("x[%d] : ", i); scanf("%d", &x[i]);
    }
    insertion(x, nx);
    printf("Finish the insertion\n");
    for(i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}