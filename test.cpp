#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class StudClass
{
public:
	int no;
	char *pname;

public:
	StudClass();
	StudClass(int n, char *p);
	virtual ~StudClass();
	void dispaly();
	StudClass& operator = (StudClass &s);
	bool operator >(StudClass &s);

};


bool StudClass::operator >(StudClass &s) {
	if (this->no > s.no)
		return 1;
	else if (this->no < s.no)
		return -1;
	else if (this->no == s.no)
		return 0;

}


StudClass::StudClass() {
	cout << "create\n";
}


StudClass::StudClass(int n, char *p) {
	this->no = n;
	this->pname = new char[10];
	strcpy(pname, p);
	

}


 StudClass::~StudClass() {
	cout << "byebye!!\n";
	if (NULL != pname)
		delete[] pname;

}


void StudClass::dispaly() {
	cout << "no:" << no << "\nname:" << pname << endl;
}


StudClass& StudClass::operator =(StudClass &s) {
	pname = new char[10];
	memset(pname, 0, 10);

	no = s.no;
	strcpy(pname, s.pname);
	return *this;
}









int main(int argc, char** argv)
{
	StudClass s(10,"huang"),t;
	s.dispaly();
	t = s;

	cout << s.pname << " " << t.pname << endl;
	t.dispaly();
	
	system("pause");
	
	return 0;
}
