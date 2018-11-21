#include<iostream>
#include<string>
using namespace std;

enum Color{ RED, BLUE, GREEN};

class Monster{
protected:
	string name;
public:
	int hp;
	Monster() : hp(100), name("임시이름"){}
	Monster(int hp, const string& name) : hp(hp), name(name) {}
	virtual void Attack(){
		cout << name << " 공격!" << endl;
	}
};

class Slime : public Monster{
public:
	Color color;
	Slime(int hp, const string& name, Color color) : Monster(hp, name), color(color) {}
	void Attack(){
		cout << name << " 돌진 공격!" << endl;
	}
};

class Goblin : public Monster{
public:
	Goblin(int hp, const string& name) : Monster(hp, name){}
	void Attack(){
		cout << name << " 주먹질!" << endl;
	}
};

int main(){
	Monster *arr[3];
	arr[0] = new Monster(10, "몬스터1");
	arr[1] = new Slime(10, "슬라임1", Color::RED);
	arr[2] = new Goblin(30, "고블린1");
	for (int i = 0; i < 3; i++){
		arr[i]->Attack();
	}
}