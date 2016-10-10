//#include "SeqQueueNCircle.h"
#include "SeqQueueCircle.h"
#include "LinkedQueueClass.h"
#include "CircleLinkedQueue.h"

int main()
{
	CircleLinkedQueue<int> sq;
	sq.EnQueue(256); sq.EnQueue(25246); sq.EnQueue(25); sq.EnQueue(456);
	for (int i = 1; i <= 1000; i++)
	{
		sq.EnQueue((i + 1)*2);
	}
	int e;
	int k = 1;
	while (!sq.IsQueueEmpty())
	{

		sq.Dequeue(e);
		cout << e << " ";
		if (0 == k%5)cout << endl;
		k++;
		
	}

	system("pause");
	return 0;
}



int maind()
{
	LinkedQueueClass<int> sq;
	sq.EnQueue(256); sq.EnQueue(25246); sq.EnQueue(25); sq.EnQueue(456);
	for (int i = 1; i <= 10; i++)
	{
		sq.EnQueue((i+1)*i*i);
	}
	int e;
	while (!sq.IsQueueEmpty())
	{
		
		sq.Dequeue(e);
		cout << e << " ";

	}

	system("pause");
	return 0;
}


int main32424()
{

	SeqQueueCircle<int> sq;
	sq.EnQueue(256); sq.EnQueue(25246); sq.EnQueue(25); sq.EnQueue(456);
	cout << sq.GetLength() << endl;
	while (!sq.IsQueueEmpty())
	{
		int e;
		sq.Dequeue(e);
		cout << e << " ";

	}
	system("pause");
	return 0;
}

//int main1()
//{
//
//	SeqQueueNCircle<int> sq;
//	sq.EnQueue(256); sq.EnQueue(25246); sq.EnQueue(25); sq.EnQueue(456);
//	cout << sq.GetLength() << endl;
//	while (!sq.IsQueueEmpty())
//	{
//		int e;
//		sq.Dequeue(e);
//		cout << e << " ";
//
//	}
//	system("pause");
//	return 0;
//}

