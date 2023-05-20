#include <iostream>
template <typename T>
class List
{
public:
	List();
	List(T* arr, int length);
	void push_front(T data);
	void push_back(T data);
	void insert();
	void pop_front();
	void pop_back();
	void pop();
	bool search(T data);
	void output();
	int length() { return size; }
	T& operator[](int index);
	void merge_sort() { head=sort(head); }
private:
	template <typename T>
	class Node
	{
	public:
		Node<T>* pnext;
		T data;
		Node(T data = 0 , Node<T>* pnext = nullptr) :pnext(pnext), data(data) {}
	};
	Node<T>* merge(Node<T>* a, Node<T>* b);
	Node<T>* sort(Node<T>* a);
	Node<T>* mid_point(Node<T>* a);
	Node<T>* head;
	int size;	

};



template<typename T>
List<T>::List()
{
	head = nullptr;
	size = 0;
};
template<typename T>
List<T>::List(T* arr, int length)
{
	size = length;
	head = new Node<T>(arr[0]);
	Node<T>* counter = head;
	for (int i = 1; i <= length - 1; i++)
	{
		counter->pnext = new Node<T>(arr[i]);
		counter = counter->pnext;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	if (size == 0)
	{
		head = new Node<T>(data);
	}
	else
	{
		head = new Node<T>(data, head);
	}
	size++;
}
template<typename T>
void List<T>::push_back(T data)
{
	if (size == 0)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* counter = head;
		while (counter->pnext != nullptr)
		{
			counter = counter->pnext;
		}
		counter->pnext = new Node<T>(data);
	}
	size++;
}
template<typename T>
void List<T>::insert()
{
	int index; T data;
	std::cout << "Please enter index`  ";
	std::cin >> index;
	std::cout << "Please enter data`  ";
	std::cin >> data;
	if (size >= index)
	{
		if (index == 0)
		{
			push_front(data);
		}
		else if (index == size)
		{
			push_back(data);
		}
		else
		{
			Node<T>* counter = head;
			for (int i = 0; i < index - 1; i++)
			{
				counter = counter->pnext;
			}
			counter->pnext = new Node<T>(data, counter->pnext);
			size++;
		}
	}
	else
	{
		std::cout << "Index is not correct " << std::endl;
	}
	return;
}
template <typename T>
void List<T>::pop_front()
{
	if (size != 0)
	{
		head = head->pnext;
		size--;
	}
	return;
}
template <typename T>
void List<T>::pop_back()
{
	if (size == 1)
	{
		pop_front();
	}
	if (size != 0)
	{
		Node<T>* counter = head;
		for (int i = 0; i < size - 2; i++)
		{
			counter = counter->pnext;
		}
		counter->pnext = nullptr;
		size--;
	}
	return;
}
template <typename T>
void List<T>::pop()
{
	int index;
	std::cout << "Please input index`  ";
	std::cin >> index;

	if (index < size)
	{

		if (index == 0)
		{
			pop_front();
		}
		else if (index == size - 1)
		{
			pop_back();
		}
		else
		{
			Node<T>* counter = head;
			for (int i = 0; i <= index - 2; i++)
			{
				counter = counter->pnext;
			}
			counter->pnext = counter->pnext->pnext;
			size--;
		}
	}
	else
	{
		std::cout << "index is not correct" << std::endl;
		return;
	}

}
template<typename T>
bool List<T>::search(T data)
{
	Node<T>* counter = head;
	for (int i = 0; i < size - 1; i++)
	{
		if (counter->data == data)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
T& List<T>::operator[](int index)
{
	Node<T>* counter = head;
	for (int i = 1; i < index; i++)
	{
		counter = counter->pnext;
	}
	return counter->data;
}

template <typename T>
List<T>::Node<T>* List<T>::merge(Node<T>* a, Node<T>* b)
{
	if (a == nullptr)
		return b;

	if (b == nullptr)
		return a;

	Node<T>* c;
	if ((a->data) <= (b->data))
	{
		c = a;
		c->pnext = merge(a->pnext, b);
	}
	else
	{
		c = b;
		c->pnext = merge(a, b->pnext);
	}
	return c;
}
template <typename T>
List<T>::Node<T>* List<T>::mid_point(Node<T>* head)
{
	if (head == nullptr || head->pnext == nullptr)
		return head;

	Node<T>* fast = head;
	Node<T>* slow = head;

	while (fast != nullptr && fast->pnext != nullptr)
	{
		fast = fast->pnext;

		if (fast->pnext == nullptr)
			break;

		fast = fast->pnext;
		slow = slow->pnext;
	}
	return slow;
}

template <typename T>
List<T>::Node<T>* List<T>::sort(Node<T>* head) {

	if (head == nullptr || head->pnext == nullptr)
		return head;

	Node<T>* mid = mid_point(head);
	Node<T>* first = head;
	Node<T>* last = mid->pnext;

	mid->pnext = nullptr;

	first = sort(first);
	last = sort(last);
	Node<T>* c = merge(first, last);

	return c;
}

template<typename T>
void List<T>::output()
{
	if (size != 0) {
		Node<T>* counter = head;
		std::cout << counter->data << ' ';
		while (counter->pnext != nullptr)
		{
			counter = counter->pnext;
			std::cout << counter->data << ' ';
		}
		std::cout << std::endl;
	}
}


