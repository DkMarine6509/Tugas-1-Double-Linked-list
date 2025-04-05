#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int x;
	tnode *next;
	tnode *prev;
} *head, *tail, *curr;

void push_front(int value)
{
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	node->x = value;
	
	if(head == NULL)
	{
		head = tail = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
		head->prev = NULL;
	}
}

void push_back(int value)
{
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	node->x = value;
	
	if(head == NULL)
	{
		head = tail = node;
		tail->next = NULL;
		tail->prev = NULL;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
		tail->next = NULL;
	}
}

void push_mid(int value, int searchKey)
{
	struct tnode *node = (tnode*)malloc(sizeof(tnode));
	node->x = value;
	
	if(head == NULL)
	{
		head = tail = node;
		tail->next = NULL;
	}
	else
	{
		struct tnode *curr = head;
		while(curr!=NULL)
		{
			if(curr->x==searchKey)
			{
				if(curr==tail)
				{
					push_back(value);
				}
				else
				{
					node->next = curr->next;
					curr->next = node;
				}
				break;
			}
			curr = curr->next;
		}
		if(curr==NULL)
		{
			printf("Data %d is not found\n",searchKey);
		}
	}
}

void printList()
{
	if(head==NULL)
	{
		printf("There is no data\n");
		return;
	}
	
	curr=head;
	while(curr!=NULL)
	{
		printf("%d ",curr->x);
		curr = curr->next;
	}
}

void del_back()
{
	if(head==NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		if(head==tail)
		{
			free(head);
			head=tail=NULL;
		}
		else
		{
			struct tnode *del = head;
			while(del->next!=tail)
			{
				del = del->next;
			}
			free(tail);
			tail=del;
			tail->next=NULL;
		}
	}
}

void del_front()
{
	if(head==NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		if(head==tail)
		{
			free(head);
			head=tail=NULL;
		}
		else
		{
			struct tnode *del = head;
			head = head->next;
			free(del);
		}
	}
}

int main()
{
	printf("Linked List\n");
	
	push_front(76);
	push_front(90);
	push_front(45);
	push_mid(33,90);
	del_back();
	del_front();
	
	printList();getchar();
	
	return 0;
}
