#include<stdio.h>

void Print_Star();
void muban();
int leap_year(int year);
int Current_day(int year,int month,int day);
void Print_Calendar(int sum,int year,int month);

int year,month,day;
int leap_month[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int ordinary_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    printf("Please input legal year,month, and day: ");
    scanf("%d%d%d",&year,&month,&day);

    if(year<1900){
        printf("illegal year, you should input reasonable year(>=1900)\n");
        return 0;
    }
    if(month<1 || month>12){
        printf("illegal month, you should input reasonable month(1~12)\n");
        return 0;
    }

    muban();
    Print_Calendar(Current_day(year,month,day),year,month);
    Print_Star();
    return 0;
}

void Print_Star(){
    printf("***********************************\n");
}

void muban(){
    int i;
    printf("       Perpetual Calendar\n");
    Print_Star();
    char weekday[7][10]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    for(i = 0; i < 7; i++){
        printf("%4s ", weekday[i]);
    }
    printf("\n");
}

int leap_year(int year){
    if((year%4==0 && year%100!=0) || year%400==0) return 1;//leap year
    else return 0;//ordinary year
}

int Current_day(int year,int month,int day){
    // 1900/01/01  <->  Monday
    int i,sum=0;
    //add years
    int current_year;
    for(i=1900; i<year; i++){
        current_year = leap_year(i);
        if(current_year) sum+=2;// 366%7=2
        else sum+=1;// 365%7=1
    }
    //add months
    if(leap_year(year)){
        for(i=0; i<month-1; i++){
            sum+=leap_month[i];
        }
    }
    else{
        for(i=0; i<month-1; i++){
            sum+=ordinary_month[i];
        }
    }

    return sum%7;
}

void Print_Calendar(int sum,int year,int month){
    int i,temp;
    for(i=0; i<sum; i++){
        printf("     ");//Print extra space
    }
    temp=7-sum;
    if(leap_year(year)){
        for(i=1; i<=leap_month[month-1]; i++){
            printf("%3d  ",i);
            if(i==temp || (i-temp)%7==0) printf("\n");
        }
    }
    else{
        for(i=1; i<=ordinary_month[month-1]; i++){
            printf("%3d  ",i);
            if(i==temp || (i-temp)%7==0) printf("\n");
        }
    }
    printf("\n");
}