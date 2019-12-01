#pragma once
#ifndef database_h_
#define database_h_
#include "helpers.h"
#include <vector>
#include <set>
#include <algorithm>

class IDataBase
{
public:
	virtual void AddRecord(const Record& ) = 0;
	virtual const size_t GetRecords() const noexcept = 0;
	virtual const Record& GetRecord(int) const = 0;
	virtual Record& GetRecord(int) = 0;
};

#endif // !database_h_
