#include<stdio.h>
/*
.L3:                  //start of inner for loop
movl (%edx), %esi     //move &a[0][0]+(j*N+i) to esi
movl (%eax), %ecx     //move &a[0][0]+(i*N+j) to ecx
addl $4, %eax         //add to j each loop
addl $40, %edx        //add to i each loop
movl %esi, -4(%eax)   //move &a[0][0]+(j*N+i) into *col
movl %ecx, -40(%edx)  //move &a[0][0]+(i*N+j) into *row
cmpl %ebx, %eax       //compare i to N
jne .L3               //jump not equal,when j!=i and i!=N

*/

#define N 4                                 //set to 4 because array_t for test input is [4][4]
typedef int array_t[N][N];                  //create array of arrays size N by N

void tranpose(array_t a) {
    for(int i = 0; i != N; i++) {           //Loops through increment until i=n
        for(int j = 0; j != i; j++) {       //loops through increment until j=i
            int *row = &a[0][0]+(i*N+j);    //creates pointer to spot using pointer a[0][0] which is the start of the list and the offset
            int *col = &a[0][0]+(j*N+i);    //creates pointer set to pointer of start of array plus the offset
            int t = *row;                   //hold pointer adress to row
            *row = *col;                    //set row pointer to col
            *col=t;                         //set col to old row pointer location, finalizing the swap
        }
    }
}

void print(array_t a){
  printf("{");
  for (int i = 0; i < N; ++i) {
    printf("{");
  for (int j = 0; j <N-1; ++j) {
    printf("%d, ",a[i][j]);
  }
  printf("%d}",a[i][N-1]);
  }
  printf("}\n");
}


int main(){
    array_t a ={ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(a);
    tranpose(a);
    print(a);
}
