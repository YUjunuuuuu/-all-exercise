//
//  student.h
//  俞军的选课系统
//
//  Created by mac yj on 2018/9/28.
//  Copyright © 2018 mac yj. All rights reserved.
//

#ifndef student_h
#define student_h
struct enroll
{
    char sno[10];
    char cno[10];
    int grade;
};
void choosecourse(char *sno)
{
    char ch='y';
    int i=0,k,n=0;
    char cno[10];
    char selectcno[3][10];
    struct course cs;
    int flag1,flag2;
    FILE *fp1=fopen("/Users/macyj/Desktop/enroll.txt","r");
    FILE *fp1=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
    printf("至少选一门，最多选3门选修课\n");
    while(!feof(fp1))
    {
        flag2=fscanf(fp1,"%s",en[n].sno);
        fscanf(fp1,"%s",en[n].cno);
        fscanf(fp1,"%d",&en[n].grade);
        if(flag2==1&&strcmp(en[n].sno,sno)==0)
        {//将已选课程放入存放选修课程的二维数组中
            strcpy(selectcno[i],en[n].cno);
            i++;
            
        }
        n++;
    }
    while(i<3&&ch=='y')
    {
        flag1=0;
        while(flag1==0)
        {
            printf("请输入所选课程的课程号:");
            scanf("%s",cno);
            getchar();
            rewind(fp2);
            while(!feof(fp2))
            {
                flag2=fscanf(fp2,"%s",cs.cno);
                fscanf("fp2,"%s",cs.cname);
                fscanf("fp2,"%s",cs.tno);
                //如果读取成功，并且在course.txt找到用户输入的cno,结束循环
                if(flag2==1&&strcmp(cs.cno,cno)==0)
                       {flag1=1;break;}
                }
                if(flag1==0)
                       printf("未开设所选课程!\n");
                
            }
                       flag1=0;
                       for(k=0;k<i;k++)
                if(strcmp(cno,selectcno[k])==0)
                       {
                           flag1=1;
                           break;
        }
                if(flag1==0)
                       {
                           strcpy(selectcno[i],cno);
                           i++;
                           strcpy(en[n-1].sno,sno);
                           en[n-1].grade=0;
                           strcpy(en[n-1].cno,cno);
                           fclose(fp1);
                           fp1=fopen("enroll.txt","w");
                           for(k=0;k<n;k++)
                               fprintf(fp1,"%s%s%d",en[k].sno,en[k].cno,en[k].grade);
                           printf("选课成功!\n");
                           n++;
                           
                       }
                       else printf("上次已经选过了!\n");
                       printf("是否继续选课?(y or n)");
                       ch=getchar();
                       getchar();
    }
                if(i==3)
                       printf("你已经选修了三门课程！\n");
                       fclose(fp1);
                       fclose(fp2);
}
                void bubblesorten(struct enroll en[],int n)
                       {
                           struct enroll temp;
                           int j=0,i;
                           for(i=n-1;i>0;i--)
                           {
                               int flag=0;
                               for(j=0;j<n;j++)
                               {
                                   if(strcmp(en[j].sno,en[j+1].sno)==1)
                                   {temp=en[j+1].sno
                                       en[j+1].sno=en[j].sno;
                                       en[j].sno=temp;
                                       flag=1;
                                       
                                   }
                                   if(flag==0)
                                       break;
                               }
                           }
                       }
                
                void deletechoosecourse(char *sno)
                       {struct enroll en[100];
                           struct enroll no[100];
                           int n=0,i=0;
                           FILE *fp1=fopen("/Users/macyj/Desktop/enroll.txt","r");
                           while(!feof)
                           {
                               fscanf(fp1,"%s",no[n].sno);
                               fscanf(fp1,"%s",no[n].cno);
                               fscanf(fp1,"%s",no[n].grade);
                               if(strcmp(no[n].sno)!=0)
                               {
                                   strcpy(en[i].sno,no[n].sno);
                                   strcpy(en[i].cno,no[n].cno);
                                   strcpy(en[i].grade,no[n].grade);
                               }
                               n++;i++;
                           }
                           fclose(fp1);
                           i=0;
                           FILE *fp2=fopen("/Users/macyj/Desktop/enroll.txt","w");
                           while(!feof)
                           {
                               fprintf(fp2,"%s",en[n].sno);
                               fprintf(fp2,"%s",en[n].cno);
                               fprintf(fp2,"%s",en[n].grade);
                               n++;
                           }
                           fclose(fp2);
                       }

#endif /* student_h */
