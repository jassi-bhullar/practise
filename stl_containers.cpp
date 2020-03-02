#include <bits/stdc++.h>
using namespace std;

void runSet()
{
	set<int> mySet;

	mySet.insert(5);
	mySet.insert(9);
	mySet.insert(2);
	mySet.insert(1);
	mySet.insert(8);
	mySet.insert(9); // duplicate

	for(auto x: mySet)
	{
		cout << x << " ";
	}
	cout << endl;

	mySet.erase(mySet.find(5), mySet.end());

	for(auto x: mySet)
	{
		cout << x << " ";
	}
	cout << endl;
}

void runUnorderedSet()
{
	unordered_set<string> line1 = {"Baby's", "Day", "Out"};
	unordered_set<string> line2;

	line2.insert("Jump");
	line2.insert("Up");
	line2.insert("Jump");
	line2.insert("Up");

	for(auto x: line1) cout << x << " "; cout << ". ";
	for(auto x: line2) cout << x << " "; cout << ". ";
	cout << endl;

	line1.swap(line2);

	for(auto x: line1) cout << x << " "; cout << ". ";
	for(auto x: line2) cout << x << " "; cout << ". ";
	cout << endl;

	line2.erase(line2.find("Day"));

	for(auto x: line2) cout << x << " "; cout << ". ";
}

void runMap()
{
	map<char, int> myMap;

	myMap['f'] = 3;
	myMap['a'] = 1;
	myMap['b'] = 2;
	myMap['a'] = 4;

	for(auto x: myMap) cout << x.first << " " << x.second << endl; cout << endl;

	// if key exists
	char c = 'c';
	if(myMap.count(c) > 0)
		cout << c << " exists\n";
	else
		cout << c << " doesn't exist\n";

	cout << "Lower Bound of " << c << ": " << myMap.lower_bound(c)->first << endl;
	cout << "Upper Bound of " << c << ": " << myMap.upper_bound(c)->first << endl;

	c = 'a';
	cout << endl;

	cout << "Lower Bound of " << c << ": " << myMap.lower_bound(c)->first << endl;
	cout << "Upper Bound of " << c << ": " << myMap.upper_bound(c)->first << endl;

	c = 'f';
	cout << endl;

	cout << "Lower Bound of " << c << ": " << myMap.lower_bound(c)->first << endl;
	cout << "Upper Bound of " << c << ": " << myMap.upper_bound(c)->first << endl;
}

void runUnorderedMap()
{
	unordered_map<char, int> myMap;

	myMap['f'] = 3;
	myMap['a'] = 1;
	myMap['b'] = 2;
	myMap['a'] = 4;

	for(auto x: myMap) cout << x.first << " " << x.second << endl; cout << endl;

	unordered_map<char, int>::iterator x = myMap.find('a');
	cout << "Value at " << x->first << ": " << x->second << endl;

	myMap.erase('a');

	for(auto x: myMap) cout << x.first << " " << x.second << endl; cout << endl;

	// if key exists
	char c = 'f';
	if(myMap.count(c) > 0)
		cout << c << " exists\n";
	else
		cout << c << " doesn't exist\n";
}

int main()
{
	// runSet();
	// runUnorderedSet();

	// runMap();
	runUnorderedMap();

	return 0;
}