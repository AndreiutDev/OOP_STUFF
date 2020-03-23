#include "ex03.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include "ex03.h"
using namespace std;

shape::shape(std::string s, double fl)
{
	this->name = s;
	this->flache = fl;
}

void  shape::set_self_name(std::string other)
{
	this->name = other;
}

void  shape::set_self_flache(double other)
{
	this->flache = other;
}

std::string  shape::get_self_name()
{
	return this->name;
}

double shape::get_self_flache()
{
	return this->flache;
}

void apply(vector<shape*> v, void(f)(shape*))
{
	for (shape* c : v)
		f(c);
}

void	print_shapes(vector<shape*> v)
{
	for_each(v.begin(), v.end(), [](shape* x) {printf("%f ", x->get_self_flache()); });
}

void  funct(shape* c)
{
	c->set_self_flache(c->get_self_flache() * 2);
}

int main(void)
{
	vector<shape*> v = { new shape("circle", 3.33), new shape("triangle", 6.77) };
	print_shapes(v);
	auto function_to_apply = funct;
	apply(v, function_to_apply);
	print_shapes(v);
	return 0;
}
