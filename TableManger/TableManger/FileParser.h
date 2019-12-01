#ifndef file_parser_
#define file_parser_
#include "DataBase.h"

class FileParser
{
public:
	FileParser() = default;
	virtual ~FileParser() = default;
	// DataBase should be some 
	virtual void Parse(std::ifstream&, DataBase&) const = 0;
};

#endif // !file_parser_
