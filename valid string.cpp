#include<stdio.h>
#include<string.h>
int main()
{
	char input[100];
	printf("enter a string:");
	scanf("%s",input);
	if(strlen(input) > 0)
	{
		printf("valid.\n");
	}
	else
	{
		printf("not valid.\n");
	}
	return 0;
}
