#include "school.hpp"

void readToFile(node** head){

    FILE* file;
    
    file = fopen(FILE_NAME, "r+");
    
    if (file == NULL)
    {
        perror("Dosya okuma hatasi!");
        return;
    }
    

    char line[256];

    int num,grade;
    char name[10],surname[10];
    float average;
    
    fgets(line, sizeof(line), file);
    while(fscanf(file,"%d %s %s %d %f",&num,name,surname,&grade,&average) == 5){
        
        addStudent(head,num,name,surname,grade,average);
    }
    fclose(file);
}

