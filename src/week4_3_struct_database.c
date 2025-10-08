/*
 * week4_3_struct_database.c
 * Author: [Orkhan Hajizada]
 * Student ID: [241ADB170]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // TODO: Allocate memory for n Student structs using malloc
    students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // TODO: Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);
        // Example input format: Name ID Grade
        scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade);
    }

    // TODO: Display all student records in formatted output
     printf("\n%-6s %-15s %-6s\n", "ID", "Name", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-15s %-6.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    // Optional: Compute average grade or find top student
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    printf("\nAverage grade: %.2f\n", total / n);

    // TODO: Free allocated memory
     free(students);

    return 0;
}
