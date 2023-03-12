#include "movies.h"
#include <string>

using namespace std;

Movies::Movies() {
    name = "none";
    rating = -1.0;
}

Movies::Movies(string s) {
    int8_t comma = s.find(',');
    name = s.substr(0, comma);
    rating = stod(s.substr(i + 1, s.length() - i - 1)); 
}

Movies::Movies(string name, double rating): name(name), rating(rating) {}

bool operator>(const Movies& lhs, const Movies& rhs) {
    if (lhs.rating > rhs.rating) {
        return true;
    }
    return false;
}



bool operator<(const Movies& lhs, const Movies& rhs) {
    int compare = (lhs.name).compare(rhs.name);
    if (compare < 0) {
        return true;
    }
    return false;
}

void Movies::change(string name, double rating) {
    this->name = name;
    this->rating = rating;
}

ostream & operator<<(ostream& out, const Movies& m) {
    out << m.name << ", " << m.rating << endl;
    return out;
}

void Movies::setPrefix(string s) {
    prefix = s;
}

bool operator==(const Movies& movie,  const Movies& comparison) {
    if ((movie.name).length() < comparison.prefix.length()) {
        return false;
    }
    int8_t size = comparison.prefix.size();
    if ((movie.name).substr(0, size) == comparison.prefix) {
        return true;
    }
    return false;
}



