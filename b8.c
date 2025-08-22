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
    for (int i = 0; i < soLuongSV; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSachSV[i].id, danhSachSV[i].name, danhSachSV[i].age, danhSachSV[i].phoneNumber);
    }
}
void chenSinhVien() {
    if (soLuongSV >= 50) {
        printf("Mang da day, khong the them sinh vien moi.\n");
        return;
    }
    int viTri;
    printf("\nNhap vi tri can chen (tu 1 den %d): ", soLuongSV + 1);
    scanf("%d", &viTri);
    while (getchar() != '\n');
    if (viTri < 1 || viTri > soLuongSV + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    struct SinhVien svMoi;
    printf("\nNhap thong tin sinh vien moi:\n");
    svMoi.id = soLuongSV + 1;
    printf("ID: %d\n", svMoi.id);
    printf("Ten: ");
    fgets(svMoi.name, sizeof(svMoi.name), stdin);
    svMoi.name[strcspn(svMoi.name, "\n")] = 0;
    printf("Tuoi: ");
    scanf("%d", &svMoi.age);
    while (getchar() != '\n');
    printf("So dien thoai: ");
    fgets(svMoi.phoneNumber, sizeof(svMoi.phoneNumber), stdin);
    svMoi.phoneNumber[strcspn(svMoi.phoneNumber, "\n")] = 0;
    for (int i = soLuongSV; i >= viTri; i--) {
        danhSachSV[i] = danhSachSV[i-1];
    }
    danhSachSV[viTri-1] = svMoi;
    soLuongSV++;
    printf("Da chen sinh vien thanh cong!\n");
}
int main() {
    printf("Danh sach sinh vien ban dau:\n");
    inDanhSach();
    chenSinhVien();
    printf("\nDanh sach sinh vien sau khi chen:\n");
    inDanhSach();
    return 0;
}