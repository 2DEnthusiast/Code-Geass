#include <iostream>
using namespace std;

// Con trỏ
void inputArray(int* &a, int &n) {
	cout << "Nhap vao so luong phan tu trong mang: ";
	cin >> n;
	a = new int[n];
	cout << "\nLan luot nhap cac phan tu trong mang\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}


void deallocateArray(int* &a) {
	delete[]a;
}

void printArray(int *a, int n) {
	cout << "\nCac phan tu trong mang:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";;
	cout << endl;
}

int findMin(int *a, int n) {
	int min = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

int findMaxModulus(int *a, int n) {
	int id = 0,
		max_module = std::abs(a[id]);
	for (int i = 0; i < n; i++)
		if (std::abs(a[i]) > max_module)
		{
			max_module = std::abs(a[i]);
			id = i;
		}
	return id;
}

bool isAscendingOrder(int *a, int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			return false;
	return true;
}

bool isPrime(int num) {
	if (num < 3)
		return num == 2;
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;
	return true;
}
int sumOfPrimes(int *a, int n) {
	int result = 0;
	for (int i = 0; i < n; i++)
		if (isPrime(a[i]) == true)
			result += a[i];
	return result;
}

void swap(int &former, int &latter) {
	int temp = former;
	former = latter;
	latter = temp;
}

void customSort(int* a, int n) {
	int count_zero = 0,
		count_negative = 0;
	// Mang 0 lên đầu mảng
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			swap(a[i], a[count_zero++]);
	// Sắp xếp từ vị trí kế 0 cuối cùng tăng dần
	for (int i = count_zero; i < n - 1; i++){
		for (int j = i; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);

		count_negative += a[i] < 0;
	}
	// Sắp xếp các số âm giảm dần
	for (int i = 0; i < count_negative / 2; i++)
		swap(a[count_zero + i], a[count_negative - i - 1 + count_zero]);
}


void revertArray(int* a, int n) {
	for (int i = 0; i < n / 2; i++)
		swap(a[i], a[n - 1 - i]);
}

int* mergeArrays(int* a, int m, int* b, int n) {
	int *c = new int[m + n];
	for (int i = 0; i < m; i++)
		c[i] = a[i];
	for (int i = 0; i < n; i++)
		c[i + m] = b[i];
	for (int i = 0; i < m + n - 1; i++)
		for (int j = i; j < m + n; j++)
			if (c[i] > c[j])
				swap(c[i], c[j]);
	return c;
}

 //Đệ Quy
int sumOfSquares(int n) {
	if (n == 1)
		return 1;
	return sumOfSquares(n - 1) + n * n;

}

int stringLength(char s[]) {
	if (*s == '\0')
		return 0;
	return stringLength(s + 1) + 1;
}

int ack(int m, int n){
	if (m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return ack(m - 1, 1);
	else if (m > 0 && n>0)
		return ack(m - 1, ack(m, n - 1));
}

// Struct
struct DATE {
	int day;
	int month;
	int year;
};

struct STUDENT {
	char ID[8];
	char name[50];
	DATE birthday;
	char address[100];
	float Math;
	float English;
	float CS;
};


void inputDate(DATE date) {
	cout << "Day: ";
	cin >> date.day;
	cout << "Month: ";
	cin >> date.month;
	cout << "Year: "; 
	cin >> date.year;
}

void inputStudent(STUDENT& student) {
	cout << "Nhap ma so: "; 
	cin.ignore();
	cin.getline(student.ID, 8);

	cin.sync();
	cout << "Nhap ten: ";
	cin.getline(student.name, 50);

	cout << "Nhap ngay sinh: ";
	cin.ignore();
	inputDate(student.birthday);

	cin.ignore();
	cout << "Nhap dia chi nha: ";
	cin.getline(student.address, 100);

	cout << "Nhap diem toan: ";
	cin >> student.Math;

	cout << "Nhap diem anh van: ";
	cin >> student.English;

	cout << "Nhap diem tin hoc: ";
	cin >> student.CS;
	cout << endl;
}

void inputClass(STUDENT* &list, int &n) {
	cout << "Nhap so luong hoc sinh : ";
	cin >> n;
	list = new STUDENT[n];
	cout << "\nLan luot nhap thong tin cho tung hoc sinh\n";
	for (int i = 0; i < n; i++)
		inputStudent(list[i]);
}

void updateScores(STUDENT *list, int n) {
	cout << "Cap nhat diem mon hoc\n";
	for (int i = 0; i < n; i++) {
		cout << "Cap nhat diem cua hoc sinh thu " << i + 1 << ": ";
		cin >> list[i].Math >> list[i].English >> list[i].CS;
	}
}

void printScores(STUDENT *list, int n) {
	cout << "Diem cua cac hoc sinh:\n";
	for (int i = 0; i < n; i++) 
		cout << "Diem hoc sinh thu " << i + 1 << " : " << endl << "Toan: " << list[i].Math << " | " << "Anh van: " << list[i].English << " | " << "Tin hoc: " << list[i].CS << endl << endl;
}

float calculateAverageOfCS(STUDENT *list, int n) {
	float result = 0;
	for (int i = 0; i < n; i++) {
		result += list[i].CS;
		if (i == n - 1)
			return result * 1.0 / i / 3;
	}
}

char* findBestStudent(STUDENT *list, int n) {
	int best_id = 0;
	float score = (list[best_id].Math + list[best_id].English + list[best_id].CS) / 3 * 1.0;
	for (int i = 0; i < n; i++)
		if ((list[i].Math + list[i].English + list[i].CS) / 3 * 1.0 > score)
		{
			score = (list[i].Math + list[i].English + list[i].CS) / 3 * 1.0;
			best_id = i;
		}
	return list[best_id].ID;
}

// Trả về 1 nếu nhỏ hơn, 0 nếu lớn hơn, -1 nếu bằng nhau
short isYounger(DATE d1, DATE d2) {
	if (d1.year != d2.year)
		return d1.year > d2.year;
	if (d1.month != d2.month)
		return d1.month > d2.month;
	if (d1.day != d2.day)
		return d2.day > d2.day;
	return -1;
}

char* findYoungestStudent(STUDENT *list, int n) {
	int youngest_id = 0;
	for (int i = 0; i < n; i++)
		if (isYounger(list[i].birthday, list[youngest_id].birthday))
			youngest_id = i;
	return list[youngest_id].ID;
}

void main() {

	//// Con trỏ
	//int *a, n;
	//inputArray(a, n);
	//printArray(a, n);
	//cout << "\nPhan tu nho nhat trong mang la: " << findMin(a, n) << endl;
	//cout << "\nPhan tu co tri tuyet doi lon nhat trong mang nam tai vi tri thu: " << findMaxModulus(a, n) << endl;
	//cout << "\nMang co tang dan hay khong: " << isAscendingOrder(a, n) << endl;
	//cout << "\nTong cac so nguyen to co trong mang: " << sumOfPrimes(a, n) << endl;
	//cout << "\nMang sau khi duoc sap xep\n";
	//customSort(a, n);
	//printArray(a, n);
	//cout << "\nMang sau khi duoc dao nguoc\n";
	//revertArray(a, n);
	//printArray(a, n);
	//int *b, m;
	//inputArray(b, m);
	//printArray(b, m);
	//int *c = mergeArrays(a, n, b, m);
	//cout << "Mang moi duoc gop:\n";
	//printArray(c, m + n);
	//deallocateArray(b);
	//deallocateArray(c);
	//deallocateArray(a);

	//Đệ quy
	int m = 2,
		n = 3;
	cout << sumOfSquares(m) << endl;
	char *s = "Orange Princess";
	cout << stringLength(s) << endl;
	//cout << ack(3, 10) << endl;

	//// Struct
	//STUDENT *a;
	//int n;
	//inputClass(a, n);
	////updateScores(a, n);
	////printScores(a, n);
	////cout << calculateAverageOfCS(a, n) << endl;
	////cout << findBestStudent(a, n) << endl;
	//cout << findYoungestStudent(a, n) << endl;

}
