#include <iostream>
#include <cstdlib>
#include "Exception.h"
#include "SmartPointer.h"
#include "StaticList.h"

using namespace std;
using namespace mylib;

int main()
{
	StaticList<int,10> l;
	for (int i=0; i < l.capcity(); i++)
	{
		l.insert(0, i);
	};
	for (int i=0; i < l.capcity(); i++)
	{
		cout << l[i] << endl;
	}
	cout << "__________________" << endl;
	cout << "m_length=" << l.length() << endl;
	for (int i = 0; i < l.capcity(); i++)
	{
		l.set(i,i);
	};
	for (int i = 0; i < l.capcity(); i++)
	{
		cout << l[i] << endl;
	}
	cout << "__________________" << endl;
	l.remove(5);
	cout << "m_length=" << l.length() << endl;
	l.remove(6);
	cout << "m_length=" << l.length() << endl;
	bool ret=l.remove(9);
	cout << "ret=" <<ret <<endl;
	for (int i = 0; i < l.capcity(); i++)
	{
		cout << l[i] << endl;
	}
	cout << "__________________" << endl;
	cout << "m_length=" << l.length() << endl;

	return 0;
}