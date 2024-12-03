#include <stdio.h>

void Shell_sorting(int Arr[], int N) {
	for (int D = N / 2; D > 0; D /= 2) {
		for (int P = D; P < N; P++) {
			int temp = Arr[P];
			int i;
			for (i = P; i >= D && Arr[i - D] > temp; i -= D) {
				Arr[i] = Arr[i - D];
			}
			Arr[i] = temp;
		}
	}

	printf("排序后的数组输出为：");
	for (int i = 0; i < N; i++) {
		printf("%d ", Arr[i]);
	}
	printf("\n");
}

int main() {

	int Arr[10] = { 33,21,55,66,73,8,10,50,30,2 };
	Shell_sorting(Arr, 10);

	return 0;
}