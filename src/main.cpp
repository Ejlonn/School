#include "school.hpp"



int main(){
    node *head = NULL;
    readToFile(&head);
       
    int op;
    //printf("\nYapmak istediginiz islemi secin: ");
    printf("\n1: Listedeki ogrencileri bastir: ");
    printf("\n2: Listedeki sinif bilgisini bastir: ");
    printf("\n3: Listede ogrenci numarasina gore arama yap: ");
    printf("\n4: Listeden ogrenci sil: ");
    printf("\n5: Listeden ogrencileri ortalamaya gore bastir: ");
    printf("\n\n9: Cikis yap: ");

    while (1)
    {   
        printf("\nIslem girin: ");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            printList(head);
            break;
        case 2:
            classInfo(&head);
            break;
        case 3:
            int search;
            printf("Aramak istediginiz ogrencinin numarasini girin: ");
            scanf("%d",&search);
            searchPerson(&head,search);
            break;
        case 4:
            deletePersonFromList(&head);
            break;
        case 5:
            groupInfo(&head);
            break;

        case 9:
            printf("Cikis yapildi!\n");
            return 0;
            break;        
        default:
            break;
        }
    }
 

    return 0;
}