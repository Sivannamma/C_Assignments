#include "isort.h"
#include <stdio.h>


void shift_element(int* arr, int i) {
int* p = arr + i;
while (p != arr) {
*p = *(p - 1);
p--;
}

}
void insertion_sort(int* arr, int len) {
int* p, counter = 0, i = 0;
for (i = 1; i < len; i++) {
int key = *(arr + i);
p = (arr + i - 1);
int k = i - 1;


while (key < *p && k >= 0) {
counter++;
k--;
p--;
}
shift_element(arr + (k + 1), counter);
*(p + 1) = key;
counter = 0;
}
}

void printArr(int* arr) {
int i = 0;
for (i = 0; i < SIZE; i++)
{
if (i == SIZE - 1) {
printf("%d ", *(arr + i));
}

else {

printf("%d ", *(arr + i));
printf(",");
}
}
}
