#include "TruckDatabase.h"

bool TruckDatabase:: DatabaseIsEmpty() const
{
	return m_dataBase.empty();
}

TruckDatabase::TruckDatabase(const Record & record)
{
	m_dataBase.emplace_back(record);
}


TruckDatabase & TruckDatabase::operator=(const TruckDatabase & other)
{
	if (this == &other)
	{
		return *this;
	}

	m_dataBase = other.m_dataBase;
	return *this;
}

TruckDatabase & TruckDatabase::operator=(TruckDatabase && other)
{
	if (this == &other)
	{
		return *this;
	}

	m_dataBase = std::move(other.m_dataBase);
	return *this;
}

void TruckDatabase::DisplayData() const
{
	std::cout << "======================================================================================\n";
	for (const auto& record : m_dataBase)
	{
		std::cout << record.Date << "\t " << record.Truck_Number << "\t " << record.Weight << "\n";
	}
}

std::set<std::string> TruckDatabase::FindUniqueTrucks() const
{
	if ( DatabaseIsEmpty())
		return std::set<std::string>();

	std::set<std::string> unique_trucks;
	for (const auto& truck : m_dataBase)
		unique_trucks.insert(truck.Truck_Number);

	return unique_trucks;
}

std::vector<TruckDatabase> TruckDatabase::SplitDatabase() const
{
	if ( DatabaseIsEmpty())
		return std::vector<TruckDatabase>{};

	auto unique_trucks = FindUniqueTrucks();
	std::vector<TruckDatabase> tables(unique_trucks.size());

	int tableNo = 0;
	for (const auto& truck : unique_trucks)
	{
		for (auto record : m_dataBase)
		{
			if (record.Truck_Number == truck)
			{
				tables[tableNo].AddRecord(record);
			}
		}
		++tableNo;
	}
	return tables;
}

double TruckDatabase::CalculateTotalWeight() const 
{
	double total_weight = 0;
	for (auto const record : m_dataBase)
	{
		total_weight += record.Weight;
	}
	return total_weight;
}

void TruckDatabase::SortByDate()
{
	if ( DatabaseIsEmpty())
		return;

	std::sort(m_dataBase.begin(), m_dataBase.end(), [](const Record& date1, const Record& date2)
		{
			return date1.Date < date2.Date;
		});
}

void TruckDatabase::AddRecord(const Record & record) 
{
	m_dataBase.push_back(record);
}

const size_t TruckDatabase::GetRecords() const noexcept
{
	return m_dataBase.size();
}

const Record & TruckDatabase::GetRecord(int index) const
{
	return m_dataBase.at(index);
}

Record& TruckDatabase::GetRecord(int index)
{
	return m_dataBase.at(index);
}
