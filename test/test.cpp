// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class Point {
	int * stt;
public:
	int x;
	int y;
	bool enable = true;
	Point() {};
	Point(int a, int b) : x(a), y(b) {}
	Point(const Point & point) {
		x = point.x;
		y = point.y;
	}
	Point& operator= (const Point& src) {
		x = src.x;
		y = src.y;
		return *this;
	}
	~Point() {}
	void Print() {
		printf("(%d %d)", x, y);
	}
	void Print(string txt) {
		cout << "\n" <<  txt; 
		printf(" : (%d %d) ", x, y);
	}
	bool Equal(Point p) {
		if (p.x == x && p.y == y) {
			return true;
		}
		else {
			return false;
		}
	}

};

int Kosoe(Point A0, Point A, Point B0, Point B);
int L(Point A, Point B);
void first(vector<Point> &input, vector<Point> &output);
void Next(vector<Point> &input, vector<Point> &output);
void Djarvice(vector<Point> &input, vector<Point> &output);
void Print(vector <Point> array, const string str);

int main()
{
	vector<Point> v;
	vector<Point> result;
	v.push_back(Point(3, 3));
	v.push_back(Point(3, 4));
	v.push_back(Point(3, 5));
	v.push_back(Point(3, 8));
	v.push_back(Point(4, 6));
	v.push_back(Point(9, 7));
	Djarvice(v, result);

	Print(v, "It was");
	Print(result, "become");
	system("pause");
	return 0;
}

void Djarvice(vector<Point> &input, vector<Point> &output) {
	first(input, output);

	do {
		Next(input, output);
		Print(output, ">> ");
		system("pause");
	} while (!output[0].Equal(output.back()));
}

void Next(vector<Point> &input, vector<Point> &output) {

	for (int i = 0; i < input.size(); i++) {
		bool flag = true;
		for (int j = 0; j < input.size(); j++) {
			int b = Kosoe(output.back(), input[i], output.back(), input[j]);
			
			if (b > 0) {
				flag = false;
				
			}
		}
		if (flag) {
			output.push_back(input[i]);
		}
	}
}

void first(vector<Point> &input, vector<Point> &output) {
	Point p(1000, 1000);
	for (int i = 0; i < input.size(); i++) {
		if (input[i].x < p.x) {
			p = input[i];
		}
	}
	output.push_back(p);
}
int Kosoe(Point A0, Point A, Point B0, Point B) {
	return (A.x - A0.x)*(B.y - B0.y) - (B.x - B0.x)*(A.y - A0.y);
}
int L(Point A, Point B) {
	return (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y);
}

void Print(vector <Point> array, const string str) {

	cout << str << " : ";
	for (int i = 0; i < array.size(); i++) {
		array[i].Print();
	}
	cout << endl;
}