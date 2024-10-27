#include "school.hpp"

void classInfo(node** head){
    int studentCount = 0;
    float sumOfAverage = 0;
    float averageAverage;
    node* iter = *head;

    if(iter == NULL) return;
    
    do{
        studentCount++;
        sumOfAverage += iter->average;
        iter = iter->next;
    } while (iter != *head);
    
    if(studentCount == 0){
        printf("Sinifta ogrenci yok.\n");
    }
    else{
        averageAverage = sumOfAverage / studentCount;
        printf("Toplam ogrenci sayisi: %d\n",studentCount);
        printf("Toplam Ortalama: %.2f\n",sumOfAverage);
        printf("Ortalamalarin Ortalamasi: %.2f\n",averageAverage);
    }
}