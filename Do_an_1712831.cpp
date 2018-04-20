// Do_an_1712831.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
# include <io.h> 
#include <fcntl.h> 
#include <string.h> 
#include <stdlib.h> 
#include <wchar.h> 
struct Student {
	char *MSSV;
	char *HoTen;
	char *Khoa;
	char *NgaySinh;
	char *Gmail;
	char *MTBT;
	char *Hinh;
	char **SoThich;
};
struct Student Students[256];
int docsv(FILE* fp)
{
	char *buf = new char[256];
	char *tmp;

	if (buf == NULL) {
		printf("No memory\n");
		return 1;
	}
	int i = 0;
	int j = 0;
	int flag = 0;
	while (fgets(buf, 255, fp) != NULL)
	{
		if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n'))
			buf[strlen(buf) - 1] = '\0';

		tmp = strtok(NULL, ",");
		Students[i].MSSV = tmp;

		tmp = strtok(NULL, ",");
		Students[i].HoTen = tmp;

		tmp = strtok(NULL, ",");
		Students[i].Khoa = tmp;

		tmp = strtok(NULL, ",");
		Students[i].Gmail = tmp;

		tmp = strtok(NULL, ",");
		Students[i].NgaySinh = tmp;

		tmp = strtok(NULL, ",");
		Students[i].Hinh = tmp;

		tmp = strtok(NULL, ",");
		Students[i].MTBT = tmp;

		tmp = strtok(NULL, ",");
		for (j; strcpy(tmp, '\0') != 0; j++)
		{
			Students[i].SoThich[j] = tmp;
		}
		i++;
	}
	return 0;
}
int demsv(FILE* fp)
{
	int dem = 0;
	while (feof(fp) == NULL) {
		char a = fgetc(fp);
		if (a == '\n')
			dem++;
	}
	return dem;
}
Student* docsv1(FILE* fp, int &n)
{
	n = demsv(fp);
	fseek(fp, 0, 0);
	Student* a = (Student*)malloc(n * sizeof(Student));
	for (int i = 0; i < n; i++)
	{
		docsv(fp);
	}
	fclose(fp);
	return  a;
}
void ghi_html(FILE* fo, Student x)
{
	fwprintf(fo, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");

	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");

	fwprintf(fo, L"<head>\n");

	fwprintf(fo, L"<meta http-equiv=\"Content - Type\" content=\"text / html; charset = utf - 8\" />\n");

	fwprintf(fo, L"<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");

	fwprintf(fo, L"<title>HCMUS - ");

	fwprintf(fo, x.H);//

	fwprintf(fo, L"</title>\n");

	fwprintf(fo, L"</head>\n");

	fwprintf(fo, L"<body>\n");

	fwprintf(fo, L"<div class=\"Layout_container\">\n");

	fwprintf(fo, L"<!-- Begin Layout Banner Region -->\n");

	fwprintf(fo, L"<div class=\"Layout_Banner\" >\n");

	fwprintf(fo, L"<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");

	fwprintf(fo, L"<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<!-- End Layout Banner Region -->\n");

	fwprintf(fo, L"<!-- Begin Layout MainContents Region -->\n");

	fwprintf(fo, L"<div class=\"Layout_MainContents\">\n");

	fwprintf(fo, L"<!-- Begin Below Banner Region -->\n");

	fwprintf(fo, L"<div class=\"Personal_Main_Information\">\n");

	fwprintf(fo, L"<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");

	fwprintf(fo, L"<div class=\"Personal_Location\">\n");

	fwprintf(fo, L"<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");

	fwprintf(fo, L"<span class=\"Personal_FullName\">");

	fwprintf(fo, x.HOVATEN);//

	fwprintf(fo, L" - ");

	fwprintf(fo, x.MSSV);//

	fwprintf(fo, L"</span>\n");

	fwprintf(fo, L"<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");

	fwprintf(fo, L"<br />\n");

	fwprintf(fo, L"<div class=\"Personal_Phone\">\n");

	fwprintf(fo, L"Email: ");

	fwprintf(fo, x.MSSV);

	fwprintf(fo, L"@student.edu.vn ");

	fwprintf(fo, L"\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<br />\n");

	fwprintf(fo, L"<br /> \n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");

	fwprintf(fo, L"<div class=\"Personal_HinhcanhanKhung\">\n");

	fwprintf(fo, L"<img src=\"Images/");

	fwprintf(fo, x.hinh);//

	fwprintf(fo, L"\" class=\"Personal_Hinhcanhan\" />\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<!-- End Below Banner Region -->\n");

	fwprintf(fo, L"<!-- Begin MainContents Region -->\n");

	fwprintf(fo, L"<div class=\"MainContain\">\n");

	fwprintf(fo, L"<!-- Begin Top Region -->\n");

	fwprintf(fo, L"<div class=\"MainContain_Top\">\n");

	fwprintf(fo, L"<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");

	fwprintf(fo, L"<div>\n");

	fwprintf(fo, L"<ul class=\"TextInList\">\n");

	fwprintf(fo, L"<li>Họ và tên: ");

	fwprintf(fo, x.HOVATEN);//

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"<li>MSSV: ");

	fwprintf(fo, x.MSSV);//

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"<li>Sinh viên khoa ");

	fwprintf(fo, x.khoa);//

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"<li>Ngày sinh: ");

	fwprintf(fo, x.ngaysinh);//

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"<li>Email: ");

	fwprintf(fo, x.MSSV);

	fwprintf(fo, L"@student.edu.vn ");

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"</ul>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<div class=\"InfoGroup\">Sở thích</div>\n");

	fwprintf(fo, L"<div>\n");

	fwprintf(fo, L"<ul class=\"TextInList\">\n");

	fwprintf(fo, L"<li>");

	fwprintf(fo, x.sothich1);//

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"<li>");

	fwprintf(fo, x.sothich2);//

	fwprintf(fo, L"</li>\n");

	fwprintf(fo, L"</ul>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<div class=\"InfoGroup\">Mô tả</div>\n");

	fwprintf(fo, L"<div class=\"Description\">\n");

	fwprintf(fo, x.mota);//

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<!-- Begin Layout Footer -->\n");

	fwprintf(fo, L"<div class=\"Layout_Footer\">\n");

	fwprintf(fo, L"<div class=\"divCopyright\">\n");

	fwprintf(fo, L"<br />\n");

	fwprintf(fo, L"<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");

	fwprintf(fo, L"<br />\n");

	fwprintf(fo, L"@2013</br>\n");

	fwprintf(fo, L"Đồ án giữ kỳ</br>\n");

	fwprintf(fo, L"Kỹ thuật lập trình</br>\n");

	fwprintf(fo, L"TH2012/03</br>\n");

	fwprintf(fo, L"MSSV - Tên sinh viên thực hiện</br>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"<!-- End Layout Footer -->\n");

	fwprintf(fo, L"</div>\n");

	fwprintf(fo, L"</body>\n");

	fwprintf(fo, L"</html>\n");

	fclose(fo);

}
int main()
{
	FILE *fp;
	fp = fopen("do_an_ktlt.csv", " r");
	if (fp == NULL)
		printf("Mo file csv that bai \n");
	Student *a;
	int n = demsv(fp);
	a = new Student[n];
	docsv1(fp, n);
	
	
	return 0;
}

