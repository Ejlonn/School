#include "school.hpp"

void deletePersonFromList(node** head){

    node* iter = *head;
    int num;
    char surname[10];
    char name[10];
    int control = 0;

    printf("Bir ogrenci numarasi giriniz: ");
    scanf("%d",&num);
    printf("Bir ogrenci adi giriniz: ");
    scanf("%s",name);
    printf("Bir ogrenci soyadi giriniz: ");
    scanf("%s",surname);

    do{

        if(iter->num == num && (strcmp(iter->name,name)==0) && (strcmp(iter->surname,surname)==0)){

            if(iter == *head){
                
                (*head)->prev->next = (*head)->next;
                (*head)->next->prev = (*head)->prev;
                free(iter);
                *head = (*head)->next;
                control = 1;
            }
            else{
                iter->next->prev = iter->prev;
                iter->prev->next = iter->next;
                free(iter);
                control = 1;
            }    
        }
        
        
        iter = iter->next;
    
    } while (iter != *head);

    if(control){
           printf("%d numarali %s %s listeden silinmistir.\n",num,name,surname);     
        }
    else{
        printf("Ogrenci mevcut degil\n");
    }    
}