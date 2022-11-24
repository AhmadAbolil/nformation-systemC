
#include <stdio.h>
#include <stdlib.h>
void print_number_of_students();
void print_number_of_class();
void print_number_of_students_in_class();
void print_students_name();
void print_classes_name();
void print_students_from_class();
char * getName(char[],int);
int main ()
{
    int option;
do{
    printf ("please select option from 1-7 \n");
    printf ("1 is for printing how many students in school\n");
    printf ("2 is for printing how many class in school\n");
    printf ("3 is for printing how many  students in specific class \n");
    printf ("4 is for printing all students names in the school\n");
    printf ("5 is for printing all class names in the school\n");
    printf ("6 is for printing all students names in specific class\n");
    printf ("7 for exit \n");
    scanf("%d",&option);
    switch (option){
        case 1:
           print_number_of_students();
           break;
         case 2:
           print_number_of_class();
           break;
         case 3:
           print_number_of_students_in_class();
           break;
         case 4:
           print_students_name();
           break;
         case 5:
           print_classes_name();
           break;
         case 6:
           print_students_from_class();
           break;
         default:
           break;
    }
}while (option!=7);
return 0;
}

void print_number_of_students() {
    int i =0;
    FILE *fp;
    char buff[255];
   
    fp=fopen("students.dat","r");
    if(!fp)
    exit(1);
    while (fgets(buff,255,(FILE *)fp)){
        i++;
    }
    printf("the number of students is %d \n",i);
    fclose (fp);
}

void print_number_of_class(){
    int i =0;
    FILE *fp;
    char buff[255];
    char className[10] = "";
   
    fp=fopen("students.dat","r");
    if(!fp)
    exit(1);
    while (fgets(buff,255,(FILE *)fp)){
        char wordd[2];
        char newString[10][10];
        int k,j,ctr;
        j=0; ctr=0;
        for(k=0;k<=(strlen(buff));k++)
        {
            // if space or NULL  assign NULL g[ctr]
            if(buff[k]==' '||buff[k]=='\0' || buff[k]=='\n')
            {
                newString[ctr][j]='\0';
                ctr++;  //for next word
                j=0;    //for next word, init index to 0
            }
            else
            {
                newString[ctr][j]=buff[k];
                j++;
            }
        }
        if (strcmp(className, newString[1]) != 0){ 
            strcpy(className, newString[1]);
            i= i + 1;
        }
    }

    printf("the number of class is %d \n", i);
    fclose (fp);
}

void print_number_of_students_in_class(){
    char inputClass[10];
    int i =0;
    printf ("please enter class name :\n");
    scanf("%s",&inputClass);
    FILE *fp;
    char buff[255];
    fp=fopen("students.dat","r");
    if(!fp)
    exit(1);
    while (fgets(buff,255,(FILE *)fp)){
        char wordd[2];
        char newString[10][10];
        int k,j,ctr;
        j=0; ctr=0;
        for(k=0;k<=(strlen(buff));k++)
        {
            // if space or NULL found,  NULL into newString[ctr]
            if(buff[k]==' '||buff[k]=='\0' || buff[k]=='\n')
            {
                newString[ctr][j]='\0';
                ctr++;  //for next word
                j=0;    //for next word, i
            }
            else
            {
                newString[ctr][j]=buff[k];
                j++;
            }
        }
        //printf("student name %s \n", newString[0]);
        printf("newString %s \n", newString[1]);
        printf("inputClass %s \n", inputClass);
        if (strcmp(inputClass, newString[1]) == 0){
            i= i + 1;
        }
    }
    printf("the number of students in class %s is %d \n",inputClass, i);
}

void print_students_name(){
    printf("Students name : \n");
    FILE *fp;
    char buff[255];
   
    fp=fopen("students.dat","r");
    if(!fp)
    exit(1);
    while (fgets(buff,255,(FILE *)fp)){
        char newString[10][10];
        int k,j,ctr;
        j=0; ctr=0;
        for(k=0;k<=(strlen(buff));k++)
        {
            // if space or assign NULL into newString[ctr]
            if(buff[k]==' '||buff[k]=='\0' || buff[k]=='\n')
            {
                newString[ctr][j]='\0';
                ctr++;  //for next word
                j=0;    //for next word, init index to 0
            }
            else
            {
                newString[ctr][j]=buff[k];
                j++;
            }
        }
        printf("%s \n", newString[0]);
    }
}

void print_classes_name(){
    printf("class names : \n");
    char className[10] = "";
    FILE *fp;
    char buff[255];
   A
    fp=fopen("students.dat","r");
    if(!fp)
    exit(1);
    while (fgets(buff,255,(FILE *)fp)){
        char newString[10][10];
        int k,j,ctr;
        j=0; ctr=0;
        for(k=0;k<=(strlen(buff));k++)
        {
            // if space or NULL found, assign NULL into newString[ctr]
            if(buff[k]==' '||buff[k]=='\0' || buff[k]=='\n')
            {
                newString[ctr][j]='\0';
                ctr++;  //for next word
                j=0;    //for next word, init index to 0
            }
            else
            {
                newString[ctr][j]=buff[k];
                j++;
            }
        }
       
        if (strcmp(className, newString[1]) != 0){
            strcpy(className, newString[1]);
            printf("%s \n", newString[1]);
           
        }
    }
}

void print_students_from_class(){
    char inputClass[10];
    int i =0;
    printf ("please enter class name :\n");
    scanf("%s",&inputClass);
    printf("Students name in class %s is : \n",inputClass);
    FILE *fp;
    char buff[255];
    fp=fopen("students.dat","r");
    if(!fp)
    exit(1);
    while (fgets(buff,255,(FILE *)fp)){
        char wordd[2];
        char newString[10][10];
        int k,j,ctr;
        j=0; ctr=0;
        for(k=0;k<=(strlen(buff));k++)
        {
            // if space or NULL found, assign NULL into newString[ctr]
            if(buff[k]==' '||buff[k]=='\0' || buff[k]=='\n')
            {
                newString[ctr][j]='\0';
                ctr++;  //for next word
                j=0;    //for next word, init index to 0
            }
            else
            {
                newString[ctr][j]=buff[k];
                j++;
            }
        }
        if (strcmp(inputClass, newString[1]) == 0){
            printf("%s \n", newString[0]);
        }
    }
}
