#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 5

typedef struct {
    char last_name[30];
    char location[30];
    float grade_point_average;
} student;

/*
A list of applicants is given. Each line contains the surname of the applicant,
his permanent place of residence, the average grade of the certificate.
Determine the GPA of the university certificate and print the list
applicants whose average score is not lower than the university average.
The list must be sorted alphabetically.
*/
int main() {
    int i;
    student student_list[NUM_STUDENTS] = {
        {"Bakuvich", "Dzerzhinsk", 9.35},
        {"Savkov   ", "Minsk     ", 8.13},
        {"Anivich ", "Dzerzhinsk", 5.78},
        {"Shko    ", "Mogilev   ", 6.53},
        {"Smoh    ", "Minsk     ", 10}
    },
    temp;
    float average_sum = 0;

    // Bubble sort
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3-i; j++) {
            if (
                strcmp(student_list[j].last_name, student_list[j+1].last_name) > 0) {
                temp = student_list[j];
                student_list[j] = student_list[j+1];
                student_list[j+1] = temp;
            }
        }
    }

    for (i = 0; i < NUM_STUDENTS; i++) {
        average_sum += student_list[i].grade_point_average;
    }
    average_sum = average_sum / NUM_STUDENTS;

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf(
            "%s\t %s\t %.2f\n",
            student_list[i].last_name,
            student_list[i].location,
            student_list[i].grade_point_average
        );
    }

    printf("University grade point average: %.2f\n", average_sum);
    return 0;
}
