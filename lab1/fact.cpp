#include "factory.h"
#include <iomanip>
#include <string>
Factory::Factory()
{
	count_furnitures = 0;
	count_machines = 0;
	count_workers = 0;
	work_mas = nullptr;
	fur_mas = nullptr;
	mach_mas = nullptr;
	int len = 5;           //����� ������ "none"
	try
	{
		name = new char[len];
	}
	catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name, "none");
	std::cout << "(����������� ��� ���������� ��� ������� ������ Factory)\n";
}
Factory::Factory(const char* n)
{
	count_furnitures = 0;
	count_machines = 0;
	count_workers = 0;
	fur_mas = nullptr;
	mach_mas = nullptr;
	work_mas = nullptr;
	try
	{
		name = new char[std::strlen(n) + 1];
		std::strcpy(name, n);
	}
	catch (std::bad_alloc)
	{
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "(����������� � ����������� ��� ������� ������ Factory)\n";
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "(����������� ����������� ��� ������� ������ Factory)\n";
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
		std::cout << "������������ ������!\n";
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
	std::cout << "(���������� ��� ������� ������ Factory)\n";
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- �������� �������� � ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- �������� �������� � ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- ������ ��������� � ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- ������ ��������� � ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- ������ ��������� � ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- ������ ��������� � ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- �������� ������ �� ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- ������ ������� �� ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "--- ������ ������� �� ������� " << name << std::endl;
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(name, str);
	std::cout << "--- ��� ������� �����������\n";
}

std::ostream& operator<<(std::ostream& out, Factory** fact)
{
	for (int i = 0; fact[i] != nullptr; i++)
	{
		out << std::setw(60) << "������� " << fact[i]->name << std::endl << std::endl;
		if (fact[i]->count_workers)
		{
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			out << std::setw(60) << "��������� " << std::endl;
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			out << "|  " << std::setw(10) << "�������" << "   ";
			out << "  " << std::setw(10) << "���" << "   ";
			out << "  " << std::setw(10) << "��������" << "   ";
			out << "  " << std::setw(13) << "�������" << "   ";
			out << "  " << std::setw(40) << "�����" << "   ";
			out << "  " << std::setw(15) << "����" << "   ";
			out << "  " << std::setw(10) << "��������" << "   " << std::endl;
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			for (int j = 0; j < fact[i]->count_workers; j++)
			{
				out << j << "  " << std::setw(10) << fact[i]->work_mas[j]->get_surname() << "  |";
				out << "  " << std::setw(10) << fact[i]->work_mas[j]->get_name() << "  |";
				out << "  " << std::setw(10) << fact[i]->work_mas[j]->get_patr() << "  |";
				out << "  " << std::setw(13) << fact[i]->work_mas[j]->get_phone() << "  |";
				out << "  " << std::setw(40) << fact[i]->work_mas[j]->get_address() << "  |";
				out << "  " << std::setw(15) << fact[i]->work_mas[j]->get_post() << "  |";
				out << "  " << std::setw(10) << fact[i]->work_mas[j]->get_money() << "  |" << std::endl;
			}
		}
		if (fact[i]->count_furnitures)
		{
			out.fill('_');
			out << std::setw(155) << "_\n";
			out.fill(' ');
			out << std::setw(60) << "������ " << std::endl;
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			out << "|  " << std::setw(20) << "���" << "   ";
			out << "  " << std::setw(20) << "��������" << "   ";
			out << "  " << std::setw(20) << "����" << "   ";
			out << "  " << std::setw(6) << "������" << "   ";
			out << "  " << std::setw(6) << "������" << "   ";
			out << "  " << std::setw(6) << "�������" << "   ";
			out << "  " << std::setw(11) << "���������" << "   " << std::endl;
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			for (int j = 0; j < fact[i]->count_furnitures; j++)
			{
				out << j << "  " << std::setw(20) << fact[i]->fur_mas[j]->get_type() << "  |";
				out << "  " << std::setw(20) << fact[i]->fur_mas[j]->get_material() << "  |";
				out << "  " << std::setw(20) << fact[i]->fur_mas[j]->get_color() << "  |";
				out << "  " << std::setw(6) << fact[i]->fur_mas[j]->get_height() << "  |";
				out << "  " << std::setw(6) << fact[i]->fur_mas[j]->get_width() << "  |";
				out << "  " << std::setw(6) << fact[i]->fur_mas[j]->get_depth() << "  |";
				out << "  " << std::setw(11) << fact[i]->fur_mas[j]->get_money() << "  |" << std::endl;
			}
		}
		if (fact[i]->count_machines)
		{
			out.fill('_');
			out << std::setw(155) << "_\n";
			out.fill(' ');
			out << std::setw(60) << "������ " << std::endl;
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			out << "|  " << std::setw(20) << "�����" << "   ";
			out << "  " << std::setw(20) << "������" << "   ";
			out << "  " << std::setw(20) << "�����" << "   ";
			out << "  " << std::setw(6) << "����" << "   " << std::endl;
			out.fill('-');
			out << std::setw(155) << "-\n";
			out.fill(' ');
			for (int j = 0; j < fact[i]->count_machines; j++)
			{
				out << j << "  " << std::setw(20) << fact[i]->mach_mas[j]->get_make() << "  |";
				out << "  " << std::setw(20) << fact[i]->mach_mas[j]->get_model() << "  |";
				out << "  " << std::setw(20) << fact[i]->mach_mas[j]->get_number() << "  |";
				out << "  " << std::setw(6) << fact[i]->mach_mas[j]->get_money() << "  |" << std::endl;
			}
			out.fill('_');
			out << std::setw(155) << "_______\n\n\n";
			out.fill(' ');
		}
	}
	return out;
}
bool bad_stroki(std::istream& in, std::string& str)
{
	std::getline(in, str);
	if (str[0] == '|')
		std::getline(in, str);
	for (int j = 6; j < str.size(); j++)
	{
		if (str[j - 6] == '_' && str[j - 5] == '_' && str[j - 4] == '_' && str[j - 3] == '_' && str[j - 2] == '_' && str[j - 1] == '_')
			return false;
		else if (str[j - 6] == '-' && str[j - 5] == '-' && str[j - 4] == '-')
		{
			std::getline(in, str);
			if (str[0] == '|')
			{
				std::getline(in, str);
				std::getline(in, str);
			}
			break;
		}
	}
	return true;
}
void razdel(char* mas[], char* st)
{
	int i = 0;
	char* next_tok = NULL;
	char* prov = strtok_s(st, " |", &next_tok);
	while (prov != NULL)
	{
		prov = strtok_s(NULL, " |", &next_tok);
		mas[i++] = prov;
	}
}
Factory** scan(std::istream& in, Factory** fact)
{
	using std::string;
	if(fact!=nullptr)
	{
		for (int i = 0; fact[i] != nullptr; i++)
			delete[] fact[i];
		delete[] fact;
		fact = nullptr;
	}
	string str;
	int count_factory = 0;
	while(in)
	{
		std::getline(in,str);
		for (int j = 6; j < str.size(); j++)
		{
			if (str[j - 6] == '�' && str[j - 5] == '�' && str[j - 4] == '�' && str[j - 3] == '�' && str[j - 2] == '�' && str[j - 1] == '�' && str[j] == '�')
			{
				count_factory += 1;
				char* next_tok = NULL;
				char* st = new char[strlen(str.c_str())+1];
				strcpy(st,str.c_str());
				char* prov = strtok_s(st, " ", &next_tok);
				prov = strtok_s(NULL, " ", &next_tok);
				delete[] st;
			}
		}
	}
	fact = new Factory * [count_factory+1];
	fact[count_factory] = nullptr;
	count_factory = -1;
	in.clear();
	in.seekg(std::ios_base::beg);
	while (in)
	{
		std::getline(in, str);
		for (int j = 6; j < str.size(); j++)
		{
			if (str[j - 6] == '�' && str[j - 5] == '�' && str[j - 4] == '�' && str[j - 3] == '�' && str[j - 2] == '�' && str[j - 1] == '�' && str[j] == '�')
			{
				char* next_tok = NULL;
				char* st = new char[strlen(str.c_str()) + 1];
				strcpy(st, str.c_str());
				char* prov = strtok_s(st, " ", &next_tok);
				prov = strtok_s(NULL, " ", &next_tok);
				Factory* f = new Factory(prov);
				//f->set_name(prov);
				count_factory += 1;
				fact[count_factory] = f;
				delete[] st;
			}
			else if (str[j - 6] == '�' && str[j - 5] == '�' && str[j - 4] == '�' && str[j - 3] == '�' && str[j - 2] == '�' && str[j - 1] == '�' && str[j] == '�')
			{
				while (in)
				{
					if (!bad_stroki(in, str))
						goto NEXT;
					char* mas[10];
					char* st = new char[strlen(str.c_str()) + 1];
					strcpy(st, str.c_str());
					razdel(mas, st);
					Worker w(atoi(mas[6]), atoll(mas[3]), mas[1], mas[2], mas[0], mas[4], mas[5]);
					fact[count_factory]->add_Worker(w);
					delete[] st;
				}
			}
			else if (str[j - 6] == '�' && str[j - 5] == '�' && str[j - 4] == '�' && str[j - 3] == '�' && str[j - 2] == '�' && str[j - 1] == '�')
			{
				while (in)
				{
					if (!bad_stroki(in, str))
						goto NEXT;
					char* mas[10];
					char* st = new char[strlen(str.c_str()) + 1];
					strcpy(st, str.c_str());
					razdel(mas, st);
					Furniture f(atoi(mas[3]), atoi(mas[4]), atoi(mas[5]), atoi(mas[6]), mas[2],mas[1],mas[0]);
					fact[count_factory]->add_Furniture(f);
					delete[] st;
				}
			}
			else if (str[j - 6] == '�' && str[j - 5] == '�' && str[j - 4] == '�' && str[j - 3] == '�' && str[j - 2] == '�' && str[j - 1] == '�')
			{
				while (in)
				{
					if (!bad_stroki(in, str))
						goto NEXT;
					char* mas[10];
					char* st = new char[strlen(str.c_str()) + 1];
					strcpy(st, str.c_str());
					razdel(mas,st);
					Machine m(atoll(mas[2]),atoi(mas[3]),mas[1],mas[0]);
					fact[count_factory]->add_Machine(m);
					delete[] st;
				}
			}
		}
		NEXT:;
	}
	return fact;
}
/*
void Factory::show() const
{
	std::cout << "------------------------------------------------------------- ������� " << name << " -------------------------------------------------------------------\n";
	if (count_workers)
	{
		std::cout << "\n_________________________________________________________________���������_____________________________________________________________________\n";
		std::cout <<std::setw(15) << "�������";
		std::cout << std::setw(15) << "���";
		std::cout << std::setw(15) << "��������";
		std::cout << std::setw(40) << "�����";
		std::cout << std::setw(20) << "�������";
		std::cout << std::setw(20) << "���������";
		std::cout << std::setw(10) << "��������";
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
		std::cout << "\n_________________________________________________________________������________________________________________________________________________\n";
		std::cout << std::setw(30) << "���";
		std::cout << std::setw(30) << "��������";
		std::cout << std::setw(20) << "����";
		std::cout << std::setw(10) << "������";
		std::cout << std::setw(10) << "������";
		std::cout << std::setw(10) << "�������";
		std::cout << std::setw(15) << "���������";
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
		std::cout << "\n_____________________________________________________________________������________________________________________________________________________\n";
		std::cout << std::setw(25) << "�����";
		std::cout << std::setw(25) << "������";
		std::cout << std::setw(20) << "���.�����";
		std::cout << std::setw(15) << "����";
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
*/

/*
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
		std::cout << "������������ ������!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "(����������� � ����������� ��� ������� ������ Factory)\n";
}
*/