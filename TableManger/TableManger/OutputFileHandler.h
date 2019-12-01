#pragma once
#include <fstream>
#include <ostream>
#include <string>
#include <mutex>
#include "DataBase.h"

class OutputFileHandler
{
protected:
	std::string m_file_name = "";
	std::ofstream m_output_file;
	std::mutex m_mtx;

	void m_check_file();
public:
	OutputFileHandler() = default;
	OutputFileHandler(std::string filename) : m_file_name(filename), m_output_file(m_file_name) {};
	virtual ~OutputFileHandler() 
	{
		if (m_output_file.is_open())
			m_output_file.close();
	}

	virtual void WriteData(const DataBase& db);
	virtual void AppendData(std::string data);
};

