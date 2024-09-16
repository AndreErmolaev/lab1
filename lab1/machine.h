#ifndef MACHINE_H_
#define MACHINE_H_
#include "Base.h"
class Machine:public Base
{
private:
	long long number_;
	int price_;
	char* model_;
	char* make_;
public:
	class bad_mach : public bad
	{
	public:
		bad_mach(const char* field_name, long long field_mean) : bad(field_name, field_mean) { }
		const char* what() const override { return "---- ИСКЛЮЧЕНИЕ! Недопустимое значение для числового поля класса Machine!\n"; }
	};
	Machine(long long n, int c, const char* mod, const char* mak);
	Machine();
	Machine(const Machine&);
	~Machine();
	void set_number(long long);
	void set_price(int);
	void set_model(const char*);
	void set_make(const char*);
	long long get_number() const;
	const char* get_model() const;
	const char* get_make() const;
	Machine& operator=(const Machine&);
	bool operator==(const Machine&) const;    //Для сравнения номеров
	bool operator>(const Machine&) const;	  //Для сравнения номеров
public:
	void show() const override;
	int compare_money(const Base&) const override;
	int get_money() const override;
};
inline void Machine::set_number(long long i) { if (i <= 0)throw bad_mach("number", i); number_ = i; }
inline void Machine::set_price(int i) { if (i <= 0)throw bad_mach("price", i); price_ = i; }
inline long long Machine::get_number() const { return number_; }
inline const char* Machine::get_model() const { return model_; }
inline const char* Machine::get_make() const { return make_; }
#endif
