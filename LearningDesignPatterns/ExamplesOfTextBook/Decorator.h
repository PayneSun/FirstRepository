// Decorator
// 2016.06.02


class VisualComponent {
public:
	VisualComponent();
	
	virtual void Draw();
	virtual void Resize();
	// ...
};


class Decorator : public VisualComponent {
public:
	Decorator(VisualComponent*);
	
	virtual void Draw();
	virtual void Resize();
	// ...
	
private:
	VisualComponent* _component;
};


void Decorator::Draw() {
	_component->Draw();
}


void Decorator::Resize() {
	_component->Resize();
}


class BorderDecorator ： public Decorator {
public:
	BorderDecorator(VisualComponent*, int borderWidth);
	
	virtual void Draw();
	
private:
	void DrawBorder(int);

	int _width;
};


void BorderDecorator::Draw() {
	Decorator::Draw();
	DrawBorder(_width);
}
