#include "period.h"

using namespace std;

period::period(int p): preferabilty_score(p){
    period_subject_index = -1;
}

period::period(): preferabilty_score(0), period_subject_list(NULL){
    period_subject_index = -1;
}

period::~period(){
    delete[] period_subject_list;
}

int period::get_preferability_score() const
{
    return preferabilty_score;
}


