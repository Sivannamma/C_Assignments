#include "Trie.h"
extern int maxSize;
// Function that returns a new Trie node
node* getNewTrieNode(char letter)
{
	node* p = (node*)malloc(sizeof(node));
	if (p != NULL) { // if the malloc finished succesfully
		p->count = 0;
		p->letter = letter;
		for (int i = 0; i < NUM_LETTERS; i++) // by default making its array of nodes null
			p->children[i] = NULL;
	}
	return p;
}

// Iterative function to insert a string in Trie
void insert(node* head, char* str)
{
	// start from root node
	node* curr = head;
	while (*str)
	{
		// create a new node if path doesn't exists
		if (curr->children[*str - 'a'] == NULL)
			curr->children[*str - 'a'] = getNewTrieNode(*str);

		// go to next node
		curr = curr->children[*str - 'a'];

		// move to next character
		str++;
	}

	// mark current node as leaf
	curr->count++;
}
void printLexUp(node* head, char s[], int k) {
	int i = 0;
	while (i < NUM_LETTERS) { // going over the children of the first node

		if (head->children[i] != NULL) { // checking if the neighboor [i] exsits.
			s[k] = head->children[i]->letter; // takes its value into the arr

			if (head->children[i]->count > 0) { // checking if the node is leaf 
			// if then print the arr
				s[k+1] = 0;
				printf("%s ", s);
				printf(" %ld\n", head->children[i]->count);

			}
			// call again to the function with the next group of neighboor
			printLexUp(head->children[i], s, ++k);
			k--;
			i++;
			s[k + 1] = 0;
		}
		else {
			i++;
		}

	}
}
void printLexDown(node* head, char s[], int k) {
	int i = NUM_LETTERS-1;
	while (i >= 0) { // going over the children of the fist node from the last

		if (head->children[i] != NULL) {// checking if the neighboor [i] exsits.
			s[k] = head->children[i]->letter;

			printLexDown(head->children[i], s, ++k); // call the function again with the next node neighboor
			if (head->children[i]->count > 0) {
				s[k] = 0;
				printf("%s ", s);
				printf(" %ld\n", head->children[i]->count);
			}
			k--;
			i--;
			s[k] = 0;
		}
		else {
			i--;
		}



	}



}
void printTreeLexUp(node* head) {

	if (head != NULL) {

		char* str = (char*)malloc(maxSize+1);
	
		if (str != NULL) {
			printLexUp(head, str, 0);
			free(str);
		}
	}
	else {
		printf("The tree is empty");
		return;
	}
}
void printTreeLexDown(node* head) {
	if (head != NULL) {
		char* str = (char*)malloc(maxSize + 1);
		
		if (str != NULL) {
		printLexDown(head, str, 0);
		free(str);
	}
	}
	else {
		printf("The tree is empty");
		return;
	}

}
Node* add(Node* head, char c) {
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		if (head != NULL) {
			head->c = c;
			head->next = NULL;
		}
		return head;

	}
	else {
		Node* temp = (Node*)malloc(sizeof(Node));
		if (temp != NULL) {
			temp->c = c;
			temp->next = NULL;
			Node* help = head;
			while (help->next != NULL) {
				help = help->next;
			}
			help->next = temp;
		}


	}
	return head;

}

Node* freeList(Node* head) {
	if (head != NULL) { // if the list is not empty
		if (head->next != NULL) { // if the list has more then 1 variable
			Node* temp = head->next;
			while (temp != NULL) {
				free(head);
				head = temp;
				temp = temp->next;
			}

		}
		// if the list has 1 variable
		free(head);
		head = NULL;
		return head;
	}

else{
head = NULL;
return head;
}
		


}

node* freeTree(node* root) {
	int i = 25;
	while (i >= 0) { // going over the children of the fist node from the last

		if (root->children[i] != NULL) {// checking if the neighboor [i] exsits.

			freeTree(root->children[i]); // call the function again with the next node neighboor
			if (root->children[i] != NULL) {
				free(root->children[i]);
			}
			i--;
		}
		else {
			i--;
		}



	}
	return root;
}

char* fromListToStr(Node* head, char* str, int count) {
	str = (char*)malloc(count + 1);
	if (str != NULL) {
		Node* temp = head;
		while (temp != NULL) {
			*str = temp->c;
			str++;
			temp = temp->next;
		}
		*str = 0;
		str -= count;

		return str;
	}
else{
str=NULL;
return str;
}
}


