#include <stdio.h>
#include <string.h>

int n = 0; // So luong sach hien tai
struct Sach {
    int maSach;
    char tenSach[100];
    char giaSach[100];
};

// Khai bao mang sach, su dung mot kich thuoc co dinh
struct Sach dsSach[100]; // Dung mot mang co dinh, co the thay doi tuy nhu cau
int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1: {
                // Nhap so luong va thong tin sach
                printf("Nhap so luong sach: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("\nNhap thong tin sach %d:\n", i + 1);
                    printf("Ma sach: ");
                    scanf("%d", &dsSach[i].maSach);
                    getchar();
                    printf("Ten sach: ");
                    fgets(dsSach[i].tenSach, 100, stdin);
                    dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = 0;
                    printf("Gia sach (nhap gia duoi dang chuoi): ");
                    fgets(dsSach[i].giaSach, 100, stdin);
                    dsSach[i].giaSach[strcspn(dsSach[i].giaSach, "\n")] = 0;  // Loai bo ky tu newline
                }
                break;
            }
            case 2: {
                // Hien thi thong tin sach
                printf("\nDanh sach sach:\n");
                for (int i = 0; i < n; i++) {
                    printf("Ma sach: %d, Ten sach: %s, Gia sach: %s\n", dsSach[i].maSach, dsSach[i].tenSach, dsSach[i].giaSach);
                }
                break;
            }
            case 3: {
                // Them sach vao vi tri
                if (n >= 100) {
                    printf("Danh sach sach da day!\n");
                    break;
                }
                int viTri;
                printf("Nhap vi tri can them (0 den %d): ", n);
                scanf("%d", &viTri);

                if (viTri < 0 || viTri > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("\nNhap thong tin sach can them:\n");
                printf("Ma sach: ");
                scanf("%d", &dsSach[n].maSach);
                getchar();
                printf("Ten sach: ");
                fgets(dsSach[n].tenSach, 100, stdin);
                dsSach[n].tenSach[strcspn(dsSach[n].tenSach, "\n")] = 0;
                printf("Gia sach (nhap gia duoi dang chuoi): ");
                fgets(dsSach[n].giaSach, 100, stdin);
                dsSach[n].giaSach[strcspn(dsSach[n].giaSach, "\n")] = 0;
                for (int i = n; i > viTri; i--) {
                    dsSach[i] = dsSach[i - 1];
                }
                n++;
                break;
            }
            case 4: {
                // Xoa sach theo ma sach
                int maSach;
                printf("Nhap ma sach can xoa: ");
                scanf("%d", &maSach);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (dsSach[i].maSach == maSach) {
                        for (int j = i; j < n - 1; j++) {
                            dsSach[j] = dsSach[j + 1];
                        }
                        n--;
                        printf("Xoa sach thanh cong!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Khong tim thay sach voi ma %d!\n", maSach);
                }
                break;
            }
            case 5: {
                // Cap nhat thong tin sach theo ma sach
                int maSach;
                printf("Nhap ma sach can cap nhat: ");
                scanf("%d", &maSach);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (dsSach[i].maSach == maSach) {
                        printf("\nNhap thong tin sach moi:\n");
                        printf("Ten sach: ");
                        getchar();
                        fgets(dsSach[i].tenSach, 100, stdin);
                        dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = 0;
                        printf("Gia sach (nhap gia duoi dang chuoi): ");
                        fgets(dsSach[i].giaSach, 100, stdin);
                        dsSach[i].giaSach[strcspn(dsSach[i].giaSach, "\n")] = 0;
                        printf("Cap nhat thong tin sach thanh cong!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Khong tim thay sach voi ma %d!\n", maSach);
                }
                break;
            }
            case 6: {
                // Sap xep sach theo gia (tang/giam)
                int luaChon;
                printf("1. Sap xep tang theo gia\n");
                printf("2. Sap xep giam theo gia\n");
                printf("Nhap lua chon: ");
                scanf("%d", &luaChon);
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if ((luaChon == 1 && atof(dsSach[i].giaSach) > atof(dsSach[j].giaSach)) || 
                            (luaChon == 2 && atof(dsSach[i].giaSach) < atof(dsSach[j].giaSach))) {
                            struct Sach temp = dsSach[i];
                            dsSach[i] = dsSach[j];
                            dsSach[j] = temp;
                        }
                    }
                }
                printf("Sap xep thanh cong!\n");
                // In danh sach sau khi sap xep
                printf("\nDanh sach sach sau khi sap xep:\n");
                for (int i = 0; i < n; i++) {
                    printf("Ma sach: %d, Ten sach: %s, Gia sach: %s\n", dsSach[i].maSach, dsSach[i].tenSach, dsSach[i].giaSach);
                }
                break;
            }
            case 7: {
                // Tim kiem sach theo ten sach
                char tenSach[100];
                getchar();
                printf("Nhap ten sach can tim: ");
                fgets(tenSach, 100, stdin);
                tenSach[strcspn(tenSach, "\n")] = 0; // Loai bo ky tu newline

                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (strstr(dsSach[i].tenSach, tenSach) != NULL) {
                        printf("Ma sach: %d, Ten sach: %s, Gia sach: %s\n", dsSach[i].maSach, dsSach[i].tenSach, dsSach[i].giaSach);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay sach!\n");
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 8);
    return 0;
}
