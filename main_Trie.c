#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

typedef enum{false, true} bool;

struct contact{
    char *num;
    char *name;
};

struct TrieNode{
    struct TrieNode * child[26];
    struct contact * con;
    bool end;
};

typedef struct contact contact;
typedef struct TrieNode TrieNode;

TrieNode * root;

void print_con(contact * cnt);
contact * new(char * name, char * num);
TrieNode * new_trie();
bool insert(char * name, char * num);
bool delete(char * name);
contact * search(char * name);
void show_all(TrieNode * src);

void print_con(contact * cnt){
    printf("Name:    %s\n", cnt->name);
    printf("Number:  %s\n", cnt->num);
}

contact * new(char * name, char * num){
    contact * ans = (contact *) malloc(sizeof(contact));
    ans->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    ans->num = (char *) malloc(sizeof(char) * 11);
    strcpy(ans->name, name);
    strcpy(ans->num, num);
    return ans;
}

TrieNode * new_trie(){
    TrieNode * p = NULL;
    p = (TrieNode *) malloc(sizeof(TrieNode));
    if(p){
        p->end = false;
        p->con = NULL;
        for(int i = 0; i < 26; i++)
            p->child[i] = NULL; 
    }
    return p;
}

bool insert(char *name, char *num){
    int length = strlen(name);
    int index;

    TrieNode *p = root;
    for(int i = 0; i < length; i++){
        index = name[i] - 'a';
        if(p->child[index] == NULL)
            p->child[index] = new_trie();
        p = p->child[index];
    }
    if(p->end)
        return false;
    p->end = true;
    p->con = new(name, num);
    return true;
}



contact * search(char * name){
    int length = strlen(name);
    int index;

    TrieNode *p = root;
    for(int i = 0; i < length; i++){
        index = name[i] - 'a';
        if(p->child[index] == NULL)
            return NULL;
        p = p->child[index];
    }
    if(!p->end)
        return NULL;
    return p->con;
}

bool delete(char * name){
    int length = strlen(name);
    int index;

    TrieNode *p = root;
    for(int i = 0; i < length; i++){
        index = name[i] - 'a';
        if(p->child[index] == NULL)
            return false;
        p = p->child[index];
    }
    if(!p->end)
        return false;
    p->end = false;
    free(p->con);
    return true;
}

void show_all(TrieNode * src){
    if(src->end){
        print_con(src->con);
        printf("\n");
    }

    for(int i = 0; i < 26; i++)
        if(src->child[i] != NULL)
            show_all(src->child[i]);
    
}

int main(){
    root = new_trie();
    system("cls");
    int choice;
    char name[30];
    char num[11];
    contact * res;
    bool status;
    do{
        printf("1. Enter New Contact.\n");
        printf("2. Search a Conatact.\n");
        printf("3. Delete a Contact.\n");
        printf("4. Show all contacts.\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Number: ");
                scanf("%s", num);
                status = insert(name, num);
                if(status)
                    printf("\nSuccessfully added!\n");
                else
                    printf("Name already exist!\n");
                break;
            case 2:
                printf("Enter Name: ");
                scanf("%s", name);
                res = search(name);
                printf("\n");
                if(res == NULL)
                    printf("Contact not Found!\n");
                else
                    print_con(res);
                break;
            case 3:
                printf("Enter Name: ");
                scanf("%s", name);
                status = delete(name);
                if(status)
                    printf("Successfully deleted.\n");
                else
                    printf("\nContact not found!\n");
                break;
            case 4:
                show_all(root);
                break;
            case 0:
                break;
            default:
                printf("Enter valid choice!");
                break;
        }
        if(choice){
            printf("\nPress any key to continue.");
            getch();
        }
        system("cls");
    }while(choice);
    
    return 0;
}