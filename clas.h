#ifndef CLAS_H
#define CLAS_H

#include "teacher.h"
#include "course.h"

class clas{
    teacher teacher_obj;
    course* course_obj;

    public:
    int period_index;
    int class_spacing;
    int* backtrackRestrictions;
    clas(teacher, course*);
    ~clas(); 

    teacher get_teacher_obj() const;
    course* get_course_obj() const;  
};

#endif //CLAS_H