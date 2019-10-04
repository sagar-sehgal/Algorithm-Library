#include <stdio.h>
#include <stdlib.h>

//Declaration of Linked List of Integer
typedef struct ListNode{
	int data;
	struct ListNode* next;
}ListNode;

//Size of the Linked List
void ListLength(ListNode* head){
	ListNode* current = head;
	int count = 0;

	while(current != NULL){//Traversing through Liknked List
		count += 1;
		current = current->next;
	}

	printf("Size of the Linked List is:%d\n", count);
}

//Print the data of the Linked List
void PrintList(ListNode *head){
	ListNode *current = head;
	printf("Your Linked List is: ");
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

//Singly Linked List Insertion
//Insertion into a singly linked list has three cases:-
//	1. Inserting a new node before the head (at the beginning)
//	2. Inserting a new node after the tail (at the end of the list)
//	3. Inserting a new node at the specific position of the list (random location)

//1. Inserting a new node before the head (at the beginning)
ListNode* InsertAtTheHead(ListNode *head, int newData){
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = newData;
	if(head == NULL){
		head = newNode;//Assigning head pointer to the newNode to make it head
	}else{
		newNode->next = head;//Linking newNode to the existing Linked List
		head = newNode;
	}
	// PrintList(head);
	return head;
}

//2. Inserting a new node after the tail (at the end of the list)
ListNode* InsertAtTheTail(ListNode *head, int newData){
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = newData;
	newNode->next = NULL;

	ListNode *pseudoHead = head;

	if(head == NULL){
		head = newNode;
	}else{
		while(pseudoHead->next != NULL){
			pseudoHead = pseudoHead->next;
		}
		pseudoHead->next = newNode;
	}
	return head;
}



int main(){
	ListNode *head, *second, *third;
	int x;

	head = (ListNode*)malloc(sizeof(ListNode));
	second = (ListNode*)malloc(sizeof(ListNode));
	third = (ListNode*)malloc(sizeof(ListNode));

	printf("Enter any three numbers to create a Linked List:\n");
	scanf("%d", &x);
	head->data = x;
	head->next = second;

	scanf("%d", &x);
	second->data = x;
	second->next = third;

	scanf("%d", &x);
	third->data = x;
	third->next = NULL;

	// ListNode *finalList = InsertAtTheHead(head,100);
	ListNode *finalList = InsertAtTheTail(head,100);
	ListLength(finalList);
	PrintList(finalList);
	return 0;
}
