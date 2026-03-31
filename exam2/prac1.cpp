#include <iostream>

int* filter_evens(int* arr, int size, int& new_size){
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0){
			count++;
		}
	}
	int* new_arr = new int[count];
	for (int i = 0; i < size; i++){
		if (arr[i]%2 == 0){
			new_arr[current_index] = arr[i];
			current_index++;
		}
	}
	new_size = count;
	return new_size;
}
int main(){
	int data[] = {1,2,3,4,5,6};
	int size = 6;
	int filtered_size = 0;
	int* result = filter_evens(data, size, filtered_size);
	for (int i = 0; i < filtered_size; i++){
		std::cout << result[i] << std::endl;
	}
	delete[] result;

	return 0;
}

