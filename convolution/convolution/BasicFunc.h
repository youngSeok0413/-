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
//double ���� �迭�� �����ϴ� Ŭ����(�ϳ��� ����� ��)
class ArrDestroyer {
private:
	std::list<double*> toDestroy;

	int cnt = 0;
public:

	void add(double* toAdd);

	int size();

	void destroy();
};

//point ���� ������ �����ϴ� Ŭ����(�ϳ��� ����� ��)
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
//����ڰ� �Է��� ũ���� �迭�� ��ȯ
double* UserArr(int size, ArrDestroyer& destroyer);

//�迭�� ���Ұ� 0�̰� ũ�Ⱑ n�� �迭 ��ȯ
double* Zeros(int size, ArrDestroyer& destroyer);

//����ڰ� ������ �������� ������ ���� ��, ���� �������� �����ϴ� ������ ���ҷ� �ϴ� �迭 ��ȯ [start, end)
double* BasicArr(double start, double end, double gap, ArrDestroyer& destroyer);

//READ
//�迭 ��ü�� ���� ���� ��ȯ
int ArraySize(double* arr);

//�迭 ��ü�� ��ȯ
void ReadArray(double* arr);

//�ʿ��� �Լ���
//�迭 ����
double* copy(double* arr, ArrDestroyer& des);

//�Է��� ���� ���� ���� ����� �ý����� ���� ��� �迭�� ��ȯ
double* InputToOutput(double* arr, double(*fp)(double));

//����� �ý����� ���� ��� �迭�� ��ȯ
double* GetOutputArr(double* arr, double(*fp)(double), ArrDestroyer& destroyer);

//���� ��ȣ �迭 ��ȯ
double* GetSinSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//�ڻ��� ��ȣ �迭 ��ȯ
double* GetCosSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//���� ��ȣ ��ȯ
double* GetExpSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//��� ��ȣ ��ȯ
double step(double x);

double* GetStepSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//���� ��ȣ ��ȯ
double ramp(double x);
double* GetRampSignal(double start, double end, double gap, ArrDestroyer& destroyer);

//���� ���� ���� : (x, y)
point* GetPointArr(double* x, double* y, PointArrDestroyer& destroyer);

//Ư�� ���������� ������ ������ ��������
point* GetAreaPointArr(double start, double end, double gap, double* y,
	ArrDestroyer& arrDestroyer, PointArrDestroyer& pointDestroyer);

//x�� ��Ī
double* XAxisFlip(double* arr, ArrDestroyer& destroyer);

//y�� ��Ī
double* YAxisFlip(double* arr, ArrDestroyer& destroyer);

//conv �Լ�
double* conv(double* sig, double* h, ArrDestroyer& destroyer);