#pragma once
#include "DataBase.h"

class TruckDatabase : public DataBase
{
private:
	std::vector<Record> m_database;
	bool database_is_empty() const;

public:
	void DisplayData() const;
	std::set<std::string> FindUniqueTrucks() const;
	std::vector<TruckDatabase> SplitDatabase() const;
	double CalculateTotalWeight() const;

	void SortByDate();
	void AddRecord(const Record& record)  override;
	virtual const size_t GetRecords() const noexcept override;
	virtual const Record& GetRecord(int index) const override;
	Record& GetRecord(int index) override;
};

