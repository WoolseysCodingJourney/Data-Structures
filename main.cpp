#include <iostream>
using namespace std;

const int MAX = 10;

struct List {
	int array[MAX];
	int len;
};

void enterList(List& list)
{
	cout << "Nhap so luong phan tu cua Danh Sach Dac:";
	cin >> list.len;
	for (int i = 0; i < list.len; i++)
	{
		cout << "\nNhap phan tu thu [" << i << "]:";
		cin >> list.array[i];
	}
}

void printList(List list)
{
	for (int i = 0; i < list.len; i++)
	{
		cout << list.array[i] << " ";
	}
	cout << "{Len: "<<list.len <<"}" << endl;
}
void chenGiaTriVaoCuoiDS(List& list)
{
	int x;
	cout << "\n\nNhap gia tri can chen: ";
	cin >> x;
	if (list.len == MAX)
	{
		cout << "\n\nMang Day! Khong the chen";
		return;
	}
	list.array[list.len] = x;
	list.len++;
	cout << "\n\nMang sau khi chen them " << x << " : ";
	printList(list);
}
//vd 1 2 3 1
//   0 1 2 3
// x = 1
//=> 0 3

List timKiemPhanTuGiaTriX_TraVeDSIndex(List list)
{
	List results;
	results.len = 0;
	int x;
	cout << "\n\nNhap gia tri can tim: ";
	cin >> x;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			results.array[results.len++] = i;
		}
	}
	return results;
}

void xoaPhanTuGiaTriX(List& list)
{
	int x;
	cout << "\n\nNhap gia tri can xoa: ";
	cin >> x;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			for (int j = i; j < list.len - 1; j++)
			{
				list.array[j] = list.array[j + 1];
			}
			list.len--;
			i--;
		}
	}
	cout << "\n\nMang sau khi xoa toan bo phan tu co gia tri " << x << ": ";
	printList(list);
}

void suaPhanTuGiaTriX(List& list)
{
	int x, y;
	cout << "\n\nNhap gia tri can sua: ";
	cin >> x;
	cout << "\n\nNhap gia tri moi: ";
	cin >> y;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			list.array[i] = y;
		}
	}
	cout << "\n\nMang sau khi sua toan bo phan tu co gia tri " << x << " thanh gia tri "<<y<<": ";
	printList(list);
}

//1	Trả về số lượng phần tử có giá trị là x.
void cau1(List list)
{
	int x;
	cout << "\n\nNhap x:";
	cin >> x;
	int count = 0;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			count++;
		}
	}
	if (count > 0)
	{
		cout << "\nSo luong phan tu co gia tri " << x << ": " << count;
	}
	else
	{
		cout << "\n\nMang khong ton tai gia tri " << x;
	}
}
//2	Trả về địa chỉ phần tử có giá trị x thứ 2 tìm thấy trong danh sách
int timViTriGiaTriXThu2(List list, int x)
{
	int pos = -1;
	int count = 0;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			count++;
			if (count > 1)
			{
				pos = i;
				break;
			}
		}
	}
	return pos;
}
void cau2(List list)
{
	int x;
	cout << "\n\nNhap x:";
	cin >> x;
	int pos = timViTriGiaTriXThu2(list, x);
	if (pos == -1)
	{
		cout << "\n\nMang khong ton tai gia tri " << x << " thu 2!";
	}
	else
	{
		cout << "\n\nDia chi cua phan tu co gia tri " << x << " thu 2:" << pos;
	}
}
//3	Viết hàm xuất ra các phần tử có giá trị bằng tổng 02 phần tử liền kề trước đó.
void cau3(List list)
{
	if (list.len < 3)
	{
		cout << "\n\nMang khong du dai de thuc hien kiem tra!";
		return;
	}
	//vd 1 2 3 4
	cout << "\n\nCac phan tu co gia tri bang tong 2 phan tu lien ke truoc do: ";
	bool flag = false;
	for (int i = 2; i < list.len; i++)
	{
		if (list.array[i] == list.array[i - 1] + list.array[i - 2])
		{
			flag = true;
			cout << " " << list.array[i];
		}
	}
	if (flag == false)
	{
		cout << " Khong co";
	}
}
//4	Viết hàm kiểm tra mảng có thứ tự tăng hay không ? Nếu có trả về 1, ngược lại trả về 0.
bool kiemTraMangTang(List list)
{
	if (list.len == 1)
	{
		return true;
	}
	else if (list.len == 0)
	{
		return false;
	}
	for (int i = 0; i < list.len - 1; i++)
	{
		if (list.array[i] >= list.array[i + 1])
		{
			return false;
		}
	}
	return true;
}
void cau4(List list)
{
	bool isIncrease = kiemTraMangTang(list);
	if (isIncrease == true)
	{
		cout << "\n\nMang tang!";
	}
	else
	{
		cout << "\n\nMang khong tang!";
	}
}
//5	Viết hàm kiểm tra trong DS này có phần tử nào là số nguyên tố hay không ? Nếu có trả về vị trí phần tử đầu tiên được tìm thấy.
bool kiemTraSoNguyenTo(int num)
{
	if (num < 2) return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
void cau5(List list)
{
	for (int i = 0; i < list.len; i++)
	{
		if (kiemTraSoNguyenTo(list.array[i]))
		{
			cout << "\n\nVi tri phan tu dau tien la so Nguyen To duoc tim thay: " << i;
			
			return;
		}
	}
	cout << "\n\nDanh sach khong ton tai so nguyen to";
}
//6	Viết hàm trả về số lượng các số hoàn hảo được tìm thấy trong danh sách.
bool kiemTraSoHoanHao(int num)
{
	if (num < 6) return false;
	int sum = 0;
	for (int i = 1; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			sum += i;
		}
	}
	if (sum == num)
	{
		return true;
	}
	return false;
}
void cau6(List list)
{
	int count = 0;
	for (int i = 0; i < list.len; i++)
	{
		if (kiemTraSoHoanHao(list.array[i]))
		{
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\n\nDanh sach khong ton tai so hoan hao!";
	}
	else
	{
		cout << "\n\nSO luong so hoan hao co trong danh sach: " << count;
	}
}
//7	Viết hàm trả về giá trị số âm lớn nhất trong DS
void cau7(List list)
{
	int max = 0;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] < 0)
		{
			if (max == 0)
			{
				max = list.array[i];
			}
			else if(max < list.array[i])
			{
				max = list.array[i];
			}
		}
	}
	if (max == 0)
	{

		cout << "\n\nDanh sach khong ton tai so Am";
	}
	else
	{
		cout << "\n\nSo Am lon nhat trong Danh sach: " << max;
	}
}
//8	Sử dụng thuật toán sắp xếp tuần tư, hãy viết hàm sắp xếp DS giảm dần.
void selectionSort(List& list, bool mode)
{
	for (int i = 0; i < list.len - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < list.len; j++)
		{
			if (mode == true)//sap tang
			{
				if (list.array[j] < list.array[minIndex])
				{
					minIndex = j;
				}
			}
			else
			{
				if (list.array[j] > list.array[minIndex])
				{
					minIndex = j;
				}
			}
		}
		if (minIndex != i)
		{
			int temp = list.array[i];
			list.array[i] = list.array[minIndex];
			list.array[minIndex] = temp;
		}
	}
}
void cau8(List list)
{
	cout << "\n\nDanh sach truoc khi duoc sap xep giam dan: ";
	printList(list);
	selectionSort(list, false);
	cout << "\n\nDanh sach sau khi duoc sap xep giam dan: ";
	printList(list);
}
//9	Viết hàm chèn giá trị a vào sau phần tử có giá trị x tìm thấy đầu tiên.
void cau9(List& list)
{
	int x;
	cout << "\n\nNhap x can tim:";
	cin >> x;
	int a;
	cout << "\n\nNhap a chen chen sau "<<x<<":";
	cin >> a;
	bool flag = false;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			flag = true;
			if (list.len == MAX)
			{
				cout << "\n\nMang day!";
				return;
			}
			for (int j = list.len; j > i; j--)
			{
				list.array[j] = list.array[j - 1];
			}
			list.array[i + 1] = a;
			list.len++;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\nDanh sach sau khi chen " << a << " vao sau " << x << " dau tien: ";
		printList(list);
	}
	else
	{
		cout << "\n\nKhong tim thay phan tu co gia tri " << x;
	}

}
//10	Viết hàm chèn giá trị a vào trước vị trí pos.
void cau10(List& list)
{
	int a;
	cout << "\n\nNhap a can chen:";
	cin >> a;
	int pos;
	cout << "\n\nNhap vi tri pos: ";
	cin >> pos;
	if (pos <= 0 || pos > list.len)
	{
		cout << "\n\nVi tri khong hop le!";
		return;
	}
	if (list.len == MAX)
	{
		cout << "\n\nMang day!";
		return;
	}
	for (int i = list.len; i >= pos; i--)
	{
		list.array[i] = list.array[i - 1];
	}
	list.array[pos-1] = a;
	list.len++;
	cout << "\n\nDanh sach sau khi chen " << a << " truoc vi tri " << pos << ": ";
	printList(list);
}
//11	Viết hàm xóa phần tử có giá trị x cuối cùng được tìm thấy
void cau11(List& list)
{
	int x;
	cout << "\n\nNhap x:";
	cin >> x;
	bool flag = false;
	for (int i = list.len - 1; i >= 0; i--)
	{
		if (list.array[i] == x)
		{
			flag = true;
			for (int j = i; j < list.len -1; j++)
			{
				list.array[j] = list.array[j + 1];
			}
			list.len--;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\nDanh sach sau khi xoa phan tu co gia tri " << x << " cuoi cung: ";
		printList(list);
	}
	else
	{
		cout << "\n\nKhong tim thay bat ki phan tu nao co gia tri " << x;
	}
}
//12	Viết hàm xóa tất cả các phần tử có giá trị x.
 void cau12(List& list)
{
	int x;
	cout << "\n\nNhap x:";
	cin >> x;
	bool flag = false;
	for (int i = 0; i < list.len; i++)
	{
		if (list.array[i] == x)
		{
			flag = true;
			for (int j = i; j < list.len - 1; j++)
			{
				list.array[j] = list.array[j + 1];
			}
			list.len--;
			i--;
		}
	}
	if (flag)
	{
		cout << "\n\nDanh sach sau khi xoa phan tu co gia tri " << x << ": ";
		printList(list);
	}
	else
	{
		cout << "\n\nKhong tim thay bat ki phan tu nao co gia tri " << x;
	}
}
//13	Viết hàm xóa phần tử có giá trị x thứ 2 được tìm thấy.
 void cau13(List& list)
 {
	 int x;
	 cout << "\n\nNhap x:";
	 cin >> x;
	 int count = 0;
	 for (int i = 0; i < list.len; i++)
	 {
		 if (list.array[i] == x)
		 {
			 count++;
			 if (count > 1)
			 {
				 for (int j = i; j < list.len - 1; j++)
				 {
					 list.array[j] = list.array[j + 1];
				 }
				 list.len--;
				 i--;
				 break;
			 }
			
		 }
	 }
	 if (count > 1)
	 {
		 cout << "\n\nDanh sach sau khi xoa phan tu co gia tri " << x << " thu 2: ";
		 printList(list);
	 }
	 else
	 {
		 cout << "\n\nKhong tim thay bat ki phan tu nao co gia tri " << x <<" thu 2";
	 }
 }
//14	Viết hàm xóa tất cả các phần tử có giá trị x từ phần tử thứ 2 trở đi được tìm thấy.
 void cau14(List& list)
 {
	 int x;
	 cout << "\n\nNhap x:";
	 cin >> x;
	 int count = 0;
	 for (int i = 0; i < list.len; i++)
	 {
		 if (list.array[i] == x)
		 {
			 count++;
			 if (count > 1)
			 {
				 for (int j = i; j < list.len - 1; j++)
				 {
					 list.array[j] = list.array[j + 1];
				 }
				 list.len--;
				 i--;
			 }

		 }
	 }
	 if (count > 1)
	 {
		 cout << "\n\nDanh sach sau khi xoa tat ca phan tu co gia tri " << x << " : ";
		 printList(list);
	 }
	 else
	 {
		 cout << "\n\nKhong tim thay bat ki phan tu nao co gia tri " << x << " thu 2";
	 }
 }
//15	Viết hàm thay thế các phần tử có giá trị x sang giá trị y.
 void cau15(List& list)
 {
	 int x, y;
	 cout << "\n\nNhap x:";
	 cin >> x;
	 cout << "\n\nNhap y:";
	 cin >> y;
	 bool flag = false;
	 for (int i = 0; i < list.len; i++)
	 {
		 if (list.array[i] == x)
		 {
			 flag = true;
			 list.array[i] = y;
		 }
	 }
	 if (flag)
	 {

		 cout << "\n\nDanh sach sau khi thay cac phan tu gia tri " << x << " thanh " << y << ": ";
		 printList(list);
	 }
	 else
	 {
		 cout<<"\n\nKhong tim thay bat cu phan tu nao mang gia tri "<<x;
	 }
}
//16	Cho 02 DS đặc D1 và D2, viết hàm chèn xen kẻ các phần tử D2 vào D1
 void cau16()
 {
	 List d1, d2;
	 cout << "\n\nNhap D1:\n";
	 enterList(d1);
	 cout << "\n\nNhap D2:\n";
	 enterList(d2);

	 if (d1.len + d2.len > MAX)
	 {
		 cout << "\n\nKhong the chen vi Vuot qua gioi han MAX: " << MAX;
		 return;
	 }
	 List d3;

	 int i = 0, j = 0, k = 0;
	 while (i < d1.len && j < d2.len)
	 {
		 d3.array[k++] = d1.array[i++];
		 d3.array[k++] = d2.array[j++];
	 }
	 while (i < d1.len)
	 {
		 d3.array[k++] = d1.array[i++];
	 }
	 while (j < d2.len)
	 {
		 d3.array[k++] = d2.array[j++];
	 }
	 d3.len = d1.len + d2.len;

	 cout << "\n\nDanh sach sau khi chen xen ke D2 vao D1:";
	 printList(d3);

}
//17	Giả sử, cho 02 DS đặc d1 và d2 có thứ tự tăng, viết hàm chèn các phần tử d2 vào d1 sao cho d1 vẫn có thứ tự
 void cau17()
 {
	 List d1, d2;
	 cout << "\n\nNhap D1:\n";
	 enterList(d1);
	 cout << "\n\nNhap D2:\n";
	 enterList(d2);
	 if (d1.len + d2.len > MAX)
	 {
		 cout << "\n\nKhong the chen vi Vuot qua gioi han MAX: " << MAX;
		 return;
	 }
	 selectionSort(d1, true);
	 selectionSort(d2, true);

	 cout << "\n\nD1:";
	 printList(d1);
	 cout << "\n\nD2:";
	 printList(d2);

	 List d3;

	 int i = 0, j = 0, k = 0;
	 while (i < d1.len && j < d2.len)
	 {
		 if (d1.array[i] < d2.array[j])
		 {
			 d3.array[k++] = d1.array[i++];
		 }
		 else
		 {
			 d3.array[k++] = d2.array[j++];
		 }
	 }
	 while (i < d1.len)
	 {
		 d3.array[k++] = d1.array[i++];
	 }
	 while (j < d2.len)
	 {
		 d3.array[k++] = d2.array[j++];
	 }
	 d3.len = d1.len + d2.len;

	 cout << "\n\nDanh sach sau khi chen xen ke D2 vao D1:";
	 printList(d3);

}
//18	Cho 02 DS đặc d1 và d2 viết hàm chép các phần tử d2 nối tiếp vào d1.
 void cau18()
 {
	 List d1, d2;
	 cout << "\n\nNhap D1:\n";
	 enterList(d1);
	 cout << "\n\nNhap D2:\n";
	 enterList(d2);
	 if (d1.len + d2.len > MAX)
	 {
		 cout << "\n\nKhong the chen vi Vuot qua gioi han MAX: " << MAX;
		 return;
	 }
	 //1  2  3  
	 //0  1  2  3
	 //55 66
	 //0  1
	 //i = 3
	 //1 2 3 55 66
	 for (int i = d1.len; i < d1.len + d2.len; i++)
	 {
		 d1.array[i] = d2.array[i - d1.len];
	 }

	 d1.len += d2.len;

	 cout << "\n\nD1 sau khi noi D2:";
	 printList(d1);
}
//19	Viết hàm copy DS đặc d1 thành 02 DS đặc mới a và b, trong đó, a là ds chứa các phần tử có giá trị dương và b là ds chứa các phần tử có giá trị âm.
 void cau19(List list)
 {
	 List a, b;
	 int j = 0, k = 0;
	 for (int i = 0; i < list.len; i++)
	 {
		 if (list.array[i] < 0)
		 {
			 b.array[j++] = list.array[i];
		 }
		 else
		 {
			 a.array[k++] = list.array[i];
		 }
	 }
	 a.len = k;
	 b.len = j;
	 cout << "\n\na toan duong:";
	 printList(a);
	 cout << "\n\nb toan am:";
	 printList(b);

}
//20	Viết hàm kiểm tra DS có đối xứng không ? Nếu có trả về 1, ngược lại trả về 0.
 bool kiemTraDoiXung(List list)
 {
	 //1 2 3 2 1 
	 //0 1 2 3 4
	 for (int i = 0; i < list.len/2; i++)
	 {
		 if (list.array[i] != list.array[list.len - i - 1])
		 {
			 return false;
		 }
	 }
	 return true;
}

 void cau20(List list)
 {
	 bool isDoiXung = kiemTraDoiXung(list);
	 if (isDoiXung)
	 {
		 cout << "\n\nMang doi xung!";
	 }
	 else
	 {
		 cout << "\n\nMang khong doi xung!";
	 }
 }
//21	Chèn phần tử x vào vị trí giữa DS đặc
 void cau21(List& list)
 {
	 if (list.len == MAX)
	 {
		 cout << "\n\nMang day khong the chen!";
		 return;
	 }

	 cout << "\n\nNhap x can chen vao giua:";
	 int x;
	 cin >> x;
	 
	 for (int i = list.len; i >= list.len / 2; i--)
	 {
		 list.array[i] = list.array[i - 1];
	 }
	 list.array[list.len / 2] = x;
	 list.len++;

	 cout << "\n\nDanh sach sau khi chen " << x << " vao giua: ";
	 printList(list);
}
//22	Viết hàm chèn giá trị a vào sau tất cả các phần tử có giá trị x tìm thấy trong DS đặc
 void cau22(List list)
 {
	 int x;
	 cout << "\n\nNhap x can tim:";
	 cin >> x;
	 int a;
	 cout << "\n\nNhap a chen chen sau " << x << ":";
	 cin >> a;
	 bool flag = false;
	 for (int i = 0; i < list.len; i++)
	 {
		 if (list.array[i] == x)
		 {
			 flag = true;
			 if (list.len == MAX)
			 {
				 cout << "\n\nMang day!";
				 return;
			 }
			 for (int j = list.len; j > i; j--)
			 {
				 list.array[j] = list.array[j - 1];
			 }
			 list.array[i + 1] = a;
			 list.len++;
		 }
	 }
	 if (flag)
	 {
		 cout << "\n\nDanh sach sau khi chen " << a << " vao sau tat ca" << x << " tim thay: ";
		 printList(list);
	 }
	 else
	 {
		 cout << "\n\nKhong tim thay phan tu co gia tri " << x;
	 }
}
//23	Giả sử DS đặc nguyên dương có nhiều chuỗi con có thứ tự tăng, 
// viết hàm chèn giá trị 0 vào sau phần tử cuối cùng của mỗi chuỗi con.
// vd 1 2 3 5 3 1 8 4 5 6 9 10
// 	  0 1 2 3 4 5
// trong mảng trên có các chuỗi con sau
// - 1 2 3 5
// - 3
// - 1 8
// - 4 5 6 8 10
// Tiến hành chèn 0 vào cuối mỗi Chuỗi Con
// 1 2 3 5 0 3 0 1 8 0 4 5 6 9 10 0
 void cau23(List list)
 {
	 // 1 2 -5 -2 10 5
	 // 0 1  2  3  4 5
	 //newlist
	 // 1 2 0 -2
	 // 0 1 2  3 4
	 List newList;
	 int j = 0;
	 for (int i = 0; i < list.len; i++)
	 {
		 
		 if (list.array[i] < list.array[i + 1])
		 {
			 newList.array[j++] = list.array[i];
		}
		 else
		 {
			 newList.array[j++] = list.array[i];
			 newList.array[j++] = 0;
		 }
	 }
	 newList.len = j;
	 cout << "\n\nNew list: ";
	 printList(newList);
}
//24	Viết hàm kiểm tra DS đặc có số 0 và số 1 được sắp xếp xem kẻ nhau không ? Nếu có thì trả về 1, nếu sai thì trả về 0
// vd 0 1 0 1 0 => thỏa
//25	Viết hàm thay thế tất cả các số nguyên tố được tìm thấy trong DS đặc nguyên dương thành số 0.
//26	Viết hàm đảo ngược DS đặc.



void main()
{
	List newList;
	enterList(newList);


	int choice = 0;

	do
	{
		system("cls");
		cout << "\n = = = = Menu = = = =\n";
		cout << "\n  -5. Sua phan tu co gia tri X duoc tim thay";
		cout << "\n  -4. Xoa phan tu co gia tri X nhap vao";
		cout << "\n  -3. Tim vi tri cua cac phan tu co gia tri X nhap vao";
		cout << "\n  -2. Chen phan tu moi";
		cout << "\n  -1. Nhap Danh Sach Moi";
		cout << "\n   0. Xuat Danh Sach Hien Tai";
		cout << "\n   1. Xuat so luong phan tu co gia tri X";
		cout << "\n   2. Tra ve dia chi phan tu co gia tri X thu 2";
		cout << "\n   3. Xuat cac phan tu co gia tri bang tong 2 phan tu lien ke truoc do";
		cout << "\n   4. Kiem tra mang co tang hay khong";
		cout << "\n   5. Tra ve vi tri so nguyen to dau tien trong DS";
		cout << "\n   6. Tra ve so luong So Hoan Hao";
		cout << "\n   7. Tra ve so Am Lon Nhat";
		cout << "\n   8. Sap xep tuan tu giam dan";
		cout << "\n   9. Chen a vao sau x";
		cout << "\n  10. Chen a vao truoc vi tri pos";
		cout << "\n  11. Xoa phan tu gia tri x cuoi cung";
		cout << "\n  12. Xoa tat ca phan tu gia tri x";
		cout << "\n  13. Xoa phan tu gia tri x thu 2 ";
		cout << "\n  14. Xoa tat ca phan tu gia tri x tu phan tu thu 2 ";
		cout << "\n  15. Thay the tat ca phan tu gia tri x thanh y";
		cout << "\n  16. Chen xen ke d2 vao d1";
		cout << "\n  17. Chen xe ke d2 vao d1 co thu tu";
		cout << "\n  18. Noi D2 vao D1";
		cout << "\n  19. Copy ra 2 danh sach am va duong";
		cout << "\n  20. Kiem tra doi xung";
		cout << "\n  21. Chen x vao giua danh sach";
		cout << "\n  22. Chen a vao sau tat ca x";
		cout << "\n  23. Chen 0 vao sau phan tu cuoi cung cua mang con tang";
		cout << "\n-999. Thoat chuong trinh";
		cout << "\nDanh Sach Dac: ";
		printList(newList);
		cout << "\n\nNhap lua chon: ";
		cin >> choice;

		switch (choice)
		{
		case 23:
			cau23(newList);
			break;
		case 22:
			cau22(newList);
			break;
		case 21:
			cau21(newList);
			break;
		case 20:
			cau20(newList);
			break;
		case 19:
			cau19(newList);
			break;
		case 18:
			cau18();
			break;
		case 17:
			cau17();
			break;
		case 16:
			cau16();
			break;
		case 15:
			cau15(newList);
			break;
		case 14:
			cau14(newList);
			break;
		case 13:
			cau13(newList);
			break;
		case 12:
			cau12(newList);
			break;
		case 11:
			cau11(newList);
			break;
		case 10:
			cau10(newList);
			break;
		case 9:
			cau9(newList);
			break;
		case 8:
			cau8(newList);
			break;
		case 7:
			cau7(newList);
			break;
		case 6:
			cau6(newList);
			break;
		case 5:
			cau5(newList);
			break;
		case 4:
			cau4(newList);
			break;
		case 3:
			cau3(newList);
			break;
		case 2:
			cau2(newList);
			break;
		case 1:
			cau1(newList);
			break;
		case -5:
			suaPhanTuGiaTriX(newList);
			break;
		case -4:
			xoaPhanTuGiaTriX(newList);
			break;
		case -3:
			List rs = timKiemPhanTuGiaTriX_TraVeDSIndex(newList);
			cout << "\n\nDS vi tri cac phan tu duoc tim thay: ";
			printList(rs);
			break;
		case -2:
			chenGiaTriVaoCuoiDS(newList);
			break;
		case -1:
			enterList(newList);
			break;
		case 0:
			cout << "\n\nDanh Sach Hien Tai: ";
			printList(newList);
			break;
		case -999:
			cout << "\n\nCHUONG TRINH DUNG LAI!";
			break;
		default:
			cout << "\n\nLUA CHON KHONG HOP LE!";
			break;
		}
		cout << "\n\n";
		system("pause");
	} while (choice != -999);
}