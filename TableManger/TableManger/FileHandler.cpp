#include "FileHandler.h"

void FileHandler::m_check_file()
{
	if (!m_file.is_open())
		throw std::exception("File could not be opened");
}

void FileHandler::GetFileRawData()
{
	char reader;

	m_check_file();

	while (m_file.get(reader))
		m_raw_data += reader;
}

void FileHandler::ParseFile(const FileParser& parser, DataBase & database)
{
	m_check_file();
	parser.Parse(m_file, database);
}