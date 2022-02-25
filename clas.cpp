#include "clas.h"
#include "course.h"
#include "course.cpp"

using namespace std;

clas::clas(teacher t, course* c): teacher_obj(t)
{
    course_obj = new course(c->get_student_names(), c->get_subject_name(), c->get_no_of_periods());
    period_index = -1;
    //class_spacing
}
