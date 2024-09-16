#ifndef BASE_H_
#define BASE_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <cstring>
class Base
{
public:
	Base(){ std::cout << "(Конструктор класса Base)\n"; };
	virtual void show() const = 0;
	virtual int compare_money(const Base&) const = 0;
	virtual int get_money() const = 0;
	virtual ~Base() { std::cout << "(Деструктор класса Base)\n"; };
};
class bad : public std::exception
{
private:
	enum { MAX_NAME_FIELD = 15 };
	char field_name_[MAX_NAME_FIELD];
	long long field_mean_;
public:
	bad(const char* field_name, long long field_mean) :field_mean_(field_mean) { std::strcpy(field_name_, field_name); }
	inline const char* get_field_name() const { return field_name_; }
	inline long long get_field_mean() const { return field_mean_; }
};
#endif
