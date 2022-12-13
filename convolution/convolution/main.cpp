#include <iostream>
#include <list>
#include <math.h>
#include <sstream>

/*
* �ش� ���α׷��� ��ȣ�� �ý����� �ǽ��ϱ� ���� ���α׷��Դϴ�.(Ư���� ���Ǽ��� ������� ����)
* 
*/

//MANGING
//��� ���� �迭�� �����ϴ� Ŭ����(�ϳ��� ����� ��)
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
		std::cout << "��� ���� �迭�� ���� �Ǿ����ϴ�.";
	}
};

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
	int arrSize = abs((end-start)/gap);

	double* newArr = new double[arrSize];

	for (int i = 0; i < arrSize; i++) newArr[i] = start+ i*gap;

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
