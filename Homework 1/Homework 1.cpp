// Homework 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TimeSpan.h"
#include <iostream>
#include <istream>

using namespace std;

void PrintTestResult(bool result);
void RobTest();
void BobTest();
void BugTest();

int _tmain(int argc, _TCHAR* argv[])
{
	BugTest();

	return 0;
}

void PrintTestResult(bool result)
{
	if (result)
	{
		cout << "This Test PASSED" << endl << endl;
	}

	else
	{
		cout << "This Test FAILED" << endl << endl;
	}
}

void RobTest()
{
	TimeSpan dur1(0, 0, 0);
	TimeSpan dur2(0, 60, 123);
	TimeSpan dur3(0, 0, 0);
	bool testResult = false;

	// Note: I could just create new objects to test all of this, but I want to make
	//		 sure that my setters are working properly, so for every test, I also test
	//		 the setter members.

	// Test + Operator
	cout << "===== [+ Test] =====" << endl;
	dur3 = dur1 + dur2;
	cout << dur3;
	PrintTestResult(dur3 == TimeSpan(1, 2, 3));

	// Test - Operator
	dur1.setSeconds(-61);
	dur1.setMinutes(0);
	dur1.setHours(1);

	dur2.setSeconds(1);
	dur2.setMinutes(1);
	dur2.setHours(1);

	cout << "===== [- Test] =====" << endl;
	dur3 = dur1 - dur2;
	cout << dur3;
	PrintTestResult(dur3 == TimeSpan(0, -2, -2));

	// Test += Operator
	dur2.setSeconds(1);
	dur2.setMinutes(1);
	dur2.setHours(1);

	dur3.setSeconds(-1);
	dur3.setMinutes(0);
	dur3.setHours(0);

	cout << "===== [+= Test] =====" << endl;
	dur3 += dur2;
	cout << dur3;
	PrintTestResult(dur3 == TimeSpan(1, 1, 0));

	// Test -= Operator
	dur2.setSeconds(-1);
	dur2.setMinutes(0);
	dur2.setHours(1);

	dur3.setSeconds(-1);
	dur3.setMinutes(-1);
	dur3.setHours(1);

	cout << "===== [-= Test] =====" << endl;
	dur3 -= dur2;
	cout << dur3;
	PrintTestResult(dur3 == TimeSpan(0, -1, 0));

	// Test == Operator
	cout << "===== [== Test] =====" << endl;
	PrintTestResult(TimeSpan(1, 0, 0) == TimeSpan(0, 0, 3600));

	// Test != Operator
	cout << "===== [!= Test] =====" << endl;
	PrintTestResult(TimeSpan(1, 1, 1) != TimeSpan(12, -1, -1));

	// Test for unairy negation
	cout << "===== [UN Test] =====" << endl;
	PrintTestResult(-TimeSpan(1,-1,-1) == TimeSpan(-1, 1, 1));

	// InStream test
	cin >> dur3;
	cout << dur3;

	cout << "Press Any Key to Continue...";
	getchar();
}

void BobTest()
{
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0); TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7(0,0,0), dur8(0,0,0);
	dur7 = dur1 + dur3;
	cout << dur1;  cout << dur2;  cout << dur3;  cout << dur4;  cout << dur5;  cout << dur6;  cout << dur7;
	dur7 += dur3;  cout << dur3;  cout << dur7;
	if (dur3 != dur6)  { cout << "Durations are different." << endl; }
	else  {
		cout << "Durations are the same" << endl;
	}
}

void BugTest()
{
	TimeSpan ts1(0,0,0);

	ts1.setSeconds(600);

	std::cout << ts1 << std::endl;

	ts1.setMinutes(3);

	TimeSpan ts2(0, 0, 0);

	ts1 = ts1 + ts2;

	cout << ts1 << endl;

	std::cout << ts1 << std::endl;
}
