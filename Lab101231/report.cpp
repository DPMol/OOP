#include "report.h"

void test_report()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(1, "n1", 22, "t");
	srv.add(2, "n2", 24, "t2");
	srv.add(3, "n3", 30, "t");
	ReportItem ri = ReportItem("t", srv);
	assert(ri.get_val() == 2);
}