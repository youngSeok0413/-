#include "BasicFunc.h"
#include "UserDefFunction.h"

int main() {
	ArrDestroyer des;

	double* arr1 = Zeros(10, des);
	std::cout << ArraySize(arr1) << " : ";
	ReadArray(arr1);
	std::cout << std::endl;

	double* arr2 = BasicArr(-5, 5, 1, des);
	std::cout << ArraySize(arr2) << " : ";
	ReadArray(arr2);
	std::cout << std::endl;

	double* arr3 = GetOutputArr(arr2, abs, des);
	std::cout << ArraySize(arr3) << " : ";
	ReadArray(arr3);
	std::cout << std::endl;

	double* arr4 = InputToOutput(arr2, abs);
	std::cout << ArraySize(arr4) << " : ";
	ReadArray(arr4);
	std::cout << std::endl;

	double* arr5 = GetSinSignal(-5, 5, 1, des);
	std::cout << ArraySize(arr5) << " : ";
	ReadArray(arr5);
	std::cout << std::endl;

	double* arr6 = GetCosSignal(-5, 5, 1, des);
	std::cout << ArraySize(arr6) << " : ";
	ReadArray(arr6);
	std::cout << std::endl;

	double* arr7 = GetExpSignal(-5, 5, 1, des);
	std::cout << ArraySize(arr7) << " : ";
	ReadArray(arr7);
	std::cout << std::endl;

	double* arr8 = GetStepSignal(-5, 5, 1, des);
	std::cout << ArraySize(arr8) << " : ";
	ReadArray(arr8);
	std::cout << std::endl;

	double* arr9 = GetRampSignal(-5, 5, 1, des);
	std::cout << ArraySize(arr9) << " : ";
	ReadArray(arr9);
	std::cout << std::endl;

	double* arr10 = copy(arr9, des);
	std::cout << ArraySize(arr10) << " : ";
	ReadArray(arr10);
	std::cout << std::endl;

	double* arr11 = GetOutputArr(arr2, testFunction, des);
	std::cout << ArraySize(arr11) << " : ";
	ReadArray(arr11);
	std::cout << std::endl;

	double* arr12 = XAxisFlip(arr9, des);
	std::cout << ArraySize(arr12) << " : ";
	ReadArray(arr12);
	std::cout << std::endl;

	double* arr13 = YAxisFlip(arr9, des);
	std::cout << ArraySize(arr13) << " : ";
	ReadArray(arr13);
	std::cout << std::endl;

	double* x = new double[3];
	double* h = new double[7];

	des.add(x);
	des.add(h);

	x[0] = 1;
	x[1] = 1;
	x[2] = 1;

	h[0] = 1;
	h[1] = 1;
	h[2] = 0;
	h[3] = 0;
	h[4] = 0;
	h[5] = 1;
	h[6] = 1;

	double* arr15 = conv(x, h, des);
	ReadArray(arr15);
	std::cout << std::endl;

	std::cout << des.size() << std::endl;
	des.destroy();

	return 0;
}
