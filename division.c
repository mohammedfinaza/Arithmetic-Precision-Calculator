#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2 ,Dlist **headR, Dlist **tailR)//divison function
{
    int flag=1,i,list1,list2;

    int count=0;

    list1=list_length(head1);//finding the length of the list
    list2=list_length(head2);

    if(list2>list1)//checking whether the num2 is smaller than num1
        return 0;
    
     if(list1 == 1)//checking ifboth the nums are non zero
    {
        if((*head1) -> data == 0 )
        {
            printf("Division Not Possible\n");
            return -1;

        }   

    } 
    else if(list2 == 1)
    {
        if((*head2) -> data == 0 )
        {
            printf("Division Not Possible\n");
            return -1;

        }  


    }
     
    while(1)
    {
        list1=list_length(head1);
        list2=list_length(head2);


        if(list1 < list2)
        {
            break;
        }
        else if(list1 > list2)
        {
            subtraction(head1,tail1,head2,tail2,headR,tailR);//calling subtraction function

            delete_zero(headR);//deleting the precerding zeros

            delete_list(head1,tail1);// deleting the first list after the operation

            *head1=*headR;
            *tail1=*tailR;

            count++;

            *headR=NULL;
            *tailR=NULL;
        }
        else if(list1==list2)
        {
            Dlist *temp1=*head1,*temp2=*head2;

            for(i=0;i<list1;i++)
            {
                if(temp1 -> data > temp2 -> data)
                {
                    flag=1;
                    break;
                    
                }
                else if(temp1 -> data < temp2 -> data)
                {
                    flag=0;
                    break;
                }

                temp1=temp1 -> next;
                temp2=temp2 -> next;

            }

            if(flag==0)
            {
                break;

            }
            else
            {
                subtraction(head1,tail1,head2,tail2,headR,tailR);//calling subtraction function

                delete_zero(headR);
                
                delete_list(head1,tail1);

                *head1=*headR;
                *tail1=*tailR;

                count++;

                *headR=NULL;
                *tailR=NULL; 

            }
                

        }

        //printf("\nlist1: %d, list2: %d, flag: %d, count: %d\n", list1, list2, flag, count);


    }

    return count;    

}