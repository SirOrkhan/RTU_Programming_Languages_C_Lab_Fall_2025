/*
 * week4_2_struct_student.c
 * Author: [Orkhan Hajizada]
 * Student ID: [241ADB170]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
// Example:
struct Student {
     char name[50];
     int id;
     float grade;
 };

int main(void) {
    // TODO: Declare one or more Student variables
     struct Student s1, s2;

    // TODO: Assign values (either manually or via scanf)
     strcpy(s1.name, "Alice Johnson");
        s1.id = 1001;
        s1.grade = 9.1;
    
    strcpy(s2.name, "Bob Smith");
        s2.id = 1002;
        s2.grade = 8.7;

    // TODO: Print struct contents using printf
    printf("Student 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

    return 0;
}
