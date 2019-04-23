#include "unittest.h"

Generator::Generator(void)
{}
Generator::Generator(const Generator &src)
{ (void)src; }
Generator::~Generator(void)
{}

const Generator&	Generator::operator=(const Generator &rhs)
{ (void)rhs; return (*this); }

std::string	Generator::gen(void)
{
	return (std::to_string(rand()));
}
