#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Movie{
 private:
  string title;
  string genre;
  int year;
  double rating;
  
 public:
  //define and describe:
  //This is a default constructor. it constructs a new instance of the movie class with default values.
  Movie();

  //define and describe:
  //This is a constructor
  Movie(string t, int y, double r, string g);

  //define and describe:
  //This is a copy constructor. This defines how C++ should copy this class
  Movie(const Movie &m);

  //define and describe:
  //This is a destructor. This defines how C++ should delete this class.
  ~Movie() {};

  //define and describe:
  //This is a assignement operator overloader. This defines how C++ should handle situations where we assign one movie class to another.
  Movie& operator=(const Movie &m);

  //define and describe:
  //These are setter functions. These functions help the user write private variables of the class.
  void setTitle(string t) {title = t;};
  void setGenre(string g) {genre = g;};
  void setYear(int y) {year = y;};
  void setRating(double r) {rating = r;};

  //define and describe:
  //These are getter functions. These functions help the programmer access private variables of this class.
  string getTitle() {return title;};
  string getGenre() {return genre;};
  int getYear() {return year;};
  double getRating() {return rating;};
};

#endif