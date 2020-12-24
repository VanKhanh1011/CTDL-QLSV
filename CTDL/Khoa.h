#pragma once

#include "KhaiBao.h"
using namespace std;

bool kTTonTaiKhoa(TREEKhoa &t, char maKhoa[],Khoa &K)
{	
	
	if (t == NULL)
	{
		return false;
	}
	else if (strcmp(t->data.maKhoa,maKhoa) ==0)
	{
		 K=t->data;
		return true;
	}
	else if (strcmp(t->data.maKhoa , maKhoa)>0)
	{
		return kTTonTaiKhoa(t->pLeft, maKhoa,K);
	}
	else
	{
		return kTTonTaiKhoa(t->pRight, maKhoa,K);
	}
}
void themKhoaVaoCay(TREEKhoa& t, Khoa k)
{
	if (t == NULL)
	{
		soLgKhoa++;
		NODE_TREEKhoa* p = new NODE_TREEKhoa;
		p->data = k;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if (strcmp(k.maKhoa , t->data.maKhoa)<0)
			themKhoaVaoCay(t->pLeft, k);
		else if (strcmp(k.maKhoa, t->data.maKhoa) > 0)
			themKhoaVaoCay(t->pRight, k);
	}
}
void timKiemCayKhoa(TREEKhoa &pHuy, TREEKhoa &pTM)
{
	if (pTM->pLeft)
		timKiemCayKhoa(pHuy, pTM->pLeft);
	else
	{
		strcmp(pHuy->data.maKhoa , pTM->data.maKhoa)==0;
		pHuy = pTM;
		pTM = pTM->pRight;
	}
}

void xoaCayKhoa(TREEKhoa & t, char k[])
{
	if (t != NULL)
	{
		if (strcmp(k , t->data.maKhoa)<0)
			xoaCayKhoa(t->pLeft, k);
		else if (strcmp(k , t->data.maKhoa)>0)
			xoaCayKhoa(t->pRight, k);
		else
		{
			NODE_TREEKhoa * pHuy = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			else if (t->pRight == NULL)
				t = t->pLeft;
			else timKiemCayKhoa(pHuy, t->pRight);
			delete pHuy;
		}
	}
}
void themKhoa(TREEKhoa &t) {
	Khoa k;	
	do
	{
		cout << "Nhap ma Khoa: ";
		cin.get(k.maKhoa,6);
		cin.ignore();
		if (kTTonTaiKhoa(t, k.maKhoa,k))
			cout << "Ma Khoa bi trung. Moi nhap lai. " << endl;
	} while (kTTonTaiKhoa(t, k.maKhoa,k));
	cout << "Nhap ten Khoa: ";
	cin.get(k.tenKhoa, 20);
	cin.ignore();
	cout << "Nhap nam thanh lap: ";
	cin >> k.namThanhLap;
	themKhoaVaoCay(t, k);
}
void xuatDanhSachKhoa(TREEKhoa &t) {
	if (t == NULL) {
		return;
	}
	xuatDanhSachKhoa(t->pLeft);
	cout << t->data.maKhoa << "     |     " << t->data.tenKhoa << "     |     " << t->data.namThanhLap << endl;
	xuatDanhSachKhoa(t->pRight);
}
//
void timKiemMaKhoa(TREEKhoa &t, char maKhoa[])
{

	if (t == NULL)
	{
		cout<<"Khong tim thay Khoa";
	}
	else if (strcmp(t->data.maKhoa, maKhoa) == 0)
	{
		cout << "Thong tin Khoa";
		cout<<"Ma khoa: " <<t->data.maKhoa<<endl;
		cout << "Ten khoa: " << t->data.tenKhoa << endl;
		cout << "Nam thanh lap khoa: " << t->data.namThanhLap << endl;
		
	}
	else if (strcmp(t->data.maKhoa, maKhoa) > 0)
	{
		return timKiemMaKhoa(t->pLeft, maKhoa);
	}
	else
	{
		return timKiemMaKhoa(t->pRight, maKhoa);
	}
}
void timKiemTenKhoa(TREEKhoa &t, char tenKhoa[])
{

	if (t == NULL)
	{
		cout << "Khong tim thay Khoa";
	}
	else if ( strcmp(t->data.tenKhoa, tenKhoa) == 0)
	{
		cout << "Thong tin Khoa";
		cout << "Ma khoa: " << t->data.maKhoa << endl;
		cout << "Ten khoa: " << t->data.tenKhoa << endl;
		cout << "Nam thanh lap khoa: " << t->data.namThanhLap << endl;

	}
	else if (strcmp(t->data.maKhoa, tenKhoa) > 0)
	{
		return timKiemTenKhoa(t->pLeft, tenKhoa);
	}
	else
	{
		return timKiemTenKhoa(t->pRight, tenKhoa);
	}
}
