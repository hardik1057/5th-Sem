/*Write a C program to assign values to each member of the following structure.
Pass the populated structure to a function Using call-by-value and another
function using call-by-address and print the value of each member of the
structure.
struct student_info{
int roll_no;
char name [50];
float CGPA;
struct dob age;
};
*/
#include <stdio.h>
struct dob
{
    int day, month, year;
};
struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void printByValue(struct student_info student)
{
    printf("Student Information (Call-by-Value):\n");
    printf("Roll No: %d\nName: %s\nCGPA: %.2f\nDate of Birth: %d-%d-%d\n",
           student.roll_no, student.name, student.CGPA, student.age.day, student.age.month, student.age.year);
}

void printByAddress(struct student_info *studentPtr)
{
    printf("Student Information (Call-by-Address):\n");
    printf("Roll No: %d\nName: %s\nCGPA: %.2f\nDate of Birth: %d-%d-%d\n",
           studentPtr->roll_no, studentPtr->name, studentPtr->CGPA, studentPtr->age.day, studentPtr->age.month, studentPtr->age.year);
}

int main()
{
    struct student_info student1 = {101, "John Doe", 8.5, {15, 3, 2000}};
    printByValue(student1);
    printf("\n");
    printByAddress(&student1);
    return 0;
}
