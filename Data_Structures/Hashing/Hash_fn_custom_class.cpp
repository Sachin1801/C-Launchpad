#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string r)
    {
        firstname = f;
        lastname = l;
        rollno = r;
    }
    bool operator==(const Student &s) const
    {
        return rollno == s.rollno ? true : false;
    }
};

class Hashfn
{
public:
    size_t operator()(const Student &s) const
    {
        return s.firstname.length() + s.lastname.length(); // returns the enterted string in int value after conversion
    }
};

int main()
{
    unordered_map<Student, int, Hashfn> student_map;
    Student s1("Prateek", "Nßarang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");

    // Add students marks to hashmap
    student_map[s1] = 100;
    student_map[s2] = 99;
    student_map[s3] = 33;
    student_map[s4] = 55;

    // Iterator over the map
    for (auto s : student_map)
    {
        cout << s.first.firstname << "-> " << s.first.rollno << " Marks " << s.second << endl;
    }
    return 0;
}