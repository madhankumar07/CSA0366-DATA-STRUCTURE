#include<stdio.h>
int main()
{
	int number,first = 0,second = 1,next = 0,sum = 0;
	printf("enter maximum number for fibonacci series =");
	scanf("%d",&number);

    printf("first %d fibonacci series numbers:\n", number);
    while(first <= number){
    sum = sum + first;
    next = first + second;
    first = second;
    second = next;
    }
    printf("\nthe sum of fabonacci series numbers = %d\n", sum);
}

