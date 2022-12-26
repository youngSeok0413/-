#pragma once
#include <iostream>
#include <list>
#include <math.h>
#include <sstream>

struct point
{
	double x;
	double y;
};

//MANGING
//double 동적 배열을 관리하는 클래스(하나만 사용할 것)
class ArrDestroyer {
private:
	std::list<double*> toDestroy;

	int cnt = 0;
public:

	void add(double* toAdd);

	int size();

	void destroy();
};

//point 동적 배을을 관리하는 클래스(하나만 사용할 것)
class PointArrDestroyer {
private:
	std::list<point*> toDestroy;

	int cnt = 0;
public:

	void add(point* toAdd);

	int size();

	void destroy();
};



//CREATE
//사용자가 입력한 크기의 배열을 변환
double* UserArr(int size, ArrDestroyer& destroyer);

//배열의 원소가 0이고 크기가 n인 배열 반환
double* Zeros(int size, ArrDestroyer& destroyer);

//사용자가 지정한 시작점과 끝점이 있을 때, 일정 간격으로 증가하는 수들을 원소로 하는 배열 반환 [start, end)
double* BasicArr(double start, double end, double gap, ArrDestroyer& destroyer);

//READ
//배열 전체의 원소 개수 반환
int ArraySize(double* arr);

//배열 전체를 반환
void ReadArray(double* arr);

//필요한 함수를
//배열 복사
double* copy(double* arr, ArrDestroyer& des);

//입력의 별도 저장 없이 무기억 시스템을 지난 출력 배열을 반환
double* InputToOutput(double* arr, double(*fp)(double));

//무기억 시스템을 지난 출력 배열을 반환
double* GetOutputArr(double* arr, double(*fp)(double), ArrDestroyer& destroyer);

//사인 신호 배열 반환
double* GetSinSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//코사인 신호 배열 반환
double* GetCosSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//지수 신호 반환
double* GetExpSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//계단 신호 반환
double step(double x);

double* GetStepSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//램프 신호 반환
double ramp(double x);
double* GetRampSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//벡터 집합 생성 : (x, y)
point* GetPointArr(double* x, double* y, PointArrDestroyer& destroyer);

//특정 범위에서의 점들의 집합을 생성해줌
point* GetAreaPointArr(double start, double end, double gap, double* y,
	ArrDestroyer& arrDestroyer, PointArrDestroyer& pointDestroyer);

//x축 대칭
double* XAxisFlip(double* arr, ArrDestroyer& destroyer);

//y축 대칭
double* YAxisFlip(double* arr, ArrDestroyer& destroyer);

//conv 함수
double* conv(double* sig, double* h, ArrDestroyer& destroyer);