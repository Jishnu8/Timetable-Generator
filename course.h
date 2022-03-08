#ifndef COURSE_H
#define COURSE_H

using namespace std;

#include <string>

class course{
    string* student_names;
    string subject_name;
    int no_of_periods;
    friend class teacher;
    //int* location_assigned;

    public:
    int* periods_assigned;
    int no_of_periods_assigned;

    course();
    course(string*, string, int);

    string* get_student_names() const;
    string get_subject_name() const;
    int get_no_of_periods() const;
};

#endif //COURSE_H
