#include <stdio.h>

#define SUBJECTS 3

void calculate(int marks[], int n, int *total, float *average) {
    *total = 0;
    for (int i = 0; i < n; i++) {
        *total += marks[i];
    }
    *average = (float)(*total) / n;
}

int main() {
    int students;
    printf("Enter number of students (max 8): ");
    scanf("%d", &students);

    if (students > 8 || students <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    int marks[students][SUBJECTS];
    int total;
    float average, classAverage = 0;

    printf("\nEnter marks of %d students in %d subjects:\n", students, SUBJECTS);

    for (int i = 0; i < students; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    printf("\n===== Class Performance Report =====\n");
    printf("Student\t\tTotal\tAverage\tPerformance\n");

    for (int i = 0; i < students; i++) {
        calculate(marks[i], SUBJECTS, &total, &average);
        classAverage += average;

        printf("%d\t\t%d\t%.2f\t", i + 1, total, average);

        if (average >= 75)
            printf("Excellent\n");
        else if (average >= 50)
            printf("Good\n");
        else
            printf("Needs Improvement\n");
    }

    classAverage /= students;
    printf("\nOverall Class Average: %.2f\n", classAverage);

    if (classAverage >= 75)
        printf("Class Performance: Excellent\n");
    else if (classAverage >= 50)
        printf("Class Performance: Average\n");
    else
        printf("Class Performance: Poor\n");

    return 0;
}