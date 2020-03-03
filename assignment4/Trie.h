

#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS ((int)26) 
typedef struct node { // for tire
	char letter;
	 long unsigned int count; 
	struct node* children[NUM_LETTERS];
} node;

typedef struct Node { // for linked list
	char c;
	struct Node* next;
}Node;

Node* add(Node* head, char c);
void insert(node* root, char* str);
node* getNewTrieNode(char letter);
void printLexUp(node* head,char s [] ,int k);
void printLexDown(node* head, char s[], int k);
void printTreeLexUp(node* head);
void printTreeLexDown(node* head);
Node* freeList(Node*);
node* freeTree(node* root);
char* fromListToStr(Node* head, char* str, int count);

