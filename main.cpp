

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
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

string student_names[5][4] = {{"Narendran", "Vibhu", "Jishnu"},
                            {"Shubham", "Auro", "Roshini", "Vibhu"},
                            {"Narendran", "Auro", "Divyanshu"},
                            {"Jishnu", "Roshini", "Harshini"},
                            {"Vibhu", "Narendran"}};

course courses[5] = {course(student_names[0],"CS",4),
                      course(student_names[1],"Sociology",2),
                      course(student_names[2], "Machine Learning", 6),
                      course(student_names[3], "Les Chouchous:)",1),
                      course(student_names[4],"Closet",3)};

course* course1[2] = {&courses[0],&courses[2]};
course* course2[2] = {&courses[1],&courses[3]};
course* course3[1] = {&courses[4]};


int restrictions1[1] = {1};
int r_size = sizeof(restrictions1)/sizeof(restrictions1[0]);

string teacher_names[3] = {"Vijayalakshmi","Avani","Shanti"};
teacher teachers[3] = {teacher(teacher_names[0],course1,2,restrictions1,r_size, 2),
                        teacher(teacher_names[1],course2,2,restrictions1,r_size, 2),
                        teacher(teacher_names[2],course3,1,restrictions1,r_size, 1)};

int num_of_courses;
int num_of_teachers;


int num_periods = 42;
int num_periods_per_day = 7;
period* timetable = new period[num_periods];
//clas* class_array = nullptr;
vector<clas> class_array;

int class_index = 0;
int capacity = 10;
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

bool is_restricted(int period_index, int class_index, int* array_pointer, int r_size);
bool is_full(int period_index);
bool is_overlapping(int period_index, int class_index);
void function7(int best_index);
void print_timetable();

int get_num_of_classes() {

    int num_of_classes = 0;

    for(int i = 0; i < sizeof(courses)/sizeof(courses[0]); i++) {

        num_of_classes += courses[i].get_no_of_periods();

    }

    return num_of_classes;


}

void construct_class_array() {
    // iterate through course array, create class object

    course** teacher_courses = nullptr;
    int num_of_classes = get_num_of_classes();
    int index = 0;

    cout << course1[0]->get_subject_name() << course1[1]->get_subject_name() << endl;

    for(int i = 0; i < sizeof(teachers)/sizeof(teachers[0]); i++) {
        teacher_courses = teachers[i].get_course_array();
        //cout<<"Number of courses with teacher: " << sizeof(teacher_courses)/sizeof(teacher_courses[0]) << endl;
        for(int j = 0; j < teachers[i].get_num_courses(); j++) {
            for(int k = 0; k < teacher_courses[j]->get_no_of_periods(); k++) {
                class_array.push_back(clas(teachers[i], teacher_courses[j]));
            }
        }
    }

    cout << "Class array constructed!\n";

}

void find_possibilities_in_range(int a, int b, int index) {
    bool full, overlapping, t_restricted, b_restricted;
    cout << "Finding possibilities between " << a << " and " << b << endl;
    for(int i = a; i < b; i++) {
        // check conditions for i
        cout << "Checking period " << i << endl;
        full = is_full(i);
        cout << "Full: " << full << endl;
        overlapping = is_overlapping(i, index);
        cout << "Overlapping: " << overlapping << endl;
        b_restricted = is_restricted(i, index, class_array[index].backtrack_restrictions, class_array[index].backtrack_restrictions_size);
        cout << "Is in backtrack restrictions: " << b_restricted << endl;
        t_restricted = is_restricted(i, index, class_array[index].get_teacher_obj().get_teacher_restrictions(), class_array[index].get_teacher_obj().teacher_restrictions_size);
        cout << "Is in teacher restrictions: " << t_restricted << endl;
        if(!full && !overlapping && !t_restricted && !b_restricted) {
            cout << i << " is a possibility\n";
            possibilities[++possibilities_index] = i;
        }
    }
}


void backtrack_to_prev_class(clas* curr_class, clas* prev_class) {

    curr_class->backtrack_restrictions_size = 0;
    prev_class->backtrack_restrictions[prev_class->backtrack_restrictions_size++] = prev_class->period_index;
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

void sort_arr(int* arr, int len, char metric) {
    if(metric == 'p') {
        cout << "Sorting wrt preference\n";
        sort(arr, arr + len, comp_wrt_pref);
        cout << "Sorted wrt preference\n";
    } else {
        if(metric == 'c') {
            cout << "Sorting wrt congestion\n";
            sort(arr, arr + len, comp_wrt_cong);
            cout << "Sorted wrt congestion\n";
        }
    }
}

void fill_most_pref() {

    most_pref[0] = possibilities[possibilities_index];
    most_pref_index = 1;
    float highest_score = timetable[most_pref[0]].get_preferability_score();
    cout << "Possibilities index: " << possibilities_index << endl;
    for(int i = possibilities_index-1; i >= 0; i--) {
        if(timetable[possibilities[i]].get_preferability_score() < highest_score) {
            break;
        }
        cout << "Filling most_pref\n";
        most_pref[most_pref_index++] = possibilities[i];
    }

}

void put_in_timetable(int carray_index, int tt_index) {

    //cout << "TT: " << tt_index << endl;
    //period best_period = timetable[tt_index];
    //cout << "Pref: " << best_period.get_preferability_score() << endl;
    course* course_ = class_array[carray_index].get_course_obj();
    timetable[tt_index].period_subject_index++;
    //error in the following line
    timetable[tt_index].period_subject_list[timetable[tt_index].period_subject_index] = &class_array[carray_index];
    class_array[carray_index].period_index = tt_index;
    (course_->periods_assigned)[course_->no_of_periods_assigned] = tt_index;
    //cout << "Period assigned: " << (course_->periods_assigned)[course_->no_of_periods_assigned] << endl;
    (course_->no_of_periods_assigned)++;
    cout << "Putting " << course_->get_subject_name() << " in period number " << tt_index << endl;
}

void init() {

    while(1) {
        clas* class_ = &class_array[class_index];
        course_ref = class_->get_course_obj(); // a course pointer
        cout << "Course: " << course_ref->get_subject_name() << endl;
        //getchar();
        periods_qty = course_ref->no_of_periods_assigned;
        cout << "Number of periods already assigned: " << periods_qty << endl;
        //getchar();
        if(periods_qty > 0) {
            previous_index = course_ref->periods_assigned[periods_qty-1];
            cout << "Periods_qty = " << periods_qty << ", previous index = " << previous_index << endl;
            indices_skipped = class_->class_spacing*7 - previous_index%7;
        } else {
            previous_index = 0;
            indices_skipped = 0;
        }

        possibilities_index = -1;
        start_pos = previous_index + indices_skipped;
        find_possibilities_in_range(start_pos, start_pos + 7, class_index); // function 1
        cout << "Possibilities found\n";

        if(possibilities_index == -1) {
            if(--(class_->class_spacing) == 0) { // if backtracking's necessary
                if(class_index == 0) { // if all possibilities exhausted
                    cout << "All possibilities exhausted\n";
                    return;
                }
                cout << "Backtracking\n";
                backtrack_to_prev_class(class_, &class_array[class_index-1]); // function 2
                class_index--;
            }
            continue;
        }



        sort_arr(possibilities, possibilities_index+1, 'p'); // function 3
        fill_most_pref(); // function 4 (not good)
        sort_arr(most_pref, most_pref_index, 'c');
        best_index = most_pref[0];
        put_in_timetable(class_index, best_index);
        cout << "End of iteration\n";
        class_index++;

        if(class_index >= class_array.size()) {
            print_timetable();
            class_index--;
            function7(best_index);
            cout << "Going to backtrack\n";
            getchar();
            /*if (classIndex == classArray.length){
		//function 6 start
		output solution
		//function 6 end
		classIndex -= 1
		//function 7 start
		remove classarray[classIndex] in timetable[bestIndex]
		classArray[classIndex].backtrackRestrcition.append(bestIndex)
		classArray[classIndex].periodIndex = -1
		timetable[bestIndex].subjectlistindex -= 1
		course_array[classarray[classIndex].courseIndex].noOfPeriodsAssigned -= 1
		//function 7 end
	}*/

        }

    }
}

bool is_restricted(int period_index, int class_index, int* array_pointer, int r_size) {
    if(array_pointer != nullptr) {
        for (int i = 0; i < r_size; i++) {
            cout << "Class in restrictions: " << array_pointer[i] << endl;
            if (period_index == array_pointer[i]) {
                return true;
            }
        }
    }

    return false;
}

bool is_full(int period_index) {
    if (timetable[period_index].period_subject_index == capacity - 1) {
        return true;
    }
    return false;
}

bool is_overlapping(int period_index, int class_index) {
    clas** period_subject_list = timetable[period_index].period_subject_list;
        cout << "Made it!" << endl;

    for (int i = 0; i <= timetable[period_index].period_subject_index; i++) {

        cout << period_subject_list[i]->get_teacher_obj().get_teacher_name() << endl;
        if (period_subject_list[i]->get_teacher_obj().get_teacher_name() == class_array[class_index].get_teacher_obj().get_teacher_name()) {
            return true;
        }
    }
    string* timetable_student_list = NULL;
    string* clas_student_list = NULL;
    for (int i = 0; i <= timetable[period_index].period_subject_index; i++) {
        timetable_student_list = timetable[period_index].period_subject_list[i]->get_course_obj()->get_student_names();
        for (int j = 0; j < sizeof(timetable_student_list) / sizeof(timetable_student_list[0]); j++) {
            clas_student_list = class_array[class_index].get_course_obj()->get_student_names();
            for (int k = 0; k < sizeof(clas_student_list) / sizeof(clas_student_list[0]); k++) {
                if(timetable[period_index].period_subject_list[i]->get_course_obj()->get_student_names()[j] == class_array[class_index].get_course_obj()->get_student_names()[k]){
                    return true;
                }
            }
        }
    }

    return false;
}

void function7(int best_index){
    timetable[best_index].period_subject_index -= 1;
    cout << "Entered function 7" << endl;
    int* temp = new int[++class_array[class_index].backtrack_restrictions_size];

    cout << "Backtrack size: " << class_array[class_index].backtrack_restrictions_size << endl;
    for(int i = 0; i < class_array[class_index].backtrack_restrictions_size - 1; i++){
        temp[i] = class_array[class_index].backtrack_restrictions[i];
    }
    temp[class_array[class_index].backtrack_restrictions_size-1] = best_index;
    delete class_array[class_index].backtrack_restrictions;
    class_array[class_index].backtrack_restrictions = temp;

    class_array[class_index].period_index = -1;
    timetable[best_index].period_subject_index -= 1;
    cout << "Test1\n";

    class_array[class_index].get_course_obj()->no_of_periods_assigned--;
    cout << "function 7 done\n";
}

void print_timetable(){
    for(int i = 0; i < num_periods; i++){
        cout << "Period " << i+1 << ":\n";
        timetable[i].print_classes();
        cout << "\n";
    }
}


int main(){
    cout << "calculating size outside: " << sizeof(course1)/sizeof(course1[0]) << endl;
    construct_class_array();
    init();
    cout << "buffalo";
    getchar();
    return 0;
}

