#include <stdio.h>

int main() {
    int age;
    char ageRating;
    int seatType;
    int dayType;
    int customerType;
    int quantity;

    float baseSeatPrice = 0.0;
    float daySurchargeRate = 0.0;
    float discountRate = 0.0;

    float priceAfterDaySurcharge;
    float subtotal;
    float discountAmount;
    float finalTotal;

    printf("Tuoi khan gia: ");
    scanf("%d", &age);

    printf("Mac phim (G/P/T): ");
    scanf(" %c", &ageRating);

    printf("Loai ghe (1-Thuong, 2-VIP, 3-Couple): ");
    scanf("%d", &seatType);

    printf("Loai ngay (1-Thuong, 2-Cuoi tuan, 3-Ngay le): ");
    scanf("%d", &dayType);

    printf("Doi tuong (1-HSSV, 2-VIP, 3-Pho thong): ");
    scanf("%d", &customerType);

    printf("So luong ve: ");
    scanf("%d", &quantity);

    if (quantity < 1 || quantity > 10) {
        printf("Loi: So luong ve phai tu 1 den 10 ve.\n");
        return 0;
    }

    if (age < 0) {
        printf("Loi: Tuoi khong hop le.\n");
        return 0;
    }

    if (ageRating == 'T' || ageRating == 't') {
        if (age < 18) {
            printf("TU CHOI BAN VE: Khán gi? chua d? 18 tu?i cho phim mác T18.\n");
            return 0;
        }
    } else if (ageRating == 'P' || ageRating == 'p') {
        if (age < 13) {
            printf("TU CHOI BAN VE: Khán gi? chua d? 13 tu?i cho phim mác P13.\n");
            return 0;
        }
    } else if (ageRating == 'G' || ageRating == 'g') {

    } else {
        printf("Loi: Mac phan loai phim khong hop le.\n");
        return 0;
    }

    switch (seatType) {
        case 1:
            baseSeatPrice = 80000.0;
            break;

        case 2:
            baseSeatPrice = 95000.0;
            break;

        case 3:
            baseSeatPrice = 120000.0;
            break;

        default:
            printf("Loi: Ma loai ghe khong hop le.\n");
            return 0;
    }

    switch (dayType) {
        case 1:
            daySurchargeRate = 0.00;
            break;

        case 2:
            daySurchargeRate = 0.20;
            break;

        case 3:
            daySurchargeRate = 0.40;
            break;

        default:
            printf("Loi: Ma loai ngay chieu khong hop le.\n");
            return 0;
    }

    if (customerType == 1) {
        if (age >= 6 && age <= 22 && dayType == 1) {
            discountRate = 0.20;
        } else {
            discountRate = 0.00;

            printf("Canh bao: Uu dai HSSV chi ap dung ngay thuong "
                   "cho do tuoi 6-22 (Khong ap dung cho giao dich nay).\n");
        }
    } else if (customerType == 2) {
        discountRate = 0.15;
    } else if (customerType == 3) {
        discountRate = 0.00;
    } else {
        printf("Loi: Ma doi tuong uu dai khong hop le.\n");
        return 0;
    }

    priceAfterDaySurcharge =
        baseSeatPrice * (1.0 + daySurchargeRate);

    subtotal = priceAfterDaySurcharge * quantity;

    discountAmount = subtotal * discountRate;

    finalTotal = subtotal - discountAmount;

    printf("\n==================================================\n");
    printf("              HOA DON DAT VE CINEMA\n");
    printf("==================================================\n");

    if (ageRating == 'T' || ageRating == 't') {
        printf("Mac phim dang ky : T (Phim 18+)\n");
    } else if (ageRating == 'P' || ageRating == 'p') {
        printf("Mac phim dang ky : P (Phim 13+)\n");
    } else {
        printf("Mac phim dang ky : G (Moi lua tuoi)\n");
    }

    printf("Khan gia : %d tuoi -> DU DIEU KIEN\n", age);

    printf("Don gia ghe goc : %.0f VNÐ / ve\n",
           baseSeatPrice);

    printf("Ty le phu thu ngay : %.0f%%\n",
           daySurchargeRate * 100);

    printf("Gia 1 ve sau phu thu : %.0f VNÐ / ve\n",
           priceAfterDaySurcharge);

    printf("So luong dat mua : %d ve\n", quantity);

    printf("--------------------------------------------------\n");

    printf("Tong tien niem yet : %.0f VNÐ\n",
           subtotal);

    printf("So tien giam gia : %.0f VNÐ (Uu dai %.0f%%)\n",
           discountAmount,
           discountRate * 100);

    printf("--------------------------------------------------\n");

    printf("TONG THANH TIEN : %.0f VNÐ\n",
           finalTotal);

    printf("==================================================\n");

    return 0;
}
