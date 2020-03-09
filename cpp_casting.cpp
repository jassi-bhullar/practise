#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
	Base() {}
	virtual ~Base() {}
};

class Derived : public Base
{
	public:
		Derived() {}
		~Derived() {}
};

class AnotherClass : public Base
{
public:
	AnotherClass() {}
	~AnotherClass() {}
};

int main()
{
	Derived *derived = new Derived();

	Base *base = derived;

	// Derived* ac = dynamic_cast<Derived*>(base);
	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);

	if(!ac)
	{
		cout << "Didn't Work!\n";
	}

	return 0;
}
