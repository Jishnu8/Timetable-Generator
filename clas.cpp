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
    cout << "Number of periods per day: " << num_periods_per_day << endl;
    class_spacing = ceil(num_periods_per_day/c->get_no_of_periods());
    backtrack_restrictions = new int[num_periods_per_week];
    backtrack_restrictions_size = 0;
}

int clas::calc_class_spacing() {
    return ceil(num_periods_per_day/clas::get_course_obj()->get_no_of_periods());
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
