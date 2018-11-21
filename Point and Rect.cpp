#include<iostream>
#include<cstdio>

class Point{
private:
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}

	void PrintP() const{
		std::cout << "[" << x << "," << y << "]" << std::endl;
	}

	void IncrePoint(){
		x++;
		y++;
	}
	void MovePoint(int x, int y){
		this->x += x;
		this->y += y;
	}
	void AddPoint(Point p){
		this->x += p.x;
		this->y += p.y;
	}
	float GetDistance(Point p2){
		return sqrt((x - p2.x)*(x - p2.x) + (y - p2.y)*(y - p2.y));
	}

	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(int x) { if (x <= 10) this->x = x; }
	void SetY(int y) { if (y <= 10) this->y = y; }

};

class Rect
{
private:
public:
	Point p1;
	Point p2;
	Rect() : p1(0, 1), p2(1, 0){}
	Rect(const Point& p1, const Point& p2){
		if (p1.GetX() > p2.GetX()){
			this->p1.SetX(p2.GetX());
			this->p2.SetX(p1.GetX());
		}
		else
		{
			this->p1.SetX(p1.GetX());
			this->p2.SetX(p2.GetX());
		}

		if (p1.GetY() > p2.GetY()){
			this->p1.SetY(p1.GetY());
			this->p2.SetY(p2.GetY());
		}
		else
		{
			this->p1.SetY(p2.GetY());
			this->p2.SetY(p1.GetY());
		}
	}

	void Move(int x, int y){
		p1.MovePoint(x, y);
		p2.MovePoint(x, y);

	}

	double GetArea(){
		return (p2.GetX() - p1.GetX()) * (p1.GetY() - p2.GetY());
	}
};

int main(){
	Point p1(1, 4);
	Point p2(3, 2);

	Rect r1 = Rect();
	Rect r2(p1, p2);

	std::cout << r1.GetArea() << std::endl;
	std::cout << r2.GetArea() << std::endl;
}
