#pragma once

//#include <iostream>
//#include <fstream>
//#include <string>

#include <bits/stdc++.h>
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

};