//=============================================================================
// File:		TimeSpan.cpp
// Author:		Robert House
// Date:		5 OCT 2014
// Project:		Assignment 1
//
// Description: This is the implementation for a TimeSpan object. Handles 
//				typical operations (+ - += -=) of this object type.
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

#include "TimeSpan.h"

TimeSpan::TimeSpan(double seconds)
{
	pSeconds = (int)seconds;

	//=====================
	// NORMALIZATION
	//=====================
	NormalCorrection();
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	pSeconds = (int)seconds;
	pMinutes = (int)minutes;

	//=====================
	// NORMALIZATION
	//=====================
	NormalCorrection();
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	pSeconds = (int)seconds;
	pMinutes = (int)minutes;
	pHours = (int)hours;

	//=====================
	// NORMALIZATION
	//=====================
	NormalCorrection();
}

TimeSpan::~TimeSpan() {}

// Operator Overloads
TimeSpan& TimeSpan::operator+(TimeSpan &rightSide)
{
	int seconds = pSeconds + rightSide.getSeconds();
	int minutes = pMinutes + rightSide.getMinutes();
	int hours = pHours + rightSide.getHours();

	return TimeSpan(hours, minutes, seconds);
}

TimeSpan& TimeSpan::operator-(TimeSpan &rightSide)
{
	
	int seconds = pSeconds - rightSide.getSeconds();
	int minutes = pMinutes - rightSide.getMinutes();
	int hours = pHours - rightSide.getHours();

	return TimeSpan(hours, minutes, seconds);
}

TimeSpan& TimeSpan::operator+=(TimeSpan &rightSide)
{
	int seconds = pSeconds += rightSide.getSeconds();
	int minutes = pMinutes += rightSide.getMinutes();
	int hours = pHours += rightSide.getHours();

	return TimeSpan(hours, minutes, seconds);
}

TimeSpan& TimeSpan::operator-=(TimeSpan &rightSide)
{
	int seconds = pSeconds -= rightSide.getSeconds();
	int minutes = pMinutes -= rightSide.getMinutes();
	int hours = pHours -= rightSide.getHours();

	return TimeSpan(hours, minutes, seconds);
}

TimeSpan& operator-(TimeSpan &timespan)
{
	// Assign the fields of timespan to its negative values
	timespan.setSeconds(-timespan.getSeconds());
	timespan.setMinutes(-timespan.getMinutes());
	timespan.setHours(-timespan.getHours());

	return timespan;
}
bool operator==(TimeSpan &leftSide, TimeSpan &rightSide)
{
	// Check if all of the fields are equal. If it gets to the
	// third conditional, it is "equal"
	if (leftSide.getSeconds() == rightSide.getSeconds())
	{
		if (leftSide.getMinutes() == rightSide.getMinutes())
		{
			if (leftSide.getHours() == rightSide.getHours())
			{
				return true;
			}
		}
	}

	return false;
}

bool operator!=(TimeSpan &leftSide, TimeSpan &rightSide)
{
	// If all fields are equal, the two objects are equal.
	// If one of them are not, return true, they are not equal
	if (leftSide.getSeconds() == rightSide.getSeconds())
	{
		if (leftSide.getMinutes() == rightSide.getMinutes())
		{
			if (leftSide.getHours() == rightSide.getHours())
			{
				return false;
			}
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream &output, const TimeSpan &timespan)
{
	output << "Hours: " << timespan.getHours() << " Minutes: " << timespan.getMinutes()
		<< " Seconds: " << timespan.getSeconds() << std::endl;

	return output;
}

std::istream& operator>>(std::istream &input, TimeSpan &timespan)
{
	// Temp Vars
	double tempSeconds = 0;
	double tempMinutes = 0;
	double tempHours = 0;

	std::cout << "Please Enter 3 Numbers Seperated by Spaces:" << std::endl;

	// Read the input stream for the time values
	input >> tempHours;
	input >> tempMinutes; 
	input >> tempSeconds;

	// Convert to int and assign values
	timespan.setHours((int)tempHours);
	timespan.setMinutes((int)tempMinutes);
	timespan.setSeconds((int)tempSeconds);

	// Normalize the input
	timespan.NormalCorrection();

	return input;
}

// Getters
int TimeSpan::getSeconds() const
{
	return pSeconds;
}

int TimeSpan::getMinutes() const
{
	return pMinutes;
}

int TimeSpan::getHours() const
{
	return pHours;
}

// Setters
bool TimeSpan::setSeconds(int seconds)
{
	pSeconds = seconds;
	return true;
}

bool TimeSpan::setMinutes(int minutes)
{
	pMinutes = minutes;
	return true;
}

bool TimeSpan::setHours(int hours)
{
	pHours = hours;
	return true;
}

bool TimeSpan::NormalCorrection()
{
	int totalSeconds = 0;

	// Convert time into the total number of seconds
	totalSeconds += pHours * SECOND_HOUR_CONVERSION;
	totalSeconds += pMinutes * MINUTE_HOUR_CONVERSION;
	totalSeconds += pSeconds;
	
	// Get Number of Minutes
	pMinutes = (totalSeconds / SECOND_MINUTE_CONVERSION);
	pSeconds = totalSeconds % SECOND_MINUTE_CONVERSION; // Assign the remainder as our seconds

	// Get number of hours
	pHours = (pMinutes / MINUTE_HOUR_CONVERSION);
	pMinutes = pMinutes % MINUTE_HOUR_CONVERSION; // remainder is the minutes
	
	return true;
}