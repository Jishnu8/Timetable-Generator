#include <iostream>
#include <stdio.h>
#include <string>
#include "course.h"
#include "course.cpp"
#include "teacher.h"
#include "teacher.cpp"

using namespace std;

const int no_of_courses = 100;
const int no_of_students = 100;
const int no_of_teachers = 50;
string student_list[no_of_students] = {"Liam", "Noah", "Oliver", "Elijah", "William", "James", "Benjamin", "Lucas", "Henry", "Alexander", "Mason", "Michael", "Ethan", "Daniel", "Jacob", "Logan", "Jackson", "Levi", "Sebastian", "Mateo", "Jack", "Owen", "Theodore", "Aiden", "Samuel", "Joseph", "John", "David", "Wyatt", "Matthew", "Luke", "Asher", "Carter", "Narendran", "Grayson", "Leo", "Jayden", "Gabriel", "Isaac", "Lincoln", "Anthony", "Hudson", "Dylan", "Ezra", "Thomas", "Charles", "Christopher", "Jaxon", "Maverick", "Josiah", "Isaiah", "Andrew", "Elias", "Joshua", "Nathan", "Caleb", "Ryan", "Adrian", "Miles", "Eli", "Nolan", "Christian", "Aaron", "Cameron", "Ezekiel", "Colton", "Luca", "Landon", "Hunter", "Jonathan", "Santiago", "Axel", "Easton", "Cooper", "Jeremiah", "Angel", "Roman", "Connor", "Jameson", "Robert", "Greyson", "Jordan", "Ian", "Carson", "Jaxson", "Leonardo", "Nicholas", "Dominic", "Austin", "Everett", "Brooks", "Xavier", "Kai", "Jose", "Parker", "Adam", "Jace", "Wesley", "Kayden", "Silas"};
string teacher_list[no_of_teachers] = {"Aaditya", "Aarav", "Ajay", "Akash", "Akhil", "Akshay", "Anand", "Anil", "Ari", "Arian", "Arjun", "Armaan", "Arun", "Aum", "Avi", "Ayaan", "Bodhi", "Daksh", "Dev", "Eshaan", "Ishan", "Jahan", "Jaiden", "Jay", "Jiyan", "Kabir", "Kahan", "Kailash", "Kaiyen", "Kalpen", "Karam", "Karthik", "Kavish", "Kiaan", "Krish", "Kriyan", "Laksh", "Manav", "Milan", "Mivan", "Mohan", "Moksh", "Nayan", "Neeraj", "Nikhil", "Nirmay", "Nishan", "Nitin", "Niyam", "Ohm"};
string list_of_courses[no_of_courses] = {"Androcentrism", "Feminine psychology", "Feminism", "Feminity", "Feminist theory", "Gender dysphoria", "Gender history", "Gender identity", "Gender role", "Gender studies/Gender theory", "Genderqueer", "Gynocentrism", "Heterosexism", "Human sexual behavior", "Human sexuality (outline)", "Intersex", "Masculinity", "Masculism", "Men in feminism", "Men's liberation movement", "Men's movement", "Men's rights movement", "Men's studies", "Misandry", "Misogyny", "Postfeminism", "Postgenderism", "Queer studies/Queer theory", "Sex and gender distinction", "Sex differences in psychology", "Sex education", "Sexism", "Sexology", "Third gender", "Transgender", "Women's rights", "Women's studies", "Canon law", "Church history", "Field ministry", "Pastoral counseling", "Pastoral theology", "Religious education techniques", "Homiletics", "Liturgy", "Sacred music", "Missiology", "Hermeneutics", "Scriptural study and languages", "Biblical Hebrew", "Biblical studies/Sacred scripture", "Vedic Study", "New Testament Greek", "Latin", "Old Church Slavonic", "Theology (outline)", "Dogmatic theology", "Ecclesiology", "Sacramental theology", "Systematic theology", "Christian ethics", "Hindu ethics", "Moral theology", "Historical theology", "Acquired taste", "Aftertaste", "Appetite", "Artisanal food", "Cooking", "Cuisine", "Culinary arts", "Culinary tourism", "Delicacy", "Diet", "Flavor", "Food choice", "Food pairing", "Food photography", "Food preparation", "Food presentation", "Food safety", "Food security", "Food studies", "Gastronomy", "Gourmet", "Palatability", "Specialty foods", "Traditional food", "Blah", "Closet", "Maths", "Physics", "Chemistry", "Biology", "Geology", "French", "English", "CS", "German", "Spanish"};


//class course{
//    string* student_names;
//    string subject_name;
//    int no_of_periods;
//    int no_of_students;
//    friend class teacher;
//    //int* location_assigned;
//
//    public:
//    int* periods_assigned;
//    int no_of_periods_assigned;
//
//    course();
//    course(string*, string, int, int);
//    //~course();
//
//    string* get_student_names() const;
//    string get_subject_name() const;
//    int get_no_of_periods() const;
//    int get_no_of_students() const;
//};

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
        if (size1 == 2 || !is_random ){
            size1 = get_rand(1,3);
            is_random = true;
        }
        else if (size1 == 1 && is_random){
            size1 = 3;
        }
        else if (size1 == 3 && is_random){
            size1 = 1;
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


teacher* create_teacher_obj(Teacher *t){
    teacher* teacher_objs = new teacher[no_of_teachers];
    for (int i = 0; i < no_of_teachers; i++){
        course* course_objs = new course[t[i].no_of_courses];
        for (int j = 0; j < t[i].no_of_courses; j++){
            course_objs[j] = course(t[i].courses[j].student_names, t[i].courses[j].course_name, t[i].courses[j].no_of_periods, t[i].courses[j].no_of_students);
        }
        teacher_objs[i] = teacher(t[i].teacher_name, &course_objs, t[i].no_of_courses, t[i].teacher_restrictions, t[i].tr_size, t[i].no_of_courses);
    }
}

int main(){
    Course* course_list = new Course[no_of_courses];
    Teacher* teacher_list = new Teacher[no_of_teachers];
    assign_course_names(course_list);
    assign_periods(course_list);
    assign_students(course_list);
    assign_courses(teacher_list, course_list);
    assign_restrictions(teacher_list);
    print2(teacher_list);
    return 0;
};
