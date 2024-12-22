#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[30];
    char dob[11];
    char fathername[30];
    char mothername[30];
    char contractnumber[20];
    char address[50];

    struct student *NEXT;

};

struct student *head = NULL;
struct student *tail = NULL;

void addStudent(){

    getchar();
    struct student *temp = malloc(sizeof(struct student));
    printf("\n Enter name of the student : ");
    scanf("%[^\n]s", temp->name);
    getchar();

    printf("\n Enter DOB (MM/DD/YYYY) : ");
    scanf("%s", temp->dob);
    getchar();

    printf("\n Enter father name: ");
    scanf("%s", temp->fathername);
    getchar();

    printf("\n Enter mother name: ");
    scanf("%s", temp->mothername);
    getchar();

    printf("\n Enter contract no : ");
    scanf("%s", temp->contractnumber);
    getchar();

    printf("\n Enter address : ");
    scanf("%s", temp->address);
    getchar();

    temp->NEXT = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        getchar();
    }
}

void displayAllStudents()
{
    struct student *temp = head;

    if(head == NULL)
        printf("\n NO record: Linked List is empty !!");
    else{
        while(temp != NULL)
        {
            printf("\n Name : %s", temp->name);
            printf("\n DOB  : %s", temp->dob);
            printf("\n Father Name : %s", temp->fathername);
            printf("\n Mother Name : %s", temp->mothername);
            printf("\n Contact No : %s", temp->contractnumber);
            printf("\n Address : %s", temp->address);
            temp = temp->NEXT;
            if(temp != NULL)
            {
                printf("\n------------------------------------");
                printf("\n Press ENTER Key for the next record..");
            }
        }
    }
}

void deleteAllStudent()
{
    if(head == NULL)
        printf("\n Linked List empty..");
    else{
        unsigned long int count = 0;
        struct student *temp = head;
        while(temp != NULL)
        {
            struct student * var = temp->NEXT;
            free(temp);
            temp = var;
            count++;
        }

        printf("\n**** Number of nodes deleted : %ld **\n", count);
    }
}

int main()
{
    int choice = 1;

    while (choice != 0){

        printf("\n***** Main Menu *****");
        printf("\n\tPress 1 to add student");
        printf("\n\tPress 2 to display add student");
        printf("\n\tPress 0 to exit..");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

            switch(choice)
            {
                case 1: addStudent();
                break;
                case 2: displayAllStudents();
                break;
                case 0: deleteAllStudent();
                exit(1);
                default: printf("\nInvalid choice, please input a valid no");
                getchar();
            }
    }

    return 0;
}
