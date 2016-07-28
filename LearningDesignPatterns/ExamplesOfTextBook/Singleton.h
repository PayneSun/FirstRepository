// Singleton
// 2016.05.26

class Singleton
{
public:
	static Singleton* Instance();
protected:
	Singleton();
private:
	static Singleton* _instance;
};


Singleton* Singleton::instance = 0;


Singleton* Singleton::Instance() {
	if (_instance == 0) {
		instance = new Singleton;
	}
}


class Singleton
{
public:
	static void Register(const char* name, Singleton*);
	static Singleton* Instance();
protected:
	static Singleton* Lookup(const char* name);
private:
	static Singleton* _instance;
	static List<NameSingletonPair>* _registry;
};


Singleton* Singleton::Instance() {
	if (_instance == 0) {
		const char* singletonName = getenv("SINGLETON");
		_instance = Lookup(singletonName);
	}
	return _instance;
}


class MazeFactory
{
public:
	static MazeFactory* Instance();
protected:
	MazeFactory();
private:
	static MazeFactory* _instance;
};


MazeFactory* MazeFactory::_instance = 0;


MazeFactory* MazeFactory：：Instance() 
{
	if (_instance == 0) {
		_instance = new MazeFactory;
	}
	return _instance;
}
