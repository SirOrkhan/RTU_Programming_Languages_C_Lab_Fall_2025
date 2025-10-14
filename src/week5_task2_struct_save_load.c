// week5_task4_struct_binary_io.c
// Bonus Task 4: Binary file version – Save and load struct Student
// Week 5 – Files & Modular Programming
// Orkhan Hajizada(241ADB170)
// TODO: Implement binary save and load for Student struct

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define BINARY_FILE "student.bin"

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student_binary(Student s, const char *filename);
Student load_student_binary(const char *filename);

int main(void) {
    Student s1, s2;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    // TODO: Save student in binary format
    printf("Saving student in binary format...\n");
    save_student_binary(s1, BINARY_FILE);

    // TODO: Load student from binary file
    printf("Loading student from binary file...\n");
    s2 = load_student_binary(BINARY_FILE);

    // TODO: Print loaded data
    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

    // TODO: Print binary file size
    FILE *fp = fopen(BINARY_FILE, "rb");
    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        fclose(fp);
        printf("Binary file size: %ld bytes\n", size);
    }

    return 0;
}

// TODO: Implement save_student_binary()
// Open file in "wb", check errors, write struct, close file
void save_student_binary(Student s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening binary file for writing");
        exit(1);
    }

    if (fwrite(&s, sizeof(Student), 1, fp) != 1) {
        perror("Error writing student to binary file");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
}

// TODO: Implement load_student_binary()
// Open file in "rb", check errors, read struct, close file
Student load_student_binary(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening binary file for reading");
        exit(1);
    }

    if (fread(&s, sizeof(Student), 1, fp) != 1) {
        perror("Error reading student from binary file");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return s;
}
