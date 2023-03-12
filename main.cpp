// Spring'22
// Instructor: Diba Mirza
// Student name: Sungchae Park
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <utility>
#include <set>
#include <queue>
#include "movies.h"
#include <functional>
using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);
bool compare(const Movies& lhs, const Movies& rhs);


int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
  // Create an object of a STL data-structure to store all the movies
  set<Movies> s;


  string line, movieName;
  double movieRating;
  cout << "P" << endl;
  // Read each file and store the name and rating
  int8_t i;
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    Movies addMovie(movieName,movieRating);
    s.insert(addMovie);
        // Use std::string movieName and double movieRating
        // to construct your Movie objects
        // cout << movieName << " has rating " << movieRating << endl;
        // insert elements into your data structure 
  }

  movieFile.close();
  cout << "P" << endl;

  if (argc == 2){
        if (!s.empty()) {
            set<Movies>::iterator j =  s.begin();
            while (j != s.end()) {
                cout << (*j);
                j++;
            }
        }
        //print all the movies in ascending alphabetical order of movie names
        return 0;
  }



  //  For each prefix,
  //  Find all movies that have that prefix and store them in an appropriate data structure
  //  If no movie with that prefix exists print the following message
  int8_t m = argc - 2;
  set<Movies> filter;
  set<Movies, greater<Movies>> filterInt;
  set<Movies>::iterator k;
  queue<Movies> maxRating;
  string prefix;
  Movies findMovie;
  for (int8_t v = 2; v < m; ++v) {
    prefix = argv[v];
    findMovie.setPrefix(prefix);
    k = s.find(findMovie);
    queue<Movies> ratingMax;
    while (k != s.end()) {
      filter.insert(*k);
      filterInt.insert(*k);
      s.erase(*k);
      k = s.find(findMovie);
    }
    if (filter.empty()) {
        Movies a;
        maxRating.push(a);
    }
    else {
        set<Movies>::iterator y = filter.begin();
        while (y != filter.end()) {
            cout << *y;
            s.insert(*y);
            ++y;
        }
        Movies max = *(filterInt.begin());
        max.prefix = prefix;
        maxRating.push(max);
        filter.clear();
    }
  }
  Movies p;
  while (!maxRating.empty()) {
    p = maxRating.front();
    if (p.rating < 0) {
        cout << "No movies found with prefix" << p.prefix << endl << endl;
    }
    else {
        cout << "Best movie with prefix" << p.prefix << " is: " << p.name << " with rating " << fixed << setprecision(1) << p.rating << endl;
    }
    maxRating.pop();
  }




  //  For each prefix,
  //  Print the highest rated movie with that prefix if it exists.

  return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    if (line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++){
        if(flag) tempRating += line[i];
        else if(line[i]==','&& line[0]!='"') flag = true;
        else {
            if(i==0 && line[0]=='"') continue;
            if(line[i]=='"'){ i++; flag=true; continue;}
            movieName += line[i];
        }
    }
    
    movieRating = stod(tempRating);
    return true;
}

bool compare(const Movies& lhs, const Movies& rhs) {
    if (lhs.rating > rhs.rating) {
        return true;
    }
    return false;
}