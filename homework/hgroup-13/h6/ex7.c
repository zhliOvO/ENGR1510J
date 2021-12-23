#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
/*int ex7()
{
    node_t *a = Initialize('1');// define the head of the list
    node_t *b = NULL;
    PrintList(a);// print list a
    InsertFirstList(&a, 'V');//insert 'V' to the first of the list 
    InsertFirstList(&a, 'M');//insert 'M' to the first of the list 
    PrintList(a);//print a again
    InsertLastList(&a, 'C');//insert 'C' to the last of the list
    PrintList(a);//print a
    SplitList(&a, &b, 2);//split into [0 1] and [2 end]
    PrintList(a);//print a
    PrintList(b);//print b
    DeleteFirstList(&a);//delete first element of a
    PrintList(a);//print a
    InsertLastList(&a, 'G');//insert 'G' to the last of a
    DeleteLastList(&b);//delete the last element of b
    PrintList(b);//print b
    InsertLastList(&b, '0');//insert '0' to the last of b
    PrintList(b);//print b
    InsertLastList(&b, '1');//insert '1' to the last of b
    PrintList(b);//print b
    MergeList(&a, &b);//merge a with b
    PrintList(a);//print b
    char target = 'G';
    printf("Count '%c': %d\n", target, SearchList(&a, target));//count how many times 'G' appears
    target = '1';
    printf("Count '%c': %d\n", target, SearchList(&a, target));//count how many times '1' appears
    //FreeList(&a);//free a
    return 0;
}*/
node_t *Initialize(char ch)
{
    node_t *head;
    head = (node_t *)calloc(1, sizeof(node_t));
    if (head == NULL)// to check the memory
    {
        fprintf(stderr, "Failed to assign memory!\n");
        exit(-1);
    }
    head->next = NULL;
    head->ch = ch;
    return head;
}
void PrintList(node_t *head)
{
    node_t *temp = head;
    printf("***Print Linked List***\n");
    while (temp != NULL)
    {
        printf("%c ", temp->ch);
        temp = temp->next;
    }
    printf("\n****Print Finished****\n\n");
}
void FreeList(node_t **head)
{
    node_t *tmp = NULL;
    node_t *pHead = *head;
    while (pHead->next != NULL)
    {
        tmp = pHead;
        pHead = pHead->next;
        free(tmp);
    }
    free(pHead);
}
bool IsEmptyList(node_t *head) {
    if(head==NULL)
        return 1;
    else
        return 0;
}
void InsertFirstList(node_t **head,char insert_char){
    node_t* prev=(node_t *)calloc(1, sizeof(node_t));
    prev->next=*head;
    prev->ch=insert_char;
    *head=prev;
}
void InsertLastList(node_t **head,char insert_char){
    if(*head==NULL){
        *head=(node_t *)calloc(1, sizeof(node_t));
        (*head)->next=NULL;(*head)->ch=insert_char;
    }
    else{
        node_t *temp = *head;
        node_t *next = (node_t *)calloc(1, sizeof(node_t));
        next->ch = insert_char;
        next->next = NULL;
        while ((*head)->next != NULL)
        {
            *head = (*head)->next;
        }
        (*head)->next = next;
        *head = temp;
    }
} 
void DeleteFirstList(node_t **head) {
    if(IsEmptyList(*head)!=true){
        node_t* temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}   
void DeleteLastList(node_t **head) {
    if(IsEmptyList(*head)!=true){
        node_t* temp=*head;
        if((*head)->next==NULL){
            free(*head);*head=NULL;
        }
        else{
            while ((*head)->next->next != NULL)
            {
                *head = (*head)->next;
            }
            free((*head)->next);
            (*head)->next = NULL;
            *head = temp;
        }
    }
}
int SizeList(node_t *head) {
    int count=0;node_t* temp=head;
    while (head!=NULL)
    {
        count++;
        head=head->next;
    }
    head=temp;
    return count;
}
int SearchList(node_t **head, char target) {
    int count=0;node_t* temp=*head;
    while (*head!=NULL)
    {
        if(target==(*head)->ch){count++;}
        *head=(*head)->next;
    }
    *head=temp;
    return count;
}
void SplitList(node_t **head, node_t **tail, int pos) {
    int size=SizeList(*head);
    if(pos<0){*tail=*head;*head=NULL;}
    else if(pos==0){*tail=(*head)->next;(*head)->next=NULL;}
    else if(pos>size-1){*tail=NULL;}
    else {
        node_t* temp=*head;
        for(int i=0;i<pos-1;i++)
        {
            *head=(*head)->next;
        }
        *tail=(*head)->next;(*head)->next=NULL;
        *head=temp;
    }
}
void MergeList(node_t **head1, node_t **head2) {
    node_t* temp=*head1;
    if(*head1==NULL){
        *head1=*head2;*head2=NULL;
    }
    else
    {
        while ((*head1)->next != NULL)
        {
            *head1 = (*head1)->next;
        }
        (*head1)->next = *head2;
        *head2 = NULL;
        *head1 = temp;
    }
}
// #ifdef JOJ
// int main(){
//     ex7();
//     return 0;
// }
// #endif
