//=============================================================================
// File:		TimeSpan.h
// Author:		Robert House
// Date:		5 OCT 2014
// Project:		Assignment 1
//
// Description: This is an interface for the implementation of a TimeSpan
//				object. Handles typical operations (+ - += -=) of this object
//				type
//
// Assumptions: 1) time0 - (-time1) => time0 + time1
//				2) Convert min->hours and sec->min when the values are >60
//				3) Values will not overflow int32
//				4) Negative time is not wrong
//
// Known Bugs:	1) >> operator: no input validation :(. Any invalid input
//				makes the input be 0,0,0.
//				2) I'm sure there are more, but I have EE stuff to do....
//=============================================================================

#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>
#include <math.h>

class TimeSpan
{
	// Don't know why you would want to change this. In the event that
	// the values for hours, minutes and seconds change, this will be
	// easy to update.
	static const int SECOND_MINUTE_CONVERSION	= 60;
	static const int MINUTE_HOUR_CONVERSION		= 60;
	static const int SECOND_HOUR_CONVERSION		= 3600;

public:
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds);

	~TimeSpan();

	// Operator overloading
	TimeSpan& operator+(TimeSpan &rightSide);
	TimeSpan& operator-(TimeSpan &rightSide);
	TimeSpan& operator+=(TimeSpan &rightSide);
	TimeSpan& operator-=(TimeSpan &rightSide);

	// Friends (operator overloading)
	friend TimeSpan& operator-(TimeSpan &timespan);
	friend bool operator==(TimeSpan &leftSide, TimeSpan &rightSide);
	friend bool operator!=(TimeSpan &leftSide, TimeSpan &rightSide);
	friend std::ostream& operator<<(std::ostream &os, const TimeSpan &timespan);
	friend std::istream& operator>>(std::istream &is, TimeSpan &timespan);

	// Getters/Setters
	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;

	bool setSeconds(int seconds);
	bool setMinutes(int minutes);
	bool setHours(int hours);


private:
	int pSeconds	= 0;
	int pMinutes	= 0;
	int pHours		= 0;

	// Normalize the input to not have minutes or seconds >60. Convert
	// to the appropriate format
	bool NormalCorrection();
};

#endif