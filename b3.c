#include <stdio.h>
#include <string.h>

struct SinhVien {
    char name[50];
    int age;
    char phoneNumber[20];
};
int main() {
    struct SinhVien danhSachSV[5];
    int i;
    for (i = 0; i < 5; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("Ten: ");
        fgets(danhSachSV[i].name, sizeof(danhSachSV[i].name), stdin);
        danhSachSV[i].name[strcspn(danhSachSV[i].name, "\n")] = 0;
        printf("Tuoi: ");
        scanf("%d", &danhSachSV[i].age);
        while(getchar() != '\n');
        printf("So dien thoai: ");
        fgets(danhSachSV[i].phoneNumber, sizeof(danhSachSV[i].phoneNumber), stdin);
        danhSachSV[i].phoneNumber[strcspn(danhSachSV[i].phoneNumber, "\n")] = 0;
    }
    printf("\n--- Danh sach sinh vien vua nhap ---\n");
    for (i = 0; i < 5; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        printf("Ten: %s\n", danhSachSV[i].name);
        printf("Tuoi: %d\n", danhSachSV[i].age);
        printf("So dien thoai: %s\n", danhSachSV[i].phoneNumber);
    }
    return 0;
}