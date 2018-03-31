#ifndef ROME_H
#define ROME_h
#include <string>
#include <iostream>
using namespace std;
class rome {
	int count;
	int size;
	string *p;	  // 0	  1	  2	  3    4   5    6   7    8    9  10   11  12
	string s[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int length(int);
	void foo(int&, int&, int);
	void foo1(int&, int);
public:
	rome(int);
	void print();
	~rome();
};
#endif
