#pragma once

#include "KhaiBao.h"
#include "SinhVien.h"
using namespace std;

NODE_KQ* GetNodeKQ(KetQua kq)
{
	NODE_KQ* p = new NODE_KQ;

	if (p == NULL)
	{
		return NULL;
	}
	p->data = kq;
	p->pNext = NULL; // khoi tao moi lien ket
	return p;
}
bool KTraTrungMaKQ(LIST_KQ &KQ, char maKQ[]) {
	for (NODE_KQ *k = KQ.pHead; k != NULL; k = k->pNext) {
		if (strcmp(k->data.maKQ , maKQ)==0) {
			return true;
		}
	}
	return false;
}

void dskq_themcuoi(LIST_KQ& l, KetQua kq) {
	NODE_KQ* p = GetNodeKQ(kq);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	soluongKQ++;
}
void NhapKQ(LIST_KQ &KQ,LIST_SV &SV,TREEMonHoc &tMH)
{
	KetQua kq;
	MonHoc mh;
	do
	{
		cout << "Nhap Ma Ket Qua: ";
		fflush(stdin);
		cin.get(kq.maKQ, 6);
		cin.ignore();
		if (KTraTrungMaKQ(KQ, kq.maKQ))
			cout << "Ma KQ bi trung. Moi nhap lai. " << endl;
	} while (KTraTrungMaKQ(KQ, kq.maKQ));
	do
	{
		cout << "Nhap Ma Sinh Vien: ";
		fflush(stdin);
		cin.get(kq.maSinhVien, 6);
		cin.ignore();
		if (!KTraTrungMaSV(SV, kq.maSinhVien))
			cout << "Ma SV bi trung. Moi nhap lai. " << endl;
	} while (!KTraTrungMaSV(SV, kq.maSinhVien));
	do
	{
		cout << " Nhap Ma MH: ";
		cin.get(kq.maMon, 6);
		cin.ignore();
		if (!kTTonTaiMonhoc(tMH, kq.maMon, mh))
			cout << "Ma MH chua co. Moi nhap lai. " << endl;
	} while (!kTTonTaiMonhoc(tMH, kq.maMon, mh));
	cout << "Nhap DIEM";
	cin>>kq.diem;
	cout << "Nhap LAN THI";
	cin>>kq.lanThi;

	dskq_themcuoi(KQ, kq);
}
bool dskq_kiemtrarong(LIST_KQ& KQ) {//kiem tra ds rong
	return KQ.pHead == NULL;
}

void XuatDanhSachKQ(LIST_KQ KQ)
{
	cout << endl;
	cout << "DANH SACH KET QUA" << endl;
	for (NODE_KQ *i = KQ.pHead; i != NULL; i = i->pNext)
	{
		cout << "Ma LOP         : " << i->data.maKQ << endl;
		cout << "MA SINH VIEN      : " << i->data.maSinhVien << endl;
		cout << "MA MON HOC      : " << i->data.maMon << endl;
		cout << "Diem Thi        : " << i->data.diem << endl;
		cout << "Lan Thi      : " << i->data.lanThi << endl;
	}
}