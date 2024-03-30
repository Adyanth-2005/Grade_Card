#include <stdio.h>
#include "grade_card.h"

#define MAX_STUDENTS 10 // Define the maximum number of students
#define MAX_SUBJECTS 6 // Define the maximum number of subjects
#define NUM_EXAMS 3     // Define the number of exams

int main() {
    int numStudents;
    
    // User input for numebr of students 
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    // Validate the number of students
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }

    char names[MAX_STUDENTS][50];
    int rollNumbers[MAX_STUDENTS];
    long long phoneNumbers[MAX_STUDENTS];
    char subjects[MAX_SUBJECTS][50];

    // Input student information
    for (int s = 0; s < numStudents; s++) {
        printf("Enter name for student %d: ", s + 1);
        scanf("%s", names[s]);
        
        printf("Enter roll number for student %d: ", s + 1);
        scanf("%d", &rollNumbers[s]);
        
        printf("Enter phone number for student %d: ", s + 1);
        scanf("%lld", &phoneNumbers[s]);
    }

    // User input for number of subjects
    int numSubjects;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);
    
    // Validate the number of subjects
    if (numSubjects <= 0 || numSubjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects. Please enter a number between 1 and %d.\n", MAX_SUBJECTS);
        return 1;
    }
    
    // Input subject names
    printf("Enter subject names:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%s", subjects[i]);
    }

    int choice, studentIndex, subjectIndex;
    float marks[MAX_STUDENTS][MAX_SUBJECTS][NUM_EXAMS];

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
                    return 1; // Exit with error
                }
            }
        }
    }

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
            totalMarks += (subjectTotalMarks/2 +10);
            printf(" %-5.2f|\n", (subjectTotalMarks/2 + 10));
        }
        printf("=======================================================\n");
        // Calculate SGPA
        float totalScaledMarks = (totalMarks) + 10;
        float sgpa = calculateSGPA(totalScaledMarks);
        printf("Total SGPA: %.2f\n", sgpa);
    } else {
        printf("Invalid student index!\n");
    }

    return 0;
}
