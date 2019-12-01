#pragma once
#ifndef file_handler_
#define file_handler_

#include "FileParser.h"
#include "DataBaseParser.h"

class FileHandler
{
protected:
	std::string m_file_name;
	std::ifstream m_file;
	std::string m_raw_data;

	void m_check_file();

public:
	FileHandler() = default;
	FileHandler(const std::string& file_name) : m_file_name(file_name), m_file(file_name), m_raw_data("") {}
	virtual ~FileHandler()
	{
		if (m_file.is_open())
			m_file.close();
	}

	void GetFileRawData();
	virtual void ParseFile(const FileParser& parser, DataBase& TruckDataBase);
};

#endif // !file_handler
