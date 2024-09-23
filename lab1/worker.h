#ifndef WORKER_H_
#define WORKER_H_
#include "Base.h"
class Worker:public Base
{
private:
	int salary_;
	long long phone_;
	char* name_;
	char* patronymic_;
	char* surname_;
	char* address_;
	char* post_;
public:
	class bad_work : public bad
	{
	public:
		bad_work(const char* field_name, long long field_mean) : bad(field_name, field_mean) { }
		const char* what() const override { return "---- ИСКЛЮЧЕНИЕ! Недопустимое значение для числового поля класса Worker!\n"; }
	};
	Worker(int s, long long p, const char* n, const char* pat, const char* sur, const char* a, const char* post);
	Worker();
	Worker(const Worker&);
	~Worker();
	void set_salary(int);
	void set_phone(long);
	void set_name(const char*);
	void set_patr(const char*);
	void set_surname(const char*);
	void set_address(const char*);
	void set_post(const char*);
	long long get_phone() const;
	const char* get_name() const;
	const char* get_patr() const;
	const char* get_surname() const;
	const char* get_address() const;
	const char* get_post() const;
	Worker& operator=(const Worker&);
	bool operator==(const Worker&) const;     //Для сравнения зарплат
	bool operator>(const Worker&) const;	  //Для сравнения зарплат
public:
	void show() const override;
	int get_money() const override;
};
inline void Worker::set_salary(int i) { if (i <= 0)throw bad_work("salary", i); salary_ = i; }
inline void Worker::set_phone(long i) { if (i <= 0)throw bad_work("phone", i); phone_ = i; }
inline long long Worker::get_phone() const { return phone_; }
inline const char* Worker::get_name() const { return name_; }
inline const char* Worker::get_patr() const { return patronymic_; }
inline const char* Worker::get_surname() const { return surname_; }
inline const char* Worker::get_address() const { return address_; }
inline const char* Worker::get_post() const { return post_; }
#endif
