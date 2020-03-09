#include <bits/stdc++.h>
using namespace std;

class Player // Base
{
private:
	int salary;

public:
	Player(int s) : salary(s) {}

	virtual void printSalary()
	{
		cout << "Player has a salary of " << salary << " dollars.\n";
	}

	int GetSalary()
	{
		return salary;
	}

	void printTypeName()
	{
		cout << "Player!\n";
	}
};

class FieldPlayer : public Player
{
public:
	FieldPlayer(int s) : Player(s) {}

	void printSalary() override
	{
		cout << "Field Player has a salary of " << GetSalary() << " dollars.\n";
	}

	void printTypeName()
	{
		cout << "Field Player!\n";
	}
};
//feature 3 git learning
class Goalkeeper : public Player
{
public:
	Goalkeeper(int s) : Player(s) {}

	void printSalary() override
	{
		cout << "Goalkeeper has a salary of " << GetSalary() << " dollars.\n";
	}

	void printTypeName()
	{
		cout << "Goalkeeper!\n";
	}
};

int main()
{
	FieldPlayer fp(3500);
	Goalkeeper gk(1500);

	Player *p = &fp;
	p->printSalary();
	p->Player::printSalary(); // Supress Virtual Functionality
	p->printTypeName();

	cout << endl;
	p = &gk;
	p->printSalary();
	p->Player::printSalary(); // Supress Virtual Functionality
	p->printTypeName();

	cout << endl;
	FieldPlayer *fp_ptr = &fp;
	fp_ptr->printTypeName();
}