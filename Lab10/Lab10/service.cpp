#include "service.h"
#include <assert.h>
#include <memory>
#include<fstream>
#include "undo.h"
using std::make_unique;

void Bloc::add(int ap, string nume, int suprafata, string tip)
{
	Locatar l{ ap, nume, suprafata, tip };
	val.validate(l);
	rep.store(l);
	undo_actions.push_back(make_unique<UndoAdd>(rep, l));
}

void Bloc::delete_locatar(int ap)
{
	Locatar l = find(ap);
	rep.del(ap);
	undo_actions.push_back(make_unique<UndoDel>(rep, l));
}

void Bloc::update(int ap, string nume)
{

	Locatar l = find(ap);
	rep.update(ap, nume);
	undo_actions.push_back(make_unique<UndoUpdate>(rep, l));
}

void Bloc::undo()
{
	if (undo_actions.empty())
		throw RepoExceptions{ "You can't make undo anymore\n" };
	undo_actions.back()->doUndo();
	undo_actions.pop_back();
}

const Locatar Bloc::find(int ap)
{
	return rep.find(ap);
}

VectorDinamic<Locatar> Bloc::filter_by_type(string t)
{
	return rep.filter_by_type(t);
}

VectorDinamic<Locatar> Bloc::filter_by_surface(int sup)
{
	return rep.filter_by_surface(sup);
}

VectorDinamic<Locatar> Bloc::sort_by_name()
{
	return rep.sort_by_name();
}

VectorDinamic<Locatar> Bloc::sort_by_surface()
{
	return rep.sort_by_surface();
}

VectorDinamic<Locatar> Bloc::sort_combined()
{
	return rep.sort_combined();
}

vector<Locatar> Bloc::get_all()
{
	return rep.get_all();
}

void Bloc::addToNotif(int nr_ap)
{
	const auto& l = rep.find(nr_ap);
	notif.addApToNotif(l);
}

void Bloc::addRandomToNotif(int nr)
{
	notif.addRandomAp(get_all(), nr);
}

void Bloc::emptyNotif() noexcept
{
	notif.emptyNotif();
}

void Bloc::exportNotif(const string& file)
{
	std::ofstream filename(file);
	for (auto& n : notif.getAllNotif())
	{
		filename << n.get_apartament() << ',' << n.get_nume() << ',' << n.get_suprafata() << ',' << n.get_tip() << "<br/>";
	}
	filename.close();
}

const vector<Locatar>& Bloc::getNotifList() noexcept
{
	return notif.getAllNotif();
}

void test_add()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 120, "2 camere");
	auto locatari = srv.get_all();
	assert(locatari.size() == 1);
	srv.add(1, "Alina Marcu", 200, "2 camere");
	locatari = srv.get_all();
	assert(locatari.size() == 2);
	try {
		srv.add(-2, "Alin Pop", 270, "4 camere");
	}
	catch (ValidationException& e) {
		assert(true);
		assert(e.getErrorMsg() == "Apartment must be a natural number!\n");
	}
	try {
		srv.add(8, "D", 25, "2 camere");
	}
	catch (ValidationException& e) {
		assert(true);
		assert(e.getErrorMsg() == "Name must have at least 2 characters!\n");
	}
	try {
		srv.add(8, "Daria Groza", 0, "1 camera");
	}
	catch (ValidationException& e) {
		assert(true);
		assert(e.getErrorMsg() == "Surface must be greater than 0!\n");
	}
}

void test_delete_locatar()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 120, "2 camere");
	srv.add(1, "Alina Marcu", 200, "2 camere");
	auto locatari = srv.get_all();
	assert(locatari.size() == 2);
	srv.delete_locatar(12);
	locatari = srv.get_all();
	assert(locatari.size() == 1);
	assert(locatari.front().get_apartament() == 1);
	try
	{
		srv.delete_locatar(2);
	}
	catch (RepoExceptions& e)
	{
		assert(e.get_message() == "The apartment doesn't exist\n");
		assert(true);
	}
}

void test_update()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 120, "2 camere");
	srv.add(1, "Alina Marcu", 200, "2 camere");
	srv.update(12, "Carmen Dan");
	auto locatari = srv.get_all();
	assert(locatari.front().get_nume() == "Carmen Dan");
	try
	{
		srv.update(2, "Victor Pop");
	}
	catch (RepoExceptions& e)
	{
		assert(e.get_message() == "The apartment doesn't exist\n");
		assert(true);
	}
}

void test_find()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 120, "2 camere");
	srv.add(1, "Alina Marcu", 200, "2 camere");
	auto l = srv.find(1);
	assert(l.get_apartament() == 1);
	assert(l.get_nume() == "Alina Marcu");
	assert(l.get_suprafata() == 200);
	assert(l.get_tip() == "2 camere");
	try
	{
		l = srv.find(2);
	}
	catch (RepoExceptions& e)
	{
		assert(e.get_message() == "The apartment doesn't exist\n");
		assert(true);
	}

}

void test_filter_by_type()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 30, "2 camere");
	auto filtered_list = srv.filter_by_type("2 camere");
	assert(filtered_list.size() == 2);
	filtered_list = srv.filter_by_type("penthouse");
	assert(filtered_list.size() == 0);
}

void test_filter_by_surface()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 20, "2 camere");
	auto filtered_list = srv.filter_by_surface(20);
	assert(filtered_list.size() == 2);
	filtered_list = srv.filter_by_surface(100);
	assert(filtered_list.size() == 0);
}

void test_sort_by_name()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 30, "2 camere");
	VectorDinamic<Locatar> locatari = srv.sort_by_name();
	assert(locatari.front().get_nume() == "Alina Marcu");
	assert(locatari.back().get_nume() == "Mihai Popa");
}

void test_sort_by_surface()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 30, "2 camere");
	srv.add(7, "Daniel Cristea", 25, "2 camere");
	srv.add(15, "Alisa Maier", 33, "3 camere");
	srv.add(2, "Carina Anton", 32, "2 camere");
	VectorDinamic<Locatar> locatari = srv.sort_by_surface();
	assert(locatari.front().get_suprafata() == 20);
	assert(locatari.back().get_suprafata() == 40);
}

void test_sort_combined()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 30, "2 camere");
	VectorDinamic<Locatar> locatari = srv.sort_combined();
	assert(locatari.front().get_suprafata() == 20);
	assert(locatari.back().get_suprafata() == 40);
}

void test_addToNotif()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.addToNotif(12);
	vector<Locatar> n = srv.getNotifList();
	assert(n.size() == 1);
}

void test_addRandomToNotif()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 30, "2 camere");
	srv.add(7, "Daniel Cristea", 25, "2 camere");
	srv.add(15, "Alisa Maier", 33, "3 camere");
	srv.addToNotif(12);
	srv.addRandomToNotif(5);
	vector<Locatar> n = srv.getNotifList();
	assert(n.size() == 5);
}

void test_emptyNotif()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	srv.add(1, "Alina Marcu", 30, "2 camere");
	srv.add(7, "Daniel Cristea", 25, "2 camere");
	srv.add(15, "Alisa Maier", 33, "3 camere");
	srv.addRandomToNotif(5);
	vector<Locatar> n = srv.getNotifList();
	assert(n.size() == 5);
	srv.emptyNotif();
	n = srv.getNotifList();
	assert(n.size() == 0);
}

void test_undo()
{
	Repo rep;
	LocatarValidator val;
	Bloc srv{ rep, val };
	try {
		srv.undo();
	}
	catch (RepoExceptions& e)
	{
		assert(e.get_message() == "You can't make undo anymore\n");
		assert(true);
	}
	srv.add(12, "Mihai Popa", 20, "2 camere");
	srv.add(9, "Diana Groza", 40, "3 camere");
	auto locatari = srv.get_all();
	assert(locatari.size() == 2);
	srv.undo();
	locatari = srv.get_all();
	assert(locatari.size() == 1);
	srv.delete_locatar(12);
	locatari = srv.get_all();
	assert(locatari.size() == 0);
	srv.undo();
	locatari = srv.get_all();
	assert(locatari.size() == 1);
	assert(locatari.front().get_nume() == "Mihai Popa");
	srv.update(12, "Sabina Muresan");
	locatari = srv.get_all();
	assert(locatari.front().get_nume() == "Sabina Muresan");
	srv.undo();
	locatari = srv.get_all();
	assert(locatari.front().get_nume() == "Mihai Popa");

}