#include <iostream>
#include <stdio.h>
#include <string.h>
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

period* timetable = new period[42];
clas* class_array = nullptr;
clas* class_ = nullptr;
int class_index = 0;
int capacity;
int previous_index;
int periods_qty;
course* course_ref = nullptr;
int indices_skipped;
int possibilities[7];
int possibilities_index;
int start_pos;


void construct_class_array() {
    // iterate through course array, create class object, add to the linked list
}

void find_possibilities_in_range(int a, int b, int index) {
    bool full, overlapping, t_restricted, b_restricted;
    for(int i = a; i < b; i++) {
        // check conditions for i
        full = is_full(i);
        overlapping = is_overlapping(i, index);
        t_restricted = is_restricted(i, index, class_array[index].backtrackRestrictions);
        b_restricted = is_restricted(i, index, class_array[index].get_teacher_obj().get_teacher_restrictions());
        if(!full && !overlapping && !t_restricted && !b_restricted) {
            possibilities_index++;
            possibilities[possibilities_index] = i;
        }
    }
}

void backtrack_to_prev_class(clas* curr_class, clas* prev_class) {

    curr_class->backtrack_restrictions_size = 0;
    prev_class->backtrackRestrictions[prev_class->backtrack_restrictions_size++] = prev_class->period_index;
    timetable[prev_class->period_index].period_subject_index--;
    prev_class->period_index = -1;
    // #periods assigned

}

void init() {

    while(1) {
        class_ = &class_array[class_index];
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
            if(--(class_->class_spacing) == 0) {
                if(class_index == 0) { // all possibilities exhausted
                    return;
                }
                backtrack_to_prev_class(class_, class_array[class_index-1]); // function 2


            }
            continue;
        }

    }

}

//
//	if (possibilitiesIndex == -1){
//		//function 2 start
//		classSpacing -= 1
//		if (classSpacing == 0){
//			If classIndex = 0:
//				Return
//
//
//		classarray[classIndex].backtrackRestrcition.empty()
//        classIndex -= 1
//		classarray[classIndex].backtrackRestriction.append(classarray[classIndex].periodIndex)
//		classarray[classIndex].periodIndex = -1
//        timetable[classarray[classIndex].periodindex].subjectlistindex -= 1
//		course_array[classarray[classIndex].courseIndex].noOfPeriodsAssigned -= 1
//		//function 2 end
//		}
//		continue
//    }
//
//	//function 3 start
//    sort(possiblities, 0, possibilitiesIndex) according to preferability
//	//function 3 end
//	//function 4 start
//    int finalPeriods[possibilitiesIndex+1];
//    finalPeriods[0] = possiblities[possiblitiesIndex]
//    For i, possiblitiesIndex - 1->0:
//        If timetable[possibilties[i].preferabilityScore < finalPeriods[0].preferabilityScore:
//            Break
//        finalPeriods.append(i)
//	//function 4 end
//
//	//function 3 start
//    sort(finalPeriods, 0, finalPeriodIndex) according to congestion
//	//function 3 end
//    Int bestIndex = finalPeriods[0]
//
//	//function 5 start
//    put classarray[classIndex] in timetable[bestIndex]
//    classarray[classIndex].periodindex = bestIndex
//    timetable[bestIndex].subjectlistindex += 1
//	course_array[classarray[classIndex].courseIndex].periodAssigned[noOfPeriodsAssigned++] = bestIndex
//	//function 5 end

bool is_full(int period_index) {}
bool is_overlapping(int period_index, int class_index) {}
bool is_restricted(int period_index, int class_index, int* a) {}


int main(){
    cout << "buffalo";
    construct_class_array();
    init();
    return 0;
}
