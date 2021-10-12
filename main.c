#include <stdio.h>
#include<string.h>
typedef struct {
     char hoten[35], khoa[10];
     int sbd;
     float diemthi;
} sinhvien;
int main() {
   FILE * f = fopen("D:\\Code\\Thisinh.dat", "wb");
   int i=1;
   sinhvien t;
   while(1) {
    printf("Nhap du lieu thi sinh thu %d:\n", i++);
    printf(" Nhap ten: ");fflush(stdin); fgets(t.hoten,35,stdin);
    t.hoten[strlen(t.hoten)-1]='\0'; // bỏ kí tự xuống dòng khi nhập ^_^
    if(strcmp(t.hoten,"***")==0) break;
    printf(" Nhap SBD: "); scanf("%d", &t.sbd); fflush(stdin);
    printf(" Nhap khoa thi: "); fgets(t.khoa,10,stdin);
    t.khoa[strlen(t.khoa)-1] = '\0'; // bỏ kí tự xuống dòng khi nhập ^_^
    printf(" Nhap diem thi: "); scanf("%f", &t.diemthi); fflush(stdin);
    fprintf(f,"%-s %-d %-s %-f\n", t.hoten, t.sbd, t.khoa, t.diemthi);
//    fwrite(&t, sizeof(sinhvien), 1, f);
   }
   fclose(f);
  f = fopen("D:\\Code\\Thisinh.dat", "rb");
   i=1;
   while(fread(&t,sizeof(sinhvien), 1,f) > 0) {
    printf("%-d %-d %-s %f ", i++, t.sbd, t.hoten, t.diemthi);
   }
   return 0;

}
