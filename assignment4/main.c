#include "Trie.h"
#include <string.h>
int maxSize=0;
int main(int argc,char** args) {

	int isReverse=0;
	if(argc==2 && strcmp(args[1],"r")==0){ // check if there is an input from user
		isReverse=1;
	}	



	node* root = getNewTrieNode(' '); // initializing the root
	char c=0; 
	char* str= NULL;
	Node* head = NULL;
	int count = 0;

	while (((c = getc(stdin)) != EOF)) {
		
		//if (c != ' ' && c!='\n' && c!='.' && c!=',') {
			if((c>=65 && c<=90) || (c>=97 && c<=122)){
			count++;
			if(c<97 || c>122){ // if c is not small letter
				c=c+'a'-'A';
			}
			head = add(head, c);
		}
		
		if (c == ' ' || c=='\n' || c=='.' || c==',') {
			if(maxSize<count){
			maxSize=count; // saving the maximum length of word 						//that we get
			}
			str = fromListToStr(head,str,count);
					
					insert(root, str);
					 head = freeList(head);
					free(str);
					str=NULL;
					count = 0;




		}

		


	}
	
					
	free(str);
	if(isReverse)
		printTreeLexDown(root);
	else
		printTreeLexUp(root);
	freeTree(root);
	free(root);
	root=NULL;



	return 0;
}
