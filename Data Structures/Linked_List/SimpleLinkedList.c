#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node* next;
};

typedef struct Node node;

node* insertfront(node* head,int x)
{
	node* p = (node*)malloc(sizeof(node));
	p->info=x;
	p->next=head;
	return p;
}

node* insertrear(node* head,int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->info=x;
	p->next=NULL;
	if(head==NULL)
		return p;
	node* q=head;
	while(q->next!=NULL)
	   q=q->next;
	q->next=p;

	return head;
}

node* insertafter(node* head,int n,int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->info=x;
	if(head->next==NULL)
	{
		head->next=p;
		p->next=NULL;
		return head;
	}
	node* q=head;
	while(q->info!=n)
		q=q->next;
	p->next=q->next;
	q->next=p;
	return head;
}

node* insertbefore(node* head,int n,int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->info=x;
	if(head->info==n)
	{
		p->next=head;
		return p;
	}
	node* q=head;
	while(q->next->info!=n)
		q=q->next;
	p->next=q->next;
	q->next=p;
	return head;
}

node* deletefront(node* head)
{
	if(head==NULL)
	{
		printf("List id empty\n");
		return head;
	}
	node* p=head;
	head=head->next;
	free(p);
	return head;
}

node* deleterear(node* head)
{
	node* p= head;
	if(head==NULL)
	{
		printf("List is empty\n");
		return NULL;
	}
	if(head->next==NULL)
	{
		return NULL;
	}
	while(p->next->next!=NULL)
		p=p->next;
	p->next=NULL;
	return head;
}

node* deleteindex(node* head, int n)
{
	if(head==NULL)
	{
		printf("List empty\n");
		return NULL;
	}
	node* p=head;
	node* q;
	while(p->info!=n)
	{
		q=p;
		p=p->next;
		if(p==NULL)
		{
			printf("Element not present\n");
			return head;
		}
	}
	if(p==head)
	{
		head=head->next;
		free(p);
		return head;
	}
	q->next=p->next;
	free(p);
	return head;
}

void display(node* head)
{
node* p=head;
if(p==NULL)
{
	printf("List is empty\n");
	return;
}
while(p!=NULL)
{
	printf("%d ",p->info);
	p=p->next;
}
printf("\n");
}

int main()
{
	node* head = NULL;
	int n;
	printf("1.Insert at front\n2.Insert at rear\n3.Insert after given element\n4.Insert before a given element\n5.Delete first element\n6.Delete last element\n7.Delete given element\n8.Display\n9.Exit ");
	while(1)
	{
		printf("Choose one option: ");
		scanf("%d",&n);
	switch(n)
	{
	case 1:printf("Enter the element ");
		int a;
		scanf("%d",&a);
		head=insertfront(head,a);
		break;
	case 2:printf("Enter the element ");
		int b;
		scanf("%d",&b);
		head=insertrear(head,b);
		break;
	case 3:printf("Enter the element after which to insert");
		int c,d;
		scanf("%d",&c);
		printf("Enter the element to insert ");
		scanf("%d",&d);
		head=insertafter(head,c,d);
		break;
	case 4:printf("Enter the element before which to insert");
		int e,f;
		scanf("%d",&e);
		printf("Enter the element to insert ");
		scanf("%d",&f);
		head=insertbefore(head,e,f);
		break;
	case 5:head=deletefront(head);
		break;
	case 6:head=deleterear(head);
		break;
	case 7:printf("Enter the element to delete ");
		int g;
		scanf("%d",&g);
		head=deleteindex(head,g);
		break;
	case 8:display(head);
		break;
	case 9:exit(1);
		break;
	default:printf("Enter valid choice ");
	}
	}
	return 0;
}






















