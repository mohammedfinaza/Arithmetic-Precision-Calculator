#include "apc.h"


int my_atoi(char ch)
{
    return (ch-48);
}

int insert_first(int digit,Dlist **head,Dlist **tail)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("INFO :MEMORY ALLOCATION FAILED\n");
        return FAILURE;
    }

     new -> data=digit;
     new -> prev=NULL;

     if(*head==NULL)
    {
        *head=new; 
        *tail=new; 
        new -> next=NULL;
        return SUCCESS;   
    }

    (*head) -> prev=new;
    new -> next=*head;
    *head=new;
    return SUCCESS;  

}


int insert_last(int digit,Dlist **head,Dlist **tail)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        printf("INFO :MEMORY ALLOCATION FAILED\n");
        return FAILURE;
    }

     new -> data=digit;
     new -> next=NULL;
     new -> prev=*tail;
   

    if(*head==NULL)
    {
        *head=new; 
        *tail=new; 
        return SUCCESS;   
    }

    (*tail) -> next=new;
    *tail=new;

    return SUCCESS;  

}


void print_list(Dlist *head)
{
    
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else if(head -> next == NULL)
    {
        while (head)		
	    {
                
            printf("%d ", head -> data);

		    head = head -> next;   
	    }
    	printf(" \n");
        
           
    }
	else
	{
        delete_zero(&head);

	    while (head)		
	    {
                
            printf("%d", head -> data);

		    head = head -> next;   
	    }
    	printf(" \n");
    }

    return;
}


void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    int i;

    if(sign_flag == -1)
    {
        for(i=0;i<strlen(argv[3]);i++)
        {
            if(insert_last(my_atoi(argv[3][i]),head1,tail1) != SUCCESS)
                return;
        }

        //print_list(*head1);

        for(i=0;i<strlen(argv[1]);i++)
        {
            if(insert_last(my_atoi(argv[1][i]),head2,tail2) != SUCCESS)
                return;
        }

        //print_list(*head2);

        
    }
    else
    {
        for(i=0;i<strlen(argv[1]);i++)
        {
            if(insert_last(my_atoi(argv[1][i]),head1,tail1) != SUCCESS)
                return;
        }

        //print_list(*head1);

        for(i=0;i<strlen(argv[3]);i++)
        {
            if(insert_last(my_atoi(argv[3][i]),head2,tail2) != SUCCESS)
                return;
        }

        //print_list(*head2);


    }


    return;
}


int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    while((*head) -> next != NULL)
    {
        *head=(*head) -> next;
        free((*head) -> prev);
    }
    
    free(*head);
    *head=NULL;
    *tail=NULL;
    
    return SUCCESS;

}   

int list_length(Dlist **head)
{
    int count=0;
    if(*head == NULL)
    {
        return count;
    }

    Dlist *temp=*head;

    while(temp != NULL)
    {
        count++;
        temp=temp -> next;
    }

    return count;

}
