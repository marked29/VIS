#include "OutputFileHandler.h"

void OutputFileHandler::m_check_file()
{
	if (!m_output_file.is_open())
		throw std::exception("File could not be opened");
}

void OutputFileHandler::WriteData(const DataBase & db)
{
	std::unique_lock<std::mutex> protector(m_mtx);
	for (size_t i = 0; i < db.GetRecords(); i++)
	{
		auto record = db.GetRecord(i);
		m_output_file << record.Date << " "
					  << record.Truck_Number << " "
					  << record.Weight << "\n";
	}
}

void OutputFileHandler::AppendData(std::string data)
{
	m_output_file << data;
}
