#include "machine.h"
Machine::Machine(long n, int c, const char* mod, const char* mak)
	: number_(n), price_(c)
{
	try
	{
		model_ = new char[std::strlen(mod) + 1];
		make_ = new char[std::strlen(mak) + 1];
	}catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(model_, mod);
	std::strcpy(make_, mak);
	std::cout << "������ ����������� � ����������� ��� ������� ������ Machine\n";
}
Machine::Machine() : number_(1), price_(1)
{
	int len = 5;        //����� ������ "none"
	try
	{
		model_ = new char[len];
		make_ = new char[len];
	}catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(model_, "none");
	std::strcpy(make_, "none");
	std::cout << "������ ����������� ��� ���������� ��� ������� ������ Machine\n";
}
Machine::Machine(const Machine& cop) : number_(cop.number_), price_(cop.price_)
{
	try
	{
		model_ = new char[std::strlen(cop.model_) + 1];
		make_ = new char[std::strlen(cop.make_) + 1];
	}catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(model_, cop.model_);
	std::strcpy(make_, cop.make_);
	std::cout << "������ ����������� ����������� ��� ������a ������ Machine\n";
}
Machine::~Machine()
{
	delete[] model_;
	delete[] make_;
	std::cout << "������ ���������� ��� ������a ������ Machine\n";
}
void Machine::set_model(const char* str)
{
	if (std::strlen(model_) == std::strlen(str))
		std::strcpy(model_, str);
	else
	{
		delete[] model_;
		try
		{
			model_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "������������ ������!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(model_, str);
	}
}
void Machine::set_make(const char* str)
{
	if (std::strlen(make_) == std::strlen(str))
		std::strcpy(make_, str);
	else
	{
		delete[] make_;
		try
		{
			make_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "������������ ������!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(make_, str);
	}
}
Machine& Machine::operator=(const Machine& obj)
{
	if (this == &obj)
		return *this;
	price_ = obj.price_;
	number_ = obj.number_;
	set_model(obj.model_);
	set_make(obj.make_);
	std::strcpy(model_, obj.model_);
	std::strcpy(make_, obj.make_);
	return *this;
}
bool Machine::operator==(const Machine & obj) const     //��� ��������� �������
{
	return (number_ > obj.number_) ? true : false;
}
bool Machine::operator>(const Machine& obj) const	  //��� ��������� �������
{
	return (number_ == obj.number_) ? true : false;
}
void Machine::show() const
{
	std::cout << "�����: " << make_ << std::endl;
	std::cout << "������: " << model_ << std::endl;
	std::cout << "���.�����: " << number_ << std::endl;
	std::cout << "���������: " << price_ << std::endl;
}
int Machine::compare_money(const Base& obj) const
{
	if (price_ == obj.get_money())
		return 0;
	else if (price_ > obj.get_money())
		return 1;
	else
		return 2;
}
int Machine::get_money() const { return price_; }