#pragma once
#include <fstream>
#include <ostream>
#include <string>
#include <mutex>
#include "DataBase.h"

class OutputFileHandler
{
private:
	std::string m_fileName = "";
	std::ofstream m_outputFile;

	using MutexType = std::mutex;
	using WriteLock = std::unique_lock<MutexType>;
	
	mutable MutexType m_mtx;

	void CheckFile();
public:
	OutputFileHandler() = default;
	explicit OutputFileHandler(std::string filename) : m_fileName(filename), m_outputFile(m_fileName) {};
	OutputFileHandler(const OutputFileHandler&) = delete;
	OutputFileHandler& operator= (const OutputFileHandler&) = delete;
	OutputFileHandler(OutputFileHandler&& other);
	OutputFileHandler& operator=(OutputFileHandler&& other);
	virtual ~OutputFileHandler() 
	{
		if (m_outputFile.is_open())
			m_outputFile.close();
	}

	virtual void WriteData(const IDataBase& db);
	virtual void AppendData(std::string data);
};

