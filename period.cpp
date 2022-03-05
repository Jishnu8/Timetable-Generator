#include "period.h"

using namespace std;

period::period(int p): preferabilty_score(p){
    period_subject_index = -1;
}

int period::get_preferability_score() const
{
    return preferabilty_score;
    preferabilty_score = 0;
}

period::period(){
    period_subject_index = -1;
}
