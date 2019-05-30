#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<dir.h>
int log_in(int n,int m);
char idf[53];
int lns(void)
{
    FILE *fp;
    char ch[28];
    int c=0,lines=0;
    fp=fopen("Ids.txt","r");
    lines++;
    do
    {
      if (c == '\n' && c!='\0')
            lines++;
    }while ((c = fgetc(fp)) != EOF);
    fclose(fp);
    //printf("Lines= %d",lines);
    return lines;
}
int plns(void)
{
    FILE *fp;
    char ch[28];
    int c=0,lines=0;
    fp=fopen("Passes.txt","r");
    lines++;
    while ((c = fgetc(fp)) != EOF)
    {
      if (c == '\n' && c!='\0')
            lines++;
    }
    fclose(fp);
    //printf("Lines= %d",lines);
    return lines;
}
int sign_up()
{
    getwchar();
    char name[52],id[12],intake[3],sec[2],smail[34],spass[16],rpass[16],fld[34];
    int n1,n2,i,flag=1;
    FILE *fp,*f,*p;
    printf("Name:  ");
    gets(name);
    printf("Id:  ");
    gets(id);
    printf("Intake:  ");
    gets(intake);
    printf("Section:  ");
    gets(sec);
    printf("Select mail id:  ");
    gets(smail);
    strcpy(fld,smail);
    mkdir(fld);
    printf("Password:  ");
    gets(spass);
    n1=strlen(spass);
    printf("Re-type password:  ");
    gets(rpass);
    n2=strlen(rpass);
    if(n1==n2)
    {
        for(i=0;i<n2;++i)
        {
            if(rpass[i]!=spass[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("An error occured during sign up. Please try next time.\n");
        }
        else
        {
            printf("Successfully signed up. Please wait, your account will be activate within 72 hours.\n");
            strcat(fld,"\\\\");
            strcat(fld,"Details.txt");
            f=fopen(fld,"w");
            fprintf(f,"Name:  ");
            fputs(name,f);
            fprintf(f,"\n\nId:  ");
            fputs(id,f);
            fprintf(f,"\n\nIntake:  ");
            fputs(intake,f);
            fprintf(f,"\n\nSection:  ");
            fputs(sec,f);
            fprintf(f,"\n\nMail id:  ");
            fputs(smail,f);
            fprintf(f,"\n\nPassword:  ");
            fputs(spass,f);
            fp=fopen("Ids.txt","a");
            fprintf(fp,"\n");
            fputs(smail,fp);

            //fprintf(fp,"\n");
            p=fopen("Passes.txt","a");
            fprintf(p,"\n");
            fputs(spass,p);
            //fprintf(p,"\n");
            fclose(p);
            fclose(f);
            fclose(fp);
        }

    }
    else
    {
        flag=0;
        printf("An error occured during sign up. Please try next time.\n");
    }

    return flag;
}
int new_mail(void)
{
    //getwchar();
    char id[5001],sub[101],mod[5];
    int n,sum=48;

    gets(mod);
    printf("\n\nTo:  ");
    gets(id);
    //strcpy(idf,id);
    //puts(idf);
    printf("Subject:  ");
    gets(sub);
    printf("\n\nWrite your mail here,\n\n\n");
    strcat(id,"\\\\");
    strcat(id,idf);
    strcat(id,sub);

    strcat(id,".txt");
    FILE *fp;
    fp=fopen(id,"w");
    gets(id);
    fputs(id,fp);
    fclose(fp);

    return 0;
}
int proceed(void)
{
    char ch;
    int flag=0;
    scanf("%c",&ch);
    switch(ch)
    {
    case 'N':
    case 'n':
        {
            new_mail();
            break;
        }
    default:
    {
        flag=1;
        system("cls");
        printf("This software is till under construction.\n\n\nThank You for using this software.\n\n\n\n\n\n\n\n\n\n");
        break;
    }
    }
    /*if(ch!='n' || ch!='N')
        return 1;
    else
        return proceed();*/
    return flag;
}
int main(void)
{
    system("COLOR F0");
    for(int k=0;;++k){
    printf("Sign up:  press 1\n\nLog in:   press 2\n\n\nChoice:   ");
    int n=lns();
    int m=plns();
    int l,s,ch,i,j,x;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            system("cls");
            s=sign_up();
            if(s==1)
            {
                n++;
                m++;

            }
            break;
        }
    case 2:
        {
            system("cls");
            n+=lns();
            m+=plns();
            l=log_in(n,m);
            if(l==(m+n)-2)
            {
                system("cls");
                printf("Send a mail:  press N\n\nCheck inbox:  press I\n\nLog out:  press 0");
                for(i=0;;++i)
                {
                    printf("\n\n\n\nChoice:  ");
                    x=proceed();
                    if(x==1)
                        break;
                }

            }
            else
            {
                printf("Log in Failed.\n");
                for(i=0;i<2;++i)
                {
                    system("cls");
                    n=log_in(n,m);
                    if(n==0)
                    {
                        system("cls");
                        printf("Send a mail:  press N\n\nCheck inbox:  press I\n\nLog out:  press 0\n\n\n\n");
                        for(j=0;;++j)
                        {
                            printf("Choice:  ");

                            x=proceed();
                            if(x==1)
                                break;
                        }
                        break;
                    }
                }

            }
            break;
        }
    default:
        {
            printf("\n\n\n\n\nYour expectation can't recognized by machine. Good Bye.\n\n\n\n\n");
            break;
        }
    }
        if(ch>2 || ch<1)
        break;
    }
    getch();
    return 0;
}
int log_in(int n,int m)
{
    getwchar();
    char *chid,*id,*cpass,*pass;
    long long x=1000000,y=1000000;
    chid=(char *)malloc(x*sizeof(char));
    id=(char *)malloc(x*sizeof(char));
    cpass=(char *)malloc(y*sizeof(char));
    pass=(char *)malloc(y*sizeof(char));
    //int n=5;
    int i,j,flag=0,l1,l2,l3,l4,flag1=0;
    FILE *fp,*f;
    fp=fopen("Ids.txt","r");
    f=fopen("Passes.txt","r+");
    printf("Id: ");
    gets(chid);
    l1=strlen(chid);
    for(i=0;i<n;++i)
    {
        fgets(id,1000000,fp);
        l2=strlen(id)-1;
        if(l1==l2)
        {
            for(j=0;j<l1;++j)
            {
                if(*(chid+j)!=*(id+j))
                {
                    flag+=1;
                    break;
                }
            }

        }
        else
        {
            flag+=1;
        }
    }
    if(flag==n)
    {
        printf("Id not matched.\n");
    }
    else
    {
        printf("Password: ");
        gets(cpass);
        l3=strlen(cpass);
        for(i=0;i<m;++i)
        {
            fgets(pass,y,f);
            l4=strlen(pass)-1;
            if(l3==l4)
            {
                for(j=0;j<l3;++j)
                {
                    if(*(cpass+j)!=*(pass+j))
                    {
                        flag1+=1;
                        break;
                    }
                }
            }
            else
            {
                flag1+=1;
            }
        }
    }
    //printf("\nFlag= %d & Flag1= %d\n\n",flag,flag1);
    int r;
    r=flag+flag1;
    /*if(r==(m+n)-2)
    {
        printf("Welcome.\n");
    }
    else
    {
        printf("Log in failed.\n");
    }*/
    fclose(f);
    fclose(fp);
    return r;
}
