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
};


#endif //TEACHER_H