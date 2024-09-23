#include "furniture.h"
#include "machine.h"
#include "worker.h"
#include "factory.h"
#include <clocale>
int main()
{
	setlocale(LC_ALL, "Ru-ru");
	system("chcp 1251");
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ofstream;
	using std::ifstream;
	ifstream fin;
	ofstream fout;
	Factory** fact = nullptr;
	try
	{
		fact = new Factory * [1];
	}
	catch (std::bad_alloc&)
	{
		cout << "\n\n������������ ������!\n\n";
		exit(EXIT_FAILURE);
	}
	fact[0] = nullptr;
	int choice_change = 0;
	int choice_worker = 0; 
	int choice_data = 0;
	long phone = 0;
	int for_enter = 0;
	long long gos_number = 0;
	int size = 0;
	Worker* work = nullptr;
	Furniture* fur = nullptr;
	Machine* mach = nullptr;
	Factory** for_realloc = nullptr;
	std::string str;
	while (1)
	{
		cout << "\n�������� ��������:\n";
		cout << "1 - �������� �������\n";
		cout << "2 - �������� ������ ����� �� ������\n";
		cout << "3 - ������� �������\n";
		cout << "4 - ������� ������ ������\n";
		cout << "5 - ������� �������� ��� ���� ��������\n";
		cout << "6 - ��������� �������� � �������� � ����\n";
		cout << "7 - ������� �������� � �������� �� �����\n";
		cout << "8 - ����� ����� ������� ������ �������\n";
		cout << "9 - ����� ����� ������� ����� ������ ������� \n";
		cout << "10 - ����� ����� ������� �������� ��������� ������� \n";
		cout << "11 - ��������� ������ ���������\n";
		cout<<"����: ";
		int choice_action = 0;
		cin >> choice_action;
		while (cin.fail() || (choice_action<1 || choice_action>11))
		{
			if(cin.fail())
			{
				cout << "------������ �����! ������� �� �����!\n--������� �����: ";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			else
				cout << "------������ �����! ����� ������������ ����� ��������!\n--������� �����: ";
			cin >> choice_action;
		}
		switch(choice_action)
		{
			case 1:
				cout << "������� �������� �������: ";
				if (cin.peek() == '\n')
					cin.get();
				std::getline(cin, str);
				for (int i = 0; fact[i] != nullptr; i++)
					size += 1;
				try
				{
					for_realloc = new Factory * [size + 2];
					for (int i = 0; i < size; i++)
						for_realloc[i] = fact[i];
					for_realloc[size] = new Factory(str.c_str());
				}
				catch (std::bad_alloc&)
				{
					cout << "\n\n������������ ������!\n\n";
					exit(EXIT_FAILURE);
				}
				for_realloc[size + 1] = nullptr;
				delete[] fact;
				fact = for_realloc;
				size = 0;
				cout << "\n\n������� ���������!\n\n";
				break;
			case 2:
				if (fact[0] == nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					cout << "������ ������:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size+=1;
					}
					cout << "\n--������� ����� �������: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size-1))
					{
						if(cin.fail())
						{
							cout << "------������ �����! ������� �� �����!\n--������� �����: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------������ �����! ����� ������������ �����!\n--������� ������ �����: ";
						cin >> number;
					}
					fact[number]->show();
					cout << "\n\n�������� ���� �� ��������:\n";
					cout << "1 - �������� ������\n";
					cout << "2 - �������� ������\n";
					cout << "3 - ������� ������\n";
					cout << "4 - ��������� � ������� ����\n";
					cout << "����: ";
					int action_with_fact = 0;
					cin >> action_with_fact;
					while (cin.fail() ||(action_with_fact<1 || action_with_fact>4))
					{
						if(cin.fail())
						{
							cout << "------������ �����! ������� �� �����!\n--������� �����: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------������ �����! ����� ������������ ����� ��������!\n--������� �����: ";

						cin >> action_with_fact;
					}
					switch (action_with_fact)
					{
					case 1:
						cout << "	��������, ��� ����� ��������:\n";
						cout << "	1 - ������ � ���������\n";
						cout << "	2 - ������ � ������\n";
						cout << "	3 - ������ � ������\n";
						cout << "	4 - ��������� � ������� ����\n";
						cout << "����: ";
						cin >> choice_data;
						while (cin.fail() || (choice_data < 1 || choice_data>4))
						{
							if (cin.fail())
							{
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
							}
							else
								cout << "------������ �����! ����� ������������ ����� ��������!\n--������� ����� ��������: ";
							cin >> choice_data;
						}
						if (choice_data == 1)
						{
							work = new Worker;
							if (cin.peek() == '\n')
								cin.get();
							cout << "������� �������: ";
							std::getline(cin, str);
							work->set_surname(str.c_str());
							cout << "������� ���: ";
							std::getline(cin, str);
							work->set_name(str.c_str());
							cout << "������� ��������: ";
							std::getline(cin, str);
							work->set_patr(str.c_str());
							cout << "������� ���������: ";
							std::getline(cin, str);
							work->set_post(str.c_str());
							cout << "������� ����� (��� ��������): ";
							std::getline(cin, str);
							work->set_address(str.c_str());
							BACK_bad_salary:;
							cout << "������� ��������: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								work->set_salary(for_enter);
							}
							catch (Worker::bad_work& w)
							{
								cout << "\n\n" << w.what();
								cout << "����: " << w.get_field_name() << "; ��������: " << w.get_field_mean() << endl << endl;
								goto BACK_bad_salary;
							}
							BACK_bad_phone:;
							cout << "������� �������: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								work->set_phone(for_enter);
							}
							catch (Worker::bad_work& w)
							{
								cout << "\n\n" << w.what();
								cout << "����: " << w.get_field_name() << "; ��������: " << w.get_field_mean() << endl << endl;
								goto BACK_bad_phone;
							}
							if (cin.peek() == '\n')
								cin.get();
							fact[number]->add_Worker(work);
							fact[number]->show_work(fact[number]->get_count_workers()-1);
						}
						else if (choice_data == 2)
						{
							fur = new Furniture;
							if (cin.peek() == '\n')
								cin.get();
							cout << "������� ��������: ";
							std::getline(cin, str);
							fur->set_material(str.c_str());
							cout << "������� ���: ";
							std::getline(cin, str);
							fur->set_type(str.c_str());
							cout << "������� ����: ";
							std::getline(cin, str);
							fur->set_color(str.c_str());
							BACK_bad_width:;
							cout << "������� ������: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								fur->set_width(for_enter);
							}
							catch (Furniture::bad_fur& f)
							{
								cout << "\n\n" << f.what();
								cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_width;
							}
							BACK_bad_height:;
							cout << "������� ������: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								fur->set_height(for_enter);
							}
							catch (Furniture::bad_fur& f)
							{
								cout << "\n\n" << f.what();
								cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_height;
							}
							BACK_bad_depth:;
							cout << "������� �������: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								fur->set_depth(for_enter);
							}
							catch (Furniture::bad_fur& f)
							{
								cout << "\n\n" << f.what();
								cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_depth;
							}
							BACK_bad_cost:;
							cout << "������� ���������: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								fur->set_cost(for_enter);
							}
							catch (Furniture::bad_fur& f)
							{
								cout << "\n\n" << f.what();
								cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_cost;
							}
							if (cin.peek() == '\n')
								cin.get();
							fact[number]->add_Furniture(fur);
							fact[number]->show_fur(fact[number]->get_count_furns() - 1);
						}
						else if (choice_data == 3)
						{
							mach = new Machine;
							if (cin.peek() == '\n')
								cin.get();
							cout << "������� ������: ";
							std::getline(cin, str);
							mach->set_model(str.c_str());
							cout << "������� �����: ";
							std::getline(cin, str);
							mach->set_make(str.c_str());
							BACK_bad_price:;
							cout << "������� ����: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> for_enter;
							}
							try
							{
								mach->set_price(for_enter);
							}
							catch (Machine::bad_mach& m)
							{
								cout << "\n\n" << m.what();
								cout << "����: " << m.get_field_name() << "; ��������: " << m.get_field_mean() << endl << endl;
								goto BACK_bad_price;
							}
							BACK_bad_gos:;
							cout << "������� ���.�����: ";
							cin >> gos_number;
							while (cin.fail())
							{
								cin.clear();
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								while (cin.get() != '\n')
									continue;
								cin >> gos_number;
							}
							try
							{
								mach->set_number(gos_number);
							}
							catch (Machine::bad_mach& m)
							{
								cout << "\n\n" << m.what();
								cout << "����: " << m.get_field_name() << "; ��������: " << m.get_field_mean() << endl << endl;
								goto BACK_bad_gos;
							}
							if (cin.peek() == '\n')
								cin.get();
							fact[number]->add_Machine(mach);
							fact[number]->show_mach(fact[number]->get_count_machines() - 1);
						}
						break;
					case 2:
						cout << "	��������, ��� ����� ��������:\n";
						cout << "	1 - ������ � ����������\n";
						cout << "	2 - ������ � ������\n";
						cout << "	3 - ������ � �������\n";
						cout << "	4 - ��������� � ������� ����\n";
						cout << "����: ";
						cin >> choice_data;
						while (cin.fail() || (choice_data<1 || choice_data>4))
						{
							if(cin.fail())
							{
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
							}
							else
								cout << "------������ �����! ����� ������������ ����� ��������!\n--������� ����� ��������: ";
							cin >> choice_data;
						}
						switch (choice_data)
						{
						case 1:
							if (!fact[number]->get_count_workers())
							{
								cout << "\n--- ���������� ���!\n\n";
								break;
							}
							cout << "�������� ����� ���������: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_workers()-1))
							{
								if(cin.fail())
								{
									cout << "------������ �����! ������� �� �����!\n--������� �����: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------������ �����! ����� ������������ ����� ���������!\n--������� ������ �����: ";
								cin >> choice_worker;
							}
							cout << "	��������, ��� ��������� ����� ��������:\n";
							cout << "	1 - �������\n";
							cout << "	2 - ���\n";
							cout << "	3 - ��������\n";
							cout << "	4 - �������\n";
							cout << "	5 - �����\n";
							cout << "	6 - ��������\n";
							cout << "	7 - ���������\n";
							cout << "	8 - ��������� � ������� ����\n";
							cout << "���� (���� ����� �������� ��������� ����� - ������� ������ ������ ��� ��������): ";
							cin >> choice_change;
							while (cin.fail())
							{
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
								cin >> choice_change;
							}
							while (choice_change > 0)
							{
								cout << choice_change << "\n";
								if (choice_change % 8 == 1)
								{
									cout << "������� �������: ";
									std::getline(cin, str);
									fact[number]->set_surname(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 2)
								{
									cout << "������� ���: ";
									std::getline(cin, str);
									fact[number]->set_name(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 3)
								{
									cout << "������� ��������: ";
									std::getline(cin, str);
									fact[number]->set_patr(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 4)
								{
									BACK_bad_phone1:;
									cout << "������� �������: ";
									cin >> phone;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> phone;
									}
									try
									{
										fact[number]->set_phone(choice_worker, phone);
									}
									catch (Worker::bad_work& w)
									{
										cout << "\n\n" << w.what();
										cout << "����: " << w.get_field_name() << "; ��������: " << w.get_field_mean() << endl << endl;
										goto BACK_bad_phone1;
									}
								}
								else if (choice_change % 8 == 5)
								{
									cout << "������� ����� (��� ��������): ";
									std::getline(cin, str);
									fact[number]->set_address(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 6)
								{
									BACK_bad_salary1:;
									cout << "������� ��������: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> for_enter;
									}
									try
									{
										fact[number]->set_salary(choice_worker, for_enter);
									}
									catch (Worker::bad_work& w)
									{
										cout << "\n\n" << w.what();
										cout << "����: " << w.get_field_name() << "; ��������: " << w.get_field_mean() << endl << endl;
										goto BACK_bad_salary1;
									}
								}
								else if (choice_change % 8 == 7)
								{
									cout << "������� ���������: ";
									std::getline(cin, str);
									fact[number]->set_post(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 0)
									break;
								choice_change /= 10;
								if (cin.peek() == '\n')
								{
									while (cin.get() != '\n')
										continue;
								}
								cin.clear();
							}
							fact[number]->show_work(fact[number]->get_count_workers() - 1);
							break;
						case 2:
							if (!fact[number]->get_count_furns())
							{
								cout << "\n--- ���������� ���!\n\n";
								break;
							}
							cout << "�������� ����� ������: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_furns()-1))
							{
								if(cin.fail())
								{
									cout << "------������ �����! ������� �� �����!\n--������� �����: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------������ �����! ����� ������������ ����� ������!\n--������� ������ �����: ";
								cin >> choice_worker;
							}
							cout << "	��������, ��� ��������� ����� ��������:\n";
							cout << "	1 - ������\n";
							cout << "	2 - ������\n";
							cout << "	3 - �������\n";
							cout << "	4 - ����\n";
							cout << "	5 - ����\n";
							cout << "	6 - ��������\n";
							cout << "	7 - ���\n";
							cout << "	8 - ��������� � ������� ����\n";
							cout << "���� (���� ����� �������� ��������� ����� - ������� ������ ������ ��� ��������): ";
							cin >> choice_change;
							while (cin.fail())
							{
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
								cin >> choice_change;
							}
							while (choice_change > 0)
							{
								if (choice_change % 8 == 1)
								{
									BACK_bad_height1:;
									cout << "������� ������: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> for_enter;
									}
									try
									{
										fact[number]->set_height(choice_worker, for_enter);
									}
									catch (Furniture::bad_fur& f)
									{
										cout << "\n\n" << f.what();
										cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_height1;
									}
								}
								else if (choice_change % 8 == 2)
								{
								BACK_bad_width1:;
									cout << "������� ������: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> for_enter;
									}
									try
									{
										fact[number]->set_width(choice_worker, for_enter);
									}
									catch (Furniture::bad_fur& f)
									{
										cout << "\n\n" << f.what();
										cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_width1;
									}
								}
								else if (choice_change % 8 == 3)
								{
								BACK_bad_depth1:;
									cout << "������� �������: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> for_enter;
									}
									try
									{
										fact[number]->set_depth(choice_worker, for_enter);
									}
									catch (Furniture::bad_fur& f)
									{
										cout << "\n\n" << f.what();
										cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_depth1;
									}
								}
								else if (choice_change % 8 == 4)
								{
								BACK_bad_cost1:;
									cout << "������� ����: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> for_enter;
									}
									try
									{
										fact[number]->set_cost(choice_worker, for_enter);
									}
									catch (Furniture::bad_fur& f)
									{
										cout << "\n\n" << f.what();
										cout << "����: " << f.get_field_name() << "; ��������: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_cost1;
									}
								}
								else if (choice_change % 8 == 5)
								{
									cout << "����: ";
									std::getline(cin, str);
									fact[number]->set_color(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 6)
								{
									cout << "��������: ";
									std::getline(cin, str);
									fact[number]->set_material(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 7)
								{
									cout << "���: ";
									std::getline(cin, str);
									fact[number]->set_type(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 0)
									break;
								if (cin.peek() == '\n')
								{
									while (cin.get() != '\n')
										continue;
								}
								choice_change /= 10;
							}
							fact[number]->show_fur(fact[number]->get_count_furns() - 1);
							break;
						case 3:
							if (!fact[number]->get_count_machines())
							{
								cout << "\n--- ���������� ���!\n\n";
								break;
							}
							cout << "�������� ����� ������: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_machines()-1))
							{
								if(cin.fail())
								{
									cout << "------������ �����! ������� �� �����!\n--������� �����: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------������ �����! ����� ������������ ����� ������!\n--������� ������ �����: ";
								cin >> choice_worker;
							}
							cout << "	��������, ��� ��������� ����� ��������:\n";
							cout << "	1 - ���.�����\n";
							cout << "	2 - ����\n";
							cout << "	3 - ������\n";
							cout << "	4 - �����\n";
							cout << "	5 - ��������� � ������� ����\n";
							cout << "���� (���� ����� �������� ��������� ����� - ������� ������ ������ ��� ��������): ";
							cin >> choice_change;
							while (cin.fail())
							{
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
								cin >> choice_change;
							}
							while (choice_change > 0)
							{
								if (choice_change % 8 == 1)
								{
								BACK_bad_gos1:;
									cout << "������� ���.�����: ";
									cin >> gos_number;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> gos_number;
									}
									try
									{
										fact[number]->set_number(choice_worker, gos_number);
									}
									catch (Machine::bad_mach& m)
									{
										cout << "\n\n" << m.what();
										cout << "����: " << m.get_field_name() << "; ��������: " << m.get_field_mean() << endl << endl;
										goto BACK_bad_gos1;
									}
								}
								else if (choice_change % 8 == 2)
								{
								BACK_bad_price1:;
									cout << "������� ����: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------������ �����! ������� �� �����!\n--������� �����: ";
										while (cin.get() != '\n')
											continue;
										cin >> for_enter;
									}
									try
									{
										fact[number]->set_price(choice_worker, for_enter);
									}
									catch (Machine::bad_mach& m)
									{
										cout << "\n\n" << m.what();
										cout << "����: " << m.get_field_name() << "; ��������: " << m.get_field_mean() << endl << endl;
										goto BACK_bad_price1;
									}
								}
								else if (choice_change % 8 == 3)
								{
									cout << "������� ������: ";
									std::getline(cin,str);
									fact[number]->set_model(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 4)
								{
									cout << "������� �����: ";
									std::getline(cin, str);
									fact[number]->set_make(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 0)
									break;
								if (cin.peek() == '\n')
								{
									while (cin.get() != '\n')
										continue;
								}
								choice_change /= 10;
							}
							fact[number]->show_mach(fact[number]->get_count_machines() - 1);
							break;
						}
						break;
					case 3:
						cout << "	��������, ��� ����� �������:\n";
						cout << "	1 - ������ � ���������\n";
						cout << "	2 - ������ � ������\n";
						cout << "	3 - ������ � ������\n";
						cout << "	4 - ��������� � ������� ����\n";
						cout << "����: ";
						cin >> choice_data;
						while (cin.fail() || (choice_data < 1 || choice_data>4))
						{
							if (cin.fail())
							{
								cout << "------������ �����! ������� �� �����!\n--������� �����: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
							}
							else
								cout << "------������ �����! ����� ������������ ����� ��������!\n--������� ����� ��������: ";
							cin >> choice_data;
						}
						switch (choice_data)
						{
						case 1:
							if (!fact[number]->get_count_workers())
							{
								cout << "\n--- ���������� ���!\n\n";
								break;
							}
							cout << "������� ����� ���������: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_workers() - 1))
							{
								if (cin.fail())
								{
									cout << "------������ �����! ������� �� �����!\n--������� �����: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------������ �����! ����� ������������ ����� ���������!\n--������� ������ �����: ";
								cin >> choice_worker;
							}
							fact[number]->delete_Worker(choice_worker);
							break;
						case 2:
							if (!fact[number]->get_count_furns())
							{
								cout << "\n--- ������ ���!\n\n";
								break;
							}
							cout << "������� ����� ������: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_furns() - 1))
							{
								if (cin.fail())
								{
									cout << "------������ �����! ������� �� �����!\n--������� �����: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------������ �����! ����� ������������ ����� ���������!\n--������� ������ �����: ";
								cin >> choice_worker;
							}
							fact[number]->delete_Furniture(choice_worker);
							break;
						case 3:
							if (!fact[number]->get_count_machines())
							{
								cout << "\n--- ����� ���!\n\n";
								break;
							}
							cout << "������� ����� ������: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_machines() - 1))
							{
								if (cin.fail())
								{
									cout << "------������ �����! ������� �� �����!\n--������� �����: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------������ �����! ����� ������������ ����� ���������!\n--������� ������ �����: ";
								cin >> choice_worker;
							}
							fact[number]->delete_Machine(choice_worker);
							break;
						case 4:
							break;
						}
						break;
					case 4:
						break;
					}
				}
				break;
			case 3:
				if (fact[0] == nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					cout << "������ ������:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--������� ����� �������: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------������ �����! ������� �� �����!\n--������� �����: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------������ �����! ����� ������������ �����!\n--������� ������ �����: ";
						cin >> number;
					}
					if (size == 1)
					{
						delete fact[0];
						delete[] fact;
						try
						{
							fact = new Factory * [1];
						}
						catch (std::bad_alloc&)
						{
							cout << "\n\n������������ ������!\n\n";
							exit(EXIT_FAILURE);
						}
						fact[0] = nullptr;
					}
					else
					{
						Factory** for_realloc = nullptr;
						try
						{
							for_realloc = new Factory * [size];
						}
						catch (std::bad_alloc&)
						{
							cout << "\n\n������������ ������!\n\n";
							exit(EXIT_FAILURE);
						}
						delete fact[number];
						for (int i = 0; i < number; i++)
							for_realloc[i] = fact[i];
						for (int i = number + 1; i < size; i++)
							for_realloc[i - 1] = fact[i];
						for_realloc[size - 1] = nullptr;
						delete[] fact;
						fact = for_realloc;
					}
					cout << "\n\n������� �������!\n\n";
				}
				break;
			case 4:
				if(fact[0]==nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					for (int i = 0; fact[i] != nullptr; i++)
						cout << i << " - " << fact[i]->get_name() << "\n";
				}
				break;
			case 5:
				if (fact[0] == nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
					cout << fact;
				break;
			case 6:
				if(fact[0]==nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					cout << "������� �������� ����� (���� ��� ��� - �� ����� ������): ";
					cin >> str;
					fout.open(str.c_str(), std::ios_base::out | std::ios_base::app);
					if (!fout.is_open())
						cout << "\n--- �� ������� ������� ����!\n\n";
					else
					{
						fout << fact;
						cout << "\n\n������ ������� ���������!\n\n";
					}
					fout.clear();
					fout.close();
				}
				break;
			case 7:
				cout << "������� �������� �����: ";
				cin >> str;
				fin.open(str.c_str());
				if (!fin.is_open())
					cout << "\n--- ������ ����� ���!\n\n";
				else
				{
					fin>>fact;
					cout << "\n\n������ ������� �������!\n\n";
				}
				fin.clear();
				fin.close();
				break;
			case 8:
				if (fact[0] == nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					cout << "������ ������:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--������� ����� �������: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------������ �����! ������� �� �����!\n--������� �����: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------������ �����! ����� ������������ �����!\n--������� ������ �����: ";
						cin >> number;
					}
					int res = fact[number]->compare_gabarits();
					if (res != -1)
					{
						cout << "\n\n����� ������� ������:\n";
						fact[number]->show_fur(res);
					}
					else
						cout << "\n\n��� ������!\n";
				}
				break;
			case 9:
				if (fact[0] == nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					cout << "������ ������:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--������� ����� �������: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------������ �����! ������� �� �����!\n--������� �����: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------������ �����! ����� ������������ �����!\n--������� ������ �����: ";
						cin >> number;
					}
					int res = fact[number]->compare_gos_numbers();
					if (res != -1)
					{
						cout << "\n\n����� ������� ����� ������:\n";
						fact[number]->show_mach(res);
					}
					else
						cout << "\n\n��� �����!\n";
				}
				break;
			case 10:
				if (fact[0] == nullptr)
					cout << "\n--- ������ ���!\n\n";
				else
				{
					cout << "������ ������:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--������� ����� �������: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------������ �����! ������� �� �����!\n--������� �����: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------������ �����! ����� ������������ �����!\n--������� ������ �����: ";
						cin >> number;
					}
					int res = fact[number]->compare_salaries();
					if (res != -1)
					{
						cout << "\n\n����� ������� ��������:\n";
						fact[number]->show_work(res);
					}
					else
						cout << "\n\n��� ����������!\n";
				}
				break;
			case 11:
				for (int i = 0; fact[i] != nullptr; i++)
					delete fact[i];
				delete[] fact;
				cout << "\n\n��������� ���������\n";
				goto OUT;
		}
	}
OUT:;
	return 0;
}