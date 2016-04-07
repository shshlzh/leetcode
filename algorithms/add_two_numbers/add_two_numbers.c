#include <stdio.h>
#include <malloc.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {	
	// if one null return other
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	struct ListNode* l3 = NULL;
	struct ListNode* p3 = l3;

	int value, carry;
	carry = 0;
	while (p1 && p2) {
		value = p1->val + p2->val + carry;
		carry = value/10;
		value -= carry * 10;
		printf("%d, %d\n", value, carry);
		if (l3) {
			p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			p3 = p3->next;
			p3->val = value;
			p3->next = NULL;

		} else {
			p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
			p3->val = value;
			p3->next = NULL;
			l3 = p3;
		}

		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1) {
		value = p1->val + carry;
		carry = value/10;
		value -= carry * 10;
		p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p3 = p3->next;
		p3->val = value;
		p3->next = NULL;

		p1 = p1->next;
	}

	while (p2) {
		value = p2->val +  carry;
		carry = value/10;
		value -= carry * 10;
		p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p3 = p3->next;
		p3->val = value;
		p3->next = NULL;

		p2 = p2->next;
	}
	
	if (carry != 0) {
		p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p3 = p3->next;
		p3->val = carry;
		p3->next = NULL;
	}

	return l3;
}


int main(int argc, char* argv[]) {
	struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1->val = 5;
	l1->next = NULL;

	struct ListNode* l3 = addTwoNumbers(l1, l1);
	printf("%d\n", l3->next->val);

	return 0;
}
