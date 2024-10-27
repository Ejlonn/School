#include "school.hpp"

void groupInfo(node** head){

    node* iter = *head;
    Class school[3];
    

    do{ 
        
        school[(iter->grade)-1].studentCount++;
        
        school[(iter->grade)-1].sumOfAverage += iter->average;

        if (school[(iter->grade)-1].studentCount == 1)
        {
            school[(iter->grade)-1].max = iter->average;        
            school[(iter->grade)-1].min = iter->average;
        }
        

        if(school[(iter->grade)-1].min > iter->average){
            school[(iter->grade)-1].min = iter->average;
        }
        if(school[(iter->grade)-1].max < iter->average){
            school[(iter->grade)-1].max = iter->average;
        }

    iter = iter->next; 
    }while (iter != *head);
    

    printf("Her sinifta yer alan toplam öğrenci sayisi: %d.Sinif: %d, %d.Sinif: %d, %d.Sinif: %d ",1,school[0].studentCount,2,school[1].studentCount,3,school[2].studentCount);
    printf("\nHer sinifta yer alan öğrencilerin toplam ortalamasi: 1.sinif: %.2f, 2.sinif: %.2f, 3.sinif: %.2f",school[0].sumOfAverage, school[1].sumOfAverage,school[2].sumOfAverage);
    printf("\nHer sinifta yer alan öğrencilerin maksimum ve minimum ortalamasi:\n 1.sinif: max: %.2f ve min: %.2f;\n2.sinif: max: %.2f ve min: %.2f;\n3.sinif: max: %.2f ve min: %.2f\n",school[0].max,school[0].min,school[1].max,school[1].min,school[2].max,school[2].min);
    
}