// ch07_class.cpp
// Window_mgr.h
// 2019/4/12


#include "Screen.h"
#include <vector>
#include <string>

class Screen;


class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);

private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};


void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = this->screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}
