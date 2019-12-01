#include "TruckDatabase.h"

bool TruckDatabase::database_is_empty() const
{
	return m_database.empty();
}

void TruckDatabase::DisplayData() const
{
	std::cout << "======================================================================================\n";
	for (const auto& record : m_database)
	{
		std::cout << record.Date << "\t " << record.Truck_Number << "\t " << record.Weight << "\n";
	}
}

std::set<std::string> TruckDatabase::FindUniqueTrucks() const
{
	if (database_is_empty())
		return std::set<std::string>();

	std::set<std::string> unique_trucks;
	for (const auto& truck : m_database)
		unique_trucks.insert(truck.Truck_Number);

	return unique_trucks;
}

std::vector<TruckDatabase> TruckDatabase::SplitDatabase() const
{
	if (database_is_empty())
		return std::vector<TruckDatabase>{};

	auto unique_trucks = FindUniqueTrucks();
	std::vector<TruckDatabase> tables(unique_trucks.size());

	int tableNo = 0;
	for (const auto& truck : unique_trucks)
	{
		for (auto record : m_database)
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
	for (auto const record : m_database)
	{
		total_weight += record.Weight;
	}
	return total_weight;
}

void TruckDatabase::SortByDate()
{
	if (database_is_empty())
		return;

	std::sort(m_database.begin(), m_database.end(), [](const Record& date1, const Record& date2)
		{
			return date1.Date < date2.Date ? true : false;
		});
}

void TruckDatabase::AddRecord(const Record & record) 
{
	m_database.push_back(record);
}

const size_t TruckDatabase::GetRecords() const noexcept
{
	return m_database.size();
}

const Record & TruckDatabase::GetRecord(int index) const
{
	return m_database.at(index);
}

Record& TruckDatabase::GetRecord(int index)
{
	return m_database.at(index);
}
