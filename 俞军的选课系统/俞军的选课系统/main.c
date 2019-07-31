#include<stdio.h>
#include<string.h>
struct course
{
    char cno[10];
    char cname[20];
    char tno[20];
};struct person
{
    char pno[10];
    char pname[10];
    char pw[10];
};
struct enroll
{
    char sno[10];
    char cno[10];
    int grade;
};
int main()
{int yanzheng(char kind,char *bh);
    void teacher(char *tno);
    void student(char *sno);
    printf("**********************************\n");
    printf("        软工一班的选课表          \n");
    printf("**********************************\n");
    printf("请输入用户类别<s or t>\n");
    char kind;
    scanf("%c",&kind);
    char bh[10];
    if(yanzheng(kind,bh)==1)
    {
        if(kind=='s')
            student(bh);
        if(kind=='t')
            teacher(bh);
    }
    return 0;
}

int yanzheng(char kind,char *bh)
{
    FILE *fp;
    if(kind=='s'||kind=='t')
    {
        do
        {
            char mima[10];
            if(kind=='s')
               fp=fopen("/Users/macyj/Desktop/Debug/student.txt","r");            else
                fp=fopen("/Users/macyj/Desktop/Debug/teacher.txt","r");
            if(fp==NULL)
            {
                printf("文件打开失败\n");
                return 0;
            }
            printf("请输入用户编号\n");
            scanf("%s",bh);
            printf("请输入密码\n");
            int i=0;
            scanf("%s",mima);
           
            
            struct person ps;
            while(!feof(fp))
            {
                fscanf(fp,"%s",ps.pno);
                fscanf(fp,"%s",ps.pname);
                fscanf(fp,"%s",ps.pw);
                if(strcmp(ps.pno,bh)==0&&strcmp(ps.pw,mima)==0)
                {    printf("\n登陆成功\n");return 1;}
            
                    printf("\n登陆失败\n");
            }
            rewind(fp);
        }while(1);
        fclose(fp);
        
        
    }
    else
        printf("用户类别错误\n");
    return 0;
}

void teacher(char *tno)
{void addcourse(char *tno);    char choice,he;
    void seechoosed(char *tno);
    void addgrade(char *tno);    int m;
    printf("录入课程信息请安1\n");
    printf("查看被选信息请按2\n");
    printf("录入选课信息请按3\n");
    printf("退出请按其他\n");
    printf("1111请选择\n");
    getchar();
    choice=getchar();
    while(choice=='1'||choice=='2'||choice=='3')
    {
        switch(choice)
        {
            case'1':addcourse( tno);break;
            case'2':seechoosed(tno);break;
            case'3':addgrade(tno);break;
        }
        printf("请输入: ");
        getchar();
        choice=getchar();
        printf("请输入\n");
    }
}

void student(char *sno)
{void seecourse() ;
    void choosecourse(char *sno);
    void deletechoosecourse(char *sno);
    void seechoosecoursegrade(char *sno);
    char choice;
    int m;
    printf("查看课程信息请按1\n");
    printf("完成选课信息请按2\n");
    printf("删除选课信息请按3\n");
    printf("查看选课成绩请按4\n");
    printf("请选择\n");
    getchar();
    choice=getchar();
    while(choice=='1'||choice=='2'||choice=='3'||choice=='4')
    {
        switch(choice)
        {
            case'1':seecourse();break;
            case'2':choosecourse(sno);break;//问题no有wen
            case'3':deletechoosecourse(sno);break;
            case'4':seechoosecoursegrade(sno);
        }
        printf("请输入:");
        getchar();
        choice=getchar();
        
    }
}
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
void seecourse()
{
    FILE *fp;
    struct course cs[10];
    int n=0;
    fp=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s",cs[n].cno);
        fscanf(fp,"%s",cs[n].cname);
        fscanf(fp,"%s",cs[n].tno);n++;
    }
    fclose(fp);
    for(n=0;n<=10;n++)
    {
        printf("%s  %s  %s\n",cs[n].cno,cs[n].cname,cs[n].tno);
    }
}
void choosecourse(char *sno)
{
    char ch='y';
    int i=0,k,n=0;
    char cno[10];
    char selectcno[3][10];
    struct enroll en[10];
    struct course cs;
    int flag1,flag2;
    FILE *fp1=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r");
    if((fp1=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r"))==NULL)
    {
        printf("can not open this file\n");
    }
    FILE *fp2=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
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
                fscanf(fp2,"%s",cs.cname);
                fscanf(fp2,"%s",cs.tno);
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
                                  fp1=fopen("/Users/macyj/Desktop/Debug/enroll.txt","w");
                                  for(k=0;k<n;k++)
                                      fprintf(fp1,"%s%s%d",en[k].sno,en[k].cno,en[k].grade);
                                  printf("选课成功!\n");
                                  n++;
                                  
                              }
                              else printf("上次已经选过了!\n");
                              printf("是否继续选课?(y or n)");
                              ch=getchar();
                              getchar();
        if(ch=='n')
            printf("跳出选课系统成功\n");
        printf("请继续选择你要进行的操作\n");
                              }
                              if(i==3)
                              printf("你已经选修了三门课程！\n");
                              fclose(fp1);
                              fclose(fp2);
                              }
void deletechoosecourse(char *sno)
{struct enroll en[100];
    struct enroll no[100];
    int n=0,i=0,flag;
    FILE *fp1=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r");
    if((fp1=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r"))==NULL)
    {
        printf("can not open this file\n");
    }
    printf("数据读取成功\n");
    while(!feof(fp1))
    {
        flag=fscanf(fp1,"%s",no[n].sno);
        fscanf(fp1,"%s",no[n].cno);
        fscanf(fp1,"%d",&no[n].grade);
        if(strcmp(no[n].sno,sno)!=0&&flag==1)
        {
            n++;
        
        }
    
    }
    fclose(fp1);
    i=0;
    FILE *fp2=fopen("/Users/macyj/Desktop/Debug/enroll.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp2,"%s",en[i].sno);
        fprintf(fp2,"%s",en[i].cno);
        fprintf(fp2,"%d",en[i].grade);
    }
    fclose(fp2);
    printf("删除成功\n");
}
void seechoosecoursegrade(char *sno)//bug
{
    FILE *fp=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r");
    int i=0,j;
    struct enroll en1[100];
    while(!feof(fp))
    {
        fscanf(fp,"%s",en1[i].sno);
        fscanf(fp,"%s",en1[i].cno);
        fscanf(fp,"%d",&en1[i].grade);
        i++;
        
    }
    fclose(fp);
    for(j=0;j<i;j++)
    {
        if(strcmp(en1[j].sno,sno)==0)
        {  printf("%s\n",en1[j].sno);
             printf("%s\n",en1[j].cno);
            printf("grade is %d\n",en1[j].grade);}
        continue;
        
    }
    
    
}
void seechoosed(char *tno)//查看教师的课被多少学生选bug
{int i=0,j=0,k=0;
    struct enroll hn[100];
    struct course cs[100];
    FILE *fp1=fopen("/Users/macyj/Desktop/Debug/course.txt","r");
    while(!feof(fp1))
    {
        fscanf(fp1,"%s",cs[i].cno);
        fscanf(fp1,"%s",cs[i].cname);
        fscanf(fp1,"%s",cs[i].tno);
        if(strcmp(cs[i].tno,tno)==0)
        {  i++;
        }
        
        
    }
     fclose(fp1);
    FILE *fp2=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r");
    
    while(!feof(fp2))
    {
        fscanf(fp2,"%s",hn[k].sno);
        fscanf(fp2,"%s",hn[k].cno);
        fscanf(fp2,"%d",&hn[k].grade);
        if(strcmp(cs[j].cno,hn[k].cno)==0)
        {
            printf("%s\n",hn[k].cno);
            j++;if(j>i)
            {break;}
        }
        k++;
    }
    
    fclose(fp2);
}
void addgrade(char *tno)
{void seechoosed(char *tno);
    struct enroll en1[100],en2[100];
    int n1=0,n2=0,n=0,i,j,flag;
    seechoosed(tno);
    for(i=0;i<n2;i++)
    {
        printf("请输入学号%s选修课程号%s的成绩:",en2[i].sno,en2[i].cno);
        scanf("%d",&en2[i].grade);
    }
    getchar();
    FILE *fp=fopen("/Users/macyj/Desktop/Debug/enroll.txt","r");
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
    fp=fopen("/Users/macyj/Desktop/Debug/enroll.txt","w");
    for(i=0;i<n1;i++)
    {
        fprintf(fp,"%s",en1[i].sno);
        fprintf(fp,"%s",en1[i].cno);
        fprintf(fp,"%d",en1[i].grade);
    }
    fclose(fp);
}
