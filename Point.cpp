#include<iostream>
#include<cstdio>

class Point{
private:
	int x, y;
public:
	Point(){
		this->x = 0;
		this->y = 0;
	}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}

	void PrintP(){
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

	Point& operator=(const Point &p){
		delete this;
		Point res;
		res.x = p.x;
		res.y = p.y;
		return res;
	}

};

int main(){
	Point *p1 = new Point(1, 2);
	Point *p2 = new Point(3, 4);
	p1->PrintP();
	p2->PrintP();
	p1->MovePoint(3, 4);
	p1->PrintP();
	p1 = p2;
	p1->PrintP();
}




