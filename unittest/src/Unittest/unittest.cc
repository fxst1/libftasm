#include "unittest.h"

Unittest::Unittest(void):
	tests()
{}
Unittest::~Unittest(void)
{}

void		Unittest::appendTest(const std::string &func, StackOfTest *ex)
{
	this->tests[func] = ex;
}

void		Unittest::launchprocess(const std::string &name, Unittest::StackOfTest *ex, Generator *g)
{
	ex->start();
	(void)name;
	(void)g;
}

void		Unittest::start(void)
{
	for (auto it = this->tests.begin();
			it != this->tests.end(); it++)
	{
		this->launchprocess(it->first, it->second);
	}
}
