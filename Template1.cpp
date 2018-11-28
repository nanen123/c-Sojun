#include<iostream>

using namespace std;

class Entity
{
	int x, y;
public:
	Entity() : x(0), y(0) {}
	Entity(int x, int y) : x(x), y(y){}
	friend std::ostream& operator<<(ostream&, const Entity e);
};

ostream& operator<<(ostream& stream, const Entity e)
{
	stream << '[' << e.x << ',' << e.y << ']';
	return stream;
}

template <typename T, unsigned int size>
class Array
{
	T arr[size];
public:
	unsigned int GetSize(){
		return size;
	}
	T& operator[](unsigned int index)
	{
		if (index >= size){
			cout << "아니 인덱스를 왜 그렇게;;" << endl;
			__debugbreak();
		}
		return arr[index];
	}
};

int main()
{
	Array<int,5> arr;
	for (int i = 0; i < arr.GetSize(); i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	Array<Entity, 5> arr1;
	for (int i = 0; i < arr1.GetSize(); i++){
		arr1[i] = Entity(i + 1, i + 1);
	}
	for (int i = 0; i < arr1.GetSize(); i++){
		cout << arr1[i] << ' ';
	}

	cout << endl;
}