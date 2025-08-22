#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
struct SinhVien danhSachSV[50] = {
    {1, "Nguyen Van A", 20, "0912345678"},
    {2, "Tran Thi B", 21, "0987654321"},
    {3, "Le Van C", 22, "0901234567"},
    {4, "Pham Thi D", 19, "0976543210"},
    {5, "Hoang Van E", 23, "0965432109"}
};
int soLuongSV = 5;
void inDanhSach() {
    printf("\n--- Danh sach sinh vien hien tai ---\n");
    if (soLuongSV == 0) {
        printf("Danh sach dang trong.\n");
        return;
    }
    for (int i = 0; i < soLuongSV; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSachSV[i].id, danhSachSV[i].name, danhSachSV[i].age, danhSachSV[i].phoneNumber);
    }
}
void xoaSinhVien() {
    if (soLuongSV == 0) {
        printf("Danh sach sinh vien dang trong.\n");
        return;
    }
    char tenCanXoa[50];
    int timThay = 0;
    int viTriXoa = -1;
    printf("\nNhap ten sinh vien muon xoa: ");
    fgets(tenCanXoa, sizeof(tenCanXoa), stdin);
    tenCanXoa[strcspn(tenCanXoa, "\n")] = 0;
    for (int i = 0; i < soLuongSV; i++) {
        if (strcmp(danhSachSV[i].name, tenCanXoa) == 0) {
            viTriXoa = i;
            timThay = 1;
            break;
        }
    }
    if (timThay == 1) {
        for (int i = viTriXoa; i < soLuongSV - 1; i++) {
            danhSachSV[i] = danhSachSV[i + 1];
        }
        soLuongSV--;
        printf("Da xoa sinh vien '%s' thanh cong.\n", tenCanXoa);
    } else {
        printf("Khong tim thay sinh vien co ten '%s'.\n", tenCanXoa);
    }
}
int main() {
    printf("Danh sach sinh vien ban dau:\n");
    inDanhSach();
    xoaSinhVien();
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    inDanhSach();
    return 0;
}