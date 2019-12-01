#pragma once
#include "DataBase.h"

class TruckDatabase : public IDataBase
{
private:
	std::vector<Record> m_dataBase;
	bool DatabaseIsEmpty() const;

public:
	TruckDatabase() = default;
	TruckDatabase(const Record &record);
	TruckDatabase(std::vector<Record> db) : m_dataBase(db) {};
	TruckDatabase(const TruckDatabase& other) : m_dataBase(other.m_dataBase) {};
	TruckDatabase(TruckDatabase&& other) : m_dataBase(std::move(other.m_dataBase)) {};
	TruckDatabase& operator=(const TruckDatabase& other);
	TruckDatabase& operator=(TruckDatabase&& other);

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

