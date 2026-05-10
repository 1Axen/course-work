#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u32 unsigned int
#define u64 unsigned long long

#define MAX_COURSES_PER_STUDENT 7
#define MAX_STUDENTS_PER_COURSE 50

typedef enum {
    Design,
    Programming
} CourseType;

typedef struct
{
    u64 id;
    char name[129];
    char start_date[11];
    float price;
    int n_students;
    CourseType type;
} Course;

typedef struct {
    u64 faculty_id;
    char full_name[81];
    int n_courses;
    u64 course_ids[MAX_COURSES_PER_STUDENT];
} Student;

u32 to_timestamp(int day, int month, int year) {
    return (year << 9) | (month << 5) | day;
}

u32 mdy_to_timestamp(char* date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &month, &day, &year);
    return to_timestamp(day, month, year);
}

u32 dmy_to_timestamp(char* date) {
    int day, month, year;
    sscanf(date, "%d.%d.%d", &day, &month, &year);
    return to_timestamp(day, month, year);
}

void* read_binary_file(const char* file_name, size_t element_size, int* size_out) {
    FILE* f = fopen(file_name, "rb");
    if (f == NULL) {
        printf("Error opening file %s for reading!", file_name);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    int size = ftell(f) / element_size;
    rewind(f);

    void* array = calloc(size, element_size);
    if (array != NULL) {
        fread(array, element_size, size, f);
    }
    else {
        size = 0;
        printf("Error allocating array!");
    }

    fclose(f);

    *size_out = size;
    return array;
}

void remove_courses(Course** array, int* size, CourseType type, char* date) {
    int counter = 0;
    u32 timestamp = dmy_to_timestamp(date);
    for (int i = 0; i < *size; i++) {
        Course* course = &(*array)[i];
        if (
            course->type == type
            && course->n_students < 8
            && mdy_to_timestamp(course->start_date) > timestamp
        ) {
            continue;
        }

        (*array)[counter++] = *course;
    }

    if (counter == *size) {
        printf("No courses match the given input!");
        return;
    }

    *size = counter;
    *array = realloc(*array, counter * sizeof(Course));
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

    if (course->n_students >= MAX_STUDENTS_PER_COURSE) {
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

    if (student->n_courses >= MAX_COURSES_PER_STUDENT) {
        printf("Student is already enrolled in the maximum amount of courses!");
        return 0;
    }

    for (int i = 0; i < student->n_courses; i++) {
        if (student->course_ids[i] == course_id) {
            printf("Student is already enrolled in the course!");
            return 0;
        }
    }
    
    FILE* f = fopen("students_info.txt", "a+");
    if (f == NULL) {
        printf("Error opening file!");
        return -1;
    }

    fprintf(f, "%llu;%llu;%s;%.2f\n", course_id, faculty_id, course->start_date, course->price);
    fclose(f);

    course->n_students++;
    student->course_ids[student->n_courses++] = course_id;

    return 1;
}

Course* find_open_courses_below_average_price(Course* array, int size, int* size_out) {
    if (size <= 1) {
        return NULL;
    }
    
    float average_price = 0;
    for (int i = 0; i < size; i++) {
        average_price += array[i].price;
    }

    average_price /= size;
    
    int counter = 0;
    Course* result = malloc((size - 1) * sizeof(Course));
    for (int i = 0; i < size; i++) {
        if (array[i].n_students < MAX_STUDENTS_PER_COURSE && array[i].price < average_price) {
            result[counter++] = array[i];
        }
    }

    *size_out = counter;
    if (counter == 0) {
        free(result);
        return NULL;
    }

    return realloc(result, counter * sizeof(Course));
}

int main() {
    int courses_size = 0;
    Course* courses = read_binary_file("courses.bin", sizeof(Course), &courses_size);
    if (courses == NULL) {
        printf("Error reading courses.bin!");
        return 1;
    }

    int students_size = 0;
    Student* students = read_binary_file("students.bin", sizeof(Student), &students_size);
    if (students == NULL) {
        printf("Error reading students.bin!");
        return 1;
    }

    return 0;
}