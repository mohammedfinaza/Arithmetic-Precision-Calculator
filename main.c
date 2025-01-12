/*Documentation
Name-Mohammed Finaz A
Date-20/12/24
Des-APC calculator
*/


#include "apc.h"

int sign_flag = 0;

int main(int argc,char *argv[])
{

    
   if(validate(argc,argv)!=SUCCESS)//function call to validate the command line arguments
      return 0;

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    Dlist *headR1 = NULL, *tailR1 = NULL;
   
    char operator = argv[2][0];

    
   switch(operator)//switch case to perform respective operations
   {
      case '+':
         insert_digit(&head1,&tail1,&head2,&tail2,argv);
         printf("Addition Result = ");
         addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
         print_list(headR);
         break;
        
      case '-':

         if(validate_for_sub(argv) == RESULT_ZERO)
         {
            insert_first(0,&headR,&tailR);
            printf("Subtraction Result = ");
            print_list(headR);
            break;
               
         }
         else if(validate_for_sub(argv)!=SUCCESS)
         {
            printf("INFO : PLEASE PASS PROPER ARGUMENTS FOR SUBTRACTION\n");
            break;
         }
         else
         {
            insert_digit(&head1,&tail1,&head2,&tail2,argv);
            printf("Subtraction Result = ");
            subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            if(sign_flag==-1)
            {
               printf("-");
            }
            print_list(headR);
            break;
         }
           

      case 'x':
            
         insert_digit(&head1,&tail1,&head2,&tail2,argv);
         printf("Multiplication Result = ");
         multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR,&headR1,&tailR1);
         break;

      case '/':

         insert_digit(&head1,&tail1,&head2,&tail2,argv);
         int div=division(&head1, &tail1, &head2, &tail2,&headR1,&tailR1);
         
         if(div>=0)
         {
            printf("Division Result = ");
            printf("%d\n",div);
         }
         break;

        default:
         printf("Invalid Input:-( Try again...\n");
         break;
    
   }

   return 0;
}