#include "txtfind.h"
#include <stdio.h>
#include <string.h>


void print_lines(char* str,char c,char* word){
int i=1;
char temp;
while ((c = getc(stdin)) != EOF) {
temp=c;
while ((c = getc(stdin)) !='\n') {
str[i++] = c;
}
str[0]=temp;
str[i]=0;
i=1;
if (substring(str, word)) {
printf("%s\n", str);
}

}
}

void print_similar_words(char* str,char c,char* word){
int i=1;
while ((c = getc(stdin)) != EOF) {

str[i++] = c;
if (c == ' ' || c == '\n' || c== '\t'){

str[i-1] = 0;

if (similar(str, word,1)) {
printf("%s\n", str);
}
if (similar(str, word, 0)) {
printf("%s\n", str);
}
i=0;
}
}
}


int similar(char* s, char* t, int n) {
int count = 0;
if (strlen(t) > strlen(s))
return 0;
while (*s) {
if (*t == *s) {
t++;
s++;
}
else {
s++;
count++;
}
}
if(n==0 && strlen(t) != strlen(s)){
return 0;
}

return count==n;
}

int substring(char* str1, char* str2) {
int i = 0;
int len = strlen(str1);
int len2 = strlen(str2);
for (i=0; i <= len - len2; i++) {
if (isEqualStrings(str1 + i, str2))
return 1;
}


return 0;
}
int isEqualStrings(char* s, char sub[]) {

while (*sub) {
if (*s != *sub)
return 0;
s++;
sub++;
}
return 1;
}

