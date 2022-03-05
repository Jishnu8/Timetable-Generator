#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "teacher.h"
#include "teacher.cpp"
#include "course.h"
#include "course.cpp"
#include "clas.h"
#include "clas.cpp"
#include "period.h"
#include "period.cpp"


using namespace std;


//global variables

course courses[10];

period* timetable = new period[42];
clas* class_array = nullptr;
//clas* class_ = nullptr;
int class_index = 0;
int capacity;
int previous_index;
int periods_qty;
course* course_ref = nullptr;
int indices_skipped;
int possibilities[7];
int most_pref[7];
int possibilities_index;
int most_pref_index;
int start_pos;
int best_index;


void construct_class_array() {
    // iterate through course array, create class object, add to the linked list
    int num_of_classes = 0;
    int index = 0;
    for(int i = 0; i < sizeof(courses); i++) {
        num_of_classes += courses[i].get_no_of_periods();
    }
    class_array = new clas[num_of_classes];
    for(int i = 0; i < sizeof(courses); i++) {
        for(int j = 0; j < courses[i].get_no_of_periods(); j++) {
            class_array[index++] = clas(teacher, &courses[i]);
        }
    }

}

bool is_full(int period_index) {}
bool is_overlapping(int period_index, int class_index) {}
bool is_restricted(int period_index, int class_index, int* a) {}

void find_possibilities_in_range(int a, int b, int index) {
    bool full, overlapping, t_restricted, b_restricted;
    for(int i = a; i < b; i++) {
        // check conditions for i
        full = is_full(i);
        overlapping = is_overlapping(i, index);
        t_restricted = is_restricted(i, index, class_array[index].backtrackRestrictions);
        b_restricted = is_restricted(i, index, class_array[index].get_teacher_obj().get_teacher_restrictions());
        if(!full && !overlapping && !t_restricted && !b_restricted) {
            possibilities[++possibilities_index] = i;
        }
    }
}


void backtrack_to_prev_class(clas* curr_class, clas* prev_class) {

    curr_class->backtrack_restrictions_size = 0;
    prev_class->backtrackRestrictions[prev_class->backtrack_restrictions_size++] = prev_class->period_index;
    timetable[prev_class->period_index].period_subject_index--;
    prev_class->period_index = -1;
    prev_class->get_course_obj()->no_of_periods_assigned--;

}


bool comp_wrt_pref(int a, int b) {
    return (timetable[a].get_preferability_score() < timetable[b].get_preferability_score());
}

bool comp_wrt_cong(int a, int b) {
    return (timetable[a].period_subject_index < timetable[b].period_subject_index);
}

void sort_arr(arr, int len, char metric) {
    if(metric == 'p') {
        sort(arr, arr + len, comp_wrt_pref);
    } else {
        if(metric == 'c') {
            sort(arr, arr + len, comp_wrt_cong);
        }
    }
}

void fill_most_pref() {

    most_pref[0] = possibilities[possibilities_index];
    most_pref_index = 1;
    float highest_score = timetable[most_pref[0]].get_preferability_score();
    for(int i = possibilities_index-1; i >= 0; i--) {
        if(timetable[possibilities[i]].get_preferability_score() < highest_score) {
            break;
        }
        most_pref[most_pref_index++] = possibilities[i];
    }

}

void put_in_timetable(int carray_index, int tt_index) {

    period best_period = timetable[tt_index];
    course* course_ = classarray[carray_index].get_course_obj();
    best_period.period_subject_list[best_period.(++period_subject_index)] = class_array[carray_index];
    class_array[carray_index].period_index = tt_index;
    course_->periods_assigned[course_->(no_of_periods_assigned++)] = tt_index;

}

void init() {

    while(1) {
        clas* class_ = &class_array[class_index];
        course_ref = class_->get_course_obj(); // a course pointer
        periods_qty = course_ref->no_of_periods_assigned;

        if(periods_qty > 0) {
            previous_index = course_ref->periods_assigned[periods_qty-1];
            indices_skipped = class_->class_spacing*7 - previous_index%7;
        } else {
            previous_index = 0;
            indices_skipped = 0;
        }

        possibilities_index = -1;
        start_pos = previous_index + indices_skipped;
        find_possibilities_in_range(start_pos, start_pos + 7, class_index); // function 1

        if(possibilities_index == -1) {
            if(--(class_->class_spacing) == 0) { // if backtracking's necessary
                if(class_index == 0) { // if all possibilities exhausted
                    return;
                }
                backtrack_to_prev_class(class_, &class_array[class_index-1]); // function 2
                class_index--;
            }
            continue;
        }

        sort_arr(possibilities, possibilities_index+1, 'p'); // function 3
        fill_most_pref(); // function 4 (not good)
        sort_arr(most_pref, most_pref_index, 'c');
        best_index = most_pref[0];
        put_in_timetable(class_index, best_index); // function 5


    }

}



int main(){
    cout << "buffalo";
    construct_class_array();
    init();
    return 0;
}
