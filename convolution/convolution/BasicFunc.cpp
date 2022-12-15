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
	std::cout << "모든 동적 배열이 삭제 되었습니다.";
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
	std::cout << "모든 동적 배열이 삭제 되었습니다.";
}

//CREATE
//사용자가 입력한 크기의 배열을 변환
double* UserArr(int size, ArrDestroyer& destroyer) {
	double* newArr = new double[size];

	destroyer.add(newArr);

	return newArr;
}

//배열의 원소가 0이고 크기가 n인 배열 반환
double* Zeros(int size, ArrDestroyer& destroyer) {
	double* newArr = new double[size];

	for (int i = 0; i < size; i++) newArr[i] = 0;

	destroyer.add(newArr);

	return newArr;
}

//사용자가 지정한 시작점과 끝점이 있을 때, 일정 간격으로 증가하는 수들을 원소로 하는 배열 반환 [start, end)
double* BasicArr(double start, double end, double gap, ArrDestroyer& destroyer) {
	int arrSize = abs((end - start) / gap);

	double* newArr = new double[arrSize];

	for (int i = 0; i < arrSize; i++) newArr[i] = start + i * gap;

	destroyer.add(newArr);

	return newArr;
}

//READ
//배열 전체의 원소 개수 반환
int ArraySize(double* arr) {
	return _msize(arr) / sizeof(double);
}

//배열 전체를 반환
void ReadArray(double* arr) {
	int sz = ArraySize(arr);

	std::cout << "[ ";
	for (int i = 0; i < sz; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]";
}

//필요한 함수를
//배열 복사
double* copy(double* arr, ArrDestroyer& des) {
	int sz = ArraySize(arr);

	double* newArr = new double[sz];

	for (int i = 0; i < sz; i++) newArr[i] = arr[i];

	des.add(newArr);

	return newArr;
}

//입력의 별도 저장 없이 무기억 시스템을 지난 출력 배열을 반환
double* InputToOutput(double* arr, double(*fp)(double)) {
	int sz = ArraySize(arr);

	for (int i = 0; i < sz; i++) arr[i] = fp(arr[i]);

	return arr;
}

//무기억 시스템을 지난 출력 배열을 반환
double* GetOutputArr(double* arr, double(*fp)(double), ArrDestroyer& destroyer) {
	int sz = ArraySize(arr);

	double* output = new double[sz];

	for (int i = 0; i < sz; i++) output[i] = fp(arr[i]);

	destroyer.add(output);

	return output;
}

//사인 신호 배열 반환
double* GetSinSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), sin);

	return newArr;
}

//코사인 신호 배열 반환
double* GetCosSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), cos);

	return newArr;
}

//지수 신호 반환
double* GetExpSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), exp);

	return newArr;
}

//계단 신호 반환
double step(double x) {
	if (x >= 0) return 1;
	else return 0;
}
double* GetStepSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), step);

	return newArr;
}

//램프 신호 반환
double ramp(double x) {
	if (x >= 0) return x;
	else return 0;
}
double* GetRampSignal(double start, double end, double gap, ArrDestroyer& destroyer) {
	double* newArr = InputToOutput(BasicArr(start, end, gap, destroyer), ramp);

	return newArr;
}

//벡터 집합 생성 : (x, y)
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

//특정 범위에서의 점들의 집합을 생성해줌
point* GetAreaPointArr(double start, double end, double gap, double* y, 
	ArrDestroyer& arrDestroyer, PointArrDestroyer& pointDestroyer) {
	double* xAxis = BasicArr(start, end, gap, arrDestroyer);
	return GetPointArr(xAxis, y, pointDestroyer);
}

//아 클래스로 구성할 걸ㅠㅠ
