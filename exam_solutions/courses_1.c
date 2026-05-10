#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u32 unsigned int
#define u64 unsigned long long

typedef struct {
    u64 id;
    char name[129];
    char teacher[65];
    char start_date[11];
    int n_students;
} Course;

typedef struct {
    char full_name[65];
    u64 faculty_id;
    int n_courses;
    u64 course_ids[10];
} Student;

u32 to_timestamp(char* date) {
    int day, month, year;
    sscanf(date, "%d.%d.%d", &month, &day, &year);
    return (year << 9) | (month << 5) | day;
}

int write_courses_file(Course* array, int size, char* teacher, char* period_start, char* period_end) {
    FILE* f = fopen("course_info.txt", "w");
    if (f == NULL) {
        printf("Error creating course info file.");
        return -1;
    }

    u32 start_timestamp = to_timestamp(period_start);
    u32 end_timestamp = to_timestamp(period_end);

    int count = 0;
    for (int i = 0; i < size; i++) {
        Course* c = &array[i];
        if (strcmp(c->teacher, teacher) != 0) {
            continue;
        }

        u32 timestamp = to_timestamp(c->start_date);
        if (timestamp < start_timestamp || timestamp > end_timestamp) {
            continue;
        }

        count++;
        fprintf(f, "%llu:%s:%s-%d\n", c->id, c->name, c->start_date, c->n_students);
    }

    fclose(f);
    return count;
}

int enroll_student(Course* courses, int courses_size, Student* students, int students_size, u64 faculty_id, u64 course_id) {
    Course* course = NULL;
    for (int i = 0; i < courses_size; i++) {
        Course* c = &courses[i];
        if (c->id == course_id) {
            course = c;
            break;
        }
    }

    if (course == NULL) {
        printf("Unable to find the target course!");
        return 0;
    }

    if (course->n_students >= 30) {
        printf("The course is full!");
        return 0;
    }

    Student* student = NULL;
    for (int i = 0; i < students_size; i++) {
        Student* s = &students[i];
        if (s->faculty_id == faculty_id) {
            student = s;
            break;
        }
    }

    if (student == NULL) {
        printf("Unable to find the target student!");
        return 0;
    }

    if (student->n_courses >= 10) {
        printf("Student is already enrolled in the maximum amount of courses!");
        return 0;
    }

    for (int i = 0; i < student->n_courses; i++) {
        if (student->course_ids[i] == course_id) {
            printf("Student is already enrolled in the course!");
            return 0;
        }
    }
    
    FILE* f = fopen("course_student.bin", "ab");
    if (f == NULL) {
        printf("Error opening course_student.bin!");
        return -1;
    }

    fwrite(&course_id, sizeof(u64), 1, f);
    fwrite(&faculty_id, sizeof(u64), 1, f);
    fclose(f);

    course->n_students++;
    student->course_ids[student->n_courses++] = course_id;

    return 1;
}

void remove_courses_before_date(Course** array, int* size, char* date) {
    int counter = 0;
    u32 timestamp = to_timestamp(date);

    for (int i = 0; i < *size; i++) {
        if (to_timestamp((*array)[i].start_date) < timestamp) {
            continue;
        }

        (*array)[counter++] = (*array)[i];
    }

    if (counter == *size) {
        printf("No courses start before the provided date!");
        return;
    }

    *size = counter;
    *array = realloc(*array, counter * sizeof(Course));
}

int main() {
    int courses_size;
    printf("Enter number of courses: "); scanf("%d", &courses_size);
    Course* courses = calloc(courses_size, sizeof(Course));
    if (courses == NULL) {
        printf("Error allocating courses array!");
        return 1;
    }

    for (int i = 0; i < courses_size; i++) {
        Course* c = &courses[i];
        printf("Enter ID: "); scanf("%llu", &c->id);
        printf("Enter name: "); scanf(" %128[^\n]", c->name);
        printf("Enter teacher: "); scanf(" %64[^\n]", c->teacher);
        printf("Enter start date (mm.dd.yyyy): "); scanf(" %10[^\n]", c->start_date);
    }

    int students_size;
    printf("Enter number of students: "); scanf("%d", &students_size);
    Student* students = calloc(students_size, sizeof(Student));
    if (students == NULL) {
        printf("Error allocating students array!");
        return 1;
    }

    for (int i = 0; i < students_size; i++) {
        Student* s = &students[i];
        printf("Enter full name: "); scanf(" %64[^\n]", s->full_name);
        printf("Enter faculty ID: "); scanf("%llu", &s->faculty_id);
    }

    return 0;
}