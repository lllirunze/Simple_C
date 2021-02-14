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

void menu();        // 进行选择
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
        menu();
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
    printf("请输入已存有学生信息的文件名：");
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
    int i,item;
    int flag;               //代表是否查询成功
    char str[20];           //代表需要输入的学号或姓名
    printf("**********************\n");
    printf("  --1.按学号查询--\n");
    printf("  --2.按姓名查询--\n");
    printf("  --3.退出本菜单--\n");
    printf("**********************\n");
    while(1){
        printf("请选择子菜单编号：");
        scanf("%d",&item);
        flag=0;
        switch(item){
            case 1:
                printf("请输入要查询的学号：");
                scanf("%s",str);
                for(i=0;i<n;i++){
                    if(strcmp(stu[i].code,str)==0){
                        flag=1;
                        printf("  学号:%s\n",stu[i].code);
                        printf("  姓名:%s\n",stu[i].name);
                        printf("  性别:%d\n",stu[i].age);
                        printf("  性别:%c\n",stu[i].sex);
                        printf("  地址:%s\n",stu[i].address);
                        printf("  邮箱:%s\n",stu[i].e_mail);
                        printf("  电话:%s\n",stu[i].tel);
                        printf("  出生日期:%s\n",stu[i].birth);
                    }
                    break;
                }
                if(flag==0) printf("该学号不存在.\n");
                break;
            
            case 2:
                printf("请输入要查询的姓名：");
                scanf("%s",str);
                for(i=0;i<n;i++){
                    if(strcmp(stu[i].code,str)==0){
                        flag=1;
                        printf("  学号:%s\n",stu[i].code);
                        printf("  姓名:%s\n",stu[i].name);
                        printf("  性别:%d\n",stu[i].age);
                        printf("  性别:%c\n",stu[i].sex);
                        printf("  地址:%s\n",stu[i].address);
                        printf("  邮箱:%s\n",stu[i].e_mail);
                        printf("  电话:%s\n",stu[i].tel);
                        printf("  出生日期:%s\n",stu[i].birth);
                    }
                    break;
                }
                if(flag==0) printf("该姓名不存在.\n");
                break;

            case 3:
                return;

            default:
                printf("请在1-3之间查询.\n");
        }
    }
}

void modify(){
    
}

void insert(){

}

void del(){

}

void display(){
    int i;
    printf("共有%d位学生的信息:\n\n",n);
    if(n!=0){
        printf("学号\t学生姓名 年龄\t性别\t地址\t\t邮箱\t\t电话\t\t出生日期  \n");             
        printf("--------------------------------------------------------------------\n");            
        for(i=0;i<n;i++){ 
           printf("%s\t%s\t %d\t%c\t%s\t%s\t%s\t%s\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].address,stu[i].e_mail,stu[i].tel,stu[i].birth);
        }
    }
    system("pause");
}

void save(){
    int i;
    FILE *fp;
    char filename[20];
    printf("请输入要保存该信息的文件名:");
    scanf("%s",filename);
    fp=fopen(filename,"w");
    for(i=0;i<n;i++){
        fprintf(fp,"%s\t%s\t %d\t%c\t%s\t%s\t%s\t%s\n",stu[i].code,stu[i].name,stu[i].age,stu[i].sex,stu[i].address,stu[i].e_mail,stu[i].tel,stu[i].birth);
    }
    printf("保存成功.\n");
    fclose(fp);
    system("pause");
}
