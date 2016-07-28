// Iterator
// 2016.06.17


template<typename T>
class List {
public:
	List(long size = DEFAULT_LIST_CAPACITY);
	
	long Count() const;
	T& Get(long index) const;
	// ...
};


template<typename T>
class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual T CurrentItem() const = 0;

protected:
	Iterator();
};


template<typename T>
class ListIterator : public Iterator<T> {
public:
	ListIterator(const List<T>* aList);
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual T CurrentItem() const;
	
private:
	const List<T>* _list;
	long _current;
};


template<typename T>
ListIterator<T>::ListIterator(const List<T>* aList)
	: _list(aList), _current(0) {	
}


template<typename T>
void ListIterator<T>::First() {
	_current = 0;
}


template<typename T>
void ListIterator<T>::Next() {
	_current++;
}


template<typename T>
bool ListIterator<T>::IsDone() const {
	return _current >= _list->Count();
}


template<typename T>
T ListIterator<T>::CurrentItem() const {
	if (IsDone()) {
		throw IteratorOutofBounds;
	}
	return _list->Get(_current);
}


void PrintEmployees(Iterator<Employee*>& i) {
	for (i.First(); !i.IsDone(); i.Next()) {
		i.CurrentItem()->Print();
	}
}


List<Employee*>* employees;
// ...
ListIterator<Employee*> forward(employees);
ReverseListIterator<Employee*> backward(employees);
PrintEmployees(forward);
PrintEmployees(backward);

SkipList<Employee*>* employees;
// ...

SkipListIterator<Employee*>* iterator(employees);
PrintEmployees(iterator);


template<typename T>
class AbstractList {
public:
	virtual Iterator<T>* CreateIterator() const = 0;
	// ...
};


template<typename T>
Iterator<T>* List<T>::CreateIterator() const {
	return new ListIterator<T>(this);
}


AbstractList<Employee*>* employees;
// ...

Iterator<Employee*>* iterator = employees->CreateIterator();
PrintEmployees(*iterator);
delete iterator;


template<typename T>
class IteratorPtr {
public:
	IteratorPtr(Iterator<T>* i) : _i(i) {}
	~IteratorPtr() { delete _i; }

	Iterator<T>* operator->() { return _i; }
	Iterator<T>& operator*() { return *_i; }

private:
	IteratorPtr(const IteratorPtr&);
	IteratorPtr operator=(const IteratorPtr&);

	Iterator<T>* _i;
};


// 6.
template<typename T>
class ListTraverser {
public:
	ListTraverser(List<T>* aList);
	bool Traverse();
	
protected:
	virtual bool ProcessT(const T&) = 0;
	
private:
	ListIterator<T> _iterator;
};


template<typename T>
ListTraverser<T>::ListTraverser(List<T>* aList) 
    : _iterator(aList) {
}


template<typename T>
bool ListTraverser<T>：：Traverse() {
	bool result = false;

	for (_iterator.First(); 
	     !_iterator.IsDone(); 
		 _iterator.Next()) {
		result = ProcessT(_iterator.CurrentItem());
		if (result == false) {
			break;
		}
	}
	
	return result;
}


template<typename T>
class PrintEmployees : public ListTraverser<Employee*> {
public:
	PrintEmployees(List<Employee*>* aList, int n) 
		: ListTraverser<Employee*>(aList), _total(n), _count(0) {}

protected:
	bool ProcessT(Employee* const&);

private:
	int _total;
	int _count;
};


bool PrintEmployees::ProcessT(Employee* const& e) {
	_count++;
	e->Print();
	return _count < _total;
}


template<typename T>
class FilteringListTraverser {
public:
	FilteringListTraverser(List<T>* aList);
	bool Traverse();
	
protected:
	virtual bool ProcessT(const T&) = 0;
	virtual bool TestT(const T&) = 0;

private:
	ListIterator<T> _iterator;
};
