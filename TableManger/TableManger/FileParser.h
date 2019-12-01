#ifndef file_parser_
#define file_parser_
#include "DataBase.h"

class IFileParser
{
public:
	IFileParser() = default;
	virtual ~IFileParser() = default;
	virtual void Parse(std::ifstream&, IDataBase&) const = 0;
};

#endif // !file_parser_
