#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


//defining macros
#define FAILURE   -1
#define SUCCESS    0
#define FNAME_SIZE 15
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

//Structure for file list
typedef char data_t;


typedef struct node
{
    char *s;

    struct node *link;

}flist;

typedef struct subnode
{
    int word_count;
    char f_name[FNAME_SIZE];
    struct subnode *link;


}sub_t;


typedef struct word
{
    int file_count;
    char word[WORD_SIZE];
    struct word *link;
    sub_t *tlink;

}wlist;

typedef struct indextable
{
    int index;
    wlist *tlink;
}table;


int insert_file(flist **head,char *str);

int creat_invertedindex(table *arr,int size);

int create_Database(table *arr,flist *head);

void disp_database(table *arr);

int search(table *arr,char *word);

int update_database(flist **head,char *fstr);

int save_database(flist *head,table *arr,char *newfile);


