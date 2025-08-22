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
    printf("\n--- Danh sach sinh vien ---\n");
    for (int i = 0; i < soLuongSV; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               danhSachSV[i].id, danhSachSV[i].name, danhSachSV[i].age, danhSachSV[i].phoneNumber);
    }
}
void suaThongTinSV() {
    int idCanSua;
    int timThay = 0;
    printf("\nNhap ID sinh vien muon sua: ");
    scanf("%d", &idCanSua);
    while (getchar() != '\n');
    for (int i = 0; i < soLuongSV; i++) {
        if (danhSachSV[i].id == idCanSua) {
            printf("Tim thay sinh vien co ID %d.\n", idCanSua);
            printf("Nhap ten moi: ");
            fgets(danhSachSV[i].name, sizeof(danhSachSV[i].name), stdin);
            danhSachSV[i].name[strcspn(danhSachSV[i].name, "\n")] = 0;
            printf("Nhap tuoi moi: ");
            scanf("%d", &danhSachSV[i].age);
            while (getchar() != '\n');
            printf("Cap nhat thong tin thanh cong!\n");
            timThay = 1;
            break;
        }
    }
    if (timThay == 0) {
        printf("Khong tim thay sinh vien co ID %d.\n", idCanSua);
    }
}
int main() {
    printf("Danh sach sinh vien ban dau:\n");
    inDanhSach();
    suaThongTinSV();
    printf("\nDanh sach sinh vien sau khi chinh sua:\n");
    inDanhSach();
    return 0;
}