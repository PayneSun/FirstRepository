// Memento
// 2016.06.22


class State;


class Originator {
public:
	Memento* CreateMemento();
	void SetMemento(const Memento*);
    // ...

private:
	State* _state;
};


class Memento {
public:
	virtual ~Memento();
	
private:
	friend class Originator;
	Memento();
	
	void SetState(State*);
	State* GetState();
	
private:
	State* _state;
	// ...
};


class Graphic;


class MoveCommand {
public:
	MoveCommand(Graphic* target, const Point& delta);
	void Execute();
	void Unexcute();
	
private:
	ConstraintSolverMemento* _state;
	Point _delta;
	Graphic* _target;
};


class ConstraintSolver {
public:
	static ConstraintSolver* Instance();

	void Solve();
	void AddConstraint(
		Graphic* startConnection, Graphic* endConnection
	);
	void RemoveConstraint(
		Graphic* startConnection, Graphic* endConnection
	);
	ConstraintSolverMemento* CreateMemento();
	void SetMemento(ConstraintSolverMemento*);
	
private:
	// ...
};


class ConstraintSolverMemento {
public:
	virtual ~ConstraintSolverMemento();
	
private:
	friend class ConstraintSolver;
	ConstraintSolverMemento();
	
	// ...
};


void MoveCommand::Execute() {
	ConstraintSolver* solver = ConstraintSolver::Instance();
	_state = solver->CreateMemento();
	_target->Move(_delta);
	solver->Solve();
}


void MoveCommand::Unexcute() {
	ConstraintSolver* solver = ConstraintSolver::Instance();
	_target->Move(-delta);
	solver->SetMemento(_state);
	solver->Solve();
}
