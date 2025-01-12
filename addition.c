#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)//function to perform addition
{
    Dlist *temp1=*tail1,*temp2=*tail2;
    int carry=0,sum=0,num1=0,num2=0,data=0;

    while(temp1!=NULL || temp2!=NULL)
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
        sum=num1+num2+carry;//adding the number
       
        data=sum%10;
        carry=sum/10;

        if(insert_first(data,headR,tailR)==FAILURE)//inserting the data into the list after operation
            return FAILURE;

    }

    if(carry!=0)
    {
        if(insert_first(carry,headR,tailR)==FAILURE)//inserting  the last carry onto the list
            return FAILURE;
    }

    return SUCCESS;

}