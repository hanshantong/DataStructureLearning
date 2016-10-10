#pragma once
#include <iostream>
using namespace std;
#define MAX_SIZE (256)
#include <string>

class SeqString
{
	char *data;
	int length;
public:
	SeqString();
	~SeqString();
	SeqString& operator =(const char *str);
	SeqString& operator = (SeqString &t);
	SeqString& operator + (SeqString &t);


	int GetLength();
	SeqString& SubString(int i, int j);
	SeqString& InsertString(int i, SeqString &s);
	SeqString& DelString(int i, int j);
	SeqString& ReplaceString(int i, int j, SeqString &s);
	void Display();
	bool isEqual(SeqString &s);
	int StrCmp(SeqString &s);
	int Match(SeqString &s);
	friend ostream& operator << (ostream &output,SeqString &s);
	friend istream& operator >> (istream &output, SeqString &s);
	friend void GetNext(, int next[])
};


int SeqString::Match(SeqString &s)
{
	int i = 0, j = 0;
	while (i < length && j < s.length)
	{
		if (data[i] == s.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= s.length)return (i - s.length);
	else return -1;
}


int SeqString::StrCmp(SeqString &s)
{
	int commonlen;
	if (length < s.length)commonlen = length;
	else commonlen = s.length;
	for (int i = 0; i < commonlen; i++)
	{
		if (data[i] > s.data[i])return 1;
		else if (data[i] < s.data[i])return -1;
		else if (data[i] == s.data[i])continue;
	}

	if (length == s.length)return 0;
	else if (length > s.length)return 1;
	else return -1;

}


bool SeqString::isEqual(SeqString &s)
{
	if (s.length != length)return false;
	for (int i = 0; i < s.length; i++)
	{
		if (data[i] == s.data[i])continue;
		else
		{
			return false;
		}
	}
	return true;
}


SeqString& SeqString::ReplaceString(int i, int j, SeqString &s)
{
	static SeqString ss;
	if (i < 1 || i + j - 1 > length)return ss;
	int k = 0;
	for (k = 0; k < i - 1; k++)
		ss.data[k] = data[k];
	for (k = 0; k < s.length; k++)
		ss.data[k+i-1] = s.data[k];
	for (k = i + j - 1; k < length; k++)
		ss.data[s.length + k - j] = data[k];

	ss.length = s.length + length - j;

	return ss;



}


SeqString& SeqString::DelString(int i, int j)
{
	static SeqString ss;
	if (i < 1 || i > length || (i + j - 1) > length)return ss;
	for (int k = 0; k < i-1; k++)
	{
		ss.data[k] = data[k];
	}

	for (int k = i + j - 1; k < length; k++)
	{
		ss.data[k - j] = data[k];
	}
	ss.length = length - j;
	return ss;



}



SeqString& SeqString::InsertString(int i, SeqString &s)
{
	static SeqString ss;
	if (i < 1 || i > length)return ss;
	int j = 0;
	for (j = 0; j < i - 1; j++)
	{
		ss.data[j] = data[j];
	}

	for (j = 0; j < s.length; j++)
	{
		ss.data[j + i - 1] = s.data[j];
	}
	
	for (j = i-1; j < length; j++)
	{
		ss.data[s.length + j] = data[j];
	}

	ss.length = length + s.length;
	return ss;
}



SeqString& SeqString::SubString(int i, int j)
{
	static SeqString seq;
	if (i < 1 || i > length || j < 0 || (i + j - 1) > length)
		return seq;
	for (int k = i - 1; k < i + j - 1; k++)
		seq.data[k-i+1] = data[k];
	seq.length = j;
	return seq;
}



int SeqString::GetLength()
{
	return length;
}


void SeqString::Display()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i];
	}
	cout << endl;
}

SeqString::SeqString()
{
	data = new char[MAX_SIZE];
	length = 0;
}

SeqString::~SeqString()
{
	delete[] data;
}


SeqString& SeqString::operator = (const char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		data[i] = str[i];

	}
	length = i;
	return *this;
}


SeqString& SeqString::operator = (SeqString &t)
{
	for (int i = 0; i < t.length; i++)
	{
		data[i] = t.data[i];
	}
	length = t.length;
	return *this;
}


SeqString& SeqString::operator + (SeqString &t)
{
	static SeqString ss;
	int i;
	for (i = 0; i < length; i++)
	{
		ss.data[i] = data[i];
	}
	
	for (int j = 0; j < t.length; j++)
	{
		ss.data[j + i] = t.data[j];
	}
	ss.length = length + t.length;
	return ss;
}


ostream& operator << (ostream &output, SeqString &s)
{
	//output << s.data << endl;
	for (int i = 0; i < s.length; i++)
	{
		output << s.data[i];
	}
	return output;
}

istream& operator >> (istream &input, SeqString &s)
{
	string str;
	input >> str;
	//char ch;
	//input >> ch;
	
	int i = 0;
	while (i < str.length())
	{
		 s.data[i] = str[i];
		i++;
		
	}
	s.length = str.length();
	
	return input;
}



int main()
{
	SeqString s1, s2,s3,s4,s5;
	s1 = "adbcdefghjr", s2 = "cdefg"; s3 = "1234567890";
	
	cout << s1.Match(s2) << endl;



	/*cout << s1 << endl << s2 << endl << s3 << endl;

	s4 = s3.ReplaceString(3, 4, s1);
	cout << s4 << endl;
	if (s1.isEqual(s2))cout << "s1等于s2\n";
	else cout << "s1不等于s2\n";

	cout << s1.StrCmp(s2) << endl;*/


	/*s3 = s1.InsertString(1, s2);
	cout << s3 << endl;
	s5 = s3.DelString(3, 4);
	cout << s5 << endl;*/
	/*s3 = s1 + s2;
	cout << s3 << endl;*/
	/*cin >> s4;
	cout << s4;*/
	/*s4 = s3.SubString(3,4);
	cout << s4 << endl;*/
	system("pause");
	return 0;
}