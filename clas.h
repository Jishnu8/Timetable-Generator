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
    int* backtrack_restrictions;
    int backtrack_restrictions_size;
    clas(teacher, course*);
    clas();
    int calc_class_spacing();
    //~clas();

    static int num_periods_per_day;
    static int num_periods_per_week;

    teacher get_teacher_obj() const;
    course* get_course_obj() const;
};

#endif //CLAS_H
