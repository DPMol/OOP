#pragma once
#include "service.h"
#include <string>
#include <assert.h>

using std::string;

class ReportItem {
private:
	string key;
	int val;
	Bloc& srv;

public:
	ReportItem(string type, Bloc& serv) : key{ type }, srv{ serv } {
		VectorDinamic<Locatar> v = srv.filter_by_type(type);
		val = v.size();
	}

	ReportItem(const ReportItem& ot) :key{ ot.key }, val{ ot.val }, srv{ ot.srv } {}

	ReportItem() = default;

	int get_val()
	{
		return val;
	}

	ReportItem& operator=(ReportItem&& ot) = default;

};

void test_report();