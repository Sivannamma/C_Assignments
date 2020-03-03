#include "isort.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
int i = 0;
int arr[SIZE] = { 0 };
for (i = 0; i < SIZE; i++)
{
scanf("%d", arr + i);
}
insertion_sort(arr, 50);
printArr(arr);
printf("\n");
return 0;
}
	


