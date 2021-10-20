#include <iostream>
#include "nlohmann/json.hpp"
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

	string jsonSerialize() {
		nlohmann::json j;
		j["name"] = GetName();
		j["age"] = GetAge();
		j["weight"] = GetWeight();
		return j.dump();
		
	}
	Human jsonDesrialize(string str) {
		Human temp;
			nlohmann::json object = nlohmann::json::parse(str);

			SetName(object["name"].get<string>());
			SetAge(object["age"].get<int>());
			SetWeight(object["weight"].get <int>());;
			return temp;
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
	string jsonSerialize() {
		nlohmann::json j;
		j["name"] = GetName();
		j["age"] = GetAge();
		j["avMark"] = GetAvMark();
		j["groupName"] = GetGroupName();
		j["weight"] = GetWeight();
		return j.dump();

	}
	void SetAvMark(int avMark) { this->avMark = avMark; };
	void SetSetGroupName(string groupName) { this->groupName = groupName; };

	int GetAvMark() { return avMark; }
	string GetGroupName() { return groupName; }
};

void main() {
	Human h1("John", 10, 50);
	Human h2("Max", 10, 55);

	

}