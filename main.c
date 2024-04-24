#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_card.h"

#define MAX_STUDENTS 10 // Define the maximum number of students
#define MAX_SUBJECTS 6  // Define the maximum number of subjects
#define NUM_EXAMS 3     // Define the number of exams

int main() {
    int numStudents;
    
    // User input for number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    // Validate the number of students
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }

    // Allocate memory for student information
    char (*names)[50] = malloc(numStudents * sizeof(char[50]));
    int *rollNumbers = malloc(numStudents * sizeof(int));
    long long *phoneNumbers = malloc(numStudents * sizeof(long long));

    if (names == NULL || rollNumbers == NULL || phoneNumbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input student information
    for (int s = 0; s < numStudents; s++) {
        printf("Enter name for student %d: ", s + 1);
        scanf(" %49[^\n]", names[s]); // Read a string with spaces

        printf("Enter roll number for student %d: ", s + 1);
        scanf("%d", &rollNumbers[s]);
        
        printf("Enter phone number for student %d: ", s + 1);
        scanf("%lld", &phoneNumbers[s]);
    }

    int numSubjects;
    
    // User input for number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);
    
    // Validate the number of subjects
    if (numSubjects <= 0 || numSubjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects. Please enter a number between 1 and %d.\n", MAX_SUBJECTS);
        free(names);
        free(rollNumbers);
        free(phoneNumbers);
        return 1;
    }
    
    // Allocate memory for subject names
    char (*subjects)[50] = malloc(numSubjects * sizeof(char[50]));

    if (subjects == NULL) {
        printf("Memory allocation failed.\n");
        free(names);
        free(rollNumbers);
        free(phoneNumbers);
        return 1;
    }

    // Input subject names
    printf("Enter subject names:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf(" %49[^\n]", subjects[i]); // Read a string with spaces
    }

    // Allocate memory for storing marks
    float (*marks)[MAX_SUBJECTS][NUM_EXAMS] = malloc(numStudents * sizeof(float[MAX_SUBJECTS][NUM_EXAMS]));

    if (marks == NULL) {
        printf("Memory allocation failed.\n");
        free(names);
        free(rollNumbers);
        free(phoneNumbers);
        free(subjects);
        return 1;
    }

    // Input exam marks
    printf("Enter ISA1, ISA2, and ESA marks for each subject:\n");
    for (int s = 0; s < numStudents; s++) {
        printf("Student: %s\n", names[s]);
        for (int i = 0; i < numSubjects; i++) {
            printf("Subject: %s\n", subjects[i]);
            for (int j = 0; j < NUM_EXAMS; j++) {
                printf("Enter marks for exam %d: ", j + 1);
                scanf("%f", &marks[s][i][j]);
                
                // Add validation for marks
                if (marks[s][i][j] < 0 || marks[s][i][j] > 100) {
                    printf("Invalid marks! Marks should be between 0 and 100.\n");
                    free(names);
                    free(rollNumbers);
                    free(phoneNumbers);
                    free(subjects);
                    free(marks);
                    return 1; // Exit with error
                }
            }
        }
    }

    int studentIndex;
    
    // Select student to generate grade card
    printf("Enter student index (0 to %d): ", numStudents - 1);
    scanf("%d", &studentIndex);

    if (studentIndex >= 0 && studentIndex < numStudents) {
        printf("\n================ Grade Card for %s ================\n", names[studentIndex]);
        printf("| %-8s| %-5s| %-5s| %-5s| %-5s|\n", "Subject", "ISA1", "ISA2", "ESA", "Total");
        printf("-------------------------------------------------------\n");
        
        float totalMarks = 0;
        
        for (int i = 0; i < numSubjects; i++) {
            printf("| %-8s|", subjects[i]);
            
            float subjectTotalMarks = 0;
            for (int j = 0; j < NUM_EXAMS; j++) {
                printf(" %-5.2f|", marks[studentIndex][i][j]);
                subjectTotalMarks += marks[studentIndex][i][j];
            }
            
            totalMarks += (subjectTotalMarks / 2 + 10);
            printf(" %-5.2f|\n", (subjectTotalMarks / 2 + 10));
        }
        
        printf("=======================================================\n");
        
        // Calculate SGPA
        float totalScaledMarks = totalMarks + 10;
        float sgpa = calculateSGPA(totalScaledMarks);
        printf("Total SGPA: %.2f\n", sgpa);
    } else {
        printf("Invalid student index!\n");
    }

    // Free dynamically allocated memory
    free(names);
    free(rollNumbers);
    free(phoneNumbers);
    free(subjects);
    free(marks);

    return 0;
}
