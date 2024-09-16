#include "factory.h"
#include <iomanip>
Factory::Factory()
{
	count_furnitures = 0;
	count_machines = 0;
	count_workers = 0;
	work_mas = nullptr;
	fur_mas = nullptr;
	mach_mas = nullptr;
	int len = 5;           //Длина строки "none"
	try
	{
		name = new char[len];
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name, "none");
	std::cout << "(Конструктор без параметров для объекта класса Factory)\n";
}
Factory::Factory(const char* n, Worker* work, Furniture* furn, Machine* mach)
{
	count_furnitures = 1;
	count_machines = 1;
	count_workers = 1;
	try
	{
		name = new char[std::strlen(n) + 1];
		std::strcpy(name, n);
		work_mas = new Worker * [count_workers];
		work_mas[0] = work;
		fur_mas = new Furniture * [count_workers];
		fur_mas[0] = furn;
		mach_mas = new Machine * [count_workers];
		mach_mas[0] = mach;
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "(Конструктор с параметрами для объекта класса Factory)\n";
}
Factory::Factory(const Factory& cop)
{
	try
	{
		name = new char[std::strlen(cop.name) + 1];
		std::strcpy(name, cop.name);
		count_workers = cop.count_workers;
		count_furnitures = cop.count_furnitures;
		count_machines = cop.count_machines;
		work_mas = new Worker * [count_workers];
		fur_mas = new Furniture * [count_furnitures];
		mach_mas = new Machine * [count_machines];
		for (int i = 0; i < count_workers; i++)
			work_mas[i] = new Worker(*(cop.work_mas[i]));
		for (int i = 0; i < count_furnitures; i++)
			fur_mas[i] = new Furniture(*(cop.fur_mas[i]));
		for (int i = 0; i < count_machines; i++)
			mach_mas[i] = new Machine(*(cop.mach_mas[i]));
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "(Конструктор копирования для объекта класса Factory)\n";
}
Factory& Factory::operator=(const Factory& obj)
{
	if (this == &obj)
		return *this;
	if(std::strlen(name) == std::strlen(obj.name))
		std::strcpy(name,obj.name);
	else
	{
		delete[] name;
		set_name(obj.name);
	}
	try
	{
		if (count_workers == obj.count_workers)
		{
			for (int i = 0; i < count_workers; i++)
			{
				delete work_mas[i];
				work_mas[i] = new Worker(*(obj.work_mas[i]));
			}
		}
		else
		{
			for (int i = 0; i < count_workers; i++)
				delete work_mas[i];
			delete[] work_mas;
			work_mas = new Worker * [obj.count_workers];
			for (int i = 0; i < obj.count_workers; i++)
				work_mas[i] = new Worker(*(obj.work_mas[i]));
			count_workers = obj.count_workers;
		}
		if (count_furnitures == obj.count_furnitures)
		{
			for (int i = 0; i < count_furnitures; i++)
			{
				delete fur_mas[i];
				fur_mas[i] = new Furniture(*(obj.fur_mas[i]));
			}
		}
		else
		{
			for (int i = 0; i < count_furnitures; i++)
				delete fur_mas[i];
			delete[] fur_mas;
			fur_mas = new Furniture * [obj.count_furnitures];
			for (int i = 0; i < obj.count_furnitures; i++)
				fur_mas[i] = new Furniture(*(obj.fur_mas[i]));
			count_furnitures = obj.count_furnitures;
		}
		if (count_machines == obj.count_machines)
		{
			for (int i = 0; i < count_machines; i++)
			{
				delete mach_mas[i];
				mach_mas[i] = new Machine(*(obj.mach_mas[i]));
			}
		}
		else
		{
			for (int i = 0; i < count_machines; i++)
				delete mach_mas[i];
			delete[] mach_mas;
			mach_mas = new Machine * [obj.count_machines];
			for (int i = 0; i < obj.count_machines; i++)
				mach_mas[i] = new Machine(*(obj.mach_mas[i]));
			count_machines = obj.count_machines;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	return *this;
}
Factory::~Factory()
{
	delete[] name;
	for (int i = 0; i < count_workers; i++)
		delete work_mas[i];
	delete[] work_mas;
	for (int i = 0; i < count_furnitures; i++)
		delete fur_mas[i];
	delete[] fur_mas;
	for (int i = 0; i < count_machines; i++)
		delete mach_mas[i];
	delete[] mach_mas;
	std::cout << "(Деструктор для объекта класса Factory)\n";
}
/*
void Factory::add_Worker(Worker* obj)
{
	try
	{
		if (count_workers == 0)
		{
			count_workers += 1;
			work_mas = new Worker * [count_workers];
			work_mas[0] = obj;
		}
		else
		{
			Worker** for_realloc = new Worker * [count_workers + 1];
			for (int i = 0; i < count_workers; i++)
				for_realloc[i] = work_mas[i];
			count_workers += 1;
			for_realloc[count_workers - 1] = obj;
			delete[] work_mas;
			work_mas = for_realloc;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Работник добавлен к фабрике " << name << std::endl;
}
*/
void Factory::add_Worker(Worker& obj)
{
	try
	{
		if (count_workers == 0)
		{
			count_workers += 1;
			work_mas = new Worker*[count_workers];
			Worker* vrem = new Worker(obj.get_money(), obj.get_phone(), obj.get_name(), obj.get_patr(), obj.get_surname(), obj.get_address(), obj.get_post());
			work_mas[0] = vrem;
		}
		else
		{
			Worker** for_realloc = new Worker*[count_workers + 1];
			for (int i = 0; i < count_workers; i++)
				for_realloc[i] = work_mas[i];
			count_workers += 1;
			Worker* vrem = new Worker(obj.get_money(), obj.get_phone(), obj.get_name(), obj.get_patr(), obj.get_surname(), obj.get_address(), obj.get_post());
			for_realloc[count_workers-1] = vrem;
			delete[] work_mas;
			work_mas = for_realloc;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Работник добавлен к фабрике " << name << std::endl;
}
void Factory::add_Furniture(Furniture& obj)
{
	try
	{
		if (count_furnitures == 0)
		{
			count_furnitures += 1;
			fur_mas = new Furniture * [count_furnitures];
			Furniture* vrem = new Furniture(obj.get_height(),obj.get_width(),obj.get_depth(),obj.get_money(),obj.get_color(),obj.get_material(),obj.get_type());
			fur_mas[0] = vrem;
		}
		else
		{
			Furniture** for_realloc = new Furniture * [count_furnitures + 1];
			for (int i = 0; i < count_furnitures; i++)
				for_realloc[i] = fur_mas[i];
			count_furnitures += 1;
			Furniture* vrem = new Furniture(obj.get_height(), obj.get_width(), obj.get_depth(), obj.get_money(), obj.get_color(), obj.get_material(), obj.get_type());
			for_realloc[count_furnitures - 1] = vrem;
			delete[] fur_mas;
			fur_mas = for_realloc;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Мебель добавлена к фабрике " << name << std::endl;
}
void Factory::add_Machine(Machine& obj)
{
	try
	{
		if (count_machines == 0)
		{
			count_machines += 1;
			mach_mas = new Machine * [count_machines];
			Machine* vrem = new Machine(obj.get_number(), obj.get_money(), obj.get_model(), obj.get_make());
			mach_mas[0] = vrem;
		}
		else
		{
			Machine** for_realloc = new Machine * [count_machines + 1];
			for (int i = 0; i < count_machines; i++)
				for_realloc[i] = mach_mas[i];
			count_machines += 1;
			Machine* vrem = new Machine(obj.get_number(), obj.get_money(), obj.get_model(), obj.get_make());
			for_realloc[count_machines - 1] = vrem;
			delete[] mach_mas;
			mach_mas = for_realloc;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Машина добавлена к фабрике " << name << std::endl;
}
/*
void Factory::add_Furniture(Furniture* obj)
{
	try
	{
		if (count_furnitures == 0)
		{
			count_furnitures += 1;
			fur_mas = new Furniture * [count_furnitures];
			fur_mas[0] = obj;
		}
		else
		{
			Furniture** for_realloc = new Furniture * [count_furnitures + 1];
			for (int i = 0; i < count_furnitures; i++)
				for_realloc[i] = fur_mas[i];
			count_furnitures += 1;
			for_realloc[count_furnitures - 1] = obj;
			delete[] fur_mas;
			fur_mas = for_realloc;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Мебель добавлена к фабрике " << name << std::endl;
}
void Factory::add_Machine(Machine* obj)
{
	try
	{
		if (count_machines == 0)
		{
			count_machines += 1;
			mach_mas = new Machine * [count_machines];
			mach_mas[0] = obj;
		}
		else
		{
			Machine** for_realloc = new Machine * [count_machines + 1];
			for (int i = 0; i < count_machines; i++)
				for_realloc[i] = mach_mas[i];
			count_machines += 1;
			for_realloc[count_machines - 1] = obj;
			delete[] mach_mas;
			mach_mas = for_realloc;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Машина добавлена к фабрике " << name << std::endl;
}
*/
void Factory::delete_Worker(int number)
{
	if (number < 0 || number >= count_workers)
		throw bad_fact("Worker",number);
	try
	{
		if (count_workers > 1)
		{
			Worker** for_realloc = new Worker * [count_workers - 1];
			delete work_mas[number];
			for (int i = 0; i < number; i++)
				for_realloc[i] = work_mas[i];
			for (int i = number + 1; i < count_workers; i++)
				for_realloc[i-1] = work_mas[i];
			count_workers -= 1;
			delete[] work_mas;
			work_mas = for_realloc;
		}
		else
		{
			delete work_mas[number];
			delete[] work_mas;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Работник удален из фабрики " << name << std::endl;
}
void Factory::delete_Furniture(int number)
{
	if (number < 0 || number >= count_furnitures)
		throw bad_fact("Furniture",number);
	try
	{
		if (count_furnitures > 1)
		{
			Furniture** for_realloc = new Furniture * [count_furnitures - 1];
			delete fur_mas[number];
			for (int i = 0; i < number; i++)
				for_realloc[i] = fur_mas[i];
			for (int i = number + 1; i < count_furnitures; i++)
				for_realloc[i-1] = fur_mas[i];
			count_furnitures -= 1;
			delete[] fur_mas;
			fur_mas = for_realloc;
		}
		else
		{
			delete fur_mas[number];
			delete[] fur_mas;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Мебель удалена из фабрики " << name << std::endl;
}
void Factory::delete_Machine(int number)
{
	if (number < 0 || number >= count_machines)
		throw bad_fact("Machine",number);
	try
	{
		if (count_machines > 1)
		{
			Machine** for_realloc = new Machine * [count_machines - 1];
			delete mach_mas[number];
			for (int i = 0; i < number; i++)
				for_realloc[i] = mach_mas[i];
			for (int i = number + 1; i < count_machines; i++)
				for_realloc[i] = mach_mas[i];
			count_machines -= 1;
			delete[] mach_mas;
			mach_mas = for_realloc;
		}
		else
		{
			delete mach_mas[number];
			delete[] mach_mas;
		}
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- Машина удалена из фабрики " << name << std::endl;
}
void Factory::set_name(const char* str)
{
	delete[] name;
	try
	{
		name = new char[std::strlen(str) + 1];
	}
	catch (std::bad_alloc)
	{
		std::cout << "Недостаточно памяти!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name, str);
	std::cout << "--- Имя фабрики установлено\n";
}

void Factory::show() const
{
	std::cout << "------------------------------------------------------------- Фабрика " << name << " -------------------------------------------------------------------\n";
	if (count_workers)
	{
		std::cout << "\n_________________________________________________________________РАБОТНИКИ_____________________________________________________________________\n";
		std::cout <<std::setw(15) << "Фамилия";
		std::cout << std::setw(15) << "Имя";
		std::cout << std::setw(15) << "Отчество";
		std::cout << std::setw(40) << "Адрес";
		std::cout << std::setw(20) << "Телефон";
		std::cout << std::setw(20) << "Должность";
		std::cout << std::setw(10) << "Зарплата";
		std::cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < count_workers; i++)
		{
			std::cout << std::setw(15) << work_mas[i]->get_surname();
			std::cout << std::setw(15) << work_mas[i]->get_name();
			std::cout << std::setw(15) << work_mas[i]->get_patr();
			std::cout << std::setw(40) << work_mas[i]->get_address();
			std::cout << std::setw(20) << work_mas[i]->get_phone();
			std::cout << std::setw(20) << work_mas[i]->get_post();
			std::cout << std::setw(10) << work_mas[i]->get_money() << std::endl;
		}
	}
	if (count_furnitures)
	{
		std::cout << "\n_________________________________________________________________МЕБЕЛЬ________________________________________________________________________\n";
		std::cout << std::setw(30) << "Тип";
		std::cout << std::setw(30) << "Материал";
		std::cout << std::setw(20) << "Цвет";
		std::cout << std::setw(10) << "Высота";
		std::cout << std::setw(10) << "Ширина";
		std::cout << std::setw(10) << "Глубина";
		std::cout << std::setw(15) << "Стоимость";
		std::cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < count_furnitures; i++)
		{
			std::cout << std::setw(30) << fur_mas[i]->get_type();
			std::cout << std::setw(30) << fur_mas[i]->get_material();
			std::cout << std::setw(20) << fur_mas[i]->get_color();
			std::cout << std::setw(10) << fur_mas[i]->get_height();
			std::cout << std::setw(10) << fur_mas[i]->get_width();
			std::cout << std::setw(10) << fur_mas[i]->get_depth();
			std::cout << std::setw(15) << fur_mas[i]->get_money() << std::endl;
		}
	}
	if (count_machines)
	{
		std::cout << "\n_____________________________________________________________________МАШИНЫ________________________________________________________________________\n";
		std::cout << std::setw(25) << "Марка";
		std::cout << std::setw(25) << "Модель";
		std::cout << std::setw(20) << "Гос.номер";
		std::cout << std::setw(15) << "Цена";
		std::cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < count_workers; i++)
		{
			std::cout << std::setw(25) << mach_mas[i]->get_make();
			std::cout << std::setw(25) << mach_mas[i]->get_model();
			std::cout << std::setw(20) << mach_mas[i]->get_number();
			std::cout << std::setw(15) << mach_mas[i]->get_money() << std::endl;
		}
	}
	std::cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
}
