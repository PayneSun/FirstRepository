// Factory Method
// 2016.05.25

class Creator
{
public:
    virtual Product* Create(ProductId);
};

Product* Creator::Create(ProductId id) {
	if (id == MINE)
		return new MyProduct;
	if (id == YOURS)
		return new YourProduct;
	// Repeat for remaining products...
	return 0;
}


Product* MyCreator::Create(ProductId id) {
	if (id == YOURS)
		return new MyProduct;
	if (id == MINE)
		return new YourProduct;
	if (id == THEIRS)
		return new TheirProduct;

	return Creator::Create(id);
}


class Creator
{
public:
	Product* GetProduct();
protected:
	virtual Product* CreateProduct();
private:
	Product* _product;
};


Product* Creator::GetProduct()
{
	if (_product == 0) {
		_product = CreateProduct();
	}
	return _product;
}


class Creator
{
public:
	virtual Product* CreatorProduct() = 0;
};


template<typename TheProduct>
class StandardCreator : public Creator
{
public:
	virtual Product* CreateProduct();
};


template<typename TheProduct>
Product* StandardCreator<TheProduct>::CreateProduct() 
{
	return new TheProduct;
}


class MazeGame
{
public:
	Maze* CreateMaze();

	virtual Maze* MakeMaze() const {
		return new Maze;
	}
	virtual Room* MakeRoom(int n) const {
		return new Room(n);
	}
	virtual Wall* MakeWall() const {
		return new Wall();
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const {
		return new Door(r1, r2);
	}
};


Maze* MazeGame::CreateMaze() 
{
	Maze* aMaze = MakeMaze();
	Room* r1 = MakeRoom(1);
	Room* r2 = MakeRoom(2);
	Door* theDoor = MakeDoor(r1, r2);
	
	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);
	
	r1->SetSide();
	r1->SetSide();
	r1->SetSide();
	r1->SetSide();
	
	r2->SetSide();
	r2->SetSide();
	r2->SetSide();
	r2->SetSide();
	
	return aMaze;
}


class BombedMazeGame : public MazeGame 
{
public:
	BombedMazeGame();
	
	virtual Wall* MakeWall() const {
		return new BombedMazeGame;
	}
	
	virtual Room* MakeRoom(int n) const {
		return new RoomWithABomb(n);
	}
};


class EnhantedMazeGame : public MazeGame
{
public:
	EnhantedMazeGame();
	
	virtual Room* MakeRoom(int n) const {
		return new EnhantedMazeGame(n, CastSpell());
	}

	virtual Door* MakeDoor(Room* r1, Room* r2) const {
		return new DoorNeedingSpell(r1, r2);
	}
};
