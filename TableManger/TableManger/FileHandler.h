#pragma once
#ifndef file_handler_
#define file_handler_

#include "FileParser.h"
#include "DataBaseParser.h"

class FileHandler
{
private:
	std::string m_fileName;
	std::ifstream m_file;
	std::string m_rawData;

	void CheckFile();

public:
	FileHandler() = default;
	explicit FileHandler(const std::string& file_name) : m_fileName(file_name), m_file(file_name), m_rawData("") {}
	FileHandler(const FileHandler&) = delete;
	FileHandler& operator=(const FileHandler&) = delete;
	FileHandler(FileHandler&& other);
	FileHandler& operator=(FileHandler&& other);
	virtual ~FileHandler()
	{
		if (m_file.is_open())
			m_file.close();
	}

	void ReadFileRawData();
	virtual void ParseFile(const IFileParser& parser, IDataBase& TruckDataBase);
};

#endif // !file_handler
