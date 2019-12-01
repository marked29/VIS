#include "helpers.h"

std::string datetime::Time::Format() const
{
	std::string time_string = std::to_string(hours) + ":";
	if (minutes < 10)
		time_string += "0" + std::to_string(minutes);
	else
		time_string += std::to_string(minutes);
	
	return time_string;
}


bool datetime::operator<(const Time & t1, const Time & t2)
{
	if (t1.hours < t2.hours)
		return true;
	if (t1.hours == t2.hours && t1.minutes < t2.minutes)
		return true;

	return false;
}

bool datetime::operator==(const Time & t1, const Time & t2)
{
	if (t1.hours == t2.hours && t1.minutes == t2.minutes)
		return true;

	return false;
}

bool datetime::operator<(const Date & d1, const Date & d2)
{
	if (d1.year < d2.year)
		return true;
	if (d1.year == d2.year && d1.month < d2.month)
		return true;
	if (d1.year == d2.year && d1.month == d2.month &&
		d1.day < d2.day)
		return true;

	return false;
}

bool datetime::operator==(const Date & d1, const Date & d2)
{
	if (d1.year == d2.year && d1.month == d2.month &&
		d1.day == d2.day)
		return true;

	return false;
}

bool datetime::operator<(const DateTime & t1, const DateTime & t2)
{
	if (t1.date < t2.date)
		return true;
	if (t1.date == t2.date && t1.time < t2.time)
		return true;

	return false;
}

bool datetime::operator==(const DateTime & t1, const DateTime & t2)
{
	if (t1.date == t2.date && t1.time == t2.time)
		return true;

	return false;
}

std::ostream & datetime::operator<<(std::ostream & str, const Time & time)
{
	str << time.Format();
	return str;
}

std::ostream & datetime::operator<<(std::ostream & str, const Date & date)
{
	str << date.day << "." << date.month << "." << date.year;
	return str;
}

std::ostream & datetime::operator<<(std::ostream & str, const DateTime & dateandtime)
{
	str << dateandtime.date << " " << dateandtime.time;
	return str;
}