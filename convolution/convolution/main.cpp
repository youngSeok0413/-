#include <iostream>
#include <list>
#include <math.h>
#include <sstream>

/*
* 해당 프로그램은 신호와 시스템을 실습하기 위한 프로그램입니다.(특별히 편의성을 고려하지 않음)
* 
*/

//MANGING
//모든 동적 배열을 관리하는 클래스(하나만 사용할 것)
class ArrDestroyer {
private: 
	std::list<double*> toDestroy;
	int cnt = 0;
public:

	void add(double* toAdd) {
		toDestroy.push_back(toAdd);
		cnt++;
	}

	int size() {
		return cnt;
	}

	void destroy() {
		for (auto each : toDestroy) {
			if (each != NULL) {
				delete[] each;
				each = NULL;
				cnt--;
			}
		}
		std::cout << "모든 동적 배열이 삭제 되었습니다.";
	}
};

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
	int arrSize = abs((end-start)/gap);

	double* newArr = new double[arrSize];

	for (int i = 0; i < arrSize; i++) newArr[i] = start+ i*gap;

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

int main() {
	ArrDestroyer des;

	double* arr1 = Zeros(10, des);
	std::cout << ArraySize(arr1) << " : ";
	ReadArray(arr1);
	std::cout << std::endl;

	double* arr2 = BasicArr(-10, -1, 0.15, des);
	std::cout << ArraySize(arr2) << " : ";
	ReadArray(arr2);

	std::cout << std::endl;
	std::cout << des.size() << std::endl;
	des.destroy();

	return 0;
}
