#pragma once
#include <iostream>
#include <string>
template <class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
};
template <class T>
class List;
template <class T>
std::ostream& operator<< (std::ostream& os, const List<T>& list) {
	Node<T>* p = list.Head;
	os << "size: " <<list.count << std::endl;
	while (p != nullptr) {
		os << p->data << " ";
		p = p->next;
	}
	os << std::endl;
	return os;
}
template <class T>
std::istream& operator>> (std::istream& is, List<T>& list) {
	list.count++;
	T d;
	is >> d;
	list.push_back(d);
	return is;
}
template <class T>
class List {
	long count;
	Node<T>* Head;
	Node<T>* Tail;
public:
	class Iterator {
	private:
		Node<T>* elem;
	public:
		/*Конструктро с параметрами
		@param el - элемент типа Node<T>*/
		Iterator(Node<T>* el) { elem = el; }
		/*Конструктор по умолчанию*/
		Iterator() { elem = nullptr; }
		/*Конструктор копирования
		@param it - копия Iterator<T> elem*/
		Iterator(const Iterator& it) { elem = it.elem; }
		/*Перегрузка оператора сравнения ==
		@param it - экземпляр класса Iteartor<T>
		@return результат сравнения */
		bool operator==(const Iterator& it) const;
		/*Перегрузка оператора сравнения !=
		@param it - экземпляр класса Iteartor<T>
		@return результат сравнения */
		bool operator!=(const Iterator& it) const;
		/*Перегрузка оператор инкремента
		@return *this - следующий указатель*/
		Iterator& operator ++();
		/*Перегрузка оператор декремента
		@return *this - предыдущий указатель*/
		Iterator& operator --();
		/*Перегрузка оператора разыменования
		@return data - значение в данном elem*/
		T& operator*() const;
		/*Метод getElem
		@return elem - текущий указатель на Node<T>*/
		Node<T>* getElem() { return elem; };
	};
private:
	Iterator head;
	Iterator tail;
public:
	/*Конструктор по умолчанию*/
	List();
	/*Конструктор с параметрами
	@param a - элемент типа T
	@param n - количество повторений элемента а , по умолчанию 1*/
	List(const T& a, int n = 1);
	/*Конструктор с параметрами-итераторами
	@param f - начало
	@param l - конец*/
	List(Iterator f, Iterator l);
	/*Конструктор копирования
	@param x - ссылка на экземпляр класса List<T>*/
	List(const List<T>& x);
	/*Деструктор*/ 
	~List();
	/*Перегрузка оператора присваивания 
	@param t - константнаяа ссылка на экземпляр класса List<T>*/
	List<T>& operator = (const List<T>&t);
	/*Метод getHead
	@return Head - указатель на голову*/
	Node<T>* getHead() { return Head; };
	/*Метод begin
	@return head итератор*/
	Iterator begin() { return head; }
	/*Метод end
	@return tail итератор*/
	Iterator end() { return tail; }
	/*Константный метод begin
	@return head итератор*/
	Iterator begin() const { return head; }
	/*Константный метод end
	@return tail итератор*/
	Iterator end() const { return tail; }
	/*Метод empty
	@return результат проверки на пустоту*/
	bool empty() const { return (Head == nullptr); }
	/*Метод length
	@return длина списка*/
	long length() const { return count; }
	/*Метод front
	@return значение начального элемента*/
	T& front() { return *begin(); }
	/*Метод back
	@return значение конечного элемента*/
	T& back() { Iterator it = end(); return *it; }
	/*Метод push_front
	@param x добавляемое в начало значение*/
	void push_front(const T&x);
	/*Метод pop_front*/
	void pop_front();
	/*Метод push_back
	@param x добавляемое в конец значение*/
	void push_back(const T&x);
	/*Метод pop_back*/
	void pop_back();
	/*Метод insert для одиночного элемента
	@param it - итератор 
	@param r - значение */
	void insert(Iterator it, const T&r);
	/*Метод insert для группы элементов
	@param p - после какого итератора вставить
    @param f - от какого итератора
	@param l - до какого итератора*/
	void insert(Iterator p, Iterator f, Iterator l);
	/*Метод erase
	@param f - итератор начало удаления
	@param l - итератор конец удаления*/
	void erase(Iterator f, Iterator l);
	/*Метод replacement
	@param f1 - начало заменяемого диапозона
	@param l1 - конец заменяемого диапозона
	@param f2 - начало нового диапозона
	@param l2 - конец нового диапозона*/
	void replacement(Iterator  f1, Iterator  l1, Iterator  f2, Iterator  l2);
	/*Метод find для одиночного элемента
	@param x - элемент типа T
	@return итератор(позиция) элемента */
	Iterator find(const T& x);
	/*Метод find для группы элементов
	@param f - начала диапозона элементов
	@param l - конец диапозона элементов
	@return итератор первого появления */
	Iterator find(Iterator f, Iterator l);
	/*Перегрузка дружественного оператора <<
	@param os - поток вывода
	@param list - экземпляр класса List<T>
	@return os - поток вывода*/
	friend std::ostream& operator<< <>(std::ostream& os, const List<T>& list);
	/*Перегрузка дружественного оператора >>
	@param is - поток ввода
	@param list - экземпляр класса List<T>
	@return is - поток ввода*/
	friend std::istream& operator>> <>(std::istream& is, List<T>& list);
};

template <class T>
List<T>::List() {
	Head = new Node<T>();
	Tail = Head;
	count = 0;
	Tail->next = Tail->prev = nullptr;
	head = Iterator(Head);
	tail = Iterator(Tail);
}

template<class T>
List<T>::List(const T& a, int n)
{
	count = n;
	for (int i = 0; i < n; i++)
		push_front(a);
}

template<class T>
List<T>::List(Iterator f, Iterator l)
{
	++l;
	count = 0;
	for (Iterator ip = f; ip != l; ++ip) {
		push_front(*ip);
		++count;
	}
}

template<class T>
List<T>::List(const List<T>& x)
{
	List<T>(x.begin(), x.end());
}

template<class T>
List<T>::~List()
{
	Node <T>* p = Head;
	while (p != nullptr) {
		--count;
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& t)
{
	count = t.count;
	Head = t.Head;
	Tail = t.Tail;
	head = t.head;
	tail = t.tail;
	return *this;
}

template<class T>
void List<T>::push_front(const T& x)
{
	Node<T>* elem = new Node<T>;
	if (empty()) {
		elem->next = elem->prev = nullptr;
		elem->data = x;
		Head = Tail = elem;
	}
	else {
		elem->prev = nullptr;
		elem->data = x;
		elem->next = Head;
		Head->prev = elem;
		Head = elem;
	}
	head = Iterator(Head);
	tail = Iterator(Tail);
}

template<class T>
void List<T>::pop_front()
{
	if (!empty() && Head->next != nullptr) {
		Node<T>* p = new Node<T>();
		p = Head->next;
		p->prev = nullptr;
		Head = p;
		--count;
	}
	else if (!empty() && Head->next == nullptr) {
		--count;
		Node<T>* p = new Node<T>();
		p = Head->next;
		Tail = Head = p;
	}
	head = Iterator(Head);
	tail = Iterator(Tail);
}

template<class T>
void List<T>::push_back(const T& x)
{
	Node<T>* elem = new Node<T>;
	if (empty()) {
		elem->prev = elem->next = nullptr;
		elem->data = x;
		Head = Tail = elem;
	}
	else {
		elem->next = nullptr;
		elem->data = x;
		elem->prev = Tail;
		Tail->next = elem;
		Tail = elem;
	}
	head = Iterator(Head);
	tail = Iterator(Tail);
}

template<class T>
void List<T>::pop_back()
{

	if (!empty() && Tail->prev != nullptr) {
		Node<T>* p = new Node<T>();
		p = Tail->prev;
		p->next = nullptr;
		Tail = p;
		--count;
	}
	else if (!empty() && Head->next == nullptr) {
		--count;
		Node<T>* p = new Node<T>();
		p = Tail->prev;
		Tail = Head = p;
	}
	head = Iterator(Head);
	tail = Iterator(Tail);
}

template <class T>
void List<T>::insert(Iterator it, const T& r) {
	Node<T>* el = it.getElem();
	if (it == end())
		push_back(r);
	else if (it == begin())
		push_front(r);
	else {
		Node<T>* nextel = el->next;
		Node<T>* p = new Node<T>;
		p->data = r;
		p->next = nextel;
		p->prev = el;
		nextel->prev = p;
		el->next = p;
	}
	++count;
}

template <class T>
void List<T>::insert(Iterator p, Iterator f, Iterator l) {
	if (p.getElem() != nullptr) {
		Iterator it = head;
		Node<T>* node = Head;
		while (it != p) {
			++it;
			node = node->next;
		}
		Node<T>* nextnode = node->next;
		++l;
		while (f != l) {
			Node<T>* cur = new Node<T>;
			cur->data = f.getElem()->data;
			node->next = cur;
			cur->prev = node;
			node = node->next;
			count++;
			++f;
		}
		if (p == tail) {
			Tail = node;
			tail = Iterator(Tail);
		}
		node->next = nextnode;
	}

}


template<class T>
void List<T>::erase(Iterator f, Iterator l)
{
	++l;
	for (Iterator it = f; it != l; ++it) {
		Node<T>* el = it.getElem();
		if (it == begin())
			pop_front();
		else {
			Node<T>* prevel = el->prev;
			Node<T>* nextel = el->next;
			if (prevel != nullptr && nextel != nullptr) {
				prevel->next = nextel;
				nextel->prev = prevel;
			}
			else if (prevel != nullptr && nextel == nullptr) {
				prevel->next = nextel;
			}
			else if (prevel == nullptr && nextel != nullptr) {
				nextel->prev = prevel;
			}
			count--;
		}
	}
}

template<class T>
void List<T>::replacement(Iterator f1, Iterator l1, Iterator f2, Iterator l2)
{
	erase(f1, l1);
	insert(--f1, f2, l2);
}

template<class T>
typename List<T>::Iterator List<T>::find(const T& x)
{
	Iterator e = end();
	++e;
	for (Iterator it = begin(); it != e; ++it) {
		if (*it == x) {
			return it;
		}
	}
	return Iterator();
}


template <class T>
typename List<T>::Iterator List<T>::find(Iterator f, Iterator l)
{
	++l;
	bool flag=false;
	Iterator e = end();
	for (Iterator it = begin(); it != e; ++it) {
		if (*it == *f) {
			Iterator ft(f);
			Iterator lt(l);
			Iterator jt(it);
			while (jt != e && ft != lt) {
				if (jt.getElem()->data == ft.getElem()->data)
					flag = true;
				else {
					flag = false;
					break;
				}
				++jt;
				++ft;
			}
			if (flag && ft == lt)
				return it;
		}


	}
	return Iterator();
}

template <class T>
bool List<T>::Iterator::operator==(const Iterator& it) const {
	return elem == it.elem;
}
template<class T>
bool List<T>::Iterator::operator!=(const Iterator& it) const
{
	return elem != it.elem;
}
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	if (elem != nullptr)
		elem = elem->next;
	return *this;
}
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	if (elem != nullptr)
		elem = elem->prev;
	return *this;
}
template<class T>
T& List<T>::Iterator::operator*() const
{
	if (elem != nullptr)
		return elem->data;
}