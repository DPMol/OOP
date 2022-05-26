#pragma once

#include "locatar.h"
#include "repo.h"

class UndoAction {
public:
	virtual void doUndo() = 0;
	virtual ~UndoAction() = default;
};

class UndoAdd : public UndoAction {
	Locatar addedLocatar;
	Repo& rep;
public:
	UndoAdd(Repo& rep, const Locatar& l) : rep{ rep }, addedLocatar{ l } {}

	void doUndo() override {
		rep.del(addedLocatar.get_apartament());
	}
};

class UndoDel : public UndoAction {
	Locatar deletedLocatar;
	Repo& rep;
public:
	UndoDel(Repo& rep, const Locatar& l) : rep{ rep }, deletedLocatar{ l } {}

	void doUndo() override {
		rep.store(deletedLocatar);
	}
};

class UndoUpdate : public UndoAction {
	Locatar updatedLocatar;
	Repo& rep;
public:
	UndoUpdate(Repo& rep, const Locatar& l) : rep{ rep }, updatedLocatar{ l } {}

	void doUndo() override {
		rep.update(updatedLocatar.get_apartament(), updatedLocatar.get_nume());
	}
};