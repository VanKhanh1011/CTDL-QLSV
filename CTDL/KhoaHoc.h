#pragma once

#include "KhaiBao.h"
using namespace std;

bool kTTonTaiKhoahoc(TREEKhoaHoc t, char maKhoaHoc[], KhoaHoc& K)
{
	if (t == NULL)
	{
		return false;
	}
	else if (strcmp(t->data.maKhoaHoc , maKhoaHoc)==0)
	{
		K = t->data;
		return true;
	}
	else if (strcmp(t->data.maKhoaHoc, maKhoaHoc) > 0)
	{
		return kTTonTaiKhoahoc(t->pLeft, maKhoaHoc, K);
	}
	else
	{
		return kTTonTaiKhoahoc(t->pRight, maKhoaHoc, K);
	}
}
void themKhoaHocVaoCay(TREEKhoaHoc& t, KhoaHoc k)
{
	if (t == NULL)
	{
		soLgKhoaHoc++;
		NODE_TREEKhoaHoc* p = new NODE_TREEKhoaHoc;
		p->data = k;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if (strcmp(k.maKhoaHoc , t->data.maKhoaHoc)<0)
			themKhoaHocVaoCay(t->pLeft, k);
		else if (strcmp(k.maKhoaHoc, t->data.maKhoaHoc) >0)
			themKhoaHocVaoCay(t->pRight, k);
	}
}
void themKhoaHoc(TREEKhoaHoc &tKH) {	
	KhoaHoc k;
	do
	{
		cout << "Nhap ma KH: ";
		cin.get(k.maKhoaHoc, 6);
		cin.ignore();
		if (kTTonTaiKhoahoc(tKH, k.maKhoaHoc, k))
			cout << "Ma KH bi trung. Moi nhap lai. " << endl;
	} while (kTTonTaiKhoahoc(tKH, k.maKhoaHoc, k));	
	cout << "Nhap nam bat dau: ";
	cin >> k.namBD;
	cout << "Nhap nam ket thuc: ";
	cin >> k.namKT;
	themKhoaHocVaoCay(tKH, k);
}
void xuatDanhSachKhoaHoc(TREEKhoaHoc &t) {
	if (t == NULL) {
		return;
	}
	xuatDanhSachKhoaHoc(t->pLeft);
	cout << t->data.maKhoaHoc << "     |     " << t->data.namBD << "     |     " << t->data.namKT << endl;
	xuatDanhSachKhoaHoc(t->pRight);
}

