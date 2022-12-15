#include "BasicFunc.h"

void ArrDestroyer::add(double* toAdd) {
	toDestroy.push_back(toAdd);
	cnt++;
}

int ArrDestroyer::size() {
	return cnt;
}

void ArrDestroyer::destroy() {
	for (auto each : toDestroy) {
		if (each != NULL) {
			delete[] each;
			each = NULL;
			cnt--;
		}
	}
	std::cout << "��� ���� �迭�� ���� �Ǿ����ϴ�.";
}

void PointArrDestroyer::add(point* toAdd) {
	toDestroy.push_back(toAdd);
	cnt++;
}

int PointArrDestroyer::size() {
	return cnt;
}

void PointArrDestroyer::destroy() {
	for (auto each : toDestroy) {
		if (each != NULL) {
			delete[] each;
			each = NULL;
			cnt--;
		}
	}
	std::cout << "��� ���� �迭�� ���� �Ǿ����ϴ�.";
}

//CREATE
//����ڰ� �Է��� ũ���� �迭�� ��ȯ
double* UserArr(int size, ArrDestroyer& destroyer) {
	double* newArr = new double[size];

	destroyer.add(newArr);

	return newArr;
}

//�迭�� ���Ұ� 0�̰� ũ�Ⱑ n�� �迭 ��ȯ
double* Zeros(int size, ArrDestroyer& destroyer) {
	double* newArr = new double[size];

	for (int i = 0; i < size; i++) newArr[i] = 0;

	destroyer.add(newArr);

	return newArr;
}

//����ڰ� ������ �������� ������ ���� ��, ���� �������� �����ϴ� ������ ���ҷ� �ϴ� �迭 ��ȯ [start, end)
double* BasicArr(double start, double end, double gap, ArrDestroyer& destroyer) {
	int arrSize = abs((end - start) / gap);

	double* newArr = new double[arrSize];

	for (int i = 0; i < arrSize; i++) newArr[i] = start + i * gap;

	destroyer.add(newArr);

	return newArr;
}

//READ
//�迭 ��ü�� ���� ���� ��ȯ
int ArraySize(double* arr) {
	return _msize(arr) / sizeof(double);
}

//�迭 ��ü�� ��ȯ
void ReadArray(double* arr) {
	int sz = ArraySize(arr);

	std::cout << "[ ";
	for (int i = 0; i < sz; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]";
}

//�ʿ��� �Լ���
//�迭 ����
double* copy(double* arr, ArrDestroyer& des) {
	int sz = ArraySize(arr);

	double* newArr = new double[sz];

	for (int i = 0; i < sz; i++) newArr[i] = arr[i];

	des.add(newArr);

	return newArr;
}

//�Է��� ���� ���� ���� ����� �ý����� ���� ��� �迭�� ��ȯ
double* InputToOutput(double* arr, double(*fp)(double)) {
	int sz = ArraySize(arr);

	for (int i = 0; i < sz; i++) arr[i] = fp(arr[i]);

	return arr;
}

//����� �ý����� ���� ��� �迭�� ��ȯ
double* GetOutputArr(double* arr, double(*fp)(double), ArrDestroyer& destroyer) {
	int sz = ArraySize(arr);

	double* output = new double[sz];

	for (int i = 0; i < sz; i++) output[i] = fp(arr[i]);

	destroyer.add(output);

	return output;
}

//���� ��ȣ �迭 ��ȯ
double* GetSinSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), sin);

	return newArr;
}

//�ڻ��� ��ȣ �迭 ��ȯ
double* GetCosSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), cos);

	return newArr;
}

//���� ��ȣ ��ȯ
double* GetExpSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), exp);

	return newArr;
}

//��� ��ȣ ��ȯ
double step(double x) {
	if (x >= 0) return 1;
	else return 0;
}
double* GetStepSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), step);

	return newArr;
}

//���� ��ȣ ��ȯ
double ramp(double x) {
	if (x >= 0) return x;
	else return 0;
}
double* GetRampSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), ramp);

	return newArr;
}

//���� ���� ���� : (x, y)
point* GetPointArr(double* x, double* y, PointArrDestroyer& destroyer) {
	int szX = ArraySize(x);
	int szY = ArraySize(y);

	if (szX == szY) {
		point* newArr = new point[szX];
		for (int i = 0; i < szX; i++) newArr[i] = { x[i], y[i] };

		destroyer.add(newArr);

		return newArr;
	}
	else return NULL;
}

//Ư�� ���������� ������ ������ ��������
point* GetAreaPointArr(double start, double end, double gap, double* y, 
	ArrDestroyer& arrDestroyer, PointArrDestroyer& pointDestroyer) {
	double* xAxis = BasicArr(start, end, gap, arrDestroyer);
	return GetPointArr(xAxis, y, pointDestroyer);
}

//�� Ŭ������ ������ �ɤФ�
