
#include <iostream>
#include <memory>

int main() {
	int a = 10;
	std::shared_ptr<int> ptra = std::make_shared<int>(a);
	std::shared_ptr<int> ptra2(ptra); //copy
	std::cout << ptra.use_count() << std::endl;

	int b = 20;
	int *pb = &a;

	//std::shared_ptr<int> ptrb = pb;  //error
	std::shared_ptr<int> ptrb = std::make_shared<int>(b);
	ptra2 = ptrb; //assign
	pb = ptrb.get(); //获取原始指针

	std::cout << ptra.use_count() << std::endl;
	std::cout << ptrb.use_count() << std::endl;

	int c = 5;

	std::unique_ptr<int> uptr(&c);
	*uptr = 6;
	std::cout << "[Debug] " << c << std::endl;

	std::unique_ptr<int> uptr2 = std::move(uptr);
	uptr2.release();

	std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
	std::cout << sh_ptr.use_count() << std::endl;

	std::weak_ptr<int> wp(sh_ptr);
	std::cout << wp.use_count() << std::endl;

	if (!wp.expired()) {
		std::shared_ptr<int> sh_ptr2 = wp.lock();
		*sh_ptr = 100;
		std::cout << wp.use_count() << std::endl;
	}

	return 0;
}

