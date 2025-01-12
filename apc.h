#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define RESULT_ZERO 2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}Dlist;

/*Global Variable for sign*/
extern int sign_flag;

/*Include the prototypes here*/

/*Store the operands into the list*/
void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/*Addition*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

/*Subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

/*multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR1, Dlist **tailR1,Dlist **headR2,Dlist **tailR2);

/*division*/
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

/*validate the commandlinr arguments*/
int validate(int argc,char **argv);

/*insert node at last*/
int insert_last(int digit,Dlist **head,Dlist **tail);

/*insert node at first*/
int insert_first(int digit,Dlist **head,Dlist **tail);

/*convert string to integer*/
int my_atoi(char ch);

/*print the node*/
void print_list(Dlist *head);

/*validate for sub*/
int validate_for_sub(char **argv);

/*delete zeros in front*/
int delete_zero(Dlist **head);

int delete_list(Dlist **head, Dlist **tail);

int list_length(Dlist **head);

#endif