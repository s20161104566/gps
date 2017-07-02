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
    char str1[70],str2[70],lat[12],lg[15],spr[7],gro[7],high[5];
    char year[10],month[10],day[6],hour[10],min[10],second[10];
    int i;
    fr=fopen("//Users//s20161104566//Desktop//GPS170510.log","r+" );
    fr2=fopen("//Users//s20161104566//Desktop//gps//output.csv","w+" );
    if(fr==NULL)
    {
        printf("文件打开错误 , 文件可能不存在\n");
    }
    else
    {
        printf("gps\n");
        fprintf(fr2,"gps\n");
        printf(" 日期,时间,纬度,经度,速率,地面航向,海拔\n");
        fprintf(fr2," 日期,时间,纬度,经度,速率,地面航向,海拔\n");
        while(fscanf(fr,"%s %s",str1,str2)!=EOF)
        {
            for(i=0;i<2;i++)
            {
                year[i]=str1[i+55];
            }
            year[2]='\0';
            for(i=0;i<2;i++)
            {
                month[i]=str1[i+53];
            }
            month[2]='\0';
            for(i=0;i<2;i++)
            {
                day[i]=str1[i+51];
            }
            day[2]='\0';
            for(i=0;i<2;i++)
            {
                hour[i]=str1[i+7];
            }
            hour[2]='\0';
            for(i=0;i<2;i++)
            {
                min[i]=str1[i+9];
            }
            min[2]='\0';
            for(i=0;i<2;i++)
            {
                second[i]=str1[i+11];
            }
            second[2]='\0';
            for(i=0;i<8;i++)
                lat[i]=str1[i+16];
            lat[11]='\0';
            for(i=0;i<9;i++)
                lg[i]=str1[i+27];
            lg[11]='\0';
            
            for(i=0;i<5;i++)
                spr[i]=str1[i+39];
            spr[6]='\0';
            
            for(i=0;i<5;i++)
                gro[i]=str1[i+45];
            gro[6]='\0';
            
            
            for(i=0;i<4;i++)
                high[i]=str2[i+43];
            high[4]='\0';
            printf("%s年%s月%s日,%s时%s分%s秒,",year,month,day,hour,min,second);
            fprintf(fr2,"%s年%s月%s日,%s时%s分%s秒,",year,month,day,hour,min,second);
            
            printf("%s,",lat);
            fprintf(fr2,"%s,",lat);
            
            printf("%s,",lg);
            fprintf(fr2,"%s,",lg);
            
            printf("%s,",spr);
            fprintf(fr2,"%s,",spr);
            
            printf("%s,",gro);
            fprintf(fr2,"%s,",gro);
            
            printf("%s千米,",high);
            fprintf(fr2,"%s千米\n",high);
        }
        fclose(fr);
        fclose(fr2);
    }
    return 0;
}
