#include<stdio.h>
#include<malloc.h>
#include<math.h>

// Global variables Start
int bitLength;
int bit;
int expectedDecimal;
// Global variables End

typedef struct node {
	int bit;
	struct node *next;
}NODE;

NODE *createNode(int b) {
	 NODE *newNode = (NODE*)malloc(sizeof(NODE));
	 newNode->bit = bit;
	 newNode->next = NULL;
	 return newNode;
}

NODE *insertLast(NODE *head, int b) {
	NODE *newNode = createNode(b);
	if (head == NULL)
	{
		return newNode;
	}
	NODE *tem = head;
	while(tem->next != NULL)
		tem = tem->next;
	tem->next = newNode;
	return head;
}

int convertBinToDec( NODE *head) {
	int decimal = 0;
	NODE *tem = head;
	while(tem != NULL)
	{
		decimal += tem->bit * pow(2, --bitLength);
		tem = tem->next;
	}
	return decimal;
}
NODE *input() {
	NODE *head = NULL;
	scanf("%d", &bitLength);
	//printf("bits size = %d\n", bitLength);
	int i;
	for (i = 0; i < bitLength; i++) {
		scanf("%d", &bit);
		//printf(" %d", bit);
		head = insertLast(head,bit);
	}
	//printf("\n");
	scanf("%d", &expectedDecimal);
	//printf("Expected result = %d\n", expectedDecimal);
	return head;
}

void freeList(NODE *head){
	NODE *cur = head;
	while (cur) {
		NODE *temp = cur;
		cur = cur->next;
		free(temp);
	}
}


int main() {
	freopen("input_practice.txt", "r", stdin);
	int testCase;
	int Case = 0;
	scanf("%d", &testCase);
	while (testCase) {
		NODE *head = input();
		int result = convertBinToDec(head);
		printf("Case#%d: ", ++Case);
		if (result == expectedDecimal) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		freeList(head);
		testCase--;
	}
	return 0;
}

/*
input text file name input_practice.txt and save the same directory...
11
4 1 0 1 0 10
5 1 1 1 1 1 31
6 1 0 0 0 0 0 32
8 1 0 1 0 1 1 1 0 174
10 1 0 0 0 0 0 0 0 1 0 514
10 1 0 0 0 0 0 1 0 1 1 523
8 1 0 1 1 1 0 0 0 184
8 1 1 0 0 0 1 1 1 199
9 1 0 0 0 0 1 0 1 0 266
4 1 1 1 1 15
15 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 32767
*/
