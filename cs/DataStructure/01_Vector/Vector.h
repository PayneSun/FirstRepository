// Algorithm/Vector
// Vector.h
// 2019/09/17

#define DEAFAULT_CAPACITY 10
typedef int Rank;


template<typename T>
struct Increase
{
	virtual void operator()(T &e) { e++; }
};


template<typename T>
class Vector
{
public:
	void expand();
	void insert(Rank r, T const &e);
	int remove(Rank lo, Rank hi);
	T remove(Rank r);
	Rank find(T const &e, Rank lo, Rank hi) const;
	int deduplicate();
	void traverse(Increase<T> &visit);
	int disordered() const;

private:
	int _size;
	int _capacity;
	T *_elem;
};


