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
	if(count_workers)
		delete[] work_mas;
	for (int i = 0; i < count_furnitures; i++)
		delete fur_mas[i];
	if(count_furnitures)
		delete[] fur_mas;
	for (int i = 0; i < count_machines; i++)
		delete mach_mas[i];
	if(count_machines)
		delete[] mach_mas;
	std::cout << "(���������� ��� ������� ������ Factory)\n";
}

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
void Factory::delete_Worker(int number)
{
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
			count_workers -= 1;
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
			count_furnitures -= 1;
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
	try
	{
		if (count_machines > 1)
		{
			Machine** for_realloc = new Machine * [count_machines - 1];
			delete mach_mas[number];
			for (int i = 0; i < number; i++)
				for_realloc[i] = mach_mas[i];
			for (int i = number + 1; i < count_machines; i++)
				for_realloc[i-1] = mach_mas[i];
			count_machines -= 1;
			delete[] mach_mas;
			mach_mas = for_realloc;
		}
		else
		{
			count_machines -= 1;
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
			out << std::setw(155) << "_\n";
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
std::istream& operator>>(std::istream& in, Factory**& fact)
{
	using std::string;
	if (fact[0] != nullptr)
	{
		for (int i = 0; fact[i] != nullptr; i++)
			delete fact[i];
		delete[] fact;
		fact = nullptr;
	}
	else
		delete[] fact;
	string str;
	int count_factory = 0;
	while(in)
	{
		std::getline(in,str);
		for (int j = 6; j < str.size(); j++)
		{
			if (str[j - 6] == '�' && str[j - 5] == '�' && str[j - 4] == '�' && str[j - 3] == '�' && str[j - 2] == '�' && str[j - 1] == '�' && str[j] == '�')
				count_factory += 1;
		}
	}
	try
	{
		fact = new Factory * [count_factory + 1];
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
					count_factory += 1;
					fact[count_factory] = new Factory(prov);
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
						Worker* w = new Worker(atoi(mas[6]), atoll(mas[3]), mas[1], mas[2], mas[0], mas[4], mas[5]);
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
						Furniture* f = new Furniture(atoi(mas[3]), atoi(mas[4]), atoi(mas[5]), atoi(mas[6]), mas[2], mas[1], mas[0]);
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
						razdel(mas, st);
						Machine* m = new Machine(atoll(mas[2]), atoi(mas[3]), mas[1], mas[0]);
						fact[count_factory]->add_Machine(m);
						delete[] st;
					}
				}
			}
		NEXT:;
		}
	}
	catch (std::bad_alloc&)
	{
		std::cout << "\n\n������������ ������!\n\n";
		exit(EXIT_FAILURE);
	}
	return in;
}
void Factory::show() const
{
	using std::cout;
	if (count_workers)
	{
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		cout << std::setw(60) << "��������� " << std::endl;
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		cout << "|  " << std::setw(10) << "�������" << "   ";
		cout << "  " << std::setw(10) << "���" << "   ";
		cout << "  " << std::setw(10) << "��������" << "   ";
		cout << "  " << std::setw(13) << "�������" << "   ";
		cout << "  " << std::setw(40) << "�����" << "   ";
		cout << "  " << std::setw(15) << "����" << "   ";
		cout << "  " << std::setw(10) << "��������" << "   " << std::endl;
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		for (int j = 0; j < count_workers; j++)
		{
			cout << j << "  " << std::setw(10) << work_mas[j]->get_surname() << "  |";
			cout << "  " << std::setw(10) << work_mas[j]->get_name() << "  |";
			cout << "  " << std::setw(10) << work_mas[j]->get_patr() << "  |";
			cout << "  " << std::setw(13) << work_mas[j]->get_phone() << "  |";
			cout << "  " << std::setw(40) << work_mas[j]->get_address() << "  |";
			cout << "  " << std::setw(15) << work_mas[j]->get_post() << "  |";
			cout << "  " << std::setw(10) << work_mas[j]->get_money() << "  |" << std::endl;
		}
	}
	if (count_furnitures)
	{
		cout.fill('_');
		cout << std::setw(155) << "_\n";
		cout.fill(' ');
		cout << std::setw(60) << "������ " << std::endl;
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		cout << "|  " << std::setw(20) << "���" << "   ";
		cout << "  " << std::setw(20) << "��������" << "   ";
		cout << "  " << std::setw(20) << "����" << "   ";
		cout << "  " << std::setw(6) << "������" << "   ";
		cout << "  " << std::setw(6) << "������" << "   ";
		cout << "  " << std::setw(6) << "�������" << "   ";
		cout << "  " << std::setw(11) << "���������" << "   " << std::endl;
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		for (int j = 0; j < count_furnitures; j++)
		{
			cout << j << "  " << std::setw(20) << fur_mas[j]->get_type() << "  |";
			cout << "  " << std::setw(20) << fur_mas[j]->get_material() << "  |";
			cout << "  " << std::setw(20) << fur_mas[j]->get_color() << "  |";
			cout << "  " << std::setw(6) << fur_mas[j]->get_height() << "  |";
			cout << "  " << std::setw(6) << fur_mas[j]->get_width() << "  |";
			cout << "  " << std::setw(6) << fur_mas[j]->get_depth() << "  |";
			cout << "  " << std::setw(11) << fur_mas[j]->get_money() << "  |" << std::endl;
		}
	}
	if (count_machines)
	{
		cout.fill('_');
		cout << std::setw(155) << "_\n";
		cout.fill(' ');
		cout << std::setw(60) << "������ " << std::endl;
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		cout << "|  " << std::setw(20) << "�����" << "   ";
		cout << "  " << std::setw(20) << "������" << "   ";
		cout << "  " << std::setw(20) << "�����" << "   ";
		cout << "  " << std::setw(6) << "����" << "   " << std::endl;
		cout.fill('-');
		cout << std::setw(155) << "-\n";
		cout.fill(' ');
		for (int j = 0; j < count_machines; j++)
		{
			cout << j << "  " << std::setw(20) << mach_mas[j]->get_make() << "  |";
			cout << "  " << std::setw(20) << mach_mas[j]->get_model() << "  |";
			cout << "  " << std::setw(20) << mach_mas[j]->get_number() << "  |";
			cout << "  " << std::setw(6) << mach_mas[j]->get_money() << "  |" << std::endl;
		}
		cout.fill('_');
		cout << std::setw(155) << "_______\n\n\n";
		cout.fill(' ');
	}
}
void Factory::set_height(int number, int h)
{
	fur_mas[number]->set_height(h);
}
void Factory::set_width(int number, int w)
{
	fur_mas[number]->set_width(w);
}
void Factory::set_depth(int number, int d)
{
	fur_mas[number]->set_depth(d);
}
void Factory::set_cost(int number, int c)
{
	fur_mas[number]->set_cost(c);
}
void Factory::set_color(int number, const char* color)
{
	fur_mas[number]->set_color(color);
}
void Factory::set_material(int number, const char* material)
{
	fur_mas[number]->set_material(material);
}
void Factory::set_type(int number, const char* type)
{
	fur_mas[number]->set_type(type);
}
int Factory::get_height(int number) const
{
	return fur_mas[number]->get_height();
}
int Factory::get_width(int number) const
{
	return fur_mas[number]->get_width();
}
int Factory::get_depth(int number) const
{
	return fur_mas[number]->get_depth();
}
const char* Factory::get_color(int number) const
{
	return fur_mas[number]->get_color();
}
const char* Factory::get_material(int number) const
{
	return fur_mas[number]->get_material();
}
const char* Factory::get_type(int number) const
{
	return fur_mas[number]->get_type();
}
int Factory::get_money_fur(int number) const
{
	return fur_mas[number]->get_money();
}
void Factory::show_fur(int number) const
{
	fur_mas[number]->show();
}
void Factory::set_number(int number ,long long n)
{
	mach_mas[number]->set_number(n);
}
void Factory::set_price(int number,int p)
{
	mach_mas[number]->set_price(p);
}
void Factory::set_model(int number,const char* m)
{
	mach_mas[number]->set_model(m);
}
void Factory::set_make(int number,const char* mak)
{
	mach_mas[number]->set_make(mak);
}
long long Factory::get_number(int number) const
{
	return mach_mas[number]->get_number();
}
const char* Factory::get_model(int number) const
{
	return mach_mas[number]->get_model();
}
const char* Factory::get_make(int number) const
{
	return mach_mas[number]->get_make();
}
void Factory::show_mach(int number) const
{
	mach_mas[number]->show();
}
int Factory::get_money_mach(int number) const
{
	return mach_mas[number]->get_money();
}
void Factory::set_salary(int number, int s)
{
	work_mas[number]->set_salary(s);
}
void Factory::set_phone(int number, long p)
{
	work_mas[number]->set_phone(p);
}
void Factory::set_name(int number, const char* n)
{
	work_mas[number]->set_name(n);
}
void Factory::set_patr(int number, const char* p)
{
	work_mas[number]->set_patr(p);
}
void Factory::set_surname(int number, const char* sur)
{
	work_mas[number]->set_patr(sur);
}
void Factory::set_address(int number, const char* add)
{
	work_mas[number]->set_address(add);
}
void Factory::set_post(int number, const char* p)
{
	work_mas[number]->set_post(p);
}
long long Factory::get_phone(int number) const
{
	return work_mas[number]->get_phone();
}
const char* Factory::get_name(int number) const
{
	return work_mas[number]->get_name();
}
const char* Factory::get_patr(int number) const
{
	return work_mas[number]->get_patr();
}
const char* Factory::get_surname(int number) const
{
	return work_mas[number]->get_surname();
}
const char* Factory::get_address(int number) const
{
	return work_mas[number]->get_address();
}
const char* Factory::get_post(int number) const
{
	return work_mas[number]->get_post();
}
void Factory::show_work(int number) const
{
	work_mas[number]->show();
}
int Factory::get_money_work(int number) const
{
	return work_mas[number]->get_money();
}
int Factory::compare_gabarits() const
{
	int max = -1;
	int count = 0;
	for (int i = 0; i < count_furnitures; i++)
	{
		for (int j = 0; j < count_furnitures; j++)
		{
			if ((*fur_mas[i]) > (*fur_mas[j]) || (*fur_mas[i]) == (*fur_mas[j]))
				count += 1;
			else
			{
				count = 0;
				break;
			}
		}
		if (count == count_furnitures)
			max = i;
		count = 0;
	}
	return max;
}
int Factory::compare_gos_numbers() const
{
	int max = -1;
	int count = 0;
	for (int i = 0; i < count_machines; i++)
	{
		for (int j = 0; j < count_machines; j++)
		{
			if ((*mach_mas[i]) > (*mach_mas[j]) || (*mach_mas[i]) == (*mach_mas[j]))
				count += 1;
			else
			{
				count = 0;
				break;
			}
		}
		if (count == count_machines)
			max = i;
		count = 0;
	}
	return max;
}
int Factory::compare_salaries() const
{
	int max = -1;
	int count = 0;
	for (int i = 0; i < count_workers; i++)
	{
		for (int j = 0; j < count_workers; j++)
		{
			if ((*work_mas[i]) > (*work_mas[j]) || (*work_mas[i]) == (*work_mas[j]))
				count += 1;
			else
			{
				count = 0;
				break;
			}
		}
		if (count == count_workers)
			max = i;
		count = 0;
	}
	return max;
}