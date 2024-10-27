#include "school.hpp"

void searchPerson(node** head, int num) {
    node* iter = *head;
    int found = 0; 

    do {

        if (iter->num == num) {
            printf("%s %s listede mevcuttur. Not Ortalamasi: %.2f, ", 
                   iter->name, iter->surname, iter->average);
            if (iter->average >= 3.00) {
                printf("Durum: Basarili\n");
            } else {
                printf("Durum: Basarisiz\n");
            }
            found = 1;
        }
        iter = iter->next;
    } while (iter != *head);

 
    if (!found) {
        printf("No record found for number %d\n", num);
    }
}