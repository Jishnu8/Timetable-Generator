#include "clas.h"
#include "course.h"
#include <iostream>
#include <cmath>

using namespace std;

clas::clas(teacher t, course* c): teacher_obj(t)
{
    course_obj = c;
    //course_obj = new course(c->get_student_names(), c->get_subject_name(), c->get_no_of_periods());
    period_index = -1;
    class_spacing = ceil(7/c->get_no_of_periods());
    backtrack_restrictions = new int[42];
    backtrack_restrictions_size = 0;
}

int clas::calc_class_spacing() {
    return ceil(7/clas::get_course_obj()->get_no_of_periods());
}

teacher clas::get_teacher_obj() const
{
    return teacher_obj;
}

course* clas::get_course_obj() const
{
    return course_obj;
}

clas::clas():course_obj(nullptr), backtrack_restrictions(nullptr), period_index(0), backtrack_restrictions_size(0){}

//clas::~clas(){
//    delete[] backtrack_restrictions;
//}
