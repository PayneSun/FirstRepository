// Algorithm/Vector
// Vector.h
// 2019/09/17

#define DEAFAULT_CAPACITY 10
typedef int Rank;

template<typename T>
class Vector
{
public:
	void expand();
	void insert(Rank r, T const &e);

private:
	int _size;
	int _capacity;
	T *_elem;
};
