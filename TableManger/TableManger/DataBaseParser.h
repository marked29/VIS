#ifndef database_parser_
#define database_parser_
#include "FileParser.h"
#include <fstream>
#include <istream>
#include <string>

class DataBaseParser : public IFileParser
{
public:
	void Parse(std::ifstream& file, IDataBase& database) const override;

};

#endif // !DataBaseParser
