#include <iostream>
#include <stdio.h>
#include <string.h>
#include "teacher.h"
#include "course.h"
#include "clas.h"
#include "period.h"


using namespace std;

period timetable[42];
clas* class_array;
int class_index = 0;
int capacity;

bool is_restricted(int period_index, int class_index, int* array_pointer);
bool is_full(int period_index);
bool is_overlapping(int period_index, int class_index);

bool is_restricted(int period_index, int class_index, int* array_pointer) {
    for (int i = 0; i < sizeof(array_pointer) / sizeof(array_pointer[0]); i++) {
        if (period_index == array_pointer[i]) {
            return true;
        }
    }
    return false;
}

bool is_full(int period_index) {
    if (timetable[period_index].period_subject_index == capacity - 1) {
        return true;
    }
    return false;
}

bool is_overlapping(int period_index, int class_index) {
    class* period_subject_list = timetable[period_index].period_subject_list;
    for (int i = 0; i <= timetable[periodIndex].period_subject_index; i++) {
        if (period_subject_list[i].teacher.name == class_array[class_index].get_teacher_obj.name) {
            return true;
        }
    }
    string* timetable_student_list;
    string* clas_student_list;
    for (int i = 0; i <= timetable[period_index].period_subject_index; i++) {
        student_list = timetable[period_index].period_subject_list[i].get_course_obj()->get_student_names()
            for (int j = 0; j < sizeof(timetable_student_list) / sizeof(timetable_student_list[0]; j++) {
                clas_student_list = class_array[class_index].get_course_obj()->get_student_names();
                    for (int k = 0; k < sizeof(clas_student_array) / sizeof(clas_student_array[0]); k++) {
                        
                }
            }
    }
}

int main(){
    cout << "buffalo";
    return 0;
}