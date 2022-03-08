#ifndef PERIOD_H
#define PERIOD_H

using namespace std;

#include "clas.h"

class period{
    int preferabilty_score;

    public:
    clas* period_subject_list;
    int period_subject_index;
    period(int);
    period();


    int get_preferability_score() const;
};

#endif //PERIOD_H
