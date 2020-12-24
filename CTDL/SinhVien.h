#pragma once

#include "KhaiBao.h"
#include "LopHoc.h"

using namespace std;
int n = 0;
//tao 1 node co du lieu la sv, dau tien khoi tao thi pnnext cua no se -> null
//truyen vao 1 sv

NODE_SV* GetNodeSV(SinhVien sv)
{//tao 1 node p 
	NODE_SV* p = new NODE_SV;

	if (p == NULL)
	{
		return NULL;
	}
	//du lieu cua p la sv 
	p->data = sv;
	p->pNext = NULL; // khoi tao moi lien ket
	return p;
}
//truyen vao 1 ds SV va 1 masv can ktra
//cho duyệt , tạo 1 node k bđ từ phead, nếu k còn != null, thì k=k->pnext
//nếu gặp k->data.masv = masv nhap vo , thi return true, else return false
//so sanh strcmp danh cho char, 0 la =, > 0 la bn trai lon hon, <0 la ben phai lon hon
bool KTraTrungMaSV(LIST_SV &SV, char maSV[]) {
	for (NODE_SV *k = SV.pHead; k != NULL; k = k->pNext) {
		if (strcmp(k->data.maSinhVien , maSV)==0) {
			return true;
		}
	}
	return false;
}
//truyen vao ds sv, sv can them
//khoi tao node cho sv vua truyen vao 
//kiem tra neu lphead=lptail=null (ds trống) thì l.phea=l.ptail= node sv cân them luon
//neu ds chua trong thi lptail->pnext= nose sv ; lptail= node sv
//tang sl sv++
void dssv_themcuoi(LIST_SV& l, SinhVien sv) {
	NODE_SV* p = GetNodeSV(sv);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
	soluongSV++;
}
//truyen vao 1 dsanh sach sv va sinh vien muon them
//tao node sv tu sinh vien vua truyen vao
//kiem tra neu lphead=lptail=null (ds trống) thì l.phea=l.ptail= node sv cân them luon
//neu ds co ptu thi sode sv->pnext=phead; phead=node sv
void dssv_themdau(LIST_SV& l, SinhVien sv) {
	NODE_SV* p = GetNodeSV(sv);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}

}
//truyen vao DS LOP HOC VA DS SV, ds lop hoc de kiem tra lop hoc co ton tai chua
//dau tien khai bao 1  sv
//cho nhap ma sv vao
//chay ham kiem tra xem masv do ton tai hay chua, neu ton tai roi thi k cho, thong bao nhap lai masv
//neu masv chua ton tai thi cho nhap tiep cac thong tin khac 
//toi khi nhap tt lop thi chay ham tra xem lop do co ton tai chua truyn vao ds lop va sv.malop, neu chua thi bat nhap lai
//sau khi day du thong tin thi goi ham them cuoi,  truyen vao dssv va sv(do trong ham them cuoi da cotao node cho sv roi)
void NhapSV(LIST_LH &LH, LIST_SV &SV)
{
	SinhVien sv;
	do
	{
	cout << "Nhap Ma Sinh Vien: ";
	fflush(stdin);
	cin.get(sv.maSinhVien,6);
	cin.ignore();
	if (KTraTrungMaSV(SV, sv.maSinhVien))
		cout << "Ma SV BI TRUNG. Moi nhap lai. " << endl;
	} while (KTraTrungMaSV(SV, sv.maSinhVien));
	cout << "Nhap Ho & Ten Sinh Vien: ";
	cin.get(sv.hoTen, 20);
	cin.ignore();
	cout << "Nhap Nam Sinh Sinh Vien: ";
	cin >> sv.namSinh;
	cin.ignore();
	cout << " Nhap Gioi Tinh Sinh Vien: ";
	cin.get(sv.gioiTinh, 5);
	cin.ignore();
	do
	{
	cout << " Nhap Ma Lop: ";
	cin.get(sv.maLop, 6);
	cin.ignore();
	if (!KTraTrungMaLH(LH, sv.maLop))
		cout << "Ma Lop chua co. Moi nhap lai. "<<endl;
	} while (!KTraTrungMaLH(LH, sv.maLop));
	dssv_themcuoi(SV, sv);
}
//truyen vao dssv
//neu ds.phead == null thì return
bool dssv_kiemtrarong(LIST_SV& SV) {//kiem tra ds rong
	return SV.pHead == NULL;
}
//xoa sau node p
//truyen vao ds, NODE p de xoa cai nut sau nut p do
//kiem tra neu node p truyen vao = null hoac node sau p = null thi return lun
//neu co ton tai node p va node sau p
//tao nodexoa= p->next(node can xoa)
//p->next = nodexoa->next (cap nhat lien ket)
//xoa nodexoa
void dssv_xoasau(LIST_SV& SV, NODE_SV* p) {
	if (p == NULL || p->pNext == NULL) return;
	NODE_SV* nodeDeleted = p->pNext;
	p->pNext = nodeDeleted->pNext;
	delete nodeDeleted;

	return;
}
//chi cna truyen ds sv
//kiem tra neu ds rong thi return luon
//neu co tin tai node trong ds thi
//nodexoa=l.phead
//l.phead=l.phead->next
//xoa nodexoa
void dssv_xoadau(LIST_SV& SV) {
	if (dssv_kiemtrarong(SV)) return;
	NODE_SV* p = SV.pHead;
	SV.pHead = p->pNext;
	delete p;

	return;
}
//chi can truyen dssv
//kiem tra neu ds rong thi return luon
//neu ds co ton tai node thi 
//cho duyet tu dau ds
//tao 1 node before
//cho duyet tu dau den cuoi
//neu chua tim dc node cuoi thi before =p r duyet tiep
//neu tim dc node cuoi p=ptail,
//ptail=before
//before->next=null
//xoa p
void dssv_xoacuoi(LIST_SV &SV) {
	if (dssv_kiemtrarong(SV)) return;
	NODE_SV* beforP = NULL;
	for (NODE_SV* p = SV.pHead; p != NULL; p = p->pNext) {
		if (p == SV.pTail) {
			SV.pTail = beforP;
			beforP->pNext = NULL;
			delete p;

			return;
		}
		beforP = p;
	}
}
//truyen vaods va ma sv can lay tt
//kiem tra neu ds ron gthi reutrn
//neu ds co pt thi cho chay vong for tu dau toi cuoi 
//neu p->data.masv = id thi return p
NODE_SV* LayThongTinSV(LIST_SV &SV, char id[]) {
	if (SV.pHead == NULL) return NULL;
	for (NODE_SV* p = SV.pHead; p != NULL; p = p->pNext)
		if (strcmp(p->data.maSinhVien ,id)==0)
			return p;
	return NULL;
}
//ham xoa
//truyen vao ds 
//yc nhap vao masv muon xoa
// tao nodexoa = laytt(theo masv do)
//neu node xoa = phead thi goi xoa dau
//neu node xoa = ptail thi goi xo cuoi
//neu no la node giua thi tao 1 cai temp= phead, cho chay toi cuoi, goi ham xoa sau node p
//tbao xoa thanh cong
//thieu ktra masv ton tai
void XoaSV(LIST_SV& SV) {
	char MSV[6];

	cout << "Nhap Ma Sinh Vien Can Xoa:";
	cin.get(MSV, 6);
	cin.ignore();
	NODE_SV* nodeDeleted = LayThongTinSV(SV, MSV);

	if (nodeDeleted == SV.pHead)
		dssv_xoadau(SV);
	else if (nodeDeleted == SV.pTail)
		dssv_xoacuoi(SV);
	else {
		NODE_SV* temp = SV.pHead;
		while (temp->pNext != nodeDeleted)
			temp = temp->pNext;
		dssv_xoasau(SV, temp);
	}
	cout << "Xoa Thanh Cong";
}
//truyen vao ds, yc nhap masv muon sua
//ktra masv co ton tai k , neu k phai cho nhap lai
//cung khai bao 1 node lay thong tin sv  sua
//r nhap lai cho sv do vo node tam vua tao, enter la luu vi no sd con tro
void SuaSV(LIST_SV &SV) {
	char maSV[6];

	do {
		fflush(stdin);
		cout << "Nhap ma Sinh Vien muon sua: ";
		cin.get(maSV,6);
		cin.ignore();
		if (!KTraTrungMaSV(SV, maSV)) {
			cout << "Ma Sinh Vien nay khong ton tai.. Nhap lai ma sinh VIen khac: " << endl << endl;
		}
	} while (!KTraTrungMaSV(SV, maSV));

	NODE_SV *tam = LayThongTinSV(SV, maSV);
	cout << "Nhap TEN           : "; cin.get(tam->data.hoTen, 20);
	cin.ignore();
	cout << "Nhap NAM SINH         : "; cin>>(tam->data.namSinh);
	cin.ignore();
	cout << "Nhap GIOI TINH          : "; cin.get(tam->data.gioiTinh, 5);
	cin.ignore();
	cout << "Nhap MA LOP        : "; cin.get(tam->data.maLop,6);
}
//duyet r in ra 
//truyen vao danh sach sv

//duyet tu dau den cuoi ds,tao node i =pheag, duyet moi lan duyet thi in ra i.thong tin
void XuatDanhSachSV(LIST_SV SV)
{
	cout << endl;
	cout << "DANH SACH SINH VIEN" << endl;
	for (NODE_SV *i = SV.pHead; i != NULL; i = i->pNext)
	{
		cout << "Ma sinh vien          : " << i->data.maSinhVien << endl;
		cout << "Ho TEn        : " << i->data.hoTen << endl;
		cout << "Gioi Tinh             : " << i->data.gioiTinh << endl;
		cout << "Nam Sinh: " << i->data.namSinh << endl;
		cout << "Lop     : " << i->data.maLop << endl;

	}
}
//truyen vao ds va ma sv can tim
//duyet ds tu dau, r so sanh strcmp p.data.masv voi masv can tim.
//neu ss =0 thi in ra p.thong tin tat ca, neu k tim dc thi tang vi tri len, r duyet tim tiep

void SearchMASV(LIST_SV SV, char value[]) {
	int position = 0;
	for (NODE_SV *p = SV.pHead; p != NULL; p = p->pNext) {
		if (strcmp(p->data.maSinhVien , value)==0) {
			cout << position;
			cout << p->data.hoTen;
			cout << p->data.maSinhVien;
			cout << p->data.maLop;
			cout << p->data.gioiTinh;
			cout << p->data.namSinh;
		}
		++position;
	}
}

//truyen vao ds va ma sv can tim
//duyet ds tu dau, r so sanh strcmp p.data.masv voi masv can tim.
//neu ss =0 thi in ra p.thong tin tat ca, neu k tim dc thi tang vi tri len, r duyet tim tiep

void SearchTENSV(LIST_SV SV, char value[]) {
	int position = 0;
	for (NODE_SV *p = SV.pHead; p != NULL; p = p->pNext) {
		if (strcmp(p->data.hoTen, value) == 0) {
			cout << position;
			cout << p->data.hoTen;
			cout << p->data.maSinhVien;
			cout << p->data.maLop;
			cout << p->data.gioiTinh;
			cout << p->data.namSinh;
		}
		++position;
	}
}
//them 1 node sau node q
//truyen vao ds, node la sv can them, q la sinh vien ma truoc sv can them
//tao node cho 2 cai sinh vien
//neu q la ptail thi goi  them cuoi
//neu k phai ptail thi node->pnext=q->pnext, q->pnext=node
void INSERTSAU(LIST_SV SV, SinhVien  node, SinhVien  q)
{
	NODE_SV* p = GetNodeSV(node);
	NODE_SV* k = GetNodeSV(q);
	if (k != SV.pTail)
	{
		p->pNext = k->pNext;
		k->pNext = p;
	}
	else
	{
		dssv_themcuoi(SV, node);
	}
}
//truyen vao ds
//cho duyet tu dau den cuoi
//moi lan duyet cho bien dem tang len 1

int DemSoPhanTu(LIST_SV l) {
	int count = 0;
	for (NODE_SV* p = l.pHead; p != NULL; p = p->pNext)
	{

		count++;
		p = p->pNext;

	}
	return count;
}
//truy ds , node the, vitri
//tao bien chua kq cua ham dem so pt 
//neu ds rong hoac la them vao vitri 1 thi goi ham them dau
//neu ma vi tri = demtemp+1 thi goi ham them cuoi
//neu them bat ky thi tao 1  bien dem de xac dinh vi tri can them
//tao 1 node g nam truoc node q can xoa, duyet ds tu dau den cuoi de xac dinh node q va vi tri
//chay for k tu dau den cuoi, tang dem len 1 neu dem = vt thi tao 1 node h, neu chua toi vi tri thi g=k de no giu cai node trc node can them
//phai co node moi de trong truong hop là có 2 node can them
//h=p la node can them
//k hientai la q, h la nut them truoc k sau g
//h->pnext = k(h tro toi nut k )
//g-pnext = h
//gio thi h chen giua g vs k
void ThemNode_p_VaoViTriBatKi(LIST_SV &l, SinhVien p, int vt)
{
	int demtemp = DemSoPhanTu(l);
	// danh sách đang rỗng
	if (l.pHead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		dssv_themdau(l, p);
	}
	else if (vt == demtemp + 1)
	{
		// thêm node p vào cuối danh sách l
		dssv_themcuoi(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		NODE_SV *g = new NODE_SV; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (NODE_SV *k = l.pHead; k != NULL; k = k->pNext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				NODE_SV *h = GetNodeSV(p); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pNext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pNext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}
///////cac ham de sap xep thu tu masv
///////////////////////////////////
//hoan vi 
void hoanvi(SinhVien &a, SinhVien  &b)


{
	SinhVien t = a;
	a = b;
	b = t;
}
//so sanh 2 ma neu <0 thi ma 1>mã 2
int kiemTraThuTuMaCB(char masv1[], char maSV[]) {

	
	if (strcmp(masv1, maSV) > 0) {
		return 1;
	}

	return 0;
}
//truyen vao ds
//tao 3 bien i, j de duyet 2 vong for long nhau, i tu dau, con j tu sau i, de lay 2 gia tri lin ke so sanh
//neu so sanh i->data.masv va j->data.masv ma return 1 thi nghia la i>j ma sx tang dan nen hoan vi i va j
//xuat ra ds
void SAPXEPMASV(LIST_SV &l)
{
	NODE_SV*i, *j, *min;

	for (i = l.pHead; i != l.pTail; i = i->pNext)
	{
		for (j = i->pNext; j != NULL; j = j->pNext)
		{
			if (kiemTraThuTuMaCB(i->data.maSinhVien, j->data.maSinhVien) == 1)
			{
				hoanvi(i->data, j->data);
			}
		}
	}
	XuatDanhSachSV(l);
}
//truyen vao ds  va ma lop
//chay tu dau den cuoi
//neu tai cho node do ->data.malop = malop nhap vo, thiin hong tin no ra
void thongKeSVTheoLop( LIST_SV &SV , char maLop[]) 
{
	
	for (NODE_SV *i = SV.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maLop, maLop) == 0) {
			cout << "Ma sinh vien          : " << i->data.maSinhVien << endl;
			cout << "Ho TEn        : " << i->data.hoTen << endl;
			cout << "Gioi Tinh             : " << i->data.gioiTinh << endl;
			cout << "Nam Sinh: " << i->data.namSinh << endl;
			cout << "Lop     : " << i->data.maLop << endl;			
		}
	}
}
//truyen vao ds  va ma lop
//chay tu dau den cuoi
//neu tai cho node do ->data.makhoa = makhoa nhap vo, thi in hong tin no ra
//thi phai co makhoa = thi moi xuat theo lop
//vi trong sv chi co ma lop lam khoa
void thongKeSVTheoKhoa(LIST_LH &LH,LIST_SV &SV,char maKhoa[]) 
{
	for (NODE_LH *i = LH.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maKhoa, maKhoa) == 0) {
			thongKeSVTheoLop(SV, i->data.maLop);
		}
	}
}
//truyen vao ds  va ma lop
//chay tu dau den cuoi
//neu tai cho node do ->data.hocky = hocky nhap vo
//thi goi xuat theo khoa, r trong xuat khoa lia goi xuat lop
//vi trong sv chi co ma lop lam khoa

void thongKeSVTheoHK(LIST_GD &GD, LIST_LH &LH, LIST_SV &SV, int HK)
{
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.hocKi==HK) {
			thongKeSVTheoKhoa(LH,SV, i->data.maKhoa);
		}
	}
}
//truyen vao ds  va ma lop
//chay tu dau den cuoi
//neu tai cho node do ->data.hocky = hocky nhap vo
//thi goi xuat theo khoa, r trong xuat khoa lia goi xuat lop
//vi trong sv chi co ma lop lam khoa
void thongKeSVTheoNamHoc(LIST_GD &GD, LIST_LH &LH, LIST_SV &SV, int NH)
{
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.namHoc == NH) {
			thongKeSVTheoKhoa(LH, SV, i->data.maKhoa);
		}
	}
}
///cung giong nhu thong ke sv theo lop, nhung ma dem chu k tra ve thong tin
///dem tat ca neu trung ma lop
int demSVTheoLop(LIST_SV &SV, char maLop[])
{
	int dem=0;
	for (NODE_SV *i = SV.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maLop, maLop) == 0) {
			dem++;
		}
	}
	return dem;
}
//cho chay tu dau den cuoi lop hoc
//so sanh ma khoa neu bang
//ao 2 bien, dem lop =goi ham dem lop
//dem khoa = dem lop +demkhoa
//khi thay trung khoa se dem het tat ca sinh vin trong cac lop co khoa do
int demSVTheoKhoa(LIST_LH &LH, LIST_SV &SV, char maKhoa[])
{
	int demlop = 0;
	int demkhoa = 0;
	for (NODE_LH *i = LH.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maKhoa, maKhoa) == 0) {
			demlop=demSVTheoLop(SV, i->data.maLop);
			demkhoa += demlop;
		}
	}
	return demkhoa;
}
//neu cay mon hoc  = nulll thi return
//neu ss mamh gion thi dem sv theo khoa
//dem sv mon hoc = dem sv thoe khoa thi dem len 1
//truong hop neu ss mamh trong cây lon hon mh nhap vao thi bo qua k dem , chay tiep qua trai de ss tiep 
//truong hop neu ss mamh trong cây nho hon mh nhap vao thi bo qua k dem , chay tiep qua phai de ss tiep 
//xet neu trung mamh thi xet toi khoa, tat ca khoa co mamh do, r xet toi tat ca lop trong att ca khoa do, xong dem tat ca sv trong lop do
int demSVTheoMon(TREEMonHoc &tMH, LIST_LH &LH, LIST_SV &SV, char maMH[]) {
	int demmon = 0;
	int demkhoa = 0;
	if (tMH == NULL)
	{
		return false;
	}
	else if (strcmp(tMH->data.maMH, maMH) == 0)
	{
		demkhoa = demSVTheoKhoa(LH, SV, tMH->data.maKhoa);
		demmon += demkhoa;
		return demmon;
	}
	else if (strcmp(tMH->data.maMH, maMH) > 0)
	{
		return demSVTheoMon(tMH->pLeft,LH,SV, maMH);
	}
	else
	{
		return demSVTheoMon(tMH->pRight,LH,SV, maMH);
	}
}
///truyen vao ds gd , ds lop hoc, ds sv, cay mon hoc, nam hoc can tim
//tao 2 bien va 1 caia node
//cho vong for chay tu dau den cuoi giang day
//neu nam hoc bang nam nhap vo
//dem sv theo mon truoc roi so snah voi max, neu mon nao nhieu nhat thi la max
void monCoMaxSVTheoNH(LIST_GD &GD, LIST_LH &LH, LIST_SV &SV, TREEMonHoc &tMH, int NH) {
	int max = 0;
	int demmon=0;
	NODE_GD  *k=new NODE_GD;
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.namHoc == NH) {
			demmon=demSVTheoMon(tMH,LH, SV, i->data.maMon);
			if (max < demmon) {
				max = demmon;
				k = i;
			}
		}
	}
	cout << "Ma mon nhieu sinh vien hoc nhat la: " << k->data.maMon<<endl;
}
//nhap ma sv cam xuat, cho chay for tu dau den cuoi, neu gapp masv do thi xuat ra thong tin
void Xuat1SVTheoMaSV(LIST_SV SV,char maSV[])
{	
	for (NODE_SV *i = SV.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maSinhVien, maSV) == 0) {
			cout << "Ma sinh vien          : " << i->data.maSinhVien << endl;
			cout << "Ho TEn        : " << i->data.hoTen << endl;
			cout << "Gioi Tinh             : " << i->data.gioiTinh << endl;
			cout << "Nam Sinh: " << i->data.namSinh << endl;
			cout << "Lop     : " << i->data.maLop << endl;
		}
	}
}
//xet theo ket qua 
//truyen dssv, dskq, mamon
//cho for chay tu dau toi cuoi, neu giong ma mon va lan thi = 2 thi xuat tt sv do
void dsSVthi2theoMon(LIST_SV &SV, LIST_KQ &KQ,char maMon[]) {
	for (NODE_KQ *i = KQ.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maMon, maMon) == 0&& i->data.lanThi==2) {
			Xuat1SVTheoMaSV(SV, i->data.maSinhVien);
		}
	}
}
//xet theo giang day
//truyen dsgd, dskq, makhoa
//cho for chay tu dau toi cuoi, neu giong ma khoa thi xuat theo thi lan 2 theo mon
void dsSVthi2theoKhoa(LIST_GD &GD, LIST_SV &SV, LIST_KQ &KQ, char maKhoa[]) {
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		if (strcmp(i->data.maKhoa, maKhoa) == 0 ) {
			dsSVthi2theoMon(SV, KQ, i->data.maMon);
		}
	}
}
//xet theo giang day
//truyen dsgd, dskq, hoc ky, kq
//cho for chay tu dau toi cuoi, neu giong hoc ky thi xuat theo mon
void dsSVthi2theoHK(LIST_GD &GD, LIST_SV &SV, LIST_KQ &KQ, int HK) {
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.hocKi=HK) {
			dsSVthi2theoMon(SV, KQ, i->data.maMon);
		}
	}
}
//xet theo giang day
//truyen dsgd, dskq, nam hoc, kq
//cho for chay tu dau toi cuoi, neu giong nam hoc thi xuat theo mon
void dsSVthi2theoNH(LIST_GD &GD, LIST_SV &SV, LIST_KQ &KQ, int NH) {
	for (NODE_GD *i = GD.pHead; i != NULL; i = i->pNext)
	{
		if (i->data.namHoc = NH) {
			dsSVthi2theoMon(SV, KQ, i->data.maMon);
		}
	}
}

