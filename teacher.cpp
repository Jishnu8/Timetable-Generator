#include "teacher.h"
#include "course.h"
#include "course.cpp"

using namespace std;

teacher::teacher(string nm, course* ca, int* tr)
                :teacher_name(nm), course_array(new course[sizeof(ca)/sizeof(ca[0])]), 
                teacher_restrictions(new int[sizeof(tr)/sizeof(tr)])
{
    for (int i = 0; i < sizeof(ca)/sizeof(ca[0]); i++){
        course_array[i] = course(ca[i].get_student_names(),ca[i].get_subject_name(),
                                ca[i].get_no_of_periods());
    }

    for (int i = 0; i < sizeof(tr)/sizeof(tr[0]); i++){
        teacher_restrictions[i] = tr[i];
    }


}