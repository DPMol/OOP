#pragma once
#include <string>
#include <memory>
#include <vector>
#include "locatar.h"
#include "repo.h"
#include "vd.h"
#include "notificare.h"
#include "validator.h"
#include "undo.h"
using std::string;
using std::unique_ptr;
using std::vector;

class Bloc
{
private:
	Repo& rep;
	LocatarValidator& val;
	Notificare notif;
	vector<unique_ptr<UndoAction>> undo_actions;

public:
	Bloc(Repo& rep, LocatarValidator& val) noexcept : rep{ rep }, val{ val } {};
	//Bloc(const Bloc& ot) = delete;
	Bloc() = default;
	void add(int ap, string nume, int suprafata, string tip);

	void delete_locatar(int ap);

	void update(int ap, string nume);

	void undo();

	const Locatar find(int ap);

	VectorDinamic<Locatar> filter_by_type(string t);

	VectorDinamic<Locatar> filter_by_surface(int sup);

	vector<Locatar> get_all();

	VectorDinamic<Locatar> sort_by_name();

	VectorDinamic<Locatar> sort_by_surface();

	VectorDinamic<Locatar> sort_combined();

	void addToNotif(int nr_ap);

	void addRandomToNotif(int nr);

	void emptyNotif() noexcept;

	void exportNotif(const string& file);

	const vector<Locatar>& getNotifList() noexcept;


};


void test_add();

void test_delete_locatar();

void test_update();

void test_find();

void test_filter_by_type();

void test_filter_by_surface();

void test_sort_by_name();

void test_sort_by_surface();

void test_sort_combined();

void test_addToNotif();

void test_addRandomToNotif();

void test_emptyNotif();

void test_undo();