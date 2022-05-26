#pragma once

#include "locatar.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class ValidationException {
	vector<string> errorMsg;
public:
	ValidationException(vector<string> errorMessages) :errorMsg{ errorMessages } {};
	string getErrorMsg()
	{
		string fullMsg = "";
		for (const string e : errorMsg)
		{
			fullMsg += e + '\n';
		}
		return fullMsg;
	}
};

class LocatarValidator {
public:
	void validate(const Locatar& l)
	{
		vector<string> errors;
		if (l.get_apartament() < 0)
			errors.push_back("Apartment must be a natural number!");
		if (l.get_nume().length() < 2)
			errors.push_back("Name must have at least 2 characters!");
		if (l.get_suprafata() <= 0)
			errors.push_back("Surface must be greater than 0!");

		if (errors.size() > 0)
			throw ValidationException(errors);
	}
};