#include <iostream>
#include "Movie.h"
#include <fstream>
#include <string>
#include <limits>


using namespace std;

int minIndexRating(Movie * m, int size, int start){
	int minIndex = start;
	double minVal = m[start].getRating();
	for(int i = start; i<size; i++){
		if(m[i].getRating() < minVal){
			minVal = m[i].getRating();
			minIndex = i;
		}
	}
	return minIndex;
}
void printMovie(Movie m){
	cout << m.getTitle() << " " << m.getGenre() << " " << m.getRating() << " " << m.getYear() << endl;
}

int main() {
	const int TOTAL_MOVIES = 250;
	string titles[TOTAL_MOVIES];
	int years[TOTAL_MOVIES];
	double ratings[TOTAL_MOVIES];
	string genres[TOTAL_MOVIES];

	ifstream input;
	input.open("movies.txt");

	int current_index = 0;
	string line = "";

	//reading
	while(getline(input, line) && current_index < TOTAL_MOVIES){
		getline(input, titles[current_index]);
		input >> years[current_index];
		input >> ratings[current_index];
		input >> genres[current_index];
		current_index++;
	}

	Movie movies[TOTAL_MOVIES];
	for(int i = 0; i < TOTAL_MOVIES; i++){
		movies[i] = Movie(titles[i], years[i], ratings[i], genres[i]);
	}

	//BUBBLE SORT
	int lastValue = TOTAL_MOVIES;
	while(lastValue > 0){
		for(int i = 0; i < lastValue-1; i++){
			Movie movie = movies[i];
			Movie nextMovie = movies[i + 1];
			if(movie.getYear() > nextMovie.getYear()){
				movies[i] = nextMovie;
				movies[i + 1] = movie;
			}
		}
		lastValue--;
	}

	for(Movie m: movies){
		cout << "YEAR: " << m.getYear() << " " << m.getTitle() << " " << m.getRating() << " " << m.getGenre() << endl;
	}


	for(int nowIndex = 0; nowIndex < TOTAL_MOVIES; nowIndex++){
		int minIndex = minIndexRating(movies, TOTAL_MOVIES, nowIndex);
		Movie nowMovie = movies[nowIndex];
		movies[nowIndex] = movies[minIndex];
		movies[minIndex] = nowMovie;
	}
	for(Movie m: movies){
		cout << "RATING: " << m.getRating() << " " << m.getYear() << " " << m.getTitle() << " "  << " " << m.getGenre() << endl;
	}

	Movie n4, n5, n6, n7 = movies[0];
	bool n7Found = false;
	for(Movie m: movies){
		if(m.getGenre() == "Comedy" && m.getRating() > n4.getRating()){
			n4 = m;
		}

		if(2000 <= m.getYear() && m.getYear() <= 2005 && m.getRating() > n5.getRating()){
			n5 = m;
		}

		if(m.getGenre() == "Action" && 1990 <= m.getYear() && m.getYear() < 2000 && m.getRating() > n6.getRating()){
			n6 = m;
		}

		if(!n7Found && m.getYear() == 1971){
			n7 = m;
			n7Found = true;
		}
	}

	cout << "highest rated comedy: ";
	printMovie(n4);
	cout << "highest rated movie released between the years 2000-2005 inclusive: ";
	printMovie(n5);
	cout << "highest rated action movie in the 90's: ";
	printMovie(n6);
	cout << "any movie that was released in 1971: ";
	printMovie(n7);

	input.close();
}