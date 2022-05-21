#include "teacher.h"
#include "course.h"
#include <iostream>

using namespace std;

teacher::teacher(string nm, course** ca, int size1, int* tr, int tr_size, int num_courses_inp)
                :teacher_name(nm),
                course_array(new course*[size1]),
                teacher_restrictions_size(tr_size),
                num_courses(num_courses_inp)
                //teacher_restrictions(new int[sizeof(tr)/sizeof(tr[0])])
{
    //cout << "subject name: " << ca[1]->get_subject_name() << endl;
//    cout << "hey" << endl;
//    for (int i = 0; i < tr_size; i++){
//        cout << tr[i] << endl;
//    }

    //cout << "Num of courses: " << size1 << endl;
    //cout << ca[1] << endl;
    //ca[0]->print();

    teacher_restrictions = new int[tr_size];
    for (int i = 0; i < size1; i++){
        course_array[i] = ca[i];
        //course_array[i]->print();
        //getchar();
    }
    //cout << "Teacher restrictions: ";
//    for (int i = 0; i < tr_size; i++){
//        teacher_restrictions[i] = tr[i];
//        cout << teacher_restrictions[i] << " ";
//    }
//    cout << endl;

}

teacher::teacher() : teacher_restrictions(NULL), course_array(NULL) {}

//teacher::~teacher(){
//    delete[] course_array;
//    delete[] teacher_restrictions;
//}

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

int teacher::get_num_courses() const{
    return num_courses;
}

void teacher::print() const{
    cout << "Teacher Name: " << teacher_name << endl << endl;
    cout << "Number of courses: " << num_courses << endl;
    for (int i = 0; i < num_courses; i++){
        course_array[i]->print();
    }
    cout << endl;
}
