#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>

// Họ và Tên: Nguyễn Văn Thông
//MSSV: 1760197

using namespace std;//In mảng
void OutPut(int a[], int N)
{
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
}

//Hoán đổi a, b
void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

// sắp xếp chọn(Selection Sort)
void SelectionSort(int a[], int N){
	int min; 
	for (int i = 0; i<N - 1; i++)
	{ 
		min = i;
		for (int j = i + 1; j < N; j++)
		{ 
			if (a[j] < a[min])
			{
				min = j; 
			}
		}
		if (min != i)
		{
			Swap(a[min], a[i]); 
		}
	}
}
// sắp xếp vun đống(Heap Sort)
void Shift(int a[], int left, int right){
	int  x, curr, joint;
	curr = left;
	joint = 2 * curr + 1;      
	x = a[curr];
	while (joint <= right)
	{
		if (joint < right)
		{    
			if (a[joint] < a[joint + 1])
			{
				joint = joint + 1;
			}
		}
		if (a[joint] < x)
		{
			break;              
		}
		a[curr] = a[joint];
		curr = joint;  
		joint = 2 * curr + 1;
	}
	a[curr] = x;
}

void CreatHeap(int a[], int N)
{
	int l = N / 2;
	while (l >= 0)
	{
		Shift(a, l, N);
		l--;
	}
}

void HeapSort(int a[], int N)
{
	int r;
	CreatHeap(a, N);
	r = N - 1;
	while (r > 0)
	{
		Swap(a[0], a[r]);
		r--;
		Shift(a, 0, r);
	}
}
// sắp xếp nhanh(Quick Sort)
void QuickSort(int a[], int left, int right)
{
	int i, j, x;
	//demSoSanh++;
	if (left >= right)
	{
		return;
	}
	x = a[(left + right) / 2]; 
	//demGan++;
	i = left; j = right;
	//demGan += 2;
	//demSoSanh++;
	while (i < j)
	{
		//demSoSanh++;
		while (a[i] < x)
		{
			i++;
			//demGan++;
		}
		//demSoSanh++;
		while (a[j] > x)
		{
			j--;
			//demGan++;
		}
		//demSoSanh++;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		//	demGan += 2;
		}
	}
	QuickSort(a, left, j);
	QuickSort(a, i, right);
}
// sắp xếp trộn(Merge Sort)
#define MAX 100000
int b[MAX], c[MAX], nb, nc;

void Distribute(int  a[], int N, int &nb, int &nc, int k)
{
	int i, pa, pb, pc; 
	pa = pb = pc = 0;
	while (pa < N)
	{
		for (i = 0; (pa < N) && (i < k); i++, pa++, pb++)
		{  
			b[pb] = a[pa];
		}
		for (i = 0; (pa < N) && (i < k); i++, pa++, pc++)
		{  
			c[pc] = a[pa];
		}
	}
	nb = pb;
	nc = pc;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void MergeSubarr(int a[], int nb, int nc, int &pa, int &pb, int &pc, int k){
	int rb, rc;
	rb = min(nb, pb + k);
	rc = min(nc, pb + k);
	while ((pb < rb) && (pc < rc))
	{
		if (b[pb] < c[pc])
			a[pa++] = b[pb++];
		else  a[pa++] = c[pc++];
	}
	while (pb < rb)
	{
		a[pa++] = b[pb++];
	}
	while (pc < rc)
	{
		a[pa++] = c[pc++];
	}
}

void Merge(int a[], int nb, int nc, int k){
	int pa, pb, pc;
	pa = pb = pc = 0;
	while ((pb < nb) && (pc < nc))
	{
		MergeSubarr(a, nb, nc, pa, pb, pc, k);
	}
	while (pb < nb)
	{
		a[pa++] = b[pb++];   
		while (pc < nc)
		{
			a[pa++] = c[pc++]; 
		}
	}
}

void MergeSort(int a[], int N)
{
	int pa, pb, pc;
	int i, k = 1;
	do{
		Distribute(a, N, nb, nc, k);
		Merge(a, nb, nc, k);
		k *= 2;
	} while (k < N);
}
void main(){
	// Họ và Tên: Nguyễn Văn Thông
	//MSSV: 1760197

	cout << "Ho va Ten:Nguyen Van Thong \nMSSV:1760197 \n";
	int n;
	cout << "Bai thi: Giua ki I\nMon:CTDL & GT ";
	cout << "\n\nNeu cho 4 thuat toan deu sap xep tang dan.\nGia su so luong phan tu la: ";
	cin >> n;

	cout << "\n<1>Du lieu ngau nhien(Random)";
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (n+1);
		//cout << a[i] << " ";
	}
	//------------//
	// Time Selection Sort
	clock_t start = clock();// hàm bắt đầu đo thời gian chương trình
	SelectionSort(a, n);
	clock_t finish = clock();// hàm kết thúc chương trình
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Selection Sort): " << duration << " giay";

	//------------//
	// Time Heap Sort
	clock_t start1 = clock();// hàm bắt đầu đo thời gian chương trình
	HeapSort(a, n);
	clock_t finish1 = clock();// hàm kết thúc chương trình
	double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Heap Sort): " << duration1 << " giay";

	//------------//
	// Time Quick Sort
	clock_t start2 = clock();// hàm bắt đầu đo thời gian chương trình
	QuickSort(a, 0, n - 1);
	clock_t finish2 = clock();// hàm kết thúc chương trình
	double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Quick Sort): " << duration2 << " giay";

	//------------//
	// Time Merge Sort
	clock_t start3 = clock();// hàm bắt đầu đo thời gian chương trình
	MergeSort(a, n);
	clock_t finish3 = clock();// hàm kết thúc chương trình
	double duration3 = (double)(finish3 - start3) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Merge Sort): " << duration3 << " giay" << endl;

/////////////////////////////////////////////////////////////////////////////////////

	cout << "\n<2>Du lieu co thu tu(Sorted)";
	sort(a, a + n);
	//OutPut(a, n);
	//------------//
	// Time Selection Sort
	clock_t start4 = clock();// hàm bắt đầu đo thời gian chương trình
	SelectionSort(a, n);
	clock_t finish4 = clock();// hàm kết thúc chương trình
	double duration4= (double)(finish4 - start4) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Selection Sort): " << duration4 << " giay";

	//------------//
	// Time Heap Sort
	clock_t start5 = clock();// hàm bắt đầu đo thời gian chương trình
	HeapSort(a, n);
	clock_t finish5 = clock();// hàm kết thúc chương trình
	double duration5 = (double)(finish5 - start5) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Heap Sort): " << duration5 << " giay";

	//------------//
	// Time Quick Sort
	clock_t start6 = clock();// hàm bắt đầu đo thời gian chương trình
	QuickSort(a, 0, n - 1);
	clock_t finish6 = clock();// hàm kết thúc chương trình
	double duration6 = (double)(finish6 - start6) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Quick Sort): " << duration6 << " giay";

	//------------//
	// Time Merge Sort
	clock_t start7 = clock();// hàm bắt đầu đo thời gian chương trình
	MergeSort(a, n);
	clock_t finish7 = clock();// hàm kết thúc chương trình
	double duration7 = (double)(finish7 - start7) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Merge Sort): " << duration7 << " giay" << endl;

	/////////////////////////////////////////////////////////////////////////////////////

	cout << "\n<3>Du lieu co thu tu nguoc(Reversed)";
	reverse(a, a + n);
	//OutPut(a, n);
	//------------//
	// Time Selection Sort
	clock_t start8 = clock();// hàm bắt đầu đo thời gian chương trình
	SelectionSort(a, n);
	clock_t finish8 = clock();// hàm kết thúc chương trình
	double duration8 = (double)(finish8 - start8) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Selection Sort): " << duration8 << " giay";

	//------------//
	// Time Heap Sort
	clock_t start9 = clock();// hàm bắt đầu đo thời gian chương trình
	HeapSort(a, n);
	clock_t finish9 = clock();// hàm kết thúc chương trình
	double duration9 = (double)(finish9 - start9) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Heap Sort): " << duration9 << " giay";

	//------------//
	// Time Quick Sort
	clock_t start10 = clock();// hàm bắt đầu đo thời gian chương trình
	QuickSort(a, 0, n - 1);
	clock_t finish10 = clock();// hàm kết thúc chương trình
	double duration10 = (double)(finish10 - start10) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Quick Sort): " << duration10 << " giay";

	//------------//
	// Time Merge Sort
	clock_t start11 = clock();// hàm bắt đầu đo thời gian chương trình
	MergeSort(a, n);
	clock_t finish11 = clock();// hàm kết thúc chương trình
	double duration11 = (double)(finish11 - start11) / CLOCKS_PER_SEC;
	cout << "\nThoi gian thuc thi(Merge Sort): " << duration11 <<" giay"<< endl << endl;
	cout << "-------------------------END------------------------\n";
	system("pause");
	
	
}