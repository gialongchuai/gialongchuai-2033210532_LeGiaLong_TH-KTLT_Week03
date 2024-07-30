/*
	Bài 1. Cho mảng 2 chiều a có m dòng, n cột chứa số nguyên. Viết các hàm xử lý sau, chú ý 
	các ngoại lệ nếu có:
	1. Tạo và xuất ma trận a chứa các phần tử ngẫu nhiên.
	Lưu ý: 
	- Để lấy số ngẫu nhiên từ 0 đến k, ta sử dụng rand()%(k+1)
	- Để lấy số ngẫu nhiên từ a đến b, ta sử dụng a + rand()%(b-a+1)
	2. Tính và xuất tổng giá trị từng dòng.
	3. Xuất phần tử lớn nhất trên từng cột.
	4. Xuất các phần tử thuộc các đường biên trên, dưới, trái và phải.
	5. Xuất các phần tử cực đại
	6. Xuất các phần tử hoàng hậu.
	7. Xuất các phần tử là điểm yên ngựa.
	8. Xuất dòng chỉ chứa số chẵn.
	9. Sắp xếp mảng a tăng theo từng dòng.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN_VAL 0    // Giá trị tối thiểu cố định
#define MAX_VAL 100  // Giá trị tối đa cố định

// Hàm tạo ma trận ngẫu nhiên
void taoMaTran(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = MIN_VAL + rand() % (MAX_VAL - MIN_VAL + 1);
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}


// Hàm tính tổng giá trị từng dòng
void tongGiaTriTungDong(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int tong = 0;
		for (int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		printf("Tong dong %d: %d\n", i, tong);
	}
}

// Hàm xuất phần tử lớn nhất trên từng cột
void phanTuLonNhatTungCot(int a[][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) max = a[i][j];
		}
		printf("Max cot %d: %d\n", j, max);
	}
}
// Hàm xuất các phần tử thuộc các đường biên
void phanTuDuongBien(int a[][MAX], int m, int n) {
	// Xuất đường biên trên
	printf("Duong bien tren: ");
	for (int j = 0; j < n; j++) {
		printf("%5d", a[0][j]);
	}

	// Xuất đường biên dưới
	printf("\nDuong bien duoi: ");
	for (int j = 0; j < n; j++) {
		printf("%5d", a[m - 1][j]);
	}

	// Xuất đường biên trái
	printf("\nDuong bien trai: ");
	for (int i = 1; i < m - 1; i++) {
		printf("%5d", a[i][0]);
	}

	// Xuất đường biên phải
	printf("\nDuong bien phai: ");
	for (int i = 1; i < m - 1; i++) {
		printf("%5d", a[i][n - 1]);
	}
	printf("\n");
}
// Hàm xuất các phần tử cực đại
void phanTuCucDai(int a[][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int isMax = 1;
			for (int k = 0; k < m; k++) {
				if (a[k][j] > a[i][j]) {
					isMax = 0;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (a[i][k] > a[i][j]) {
					isMax = 0;
					break;
				}
			}
			if (isMax) {
				printf("%5d", a[i][j]);
			}
		}
	}
	printf("\n");
}
// Hàm chính
int main() {
	int a[MAX][MAX];
	int m, n, choice;

	srand(time(NULL));

	do {
		printf("\nMenu:\n");
		printf("1. Tao va xuat ma tran\n");
		printf("2. Tong gia tri tung dong\n");
		printf("3. Phan tu lon nhat tren tung cot\n");
		printf("4. Phan tu duong bien\n");
		printf("5. Phan tu cuc dai\n");
		printf("6. Phan tu hoang hau\n");
		printf("7. Phan tu diem yen ngua\n");
		printf("8. Dong chi chua so chan\n");
		printf("9. Sap xep mang tang theo tung dong\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap so dong (m): ");
			scanf("%d", &m);
			printf("Nhap so cot (n): ");
			scanf("%d", &n);
			taoMaTran(a, m, n);
			printf("Ma tran vua tao:\n");
			xuatMaTran(a, m, n);
			break;
		case 2:
			tongGiaTriTungDong(a, m, n);
			break;
		case 3:
			phanTuLonNhatTungCot(a, m, n);
			break;
		case 4:
			phanTuDuongBien(a, m, n);
			break;
		case 5:
			phanTuCucDai(a, m, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;

		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
