#include <iostream>
using namespace std;

#define MAXR (100)
#define MAXC (3)
#define MAXSIZE (256)

template <typename T>
struct TupNode
{
	int rowIndex;
	int colIndex;
	T val;
};


template <typename T>
class SMatrixClass
{
	int rowNums;
	int colNums;
	int nums;
	TupNode<T> *data;

public:
	SMatrixClass();
	~SMatrixClass();
	void CreateTSMatrix(T A[][MAXC], int m, int n);
	bool SetValue(int i,int j,T x);
	bool GetValue(int i, int j, T &x);
	void DispMatrix();
	void Transpose(SMatrixClass &s);
	friend bool MatAdd(SMatrixClass &s1, SMatrixClass &s2, SMatrixClass &s3);
};

int main()
{
	SMatrixClass<int> sm,sm2;
	int a[4][3] = { {1,0,2}, {0,0,12}, {0,0,0}, {286,0,0} };
	sm.CreateTSMatrix(a, 4, 3);
	sm.DispMatrix();

	/*sm.SetValue(0, 1,1000);
	sm.DispMatrix();*/
	int e;
	
	if (sm.GetValue(1, 2, e))
		cout << endl << e << endl;


	sm.Transpose(sm2);
	sm2.DispMatrix();
	system("pause");
	return 0;
}



//template <typename T>
//bool MatAdd(SMatrixClass &s1, SMatrixClass &s2, SMatrixClass &s3)
//{
//	if (s1.rowNums != s2.rowNums || s1.colNums != s2.colNums)return false;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while (i < s1.nums && j < s2.nums)
//	{
//		if (s1.data[i].rowIndex == s2.data[j].rowIndex)
//		{
//			if (s1.data[i].colIndex == s2.data[j].colIndex)
//			{
//				s3.data[k].val = s1.data[i].val + s2.data[j].val;
//				k++;
//
//			}
//		}
//	}
//}


template <typename T>
void SMatrixClass<T>::Transpose(SMatrixClass &s)
{
	s.rowNums = colNums;
	s.colNums = rowNums;
	s.nums = nums;
	int k = 0;
	if (0 != nums)
	{
		for (int i = 0; i < colNums; i++)
			for (int j = 0; j < nums; j++)
			{
				if (data[j].colIndex == i)
				{
					s.data[k].val = data[j].val;
					s.data[k].rowIndex = data[j].colIndex;
					s.data[k].colIndex = data[j].rowIndex;
					k++;
				}
			}
	}
}





template <typename T>
bool SMatrixClass<T>::GetValue(int i, int j, T &x)
{
	if (i < 0 || i >= rowNums || j < 0 || j > colNums)return false;
	int k = 0;
	while (k < nums && i > data[k].rowIndex)k++;
	while (k < nums && i == data[k].rowIndex && j > data[k].colIndex)k++;
	if (i == data[k].rowIndex && j == data[k].colIndex)
	{
		x = data[k].val;
		return true;
	}
	return false;
}


template <typename T>
bool SMatrixClass<T>::SetValue(int i, int j, T x)
{
	if (i < 0 || i >= rowNums || j < 0 || j >= colNums)return false;
	int k = 0;
	while (k < nums && i > data[k].rowIndex)k++;
	while (k < nums && i == data[k].rowIndex && j > data[k].colIndex)k++;
	if (data[k].rowIndex == i && data[k].colIndex == j)
	{
		data[k].val = x;
		
	}
	else
	{
		for (int t = nums - 1; t >= k; t--)
		{
			data[t + 1].val = data[t].val;
			data[t + 1].rowIndex = data[t].rowIndex;
			data[t + 1].colIndex = data[t].colIndex;
		}
		data[k].rowIndex = i;
		data[k].colIndex = j;
		data[k].val = x;
		nums++;
		return true;
	}
}


template <typename T>
void SMatrixClass<T>::DispMatrix()
{
	int i = 0;
	if (nums <= 0)return;
	cout << rowNums << "行," << colNums << "列." << "总元素=" << nums << endl;
	for (i = 0; i < nums; i++)
	{
		cout << "(" << data[i].rowIndex << "," << data[i].colIndex << "," << data[i].val << "),";

	}
}


template <typename T>
SMatrixClass<T>::SMatrixClass()
{
	nums = 0;
	data = new TupNode<T>[MAXSIZE];
}


template <typename T>
SMatrixClass<T>::~SMatrixClass()
{
	delete[] data;
}


template <typename T>
void SMatrixClass<T>::CreateTSMatrix(T A[][MAXC], int m, int n)
{
	rowNums = m; colNums = n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (0 != A[i][j])
			{
				data[nums].rowIndex = i;
				data[nums].colIndex = j;
				data[nums].val = A[i][j];
				nums++;
			}
		}





}