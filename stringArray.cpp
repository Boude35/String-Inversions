#include "stringArray.hpp"
#include <iostream>

using namespace std;

/*
Creates an StringArray from a file
*/
stringArray::stringArray(ifstream &catalogo)
{
	_filled = 0; // number of actual values in the array
	_size = 1; //variable to update the storage of the array
	_ptr = new String[_size]; //create a new pointer to an array
	catalogo >> _ptr[_filled]; // store the first value
	
  	while(catalogo)//while the file has values
  	{
  		_ptr[_filled].ranking() = _size;//give the ranking by the 
  		if ( _size-1 == _filled)//if the size is not enough add one space
  		{
  			_size = _size+1; //add one space to the array
  			String *_colPtr2 = new String[_size]; // create a temporal array for storing the values
  			for (int i = 0; i <=_filled; i++)
  			{
  				_colPtr2[i] = _ptr[i]; // copy all the values
  			}
  			_ptr = new String[_size]; //reinizialization with the size updated
  			for (int i = 0; i <= _filled; i++)
  			{
  				_ptr[i] = _colPtr2[i]; // copy the values back
  			}
  		}
  		_filled++;//update the size
  		catalogo >>_ptr[_filled];//next values
  
  	}

}

/*
Creates an StringArray from a file and give the values of the ranking according to the ranking of the same value in the parameter stringArray
*/
stringArray::stringArray(ifstream &archivo, const stringArray &first)
{
	_filled = 0; // number of actual values in the array
	_size = 1; //variable to update the storage of the array
	_ptr = new String[_size]; //create a new pointer to an array
	archivo >> _ptr[_filled]; // store the first value
	
  	while(archivo)//while the file has values
  	{
  		if ( _size-1 <= _filled)//if the size is not enough add one space
  		{
  			_size = _size + 1; // duplicate the size
  			String *_colPtr2 = new String[_size]; // create a temporal array for storing the values
  			for (int i = 0; i <=_filled; i++)
  			{
  				_colPtr2[i] = _ptr[i]; // copy all the values
  			}
  			_ptr = new String[_size]; //reinizialization with the size updated
  			for (int i = 0; i <= _filled; i++)
  			{
  				_ptr[i] = _colPtr2[i]; // copy the values back
  			}
  		}
		
		//loop the parameter String array to find the same value and give the same ranking value to the String that is being readed
  		for(int i = 0; i < first._filled; i++)//loop the parameter StringArray
  		{
  			if(first._ptr[i].value() == _ptr[_filled].value())//if the Variable value is equal
  				_ptr[_filled].ranking() = first._ptr[i].ranking();//give the ranking value
  		}
  		_filled++;//update the size
  		archivo >>_ptr[_filled];//read next values
  
  	}

}

//function that sort the array and return inversions
int
stringArray::dicon(stringArray arr, int left, int right, stringArray pasa)
{
	//inizializate the value that will represent the index of the middle and the number of inversions
	int midd, inversions = 0;
	//if the index of the right is bigger
	if(right > left)
	{
		//fins de index of the middle
		midd = (right + left)/2;
		
		//recursive call for both parts of the array
		inversions += dicon(arr, left, midd, pasa);
		inversions += dicon(arr, midd+1, right,pasa);
		
		//merge the arrays and count the inversions
		inversions += merge(arr, left, right, midd + 1, pasa);
	}
	//return the number of inversions
	return inversions;
}

//Merges the arrays and return the inversions inside of it
int
stringArray::merge(stringArray arr, int left, int right, int midd, stringArray pasa)
{
	int i,j,k;//inizializate the variables
	int inv = 0;//inizializate what will store the number of inversion 
	
	i = left;//index for the left divided array
	j = midd;//index for the right divided array
	k = left;//index for the result divided array
	
	//loop while through the right and left index
	while(i <= midd - 1 && j <= right)
	{
		//if the there is no need for inversion
		if(arr._ptr[i].ranking() <= arr._ptr[j].ranking())
			pasa._ptr[k++].ranking() = arr._ptr[i++].ranking();//add it to the final array
		else//otherway
		{
			//invert the values
			pasa._ptr[k++].ranking() = arr._ptr[j++].ranking();
			inv = inv + (midd-i);//update the inversions with (midd-1) because they are sorted arrays
		}
	}
	//copy remaining values of left subarray
	while(i<= midd - 1) 
		pasa._ptr[k++].ranking() = arr._ptr[i++].ranking();
	
	//copy remaining values of right subarray if there are any(just for sanity)
	while(j<= right)
		pasa._ptr[k++].ranking() = arr._ptr[j++].ranking();
	
	//copy the sorted values back in the original
	for(int i = left; i <= right; i++)
		arr._ptr[i].ranking() = pasa._ptr[i].ranking();
	
	return inv; //return the number of inversions
}

//auxiliary function to inizializate dicon
int 
stringArray::result(int array_size, stringArray arr)
{
    stringArray temp(array_size);//inizializate the auxiliar function
    return dicon(arr, 0, array_size-1, temp); //call the dicon function
}





