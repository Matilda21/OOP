#pragma once
using namespace std;
#include "factory.h"
# include <iostream>
# include <memory>
# include <map>

class DrawSolution
{
public:
	typedef std::unique_ptr<AbstractFactory> (*CreateFactory)();


	bool registration(size_t id, CreateFactory createfun)
	{
		return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
	}
	bool check(size_t id) { return callbacks.erase(id) == 1; }

	std::unique_ptr<AbstractFactory> create(size_t id)
	{
		CallBackMap::const_iterator it = callbacks.find(id);

		if (it == callbacks.end())
		{
//			throw IdError();
		}

		return std::unique_ptr<AbstractFactory>((it->second)());
	}

private:
	using CallBackMap = map<size_t, CreateFactory>;

	CallBackMap callbacks;
};
