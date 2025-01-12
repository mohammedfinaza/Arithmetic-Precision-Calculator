#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)//function for subtraction
{
    Dlist *temp1=*tail1,*temp2=*tail2;
    int borrow=0,sub=0,num1=0,num2=0;

    while(temp2 !=NULL || temp1!=NULL)
    {
        if(temp1==NULL)
        {
            num1=0;
            num2=temp2 -> data;
            temp2=temp2 -> prev;
        }
        else if(temp2==NULL)
        {
            num1=temp1 -> data;
            num2=0;
            temp1=temp1 -> prev;          

        }
        else
        {
            num1=temp1 -> data;
            num2=temp2 -> data;
            temp1=temp1 -> prev;   
            temp2=temp2 -> prev;   
        }

        if(borrow==1)//decrementing the number is borrow is taken
        {
            num1=num1-1;
        }

        if(num1<num2)//taking borrow is num2 is less
        {
            num1=num1+10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }

        sub=num1-num2;//subtracting the numbers

        if(insert_first(sub,headR,tailR)==FAILURE)
            return FAILURE;

    }

    

}

int delete_zero(Dlist **headR)//function to delete zeros in front of a +ve value
{
    
    int flag=0;
    Dlist *temp;

    while (*headR)		
	{
        if(flag == 1)
            break;

        if((*headR) -> data > 0)
        {
            flag=1;
        }
        else if(((*headR) -> next)==NULL)
        {
            break;

        }
        else
        {
            temp=*headR;
            *headR = (*headR) -> next;
            (*headR) -> prev =NULL;
            free(temp);

        }    
	}


    return SUCCESS;
    
}