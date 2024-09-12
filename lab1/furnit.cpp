#include "furniture.h"
Furniture::Furniture(int h, int w, int d, int c, const char* col, const char* m, const char* t) :
	height_(h), width_(w), depth_(d), cost_(c)
{
	try
	{
		color_ = new char[std::strlen(col) + 1];
		material_ = new char[std::strlen(m) + 1];
		type_fur_ = new char[std::strlen(t) + 1];
	}
	catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(color_, col);
	std::strcpy(material_, m);
	std::strcpy(type_fur_, t);
	std::cout << "������ ����������� � ����������� ��� ������� ������ Furniture\n";
}
Furniture::Furniture() :height_(1), width_(1), depth_(1),cost_(1)
{
	int len = 5;        //����� ������ "none"
	try
	{
		color_ = new char[len];
		material_ = new char[len];
		type_fur_ = new char[len];
	}
	catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(color_, "none");
	std::strcpy(material_, "none");
	std::strcpy(type_fur_, "none");
	std::cout << "������ ����������� ��� ���������� ��� ������� ������ Furniture\n";
}
Furniture::Furniture(const Furniture& cop) : height_(cop.height_), width_(cop.width_), depth_(cop.depth_), cost_(cop.cost_)
{
	try
	{
		color_ = new char[std::strlen(cop.color_)+1];
		material_ = new char[std::strlen(cop.material_)+1];
		type_fur_ = new char[std::strlen(cop.type_fur_)+1];
	}
	catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(color_, cop.color_);
	std::strcpy(material_, cop.material_);
	std::strcpy(type_fur_, cop.type_fur_);
	std::cout << "������ ����������� ����������� ��� ������a ������ Furniture\n";
}
Furniture::~Furniture()
{
	delete[] color_;
	delete[] material_;
	delete[] type_fur_;
	std::cout << "������ ���������� ��� ������a ������ Furniture\n";
}



bool Furniture::operator>(const Furniture& obj) const 
{
	return (width_ * height_ * depth_ > obj.width_ * obj.height_ * obj.depth_) ? true : false;
}
bool Furniture::operator==(const Furniture& obj) const
{
	return (width_ * height_ * depth_ == obj.width_ * obj.height_ * obj.depth_) ? true : false;
}
Furniture& Furniture::operator=(const Furniture& obj)
{
	if (this == &obj)
		return *this;
	height_ = obj.height_;
	width_ = obj.width_;
	depth_ = obj.depth_;
	cost_ = obj.cost_;
	set_color(obj.color_);
	set_material(obj.material_);
	set_type(obj.type_fur_);
	std::strcpy(color_, obj.color_);
	std::strcpy(material_, obj.material_);
	std::strcpy(type_fur_, obj.type_fur_);
	return *this;
}
void Furniture::set_color(const char* str)
{
	if (std::strlen(color_) == std::strlen(str))
		std::strcpy(color_, str);
	else
	{
		delete[] color_;
		try
		{
			color_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "������������ ������!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(color_, str);
	}
}
void Furniture::set_material(const char* str)
{
	if (std::strlen(material_) == std::strlen(str))
		std::strcpy(material_, str);
	else
	{
		delete[] material_;
		try
		{
			material_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "������������ ������!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(material_, str);
	}
}
void Furniture::set_type(const char* str)
{
	if (std::strlen(type_fur_) == std::strlen(str))
		std::strcpy(type_fur_, str);
	else
	{
		delete[] type_fur_;
		try
		{
			type_fur_ = new char[std::strlen(str) + 1];
		}
		catch (std::bad_alloc)
		{
			std::cout << "������������ ������!\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(type_fur_, str);
	}
}
void Furniture::show() const
{
	std::cout << "��� ������: " << type_fur_ << std::endl;
	std::cout << "������: " << height_ << std::endl;
	std::cout << "������: " << width_ << std::endl;
	std::cout << "�������: " << depth_ << std::endl;
	std::cout << "����: " << color_ << std::endl;
	std::cout << "��������: " << material_ << std::endl;
	std::cout << "���������: " << cost_ << std::endl;
}
int Furniture::compare_money(const Base& obj) const
{
	if (cost_ == obj.get_money())
		return 0;
	else if (cost_ > obj.get_money())
		return 1;
	else
		return 2;
}
int Furniture::get_money() const { return cost_; }
//virtual void set_money(int);