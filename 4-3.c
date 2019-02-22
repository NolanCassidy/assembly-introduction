#include<stdio.h>
/*
int sum(int from, int to) {
 int result = 0;
 do {                         //.loop:
 result += from;              //addl
 ++from;                      //addl
} while (from <= to);         //compl, jle
 return result;               /ret eax
}
*/
int suma(int from, int to) {
int result = 0;
// Ensure that argument *from* is in %ecx,
// argument *to* is in %edx, *result* is in %eax - do not modify.
__asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from ));        //initializes from into ecx
__asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to ));            //initializes to into edx
__asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result ));    //initializes result into eax

// Your IA32 code goes below - comment each instruction...
__asm__ (
  ".loop:"              //starts the loop
    "addl %ecx, %eax;"  //adds from to result
    "addl $1, %ecx;"    //adds 1 to from
    "cmpl %edx, %ecx;"  //compare from less than equal to to
  "jle .loop;"          //jump less equal to loop
);

// Ensure that *result* is in %eax for return - do not modify.
__asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result ));
return result;
}


int main(){
  printf("%d\n",suma(1, 6));        // 21
  printf("%d\n",suma(3, 5));        // 12
}
