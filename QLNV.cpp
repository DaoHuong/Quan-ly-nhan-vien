#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <windows.h>

using namespace std;
class CanBo
{
public:
    char hoten[30],donvi[30];
    int ns;
    CanBo(){}
    CanBo( char ht[30],char dv[30],int namsinh)
    {
        strcpy(hoten,ht);
        strcpy(donvi,dv);
        ns = namsinh;
    }
    void Nhap()
    {
        cout<<"Nhap ho ten can bo: ";cin.ignore(1);cin.get(hoten,30);
        cout<<"Nhap don vi: ";cin.ignore(1);cin.get(donvi,30);
        cout<<"Nhap nam sinh: ";cin>>ns;
    }
    void hienthi()
    {
        cout<<setw(20)<<hoten<<setw(20)<<donvi<<setw(5)<<ns;
    }
};
class Bosung: public CanBo
{
public:
    int SNLV,SNN;
    float TH,LT;
    void nhapBS()
    {
       cout<<"So ngay lam viec trong thang: ";cin>>SNLV;
       cout<<"So ngay nghi trong thang: ";cin>>SNN;
       cout<<"Tien thuong: ";cin>>TH;

    }
    float tienluong()
    {
        LT = SNLV*200000+TH-SNN*100000;
        return LT;
    }
    void hienthiLT()
    {
        cout.precision(1);
        cout<<setiosflags(ios::fixed);
        cout<<"Luong thang can bo: ";
        cout<<setw(20)<<tienluong()<<endl;
    }
};

int main()
{
    Bosung A[100],tg;
    cout<<"Khoi tao:"<<endl;
    CanBo a("Dao Thi Huong","DHKTQD",1994);
    a.hienthi();
    cout<<endl<<"Nhap can bo:"<<endl;
    int n;
    do
    {
        cout<<"Nhap so luong can bo: ";cin>>n;
    }
    while(n<=0||n>100);
    for (int i=0;i<n;i++)
    {
        cout<<"Thong tin can bo thu "<<i+1<<" la:"<<endl;
        A[i].Nhap();
        A[i].nhapBS();
        A[i].hienthiLT();
        cout<<setw(59)<<setfill('=')<<"="<<endl;
        cout<<setfill(' ');
    }
    //Sap xep theo thu tu giam dam so ngay lam viec cua can bo
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
    {
        if (A[i].SNLV<A[j].SNLV)
        {
            tg = A[i];
            A[i]=A[j];
            A[j]=tg;
        }
    }
    //dua thong tin ra man hinh
    system("cls");
    cout<<"Thong tin cac can bo la:"<<endl;
    cout<<setw(59)<<setfill('=')<<"="<<endl;
    cout<<setfill(' ');
    cout<<"|"<<setw(20)<<"Ho ten"<<"|"<<setw(10)<<"Nam sinh"<<"|"<<setw(20)<<"Luong thang"<<"|"<<setw(4)<<"SNLV"<<"|"<<endl;
    cout<<setw(59)<<setfill('=')<<"="<<endl;
    cout<<setfill(' ');
    for(int i=0;i<n;i++)
    {
        cout.precision(1);
        cout<<"|"<<setw(20)<<A[i].hoten<<"|"<<setw(10)<<A[i].ns<<"|"<<setw(20)<<setiosflags(ios::fixed)<<A[i].tienluong()<<"|"<<setw(4)<<A[i].SNLV<<"|"<<endl;
        cout<<setw(59)<<setfill('=')<<"="<<endl;
        cout<<setfill(' ');
    }
    //luu thong tin vao file
    ofstream f("DaoThiHuong.txt");
    f<<"Thong tin cac can bo la:"<<endl;
    f<<setw(59)<<setfill('=')<<"="<<endl;
    f<<setfill(' ');
    f<<"|"<<setw(20)<<"Ho ten"<<"|"<<setw(10)<<"Nam sinh"<<"|"<<setw(20)<<"Luong thang"<<"|"<<setw(4)<<"SNLV"<<"|"<<endl;
    f<<setw(59)<<setfill('=')<<"="<<endl;
    f<<setfill(' ');
    for(int i=0;i<n;i++)
    {
        f.precision(1);
        f<<"|"<<setw(20)<<A[i].hoten<<"|"<<setw(10)<<A[i].ns<<"|"<<setw(20)<<setiosflags(ios::fixed)<<A[i].tienluong()<<"|"<<setw(4)<<A[i].SNLV<<"|"<<endl;
        f<<setw(59)<<setfill('=')<<"="<<endl;
        f<<setfill(' ');
    }
    f.close();
    cout<<"Thanh cong";
    getch();


}
