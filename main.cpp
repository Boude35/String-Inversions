#include "stringArray.hpp"

// FILE: main.cpp
// AUTHOR: Pablo Boudet
// DATE: 04/19/2021
// Definition file for main 


#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
	string myFile;//striing that will store the file name
	string myFile2;//striing that will store the file name of the second file
	
	cout<< "Please Insert the name of your File: ";//ask the user for the name of the file
	cin >> myFile;//ask for the name
	ifstream theReader( myFile.c_str() );//create the reader
	stringArray primero(theReader);//create an StringArray from the file
	
	cout<< "Please Insert the name of your second File: ";//ask the user for the name of the second fil
	cin >> myFile2;//ask for the name
	ifstream theReader2( myFile2.c_str() );//create the reader
	stringArray segundo(theReader2, primero);//create a second StringArray from another file
	
	cout << segundo.result(segundo.filled(), segundo)<<endl;//print the number of inversions
}


