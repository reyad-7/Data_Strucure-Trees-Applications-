#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stack>
using namespace std;

struct Student {
    int id;
    string fname;
    string lname;
    float gpa;
    string department;
    Student(){}

    Student(int i, string fn, string ln , float g, string d) : id(i), fname(fn), lname(ln) ,gpa(g), department(d) {}

    void print (){
        cout <<"["<< id << " , " << fname <<lname << " , " << gpa << " , " << department <<"]"<<"\n";
    }

    // this operator for bigger than operator used in heapfy function 
    // to compare nodes with each other so that the array becomes a HEAP 
    bool operator>(const Student& other){
        return gpa > other.gpa;
    }
};
#endif // STUDENT_H
