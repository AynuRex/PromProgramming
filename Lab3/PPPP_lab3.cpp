#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
#include <memory>
#include <iostream>
#include <vector>

constexpr auto SIZE = 16;

class IComponentWrapper
{
public:
	virtual double sumCost(int mass) { return 0; };
	virtual double sumTime() { return 0; };
	virtual int getDistance() { return 0; };
};

class Leaf : public IComponentWrapper
{
protected:
	int price;
	int speed;
	double volume;
	int distance;
public:
	Leaf(int price, int speed, double volume, int distance);
	double sumCost(int mass) override;
	double sumTime() override;
	int getDistance() override;
};

class Plane : public Leaf
{
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
	~Plane();
};
Plane::Plane() : Leaf(500, 300, 100, 0)
{}

Plane::Plane(std::tuple<int, int, double> tuple, int dist) : Leaf(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple), dist)
{}

Plane::~Plane()
{

}
class Train : public Leaf
{
public:
	Train();
	Train(std::tuple<int, int, double>, int);
	~Train();
};
Train::Train() : Leaf(200, 100, 500, 0)
{
}

Train::Train(std::tuple<int, int, double> tuple, int dist) : Leaf(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple), dist)
{
}

Train::~Train()
{

}

Leaf::Leaf(int price, int speed, double volume, int distance)
{
	this->price = price;
	this->speed = speed;
	this->volume = volume;
	this->distance = distance;
}

double Leaf::sumCost(int mass)
{
	return (mass / volume) * sumTime() * price;
}

double Leaf::sumTime()
{
	return distance / speed;
}

int Leaf::getDistance()
{
	return this->distance;
}
class Car : public Leaf
{
public:
	Car();
	Car(std::tuple<int, int, double>, int);
	~Car();
};

Car::Car() : Leaf(100, 60, 50, 0)
{}

Car::Car(std::tuple<int, int, double> tuple, int dist) : Leaf(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple), dist)
{}

Car::~Car()
{

}

class Composite : public IComponentWrapper
{
	std::vector<IComponentWrapper> components;
public:
	Composite();
	Composite(IComponentWrapper comp) { components.push_back(comp); }

	template<class... Arguments>
	Composite(IComponentWrapper comp, Arguments... args);
	
	void addComponents(IComponentWrapper comp) { components.push_back(comp); }
	
	template<class... Arguments>
	void addComponents(IComponentWrapper comp, Arguments... args);

	double sumCost(int mass) override;
	double sumTime() override;
	int getDistance() override;
};

Composite::Composite()
{}

template<class... Arguments>
Composite::Composite(IComponentWrapper comp, Arguments... args)
{
	addComponents(comp, args...);
}

template<class... Arguments>
void Composite::addComponents(IComponentWrapper comp, Arguments... args)
{
	components.push_back(comp);
	addComponents(args...);
}

double Composite::sumCost(int mass)
{
	double retVal = 0;
	for (auto component : components)
	{
		retVal += component.sumCost(mass);
	}
	return retVal;
}

double Composite::sumTime()
{
	double retVal = 0;
	for (auto component : components)
	{
		retVal += component.sumTime();
	}
	return retVal;
}

int Composite::getDistance()
{
	int retVal = 0;
	for (auto component : components)
	{
		retVal += component.getDistance();
	}
	return retVal;
}

const std::string points[SIZE] = { "msk_AP","msk_TS","msk_WH","mzh_TS",
"mzh_WH","zvn_WH","NN_AP","NN_TS", "NN_WH","dzr_TS","dzr_WH",
"vlg_AP","vlg_TS","vlg_WH","kam_TS","kam_WH" };

const std::map<std::string, int> towns = {
	{"Moscow", 2},
	{"Mozhaisk", 4},
	{"Zvenigorod", 5},
	{"Nizhniy Novgorod", 8},
	{"Dzerzhinsk", 10},
	{"Volgograd", 13},
	{"Kamishin", 15} };

const std::map<std::string, int> table = {
	{"msk", 0},
	{"mzh", 1},
	{"zvn", 2},
	{"NN", 3},
	{"dzr", 4},
	{"vlg", 5},
	{"kam", 6} };

const std::tuple<int, int, double> tableCost[21] = {
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{0, 0, 0},
	{100, 60, 50},
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50},
	{500, 300, 100},
	{200, 100, 500},
	{100, 60, 50},
	{0, 0, 0},
	{200, 100, 500},
	{100, 60, 50} };

const int matrixDist[SIZE][SIZE] = {
{0, 20, 30, 108, 110, 65, 398, 0, 0, 0, 0, 926, 0, 0, 0, 0},
{20, 0, 10, 98, 100, 55, 0, 415, 0, 483, 0, 0, 937, 0, 1204, 0},
{30, 10, 0, 108, 110, 65, 0, 0, 430, 0, 390, 0, 0, 652, 0, 1234},
{108, 98, 108, 0, 5, 0, 0, 0, 0, 581, 0, 0, 1035, 0, 1302, 0},
{110, 100, 110, 5, 0, 78, 0, 0, 540, 0, 500, 0, 0 ,1062, 0, 1344},
{65, 55, 65, 0, 78, 0, 0, 0, 495, 0, 455, 0, 0, 1017, 0, 1299},
{398, 0, 0, 0, 0, 0, 0, 19, 23, 0, 26, 828, 0, 0, 0, 0},
{0, 415, 0, 0, 0, 0 ,19, 0, 4, 32, 0, 0, 840, 0, 919, 0},
{0, 0, 430, 0, 540, 495, 23, 4, 0, 0, 40, 0, 0, 849, 0, 1010},
{0, 483, 0, 581, 0, 0, 0, 32, 0, 0, 4, 0, 872, 0, 951, 0},
{0, 0, 390, 0, 500, 455, 26, 0, 40, 4, 0, 0, 0, 889, 0, 1050},
{926, 0, 0, 0, 0 ,0 ,828, 0, 0 ,0 ,0, 0, 15, 16, 0, 285},
{0, 937, 0, 1035, 0, 0, 0, 840, 0, 872, 0, 15, 0, 2, 257, 281},
{0, 0, 952, 0, 1062, 1017, 0, 0, 849, 0, 889, 16, 2, 0, 0 ,282},
{0, 1204, 0, 1302, 0, 0, 0, 919, 0, 951, 0, 0, 257, 0, 0, 2},
{0, 0, 1234, 0, 1344, 1299, 0, 0, 1010, 0, 1050, 285, 281, 282, 2, 0} };


enum class Type { Turbo, Standart, Economy };

class Order
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Composite track;
public:
	Order();
	Order(Type, std::string, std::string, int);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Composite best(std::string, std::string, Type, int);
};

Order::Order()
{
	this->cost = 0;
	this->volume = 0;
	this->startPoint = "";
	this->finishPoint = "";
	this->track = Composite();
	this->type = Type::Economy;
}

Order::Order(Type deliv, std::string startP, std::string finishP, int vol)
{
	this->startPoint = startP;
	this->finishPoint = finishP;
	type = deliv;
	this->track = best(startP, finishP, deliv, vol);
	this->cost = track.sumCost(vol);
	this->volume = vol;
}

Order::~Order()
{

}

Composite Order::best(std::string startP, std::string finishP, Type deliv, int volume)
{
	int start = decr(startP);
	int finish = decr(finishP);
	int** mat = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
		mat[i] = new int[SIZE];
	mat = matrixUpd(deliv);
	int* path = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		path[i] = -1;
	}
	path = optim(mat, start, finish);
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (path[i] != -1)
		{
			count++;
		}
		else
		{
			break;
		}
	}

	//Что здесь происходит? Почему я должен рабираться, что делает обфусцированный код?
	//В задании не написано, какую проблему должен решать код. Если подразумевалось, что я должен рефакторить (улучшить) код, почему я не знаю, какую задачу решаю, к чему стремлюсь?
	//За что отвечает класс Track? Согласно переводчику, Track - дорога. Или путь. Почему он содержит объем?
	//Прошу простить за то, что не сдержался и оставил эти комментарии.
	switch (count)
	{
	case 1:
	{
		IComponentWrapper car1 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		Composite track = Composite(car1);
		return track;
	}
	case 3:
	{
		IComponentWrapper car1 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		IComponentWrapper car2 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		IComponentWrapper train1 = Train();
		IComponentWrapper plane1 = Plane();
		Composite track = Composite();

		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
			{
				train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
				track = Composite(car1, car2, train1);
			}

			if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
			{
				plane1 = Plane(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
				track = Composite(car1, car2, plane1);
			}
		}

		return track;
	}
	case 5:
	{

		IComponentWrapper car1 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		IComponentWrapper train1 = Train();
		IComponentWrapper plane1 = Plane();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
			{
				train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			}
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
			{
				plane1 = Plane(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
			}
		}

		IComponentWrapper car2 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[3]]) && points[path[3]].find("AP"))
			{
				plane1 = Plane(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
			}
			if ((*it).first.find(points[path[3]]) && points[path[3]].find("TS"))
			{
				train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[3]][path[4]]);
			}
		}

		IComponentWrapper car3 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[4]]))
			{
				car3 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[4]][path[5]]);
			}
		}

		Composite track = Composite(car1, car2, car3, train1, plane1);
		return track;
	}

	case 7:
	{
		IComponentWrapper car1 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		IComponentWrapper train1 = Train();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]))
			{
				train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			}
		}

		IComponentWrapper car2 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		IComponentWrapper plane1 = Plane();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[3]]))
			{
				plane1 = Plane(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
			}
		}

		IComponentWrapper car3 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[4]]))
			{
				car3 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[4]][path[5]]);
			}
		}

		IComponentWrapper train2 = Train();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[5]]))
			{
				train2 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[5]][path[6]]);
			}
		}

		IComponentWrapper car4 = Car();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[6]]))
			{
				car4 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[6]][path[7]]);
			}
		}

		Composite track = Composite(car1, car2, car3, car4, train1, train2, plane1);

		return track;
	}
	}
}

int** Order::matrixUpd(Type type)
{
	int** matrix = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		matrix[i] = new int[SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = matrixDist[i][j];
		}
	}
	switch (type)
	{
	case Type::Economy:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("TS"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
		[[fallthrough]];
	case Type::Standart:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("AP"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
		[[fallthrough]];
	case Type::Turbo:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = 99999;
		}
	}
	return matrix;
}

int* Order::optim(int** arr, int beginPoint, int endPoint)
{
	int* d = new int[SIZE];
	int* v = new int[SIZE];
	int temp, minindex, min;
	int begin_index = beginPoint;

	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 99999;
		v[i] = 1;
	}
	d[begin_index] = 0;

	do {
		minindex = 99999;
		min = 99999;
		for (int i = 0; i < SIZE; i++)
		{
			if ((v[i] == 1) && (d[i] < min))
			{
				min = d[i];
				minindex = i;
			}
		}

		if (minindex != 99999)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (arr[minindex][i] > 0)
				{
					temp = min + arr[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 99999);

	int* ver = new int[SIZE];
	int end = endPoint;
	ver[0] = end;
	int k = 1;
	int weight = d[end];

	while (end != begin_index)
	{
		for (int i = 0; i < SIZE; i++)
			if (arr[end][i] != 0)
			{
				int temp = weight - arr[end][i];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
	}
	for (int i = 0; i < k / 2; i++)
		std::swap(ver[i], ver[k - 1 - i]);
	delete[] d, v;
	return ver;
}

int Order::decr(std::string str)
{
	for (auto it = towns.begin(); it != towns.end(); it++)
	{
		if (str._Equal((*it).first))
			return (*it).second;
	}
	return -1;
}

int main()
{
	std::shared_ptr<IComponentWrapper> component1(new Train());

	Composite composite(*component1);
	//Composite composite(*component1, *component2, *component3, *component4);
	std::cout << composite.sumTime();
	return 0;
}