#include "notificare.h"
using std::shuffle;

void Notificare::addApToNotif(const Locatar& l)
{
	notifList.push_back(l);
}

void Notificare::emptyNotif() noexcept
{
	notifList.clear();
}

void Notificare::addRandomAp(vector <Locatar> v, int nr)
{
	shuffle(v.begin(), v.end(), std::default_random_engine(std::random_device{}()));
	while (notifList.size() < nr && v.size() > 0)
	{
		notifList.push_back(v.back());
		v.pop_back();
	}
}

const vector<Locatar>& Notificare::getAllNotif() noexcept
{
	return notifList;
}