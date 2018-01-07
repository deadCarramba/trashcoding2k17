#include<iostream>
#include<vector>

using namespace std;
class List
{
public:
	List *next;
	int data;
	List(int d,List *node=NULL) :data(d) 
	{
		next = node;
	}

};

class Stack_arr
{
	vector<int> arr;
	
public:
	Stack_arr()
	{
	}
	Stack_arr(int d)
	{
		arr.push_back(d);
	}

	void push(int d)
	{
		arr.push_back(d);
	}

	int pop()
	{
		if (arr.size() != 0)
		{
			int res = arr[arr.size() - 1];
			arr.pop_back();
			return res;
		}
		return NULL;
	}
	void print()
	{
		for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
		{
			cout << *it << " ";
		}
	}
};

class Stack_list
{
	List *top;
public:
	Stack_list()
	{
		top = NULL;
	}

	void push(int data_)
	{
		List *node = new List(data_,top);
		top = node;
	}
	int pop()
	{
		List *node = top;
		int res = top->data;
		top = top->next;
		delete node;
		return res;
	}
};

class Q_arr
{
	vector<int> arr;
public:
	Q_arr()
	{
	}
	Q_arr(int d)
	{
		arr.push_back(d);
	}

	void push(int d)
	{
		arr.push_back(d);
	}

	int pop()
	{
		if (arr.size() != 0)
		{
			int res = arr[0];
			arr.erase(arr.begin());
			return res;
		}
		return NULL;
	}
	void print()
	{
		for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
		{
			cout << *it << " ";
		}
	}
};

class Q_list
{
	List *front, *end;
	public:
		Q_list(int data)
		{
			front = new List(data);
			end = front;
		}
		void push(int a)
		{
			end->next = new List(a);
			end = end->next;
		}
		int pop()
		{
			if (front == NULL)
				return NULL;
			int a = front->data;
			List *node = front->next;
			delete front;
			front = node;
			return a;
		}
};

int main()
{
	Stack_arr st;
	st.push(10);
	st.pop();
	Stack_list stl;
	stl.push(0);
	stl.pop();
	Q_list a(10);
	a.push(1);
	a.pop();
	Q_arr que;
	que.push(9);
	que.pop();
}