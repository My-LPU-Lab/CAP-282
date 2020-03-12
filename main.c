
#include <stdio.h>
#include <stdlib.h>

struct pnode
{
    int priority;
    char info;
    struct pnode *next;
};

struct pnode *head, *newnode,*temp,*pt;

void create_pqueue()
{
    int p;
     char c;
        printf("\nEnter priority: ");
        scanf("%d",&p);
        printf("\nEnter data: ");
       scanf(" %c",&c);
    newnode = (struct pnode*)malloc(sizeof(struct pnode));

    newnode->priority = p;
    newnode->info = c;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->next = head;
        head = newnode;

    }

      temp = head;
      while(temp->priority <= newnode->priority && temp->next!=NULL)
      {

          pt =temp;
          temp= temp->next;
      }
      if(temp->priority > newnode->priority)
      {
          newnode->next = pt->next;
          pt->next = newnode;
      }else{
      temp->next = newnode;


      }
}



void traverse()
{

    temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->priority);
        printf(" %c ",temp->info);

        temp = temp->next;
    }
    //printf("You have no more data in the list\n");
}

void delete_node()
{

    if(head==NULL)
    {
        printf("List is empty. You cannot perform delete operation");
    }else{
    temp =head;
    head = temp->next;
    free(temp);
    }
}

int main()
{

    int sel;
    printf("PLEASE SELECT OPERATION TO FORM. \n1.Create Queue \n2.Display \n3.Delete \n4.Exit \n");
     while(1){
    printf("Answer[option 1-4]: ");
    scanf("%d",&sel);

    switch (sel)
    {


        case 1:
        {

            create_pqueue();

            break;
        }

        case 2:
        {
            traverse();
            break;
        }
        case 3:
            {
                delete_node();
                break;

            }
        case 4:
            {
                printf("Program terminated.");
                exit(1);
                break;
            }
        default:
        {
            //exit(1);
            printf("Invalid Operation Number selected. Program Terminating ...");
            exit(1);
        }
    }
    }

    return 0;
}
