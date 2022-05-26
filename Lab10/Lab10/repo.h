#pragma once
#include <vector>
#include "vd.h"
#include "locatar.h"
using std::vector;
class RepoExceptions
{
private:
	string msg;
public:
	RepoExceptions(string m) :msg{ m } {

	}
	string get_message()
	{
		return msg;
	}
};
class Repo
{
private:
	VectorDinamic<Locatar > locatari;
public:
	//Repo(const Repo& ot) = delete;

	Repo() = default;

	void store(const Locatar& loc);

	void del(const int ap);

	void update(int ap, string nume);

	const Locatar find(int ap);

	VectorDinamic<Locatar> filter_by_type(string t);

	VectorDinamic<Locatar> filter_by_surface(int sup);

	VectorDinamic<Locatar> sort_by_name();

	VectorDinamic<Locatar> sort_by_surface();

	VectorDinamic<Locatar> sort_combined();

	const vector<Locatar> get_all()
	{
		vector<Locatar> v = locatari.toStdVector();
		return v;
	}
};

void test_repo();