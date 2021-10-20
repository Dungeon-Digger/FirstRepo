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
	Student s1;
	s1.Print();
}