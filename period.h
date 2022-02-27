#ifndef PERIOD_H
#define PERIOD_H

using namespace std;

#include "clas.h"

class period{
    int preferabilty_score;

    public:
    clas* period_subject_list; // make into clas array of size 7
    int period_subject_index;
    period();
    period(int);
    ~period();

    int get_preferability_score() const;
};

#endif //PERIOD_H
