#include "Rome.h"
int c = 2;
rome::rome(int n) {
	if (n < 0) {
		cerr << "Bacasakan Tiv \n";
		return;
	}
	count=length(n);
	int i = 0, patik = 4 * (count - 1),l;
	size = count*4;
	p = new string[size];
	if (count < 1) {
		return;
	}
	else if (count > 3) {
		if (n / 1000 > size) {
			delete[]p;
			size = n / 250;
			p = new string[size];
		}
		foo1(i, n/1000);
		n %= 1000;
	}
	for (int j = 0; j < count; j++) {
		if (patik < 0)break;
		if (n < 10)l = n % 10;
		else  l = n / pow(10, length(n) - 1);
		if (n == 0)break;
		patik = 4 * (length(n) - 1);
		foo(i, patik, l);
		n %= (int)pow(10, length(n) - 1);
	}
}
int rome::length(int a) {
	int i = 0;
	while (a) {
		a /= 10;
		i++;
	}
	return i;
}
void rome::print() {
	for (register int i = 0; i < size; i++)
		cout << p[i];
	cout << endl;
}
rome::~rome() {
	if (p != nullptr)delete[] p;
	else clog << "Isn't Allocated \n";
}

void rome::foo(int &i, int &k, int n) {
	if (n == 0)return;
	switch (n) {
	case 1: {p[i++] = s[k]; break; }
	case 2: {p[i] = p[i + 1] = s[k]; i += 2;  break; }
	case 3: {p[i] = p[i + 1] = p[i + 2] = s[k]; i += 3; break; }
	case 4: {p[i++] = s[k+1]; break; }
	case 5: {p[i++] = s[k+2]; break; }
	case 6: {p[i] = s[k+2]; p[i + 1] = s[k]; i += 2; break; }
	case 7: {p[i] = s[k+2]; p[i + 1] = p[i + 2] = s[k]; i += 3; break; }
	case 8: {p[i] = s[k+2]; p[i + 1] = p[i + 2] = p[i + 3] = s[k]; i += 4; break; }
	case 9: {p[i++] = s[k+3]; break; }
	}
	k -= 4;
}

void rome::foo1(int&i,int cont) {
	for (; cont; cont--)
		p[i++] = s[12];
}