#include "period.h"

using namespace std;

period::period(int p): preferabilty_score(p){
    period_subject_index = -1;
}

period::period(): preferabilty_score(0){

    period_subject_list = new clas*[10];
    period_subject_index = -1;
}

period::~period(){
    delete[] period_subject_list;
}

int period::get_preferability_score() const
{
    return preferabilty_score;
}

void period::print_classes(){
    for(int i = 0; i <= period_subject_index; i++){
        cout << period_subject_list[i]->get_course_obj()->get_subject_name() << ":" << period_subject_list[i]->get_teacher_obj().get_teacher_name() << endl;
    }
}

int period::max_class = 10;

