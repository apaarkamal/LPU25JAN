#include<bits/stdc++.h>
using namespace std;

class Person {
public:
	int age;
	string name;
	double height;
	Person() {

	}
	Person(int age, string name, double height) {
		this->age = age;
		this->name = name;
		this->height = height;
	}
	void print() {
		cout << name << " " << age << " " << height << '\n';
	}
};

//
bool compareHeight(Person a, Person b) {
	return a.height < b.height;
}

bool compareAgeReverse(Person a, Person b) {
	return a.age > b.age;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Person a[3];
	a[0] = Person(5, "apaar", 5.7);
	a[1] = Person(10, "vishal", 5.4);
	a[2] = Person(15, "rahul", 6.3);

	// sort(a, a + 3, compareHeight);
	sort(a, a + 3, [&](Person a, Person b) {
		return a.name < b.name;
	});

	for (int i = 0; i < 3; i++) {
		a[i].print();
	}

}