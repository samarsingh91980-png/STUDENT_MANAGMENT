#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student students[100];
    int count = 0;
    int choice, roll, i, found;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Roll Number: ");
            scanf("%d", &students[count].rollNo);

            printf("Enter Name: ");
            scanf(" %[^\n]", students[count].name);

            printf("Enter Marks: ");
            scanf("%f", &students[count].marks);

            count++;

            printf("Student added successfully!\n");
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No students found.\n");
            } else {
                printf("\n--- Student List ---\n");

                for (i = 0; i < count; i++) {
                    printf("\nRoll No: %d\n", students[i].rollNo);
                    printf("Name: %s\n", students[i].name);
                    printf("Marks: %.2f\n", students[i].marks);
                }
            }
        }

        else if (choice == 3) {
            printf("Enter Roll Number to search: ");
            scanf("%d", &roll);

            found = 0;

            for (i = 0; i < count; i++) {
                if (students[i].rollNo == roll) {
                    printf("\nStudent Found!\n");
                    printf("Roll No: %d\n", students[i].rollNo);
                    printf("Name: %s\n", students[i].name);
                    printf("Marks: %.2f\n", students[i].marks);

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student not found.\n");
            }
        }

        else if (choice == 4) {
            printf("Enter Roll Number to update: ");
            scanf("%d", &roll);

            found = 0;

            for (i = 0; i < count; i++) {
                if (students[i].rollNo == roll) {
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", students[i].name);

                    printf("Enter New Marks: ");
                    scanf("%f", &students[i].marks);

                    printf("Student updated successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student not found.\n");
            }
        }

        else if (choice == 5) {
            printf("Enter Roll Number to delete: ");
            scanf("%d", &roll);

            found = 0;

            for (i = 0; i < count; i++) {
                if (students[i].rollNo == roll) {

                    for (int j = i; j < count - 1; j++) {
                        students[j] = students[j + 1];
                    }

                    count--;

                    printf("Student deleted successfully!\n");

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student not found.\n");
            }
        }

        else if (choice == 6) {
            printf("Thank you for using the program!\n");
            break;
        }

        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
