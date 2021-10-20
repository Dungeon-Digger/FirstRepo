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

	void Print() { cout << "Human named " << name << " aged " << age << " with weight " << weight << endl; }
	void Print(Human other) { cout << "Human named " << other.GetName() << " aged " << other.GetAge() << " with weight " << other.GetWeight() << endl; }

	Human operator +(Human& other) {
		Human tmp(this->name, (age + other.GetAge()), (weight + other.GetWeight()));
		return tmp;
	}
};

class Student : public Human {
	int avMark;
	string groupName;
public:
	Student() : avMark(0), groupName("Default") {
		SetName("Default");
		SetAge(0);
		SetWeight(0);
	}
	Student(string name, int age, int weight, string groupName, int avMark) : avMark(avMark), groupName(groupName) {
		SetName(name);
		SetAge(age);
		SetWeight(weight);
	}
	Student(Human other, string groupName, int avMark): avMark(avMark), groupName(groupName) {
		SetAge(other.GetAge());
		SetName(other.GetName());
		SetWeight(other.GetWeight());
	}

	void SetAvMark(int avMark) { this->avMark = avMark; };
	void SetSetGroupName(string groupName) { this->groupName = groupName; };

	int GetAvMark() { return avMark; }
	string GetGroupName() { return groupName; }
};

void main() {
	Human h1("John", 10, 50);
	Human h2("Max", 10, 55);

	h1.Print(h1 + h2);
}