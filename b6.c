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
void themSinhVien() {
    if (soLuongSV >= 50) {
        printf("Mang da day, khong the them sinh vien moi.\n");
        return;
    }
    printf("\nNhap thong tin sinh vien moi:\n");
    danhSachSV[soLuongSV].id = soLuongSV + 1;
    printf("ID: %d\n", danhSachSV[soLuongSV].id);
    printf("Ten: ");
    fgets(danhSachSV[soLuongSV].name, sizeof(danhSachSV[soLuongSV].name), stdin);
    danhSachSV[soLuongSV].name[strcspn(danhSachSV[soLuongSV].name, "\n")] = 0;
    printf("Tuoi: ");
    scanf("%d", &danhSachSV[soLuongSV].age);
    while (getchar() != '\n');
    printf("So dien thoai: ");
    fgets(danhSachSV[soLuongSV].phoneNumber, sizeof(danhSachSV[soLuongSV].phoneNumber), stdin);
    danhSachSV[soLuongSV].phoneNumber[strcspn(danhSachSV[soLuongSV].phoneNumber, "\n")] = 0;
    soLuongSV++;
    printf("Da them sinh vien thanh cong!\n");
}
int main() {
    printf("Danh sach sinh vien ban dau:\n");
    inDanhSach();
    themSinhVien();
    printf("\nDanh sach sinh vien sau khi them moi:\n");
    inDanhSach();
    return 0;
}
