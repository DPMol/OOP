#pragma once
#include "locatar.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using std::vector;

class Notificare {
private:
	vector<Locatar> notifList;
public:
	Notificare() = default;
	void addApToNotif(const Locatar& l);
	void emptyNotif() noexcept;
	void addRandomAp(vector<Locatar> l, int nr);
	const vector<Locatar>& getAllNotif() noexcept;
};