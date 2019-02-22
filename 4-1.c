#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
loop:
pushl %ebp              //push and save ebp(base pointer) to stack
movl %esp, %ebp         //move esp(stack pointer) to ebp
pushl %esi              //push and save esi for later use
pushl %ebx              //push and save esb for later use
movl 8(%ebp), %esi      //move x into esi
movl 12(%ebp), %ecx     //move y ito ecx
movl $2, %edx           //move mask=2 into edx intializing mask
movl $-1, %eax          //move result=-1 into eax intializing result
.L2:                    //beginning of for loop
movl %esi, %ebx         //move esi(x) to ebx
andl %edx, %ebx         //mask & x into ebx
xorl %ebx, %eax         //result^ebx into eax
sall %cl, %edx          //mask<<y
cmpl $1, %edx           //compare 1 to edx
jg .L2                   //jump greater than if mask > 1
popl %ebx               //remove ebx(mask&x) from stack
popl %esi               //remove esi(x) from the stack
popl %ebp               //remove ebp(base pointer) from the stack
ret                     //return eax(result)
*/

int loop(int x, int y) {
  int result = -1 ;                                   //movl $-1, %eax
  for (int mask = 2 ; mask >1 ; mask = mask<<y ) {    //(movl $2, %edx;  jg .L2;  sall %cl, %edx)
    result ^= mask & x ;                              //xorl %ebx, %eax
  }
  return result;                                      //ret
}


int main(){
	printf("%d\n",loop(1,5));  //  -1
  printf("%d\n",loop(2,4));  //  -3
  printf("%d\n",loop(3,3));  //  -3
  printf("%d\n",loop(4,2));  //  -1
  printf("%d\n",loop(5,1));  //  -5

}
