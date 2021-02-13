#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{     // 学生的结构体
    char code[20];      // 学号
    char name[10];      // 姓名
    int  age;           // 年龄
    char sex;           // 性别
    char address[80];   // 地址
    char e_mail[50];    // 邮箱
    char tel[11];       // 电话
    char birth[40];     // 出生日期
}stu[200];

int n=0,m=0;// 全局变量,n代表当前学生总人数,m表示新增学生人数

void menu();        // 打印菜单
void help();        // 帮助界面
void readfile();    // 读入数据
void seek();        // 查找信息
void modify();      // 修改数据
void insert();      // 插入数据
void del();         // 删除数据
void display();     // 显示信息
void save();        // 保存信息

int main(){
    printf("\nDesigned by _Lirz_:\n\n");
    printf("\t       学生管理系统\n");
	printf("\t****************************\n");
	printf("\t*   0. 系统帮助及说明      *\n");
	printf("\t****************************\n");
	printf("\t*   1. 刷新学生信息        *\n");
	printf("\t****************************\n");
	printf("\t*   2. 查询学生信息        *\n");
	printf("\t****************************\n");
	printf("\t*   3. 修改学生信息        *\n");
	printf("\t****************************\n");
	printf("\t*   4. 增加学生信息        *\n");
	printf("\t****************************\n");
	printf("\t*   5. 按学号删除信息      *\n");
	printf("\t****************************\n");
	printf("\t*   6. 展示当前学生信息    *\n");
	printf("\t****************************\n");
	printf("\t*   7. 保存当前学生信息    *\n");
	printf("\t****************************\n");
	printf("\t*   8. 退出系统            *\n");
	printf("\t****************************\n\n");

    while(1){
        menu();// 循环打印菜单
    }

    system("pause");
    return 0;
}

void menu(){
    int num;
	printf("请输入您的选项(0~8): ");
    scanf("%d",&num);
    switch (num){
        case 0:
            help();
            break;
        case 1:
            readfile();
            break;
        case 2:
            seek();
            break;
        case 3:
            modify();
            break;
        case 4:
            insert();
            break;
        case 5:
            del();
            break;
        case 6:
            display();
            break;
        case 7:
            save();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("请在0-8中进行选择.\n");
            break;
    }
}

void help(){
    printf("___________________________________________\n");
    printf("\n  欢迎使用系统帮助！\n");
    printf("\n  首次进入系统后,请先选择增加学生信息;\n");
    printf("\n  按照菜单提示输入数字代号;\n");
    printf("\n  增加学生信息后记得保存;\n");
    printf("\n  感谢您的使用！\n");
	printf("___________________________________________\n");
    system("pause");   
}

void readfile(){
    char filemame[20];
    FILE *fp;
    int i=0;
    printf("请输入已存有学生信息的文件名：\n");
    scanf("%s",filemame);
    if((fp=fopen(filemame,"r"))==NULL){         //以只读的方式打开文件
        printf("打开文件%s错误.\n",filemame);     //文件可能不存在  
        printf("请先增加学生信息再执行该操作.\n");
        system("pause");
        return;
    }

    while(fscanf(fp,"%s%s%d%s%s%s%s%s",&stu[i].code,&stu[i].name,&stu[i].age,&stu[i].sex,&stu[i].address,&stu[i].e_mail,&stu[i].tel,&stu[i].birth)==8){
        i++;
    }       //扫描出文件内所有学生的信息，每个学生有8条个人信息

    n=i;    //将该文件学生数赋予全局变量n

    if(i==0) printf("文件为空，请先选择菜单4来增加学生信息.\n");
    else printf("读入成功.\n");

    fclose(fp);

    system("pause");
}

void seek(){

}

void modify(){

}

void insert(){

}

void del(){

}

void display(){

}

void save(){

}
