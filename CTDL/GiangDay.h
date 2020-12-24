#pragma once
#include "KhaiBao.h"
#include"Khoa.h"
#include "MonHoc.h"
using namespace std;

NODE_GD* GetNodeGD(GiangDay gd)
{
	NODE_GD* p = new NODE_GD;

	if (p == NULL)
	{
		return NULL;
	}
	p->data = gd;
	p->pNext = NULL; // khoi tao moi lien ket
	return p;
}
bool KTraTrungMaGD(LIST_GD &GD, string maGD) {
	for (NODE_GD *k = GD.pHead; k != NULL; k = k->pNext) {
		if (k->data.maCT == maGD) {
			return true;
		}
	}
	return false;
}

void dsgd_themcuoi(LIST_GD& l, GiangDay gd) {
	NODE_GD* p = GetNodeGD(gd);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	soluongGD++;
}
void NhapGD(LIST_GD &GD,TREEKhoa &tKhoa,TREEMonHoc &tMH, LIST_CT &CT)
{
	GiangDay gd;
	Khoa k;
	MonHoc mh;
	do
	{
		cout << "Nhap Ma Giang Day: ";
		fflush(stdin);
		cin.get(gd.maGD, 6);
		cin.ignore();
		if (KTraTrungMaGD(GD, gd.maGD))
			cout << "Ma GD bi trung. Moi nhap lai. " << endl;
	} while (KTraTrungMaGD(GD, gd.maGD));
	do
	{
		cout << " Nhap Ma Khoa: ";
		cin.get(gd.maKhoa, 6);
		cin.ignore();
		if (!kTTonTaiKhoa(tKhoa, gd.maKhoa,k))
			cout << "Ma Khoa chua co. Moi nhap lai. " << endl;
	} while (!kTTonTaiKhoa(tKhoa, gd.maKhoa,k));
	do
	{
		cout << " Nhap Ma CT: ";
		cin.get(gd.maCT, 6);
		cin.ignore();
		if (!KTraTrungMaCT(CT, gd.maCT))
			cout << "Ma CT chua co. Moi nhap lai. " << endl;
	} while (!KTraTrungMaCT(CT, gd.maCT ));
	do
	{
		cout << " Nhap Ma MH: ";
		cin.get(gd.maMon, 6);
		cin.ignore();
		if (!kTTonTaiMonhoc(tMH, gd.maMon,mh))
			cout << "Ma MH chua co. Moi nhap lai. " << endl;
	} while (!kTTonTaiMonhoc(tMH, gd.maMon,mh));
	cout << "Nhap Hoc Ky: ";
	cin>>gd.hocKi;
	cout << "Nhap Nam Hoc: ";
	cin>>gd.namHoc;
	cout << "Nhap So Tin Chi: ";
	cin>>gd.sotinChi;
	cout << "Nhap So Tiet LT: ";
	cin>>gd.tietLT;
	cout << "Nhap So Tiet TH: ";
	cin>>gd.tietTH;
	dsgd_themcuoi(GD, gd);
}
bool dsgd_kiemtrarong(LIST_GD& GD) {//kiem tra ds rong
	return GD.pHead == NULL;
}


void XuatDanhSachGD(LIST_GD GD)
{
	cout << endl;
	cout << "DANH SACH GIANG DAY" << endl;
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		cout << "Ma GD         : " << i->data.maGD << endl;
		cout << "MA KHOA       : " << i->data.maKhoa << endl;
		cout << "Ma Chuong Trinh        : " << i->data.maCT << endl;
		cout << "MA MON      : " << i->data.maMon << endl;
		cout << "HOC KY       : " << i->data.hocKi << endl;
		cout << "NAM HOC      : " << i->data.namHoc << endl;
		cout << "So Tin Chi   : "<<i->data.sotinChi<<endl;
		cout << "So Tiet LT   : "<<i->data.tietLT<<endl;		
		cout << "So Tiet TH   : "<<i->data.tietTH<<endl;
	}
}