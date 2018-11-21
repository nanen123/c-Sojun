#include<iostream>
#include<string>
using namespace std;

enum Color{ RED, BLUE, GREEN};

class Monster{
protected:
	string name;
public:
	int hp;
	Monster() : hp(100), name("�ӽ��̸�"){}
	Monster(int hp, const string& name) : hp(hp), name(name) {}
	virtual void Attack(){
		cout << name << " ����!" << endl;
	}
};

class Slime : public Monster{
public:
	Color color;
	Slime(int hp, const string& name, Color color) : Monster(hp, name), color(color) {}
	void Attack(){
		cout << name << " ���� ����!" << endl;
	}
};

class Goblin : public Monster{
public:
	Goblin(int hp, const string& name) : Monster(hp, name){}
	void Attack(){
		cout << name << " �ָ���!" << endl;
	}
};

int main(){
	Monster *arr[3];
	arr[0] = new Monster(10, "����1");
	arr[1] = new Slime(10, "������1", Color::RED);
	arr[2] = new Goblin(30, "���1");
	for (int i = 0; i < 3; i++){
		arr[i]->Attack();
	}
}