#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<time.h>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
//khai báo các số lượng để khi thêm thì tăng lên
int soLgKhoa = 0;
int soLgKhoaHoc = 0;
int soLgMon = 0;
int soluongSV = 0;
int soluongCT=0;
int soluongGD=0;
int soluongLH=0;
int soluongKQ=0;

struct Khoa {
	char maKhoa[6];
	char tenKhoa[20];
	int namThanhLap;
};
struct KhoaHoc {
	char maKhoaHoc[6];
	int namBD;
	int namKT;
};
struct MonHoc {
	char maMH[6];
	char tenMH[20];
	char maKhoa[6];
};
//khai bao kieu dl sinh vien
struct SinhVien {
	char maSinhVien [6];
	char hoTen[20];
	int namSinh;
	char gioiTinh[5];
	char maLop[6];
};
struct ChuongTrinhHoc {
	char maCT[6];
	char tenCT[20];
};

struct KetQua {
	char maKQ[6];
	char maMon[6];
	int diem;
	char maSinhVien[6];
	int lanThi;
};
struct GiangDay {
	char maGD[6];
	char maKhoa[6];
	char maCT[6];
	char maMon[6];
	int hocKi;
	int namHoc;
	int sotinChi;
	int tietLT;
	int tietTH;
};
struct LopHoc {
	char maLop[6];
	char maKhoa[6];
	char maKhoaHoc[6];
	int stt;
	char maChuongTrinh[6];
};
//khai bao node sv gom data va pnext con tro lien ket
struct NODE_SV {
	SinhVien data;
	NODE_SV *pNext;

};
//khai bao danh sach sv gom 2 con tro qly o dau va cuoi
struct LIST_SV {	
	NODE_SV *pHead;
	NODE_SV *pTail;
};
struct NODE_CT {
	ChuongTrinhHoc data;
	NODE_CT *pNext;
};
struct LIST_CT {	
	NODE_CT *pHead;
	NODE_CT *pTail;
};
//////////////////////////
struct NODE_KQ {
	KetQua data;
	NODE_KQ *pNext;
};
struct LIST_KQ {
	NODE_KQ *pHead;
	NODE_KQ *pTail;
};
////////////////////////
struct NODE_LH {
	LopHoc data;
	NODE_LH *pNext;
};
struct LIST_LH {
	NODE_LH *pHead;
	NODE_LH *pTail;
};
//////////////////////
struct NODE_GD {
	GiangDay data;
	NODE_GD *pNext;
};
struct LIST_GD {
	NODE_GD *pHead;
	NODE_GD *pTail;
};
///////////
struct NODE_TREEKhoa
{
	Khoa data;
	NODE_TREEKhoa* pLeft;
	NODE_TREEKhoa* pRight;

};
typedef NODE_TREEKhoa* TREEKhoa;
struct NODE_TREEKhoaHoc
{
	KhoaHoc data;
	NODE_TREEKhoaHoc* pLeft;
	NODE_TREEKhoaHoc* pRight;

};
typedef NODE_TREEKhoaHoc* TREEKhoaHoc;
struct NODE_TREEMonHoc
{
	MonHoc data;
	NODE_TREEMonHoc* pLeft;
	NODE_TREEMonHoc* pRight;

};
typedef NODE_TREEMonHoc* TREEMonHoc;
