#include "repo.h"
#include "locatar.h"
#include "service.h"
#include "vd.h"
#include <assert.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
using std::sort;
using std::copy_if;
using std::find_if;
using std::make_unique;




void Repo::store(const Locatar& loc)
{
	bool ok = true;
	for (int i = 0; i < locatari.size(); i++)
	{
		if (locatari.at(i).get_apartament() == loc.get_apartament())
		{
			ok = false;
		}
	}
	if (!ok)
		throw RepoExceptions("The locatar has already been added\n");
	locatari.push_back(loc);
}


void Repo::del(int ap)
{
	int i = -1, index = 0;
	for (const auto& l : locatari)
	{
		i++;
		if (l.get_apartament() == ap)
		{
			index = i;
		}
	}
	locatari.erase(index);

}


void Repo::update(int ap, string nume)
{
	for (int i = 0; i < locatari.size(); i++)
	{
		if (locatari.at(i).get_apartament() == ap)
		{
			Locatar l = Locatar(locatari.at(i).get_apartament(), nume, locatari.at(i).get_suprafata(), locatari.at(i).get_tip());
			locatari.modify(i, l);
		}
	}
}


const Locatar Repo::find(int ap)
{
	/*for (const auto& l : locatari)
	{
		if (l.get_apartament() == ap)
		{
			return l;
		}
	}
	throw RepoExceptions("The apartment doesn't exist");*/
	vector<Locatar> all = get_all();
	vector<Locatar>::iterator f = std::find_if(all.begin(), all.end(),
		[=](const Locatar l) {
			return l.get_apartament() == ap;
		});
	if (f != all.end())
		return *f;
	else
		throw RepoExceptions("The apartment doesn't exist\n");
	/*vector<Locatar> all = get_all();
	vector<Locatar>::iterator it = find_if(all.begin(), all.end(),
		[=](const Locatar& l) {
			return l.get_apartament() == ap;
		});
	if (it != all.end())
		return *it; */
}


VectorDinamic<Locatar> Repo::filter_by_type(string t)
{
	vector<Locatar> filtered_list{};
	vector<Locatar> all = get_all();
	copy_if(all.begin(), all.end(), back_inserter(filtered_list),
		[t](const Locatar& l) {
			return l.get_tip() == t;
		});
	return VectorDinamic<Locatar>(filtered_list);

}

VectorDinamic<Locatar> Repo::filter_by_surface(int sup)
{
	vector<Locatar> filtered_list{};
	vector<Locatar> all = get_all();
	copy_if(all.begin(), all.end(), back_inserter(filtered_list),
		[sup](const Locatar& l) noexcept {
			return l.get_suprafata() == sup;
		});
	return VectorDinamic<Locatar>(filtered_list);
}

bool cmp_name(Locatar l1, Locatar l2)
{
	return (l1.get_nume().compare(l2.get_nume()) < 0);
}

VectorDinamic<Locatar> Repo::sort_by_name()
{
	vector<Locatar> v = locatari.toStdVector();
	sort(v.begin(), v.end(), cmp_name);
	return VectorDinamic<Locatar>(v);
}

bool cmp_surface(Locatar l1, Locatar l2) noexcept
{
	return (l1.get_suprafata() < l2.get_suprafata());
}

VectorDinamic<Locatar> Repo::sort_by_surface()
{
	vector<Locatar> v = locatari.toStdVector();
	sort(v.begin(), v.end(), cmp_surface);
	return VectorDinamic<Locatar>(v);
}

bool cmp_type(Locatar l1, Locatar l2)
{
	return (l1.get_tip().compare(l2.get_tip()) < 0);
}

VectorDinamic<Locatar> Repo::sort_combined()
{
	vector<Locatar> v = locatari.toStdVector();
	sort_by_surface();
	sort(v.begin(), v.end(), cmp_type);
	return VectorDinamic<Locatar>(v);
}

void test_repo()
{
	Repo rep;
	Locatar l{ 12, "Mihai Popa", 120, "2 camere" };
	rep.store(l);
	const auto& locatari = rep.get_all();
	assert(locatari.size() == 1);
	try
	{
		rep.store(l);
	}
	catch (RepoExceptions& e)
	{
		assert(e.get_message() == "The locatar has already been added\n");
		assert(true);
	}

}
