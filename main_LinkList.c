#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
void start()
{
    system("Color 9");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t-------------------------------\n");
    printf("\t\t\t\t\t\t\t\t-------------------------------\n");
    printf("\t\t\t\t\t\t\t\t      PHONE BOOK DIRECTIORY    \n");
    printf("\t\t\t\t\t\t\t\t-------------------------------\n");
    printf("\t\t\t\t\t\t\tLoading ");
    char x=219;
    for(int i=0;i<35;i++)
    {
        printf("%c", x);
        if(1<10)
        _sleep(300);
        if(i>=10 && i<20)
        _sleep(150);
        if(i>=10)
        _sleep(25);
    }
    system("cls");
}
struct node
{
    char name[25];
    char pnum[25];
    struct node *next;
};

struct node *newnode()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = NULL;
    return ptr;
}

void addnewnumber(struct node **head)
{
    char tname[25], tphone[25];
    struct node *p = (*head);
    struct node *a = (*head);
    p = newnode();
    fflush(stdin);
    printf("\n\n\t\t\t\t\t\tEnter the name: ");
    gets(tname);
    fflush(stdin);
    printf("\n");
    printf("\t\t\t\t\t\tEnter the phone number: ");
    gets(tphone);
    printf("\n");
    strcpy(p->name, tname);
    strcpy(p->pnum, tphone);
    if ((*head) == NULL || strcmpi((*head)->name, p->name) >= 0)
    {
        p->next = (*head);
        (*head) = p;
        printf("\n");
        return;
    }
    else
    {
        while (a->next != NULL && strcmpi(a->next->name, p->name) < 0)
        {
            a = a->next;
        }
        p->next = a->next;
        a->next = p;
    }
    printf("\n");
}

void display(struct node *head)
{
    struct node *p = head;
    if(p==NULL)
    {
        printf("\n\n\t\t\t\t\t\tThere are not any contact number!\n\n");
        return;
    }
    while (p->next != NULL)
    {
        printf("\n\n\t\t\t\t\t\tName:%s    Contact number:%s\n", p->name, p->pnum);
        p = p->next;
    }
    printf("\n\n\t\t\t\t\t\tName:%s     Contact number:%s\n\n", p->name, p->pnum);
}

void searchbyname(struct node *head)
{
    struct node *p = head;
    char tname[25];
    printf("\n\n\t\t\t\t\t\tEnter the name: ");
    gets(tname);
    fflush(stdin);
    printf("\n");
    while (strcmp(tname, p->name) != 0)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("\t\t\t\t\t\tThere is no existance of that number!\n\n");
            return;
        }
    }
    printf("\t\t\t\t\t\tContact number is found!\n");
    printf("\t\t\t\t\t\tName:%s   Contact number:%s\n\n", p->name, p->pnum);
}

void searchbynumber(struct node *head)
{
    struct node *p = head;
    char tphone[25];
    printf("\n\n\t\t\t\t\t\tEnter the phone number: ");
    gets(tphone);
    fflush(stdin);
    printf("\n");
    while (strcmp(tphone, p->pnum) != 0)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("\t\t\t\t\t\tThere is no existance of that number!\n\n");
            return;
        }
    }
    printf("\t\t\t\t\t\tContact number is found!\n");
    printf("\t\t\t\t\t\tName:%s   Contact number:%s\n\n", p->name, p->pnum);
}

void deletecontact(struct node **head)
{
    struct node *p = (*head);
    struct node *q;
    char tname[25];
    printf("\n\n\t\t\t\t\t\tEnter the name: ");
    gets(tname);
    fflush(stdin);
    printf("\n");
    if (strcmp((*head)->name, tname) == 0)
    {
        p = p->next;
        (*head) = p;
        printf("\t\t\t\t\t\tContact number deleted succesfully!\n");
        return;
    }
    else
    {
        while (strcmp(p->name, tname) != 0)
        {
            q = p;
            p = p->next;
            if (p == NULL)
            {
                printf("\t\t\t\t\t\tThere is no existance of that number!\n\n");
                return;
            }
        }
        q->next = p->next;
        printf("\t\t\t\t\t\tContact number deleted succesfully!\n");
    }
    printf("\n");
}

void editcontact(struct node *head)
{
    struct node *p = head;
    char tname[25];
    char nname[25], nnum[25];
    printf("\n\n\t\t\t\t\t\tEnter the name: ");
    gets(tname);
    fflush(stdin);
    printf("\n\n\n");
    while (strcmp(tname, p->name) != 0)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("\t\t\t\t\t\tThere is no existance of that number!\n\n");
            return;
        }
    }
    printf("\t\t\t\t\t\tEnter the new name: ");
    gets(nname);
    fflush(stdin);
    printf("\n");
    printf("\t\t\t\t\t\tEnter the new number: ");
    gets(nnum);
    fflush(stdin);
    printf("\n");
    strcpy(p->name, nname);
    strcpy(p->pnum, nnum);
    printf("\n");
}

int main()
{
    start();
    struct node *head = NULL;
    int r = 1;
    do
    {
        //printf("Enter the operation you want to perform: \n");
        int n, p, q;
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t-----------------------------------------------\n");
        printf("\t\t\t\t\t\t-----------------------------------------------\n");
        printf("\t\t\t\t\t\t|           PHONE BOOK DIRECTIORY             |\n");
        printf("\t\t\t\t\t\t-----------------------------------------------\n");
        printf("\t\t\t\t\t\t|                                             |\n");
        printf("\t\t\t\t\t\t|      [1] Add contact                        |\n");
        printf("\t\t\t\t\t\t|      [2] Delete contact                     |\n");
        printf("\t\t\t\t\t\t|      [3] Edit contact                       |\n");
        printf("\t\t\t\t\t\t|      [4] Search contact                     |\n");
        printf("\t\t\t\t\t\t|      [5] Display all contact                |\n");
        printf("\t\t\t\t\t\t|      [6] Exit                               |\n");
        printf("\t\t\t\t\t\t|                                             |\n");
        printf("\t\t\t\t\t\t-----------------------------------------------\n");

        scanf("%d", &n);
        fflush(stdin);
        system("cls");
        switch (n)
        {
        case 1:
            system("Color 1");
            addnewnumber(&head);
            break;

        case 2:
            system("Color 2");
            deletecontact(&head);
            break;

        case 3:
            system("Color 4");
            editcontact(head);
            break;

        case 4:
            system("Color 6");
            printf("Enter 1 for search through name\n");
            printf("Enter 2 for search through number\n");
            scanf("%d", &q);
            fflush(stdin);
            switch (q)
            {
            case 1:
                searchbyname(head);
                break;

            case 2:
                searchbynumber(head);
                break;
            }
            break;

        case 5:
            system("Color 1");
            display(head);
            break;

        case 6:
            r = 0;
            break;

        default:
            system("Color 7");
            scanf("You entered wrong number!");
        }
    } while (r);
    return 0;
}

