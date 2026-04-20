#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    double grade;
} Student;

typedef struct {
    Student students[10][3];
    int class_count;
} Graduation;

double class_average(Student students[]) {
    double sum = 0.0;
    for (int i = 0; i < 3; i++) {
        sum += students[i].grade;
    }
    return sum / 3;
}

double graduation_average(Graduation g) {
    double sum = 0.0;
    int total = 0;
    for (int i = 0; i < g.class_count; i++) {
        for (int j = 0; j < 3; j++) {
            sum += g.students[i][j].grade;
            total++;
        }
    }
    if (total == 0) return 0.0;
    return sum / total;
}

int main() {
    Graduation grad;
    grad.class_count = 2;

    strcpy(grad.students[0][0].name, "Ivan");
    grad.students[0][0].age = 18;
    grad.students[0][0].grade = 5.50;
    strcpy(grad.students[0][1].name, "Maria");
    grad.students[0][1].age = 18;
    grad.students[0][1].grade = 5.80;
    strcpy(grad.students[0][2].name, "Petar");
    grad.students[0][2].age = 19;
    grad.students[0][2].grade = 4.70;

    strcpy(grad.students[1][0].name, "Elena");
    grad.students[1][0].age = 18;
    grad.students[1][0].grade = 6.00;
    strcpy(grad.students[1][1].name, "Georgi");
    grad.students[1][1].age = 18;
    grad.students[1][1].grade = 4.50;
    strcpy(grad.students[1][2].name, "Nikola");
    grad.students[1][2].age = 19;
    grad.students[1][2].grade = 5.20;

    for (int i = 0; i < grad.class_count; i++) {
        printf("class %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("  %s, age %d, grade %.2f\n",
                   grad.students[i][j].name,
                   grad.students[i][j].age,
                   grad.students[i][j].grade);
        }
        printf("  average for class %d: %.2f\n",
               i + 1, class_average(grad.students[i]));
    }

    printf("\ngraduation average: %.2f\n", graduation_average(grad));

    return 0;
}