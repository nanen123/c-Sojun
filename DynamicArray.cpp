#include<cstdio>
#include<iostream>
#include<cmath>
typedef int Data;

class dArr{
private:
	int dataCnt;
	int leng;
	int* datas;
public:
	dArr(int l){
		datas = new int[l];
		dataCnt = 0; leng = l;
		for (int i = 0; i < leng; i++){
			datas[i] = 0;
		}
	}
	Data& operator[](unsigned int index){
		if (index >= leng)
			__debugbreak();
		return datas[index];
	}
	void PushBack(int data){

		if (dataCnt >= leng)
		{
			Data* temp = new Data[leng + 1];

			for (int i = 0; i < dataCnt; i++) {
				temp[i] = datas[i];
			}

			delete[] datas;
			datas = temp;
			leng++;
		}
		datas[dataCnt++] = data;
	}

	void PushFront(int data){
		if (dataCnt >= leng)
		{
			dataCnt++;
			Data* temp = new Data[leng + 1];

			for (int i = 1; i < dataCnt; i++) {
				temp[i] = datas[i - 1];
			}
			delete[] datas;
			temp[0] = data;
			datas = temp;
			leng++;
		}
		else{
			Data* temp = datas;
			delete[] datas;
			for (int i = 0; i < dataCnt; i++) {
				datas[i + 1] = temp[i];
			}
			datas[0] = data;
		}
	}

	void PrintArray(){
		for (int i = 0; i < leng; i++){
			std::cout << datas[i] << " ";
		}
		std::cout << std::endl;
	}

	void Insert(int index, int data){
		if (index >= dataCnt){
			return;
		}

		if (dataCnt >= leng){
			int* temp = new int[leng + 1];
			for (int i = 0; i < index; i++){
				temp[i] = datas[i];
			}
			for (int i = index + 1; i < leng + 1; i++){
				temp[i] = datas[i - 1];
			}
			temp[index] = data;
			delete[] datas;
			datas = temp;

			leng++;
		}
		else{

			for (int i = dataCnt-1; i >= index; i--){
				datas[i+1] = datas[i];
			}
			datas[index] = data;

		}
		dataCnt++;
	}

	void remove(int index){
		if (index >= dataCnt){
			return;
		}
		for (int i = index; i <leng - 1; i++){
			datas[i] = datas[i + 1];
		}
		leng--;
		dataCnt--;
	}

	void remove(int index1, int index2){
		if (index1 >= dataCnt || index2 >= dataCnt || index1 == index2){
			return;
		}
		if (index1 > index2){
			int temp = index1;
			index1 = index2;
			index2 = temp;
		}

		for (int i = index1; i + abs(index2 - index1) <= leng; i++){
			datas[i] = datas[i + abs(index2 - index1)];
		}
		leng -= abs(index2 - index1);
		dataCnt -= abs(index2 - index1);
	}
};


int main(){

	dArr arr(3);
	arr.PushBack(1);
	arr.Insert(1, 3);
	arr.PushBack(2);
	arr.PushBack(3);
	arr.PrintArray();
	arr.PushFront(1);
	arr.PushFront(2);
	arr.PushFront(3);
	arr.Insert(2, 3);
	arr.PrintArray();
	arr.remove(1, 2);
	arr.PrintArray();
	arr[1] = 3;
	std::cout << arr[5] << std::endl;
}