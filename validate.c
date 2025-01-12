#include "apc.h"

int validate(int argc,char **argv)
{
    int i;

    if(argc!=4)
    {
      printf("INFO : PASS PROPER ARGUMENTS\n");
      return FAILURE;
    }

    if(!(argv[2][0]=='+' || argv[2][0]=='-' || argv[2][0]=='x' || argv[2][0]=='/'))
    {
      printf("INFO: PLEASE PASS PROPER OPERAND\n");
      return FAILURE;
    }
   

  for(i=0;i<strlen(argv[1]);i++)
  {
     if(!(argv[1][i]>='0' && argv[1][i]<='9'))
     {
        printf("INFO: PLEASE PASS DIGITS ONLY\n");
        return FAILURE;

     }  
  }

  for(i=0;i<strlen(argv[3]);i++)
  {
     if(!(argv[3][i]>='0' && argv[3][i]<='9'))
     {
        printf("INFO: PLEASE PASS DIGITS ONLY\n");
        return FAILURE;

     }  
  }

  return SUCCESS;
}

int validate_for_sub(char **argv)
{
   if( strlen(argv[3]) > strlen(argv[1]) )
   {
      sign_flag=-1;
      return SUCCESS;
   }
   else if( strlen(argv[3]) == strlen(argv[1]) )
   {
      if(strcmp(argv[1],argv[3])==0)
      {
         
         sign_flag=+1;
         return RESULT_ZERO;
      }
      else if(strcmp(argv[1],argv[3])>0)
      {
         sign_flag=+1;
         return SUCCESS;
      }
      else
      {
         sign_flag=-1;
         return SUCCESS;

      }       

   }
   else
   {
      sign_flag=+1;
      return SUCCESS;
   }

   return FAILURE;

}