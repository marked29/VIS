#include "FileHandler.h"
#include "TruckDatabase.h"
#include "OutputFileHandler.h"

#ifndef test
int main()
{
	FileHandler file("table.txt");
	std::unique_ptr<FileParser>  parser = std::make_unique<DataBaseParser>(DataBaseParser());
	if (!parser)
		return 1;

	TruckDatabase db;
	file.ParseFile(*parser, db);
	db.SortByDate();

	const auto table = db.SplitDatabase();
	for (size_t i = 0; i < table.size(); i++)
	{
		std::thread([i, &table]() {
			std::string file_name = std::to_string(i + 1) + ".txt";
			OutputFileHandler file(file_name);
			file.WriteData(table[i]);
			file.AppendData("Total weight: " + std::to_string(table[i].CalculateTotalWeight())+"\n");
			}).detach();
	}

	system("pause");
	return 0;
}
#else

int main()
{
	datetime::DateTime hellow;
	hellow.date.day = 13;
	hellow.date.month = 10;
	hellow.date.year = 1990;
	hellow.time.hours = 13;
	hellow.time.minutes = 10;
	std::cout << hellow << std::endl;
	system("pause");
	return 0;
}

#endif // test