#include "unittest.h"

Unittest::StackOfTest::StackOfTest(const std::string &s, size_t shared_size):
	Executable(shared_size),
	name(s),
	tests()
{}
Unittest::StackOfTest::StackOfTest(const StackOfTest &src):
	Executable(src),
	name(src.name),
	tests(src.tests)
{}
Unittest::StackOfTest::~StackOfTest(void)
{}

const Unittest::StackOfTest		&Unittest::StackOfTest::operator=(const StackOfTest &rhs)
{
	if (this != &rhs)
	{
		Executable::operator=(rhs);
		this->name = rhs.name;
		this->tests = rhs.tests;
	}
	return (*this);
}

bool							Unittest::StackOfTest::start(void)
{
	std::cout << std::endl;
	std::cout << "[" << this->name << "]" << std::endl;
	while (!this->tests.empty())
	{
		Generator	*tmp = this->tests.top();
		this->launchprocess(tmp);
		if (this->proc->ret)
			std::cout << "\x1b[32m" << "OK" << "\x1b[0m" << std::endl;
		else
		{
			std::cout << "\x1b[31m" << "KO" << "\x1b[0m" << std::endl;
			std::cout << "trace: " << std::endl;
			this->trace();
		}
		std::cout << std::endl;
		this->tests.pop();
	}
	return (true);
}

void	Unittest::StackOfTest::push(Generator *g)
{
	this->tests.push(g);
}
void	Unittest::StackOfTest::push(Generator &g)
{
	this->tests.push(&g);
}
