#pragma once

#include "KhaiBao.h"
#include "KhoaHoc.h"
using namespace std;

NODE_LH* GetNodeLH(LopHoc lh)
{
	NODE_LH* p = new NODE_LH;

	if (p == NULL)
	{
		return NULL;
	}
	p->data = lh;
	p->pNext = NULL; // khoi tao moi lien ket
	return p;
}
bool KTraTrungMaLH(LIST_LH &LH, string maLH) {
	for (NODE_LH *k = LH.pHead; k != NULL; k = k->pNext) {
		if (k->data.maLop == maLH) {
			return true;
		}
	}
	return false;
}

void dslh_themcuoi(LIST_LH& l, LopHoc lh) {
	NODE_LH* p = GetNodeLH(lh);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	soluongLH++;
}
void NhapLH(LIST_LH &LH,TREEKhoa &tKhoa,TREEKhoaHoc &tKH,LIST_CT &CT)
{
	LopHoc lh;
	Khoa k;
	KhoaHoc kh;
	do
	{
		cout << "Nhap Ma Lop: ";
		fflush(stdin);
		cin.get(lh.maLop, 6);
		cin.ignore();
		if (KTraTrungMaLH(LH, lh.maLop))
			cout << "Ma LH bi trung. Moi nhap lai. "<<endl;
	} while (KTraTrungMaLH(LH, lh.maLop));
	do
	{
		cout << " Nhap Ma Khoa: ";
		cin.get(lh.maKhoa, 6);
		cin.ignore();
		if (!kTTonTaiKhoa(tKhoa, lh.maKhoa, k))
			cout << "Ma KHOA chua co. Moi nhap lai. "<<endl;
	} while (!kTTonTaiKhoa(tKhoa, lh.maKhoa, k));
	do
	{
		cout << " Nhap Ma Khoa Hoc: ";
		cin.get(lh.maKhoaHoc, 6);
		cin.ignore();
		if (!kTTonTaiKhoahoc(tKH, lh.maKhoaHoc, kh))
			cout << "Ma KH chua co. Moi nhap lai. " << endl;
	} while (!kTTonTaiKhoahoc(tKH, lh.maKhoaHoc, kh));
	do
	{
		cout << " Nhap Ma CT: ";
		cin.get(lh.maChuongTrinh, 6);
		cin.ignore();
		if (!KTraTrungMaCT(CT, lh.maChuongTrinh))
			cout << "Ma CT chua co. Moi nhap lai. " << endl;
	} while (!KTraTrungMaCT(CT, lh.maChuongTrinh));
	cout << "Nhap STT: ";
	cin>>lh.stt;
	dslh_themcuoi(LH, lh);
}
bool dslh_kiemtrarong(LIST_LH& LH) {//kiem tra ds rong
	return LH.pHead == NULL;
}

void XuatDanhSachLH(LIST_LH LH)
{
	cout << endl;
	cout << "DANH SACH LOP HOC" << endl;
	for (NODE_LH *i = LH.pHead; i != NULL; i = i->pNext)
	{
		cout << "Ma LOP         : " << i->data.maLop << endl;
		cout << "MA KHOA      : " << i->data.maKhoa << endl;
		cout << "Ma KHOA HOC        : " << i->data.maKhoaHoc << endl;
		cout << "MA CHUONG TRINH      : " << i->data.maChuongTrinh << endl;
		cout << "STT        : " << i->data.stt << endl;

	}
}