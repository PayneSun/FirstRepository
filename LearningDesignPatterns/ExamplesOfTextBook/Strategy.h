// Strategy
// 2016.06.23


class Composition {
public:
	Composition(Compositor*);
	void Repair();
	
private:
	Compositor* _compositor;
	Component*  _components;
	int         _componentCount;
	int         _lineWidth;
	int*        _lineBreaks;
	int         _lineCount;
};


class Compositor {
public:
	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
	) = 0;

protected:
	Compositor();
};


void Composition::Repair() {
	Coord* natural;
	Coord* stretchability;
	Coord* shrinkability;
	int componentCount;
	int* breaks;
	
	// prepare the arrays with the desired component sizes.
	// ...
	
	// determine where the breaks are:
	int breakCount;
	breakCount = _compositor->Compose(
		natural, stretchability, shrinkability,
		componentCount, _lineWidth, breaks
	);
	
	// lay out components according to breaks.
	// ...
}


class SimpleCompositor : public Compositor {
public:
	SimpleCompositor();
	
	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
	);
	// ...
};


class TexCompositor : public Compositor {
public:
	TexCompositor();
	
	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
	);
	// ...
};


class ArrayCompositor : public Compositor {
public:
	ArrayCompositor();
	
	virtual int Compose(
		Coord natural[], Coord stretch[], Coord shrink[],
		int componentCount, int lineWidth, int breaks[]
	);
	// ...
};


Composition* quick = new Composition(new SimpleCompositor);
Composition* slick = new Composition(new TexCompositor);
Composition* iconic = new Composition(new ArrayCompositor);
