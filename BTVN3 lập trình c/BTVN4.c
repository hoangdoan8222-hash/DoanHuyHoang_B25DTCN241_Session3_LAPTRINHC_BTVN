#include <stdio.h>

int main() {
    int lua_chon;

    printf("=== HE THONG QUAN LY RAP PHIM CGV / LOTTE ===\n");
    printf("1. Dat ve xem phim & Xuat kho ve\n");
    printf("2. Quan ly ton kho Combo Bap Nuoc\n");
    printf("3. Tra cuu bang gia va chinh sach\n");

    printf("Lua chon cua ban (1-3): ");
    scanf("%d", &lua_chon);

    switch (lua_chon) {

        case 1: {
            int ma_phim_18;
            int do_tuoi;
            int loai_ghe;
            int doi_tuong;
            int ngay_chieu;
            float gia_ve_chuan;

            float phu_thu_ghe = 0.0;
            float phu_thu_cuoi_tuan = 0.0;
            float giam_gia = 0.0;
            float tong_tien;

            printf("\n--- CHUC NANG 1: DAT VE PHIM ---\n");

            printf("Phim co mac C18 khong? (1: Co, 0: Khong): ");
            scanf("%d", &ma_phim_18);

            printf("Nhap do tuoi khach hang: ");
            scanf("%d", &do_tuoi);

            if (do_tuoi <= 0) {
                printf("LOI: Do tuoi phai lon hon 0!\n");
                break;
            }

            printf("Nhap loai ghe (1: Thuong, 2: VIP, 3: Couple): ");
            scanf("%d", &loai_ghe);

            if (loai_ghe != 1 && loai_ghe != 2 && loai_ghe != 3) {
                printf("LOI: Loai ghe khong hop le!\n");
                break;
            }

            printf("Nhap doi tuong (1: HS/SV, 2: Khac): ");
            scanf("%d", &doi_tuong);

            if (doi_tuong != 1 && doi_tuong != 2) {
                printf("LOI: Doi tuong khong hop le!\n");
                break;
            }

            printf("Nhap ngay chieu (1: Ngay thuong, 2: Cuoi tuan): ");
            scanf("%d", &ngay_chieu);

            if (ngay_chieu != 1 && ngay_chieu != 2) {
                printf("LOI: Ngay chieu khong hop le!\n");
                break;
            }

            printf("Nhap gia ve chuan (VND): ");
            scanf("%f", &gia_ve_chuan);

            if (gia_ve_chuan <= 0) {
                printf("LOI: Gia ve chuan phai lon hon 0!\n");
                break;
            }

            printf("\n=== KET QUA XU LY VE ===\n");

            if (ma_phim_18 == 1 && do_tuoi < 18) {
                printf("TUYET DOI CAM: Khach hang chua du 18 tuoi de xem phim mac 18+! Xuat kho ve THAT BAI.\n");
                break;
            }

            switch (loai_ghe) {
                case 1:
                    phu_thu_ghe = 0.0;
                    break;

                case 2:
                    phu_thu_ghe = 15000.0;
                    break;

                case 3:
                    phu_thu_ghe = 30000.0;
                    break;
            }

            if (ngay_chieu == 2) {
                phu_thu_cuoi_tuan = gia_ve_chuan * 0.10;
            } else {
                phu_thu_cuoi_tuan = 0.0;
            }

            if (doi_tuong == 1 && ngay_chieu == 1) {
                giam_gia = gia_ve_chuan * 0.20;
            } else {
                giam_gia = 0.0;
            }

            tong_tien = (gia_ve_chuan - giam_gia)
                        + phu_thu_ghe
                        + phu_thu_cuoi_tuan;

            printf("\n=== HOA DON XUAT VE CGV / LOTTE ===\n");
            printf("- Do tuoi khach hang: %d (Hop le)\n", do_tuoi);
            printf("- Gia ve chuan: %.1f VND\n", gia_ve_chuan);

            if (loai_ghe == 1) {
                printf("- Phu thu ghe Thuong: %.1f VND\n", phu_thu_ghe);
            } else if (loai_ghe == 2) {
                printf("- Phu thu ghe VIP: %.1f VND\n", phu_thu_ghe);
            } else {
                printf("- Phu thu ghe Couple: %.1f VND\n", phu_thu_ghe);
            }

            printf("- Phu thu cuoi tuan: %.1f VND\n",
                   phu_thu_cuoi_tuan);

            if (doi_tuong == 1 && ngay_chieu == 1) {
                printf("- Giam gia HS/SV (20%%): %.1f VND\n", giam_gia);
            } else {
                printf("- Giam gia HS/SV (20%%): 0.0 VND\n");
            }

            printf("-----------------------------------\n");
            printf("TONG TIEN THANH TOAN: %.1f VND\n", tong_tien);
            printf("XUAT KHO VE THANH CONG!\n");

            break;
        }

        case 2: {
            int ma_combo;
            int so_luong_kho;
            int so_luong_yieu_cau;
            int so_luong_con_lai;

            float ty_le_con_lai;

            printf("\n--- CHUC NANG 2: QUAN LY KHO BAP NUOC ---\n");

            printf("Nhap ma Combo (1: Single, 2: Couple, 3: Ultimate): ");
            scanf("%d", &ma_combo);

            if (ma_combo != 1 && ma_combo != 2 && ma_combo != 3) {
                printf("LOI: Ma Combo khong hop le!\n");
                break;
            }

            printf("Nhap so luong ton kho hien tai: ");
            scanf("%d", &so_luong_kho);

            if (so_luong_kho < 0) {
                printf("LOI: So luong kho phai >= 0!\n");
                break;
            }

            printf("Nhap so luong khach mua: ");
            scanf("%d", &so_luong_yieu_cau);

            if (so_luong_yieu_cau <= 0) {
                printf("LOI: So luong mua phai > 0!\n");
                break;
            }

            if (so_luong_yieu_cau > so_luong_kho) {
                printf("LOI: Ton kho khong du cung ung! "
                       "(Ton: %d, Yeu cau: %d)\n",
                       so_luong_kho,
                       so_luong_yieu_cau);
                break;
            }

            so_luong_con_lai =
                so_luong_kho - so_luong_yieu_cau;

            if (so_luong_kho == 0) {
                printf("LOI: Khong the tinh ty le voi kho bang 0!\n");
                break;
            }

            ty_le_con_lai =
                ((float)so_luong_con_lai / so_luong_kho) * 100.0;

            printf("\n=== BAO CAO XUAT KHO CONCESSION ===\n");

            if (ma_combo == 1) {
                printf("- Combo da chon: Combo Single (Ma 1)\n");
            } else if (ma_combo == 2) {
                printf("- Combo da chon: Combo Couple (Ma 2)\n");
            } else {
                printf("- Combo da chon: Combo Ultimate (Ma 3)\n");
            }

            printf("- So luong xuat kho: %d phan\n",
                   so_luong_yieu_cau);

            printf("- So luong con lai trong kho: %d phan\n",
                   so_luong_con_lai);

            printf("- Ty le ton kho con lai: %.2f%%\n",
                   ty_le_con_lai);

            if (ty_le_con_lai < 10.0) {
                printf("- TRANG THAI KHO: "
                       "MUC DONG NGUY HIEM - CAN NHAP KHO GAP\n");
            } else if (ty_le_con_lai <= 30.0) {
                printf("- TRANG THAI KHO: "
                       "CANH BAO TONG KHO THAP\n");
            } else {
                printf("- TRANG THAI KHO: TON KHO AN TOAN\n");
            }

            break;
        }

        case 3:
            printf("\n=== BANG GIA & QUY DINH CGV / LOTTE ===\n");
            printf("-----------------------------------------------\n");
            printf("Ghe Thuong : Phu thu 0 VND\n");
            printf("Ghe VIP    : Phu thu 15,000 VND\n");
            printf("Ghe Couple : Phu thu 30,000 VND\n");
            printf("Cuoi tuan  : Phu thu 10%% gia ve chuan\n");
            printf("HS/SV      : Giam 20%% ngay thuong\n");
            printf("C18        : Khong ban cho khach duoi 18 tuoi\n");
            printf("-----------------------------------------------\n");
            break;

        default:
            printf("Loi: Luachon menu khong hop le! "
                   "Vui long chay lai va chon tu 1 den 3.\n");
            break;
    }

    return 0;
}
