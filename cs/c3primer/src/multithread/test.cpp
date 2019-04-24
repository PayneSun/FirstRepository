#include <iostream>
#include <map>

using namespace std;

struct Point {
	Point() {}
	Point(int px, int py) : x(px), y(py) {}
	int x;
	int y;
};

struct Line {
	Point beg;
	Point end;
};

struct cmp_key {
	bool operator()(const Point &pt1, const Point &pt2) {
		if (pt1.x != pt2.x) {
			return pt1.x < pt2.x;
		}
		if (pt1.y != pt2.y) {
			return pt1.y < pt2.y;
		}
		return false;
	}
};

void func(map<Point, int, cmp_key> &pmap, const Line &line) {
	Point pt;
	if (line.beg.x == line.end.x) {
		for (int y = line.beg.y; y != line.end.y; ++y) {
			pt.x = line.beg.x - 1;
			pt.y = y;
			pmap[pt] = 1;

			pt.x = line.beg.x;
			pt.y = y;
			pmap[pt] = 1;

			// pmap[Point(line.beg.x - 1, y)] = 1;
			// pmap[Point(line.beg.x, y)] = 1;
		}
	} else if (line.beg.y == line.end.y) {
		for (int x = line.beg.x; x != line.end.x; ++x) {
			pt.x = x;
			pt.y = line.beg.y - 1;
			pmap[pt] = 1;

			pt.x = x;
			pt.y = line.beg.y;
			pmap[pt] = 1;

			// pmap[Point(x, line.beg.y - 1)] = 1;
			// pmap[Point(x, line.beg.y)] = 1;
		}
	}
}

int main() {
	int n;
	cin >> n;

	map<Point, int, cmp_key> pmap;

	int x1, y1, x2, y2;
	for (int i = 0; i < n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;

		Line le;
		if (x1 == x2) {
			le.beg.x = le.end.x = x1;
			le.beg.y = (y1 < y2 ? y1 : y2);
			le.end.y = y1 + y2 - le.beg.y;
		} else if (y1 == y2) {
			le.beg.y = le.end.y = y1;
			le.beg.x = (x1 < x2 ? x1 : x2);
			le.end.x = x1 + x2 - le.beg.x;
		}

		func(pmap, le);
	}

	cout << pmap.size() << endl;
}

/*

 3
 1 2 3 2
 2 5 2 3
 1 4 3 4

 */
