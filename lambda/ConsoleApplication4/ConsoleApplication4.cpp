#include "stdafx.h" 
#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;

template<typename T>
auto sum(string devide, T element) -> string
{
	stringstream ss;
	ss << element;
	string t;
	ss >> t;
	return t;
}


template<typename... Args, typename T>
auto sum(string devide, T element, Args... args) -> string
{
	return[devide](T a, string b){
		stringstream ss;
		ss << a;
		ss << devide;
		ss << b;
		string t;
		ss >> t;
		return t;
	}(element, sum(devide, args...));
}


int main()
{
	string begin = ";";
	cout << sum(begin, 1.6, 25, 35, 'c', 3.7, 6, true) << endl;
	system("pause");
}