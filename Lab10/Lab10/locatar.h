#pragma once
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <string>
#include <iostream>
using std::cout;
using std::string;

class Locatar
{
private:
	int apartament;
	string nume_proprietar;
	int suprafata;
	string tip;
public:
	int get_apartament() const noexcept
	{
		return apartament;
	}
	string get_nume() const
	{
		return nume_proprietar;
	}
	int get_suprafata() const noexcept
	{
		return suprafata;
	}
	string get_tip() const
	{
		return tip;
	}

	void set_nume(string nume_nou)
	{
		nume_proprietar = nume_nou;
	}

	bool operator==(const Locatar& ot) const noexcept
	{
		return ot.apartament == apartament;
	}

	Locatar(const Locatar& ot) :apartament{ ot.apartament }, nume_proprietar{ ot.nume_proprietar }, suprafata{ ot.suprafata }, tip{ ot.tip } {

	}

	Locatar()
	{
		apartament = 0;
		nume_proprietar = "";
		suprafata = 0;
		tip = "";
	};

	Locatar(int apartament, string nume, int suprafata, string tip) :apartament{ apartament }, nume_proprietar{ nume }, suprafata{ suprafata }, tip{ tip }{

	}
};