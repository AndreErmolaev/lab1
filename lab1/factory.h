#ifndef FACTORY_H_
#define FACTORY_H_
#include "furniture.h"
#include "machine.h"
#include "worker.h"
#include <fstream>
class Factory
{
private:
	char* name;
	int count_workers;
	int count_furnitures;
	int count_machines;
	Worker** work_mas;
	Furniture** fur_mas;
	Machine** mach_mas;
public:
	class bad_fact : public std::exception
	{
	private:
		enum{MAX_NAME_CLASS = 10};
		int index;
		char name_class[MAX_NAME_CLASS];
	public:
		bad_fact(const char* n_class, int ind) { index = ind; std::strcpy(name_class, n_class); }
		inline int get_index() const { return index; }
		inline const char* get_class() const {return name_class; }
		const char* what() const override { return "---- ИСКЛЮЧЕНИЕ! Значение номера выходит за диапазон!"; }
	};
	Factory();
	Factory(const char*);
	Factory(const Factory&);
	~Factory();
	Factory& operator=(const Factory&);
	void add_Worker(Worker&);
	void add_Furniture(Furniture&);
	void add_Machine(Machine&);
	void delete_Worker(int);
	void delete_Furniture(int);
	void delete_Machine(int);
	void set_name(const char*);
	const char* get_name() const;
	int get_count_workers() const;
	int get_count_furns() const;
	int get_count_machines() const;
	//void show_work() const;
	//void show_fur() const;
	//void show_mach() const;
	//void show() const;
	//friend std::istream& operator>>(std::istream&, Factory**);
	friend std::ostream& operator<<(std::ostream&, Factory**);
	friend Factory** scan(std::istream&, Factory**);
};
inline const char* Factory::get_name() const { return name; }
inline int Factory::get_count_workers() const { return count_workers; }
inline int Factory::get_count_furns() const { return count_furnitures; }
inline int Factory::get_count_machines() const { return count_machines; }
std::ostream& operator<<(std::ostream&,Factory**);
Factory** scan(std::istream&, Factory**);
//std::istream& operator>>(std::istream&, Factory**);
//void Factory::show_work() const {};
#endif