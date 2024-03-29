#include <stdio.h>
#include "grade_card.h"

#define MAX_STUDENTS 10 // Define the maximum number of students
#define NUM_SUBJECTS 3  // Define the number of subjects
#define NUM_EXAMS 3     // Define the number of exams

int main() {
    char names[MAX_STUDENTS][50] = {"Khushi", "Yash", "Eva", "Aarav", "Rohan", "Aditya", "Ana de dramas", "Sachin", "Rohit", "Adyanth"};
    int rollNumbers[MAX_STUDENTS] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    long long phoneNumbers[MAX_STUDENTS] = {1234567890, 9876543210, 1357924680, 2468013579, 9876543210, 1357924680, 2468013579, 1234567890, 9876543210, 1357924680};

    char subjects[NUM_SUBJECTS][50] = {"DSA", "C++", "ML"};

    int numStudents = sizeof(names) / sizeof(names[0]);

    int choice, studentIndex, subjectIndex;
    float marks[MAX_STUDENTS][NUM_SUBJECTS][NUM_EXAMS];

    printf("Enter ISA1, ISA2, and ESA marks for each subject:\n");

    for (int s = 0; s < numStudents; s++) {
        printf("Student: %s\n", names[s]);
        for (int i = 0; i < NUM_SUBJECTS; i++) {
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
        printf("| %-8s| %-5s| %-5s| %-5s| %-5s| %-5s|\n", "Subject", "ISA1", "ISA2", "ESA", "Total", "SGPA");
        printf("-------------------------------------------------------\n");
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            printf("| %-8s|", subjects[i]);
            float totalMarks = 0;
            for (int j = 0; j < NUM_EXAMS; j++) {
                printf(" %-5.2f|", marks[studentIndex][i][j]);
                totalMarks += marks[studentIndex][i][j];
            }
            // Calculate total scaled marks and SGPA
            float totalScaledMarks = (totalMarks / 2) + 10;
            float sgpa = calculateSGPA(totalScaledMarks);
            printf(" %-5.2f| %-5.2f|\n", totalScaledMarks, sgpa);
        }
        printf("=======================================================\n");
    } else {
        printf("Invalid student index!\n");
    }

    return 0;
}
