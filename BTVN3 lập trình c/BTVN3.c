#include <stdio.h>

int main() {
    int tuoi;
    int mac_phim;
    int suat_chieu;
    int loai_ghe;
    int la_ngay_thuong;
    int doi_tuong;

    float gia_ve_goc = 0.0;
    float phu_thu_ghe = 0.0;
    float tien_giam = 0.0;
    float tong_tien = 0.0;

    printf("=== HE THONG QUAN LY BAN VE CGV CINEMA ===\n");

    printf("Nhap tuoi cua khach hang: ");
    scanf("%d", &tuoi);

    if (tuoi < 0 || tuoi > 120) {
        printf("Loi: So tuoi nhap vao khong hop le!\n");
        return 0;
    }

    printf("Nhap mac phim (1: P, 2: T16, 3: T18): ");
    scanf("%d", &mac_phim);

    if (mac_phim != 1 && mac_phim != 2 && mac_phim != 3) {
        printf("Loi: Ma phan loai phim khong hop le!\n");
        return 0;
    }

    if (mac_phim == 2 && tuoi < 16) {
        printf("Tu choi ban ve: Phim T16 yeu cau khan gia tu 16 tuoi tro len!\n");
        return 0;
    }

    if (mac_phim == 3 && tuoi < 18) {
        printf("Tu choi ban ve: Phim T18 cam khan gia duoi 18 tuoi!\n");
        return 0;
    }

    printf("Nhap suat chieu (1: Sang, 2: Chieu, 3: Toi): ");
    scanf("%d", &suat_chieu);

    switch (suat_chieu) {
        case 1:
            gia_ve_goc = 70000.0;
            break;

        case 2:
            gia_ve_goc = 90000.0;
            break;

        case 3:
            gia_ve_goc = 120000.0;
            break;

        default:
            printf("Loi: Lua chon suat chieu khong nam trong menu!\n");
            return 0;
    }

    printf("Nhap loai ghe (1: Thuong, 2: VIP, 3: Couple): ");
    scanf("%d", &loai_ghe);

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

        default:
            printf("Loi: Loai ghe khong hop le!\n");
            return 0;
    }

    printf("Co phai ngay thuong khong? (1: Co, 0: Khong): ");
    scanf("%d", &la_ngay_thuong);

    printf("Nhap doi tuong (1: HSSV, 2: Nguoi cao tuoi, 3: Thuong): ");
    scanf("%d", &doi_tuong);

    if (la_ngay_thuong == 1) {
        if (doi_tuong == 1) {
            tien_giam = gia_ve_goc * 0.20;
        } else if (doi_tuong == 2 || tuoi >= 60) {
            tien_giam = gia_ve_goc * 0.30;
        } else if (doi_tuong == 3) {
            tien_giam = 0.0;
        }
    } else {
        tien_giam = 0.0;
    }

    tong_tien = (gia_ve_goc - tien_giam) + phu_thu_ghe;

    printf("\n--------------------------------------------------\n");
    printf("             HOA DON THANH TOAN VE PHIM\n");
    printf("--------------------------------------------------\n");

    if (mac_phim == 1) {
        printf("Khan gia : %d tuoi (Du dieu kien xem phim P)\n", tuoi);
    } else if (mac_phim == 2) {
        printf("Khan gia : %d tuoi (Du dieu kien xem phim T16)\n", tuoi);
    } else {
        printf("Khan gia : %d tuoi (Du dieu kien xem phim T18)\n", tuoi);
    }

    if (suat_chieu == 1) {
        printf("Suat chieu : Suat Sang\n");
    } else if (suat_chieu == 2) {
        printf("Suat chieu : Suat Chieu\n");
    } else {
        printf("Suat chieu : Suat Toi / Blockbuster\n");
    }

    if (loai_ghe == 1) {
        printf("Loai ghe : Ghe Thuong\n");
    } else if (loai_ghe == 2) {
        printf("Loai ghe : Ghe VIP\n");
    } else {
        printf("Loai ghe : Ghe Couple\n");
    }

    printf("--------------------------------------------------\n");
    printf("Gia ve goc : %.0f VNÐ\n", gia_ve_goc);

    if (tien_giam > 0) {
        if (doi_tuong == 1) {
            printf("Giam gia (20%%) : -%.0f VNÐ\n", tien_giam);
        } else {
            printf("Giam gia (30%%) : -%.0f VNÐ\n", tien_giam);
        }
    } else {
        printf("Giam gia : 0 VNÐ\n");
    }

    if (loai_ghe == 1) {
        printf("Phu thu ghe Thuong : +%.0f VNÐ\n", phu_thu_ghe);
    } else if (loai_ghe == 2) {
        printf("Phu thu ghe VIP : +%.0f VNÐ\n", phu_thu_ghe);
    } else {
        printf("Phu thu ghe Couple : +%.0f VNÐ\n", phu_thu_ghe);
    }

    printf("--------------------------------------------------\n");
    printf("TONG TIEN THANH TOAN: %.0f VNÐ\n", tong_tien);
    printf("--------------------------------------------------\n");

    return 0;
}
