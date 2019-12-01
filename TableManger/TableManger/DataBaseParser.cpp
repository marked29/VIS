#include "DataBaseParser.h"

void DataBaseParser::Parse(std::ifstream & file, IDataBase& database) const
{
	for (std::string date = "", truck_number = "", weight = "";
		!file.eof();
		std::getline(file, date, ','),
		std::getline(file, truck_number, ','),
		std::getline(file, weight))
	{
		if (!date.empty() && !truck_number.empty() && !weight.empty())
		{
			Record temp_record;

			datetime::DateTime Full_Date;
			sscanf_s(date.c_str(), "%2d.%2d.%4d %2d:%2d",
				&Full_Date.date.day,
				&Full_Date.date.month,
				&Full_Date.date.year,
				&Full_Date.time.hours,
				&Full_Date.time.minutes);

			temp_record.Date = Full_Date;
			temp_record.Truck_Number = truck_number;
			temp_record.Weight = stof(weight);
			database.AddRecord(temp_record);
		}
	}
}
