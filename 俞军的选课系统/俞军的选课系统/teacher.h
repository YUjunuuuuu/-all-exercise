//
//  teacher.h
//  俞军的选课系统
//
//  Created by mac yj on 2018/9/30.
//  Copyright © 2018 mac yj. All rights reserved.
//

#ifndef teacher_h
#define teacher_h
void seechoosed(char *tno)
{int i=0,j=0,k=0;
    struct enroll hn[100];
    struct course cs[100];
    struct course hs[100];
    FILE *fp1=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
    while(!feof(fp1))
    {
        fscanf(fp1,"%s",cs[i].cno);
        fscanf(fp1,"%s",cs[i].cname);
        fscanf(fp1,"%s",cs[i].tno);
        if(strcmp(cs[i].tno,tno==0))
        {hs[j].cno=cs[i].cno;
            hs[j].cname=cs[i].cname;
            hs[j].tno=cs[i].tno;
            j++;
            
        }
        i++;
        
}
    j=0;
    FILE *fp2=fopen("/Users/macyj/Desktop/Debug/enroll.rtf","r");
    while(!feof(fp2))
    {
        fscanf(fp2,"%s",hn[k].sno);
        fscanf(fp2,"%s",hn[k].cno);
        fscanf(fp2,"%d",hn[k].grade);
        if(strcmp(hn[k].cno,hs[j].cno)==0)
        {printf("%s",hn[k].cno);
            
        }
        k++;j++;
    }
    fclose(fp1);
    fclose(fp2);
        }


void addgrade(char *tno)
{
    struct enroll en1[100],en2[100];
    int n1=0,n2=0,i,j,flag;
    seehoosed(tno,en2,&n2);
    for(i=0;i<n2;i++)
    {
        printf("请输入学号%s选修课程号%s的成绩:",en2[i].sno,en2[i].cno);
        scanf("%d",&en2[i].grade);
    }
    getchar();
    FILE *fp=fopen("/Users/macyj/Desktop/Debug/enroll.rtf");
    while(!feof(fp))
    {
        flag=fscanf(fp,"%s",en1[n1].sno);
        fscanf(fp,"%s",en1[n1].cno);
        fscanf(fp,"%d",&en1[n1].grade);
        if(flag==1)
            n1++;
    }
    fclose(fp);
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
            if(strcmp(en1[i].sno,en2[j].sno)==0&&strcmp(en1[i].cno,en2[j].cno)==0)
            {
                en1[i]=en2[j];
                n++;break;
            }
        if(n==n2)
            break;
        
    }
    fp=fopen("/Users/macyj/Desktop/Debug/enroll.rtf","w");
    for(i=0;i<n1;i++)
    {
        fprintf(fp,"%s",en1[i].sno);
        fprintf(fp,"%s",en1[i].cno);
        fprintf(fp,"%s",en1[i].grade);
    }
    fclose(fp);
}
//查看学生的成绩
void seechoosecoursegrade(char *sno)
{
    FILE *fp=fopen("/Users/macyj/Desktop/Debug/enroll.rtf","r");
    int int i=0;,j;
    struct enroll en1[100];
    while(!feof)
    {
        fscanf=(fp,"%s",en1[i].sno);
        fscanf=(fp,"%d",en1[i].grade);
        i++;
        
    }
    for(j=0;j<i;j++)
    {
        if(strcmp(en1[j].sno,sno==0))
            printf("grade is %d\n",en1[j].grade);
        continue;
            <#statements#>
        }
            <#statements#>
    
    }


#endif /* teacher_h */
