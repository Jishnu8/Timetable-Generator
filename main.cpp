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
//#include "data_gen.h"
//#include "data_gen.cpp"

//Program running on Linux machine in CompLab, but not working on Jis Windows laptop.
//This is very strange and even troubling. Disturbing thoughts at night haunt me.
//Will the future of computers change? Unlike and yet a possibility.
//Help :(
//Update. A disturbing truth revealed. The program on Naren's horrible, archaic windows laptop/
//What has my life come to?
//Life has changed. Program failed to run on Vibhu's laptop. Halleluah!
//Conclusion: THe shittier the laptop, the better it is for the program :)

//I don't know what to write. This is a serious matter. Is this life? Is this what it has come down to?
//Labyrinthing the inconsistencies of C++, I torture myself. We are the good guys :( Aren't we? :)
//NNNNNNOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

using namespace std;
int no_of_solutions_found = 0;



//global variables

//int period_list[90] =

using namespace std;

const int no_of_courses = 100;
const int no_of_students = 100;
const int no_of_teachers = 50;
string student_list[no_of_students] = {"Liam", "Noah", "Oliver", "Elijah", "William", "James", "Benjamin", "Lucas", "Henry", "Alexander", "Mason", "Michael", "Ethan", "Daniel", "Jacob", "Logan", "Jackson", "Levi", "Sebastian", "Mateo", "Jack", "Owen", "Theodore", "Aiden", "Samuel", "Joseph", "John", "David", "Wyatt", "Matthew", "Luke", "Asher", "Carter", "Narendran", "Grayson", "Leo", "Jayden", "Gabriel", "Isaac", "Lincoln", "Anthony", "Hudson", "Dylan", "Ezra", "Thomas", "Charles", "Christopher", "Jaxon", "Maverick", "Josiah", "Isaiah", "Andrew", "Elias", "Joshua", "Nathan", "Caleb", "Ryan", "Adrian", "Miles", "Eli", "Nolan", "Christian", "Aaron", "Cameron", "Ezekiel", "Colton", "Luca", "Landon", "Hunter", "Jonathan", "Santiago", "Axel", "Easton", "Cooper", "Jeremiah", "Angel", "Roman", "Connor", "Jameson", "Robert", "Greyson", "Jordan", "Ian", "Carson", "Jaxson", "Leonardo", "Nicholas", "Dominic", "Austin", "Everett", "Brooks", "Xavier", "Kai", "Jose", "Parker", "Adam", "Jace", "Wesley", "Kayden", "Silas"};
string teacher_list[no_of_teachers] = {"Aaditya", "Aarav", "Ajay", "Akash", "Akhil", "Akshay", "Anand", "Anil", "Ari", "Arian", "Arjun", "Armaan", "Arun", "Aum", "Avi", "Ayaan", "Bodhi", "Daksh", "Dev", "Eshaan", "Ishan", "Jahan", "Jaiden", "Jay", "Jiyan", "Kabir", "Kahan", "Kailash", "Kaiyen", "Kalpen", "Karam", "Karthik", "Kavish", "Kiaan", "Krish", "Kriyan", "Laksh", "Manav", "Milan", "Mivan", "Mohan", "Moksh", "Nayan", "Neeraj", "Nikhil", "Nirmay", "Nishan", "Nitin", "Niyam", "Ohm"};
string list_of_courses[no_of_courses] = {"Androcentrism", "Feminine psychology", "Feminism", "Feminity", "Feminist theory", "Gender dysphoria", "Gender history", "Gender identity", "Gender role", "Gender studies/Gender theory", "Genderqueer", "Gynocentrism", "Heterosexism", "Human sexual behavior", "Human sexuality (outline)", "Intersex", "Masculinity", "Masculism", "Men in feminism", "Men's liberation movement", "Men's movement", "Men's rights movement", "Men's studies", "Misandry", "Misogyny", "Postfeminism", "Postgenderism", "Queer studies/Queer theory", "Sex and gender distinction", "Sex differences in psychology", "Sex education", "Sexism", "Sexology", "Third gender", "Transgender", "Women's rights", "Women's studies", "Canon law", "Church history", "Field ministry", "Pastoral counseling", "Pastoral theology", "Religious education techniques", "Homiletics", "Liturgy", "Sacred music", "Missiology", "Hermeneutics", "Scriptural study and languages", "Biblical Hebrew", "Biblical studies/Sacred scripture", "Vedic Study", "New Testament Greek", "Latin", "Old Church Slavonic", "Theology (outline)", "Dogmatic theology", "Ecclesiology", "Sacramental theology", "Systematic theology", "Christian ethics", "Hindu ethics", "Moral theology", "Historical theology", "Acquired taste", "Aftertaste", "Appetite", "Artisanal food", "Cooking", "Cuisine", "Culinary arts", "Culinary tourism", "Delicacy", "Diet", "Flavor", "Food choice", "Food pairing", "Food photography", "Food preparation", "Food presentation", "Food safety", "Food security", "Food studies", "Gastronomy", "Gourmet", "Palatability", "Specialty foods", "Traditional food", "Blah", "Closet", "Maths", "Physics", "Chemistry", "Biology", "Geology", "French", "English", "CS", "German", "Spanish"};

struct Course{
    string course_name;
    int no_of_periods;
    string* student_names;
    int no_of_students;
};

struct Teacher{
    string teacher_name;
    int no_of_courses;
    Course* courses;
    int* teacher_restrictions;
    int tr_size;
};

int get_rand(int a,int b){
    return a + (std::rand() % b);
}

void assign_course_names(Course *c){
    for (int i=0; i < no_of_courses; i++){
        c[i].course_name = list_of_courses[i];
    }
}

void assign_periods(Course* c){
    for (int i=0; i < no_of_courses; i++){
        c[i].no_of_periods = get_rand(1,6);
    }
}

void assign_courses(Teacher* t, Course* c){
    int size1 = 2;
    int k = 0;
    bool is_random = true;
    for (int i = 0; i < no_of_teachers; i++){
        t[i].teacher_name = teacher_list[i];
        if (size1 == 2 || !is_random){
            size1 = get_rand(1,3);
            is_random = true;
        }
        else if (size1 == 1 && is_random){
            size1 = 3;
            is_random = false;
        }
        else if (size1 == 3 && is_random){
            size1 = 1;
            is_random = false;
        }
        else {
            size1 = get_rand(1,3);
        }

        t[i].no_of_courses = size1;
        t[i].courses = new Course[size1];
        for (int j = 0; j < size1; j++){
            t[i].courses[j] = c[k + j];
        }
        k += size1;
    }
}

void assign_restrictions(Teacher *t){
    int a;
    for (int i = 0; i < no_of_teachers; i++){
        t[i].tr_size = get_rand(1,10);
        t[i].teacher_restrictions = new int[t[i].tr_size];
        for (int j = 0; j < t[i].tr_size; j++){
            a = get_rand(1,42);
            for (int k = 0; k < j; k++){
                if (t[i].teacher_restrictions[k] == a){
                    a = get_rand(1,42);
                    k = 0;
                }
            }
            t[i].teacher_restrictions[j] = a;
        }
    }
}

void assign_students(Course* c){
    int j = 0;
    for (int i = 0; i < no_of_courses; i++){
        int size1 = get_rand(1,8);
        if (j + size1 >= no_of_students){
            size1 = no_of_students - 1 - j;
        }
        c[i].no_of_students = size1;
        c[i].student_names = new string[size1];
        for (int k = j; k < j + size1; k++){
            c[i].student_names[k - j] = student_list[k];
        }

        j += size1;
        if (j == no_of_students - 1){
            j = 0;
        }
    }
}

void print(Course c){
    cout << "Course: " << c.course_name << endl;
    cout << "Periods: " << c.no_of_periods << endl;
    cout << "Students: ";
    for (int j = 0; j < c.no_of_students; j++){
        cout << c.student_names[j] << ", ";
    }
    cout << endl;
}

void print2(Teacher *t){
    for (int k = 0; k < no_of_teachers; k++){
        cout << "Teacher: " << t[k].teacher_name << endl;
        for (int i = 0; i < t[k].no_of_courses; i++){
            print(t[k].courses[i]);
        }
        //cout << endl;
        cout << "Restrictions: ";
        for (int j = 0; j < t[k].tr_size; j++){
            cout << t[k].teacher_restrictions[j] << ", ";
        }
        cout << endl << endl;
    }
}


teacher* create_teacher_obj(Teacher* t){
    teacher* teacher_objs = new teacher[no_of_teachers];
    for (int i = 0; i < no_of_teachers; i++){
        course** course_objs = new course*[t[i].no_of_courses];
        //course *course_objs[t[i].no_of_courses];
        for (int j = 0; j < t[i].no_of_courses; j++){
            course temp = course(t[i].courses[j].student_names, t[i].courses[j].course_name, t[i].courses[j].no_of_periods, t[i].courses[j].no_of_students);
            course_objs[j] = &temp;
            course_objs[j]->print();
            getchar();
        }
        cout << course_objs[1] << endl;
        //cout << t[i].teacher_name << endl;
        //cout << t[i].no_of_courses << endl;
        //cout << t[i].teacher_restrictions << endl << t[i].tr_size << endl;
        course **blah;
        blah = course_objs;
        teacher_objs[i] = teacher(t[i].teacher_name, blah, t[i].no_of_courses, t[i].teacher_restrictions, t[i].tr_size, t[i].no_of_courses);
        //teacher_objs[i].print();
        //getchar();
    }
    return teacher_objs;
}


teacher* return_teacher_obj(){
    Course* course_list = new Course[no_of_courses];
    Teacher* teacher_list = new Teacher[no_of_teachers];
    assign_course_names(course_list);
    assign_periods(course_list);
    assign_students(course_list);
    assign_courses(teacher_list, course_list);
    assign_restrictions(teacher_list);
    print2(teacher_list);
    teacher* ab = create_teacher_obj(teacher_list);
    return ab;
}


string student_names[5][4] = {{"Narendran", "Vibhu", "Jishnu"},
                            {"Shubham", "Auro", "Roshini", "Vibhu"},
                            {"Narendran", "Auro", "Divyanshu"},
                            {"Jishnu", "Roshini", "Harshini"},
                            {"Vibhu", "Narendran"}};

course courses[5] = {course(student_names[0],"CS",4, 3),
                      course(student_names[1],"Sociology",2, 4),
                      course(student_names[2], "Machine Learning", 6, 3),
                      course(student_names[3], "Les Chouchous:)",1, 3),
                      course(student_names[4],"Closet",3, 2)};

course* course1[2] = {&courses[0],&courses[2]};
course* course2[2] = {&courses[1],&courses[3]};
course* course3[1] = {&courses[4]};


int restrictions1[1] = {1};
int r_size = sizeof(restrictions1)/sizeof(restrictions1[0]);

string teacher_names[3] = {"Vijayalakshmi","Avani","Shanti"};
//teacher teachers[3] = {teacher(teacher_names[0],course1,2,restrictions1,r_size, 2),
//                        teacher(teacher_names[1],course2,2,restrictions1,r_size, 2),
//                        teacher(teacher_names[2],course3,1,restrictions1,r_size, 1)};

teacher* teachers;

int num_of_courses;
int num_of_teachers;


int const num_periods = 42;
int const num_periods_per_day2 = 7;

int clas::num_periods_per_day = num_periods_per_day2;
int clas::num_periods_per_week = num_periods;

period* timetable = new period[num_periods];
//clas* class_array = nullptr;
vector<clas> class_array;

int class_index = 0;
int capacity = 10;
int previous_index;
int periods_qty;
course* course_ref = nullptr;
int indices_skipped;
int possibilities[num_periods_per_day2];
int most_pref[num_periods_per_day2];
int possibilities_index;
int most_pref_index;
int start_pos;
int best_index;

bool is_restricted(int period_index, int class_index, int* array_pointer, int r_size);
bool is_full(int period_index);
bool is_overlapping(int period_index, int class_index);
void function7(int best_index);
void print_timetable();
void is_within_class_spacing(int period_index, int class_index, int spacing);

int get_num_of_classes() {

    int num_of_classes = 0;

    for(int i = 0; i < sizeof(courses)/sizeof(courses[0]); i++) {

        num_of_classes += courses[i].get_no_of_periods();

    }

    return num_of_classes;


}

void construct_class_array() {
    // iterate through course array, create class object
    cout << "test 1";
    course** teacher_courses = nullptr;
    int num_of_classes = get_num_of_classes();
    int index = 0;

    //cout << course1[0]->get_subject_name() << course1[1]->get_subject_name() << endl;

    for(int i = 0; i < no_of_teachers; i++) {
        //cout << "heyi" << endl;
        teacher_courses = teachers[i].get_course_array();
        //cout<<"Number of courses with teacher: " << sizeof(teacher_courses)/sizeof(teacher_courses[0]) << endl;
        for(int j = 0; j < teachers[i].get_num_courses(); j++) {
            for(int k = 0; k < teacher_courses[j]->get_no_of_periods(); k++) {
                class_array.push_back(clas(teachers[i], teacher_courses[j]));
            }
        }
    }

    cout << "test 2" << endl;

    //cout << "Class array constructed!\n";

}

void find_possibilities_in_range(int a, int b, int index) {
    bool full, overlapping, t_restricted, b_restricted, spaced;
    //cout << "Finding possibilities between " << a << " and " << b << endl;
    for(int i = a; i < b; i++) {
        // check conditions for i
        //cout << "Checking period " << i << endl;
        full = is_full(i);
        //cout << "Full: " << full << endl;
        overlapping = is_overlapping(i, index);
        //cout << "Overlapping: " << overlapping << endl;
        b_restricted = is_restricted(i, index, class_array[index].backtrack_restrictions, class_array[index].backtrack_restrictions_size);
        //cout << "Is in backtrack restrictions: " << b_restricted << endl;
        t_restricted = is_restricted(i, index, class_array[index].get_teacher_obj().get_teacher_restrictions(), class_array[index].get_teacher_obj().teacher_restrictions_size);
        //cout << "Is in teacher restrictions: " << t_restricted << endl;
        //spaced = is_within_class_spacing(i, index, spacing);
        if(!full && !overlapping && !t_restricted && !b_restricted) {
            //cout << i << " is a possibility\n";
            possibilities[++possibilities_index] = i;
        }
    }
}


void backtrack_to_prev_class(clas* curr_class, clas* prev_class) {
    //cout<<"1";
    curr_class->backtrack_restrictions_size = 0;
    curr_class->class_spacing = curr_class->calc_class_spacing();
    //cout << "Class spacing now: " << curr_class->class_spacing << endl;
    //getchar();
    //cout<<"2";
    prev_class->backtrack_restrictions[prev_class->backtrack_restrictions_size++] = prev_class->period_index;
    //cout<<"3";
    timetable[prev_class->period_index].period_subject_index--;
//    timetable[curr_class->period_index].period_subject_index--; naren's change
    //cout<<"4";
    prev_class->period_index = -1;
    //cout<<"5";
    prev_class->get_course_obj()->no_of_periods_assigned--;
    //cout<<"6";
    // reset class spacing





}


bool comp_wrt_pref(int a, int b) {
    return (timetable[a].get_preferability_score() < timetable[b].get_preferability_score());
}

bool comp_wrt_cong(int a, int b) {
    return (timetable[a].period_subject_index < timetable[b].period_subject_index);
}

void sort_arr(int* arr, int len, char metric) {
    if(metric == 'p') {
        //cout << "Sorting wrt preference\n";
        sort(arr, arr + len, comp_wrt_pref);
        //cout << "Sorted wrt preference\n";
    } else {
        if(metric == 'c') {
            //cout << "Sorting wrt congestion\n";
            sort(arr, arr + len, comp_wrt_cong);
            //cout << "Sorted wrt congestion\n";
        }
    }
}

void fill_most_pref() {

    most_pref[0] = possibilities[possibilities_index];
    most_pref_index = 1;
    float highest_score = timetable[most_pref[0]].get_preferability_score();
    //cout << "Possibilities index: " << possibilities_index << endl;
    for(int i = possibilities_index-1; i >= 0; i--) {
        if(timetable[possibilities[i]].get_preferability_score() < highest_score) {
            break;
        }
        //cout << "Filling most_pref\n";
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
    //timetable[tt_index].print_classes(); //vibhu is guilty of this.

    class_array[carray_index].period_index = tt_index;
    (course_->periods_assigned)[course_->no_of_periods_assigned] = tt_index;
    //cout << "Period assigned: " << (course_->periods_assigned)[course_->no_of_periods_assigned] << endl;
    (course_->no_of_periods_assigned)++;
    //cout << "Putting " << course_->get_subject_name() << " in period number " << tt_index << endl;
}

void init() {

    while(1) {
        //cout << "ihie" << endl;
        clas* class_ = &class_array[class_index];
        course_ref = class_->get_course_obj(); // a course pointer
        //cout << "Course: " << course_ref->get_subject_name() << endl;
        //getchar();
        periods_qty = course_ref->no_of_periods_assigned;
        //cout << "Number of periods already assigned: " << periods_qty << endl;
        //getchar();
        if(periods_qty > 0) {
            previous_index = course_ref->periods_assigned[periods_qty-1];
            //cout << "Periods_qty = " << periods_qty << ", previous index = " << previous_index << endl;
            indices_skipped = class_->class_spacing*num_periods_per_day2 - previous_index%num_periods_per_day2;
        } else {
            previous_index = 0;
            indices_skipped = 0;
        }

        possibilities_index = -1;
        start_pos = previous_index + indices_skipped;
        find_possibilities_in_range(start_pos, start_pos + num_periods_per_day2, class_index); // function 1
        //find_possibilities_in_range(0, 41, class_index, class_->class_spacing);
        //cout << "Possibilities found\n";

        if(possibilities_index == -1) {
            if(--(class_->class_spacing) == 0) { // if backtracking's necessary
                //cout << "Class spacing is zero\n";
                if(class_index == 0) { // if all possibilities exhausted
                    cout << "All possibilities exhausted\n";
                    return;
                }
                //cout << "Backtracking\n";
                backtrack_to_prev_class(class_, &class_array[class_index-1]); // function 2
                //cout << "Backtracking successful\n";
                class_index--;
            }
            continue;
        }


        sort_arr(possibilities, possibilities_index+1, 'p'); // function 3
        fill_most_pref(); // function 4 (not good)
        sort_arr(most_pref, most_pref_index, 'c');
        best_index = most_pref[0];

        put_in_timetable(class_index, best_index); //problem found

        //cout << "End of iteration\n";
        class_index++;
        //cout << class_index << endl;
        if(class_index >= class_array.size()) {
            cout << "No of solutions: " << ++no_of_solutions_found<<endl;
            //print_timetable();
            getchar();
            class_index--;
            function7(best_index);
            //cout << "Going to backtrack\n";
           // getchar();
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
            //cout << "Class in restrictions: " << array_pointer[i] << endl;
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
//
//
//bool is_within_class_spacing(int period_index, int class_index, int spacing) {
//    for(int i = 0; i < class_array[class_index].get_course_obj()->no_of_periods_assigned; i++){
//        if(abs(int(class_array[class_index].get_course_obj()->periods_assigned[i] / 7) - int(period_index % 7)) >= class_array[class_index].class_spacing){
//            return false;
//        }
//    }
//    return true;
//}

bool is_overlapping(int period_index, int class_index) {
    clas** period_subject_list = timetable[period_index].period_subject_list;
        //cout << "Made it!" << endl;

    for (int i = 0; i <= timetable[period_index].period_subject_index; i++) {

        //cout << period_subject_list[i]->get_teacher_obj().get_teacher_name() << endl;
        if (period_subject_list[i]->get_teacher_obj().get_teacher_name() == class_array[class_index].get_teacher_obj().get_teacher_name()) {
            return true;
        }
    }
    string* timetable_student_list = NULL;
    string* clas_student_list = NULL;
    for (int i = 0; i <= timetable[period_index].period_subject_index; i++) {
        for (int j = 0; j < timetable[period_index].period_subject_list[i]->get_course_obj()->get_no_of_students(); j++) {
            for (int k = 0; k < class_array[class_index].get_course_obj()->get_no_of_students(); k++) {
                if(timetable[period_index].period_subject_list[i]->get_course_obj()->get_student_names()[j] == class_array[class_index].get_course_obj()->get_student_names()[k]){
                    return true;
                }
            }
        }
    }
    return false;
}

void function7(int best_index){

    //cout << "Entered function 7" << endl;
    //cout << "Best index: " << best_index << endl;
    /*int* temp = new int[++class_array[class_index].backtrack_restrictions_size];

    cout << "Backtrack size: " << class_array[class_index].backtrack_restrictions_size << endl;
    for(int i = 0; i < class_array[class_index].backtrack_restrictions_size - 1; i++){
        temp[i] = class_array[class_index].backtrack_restrictions[i];
    }
    temp[class_array[class_index].backtrack_restrictions_size-1] = best_index;
    delete class_array[class_index].backtrack_restrictions;
    class_array[class_index].backtrack_restrictions = temp;*/

    class_array[class_index].backtrack_restrictions[class_array[class_index].backtrack_restrictions_size++] = best_index;


    class_array[class_index].period_index = -1;
    timetable[best_index].period_subject_index --;
    //cout << "Test1\n";

    class_array[class_index].get_course_obj()->no_of_periods_assigned--;
    //cout << "function 7 done\n";
    //getchar();
}

void print_timetable(){
    for(int i = 0; i < num_periods; i++){
        cout << "Period " << i+1 << ":\n";
        timetable[i].print_classes();
        cout << "\n";
    }
}


int main(){
    teachers = return_teacher_obj();
    for (int i = 0; i < no_of_teachers; i++){
        teachers[i].print();
    }
    cout << "size: " << float(sizeof(teachers))/float(sizeof(teachers[0]));
    cout << "hi";
    construct_class_array();
    init();
    cout << "buffalo" << endl;
    getchar();
    return 0;
}

