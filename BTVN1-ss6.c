#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50
#define PHI_PHAT_NGAY 5000

int main(void) {
    // 1. Khai bao mang va bien khoi tao
    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;

    int luachon;

    // Vong lap Menu dieu khien lien tuc
    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");

        // Nhap lua chon menu
        if (scanf("%d", &luachon) != 1) {
            // Neu nguoi dung nhap sai kieu du lieu
            printf("Loi: Lua chon khong hop le!\n");
            while (getchar() != '\n'); // Lam sach bo dem
            continue;
        }

        // Xoa ky tu xuong dong '\n' con sot trong bo dem sau khi scanf("%d")
        while (getchar() != '\n');

        switch (luachon) {
            case 1: {
                // CHUC NANG 1: XEM DANH SACH PHIEU MUON
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("%-5s | %-12s | %-18s | %-15s\n", "STT", "Ma Phieu", "So Ngay Qua Han", "Tien Phat (VND)");
                printf("------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    long long tienPhat = (long long)ngayQuaHan[i] * PHI_PHAT_NGAY;
                    printf("%-5d | %-12s | %-2d ngay            | %-lld VND\n", 
                           i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }

                printf("------------------------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }

            case 2: {
                // CHUC NANG 2: THEM MOI PHIEU MUON
                printf("\n--- THEM MOI PHIEU MUON ---\n");
                
                // Kiem tra bo nho mang
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }

                printf("Nhap ma phieu muon moi: ");
                scanf("%19s", maPhieu[soLuong]);
                while (getchar() != '\n'); // Xoa bo dem ban phim

                // Mac dinh so ngay qua han ban dau = 0
                ngayQuaHan[soLuong] = 0;
                soLuong++;

                printf("Them phieu muon thanh cong! Tong so phieu hien tai: %d\n", soLuong);
                break;
            }

            case 3: {
                // CHUC NANG 3: CAP NHAT SO NGAY QUA HAN
                printf("\n--- CAP NHAT SO NGAY QUA HAN ---\n");
                if (soLuong == 0) {
                    printf("Danh sach hien tai dang rong!\n");
                    break;
                }

                char maTimKiem[20];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maTimKiem);
                while (getchar() != '\n'); // Xoa bo dem ban phim

                // Tim kiem tuyen tinh trong mang maPhieu
                int indexTimThay = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTimKiem) == 0) {
                        indexTimThay = i;
                        break;
                    }
                }

                if (indexTimThay != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTimKiem, indexTimThay);
                    
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay qua han moi (>= 0): ");
                        if (scanf("%d", &ngayMoi) != 1) {
                            printf("Loi: Vui long nhap so nguyen!\n");
                            while (getchar() != '\n');
                            ngayMoi = -1; // Kep gia tri am de lhap lai
                            continue;
                        }
                        while (getchar() != '\n'); // Xoa bo dem ban phim

                        if (ngayMoi < 0) {
                            printf("Loi: So ngay qua han khong duoc am. Vui long nhap lai!\n");
                        }
                    } while (ngayMoi < 0);

                    // Ghi de vao mang
                    ngayQuaHan[indexTimThay] = ngayMoi;
                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", 
                           maPhieu[indexTimThay], ngayQuaHan[indexTimThay]);
                } else {
                    printf("Loi: Khong tim thay phieu muon co ma '%s'!\n", maTimKiem);
                }
                break;
            }

            case 0:
                printf("\nCam on ban da su dung HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS)!\n");
                printf("Tam biet va hen gap lai.\n");
                break;

            default:
                printf("Loi: Chuc nang khong hop le. Vui long chon tu 0 den 3!\n");
                break;
        }

    } while (luachon != 0);

    return 0;
}
