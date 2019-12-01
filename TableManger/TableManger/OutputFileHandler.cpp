#include "OutputFileHandler.h"

void OutputFileHandler::CheckFile()
{
	if (!m_outputFile.is_open())
		throw std::exception("File could not be opened");
}

OutputFileHandler::OutputFileHandler(OutputFileHandler && other)
{
	m_fileName = std::move(other.m_fileName);
	m_outputFile = std::move(other.m_outputFile);
	WriteLock wLock(other.m_mtx);
}

OutputFileHandler & OutputFileHandler::operator=(OutputFileHandler && other)
{
	if (this == &other)
	{
		return *this;
	}

	m_fileName = std::move(other.m_fileName);
	m_outputFile = std::move(other.m_outputFile);
	WriteLock wLock(other.m_mtx);
	return *this;
}

void OutputFileHandler::WriteData(const IDataBase& db)
{
	CheckFile();
	WriteLock protector(m_mtx);
	for (size_t i = 0; i < db.GetRecords(); i++)
	{
		auto record = db.GetRecord(i);
		m_outputFile << record.Date << " "
					  << record.Truck_Number << " "
					  << record.Weight << "\n";
	}
}

void OutputFileHandler::AppendData(std::string data)
{
	CheckFile();
	m_outputFile << data;
}
