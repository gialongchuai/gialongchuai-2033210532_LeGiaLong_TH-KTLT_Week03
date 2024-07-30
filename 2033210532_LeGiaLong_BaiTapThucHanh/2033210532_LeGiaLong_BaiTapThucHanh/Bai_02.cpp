/*
	Bài 2. Cho ma trận vuông a cấp n, chứa số nguyên. Viết các hàm sau:
	1. Tạo/xuất ma trận vuông a chứa số nguyên ngẫu nhiên có cấp n>=5.
	2. Xuất các phần tử trên đường chéo chính.
	3. Xuất các phần tử thuộc đường chéo song song với đường chéo chính.
	4. Tìm phần tử max thuộc tam giác trên của đường chéo chính.
	5. Sắp xếp ma trận tăng dần theo kiểu zic-zắc (tăng từ trái qua phải và từ trên xuống dưới) 
	6. Sắp xếp đường chéo chính tăng dần từ trên xuống dưới.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTran(int a[MAX][MAX], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100;
		}
	}
}

void xuatMaTran(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
void xuatCheoChinh(int a[MAX][MAX], int n) {
	printf("Phan tu tren duong cheo chinh:\n");
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i][i]);
	}
	printf("\n");
}

void xuatCheoPhu(int a[MAX][MAX], int n) {
	printf("Phan tu tren cac duong cheo song song voi duong cheo chinh:\n");
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			printf("%4d", a[i][i + k]);
		}
		printf("\n");
	}
	for (int k = 1; k < n; k++) {
		for (int i = k; i < n; i++) {
			printf("%4d", a[i][i - k]);
		}
		printf("\n");
	}
}

int timMaxTamGiacTren(int a[MAX][MAX], int n) {
	int max = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void sapXepZicZac(int a[MAX][MAX], int n) {
	int temp[MAX * MAX];
	int k = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[k++] = a[i][j];
		}
	}

	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (temp[i] > temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	k = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[k++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = temp[k++];
			}
		}
	}
}

int main() {
	int a[MAX][MAX];
	int n, choice;

	printf("Nhap cap cua ma tran (n >= 5): ");
	scanf("%d", &n);
	if (n < 5) {
		printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
		return 1;
	}

	while (1) {
		printf("\nMenu:\n");
		printf("1. Tao/xuat ma tran\n");
		printf("2. Xuat cac phan tu tren duong cheo chinh\n");
		printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
		printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
		printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
		printf("6. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			taoMaTran(a, n);
			xuatMaTran(a, n);
			break;
		case 2:
			xuatCheoChinh(a, n);
			break;
		case 3:
			xuatCheoPhu(a, n);
			break;
		case 4:
			printf("Phan tu lon nhat trong tam giac tren: %d\n", timMaxTamGiacTren(a, n));
			break;
		case 5:
			sapXepZicZac(a, n);
			xuatMaTran(a, n);
			break;
		case 0:
			return 0;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	}

	return 0;
}
