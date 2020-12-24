#pragma once
#include "KhaiBao.h"
using namespace std;
void duyetCayKhoa(TREEKhoa &t ,fstream &fileout) {
	if (t == NULL) {
		return;
	}
	int m = sizeof(Khoa);
	duyetCayKhoa(t->pLeft,fileout);
	fileout.write(reinterpret_cast<char*>(&t->data), (m));
	duyetCayKhoa(t->pRight,fileout);
}
void luuCayKhoa(TREEKhoa &t) {
	if (soLgKhoa > 0) 
	{
		fstream fileout("DSKhoa.dat", ios::out | ios::binary);
		fileout.write(reinterpret_cast<char*>(&soLgKhoa), sizeof(int));
		duyetCayKhoa(t, fileout);
		fileout.close();
	}
}
void docCayKhoa(TREEKhoa &t) {
	int n=0 ;
	fstream filein("DSKhoa.dat", ios::in | ios::binary);
	filein.read(reinterpret_cast<char*>(&n), sizeof(int));
	int m = sizeof(Khoa);
	
	for (int i = 0; i < n; i++)
	{
		Khoa k;		
			filein.read(reinterpret_cast<char*>(&k),(m));
		themKhoaVaoCay(t,k);
		
	}	
	filein.close();
}
void duyetCayKhoaHoc(TREEKhoaHoc &t, fstream &fileout) {
	if (t == NULL) {
		return;
	}
	int m = sizeof(KhoaHoc);
	duyetCayKhoaHoc(t->pLeft, fileout);
	fileout.write(reinterpret_cast<char*>(&t->data), (m));
	duyetCayKhoaHoc(t->pRight, fileout);
}
void luuCayKhoaHoc(TREEKhoaHoc &t) {
	if (soLgKhoaHoc > 0)
	{
		fstream fileout("DSKhoaHoc.dat", ios::out | ios::binary);
		fileout.write(reinterpret_cast<char*>(&soLgKhoaHoc), sizeof(int));
		duyetCayKhoaHoc(t, fileout);
		fileout.close();
	}
}
void docCayKhoaHoc(TREEKhoaHoc &t) {
	int n = 0;
	fstream filein("DSKhoaHoc.dat", ios::in | ios::binary);
	filein.read(reinterpret_cast<char*>(&n), sizeof(int));
	int m = sizeof(KhoaHoc);

	for (int i = 0; i < n; i++)
	{
		KhoaHoc k;
		filein.read(reinterpret_cast<char*>(&k), (m));
		themKhoaHocVaoCay(t, k);

	}
	filein.close();
}
void duyetCayMH(TREEMonHoc &t, fstream &fileout) {
	if (t == NULL) {
		return;
	}
	int m = sizeof(MonHoc);
	duyetCayMH(t->pLeft, fileout);
	fileout.write(reinterpret_cast<char*>(&t->data), (m));
	duyetCayMH(t->pRight, fileout);
}
void luuCayMH(TREEMonHoc &t) {
	if (soLgMon > 0)
	{
		fstream fileout("DSMonHoc.dat", ios::out | ios::binary);
		fileout.write(reinterpret_cast<char*>(&soLgMon), sizeof(int));
		duyetCayMH(t, fileout);
		fileout.close();
	}
}
void docCayMH(TREEMonHoc &t) {
	int n = 0;
	fstream filein("DSMonHoc.dat", ios::in | ios::binary);
	filein.read(reinterpret_cast<char*>(&n), sizeof(int));
	int m = sizeof(MonHoc);

	for (int i = 0; i < n; i++)
	{
		MonHoc k;
		filein.read(reinterpret_cast<char*>(&k), (m));
		themMonHocVaoCay(t, k);

	}
	filein.close();
}
void DocFile_SinhVien(LIST_SV &sv)
{
	//tao bien kieu fstream , mo de doc , kieu nhi phan
	fstream myfile("DSSinhVien.dat", ios::in | ios::binary);
	//tinh kich thuoc moi sv
	int KichThuocMotPhanTuCua_SV = sizeof(SinhVien);	
	//khai bao bien de lay so luong sv
		int n = 0;		
		//ham doc file 
		myfile.read(reinterpret_cast<char*>(&n), sizeof(int));
		//chay theo so luong 
			for (int j = 0; j < n; j++)
			{//tao 1 bien kieu sv
				SinhVien c;
				//doc cac gt vao bien sv theo kich thuoc moi sv
				myfile.read(reinterpret_cast<char*>(&c), (KichThuocMotPhanTuCua_SV));
				//goi ham thm cuoi de them sv do vao ds
				dssv_themcuoi(sv, c );
			}
	//dong file
	myfile.close();
}
void LuuFile_SinhVien(LIST_SV &sv)
{
	//khai bao 1 file dat de ghi dl xuong, kieu nhi phan
	fstream myfile("DSSinhVien.dat", ios::out | ios::binary);
	//tinh kich thuoc cua 1 sv
	//luu kieu binary phai chinh sang kieu char voi kich thuoc nhat dinh , neu khong no se 
	//cap phat vung nho k xac dinh=> ct loi
	int KichThuocMotPhanTuCua_SV = sizeof(SinhVien) ;
	//ghi file , truyen vao dia chi cua bien soluong sv 
	myfile.write(reinterpret_cast<char*>(&soluongSV), sizeof(int));
	//chay vong for tu dau den cuoi ds
	for (NODE_SV *i = sv.pHead; i != NULL; i = i->pNext)
	{
		//ghi file gom data kieu char vs kich thuoc xc dinh 
		//truyen vao data , vi kich thuoc moi tinh dc
		myfile.write(reinterpret_cast<char*>(&i->data), KichThuocMotPhanTuCua_SV);
	}	
	//dong file
	myfile.close();
}
void DocFile_ChuongTrinh(LIST_CT &sv)
{
	fstream myfile("DSChuongTrinh.dat", ios::in | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(ChuongTrinhHoc);
	int n = 0;
	myfile.read(reinterpret_cast<char*>(&n), sizeof(int));
	for (int j = 0; j < n; j++)
	{
		ChuongTrinhHoc c;
		myfile.read(reinterpret_cast<char*>(&c), (KichThuocMotPhanTuCua_SV));

		dsct_themcuoi(sv, c);
	}

	myfile.close();
}
void LuuFile_ChuongTrinh(LIST_CT &sv)
{
	fstream myfile("DSChuongTrinh.dat", ios::out | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(ChuongTrinhHoc);
myfile.write(reinterpret_cast<char*>(&soluongCT), sizeof(int));
for (NODE_CT *i = sv.pHead; i != NULL; i = i->pNext)
{
	myfile.write(reinterpret_cast<char*>(&i->data), KichThuocMotPhanTuCua_SV);
}
myfile.close();
}
void DocFile_GD(LIST_GD &sv)
{
	fstream myfile("DSGiangDay.dat", ios::in | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(GiangDay);
	int n = 0;
	myfile.read(reinterpret_cast<char*>(&n), sizeof(int));
	for (int j = 0; j < n; j++)
	{
		GiangDay c;
		myfile.read(reinterpret_cast<char*>(&c), (KichThuocMotPhanTuCua_SV));

		dsgd_themcuoi(sv, c);
	}

	myfile.close();
}
void LuuFile_GD(LIST_GD &sv)
{
	fstream myfile("DSGiangDay.dat", ios::out | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(GiangDay);
	myfile.write(reinterpret_cast<char*>(&soluongGD), sizeof(int));
	for (NODE_GD *i = sv.pHead; i != NULL; i = i->pNext)
	{
		myfile.write(reinterpret_cast<char*>(&i->data), KichThuocMotPhanTuCua_SV);
	}
	myfile.close();
}
void DocFile_KQ(LIST_KQ &sv)
{
	fstream myfile("DSKetQua.dat", ios::in | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(KetQua);
	int n = 0;
	myfile.read(reinterpret_cast<char*>(&n), sizeof(int));
	for (int j = 0; j < n; j++)
	{
		KetQua c;
		myfile.read(reinterpret_cast<char*>(&c), (KichThuocMotPhanTuCua_SV));

		dskq_themcuoi(sv, c);
	}

	myfile.close();
}
void LuuFile_KQ(LIST_KQ &sv)
{
	fstream myfile("DSKetQua.dat", ios::out | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(KetQua);
	myfile.write(reinterpret_cast<char*>(&soluongKQ), sizeof(int));
	for (NODE_KQ *i = sv.pHead; i != NULL; i = i->pNext)
	{
		myfile.write(reinterpret_cast<char*>(&i->data), KichThuocMotPhanTuCua_SV);
	}
	myfile.close();
}
void DocFile_LH(LIST_LH &sv)
{
	fstream myfile("DSLopHoc.dat", ios::in | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(LopHoc);
	int n = 0;
	myfile.read(reinterpret_cast<char*>(&n), sizeof(int));
	for (int j = 0; j < n; j++)
	{
		LopHoc c;
		myfile.read(reinterpret_cast<char*>(&c), (KichThuocMotPhanTuCua_SV));

		dslh_themcuoi(sv, c);
	}

	myfile.close();
}
void LuuFile_LH(LIST_LH &sv)
{
	fstream myfile("DSLopHoc.dat", ios::out | ios::binary);
	int KichThuocMotPhanTuCua_SV = sizeof(LopHoc);
	myfile.write(reinterpret_cast<char*>(&soluongLH), sizeof(int));
	for (NODE_LH *i = sv.pHead; i != NULL; i = i->pNext)
	{
		myfile.write(reinterpret_cast<char*>(&i->data), KichThuocMotPhanTuCua_SV);
	}
	myfile.close();
}
void Khoitao(LIST_CT &listCT, LIST_GD &listGD, LIST_KQ &listKQ, TREEKhoa &tKHOA, TREEKhoaHoc &tKHOAHOC, TREEMonHoc &tMONHOC, LIST_LH &listLH, LIST_SV &listSV) {
	
	docCayKhoa(tKHOA);
	docCayKhoaHoc(tKHOAHOC);
	docCayMH(tMONHOC);
	DocFile_SinhVien(listSV);
	DocFile_ChuongTrinh(listCT);
	DocFile_GD(listGD);
	DocFile_KQ(listKQ);
	DocFile_LH(listLH);
}
void Thoat(LIST_CT listCT, LIST_GD listGD, LIST_KQ listKQ, TREEKhoa tKHOA, TREEKhoaHoc tKHOAHOC, TREEMonHoc tMONHOC, LIST_LH listLH, LIST_SV listSV)
{

	luuCayKhoa(tKHOA);
	luuCayKhoaHoc(tKHOAHOC);
	luuCayMH(tMONHOC);
	LuuFile_SinhVien(listSV);
	LuuFile_ChuongTrinh(listCT);
	LuuFile_GD(listGD);
	LuuFile_KQ(listKQ);
	LuuFile_LH(listLH);
}