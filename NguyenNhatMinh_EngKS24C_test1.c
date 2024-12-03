#include <stdio.h>
int main(){
    int mang[100];
    int soPhanTu = 0;
    int nguoiDungNhap;
    int check = 0;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to cua mang\n");
        printf("5. Them phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri cua no\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &nguoiDungNhap);
        switch (nguoiDungNhap){
        case 1: //Nhap so phan tu can nhap va gia tri cac phan tu
            check = 1;
            printf("nhap so phan tu co trong man(1-100): ");
            scanf("%d", &soPhanTu);
            if(soPhanTu < 0 || soPhanTu > 100){
                printf("so phan tu mang khong hop le");
                break;
            }
            for(int i = 0; i < soPhanTu; i++){
                printf("mang[%d]= ", i);
                scanf("%d", &mang[i]);
            }
            break;
        
        case 2: //In ra gia tri cac phan tu dang quan ly
            if(check == 0){
                printf("chua nhap mang");
                break;
            }
            for(int i = 0; i < soPhanTu; i++){
                printf("mang[%d]= %d\n", i, mang[i]);
            }
            break;
        
        case 3: //In ra gia tri lon nhat cua mang
            if(check == 0){
                printf("chua nhap mang");
                break;
            }
            int max = mang[0];
            for(int i = 0; i < soPhanTu; i++){
                if(max < mang[i]){
                    max = mang[i];
                }
            }
            printf("gia tri lon nhat cua mang la: %d", max);
            break;
        
        case 4: //In ra cac phan tu la so nguyen to cua mang
            if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
            int coSoNguyenTo = 0;
            printf("so nguyen to trong mang la: ");
            for (int i = 0; i < soPhanTu; i++){
                int checkSoNguyenTo = 1;
                if(mang[i] < 2){
                    checkSoNguyenTo = 0;
                } else {
                    for(int j = 2; j * j <= mang[i]; j++){
                        if(mang[i] % j == 0){
                            checkSoNguyenTo = 0;
                            break;
                        } 
                    }
                }
                
                if (checkSoNguyenTo == 1){
                    printf("%d ", mang[i]);
                    coSoNguyenTo = 1;
                }
            }
            if (coSoNguyenTo == 0){
                printf("\nkhong co so nguyen to");
            }
            break;
        
        case 5: // Them phan tu vao trong mang
            if(check == 0){
                    printf("chua nhap mang");
                    break;
            }
            int viTriThem, phanTuThem;
            printf("vi tri them phan tu la: ");
            scanf("%d", &viTriThem);
            if(viTriThem < 0 || viTriThem > soPhanTu){
                printf("vi tri them khong hop le");
                break;
            }
            printf("hay nhap gia tri muon them: ");
            scanf("%d", &phanTuThem);
            for(int i = soPhanTu; i >= viTriThem ; i--){
                mang[i + 1] = mang[i];
            }
            soPhanTu++;
            mang[viTriThem] = phanTuThem;
            break;
            
        case 6: //Xoa mot phan tu trong mang
            if(check == 0){
                    printf("chua nhap mang");
                    break;
            }
            int viTriXoa;
            printf("nhap vi tri can xoa: ");
            scanf("%d", &viTriXoa);
            if(viTriXoa < 0 || viTriXoa >= soPhanTu){
                printf("vi tri xoa sai");
                break;
            }
            for(int i = viTriXoa; i < soPhanTu; i++){
                mang[i] = mang[i+1];
            }
            soPhanTu--;
            break;

        case 7: //Sap xep mang theo thu tu tang dan
            if(check == 0){
                    printf("chua nhap mang");
                    break;
            }
            int bienNho;
            for(int i  = 0; i < soPhanTu; i++){
                for(int j = 0; j < soPhanTu - 1 - i; j++){
                    if(mang[j] > mang[j + 1]){
                        bienNho = mang[j];
                        mang[j] = mang[j + 1];
                        mang[j + 1] = bienNho;
                    }
                }
            }
            printf("da sap xep");
            break;
        
        case 8: //Tim kiem phan tu va in ra vi tri cua no
            if(check == 0){
                    printf("chua nhap mang");
                    break;
            }
			int phanTuTim;
            int timThay = 0;
            printf("nhap phan tu de tim kiem: ");
            scanf("%d", &phanTuTim);
            printf("Vi tri phan tu o: ");
            for(int i = 0; i < soPhanTu; i++){
                if(phanTuTim == mang[i]){
                    printf("%d", mang[i]);
                    timThay = 1;
                }
            }
            if(timThay == 0){
                printf("khong tim thay phan tu do");
            }
        case 9: //thoat
            return 0;
        default:
            printf("nhap sai lua chon, vui long nhap lai");
        }

    }
    
    return 0;
}