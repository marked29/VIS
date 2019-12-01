#include "FileHandler.h"

void FileHandler::CheckFile()
{
	if (!m_file.is_open())
		throw std::exception("File could not be opened");
}

FileHandler::FileHandler(FileHandler && other)
{
	m_fileName = std::move(other.m_fileName);
	m_file = std::move(other.m_file);
	m_rawData = std::move(other.m_rawData);
}

FileHandler& FileHandler::operator=(FileHandler && other)
{
	if (this == &other)
	{
		return *this;
	}

	m_fileName = std::move(other.m_fileName);
	m_file = std::move(other.m_file);
	m_rawData = std::move(other.m_rawData);
}

void FileHandler::ReadFileRawData()
{
	char reader;

	CheckFile();

	while (m_file.get(reader))
		m_rawData += reader;
}

void FileHandler::ParseFile(const IFileParser& parser, IDataBase & database)
{
	CheckFile();
	parser.Parse(m_file, database);
}