#include "school.hpp"

void addStudent(node** head,int num,char* name,char* surname,int grade, float average){

    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Bellek ayirma hatasi");
        return;
    }

    newNode->num = num;
    strcpy(newNode->name,name);
    strcpy(newNode->surname,surname);
    newNode->grade = grade;
    newNode->average = average;

    if(*head == NULL){

        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return ;
    }
    node* iter = *head;

    do{
        if(iter->num > num || (iter->num == num && strcmp(iter->surname,surname) > 0) || (iter->num == num && strcmp(iter->surname,surname) == 0 && strcmp(iter->name,name) > 0)){

            newNode->next = iter;
            newNode->prev = iter->prev;
            iter->prev->next = newNode;
            iter->prev = newNode;

            if(iter == *head && iter->num > num){
                *head = newNode;

            }
            return ; 
    }
        iter = iter->next;
    } while (iter != *head);
    
    newNode->next = *head;
    newNode->prev = (*head)->prev;
    (*head)->prev->next = newNode;
    (*head)->prev = newNode;
}