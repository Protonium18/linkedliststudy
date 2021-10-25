#include <stdlib.h>
#include <stdio.h>



typedef struct node {
	int data;
	struct node* next;
	struct node* prev;

}Node;

Node* initLinkedList(const int nodes) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->prev = NULL;
	head->data = NULL;

	return head;

}

int appendLinkedList(Node* head, const int val) {
	
	Node* ptr = head;

	while (1) {
		if (!ptr->next) {
			break;
		}
		ptr = ptr->next;
	}


	ptr->next = (Node*)malloc(sizeof(Node));
	ptr->next->data = val;
	ptr->next->next = NULL;
	ptr->next->prev = ptr;

	return 0;

}

unsigned int deleteLinkedList(Node* head) {
	Node* ptr = head->next;
	Node* forwardptr = NULL;
	unsigned int count = 0;

	while (1) {
		forwardptr = ptr->next;
		free(ptr);
		count++;
		if (forwardptr == NULL) {
			break;
		}
		else {
			ptr = forwardptr;
		}
	}

	return count;

}

int delNode(Node* node) {
	if (node->next) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}

	free(node);

}

Node* getNode(Node* head, int pos) {
	Node* ptr = head;
	for (int i = -1; i < pos; i++) {
		if (ptr->next == NULL) {
			return(1);
		}
		ptr = ptr->next;
	}
	return(ptr);
}

int main(void) {

	Node* head = initLinkedList(0);

	appendLinkedList(head, 40);
	appendLinkedList(head, 80);
	appendLinkedList(head, 180);
	appendLinkedList(head, 360);
	printf("%i\n", getNode(head, 1)->prev->data);
	printf("%i\n", getNode(head, 1)->data);
	printf("%i\n", getNode(head, 1)->next->data);
	delNode(getNode(head, 1));

	printf("%i\n", getNode(head, 1)->prev->data);
	printf("%i\n", getNode(head, 1)->data);
	printf("%i\n", getNode(head, 1)->next->data);

	



	return 0;
}