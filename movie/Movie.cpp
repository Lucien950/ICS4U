  #include "Movie.h"
  using namespace std;
  
  Movie::Movie(){
    title = "";
    year = 0;
    rating = 0.0;
    genre = "";
  }

  Movie::Movie(string t, int y, double r, string g)
  {
    title = t;
    year = y;
    rating = r;
    genre = g;
  }

  Movie::Movie(const Movie &m)
  {
    title = m.title;
    year = m.year;
    rating = m.rating;
    genre = m.genre;
  }

  Movie& Movie::operator=(const Movie &m)
  {
    title = m.title;
    year = m.year;
    rating = m.rating;
    genre = m.genre;

    return *this;
  }