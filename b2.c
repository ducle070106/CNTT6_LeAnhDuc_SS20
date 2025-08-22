#include <stdio.h>
#include <string.h>

struct SinhVien {
    char name[50];
    int age;
    char phoneNumber[20];
};
int main() {
    struct SinhVien sv;
    printf("Nhap thong tin sinh vien:\n");
    printf("Nhap ten: ");
    fgets(sv.name, sizeof(sv.name), stdin);
    sv.name[strcspn(sv.name, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);
    while(getchar() != '\n');
    printf("Nhap so dien thoai: ");
    fgets(sv.phoneNumber, sizeof(sv.phoneNumber), stdin);
    sv.phoneNumber[strcspn(sv.phoneNumber, "\n")] = 0;
    printf("\nThong tin sinh vien vua nhap:\n");
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("So dien thoai: %s\n", sv.phoneNumber);
    return 0;
}