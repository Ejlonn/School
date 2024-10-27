#ifndef FILE_NAME
#define FILE_NAME "data/data.txt"
#endif

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct List{
    int num;
    char name[10];
    char surname [10];
    int grade;
    float average;
    struct List* next;
    struct List* prev;
};

typedef struct List node;

typedef struct Class{
    int studentCount = 0;
    float sumOfAverage = 0;
    float max = 0;
    float min = 0;

}Class;

void addStudent(node** head,int num,char* name,char* surname,int grade, float average);
void readToFile(node** head);
void printList(node *head);
void searchPerson(node** head, int num);
void deletePersonFromList(node** head);
void classInfo(node** head);
void groupInfo(node** head);
