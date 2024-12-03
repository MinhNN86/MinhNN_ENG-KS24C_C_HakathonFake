#include <stdio.h>
int main(){
    int nguoiDungNhap, row, col;
    int mang[100][100];
    int check = 0;
    while(1){
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cua phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("lua chon cua ban: ");
        scanf("%d", &nguoiDungNhap);
        switch(nguoiDungNhap){
            case 1: //Nhap kich co va gia tri cua phan tu cua mang
                check = 1;
                printf("nhap so hang trong mang: ");
                scanf("%d", &row);
                if(row < 0 || row > 100){
                    printf("so hang khong hop le");
                    break;
                }
                printf("nhap so cot trong mang: ");
                scanf("%d", &col);
                if(col < 0 || col > 100){
                    printf("so cot khong hop le");
                    break;
                }
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < col; j++){
                        printf("mang2Chieu[%d][%d]= ", i, j);
                        scanf("%d", &mang[i][j]);
                    }
                }
                break;
            
            case 2: //In gia tri cac phan tu cua mang theo ma tran
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < col; j++){
                        printf("%d ", mang[i][j]);
                    }
                    printf("\n");
                }
                break;
            
            case 3: //In ra cac phan tu nam tren duong bien va tinh tich
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int tich = 1;
                printf("cac phan tu nam tren duong bien la: ");
                for (int j = 0; j < col; j++) {
                    printf("%d ", mang[0][j]);
                    tich *= mang[0][j];
                }
                for (int i = 1; i < row - 1; i++) {
                    printf("%d ", mang[i][col - 1]);
                    tich *= mang[i][col - 1];
                }
                if (row > 1) {
                    for (int j = col - 1; j >= 0; j--) {
                        printf("%d ", mang[row - 1][j]);
                        tich *= mang[row - 1][j];
                    }
                }
                if (col > 1) {
                    for (int i = row - 2; i > 0; i--) {
                        printf("%d ", mang[i][0]);
                        tich *= mang[i][0];
                    }
                }
                printf("\ntich cac phan tu nam tren duong bien la %d", tich);
                break;

            case 4: //In ra cac phan tu nam tren duong cheo chinh
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                if(row != col){
                    printf("khong phai mang vuong");
                    break;
                }
                printf("phan tu nam tren duong cheo chinh la: ");
                for(int i = 0; i < row; i++){
                    printf("%d ", mang[i][i]);
                }   
                break;  
            case 5: //In ra cac phan tu nam tren duong cheo phu
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                if(row != col){
                    printf("khong phai mang vuong");
                    break;
                }
                printf("phan tu nam tren duong cheo phu la: ");
                for(int i = 0; i < row; i--){
                    printf("%d ", mang[i][col - 1 - i]);
                }
                break;
            
            case 6: //Sap xep duong cheo chinh theo thu tu tang dan
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                if(row != col){
                    printf("khong phai mang vuong");
                    break;
                }
                int duongCheoChinh[100];
                int dem = 0;
                for(int i = 0; i < row; i++){
                    duongCheoChinh[dem] = mang[i][i];
                    dem++;
                }
                for(int i = 0; i < dem - 1; i++){
                    for(int j = 0; j < dem - 1 - i; j++){
                        if(duongCheoChinh[j] > duongCheoChinh[j + 1]){
                            int bienNho = duongCheoChinh[j];
                            duongCheoChinh[j] = duongCheoChinh[j + 1];
                            duongCheoChinh[j + 1] = bienNho;
                        }
                    }
                }
                dem = 0;
                for(int i = 0; i < row; i++){
                    mang[i][i] = duongCheoChinh[dem];
                    dem++;
                }
                printf("Duong cheo chinh theo thu tu tang dan: ");
                for(int i = 0; i < row; i++){
                    printf("%d ", mang[i][i]);
                }
                break;
            case 7: //Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int phanTuTimKiem;
                int checkTim = 0;
                printf("nhap phan tu can tim kiem: ");
                scanf("%d", &phanTuTimKiem);
                for(int i = 0; i < row; i++){
                    for(int j = 0; j < col; j++){
                        if(phanTuTimKiem == mang[i][j]){
                            checkTim = 1;
                            printf("phan tu %d tim thay o mang[%d][%d]", phanTuTimKiem, i, j);
                        }
                    }
                }
                if(checkTim == 0){
                printf("khong tim thay phan tu o mang");
                }
                break;

            case 8: //thoat
                return 0;
            default:
                printf("lua chon sai, hay chon lai");
        }
    }
    return 0;
}