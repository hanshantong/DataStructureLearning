#include "GraphClass.h"
#include <stdlib.h>
int main()
{
	int a[][4] = { { 0, 1, 1, 65535 }, { 65535, 1, 0, 1 }, { 65535, 1, 0, 1 }, {1,1,65535,0} };
	int b[][4] = { { 0, 15, 6, 65535 }, { 65535, 4, 0, 2 }, { 65535, 18, 0, 9 }, { 10, 21, 65535, 0 } };
	GraphClass<int> gc;
	gc.CreateMGraph(a, 4, 8);
	gc.DisplayMGraph();

	gc.CreateALGraph(b, 4, 8);
	gc.DisplayALGraph();

	system("pause");
	return 0;
}