#include "clas.h"
#include "course.h"
#include <cmath>

using namespace std;

clas::clas(teacher t, course* c): teacher_obj(t)
{
    course_obj = c;
    //course_obj = new course(c->get_student_names(), c->get_subject_name(), c->get_no_of_periods());
    period_index = -1;
    class_spacing = ceil(7/c->get_no_of_periods());
}

teacher clas::get_teacher_obj() const
{
    return teacher_obj;
}

course* clas::get_course_obj() const
{
    return course_obj;
}

clas::clas():course_obj(NULL), backtrack_restrictions(NULL), period_index(0), backtrack_restrictions_size(0){}

clas::~clas(){
    delete[] backtrack_restrictions;
}
