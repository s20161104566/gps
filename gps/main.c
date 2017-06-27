//
//  main.c
//  gps
//
//  Created by s20161104566 on 2017/6/27.
//  Copyright © 2017年 s20161104566. All rights reserved.
//

#include <stdio.h>
int main(int args,const char * argv[]) {
    FILE *fr;
    FILE *fr2;
    char time[8],str1[70],str2[70],lat[12],lg[15],spr[7],gro[7],date[8],high[5];
    int i,year,month,day,hour,minute,second;
    fr=fopen("//Users//s20161104566//Desktop//GPS170510.log","r+" );
    fr2=fopen("//Users//s20161104566//Desktop//gps//output.txt","w+" );
    fscanf(fr,"%s%s",str1,str2);
    printf("结果: %s\n%s\n",str1,str2);
    fprintf(fr2,"结果: %s\n%s\n",str1,str2);
    for(i=0;i<8;i++)
        time[i]=str1[i+7];
    time[7]='\0';
    printf("时间:%s\n",time);
    fprintf(fr2,"时间:%s\n",time);
    for(i=0;i<12;i++)
        lat[i]=str1[i+16];
    lat[11]='\0';
    printf("纬度:%s\n",lat);
    fprintf(fr2,"纬度:%s\n",lat);
    for(i=0;i<12;i++)
        lg[i]=str1[i+28];
    lg[11]='\0';
    printf("经度:%s\n",lg);
    fprintf(fr2,"经度:%s\n",lg);
    for(i=0;i<6;i++)
        spr[i]=str1[i+39];
    spr[6]='\0';
    printf("速率:%s\n",spr);
    fprintf(fr2,"速率:%s\n",spr);
    for(i=0;i<7;i++)
        gro[i]=str1[i+45];
    gro[6]='\0';
    printf("地面航向:%s\n",gro);
    fprintf(fr2,"地面航向:%s\n",gro);

    for(i=0;i<5;i++)
        high[i]=str2[i+43];
    high[4]='\0';
    printf("海拔:%s千米\n",high);
    fprintf(fr2,"海拔:%s千米\n",high);
    fclose(fr);
    for(i=0;i<8;i++)
        date[i]=str1[i+51];
    date[7]='\0';
    int n,a[10],y,b;
    n=atoi(date);
    for(i=0;i<6;i++)
    {
        a[i]=n%10;
        n=n/10;
    }
    y=a[0]+a[1]*10+2000;
    month=a[3]*10+a[2];
    day=a[5]*10+a[4];
    hour=a[5]*10+a[4]+8;
    minute=a[3]*10+a[2];
    second=a[1]*10+a[0];
    b=0;
    if(hour>=24)
    {
        b++;
        hour=hour-24;
    }
    printf("%s",date);
    printf("日期:%d\n",y);
    fprintf(fr2,"日期:%s\n",date);
    printf (" %d年%d月%d日",year,month,day);
    printf(" %d时%d分%d秒",hour,minute,second);
    
    return 0;
}
