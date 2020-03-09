#include <bits/stdc++.h>
using namespace std;

class Entity
{
public:
	Entity()
	{
		cout << "Object Created!" << endl;
	}

	~Entity()
	{
		cout << "Object Destroyed!" << endl;
	}

	void printFunc() {}
};

void debug(int i)
{
	cout << i << endl;
}

int main()
{
	////////////// Unique Pointer
	// {
	// 	unique_ptr<Entity> entity = make_unique<Entity>();
	// 	debug(1);
	
	// 	entity->printFunc();
	// 	debug(2);
	// }
	// debug(3);

	/////////////// Shared Pointer - Increase Ref Count everytime it gets copied
	{
		shared_ptr<Entity> e0;
		debug(1);
		{
			shared_ptr<Entity> sharedEntity = make_shared<Entity>();
			debug(2);
			// e0 = sharedEntity;
			debug(3);
		}
		debug(4);
	}
	debug(5);

	/////////////// Weak Pointer - Doesn't increse ref count
	// {
	// 	weak_ptr<Entity> e0;
	// 	debug(1);
	// 	{
	// 		shared_ptr<Entity> sharedEntity = make_shared<Entity>();
	// 		debug(2);
	// 		e0 = sharedEntity;
	// 		debug(3);
	// 	}
	// 	debug(4);
	// }
	// debug(5);

	return 0;
}