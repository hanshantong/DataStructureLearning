#include <iostream>
using namespace std;

struct Child {
	int no;
	Child *next;
};


class Joseph {
	int n, m;
	Child *h;
public:
	Joseph(){}
	Joseph(int n, int m) {
		this->n = n;
		this->m = m;

		Child *p;
		h = new Child();
		h->no = 1;
		p = h;
		for (int i = 2; i <= n; i++) {
			Child *s = new Child();
			s->no = i;
			p->next = s;
			p = s;
		}
		p->next = h;
	}

	~Joseph(){}

	void JosephSequence() {
		int i = 0;
		int j = 1;
		Child *p = h;
		Child *q;
		for (i = 1; i <= n; i++)
		{
			while (j < m-1)
			{
				j++;
				p = p->next;
			}
			q = p->next;
			cout << q->no << " ";
			p->next = q->next;
			delete q;
			p = p->next;
			j = 1;


		}

	}


};

int main()
{

	Joseph s(4, 5);
	s.JosephSequence();
	cout << endl;

	system("pause");
	return 0;
}