#ifndef FACTORY_H_
#define FACTORY_H_
#include "furniture.h"
#include "machine.h"
#include "worker.h"
#include <fstream>
#include <string>
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
	Factory();
	Factory(const char*);
	Factory(const Factory&);
	~Factory();
	Factory& operator=(const Factory&);
	void add_Worker(Worker*);
	void add_Furniture(Furniture*);
	void add_Machine(Machine*);
	void delete_Worker(int);
	void delete_Furniture(int);
	void delete_Machine(int);
	void set_name(const char*);
	const char* get_name() const;
	int get_count_workers() const;
	int get_count_furns() const;
	int get_count_machines() const;
	void show() const;
	friend std::ostream& operator<<(std::ostream&, Factory**);
	friend std::istream& operator>>(std::istream&, Factory**&);
	void set_height(int,int);
	void set_width(int,int);
	void set_depth(int,int);
	void set_cost(int,int);
	void set_color(int,const char*);
	void set_material(int,const char*);
	void set_type(int,const char*);
	int get_height(int) const;
	int get_width(int) const;
	int get_depth(int) const;
	const char* get_color(int) const;
	const char* get_material(int) const;
	const char* get_type(int) const;
	int get_money_fur(int) const;
	void show_fur(int) const;

	void set_number(int,long long);
	void set_price(int,int);
	void set_model(int,const char*);
	void set_make(int,const char*);
	long long get_number(int) const;
	const char* get_model(int) const;
	const char* get_make(int) const;
	void show_mach(int) const;
	int get_money_mach(int) const;

	void set_salary(int,int);
	void set_phone(int,long);
	void set_name(int,const char*);
	void set_patr(int,const char*);
	void set_surname(int,const char*);
	void set_address(int,const char*);
	void set_post(int,const char*);
	long long get_phone(int) const;
	const char* get_name(int) const;
	const char* get_patr(int) const;
	const char* get_surname(int) const;
	const char* get_address(int) const;
	const char* get_post(int) const;
	void show_work(int) const;
	int get_money_work(int) const;

	int compare_gabarits() const;
	int compare_gos_numbers() const;
	int compare_salaries() const;
};
inline const char* Factory::get_name() const { return name; }
inline int Factory::get_count_workers() const { return count_workers; }
inline int Factory::get_count_furns() const { return count_furnitures; }
inline int Factory::get_count_machines() const { return count_machines; }
std::ostream& operator<<(std::ostream&,Factory**);
std::istream& operator>>(std::istream&, Factory**&);
#endif