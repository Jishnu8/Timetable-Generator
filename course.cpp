#include "course.h"

using namespace std;

course::course(): student_names(NULL)
{
    no_of_periods_assigned = 0;
    subject_name = "";
};

course::course(string* stu, string sub, int no)
                : student_names(new string[sizeof(stu)/sizeof(stu[0])]), subject_name(sub),
                no_of_periods(no)
{
    for (int i = 0; i < sizeof(stu)/sizeof(stu[0]); i++){
        student_names[i] = stu[i];
    }

    no_of_periods_assigned = 0;
}

course::~course(){
    delete[] student_names;
    delete[] periods_assigned;
}

string* course::get_student_names() const
{
    return student_names;
}

string course::get_subject_name() const
{
    return subject_name;
}

int course::get_no_of_periods() const
{
    return no_of_periods;
}
