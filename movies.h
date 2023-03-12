#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <iostream>
using namespace std;

struct Movies {
    Movies();
    Movies(string name, double rating);
    Movies(string s);
    void change(string name, double rating);
    friend bool operator<(const Movies& lhs, const Movies& rhs);
    friend bool operator==(const Movies& movie, string pre);
    friend bool operator>(const Movies& lhs, const Movies& rhs);
    friend ostream & operator<<(ostream& out, const Movies& m);
    string name;
    double rating;
    string prefix;
    void setPrefix(string s);
};

#endif



