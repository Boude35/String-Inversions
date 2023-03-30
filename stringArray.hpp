#include "String.hpp"
#include <iostream>
#include <fstream>

// FILE: StringArray.cpp
// AUTHOR: Pablo Boudet
// DATE: 04/19/2021
// Definition file for StringArray


#ifndef _STRING_ARRAY_HPP_
#define _STRING_ARRAY_HPP_

using namespace std;

class stringArray
{
private:
	String *_ptr; //pointer to a String 
	int _size; //auxiliar variable to add space to the array
	int _filled; //size of the array
	
public:
	stringArray(int size): _size(size), _filled(size - 1) {_ptr = new String[_size];}//basic constructor 
	stringArray(ifstream &archivo);//Constructor from a file
	stringArray(ifstream &archivo, const stringArray &first);//Constructor from a file an another StringArray
	
	//accesor and Modifier for filled
	const int filled() const {return _filled;}
  	int& filled() {return _filled;}
  	
  	//function that sort the array and return inversions
	int dicon(stringArray arr, int left, int right, stringArray pasa);
	//Merges the arrays and return the inversions inside of it
	int merge(stringArray arr, int left, int right, int midd, stringArray pasa);
	//auxiliary function to inizializate dicon
	int result(int size, stringArray arr);

};
#endif
