#ifndef TEACHER_H
#define TEACHER_H

using namespace std;

#include <string>
#include "course.h"

class teacher{
    string teacher_name;
    course* course_array;
    int* teacher_restrictions;

    public:
    teacher(string, course*, int*);
    ~teacher();
    
    string get_teacher_name() const;
    course* get_course_array() const;
    int* get_teacher_restrictions() const;
};


#endif //TEACHER_H