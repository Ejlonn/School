#include "school.hpp"

void printList(node *head) {
    if (head == NULL) return;

    node *current = head;
    do {
        printf("%d %s %s %d %.2f\n", current->num, current->name, current->surname, current->grade, current->average);
        current = current->next;
    } while (current != head);
}