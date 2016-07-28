// Observer
// 2016.06.22


class Subject;


class Observer {
public:
	virtual ~Observer();
	virtual void Update(Subject* theChangedSubject) = 0;

protected:
	Observer();
};


class Subject {
public:
	virtual ~Subject();
	
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
	
protected:
	Subject();
	
private:
	List<Observer*>* _observer;
};


void Subject::Attach(Observer* o) {
	_observer->Append(o);
}


void Subject::Detach(Observer* o) {
	_observer->Remove(o);
}


void Subject::Notify() {
	ListIterator<Observer*> i(_observer);
	for (i.First(); !i.IsDone(); i.Next()) {
		i.CurrentItem()->Update(this);
	}
}


class ClockTimer : public Subject {
public:
	ClockTimer();
	
	virtual int GetHour();
	virtual int GetMinute();
	virtual int GetSecond();

	void Tick();
};


void ClockTimer::Tick() {
	// ...
	Notify();
}


class DigitalClock ： public Widget, public Observer {
public:
	DigitalClock(ClockTimer*);
	virtual ~DigitalClock();
	
	virtual void Update(Subject*);
	virtual void Draw();

private:
	ClockTimer* _subject;
};


DigitalClock::DigitalClock(ClockTimer* s) {
	_subject = s;
	_subject->Attach(this);
}


DigitalClock::~DigitalClock() {
	_subject->Detach(this);
}


void DigitalClock::Update(Subject* theChangedSubject) {
	if (theChangedSubject == _subject) {
		Draw();
	}
}


void DigitalClock::Draw() {
	int hour   = _subject->GetHour();
	int minute = _subject->GetMinute();
	int second = _subject->GetSecond();
	// etc.
	
	// Draw the digital clock
}


class AnalogClock ： public Widget, public Observer {
public:
	AnalogClock(ClockTimer*);
	virtual void Update(Subject*);
	virtual void Draw();
	// ...
};


ClockTimer* timer = new ClockTimer;
AnalogClock analogClock = new AnalogClock(timer);
DigitalClock digitalClock = new DigitalClock(timer);
