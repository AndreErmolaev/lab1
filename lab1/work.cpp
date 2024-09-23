#include "worker.h"
Worker::Worker(int s, long long p, const char* n, const char* pat, const char* sur, const char* a, const char* post) :
	salary_(s), phone_(p)
{
	try
	{
		name_ = new char[std::strlen(n) + 1];
		patronymic_ = new char[std::strlen(pat) + 1];
		surname_ = new char[std::strlen(sur) + 1];
		post_ = new char[std::strlen(post) + 1];
		address_ = new char[std::strlen(a) + 1];
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name_, n);
	std::strcpy(patronymic_, pat);
	std::strcpy(surname_, sur);
	std::strcpy(post_, post);
	std::strcpy(address_, a);
	std::cout << "(Конструктор с параметрами для объекта класса Worker)\n";
}
Worker::Worker() :salary_(1), phone_(1)
{
	int len = 5;        //Длина строки "none"
	try
	{
		name_ = new char[len];
		patronymic_ = new char[len];
		surname_ = new char[len];
		post_ = new char[len];
		address_ = new char[len];
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name_, "none");
	std::strcpy(surname_, "none");
	std::strcpy(patronymic_, "none");
	std::strcpy(post_, "none");
	std::strcpy(address_, "none");
	std::cout << "(Конструктор без параметров для объекта класса Worker)\n";
}
Worker::Worker(const Worker& obj) : salary_(obj.salary_),phone_(obj.phone_)
{
	try
	{
		name_ = new char[std::strlen(obj.name_) + 1];
		patronymic_ = new char[std::strlen(obj.patronymic_) + 1];
		surname_ = new char[std::strlen(obj.surname_) + 1];
		post_ = new char[std::strlen(obj.post_) + 1];
		address_ = new char[std::strlen(obj.address_) + 1];
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name_, obj.name_);
	std::strcpy(patronymic_, obj.patronymic_);
	std::strcpy(surname_, obj.surname_);
	std::strcpy(post_, obj.post_);
	std::strcpy(address_, obj.address_);
	std::cout << "(Конструктор копирования для объектa класса Worker)\n";
}
Worker::~Worker()
{
	delete[] name_;
	delete[] patronymic_;
	delete[] surname_;
	delete[] post_;
	delete[] address_;
	std::cout << "(Деструктор для объектa класса Worker)\n";
}
void Worker::set_name(const char* str)
{
	if (std::strlen(name_) == std::strlen(str))
		std::strcpy(name_, str);
	else
	{
		delete[] name_;
		try
		{
			name_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "Недостаточно памяти!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(name_, str);
	}
}
void Worker::set_patr(const char* str)
{
	if (std::strlen(patronymic_) == std::strlen(str))
		std::strcpy(patronymic_, str);
	else
	{
		delete[] patronymic_;
		try
		{
			patronymic_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "Недостаточно памяти!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(patronymic_, str);
	}
}
void Worker::set_surname(const char* str)
{
	if (std::strlen(surname_) == std::strlen(str))
		std::strcpy(surname_, str);
	else
	{
		delete[] surname_;
		try
		{
			surname_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "Недостаточно памяти!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(surname_, str);
	}
}
void Worker::set_address(const char* str)
{
	if (std::strlen(address_) == std::strlen(str))
		std::strcpy(address_, str);
	else
	{
		delete[] address_;
		try
		{
			address_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "Недостаточно памяти!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(address_, str);
	}
}
void Worker::set_post(const char* str)
{
	if (std::strlen(post_) == std::strlen(str))
		std::strcpy(post_, str);
	else
	{
		delete[] post_;
		try
		{
			post_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "Недостаточно памяти!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(post_, str);
	}
}
Worker& Worker::operator=(const Worker& obj)
{
	if (this == &obj)
		return *this;
	salary_ = obj.salary_;
	phone_ = obj.phone_;
	set_name(obj.name_);
	set_patr(obj.patronymic_);
	set_surname(obj.surname_);
	set_address(obj.address_);
	set_post(obj.post_);
	return *this;
}
void Worker::show() const
{
	std::cout << "Фамилия: " << surname_ << std::endl;
	std::cout << "Имя: " << name_ << std::endl;
	std::cout << "Отчество: " << patronymic_ << std::endl;
	std::cout << "Адрес: " << address_ << std::endl;
	std::cout << "Телефон: " << phone_ << std::endl;
	std::cout << "Должность: " << post_ << std::endl;
	std::cout << "Зарплата: " << salary_ << std::endl;
}
bool Worker::operator==(const Worker& obj) const
{
	return salary_ == obj.salary_ ? true : false;
}
bool Worker::operator>(const Worker& obj) const
{
	return salary_ > obj.salary_ ? true : false;
}
int Worker::get_money() const { return salary_; }