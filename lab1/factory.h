#ifndef FACTORY_H_
#define FACTORY_H_
#include "furniture.h"
#include "machine.h"
#include "worker.h"
class Factory
{
private:
	Worker* work_mas;
	Furniture* fur_mas;
	Machine* mach_mas;
};
#endif
