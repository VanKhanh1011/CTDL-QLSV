#pragma once
#include "KhaiBao.h"
using namespace std;

NODE_CT* GetNodeCT(ChuongTrinhHoc ct)
{
	NODE_CT* p = new NODE_CT;

	if (p == NULL)
	{
		return NULL;
	}
	p->data = ct;
	p->pNext = NULL; // khoi tao moi lien ket
	return p;
}
bool KTraTrungMaCT(LIST_CT &CT, char maCT[]) {
	for (NODE_CT *k = CT.pHead; k != NULL; k = k->pNext) {
		if (strcmp(k->data.maCT, maCT)==0) {
			return true;
		}
	}
	return false;
}

void dsct_themcuoi(LIST_CT& l, ChuongTrinhHoc ct) {
	NODE_CT* p = GetNodeCT(ct);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	soluongCT++;
}
void NhapCT(LIST_CT &CT)
{
	ChuongTrinhHoc ct;
	do
	{
		cout << "Nhap Ma Chuong Trinh: ";
		fflush(stdin);
		cin.get(ct.maCT, 6);
		cin.ignore();
		if (KTraTrungMaCT(CT, ct.maCT))
			cout << "Ma CT bi trung. Moi nhap lai. " << endl;
	} while (KTraTrungMaCT(CT, ct.maCT));
	cout << "Nhap Ten CT: ";
	cin.get(ct.tenCT, 20);

	dsct_themcuoi(CT, ct);
}
bool dsct_kiemtrarong(LIST_CT& CT) {//kiem tra ds rong
	return CT.pHead == NULL;
}

void XuatDanhSachCT(LIST_CT CT)
{
	cout << endl;
	cout << "DANH SACH CHUONG TRINH HOC" << endl;
	for (NODE_CT *i = CT.pHead; i != NULL; i = i->pNext)
	{
		cout << "Ma Chuong Trinh         : " << i->data.maCT << endl;
		cout << "TEn Chuong Trinh       : " << i->data.tenCT << endl;



	}
}