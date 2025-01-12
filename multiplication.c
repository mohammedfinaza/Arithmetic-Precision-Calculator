#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR1, Dlist **tailR1,Dlist **headR2,Dlist **tailR2)//function for multiplication
{
    int i,count=0,num1=0,num2=0,data=0,carry=0;
    Dlist *temp1=*tail1,*temp2=*tail2,*backuphead=NULL,*backuptail=NULL;

    while(temp2 !=NULL)
    {
        temp1=*tail1;
    
        if(count==0)
        {
            while( temp1 != NULL)
            {
                num1 =temp1 -> data;
                num2 =temp2 -> data;

                data=(num1*num2)+carry;//multipling the number

                carry =data/10;

                data=data%10;

                if(insert_first(data,headR1,tailR1)==FAILURE)
                    return FAILURE;

                temp1= temp1 -> prev;    

            }

        }
        else
        {
            
            while( temp1 != NULL)
            {
                num1=temp1 -> data;
                num2 =temp2 -> data;

                data=(num1*num2)+carry;

                carry =data/10;

                data=data%10;

                if(insert_first(data,headR2,tailR2)==FAILURE)
                    return FAILURE;

                temp1 = temp1 -> prev; 

            }

            if(count > 0)
            {
                for(int i=0;i<count;i++)
                {
                    insert_last(0,headR2,tailR2);//adding carry if presenr
                }

            }

            addition(headR1,tailR1,headR2,tailR2,&backuphead,&backuptail);//calling addition function
            delete_list(headR1,tailR1);
            delete_list(headR2,tailR2);

            *headR1=backuphead;
            *tailR1=backuptail;

            backuphead=NULL;
            backuptail=NULL;
            

        }

        temp2 =temp2 -> prev;
        count ++; 

    }

    if(carry!=0)
    {
        insert_first(carry,headR1,tailR1);
    }

     print_list(*headR1);
     return SUCCESS;
    
}