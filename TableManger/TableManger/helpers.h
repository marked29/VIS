#ifndef helpers_h_
#define helpers_h_

#include <string>
#include <iostream>

namespace datetime {

	struct Time
	{
		int hours;
		int minutes;

		std::string Format() const;
	};

	struct Date {
		int year;
		int month;
		int day;
	};

	struct DateTime
	{
		Date date;
		Time time;
	};

	bool operator<(const Time& t1, const Time& t2);
	bool operator==(const Time& t1, const Time& t2);
	bool operator<(const Date &d1, const Date &d2);
	bool operator==(const Date &d1, const Date &d2);
	bool operator<(const DateTime& t1, const DateTime& t2);
	bool operator== (const DateTime& t1, const DateTime& t2);
	std::ostream& operator<<(std::ostream& str, const Time& time);
	std::ostream& operator<<(std::ostream& str, const Date& date);
	std::ostream& operator<<(std::ostream& str, const DateTime& datetime);
}

struct Record
{
	datetime::DateTime Date;
	std::string Truck_Number = "";
	double Weight = 0.0;
};

#endif // !helpers_h_
