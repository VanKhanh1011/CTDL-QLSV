#include "KhaiBao.h"
#include "ChuongTrinh.h"
#include "GiangDay.h"
#include "KetQua.h"
#include "Khoa.h"
#include "KhoaHoc.h"
#include "LopHoc.h"
#include "MonHoc.h"
#include "SinhVien.h"
#include "DocGhiFile.h"
using namespace std;
void Menu(LIST_CT listCT, LIST_GD listGD, LIST_KQ listKQ, TREEKhoa tKHOA, TREEKhoaHoc tKHOAHOC, TREEMonHoc tMONHOC,LIST_LH listLH, LIST_SV listSV) {
	int luachon;
	while (99) {
		system("cls");

		cout << "\n\t========= Menu ==========";
		cout << "\n\t1. Nhap Khoa";
		cout << "\n\t2.Xoa Khoa";
		cout << "\n\t3.Xuat Danh Sach Khoa";
		cout << "\n\t4.Tim Kiem Khoa Theo Ma";
		cout << "\n\t5.Tim Kiem Khoa Theo Ten";
		cout << "\n\t6.Sap Xep Thu Tu Khoa Theo Ma So";
		////////
		cout << "\n\t7.Nhap Sinh Vien";
		cout << "\n\t8.Sua Sinh Vien";
		cout << "\n\t9.Xoa Sinh Vien";
		cout << "\n\t10.Xuat Danh Sach Sinh Vien";
		cout << "\n\t11.Tim Kiem Sinh Vien Theo Ma";
		cout << "\n\t12.Tim Kiem Sinh Vien Theo Ten";
		cout << "\n\t13.Sap Xep Thu Tu Sinh Vien Theo Ma So";
		////////		
		cout << "\n\t14. Nhap Chuong Trinh Hoc";		
		cout << "\n\t15.Xuat Danh Sach Chuong Trinh Hoc";		
		/////////
		cout << "\n\t16. Nhap Giang Day";		
		cout << "\n\t17.Xuat Danh Sach Giang Day";
		//////////
		cout << "\n\t18. Nhap Ket Qua";		
		cout << "\n\t19.Xuat Danh Sach Ket Qua";		
		///////
		cout << "\n\t20. Nhap Khoa Hoc";		
		cout << "\n\t21.Xuat Danh Sach Khoa Hoc";	
		/////////////
		cout << "\n\t22. Nhap Lop Hoc";	
		cout << "\n\t23.Xuat Danh Sach Lop Hoc";
		////////////////
		cout << "\n\t24. Nhap Mon Hoc";	
		cout << "\n\t25.Xuat Danh Sach Mon Hoc";	
		/////////////////	
		cout << "\n\t26.Thong Ke Sinh Vien Theo Lop";
		cout << "\n\t27.Thong Ke Sinh Vien Theo Khoa";
		cout << "\n\t28.Thong Ke Sinh Vien Theo Hoc Ky";
		cout << "\n\t29.Thong Ke Sinh Vien Theo Nam Hoc";
		cout << "\n\t30.Mon hoc co nhieu sinh vien hoc nhat trong tung nam hoc";
		cout << "\n\t31.Danh sach nhung sinh vien thi lan II theo tung mon hoc";
		cout << "\n\t32.Danh sach nhung sinh vien thi lan II theo tung khoa";
		cout << "\n\t33.Danh sach nhung sinh vien thi lan II theo tung hoc ky";
		cout << "\n\t34.Danh sach nhung sinh vien thi lan II theo tung nam hoc";
		cout << "\n\t0.Thoat chuong trinh"<<endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		if (luachon == 1) {
			cin.ignore();
			themKhoa(tKHOA);
			cout << endl;
		}
		else if (luachon == 2) {
			cin.ignore();
			char maKhoa[6];
			cout << "Nhap ma Khoa can xoa: ";
			cin.get(maKhoa, 6);
			xoaCayKhoa(tKHOA,maKhoa);
		}
		else if (luachon == 3) {
			cin.ignore();
			cout << "DANH SACH KHOA" << endl;
			cout << " MaKhoa     |     TenKhoa     |     NamThanhLap " << endl;
			xuatDanhSachKhoa(tKHOA);
			
		}
		else if (luachon == 4) {
			cin.ignore();
			char makhoa[6];
			cout << "Nhap ma Khoa caN tim: ";
			cin.get(makhoa, 6);
			timKiemMaKhoa(tKHOA, makhoa);
		}
		else if (luachon == 5) {
			cin.ignore();			
			char tenkhoa[20];
			cout << "Nhap ten Khoa can tim: ";
			cin.get(tenkhoa, 6);
			timKiemTenKhoa(tKHOA, tenkhoa);
		}
		else if (luachon == 6) {
			cin.ignore();
			cout << "DANH SACH KHOA" << endl;
			cout << " MaKhoa     |     TenKhoa     |     NamThanhLap " << endl;
			xuatDanhSachKhoa(tKHOA);
		}
		else if (luachon == 7) {
			cin.ignore();
			NhapSV(listLH, listSV);
		}
		else if (luachon == 8) {
			cin.ignore();
			SuaSV(listSV);
		}
		else if (luachon == 9) {
			cin.ignore();
			XoaSV(listSV);
		}
		else if (luachon == 10) {
			cin.ignore();
			XuatDanhSachSV(listSV);
		}
		else if (luachon == 11) {
			cin.ignore();
			char maSV[6];
			cout << "Nhap ma sinh vien can tim: ";
			cin.get(maSV, 6);
			SearchMASV(listSV, maSV);			
		}
		else if (luachon == 12) {
			cin.ignore();
			char tenSV[20];
			cout << "Nhap TEN sinh vien can tim: ";
			cin.get(tenSV, 20);
			SearchTENSV(listSV, tenSV);
		}
		else if (luachon == 13) {
			cin.ignore();
			SAPXEPMASV(listSV);
		}
		else if (luachon == 14) {
			cin.ignore();
			NhapCT(listCT);
		}
		else if (luachon == 15) {
			cin.ignore();
			XuatDanhSachCT(listCT);
		}
		else if (luachon == 16) {
			cin.ignore();
			NhapGD(listGD, tKHOA, tMONHOC, listCT);
		}
		else if (luachon == 17) {
			cin.ignore();
			XuatDanhSachGD(listGD);
		}
		else if (luachon == 18) {
			cin.ignore();
			NhapKQ(listKQ,listSV,tMONHOC);
		}
		else if (luachon == 19) {
			cin.ignore();
			XuatDanhSachKQ(listKQ);
		}
		else if (luachon == 20) {			
			cin.ignore();
			themKhoaHoc(tKHOAHOC);
			cout << endl;
		}
		else if (luachon == 21) {
			cin.ignore();
			cout << "DANH SACH KHOA HOC" << endl;
			cout << " MaKhoaHoc     |     Nam BD     |     NamKT " << endl;
			xuatDanhSachKhoaHoc(tKHOAHOC);
		}
		else if (luachon == 22) {
			cin.ignore();
			NhapLH(listLH, tKHOA, tKHOAHOC, listCT);
		}
		else if (luachon == 23) {
		cin.ignore();
		XuatDanhSachLH(listLH);
		}
		else if (luachon == 24) {
		cin.ignore();
		themMH(tMONHOC, tKHOA);
		}
		else if (luachon == 25) {
		cin.ignore();
		cout << "DANH SACH MON HOC" << endl;
		cout << " MaMH     |     Ten MH     |     MaKhoa " << endl;
		xuatDanhSachMonHoc(tMONHOC);
		}
		else if (luachon == 26) {
		cin.ignore();
		char maLop[6];
		cout << "Nhap Ma Lop: ";
		cin.get(maLop, 6);
		thongKeSVTheoLop(listSV,maLop);
		}
		else if (luachon == 27) {
		cin.ignore();
		char maKhoa[6];
		cout << "Nhap Ma Khoa: ";
		cin.get(maKhoa, 6);
		thongKeSVTheoKhoa(listLH,listSV, maKhoa);
		}
		else if (luachon == 28) {
		cin.ignore();
		int hk;
		cout << "Nhap hoc ki: ";
		cin >> hk;
		thongKeSVTheoHK(listGD, listLH,listSV, hk);
		}
		else if (luachon == 29) {
		cin.ignore();
		int nh;
		cout << "Nhap nam hoc : ";
		cin >> nh;
		thongKeSVTheoNamHoc(listGD, listLH, listSV, nh);
		}	
		else if (luachon == 30) {
		cin.ignore();
		int nh;
		cout << "Nhap nam hoc : ";
		cin >> nh;
		monCoMaxSVTheoNH(listGD, listLH, listSV,tMONHOC, nh);
		}
		else if (luachon == 31) {
		cin.ignore();
		char maMH[6];
		cout << "Nhap Ma MH: ";
		cin.get(maMH, 6);
		dsSVthi2theoMon(listSV, listKQ, maMH);
		}
		else if (luachon == 32) {
		cin.ignore();
		char maKhoa[6];
		cout << "Nhap Ma Khoa: ";
		cin.get(maKhoa, 6);
		dsSVthi2theoKhoa(listGD, listSV, listKQ, maKhoa);
		}
		else if (luachon == 33) {
		cin.ignore();
		int hk;
		cout << "Nhap HK: ";
		cin>>hk;
		dsSVthi2theoHK(listGD,listSV, listKQ, hk);
		}
		else if (luachon == 34) {
		cin.ignore();
		int nh;
		cout << "Nhap NH: ";
		cin >> nh;
		dsSVthi2theoHK(listGD, listSV, listKQ, nh);
		}
		else if (luachon == 0) {
		cin.ignore();
		Thoat( listCT,  listGD,  listKQ, tKHOA,  tKHOAHOC, tMONHOC,  listLH,  listSV);
		exit(0);
		}
		system("pause");
	}
}

int main() {
	LIST_CT listCT;
	LIST_GD listGD;
	LIST_KQ listKQ;
	TREEKhoa tKHOA= NULL;
	TREEKhoaHoc tKHOAHOC = NULL;
	TREEMonHoc tMONHOC= NULL;
	LIST_LH listLH;
	LIST_SV listSV;
	
	
	listCT.pHead = listCT.pTail = NULL;
	listGD.pHead = listGD.pTail = NULL;
	listKQ.pHead = listKQ.pTail = NULL;
	listLH.pHead = listLH.pTail = NULL;
	listSV.pHead = listSV.pTail = NULL;
 	Khoitao(listCT, listGD, listKQ, tKHOA, tKHOAHOC, tMONHOC, listLH, listSV);
	Menu( listCT,  listGD,  listKQ,  tKHOA,  tKHOAHOC,  tMONHOC,  listLH,  listSV);
	
	
	return 0;
}
