#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{     //学生的结构体
    char code[20];      //学号
    char name[10];      //姓名
    int age;            //年龄
    char sex;           //性别
    char address[80];   //地址
    char e_mail[50];    //邮箱
    char tel[11];       //电话
    char birth[40];     //出生日期
}stu[200];
