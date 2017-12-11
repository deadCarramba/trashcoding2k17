#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Node
{
	friend class PQ;
	string data;
	uint32_t key;
public:
	Node() {}
	Node(uint32_t k, string d):key(k),data(d) {}
};

class PQ
{
	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void heapify(vector<Node>& arr, int index)
	{
		int maxI;
		int left = 2 * index + 1;
		int right = left + 1;
		if (left < arr.size() && arr[left].key > arr[index].key)
			maxI = left;
		else
			maxI = index;
		if (right < arr.size() && arr[right].key > arr[maxI].key)
			maxI = right;
		if (index != maxI)
		{
			swap(arr[index], arr[maxI]);
			heapify(arr,maxI);
		}
	}
public:
	void build_heap(vector<Node>& arr)
	{
		if (arr.size() > 0)
		{
			for (int i = arr.size() - 1; i >= 0; i--)
				heapify(arr, i);
		}
	}

	int maximum(vector<Node>& arr)
	{
		if (arr.size() > 0)
			return arr.front().key;
		else
			return -1;
	}

	Node extract_max(vector<Node>& arr)
	{
		if (arr.size() == 0)
			return Node(-1,"EMPTY_QUEUE");
		Node max = arr[0];
		arr[0] = arr[arr.size() - 1];
		arr.resize(arr.size() - 1);
		heapify(arr, 0);
		return max;
	}

	void print_heap(vector<Node>& arr)
	{
		if (arr.size() > 0)
		{
			for (int i = 0; i < arr.size(); i++)
				cout << arr[i].data << "(" << arr[i].key << ")" << " ";
			cout << endl;
		}
	}

	void up(vector<Node>& arr, int index, Node &el)
	{
		arr[index] = el;
		while (index > 0 && arr[parent(index)].key < arr[index].key)
		{
			swap(arr[index], arr[parent(index)]);
			index = parent(index);
		}
	}

	void insert(vector<Node>& arr, Node el)
	{
		arr.resize(arr.size() + 1);
		up(arr, arr.size() - 1, el);
	}
};

void test0() //пустая очередь
{
	vector<Node> nodes;

	Node n(7, "jj");

	PQ pq;

	pq.build_heap(nodes);
	cout << (uint32_t)pq.maximum(nodes) << endl;
	pq.print_heap(nodes);
	pq.extract_max(nodes);
	pq.insert(nodes, n);
	pq.print_heap(nodes);
}

void test1()  //просто данные
{
	vector<Node> nodes;

	Node n(7, "jj");
	nodes.emplace_back(0, "abc");
	nodes.emplace_back(4, "efg");
	nodes.emplace_back(-1, "abc");

	PQ pq;

	pq.build_heap(nodes);
	cout << (uint32_t)pq.maximum(nodes) << endl;
	pq.print_heap(nodes);
	pq.extract_max(nodes);
	pq.insert(nodes, n);
	pq.print_heap(nodes);
}

void main()
{
	test1();
}