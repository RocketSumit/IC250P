//source code to form a marksheet of student from a FILE

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct student 
{
    char first_name[50];
    char last_name[50];

    int roll_no;
     int marks[5];
    char grades[5];
};

//function to print n number of dashes
void print_dashes(int n);

//function to print the marsheet of student
void marksheet(struct student s1, char sb1[5], char sb2[5], char sb3[5],char sb4[5],char sb5[5]);

int main()
{
    
    struct student students[50];//assuming strength of class to be 50

    //strings to store subjects code
    char sb1[6];
    char sb2[6];
    char sb3[6];
    char sb4[6];
    char sb5[6];
   
     FILE *data_file = fopen("/Users/sumitpatidar/Desktop/assignment00/master.txt", "r");

    // current position in students array
    int i = 0;


    char useless1[50], useless2[50], useless3[50];

    //First three are useless for us and hence are read just to pass the file pointer
    fscanf(data_file, "%s %s %s %s %s %s %s %s", useless1, useless2, useless3, sb1, sb2, sb3, sb4, sb5);

    while(fscanf(data_file, "%d %s %s %d %c %d %c %d %c %d %c %d %c\n", 
            &students[i].roll_no,
            students[i].first_name,
            students[i].last_name,
            &students[i].marks[0],
            &students[i].grades[0],
            &students[i].marks[1],
            &students[i].grades[1],
            &students[i].marks[2],
            &students[i].grades[2],
            &students[i].marks[3],
            &students[i].grades[3],
            &students[i].marks[4],
            &students[i].grades[4]) == 13) {
        i++;
    }

    int rollnumber;;

    printf("Enter the rollnumber of student: ");
    scanf("%d",&rollnumber);

    int k =0;

    while(rollnumber!=students[k].roll_no){
        k++;
         }

    marksheet(students[k], sb1, sb2, sb3, sb4, sb5);

    return 0;

}
void print_dashes(int n){

    printf("\n");

    for(int i = 0; i<n; i++){
        printf("_");
    }
}
void marksheet(struct student s1, char sb1[5], char sb2[5], char sb3[5], char sb4[5], char sb5[5]){

     
 
    //Array to store Maximum marks
    int maxMarks[] = {100, 100, 100, 100, 50};

    printf("\n\n\n\t\t\tIndian Institute of Technology Mandi\n\t\t\tAcademic Session : (Aug-Dec) 2016");
    print_dashes(80);

    printf("\nName of the Student : %s %s", s1.first_name, s1.last_name );
    printf("\nRoll Number         : %d", s1.roll_no);

    print_dashes(80);
    printf("\nSr. No  |  Subject Code  |  Maximum  |  Marks Obtained  |  Grade\n");
    print_dashes(80);

    printf("\n  [1]        %s           %d             %d             %c\n", sb1, maxMarks[0], s1.marks[0], s1.grades[0] );
    printf("\n  [2]        %s           %d             %d             %c\n", sb2, maxMarks[1], s1.marks[1], s1.grades[1] );
    printf("\n  [3]        %s           %d             %d             %c\n", sb3, maxMarks[2], s1.marks[2], s1.grades[2] );
    printf("\n  [4]        %s           %d             %d             %c\n", sb4, maxMarks[3], s1.marks[3], s1.grades[3] );
    printf("\n  [5]        %s           %d              %d             %c\n", sb5, maxMarks[4], s1.marks[4], s1.grades[4] );

    print_dashes(80);

    int totalMarks = (s1.marks[0] + s1.marks[1] + s1.marks[2] + s1.marks[3] + s1.marks[4]);

    char division[15];
    int percentage = (totalMarks/450.0)*100;

    //finding which division student passed
    if(percentage>60)
    strncpy(division, "First", 6 );
    else if(percentage>45 && percentage<60)
    strncpy(division, "Second", 7 );
    else if(percentage>30 && percentage<45)
    strncpy(division, "Third", 6 );
    else
    strncpy(division, "FAIL", 5);

    printf("\n\t\t\tTotal 450\t Total %d\n\n", totalMarks);
    printf("\t  Percentage %d%% Student passed with %s division",percentage, division);

    print_dashes(80);
    printf("\n");
}