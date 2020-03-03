#include "txtfind.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

char c, ans,temp;
char str[LINE];
char word[WORD];
int i = 0;
while (((c = getc(stdin)) !=' ')) { // getting the first word of the text
word[i++] = c;
}
word[i] = 0;

while (((c = getc(stdin)) !='\n')) {
ans = c;
temp=c;
}
str[0]=temp;

if (ans == 'a'){
print_lines(str,c,word);
}
else if (ans == 'b') {

 print_similar_words(str,c,word);
}

return 0;

}
	


