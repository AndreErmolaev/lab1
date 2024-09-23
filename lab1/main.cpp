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
		cout << "\n\nНедостаточно памяти!\n\n";
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
		cout << "\nВыберите действие:\n";
		cout << "1 - Добавить фабрику\n";
		cout << "2 - Изменить данные одной из фабрик\n";
		cout << "3 - Удалить фабрику\n";
		cout << "4 - Вывести список фабрик\n";
		cout << "5 - Вывести сведения обо всех фабриках\n";
		cout << "6 - Сохранить сведения о фабриках в файл\n";
		cout << "7 - Считать сведения о фабриках из файла\n";
		cout << "8 - Найти самую большую мебель фабрики\n";
		cout << "9 - Найти самый большой номер машины фабрики \n";
		cout << "10 - Найти самую большую зарплату работника фабрики \n";
		cout << "11 - Завершить работу программы\n";
		cout<<"Ввод: ";
		int choice_action = 0;
		cin >> choice_action;
		while (cin.fail() || (choice_action<1 || choice_action>11))
		{
			if(cin.fail())
			{
				cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			else
				cout << "------Ошибка ввода! Введён недопустимый номер действия!\n--Введите номер: ";
			cin >> choice_action;
		}
		switch(choice_action)
		{
			case 1:
				cout << "Введите название фабрики: ";
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
					cout << "\n\nНедостаточно памяти!\n\n";
					exit(EXIT_FAILURE);
				}
				for_realloc[size + 1] = nullptr;
				delete[] fact;
				fact = for_realloc;
				size = 0;
				cout << "\n\nФабрика добавлена!\n\n";
				break;
			case 2:
				if (fact[0] == nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					cout << "Список фабрик:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size+=1;
					}
					cout << "\n--Введите номер фабрики: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size-1))
					{
						if(cin.fail())
						{
							cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------Ошибка ввода! Введён недопустимый номер!\n--Введите другой номер: ";
						cin >> number;
					}
					fact[number]->show();
					cout << "\n\nВыберите одно из действий:\n";
					cout << "1 - Добавить данные\n";
					cout << "2 - Изменить данные\n";
					cout << "3 - Удалить данные\n";
					cout << "4 - Вернуться в главное меню\n";
					cout << "Ввод: ";
					int action_with_fact = 0;
					cin >> action_with_fact;
					while (cin.fail() ||(action_with_fact<1 || action_with_fact>4))
					{
						if(cin.fail())
						{
							cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------Ошибка ввода! Введён недопустимый номер действия!\n--Введите номер: ";

						cin >> action_with_fact;
					}
					switch (action_with_fact)
					{
					case 1:
						cout << "	Выберите, что нужно добавить:\n";
						cout << "	1 - Данные о работнике\n";
						cout << "	2 - Данные о мебели\n";
						cout << "	3 - Данные о машине\n";
						cout << "	4 - Вернуться в главное меню\n";
						cout << "Ввод: ";
						cin >> choice_data;
						while (cin.fail() || (choice_data < 1 || choice_data>4))
						{
							if (cin.fail())
							{
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
							}
							else
								cout << "------Ошибка ввода! Введён недопустимый номер действия!\n--Введите номер действия: ";
							cin >> choice_data;
						}
						if (choice_data == 1)
						{
							work = new Worker;
							if (cin.peek() == '\n')
								cin.get();
							cout << "Введите фамилию: ";
							std::getline(cin, str);
							work->set_surname(str.c_str());
							cout << "Введите имя: ";
							std::getline(cin, str);
							work->set_name(str.c_str());
							cout << "Введите отчество: ";
							std::getline(cin, str);
							work->set_patr(str.c_str());
							cout << "Введите должность: ";
							std::getline(cin, str);
							work->set_post(str.c_str());
							cout << "Введите адрес (без пробелов): ";
							std::getline(cin, str);
							work->set_address(str.c_str());
							BACK_bad_salary:;
							cout << "Введите зарплату: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << w.get_field_name() << "; значение: " << w.get_field_mean() << endl << endl;
								goto BACK_bad_salary;
							}
							BACK_bad_phone:;
							cout << "Введите телефон: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << w.get_field_name() << "; значение: " << w.get_field_mean() << endl << endl;
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
							cout << "Введите материал: ";
							std::getline(cin, str);
							fur->set_material(str.c_str());
							cout << "Введите тип: ";
							std::getline(cin, str);
							fur->set_type(str.c_str());
							cout << "Введите цвет: ";
							std::getline(cin, str);
							fur->set_color(str.c_str());
							BACK_bad_width:;
							cout << "Введите ширину: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_width;
							}
							BACK_bad_height:;
							cout << "Введите высоту: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_height;
							}
							BACK_bad_depth:;
							cout << "Введите глубину: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
								goto BACK_bad_depth;
							}
							BACK_bad_cost:;
							cout << "Введите стоимость: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
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
							cout << "Введите модель: ";
							std::getline(cin, str);
							mach->set_model(str.c_str());
							cout << "Введите марку: ";
							std::getline(cin, str);
							mach->set_make(str.c_str());
							BACK_bad_price:;
							cout << "Введите цену: ";
							cin >> for_enter;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << m.get_field_name() << "; значение: " << m.get_field_mean() << endl << endl;
								goto BACK_bad_price;
							}
							BACK_bad_gos:;
							cout << "Введите гос.номер: ";
							cin >> gos_number;
							while (cin.fail())
							{
								cin.clear();
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
								cout << "Поле: " << m.get_field_name() << "; значение: " << m.get_field_mean() << endl << endl;
								goto BACK_bad_gos;
							}
							if (cin.peek() == '\n')
								cin.get();
							fact[number]->add_Machine(mach);
							fact[number]->show_mach(fact[number]->get_count_machines() - 1);
						}
						break;
					case 2:
						cout << "	Выберите, что нужно изменить:\n";
						cout << "	1 - Данные о работниках\n";
						cout << "	2 - Данные о мебели\n";
						cout << "	3 - Данные о машинах\n";
						cout << "	4 - Вернуться в главное меню\n";
						cout << "Ввод: ";
						cin >> choice_data;
						while (cin.fail() || (choice_data<1 || choice_data>4))
						{
							if(cin.fail())
							{
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
							}
							else
								cout << "------Ошибка ввода! Введён недопустимый номер действия!\n--Введите номер действия: ";
							cin >> choice_data;
						}
						switch (choice_data)
						{
						case 1:
							if (!fact[number]->get_count_workers())
							{
								cout << "\n--- Работников нет!\n\n";
								break;
							}
							cout << "Выберите номер работника: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_workers()-1))
							{
								if(cin.fail())
								{
									cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------Ошибка ввода! Введён недопустимый номер работника!\n--Введите другой номер: ";
								cin >> choice_worker;
							}
							cout << "	Выберите, что конкретно нужно изменить:\n";
							cout << "	1 - Фамилию\n";
							cout << "	2 - Имя\n";
							cout << "	3 - Отчество\n";
							cout << "	4 - Телефон\n";
							cout << "	5 - Адрес\n";
							cout << "	6 - Зарплату\n";
							cout << "	7 - Должность\n";
							cout << "	8 - Вернуться в главное меню\n";
							cout << "Ввод (если нужно изменить несколько полей - вводите номера подряд без пробелов): ";
							cin >> choice_change;
							while (cin.fail())
							{
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
									cout << "Введите фамилию: ";
									std::getline(cin, str);
									fact[number]->set_surname(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 2)
								{
									cout << "Введите имя: ";
									std::getline(cin, str);
									fact[number]->set_name(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 3)
								{
									cout << "Введите отчество: ";
									std::getline(cin, str);
									fact[number]->set_patr(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 4)
								{
									BACK_bad_phone1:;
									cout << "Введите телефон: ";
									cin >> phone;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << w.get_field_name() << "; значение: " << w.get_field_mean() << endl << endl;
										goto BACK_bad_phone1;
									}
								}
								else if (choice_change % 8 == 5)
								{
									cout << "Введите адрес (без пробелов): ";
									std::getline(cin, str);
									fact[number]->set_address(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 6)
								{
									BACK_bad_salary1:;
									cout << "Введите зарплату: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << w.get_field_name() << "; значение: " << w.get_field_mean() << endl << endl;
										goto BACK_bad_salary1;
									}
								}
								else if (choice_change % 8 == 7)
								{
									cout << "Введите должность: ";
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
								cout << "\n--- Работников нет!\n\n";
								break;
							}
							cout << "Выберите номер мебели: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_furns()-1))
							{
								if(cin.fail())
								{
									cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------Ошибка ввода! Введён недопустимый номер мебели!\n--Введите другой номер: ";
								cin >> choice_worker;
							}
							cout << "	Выберите, что конкретно нужно изменить:\n";
							cout << "	1 - Высоту\n";
							cout << "	2 - Ширину\n";
							cout << "	3 - Глубину\n";
							cout << "	4 - Цену\n";
							cout << "	5 - Цвет\n";
							cout << "	6 - Материал\n";
							cout << "	7 - Тип\n";
							cout << "	8 - Вернуться в главное меню\n";
							cout << "Ввод (если нужно изменить несколько полей - вводите номера подряд без пробелов): ";
							cin >> choice_change;
							while (cin.fail())
							{
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
									cout << "Введите высоту: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_height1;
									}
								}
								else if (choice_change % 8 == 2)
								{
								BACK_bad_width1:;
									cout << "Введите ширину: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_width1;
									}
								}
								else if (choice_change % 8 == 3)
								{
								BACK_bad_depth1:;
									cout << "Введите глубину: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_depth1;
									}
								}
								else if (choice_change % 8 == 4)
								{
								BACK_bad_cost1:;
									cout << "Введите цену: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << f.get_field_name() << "; значение: " << f.get_field_mean() << endl << endl;
										goto BACK_bad_cost1;
									}
								}
								else if (choice_change % 8 == 5)
								{
									cout << "Цвет: ";
									std::getline(cin, str);
									fact[number]->set_color(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 6)
								{
									cout << "Материал: ";
									std::getline(cin, str);
									fact[number]->set_material(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 7)
								{
									cout << "Тип: ";
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
								cout << "\n--- Работников нет!\n\n";
								break;
							}
							cout << "Выберите номер машины: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_machines()-1))
							{
								if(cin.fail())
								{
									cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------Ошибка ввода! Введён недопустимый номер машины!\n--Введите другой номер: ";
								cin >> choice_worker;
							}
							cout << "	Выберите, что конкретно нужно изменить:\n";
							cout << "	1 - Гос.номер\n";
							cout << "	2 - Цена\n";
							cout << "	3 - Модель\n";
							cout << "	4 - Марка\n";
							cout << "	5 - Вернуться в главное меню\n";
							cout << "Ввод (если нужно изменить несколько полей - вводите номера подряд без пробелов): ";
							cin >> choice_change;
							while (cin.fail())
							{
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
									cout << "Введите гос.номер: ";
									cin >> gos_number;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << m.get_field_name() << "; значение: " << m.get_field_mean() << endl << endl;
										goto BACK_bad_gos1;
									}
								}
								else if (choice_change % 8 == 2)
								{
								BACK_bad_price1:;
									cout << "Введите цену: ";
									cin >> for_enter;
									while (cin.fail())
									{
										cin.clear();
										cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
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
										cout << "Поле: " << m.get_field_name() << "; значение: " << m.get_field_mean() << endl << endl;
										goto BACK_bad_price1;
									}
								}
								else if (choice_change % 8 == 3)
								{
									cout << "Введите модель: ";
									std::getline(cin,str);
									fact[number]->set_model(choice_worker, str.c_str());
								}
								else if (choice_change % 8 == 4)
								{
									cout << "Введите марку: ";
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
						cout << "	Выберите, что нужно удалить:\n";
						cout << "	1 - Данные о работнике\n";
						cout << "	2 - Данные о мебели\n";
						cout << "	3 - Данные о машине\n";
						cout << "	4 - Вернуться в главное меню\n";
						cout << "Ввод: ";
						cin >> choice_data;
						while (cin.fail() || (choice_data < 1 || choice_data>4))
						{
							if (cin.fail())
							{
								cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
								cin.clear();
								while (cin.get() != '\n')
									continue;
							}
							else
								cout << "------Ошибка ввода! Введён недопустимый номер действия!\n--Введите номер действия: ";
							cin >> choice_data;
						}
						switch (choice_data)
						{
						case 1:
							if (!fact[number]->get_count_workers())
							{
								cout << "\n--- Работников нет!\n\n";
								break;
							}
							cout << "Введите номер работника: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_workers() - 1))
							{
								if (cin.fail())
								{
									cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------Ошибка ввода! Введён недопустимый номер работника!\n--Введите другой номер: ";
								cin >> choice_worker;
							}
							fact[number]->delete_Worker(choice_worker);
							break;
						case 2:
							if (!fact[number]->get_count_furns())
							{
								cout << "\n--- Мебели нет!\n\n";
								break;
							}
							cout << "Введите номер мебели: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_furns() - 1))
							{
								if (cin.fail())
								{
									cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------Ошибка ввода! Введён недопустимый номер работника!\n--Введите другой номер: ";
								cin >> choice_worker;
							}
							fact[number]->delete_Furniture(choice_worker);
							break;
						case 3:
							if (!fact[number]->get_count_machines())
							{
								cout << "\n--- Машин нет!\n\n";
								break;
							}
							cout << "Введите номер машины: ";
							cin >> choice_worker;
							while (cin.fail() || (choice_worker<0 || choice_worker > fact[number]->get_count_machines() - 1))
							{
								if (cin.fail())
								{
									cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
									cin.clear();
									while (cin.get() != '\n')
										continue;
								}
								else
									cout << "------Ошибка ввода! Введён недопустимый номер работника!\n--Введите другой номер: ";
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
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					cout << "Список фабрик:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--Введите номер фабрики: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------Ошибка ввода! Введён недопустимый номер!\n--Введите другой номер: ";
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
							cout << "\n\nНедостаточно памяти!\n\n";
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
							cout << "\n\nНедостаточно памяти!\n\n";
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
					cout << "\n\nФабрика удалена!\n\n";
				}
				break;
			case 4:
				if(fact[0]==nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					for (int i = 0; fact[i] != nullptr; i++)
						cout << i << " - " << fact[i]->get_name() << "\n";
				}
				break;
			case 5:
				if (fact[0] == nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
					cout << fact;
				break;
			case 6:
				if(fact[0]==nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					cout << "Введите название файла (если его нет - он будет создан): ";
					cin >> str;
					fout.open(str.c_str(), std::ios_base::out | std::ios_base::app);
					if (!fout.is_open())
						cout << "\n--- Не удалось открыть файл!\n\n";
					else
					{
						fout << fact;
						cout << "\n\nДанные успешно сохранены!\n\n";
					}
					fout.clear();
					fout.close();
				}
				break;
			case 7:
				cout << "Введите название файла: ";
				cin >> str;
				fin.open(str.c_str());
				if (!fin.is_open())
					cout << "\n--- Такого файла нет!\n\n";
				else
				{
					fin>>fact;
					cout << "\n\nДанные успешно считаны!\n\n";
				}
				fin.clear();
				fin.close();
				break;
			case 8:
				if (fact[0] == nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					cout << "Список фабрик:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--Введите номер фабрики: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------Ошибка ввода! Введён недопустимый номер!\n--Введите другой номер: ";
						cin >> number;
					}
					int res = fact[number]->compare_gabarits();
					if (res != -1)
					{
						cout << "\n\nСамая большая мебель:\n";
						fact[number]->show_fur(res);
					}
					else
						cout << "\n\nНет мебели!\n";
				}
				break;
			case 9:
				if (fact[0] == nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					cout << "Список фабрик:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--Введите номер фабрики: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------Ошибка ввода! Введён недопустимый номер!\n--Введите другой номер: ";
						cin >> number;
					}
					int res = fact[number]->compare_gos_numbers();
					if (res != -1)
					{
						cout << "\n\nСамая большой номер машины:\n";
						fact[number]->show_mach(res);
					}
					else
						cout << "\n\nНет машин!\n";
				}
				break;
			case 10:
				if (fact[0] == nullptr)
					cout << "\n--- Фабрик нет!\n\n";
				else
				{
					cout << "Список фабрик:\n";
					int size = 0;
					for (int i = 0; fact[i] != nullptr; i++)
					{
						cout << i << " - " << fact[i]->get_name() << "\n";
						size += 1;
					}
					cout << "\n--Введите номер фабрики: ";
					int number = 0;
					cin >> number;
					while (cin.fail() || (number < 0 || number > size - 1))
					{
						if (cin.fail())
						{
							cout << "------Ошибка ввода! Введено не число!\n--Введите число: ";
							cin.clear();
							while (cin.get() != '\n')
								continue;
						}
						else
							cout << "------Ошибка ввода! Введён недопустимый номер!\n--Введите другой номер: ";
						cin >> number;
					}
					int res = fact[number]->compare_salaries();
					if (res != -1)
					{
						cout << "\n\nСамая большая зарплата:\n";
						fact[number]->show_work(res);
					}
					else
						cout << "\n\nНет работников!\n";
				}
				break;
			case 11:
				for (int i = 0; fact[i] != nullptr; i++)
					delete fact[i];
				delete[] fact;
				cout << "\n\nПрограмма завершена\n";
				goto OUT;
		}
	}
OUT:;
	return 0;
}