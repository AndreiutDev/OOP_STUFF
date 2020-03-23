#pragma once
#include <string>
class shape
{
public:
	std::string name;
	double flache;
	shape(std::string s, double fl);


	void  set_self_name(std::string other);


	void  set_self_flache(double other);


	std::string  get_self_name();

	double get_self_flache();

};

