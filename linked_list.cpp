#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head= NULL;
int size=1;

void del(int pos)
{
    if(head != NULL)
   	{
	       if(pos != 1)
        {
            struct node *p = head;
            for(int i=1; i<pos-1; i++)
                p=p->next;
            struct node* temp;
            temp= p->next;
            p->next = p->next->next;
            free(temp);
        }
        else
        {
            struct node* temp= head;
            head = temp->next;
            free(temp);
        }
        
        size--;
    }
    else
        printf("\nList is empty. \n");
}

void insert(int pos, int val)
{
    struct node *newnode;
    newnode= (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    if(pos==1)
    {
        newnode->next = head;
        head= newnode;
    }
    else
    {
        struct node *prev;
        prev = head;
        for(int i=1; i<pos-1; i++)
            prev = prev->next;

        newnode->next = prev->next;
        prev->next = newnode;
    }
    size++;
}

int main()
{
	int ch, val, pos=1;
	struct node* temp;
	while(1)
    {
	printf("\n1. Insertion at beg \n2. Insertion at end \n3. Insertion after given position \n4. Delete element at given position \n5. Display \n6. Exit \n\nEnter choice: ");
	scanf("%d", &ch);
    switch(ch)
	{
    case 1:
        printf("Enter element to be inserted: ");
        scanf("%d", &val);
        insert(1, val);
        break;

    case 2:
        printf("Enter element to be inserted: ");
        scanf("%d", &val);

        temp = head;
        while(head!= NULL)
        {
            head=head->next;
            pos++;
        }
        head = temp;

        insert(pos, val);
        pos=1;
        break;

    case 3:
        printf("Enter element to be inserted: ");
        scanf("%d", &val);
        printf("At what position to insert? : ");
        scanf("%d", &pos);
            
        if(pos<=size && pos>=1)
            insert(pos, val);
        else
            printf("\nInvalid position.\n");
            
        pos=1;
        break;

    case 4:
        printf("Enter position of element you want to delete: ");
        scanf("%d", &pos);
        if(pos<=size && pos>=1)
            del(pos);
        else
            printf("\nInvalid position.\n");
            
        pos=1;
        break;

    case 5:
        temp = head;
        while(head!= NULL)
        {
            printf("%d\n", head->data);
            head=head->next;
        }
        head = temp;
        break;

    case 6:
        exit(0);

    default:
        printf("Wrong choice \n");
	}
    }
}