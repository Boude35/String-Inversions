
#include <iostream>
#include <fstream>

// FILE: String.cpp
// AUTHOR: Pablo Boudet
// DATE: 04/19/2021
// Definition file for String class


#ifndef _STRING_HPP_
#define _STRING_HPP_

class String
{
private:
	int _ranking; //store the position in the file
	std::string _value;//store string value 
public:
	String() : _ranking(0), _value() {}//simple constructor
	
	//Accesor and modifier for value
	const std::string& value() const {return _value;}
  	std::string& value() {return _value;}

	//Accesor and modifier for ranking
  	const int ranking() const {return _ranking;}
  	int& ranking() {return _ranking;}
  	
  	//reads values form a file to a String
  	std::istream& read (std::istream &is){ getline(is, _value);
  							    return is;}
  							    
   	//overload the >> operator to read from file
  	friend std::istream& operator>> (std::istream &is, String &m){return m.read(is);}

};
#endif
