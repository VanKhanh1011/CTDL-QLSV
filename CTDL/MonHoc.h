#pragma once

#include "KhaiBao.h"
using namespace std;

bool kTTonTaiMonhoc(TREEMonHoc t, char maMH[], MonHoc& K)
{
	if (t == NULL)
	{
		return false;
	}
	else if (strcmp(t->data.maMH , maMH)==0)
	{
		K = t->data;
		return true;
	}
	else if (strcmp(t->data.maMH, maMH) > 0)
	{
		return kTTonTaiMonhoc(t->pLeft, maMH, K);
	}
	else
	{
		return kTTonTaiMonhoc(t->pRight, maMH, K);
	}
}
void themMonHocVaoCay(TREEMonHoc& t, MonHoc k)
{
	if (t == NULL)
	{
		soLgMon++;
		NODE_TREEMonHoc* p = new NODE_TREEMonHoc;
		p->data = k;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if (strcmp(k.maMH, t->data.maMH) < 0)
			themMonHocVaoCay(t->pLeft, k);
		else if (strcmp(k.maKhoa, t->data.maKhoa) > 0)
			themMonHocVaoCay(t->pRight, k);
	}
}
void themMH(TREEMonHoc &tMH,TREEKhoa &tK) {
	MonHoc mh;
	Khoa k;
	do
	{
		cout << "Nhap ma MH: ";
		cin.get(mh.maMH, 6);
		cin.ignore();
		if (kTTonTaiMonhoc(tMH, mh.maMH, mh))
			cout << "Ma MH bi trung. Moi nhap lai. " << endl;
	} while (kTTonTaiMonhoc(tMH, mh.maMH, mh));
	do
	{
		cout << "Nhap ma Khoa: ";
		cin.get(mh.maKhoa, 6);
		cin.ignore();
		if (!kTTonTaiKhoa(tK, mh.maKhoa, k))
			cout << "Ma Khoa chua co. Moi nhap lai. " << endl;
	} while (!kTTonTaiKhoa(tK, mh.maKhoa, k));
	cout << "Nhap ten mon hoc: ";
	cin.get(mh.tenMH, 20);
	themMonHocVaoCay(tMH, mh);
}
void xuatDanhSachMonHoc(TREEMonHoc &t) {
	if (t == NULL) {
		return;
	}
	xuatDanhSachMonHoc(t->pLeft);
	cout << t->data.maMH << "     |     " << t->data.tenMH << "     |     " << t->data.maKhoa << endl;
	xuatDanhSachMonHoc(t->pRight);
}
//void timKiemCayMonHoc(TREEMonHoc &pHuy, TREEMonHoc &pTM)
//{
//	if (pTM->pLeft)
//		timKiemCayMonHoc(pHuy, pTM->pLeft);
//	else
//	{
//		pHuy->data.maMH = pTM->data.maMH;
//		pHuy = pTM;
//		pTM = pTM->pRight;
//	}
//}
//void xoaCayMonHoc(TREEMonHoc & t, MonHoc k)
//{
//	if (t != NULL)
//	{
//		if (k.maMH < t->data.maMH)
//			xoaCayMonHoc(t->pLeft, k);
//		else if (k.maMH > t->data.maMH)
//			xoaCayMonHoc(t->pRight, k);
//		else
//		{
//			NODE_TREEMonHoc * pHuy = t;
//			if (t->pLeft == NULL)
//				t = t->pRight;
//			else if (t->pRight == NULL)
//				t = t->pLeft;
//			else timKiemCayMonHoc(pHuy, t->pRight);
//			delete pHuy;
//		}
//	}
//}

