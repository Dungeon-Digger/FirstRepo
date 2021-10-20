#include <iostream>

using namespace std;

class Human {
	int age, weight;
	string name;
public:
	Human() : Human("Default", 0, 0) {}
	Human(string name, int age, int weight) : name(name), age(age), weight(weight) {}

	void SetName(string name) { this->name = name; };
	void SetAge(int age) { this->age = age; };
	void SetWeight(int weight) { this->weight = weight; };

	string GetName() { return name; }
	int GetAge() { return age; }
	int GetWeight() { return weight; }

	void Print() { cout << "Human named " << name << " aged " << age << " with weight " << weight; }
};

void main() {
	
}