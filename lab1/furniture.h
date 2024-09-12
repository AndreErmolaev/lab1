#ifndef FURNITURE_H_
#define FURNITURE_H_
#include "Base.h"
class Furniture:public Base
{
private:
	int height_;
	int width_;
	int depth_;
	int cost_;
	char* color_;
	char* material_;
	char* type_fur_;
public:
	class bad_fur : public bad
	{
	public:
		bad_fur(const char* field_name, int field_mean) : bad(field_name, field_mean) { }
		const char* what() const override { return "Недопустимое значение для числового поля класса Furniture!\n"; }
	};
	Furniture(int h, int w, int d, int c, const char* col, const char* m, const char* t);
	Furniture();
	Furniture(const Furniture&);
	~Furniture();
	Furniture& operator=(const Furniture&);
	bool operator==(const Furniture&) const;    //Для сравнения габаритов
	bool operator>(const Furniture&) const;     //Для сравнения габаритов
	void set_height(int);
	void set_width(int);
	void set_depth(int);
	void set_cost(int);
	void set_color(const char*);
	void set_material(const char*);
	void set_type(const char*);
	int get_height() const;
	int get_width() const;
	int get_depth() const;
	const char* get_color() const;
	const char* get_material() const;
	const char* get_type() const;
public:
	void show() const override;
	int compare_money(const Base&) const override;
	int get_money() const override;
};
inline void Furniture::set_height(int i) { if (i <= 0)throw bad_fur("height",i); height_ = i; }
inline void Furniture::set_width(int i) { if (i <= 0)throw bad_fur("width", i); width_ = i; }
inline void Furniture::set_depth(int i) { if (i <= 0)throw bad_fur("depth", i); depth_ = i; }
inline void Furniture::set_cost(int i) { if (i <= 0)throw bad_fur("cost", i); cost_ = i; }
inline int Furniture::get_height() const { return height_; }
inline int Furniture::get_width() const { return width_; }
inline int Furniture::get_depth() const{ return depth_; }
inline const char* Furniture::get_color() const { return color_; }
inline const char* Furniture::get_material() const { return material_; }
inline const char* Furniture::get_type() const { return type_fur_; }
#endif