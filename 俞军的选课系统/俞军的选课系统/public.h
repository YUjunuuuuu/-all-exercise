//
//  public.h
//  俞军的选课系统
//
//  Created by mac yj on 2018/9/28.
//  Copyright © 2018 mac yj. All rights reserved.
//

#ifndef public_h
#define public_h
#include<stdio.h>
#include<string.h>
struct course
{
    char cno[10];
    char cname[20];
    char tno[20];
};
void addcourse(char *tno)//录入选课信息
{
    struct course cs[100];
    int n=0,i,flag=0;
    FILE *fp=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s",cs[n].cno);
        fscanf(fp,"%s",cs[n].cname);
        fscanf(fp,"%s",cs[n].tno);n++;
    }
    fclose(fp);
    printf("请输入课程编号:");
    scanf("%s",cs[n-1].cno);
    while(1)
    {
        for(i=0;i<n-1;i++)
        {
            if(strcmp(cs[i].cno,cs[n-1].cno)==0)
            {
                flag=1;break;
            }
        }
            if(flag==1)
            {
                printf("课程编号重复，请重新输入课程编号:");
                scanf("%s",cs[n-1].cno);
                flag=0;
            }
            else break;
        }
    printf("请输入课程名称:");
    scanf("%s",cs[n-1].cname);
    getchar();
    strcpy(cs[n-1].tno,tno);
    fp=fopen("/Users/macyj/Desktop/Debug/course.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s",cs[i].cno);
        fprintf(fp,"%s",cs[i].cname);
        fprintf(fp,"%s",cs[i].tno);
    }
    printf("录入成功!\n");
    fclose(fp);
}
void bubblesorts(struct course cs[],int n)//对选课编号进行排序
{
    int i,j,flag;
    struct course temp;
    for(i=n-1;i>0;i--)
    {
        flag=0;
        for(j=0;j<i;j++)
        {
            if(strcmp(cs[j].cno,cs[j+1].cno)==1)
            {
                temp=cs[j];
                cs[j]=cs[j+1];
                cs[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    
}
void seecourse()
{
    FILE *fp;
    struct course cs[10];
    int n=0;
    FILE *fp=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s",cs[n].cno);
        fscanf(fp,"%s",cs[n].cname);
        fscanf(fp,"%s",cs[n].tno);n++;
    }
    fclose(fp);
    for(n=0;n<=10;n++)
    {
        printf("%s  %s  %s\n",cs[n].cno,cs[n].cname.cs[n].tno);
    }
}

#endif /* public_h */
