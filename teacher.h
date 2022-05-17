#ifndef TEACHER_H
#define TEACHER_H

using namespace std;

#include <string>
#include "course.h"

class teacher{
    string teacher_name;
    course** course_array;
    int* teacher_restrictions;
    int num_courses;

    public:
    teacher(string, course**,int, int*, int, int);
    teacher();
    int teacher_restrictions_size;
    //~teacher();

    string get_teacher_name() const;
    course** get_course_array() const;
    int* get_teacher_restrictions() const;
    int get_num_courses() const;
    void print() const;
};


#endif //TEACHER_H
