#include <stdio.h>
#include <string.h>
struct SanPham {
    int maSP;
    char tenSP[100];
    char giaNhap[20];  
    char giaBan[20];  
    int soLuong;
};
struct SanPham dsSP[100];
int n = 0;  // So luong san pham hien tai
char doanhThu[20] = "0";  // Bien luu doanh thu hien tai duoi dang chuoi
int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch(luaChon) {
            case 1:
                printf("Nhap so luong san pham: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap thong tin san pham %d:\n", i + 1);
                    printf("Ma san pham: ");
                    scanf("%d", &dsSP[i].maSP);
                    getchar(); 
                    printf("Ten san pham: ");
                    fgets(dsSP[i].tenSP, 100, stdin);
                    dsSP[i].tenSP[strcspn(dsSP[i].tenSP, "\n")] = 0;
                    printf("Gia nhap: ");
                    fgets(dsSP[i].giaNhap, 20, stdin);
                    printf("Gia ban: ");
                    fgets(dsSP[i].giaBan, 20, stdin);
                    printf("So luong: ");
                    scanf("%d", &dsSP[i].soLuong);
                    // Tinh doanh thu giam khi nhap san pham
                    int giaNhap = 0;
                    for (int j = 0; dsSP[i].giaNhap[j] != '\0'; j++) {
                        if (dsSP[i].giaNhap[j] >= '0' && dsSP[i].giaNhap[j] <= '9') {
                            giaNhap = giaNhap * 10 + (dsSP[i].giaNhap[j] - '0');
                        }
                    }
                    int doanhThuHienTai = 0;
                    for (int j = 0; doanhThu[j] != '\0'; j++) {
                        if (doanhThu[j] >= '0' && doanhThu[j] <= '9') {
                            doanhThuHienTai = doanhThuHienTai * 10 + (doanhThu[j] - '0');
                        }
                    }
                    snprintf(doanhThu, sizeof(doanhThu), "%d", doanhThuHienTai - dsSP[i].soLuong * giaNhap);
                }
                break;
            case 2:
                printf("\nDanh sach san pham:\n");
                for (int i = 0; i < n; i++) {
                    printf("Ma san pham: %d, Ten san pham: %s, Gia nhap: %s, Gia ban: %s, So luong: %d\n", 
                        dsSP[i].maSP, dsSP[i].tenSP, dsSP[i].giaNhap, dsSP[i].giaBan, dsSP[i].soLuong);
                }
                break;
            case 3:
                {
                    int maSP;
                    printf("Nhap ma san pham can nhap: ");
                    scanf("%d", &maSP);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (dsSP[i].maSP == maSP) {
                            printf("San pham %s da ton tai, tang so luong.\n", dsSP[i].tenSP);
                            printf("Nhap so luong can nhap: ");
                            int soLuongNhap;
                            scanf("%d", &soLuongNhap);
                            dsSP[i].soLuong += soLuongNhap;
                            // Giam doanh thu khi nhap hang
                            int giaNhap = 0;
                            for (int j = 0; dsSP[i].giaNhap[j] != '\0'; j++) {
                                if (dsSP[i].giaNhap[j] >= '0' && dsSP[i].giaNhap[j] <= '9') {
                                    giaNhap = giaNhap * 10 + (dsSP[i].giaNhap[j] - '0');
                                }
                            }
                            int doanhThuHienTai = 0;
                            for (int j = 0; doanhThu[j] != '\0'; j++) {
                                if (doanhThu[j] >= '0' && doanhThu[j] <= '9') {
                                    doanhThuHienTai = doanhThuHienTai * 10 + (doanhThu[j] - '0');
                                }
                            }
                            snprintf(doanhThu, sizeof(doanhThu), "%d", doanhThuHienTai - soLuongNhap * giaNhap);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        if (n < 100) {
                            printf("Nhap thong tin san pham moi:\n");
                            dsSP[n].maSP = maSP;
                            getchar();  // De bo qua ky tu newline con lai trong bo dem
                            printf("Ten san pham: ");
                            fgets(dsSP[n].tenSP, 100, stdin);
                            dsSP[n].tenSP[strcspn(dsSP[n].tenSP, "\n")] = 0;
                            printf("Gia nhap: ");
                            fgets(dsSP[n].giaNhap, 20, stdin);
                            printf("Gia ban: ");
                            fgets(dsSP[n].giaBan, 20, stdin);
                            printf("So luong: ");
                            scanf("%d", &dsSP[n].soLuong);
                            // Giam doanh thu khi nhap hang
                            int giaNhap = 0;
                            for (int j = 0; dsSP[n].giaNhap[j] != '\0'; j++) {
                                if (dsSP[n].giaNhap[j] >= '0' && dsSP[n].giaNhap[j] <= '9') {
                                    giaNhap = giaNhap * 10 + (dsSP[n].giaNhap[j] - '0');
                                }
                            }
                            int doanhThuHienTai = 0;
                            for (int j = 0; doanhThu[j] != '\0'; j++) {
                                if (doanhThu[j] >= '0' && doanhThu[j] <= '9') {
                                    doanhThuHienTai = doanhThuHienTai * 10 + (doanhThu[j] - '0');
                                }
                            }
                            snprintf(doanhThu, sizeof(doanhThu), "%d", doanhThuHienTai - dsSP[n].soLuong * giaNhap);
                            n++; // Tang so luong san pham
                        } else {
                            printf("Danh sach san pham da day!\n");
                        }
                    }
                }
                break;
            case 4:
                {
                    int maSP;
                    printf("Nhap ma san pham can cap nhat: ");
                    scanf("%d", &maSP);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (dsSP[i].maSP == maSP) {
                            printf("Nhap thong tin moi cho san pham %s:\n", dsSP[i].tenSP);
                            printf("Ten san pham: ");
                            getchar();  // De bo qua ky tu newline con lai trong bo dem
                            fgets(dsSP[i].tenSP, 100, stdin);
                            dsSP[i].tenSP[strcspn(dsSP[i].tenSP, "\n")] = 0;
                            printf("Gia nhap: ");
                            fgets(dsSP[i].giaNhap, 20, stdin);
                            printf("Gia ban: ");
                            fgets(dsSP[i].giaBan, 20, stdin);
                            printf("So luong: ");
                            scanf("%d", &dsSP[i].soLuong);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("San pham voi ma %d khong ton tai!\n", maSP);
                    }
                }
                break;
            case 5:
                {
                    int luaChonSapXep;
                    printf("Chon sap xep theo gia (1: tang, 2: giam): ");
                    scanf("%d", &luaChonSapXep);
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            int giaI = 0, giaJ = 0;
                            for (int k = 0; dsSP[i].giaBan[k] != '\0'; k++) {
                                if (dsSP[i].giaBan[k] >= '0' && dsSP[i].giaBan[k] <= '9') {
                                    giaI = giaI * 10 + (dsSP[i].giaBan[k] - '0');
                                }
                            }
                            for (int k = 0; dsSP[j].giaBan[k] != '\0'; k++) {
                                if (dsSP[j].giaBan[k] >= '0' && dsSP[j].giaBan[k] <= '9') {
                                    giaJ = giaJ * 10 + (dsSP[j].giaBan[k] - '0');
                                }
                            }
                            if (luaChonSapXep == 1 && giaI > giaJ) {
                                struct SanPham temp = dsSP[i];
                                dsSP[i] = dsSP[j];
                                dsSP[j] = temp;
                            } else if (luaChonSapXep == 2 && giaI < giaJ) {
                                struct SanPham temp = dsSP[i];
                                dsSP[i] = dsSP[j];
                                dsSP[j] = temp;
                            }
                        }
                    }
                    printf("Danh sach san pham sau khi sap xep:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Ma SP: %d, Ten SP: %s, Gia Ban: %s, So Luong: %d\n", 
                                dsSP[i].maSP, dsSP[i].tenSP, dsSP[i].giaBan, dsSP[i].soLuong);
                    }
                }
                break;
            case 6:
                {
                    char tenSanPham[100];
                    getchar(); // Bo qua ky tu newline con lai
                    printf("Nhap ten san pham can tim: ");
                    fgets(tenSanPham, 100, stdin);
                    tenSanPham[strcspn(tenSanPham, "\n")] = 0;
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (strstr(dsSP[i].tenSP, tenSanPham) != NULL) {
                            printf("San pham tim thay: Ma SP: %d, Ten SP: %s, Gia Ban: %s, So Luong: %d\n", 
                                    dsSP[i].maSP, dsSP[i].tenSP, dsSP[i].giaBan, dsSP[i].soLuong);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay san pham!\n");
                    }
                }
                break;
            case 7:{
			}
                break;
            case 8:
                printf("Doanh thu hien tai: %s\n", doanhThu);
                break;
            case 9:
                printf("Thoat!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 9);
    return 0;
}
