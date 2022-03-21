#include "teacher.h"
#include "course.h"
#include <iostream>

using namespace std;

teacher::teacher(string nm, course** ca, int size1, int* tr)
                :teacher_name(nm),
                course_array(new course*[size1]),
                teacher_restrictions(new int[sizeof(tr)/sizeof(tr)])
{
    //cout << "subject name: " << ca[1]->get_subject_name() << endl;

    for (int i = 0; i < size1; i++){
        course_array[i] = ca[i];
    }

    for (int i = 0; i < sizeof(tr)/sizeof(tr[0]); i++){
        teacher_restrictions[i] = tr[i];
    }
}

teacher::teacher() : teacher_restrictions(NULL), course_array(NULL) {}

teacher::~teacher(){
    delete[] course_array;
    delete[] teacher_restrictions;
}

string teacher::get_teacher_name() const
{
    return teacher_name;
}

course** teacher::get_course_array() const
{
    return course_array;
}

int* teacher::get_teacher_restrictions() const
{
    return teacher_restrictions;
}
