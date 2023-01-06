#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
void start();
void roundrobin(int,int,char[]);
void knockout(int,int,char[]);
void hybrid(int,int,char[]);
void timer();
void zero(int x ,int y);
void one(int x,int y);
void two(int x,int y);
void three(int x,int y);
void four(int x,int y);
void five(int x,int y);
void six(int x,int y);
void seven(int x,int y);
void eight(int x,int y);
void nine(int x,int y);
void colon(int x,int y);
void gotoxy(int x,int y);
void display(int digit, int x , int y);
void showtime(int minute , int second);
void SetColor(int ForgC);
void characterC(int x,int y);
void characterU(int x, int y);
void characterS(int x, int y);
void characterT(int x, int y);
void characterO(int x,int y);
void characterM(int x, int y);
void characterF(int x,int y);
void characterB(int x, int y);
void characterA(int x, int y);
void characterL(int x, int y);
void characterR(int x, int y);
void characterN(int x, int y);
void characterE(int x, int y);
struct table
{
    char name[50];
    int p,pts,GS,GA,GD,len,rcheck,g;
};
struct groups
{
    struct table grp[50],temp;
    int teams,check[50];
};
struct general
{
    char name[50];
    int goals,agg,check;
};
struct teams
{
    char name[50];
    int goals,agg,check;
};
int main()
{
    char ch;
    SetColor(13);
    characterC(33,1);
    characterU(41,1);
    characterS(49,1);
    characterT(57,1);
    characterO(65,1);
    characterM(73,1);
    SetColor(11);
    characterF(25,8);
    characterO(33,8);
    characterO(41,8);
    characterT(49,8);
    characterB(57,8);
    characterA(65,8);
    characterL(73,8);
    characterL(81,8);
    SetColor(14);
    characterT(17,15);
    characterO(25,15);
    characterU(33,15);
    characterR(41,15);
    characterN(49,15);
    characterA(57,15);
    characterM(65,15);
    characterE(75,15);
    characterN(83,15);
    characterT(91,15);
    SetColor(10);
    gotoxy(47,22);
    printf("Press any key to continue.\n");
    SetColor(15);
    gotoxy(59,23);
    ch=getch();
    system("CLS");
    start();
    printf("\nPress any key to end the program.\n");
    ch=getch();
    return 0;
}

void start()
{
    int format,n,a,t;
    char tnmt[50];
    FILE *tv,*tn;
    app:
    printf("Choose the preferred option:\n");
    SetColor(14);
    printf("1.Organize a Tournament\n");
    SetColor(10);
    printf("2.Use the StopWatch\n");
    SetColor(15);
    scanf("%d",&a);
    system("CLS");
    switch(a)
    {
    case 1:
    {
    printf("Enter:");
    SetColor(11);
    printf("\n1.New Tournament");
    SetColor(14);
    printf("\n2.Load Tournament\n");
    SetColor(12);
    printf("\nWarning!!! Starting a new tournament will erase previous tournament.\n");
    SetColor(15);
    scanf("%d",&t);
    system("CLS");
    if(t==2)
    {
    goto load;
    }
    tv=fopen("tournament variables.txt","wb");
    printf("Enter the name of the tournament:\n");
    SetColor(11);
    scanf(" %[^\n]s ",tnmt);
    SetColor(15);
    printf("Enter the number of teams:\n");
    scanf("%d",&n);
    selectformat:
    printf("Choose the format of tournament:\n");
    SetColor(14);
    printf("1)League\n");
    SetColor(12);
    printf("2)Knockout\n");
    SetColor(11);
    printf("3)Round Robin and Knockout\n");
    scanf("%d",&format);
    system("CLS");
    tn=fopen("tournament name.txt","wb");
    fprintf(tn,"%s\n",tnmt);
    fclose(tn);
    fprintf(tv,"%d\n",n);
    fprintf(tv,"%d",format);
    fclose(tv);
    load:
    tv=fopen("tournament variables.txt","rb");
    tn=fopen("tournament name.txt","rb");
    while(!feof(tn))
    {
     fscanf(tn," %[^\n]s",tnmt);
    }
    while(!feof(tv))
    {
    fscanf(tv,"%d%d",&n,&format);
    }
    fclose(tn);
    fclose(tv);
    switch(format)
    {
    case 1:
    roundrobin(n,t,tnmt);
    break;
    case 2:
    knockout(n,t,tnmt);
    break;
    case 3:
    hybrid(n,t,tnmt);
    break;
    default:
    {
    SetColor(12);
    printf("Error!!!\n");
    SetColor(15);
    goto selectformat;
    }
    }
    break;
    }
    case 2:
    timer();
    break;
    default:
    {
    SetColor(12);
    printf("Error!!!\n");
    SetColor(15);
    goto app;
    }
    }
}

void roundrobin(int n,int nl,char tnmt[50])
{
    int i,j,k,l,m,o,y,edit,sread=-1,mid;
    FILE *rr,*rv,*stand,*match;
    struct table s[100],t[100],temp;
    char e,random[100];
    srand(time(NULL));
    if(nl==2)
    {
    rv=fopen("round robin variables.txt","rb");
    while(!feof(rv))
    {
    fscanf(rv,"%d%d%d%d",&m,&y,&j,&mid);
    }
    fclose(rv);
    rr=fopen("table.txt","rb");
    while(!feof(rr))
    {
    fread(&s[++sread],sizeof(struct table),1,rr);
    }
    fclose(rr);
    goto load;
    }
    stand=fopen("standings.txt","w");
    fclose(stand);
    match=fopen("matches.txt","w");
    fclose(match);
    rv=fopen("round robin variables.txt","wb");
    mid=0;
    printf("How many times do the teams play each other?\n");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        s[i].rcheck=1;
    }
    for(i=0;i<n;i++)
    {
        SetColor(i%5+10);
        printf("Enter the name of team %d:",i+1);
        scanf(" %[^\n]s ",s[i].name);
    }
    SetColor(15);
    system("CLS");
    printf("Would you like to randomize the order of the teams?\n");
    SetColor(14);
    printf("Press Y to randomize.\n");
    SetColor(13);
    printf("Press any key to continue without randomizing.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    for(i=0;i<n;i++)
    {
        j=(rand()%(n-1))+1;
        strcpy(random,s[i].name);
        strcpy(s[i].name,s[j].name);
        strcpy(s[j].name,random);
    }
    SetColor(14);
    printf("\nRandomized!\n");
    }
    for(i=0;i<n;i++)
    {
        s[i].pts=0;
        s[i].GS=0;
        s[i].GA=0;
        s[i].GD=0;
        s[i].p=0;
        s[i].len=strlen(s[i].name);
    }
    rr=fopen("table.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct table),1,rr);
    }
    fclose(rr);
    SetColor(10);
    printf("\nData has been saved!\n");
    j=0;
    y=1;
    SetColor(12);
    printf("\nPress e to end the program.\n");
    SetColor(14);
    printf("Press any other key to continue.\n");
    e=getch();
    SetColor(15);
    if(e=='E'||e=='e')
    {
     fprintf(rv,"%d%\n%d\n%d\n%d",m,y,j,mid);
     fclose(rv);
     exit(0);
    }
    fclose(rv);
    load:
    rv=fopen("round robin variables.txt","wb");
    for(l=y;l<=m;l++)
    {
    if(n%2==0)
    {
    o=(l*n)-l;
    }
    else
    {
    o=l*n;
    }
    while(j<o)
    {
    rr=fopen("table.txt","wb");
    for(i=0;i<n;i++)
    {
        fwrite(&s[i],sizeof(struct table),1,rr);
    }
    fclose(rr);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(15);
    if(l%2==0 && mid!=1)
    {
    if(n%2==0)
    {
    for(i=0;i<n/2;i++)
        {
            temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
        }
    }
    else
    {
    for(i=0;i<n/2;i++)
        {
            temp=s[i+1];
            s[i+1]=s[n-1-i];
            s[n-1-i]=temp;
        }
    }
    }
    mid=0;
        SetColor(10);
        printf("\nMatchday %d:\n",j+1);
        SetColor(15);
    for(i=0;i<n/2;i++)
    {
        if(n%2==0)
        printf("%s VS %s\n",s[i].name,s[n-1-i].name);
        else
        printf("%s VS %s\n",s[i+1].name,s[n-1-i].name);
    }
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
    y=l;
    fprintf(rv,"%d\n %d\n %d\n%d",m,y,j,mid);
    fclose(rv);
    exit(0);
    }
    skippeda:
    if(n%2==0)
    {
    for(i=0;i<n/2;i++)
    {
        if(s[i].rcheck==1)
        {
        printf("\n");
        printf("Match %d:%s VS %s\n",i+1,s[i].name,s[n-1-i].name);
        SetColor(12);
        printf("\nPress s to skip the match for now.\n");
        SetColor(14);
        printf("Press any other key to continue.\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        s[i].rcheck=0;
        printf("\nEnter number of goals scored by %s:",s[i].name);
        scanf("%d",&s[i].g);
        printf("Enter number of goals scored by %s:",s[n-1-i].name);
        scanf("%d",&s[n-1-i].g);
        }
        }
    }
    }
    else
    {
    for(i=0;i<n/2;i++)
    {
        if(s[i+1].rcheck==1)
        {
        printf("\n");
        printf("Match %d:%s VS %s\n",i+1,s[i+1].name,s[n-1-i].name);
        SetColor(12);
        printf("\nPress s to skip the match for now.\n");
        SetColor(14);
        printf("Press any other key to continue.\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        s[i+1].rcheck=0;
        printf("\nEnter number of goals scored by %s:",s[i+1].name);
        scanf("%d",&s[i+1].g);
        printf("Enter number of goals scored by %s:",s[n-1-i].name);
        scanf("%d",&s[n-1-i].g);
        }
        }
    }
    }
    SetColor(11);
    printf("\nRemaining matches:\n");
    SetColor(15);
    if(n%2==0)
    {
    for(i=0;i<n/2;i++)
    {
        if(s[i].rcheck==1)
        {
            printf("%s VS %s\n",s[i].name,s[n-1-i].name);
        }
    }
    }
    else
    {
    for(i=0;i<n/2;i++)
    {
        if(s[i+1].rcheck==1)
        {
            printf("%s VS %s\n",s[i+1].name,s[n-1-i].name);
        }
    }
    }
    rr=fopen("table.txt","wb");
    for(i=0;i<n;i++)
    {
        fwrite(&s[i],sizeof(struct table),1,rr);
    }
    fclose(rr);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.\n");
    SetColor(14);
    printf("Press any other key to continue\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
    y=l;
    mid=1;
    fprintf(rv,"%d\n %d\n %d\n %d",m,y,j,mid);
    fclose(rv);
    exit(0);
    }
    if(n%2==0)
    {
    for(i=0;i<n/2;i++)
    {
    if(s[i].rcheck==1)
    goto skippeda;
    }
    }
    else
    {
    for(i=0;i<n/2;i++)
    {
    if(s[i+1].rcheck==1)
    goto skippeda;
    }
    }
    for(i=0;i<n;i++)
    {
        s[i].rcheck=1;
    }
    printf("\n");
    editresult1a:
    printf("\n");
    for(i=0;i<n/2;i++)
    {
        if(n%2==0)
        printf("%s %d-%d %s\n",s[i].name,s[i].g,s[n-1-i].g,s[n-1-i].name);
        else
        printf("%s %d-%d %s\n",s[i+1].name,s[i+1].g,s[n-1-i].g,s[n-1-i].name);
    }
    printf("\nWould you like to change any result of Matchday%d?\n",j+1);
    SetColor(12);
    printf("\nPress Y to change the results.\n");
    SetColor(14);
    printf("Press any other key to continue without editing any of the results.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    printf("\nChoose the match number of the match whose outcome you want to change:\n");
    for(i=0;i<n/2;i++)
    {
        if(n%2==0)
        printf("Match %d:%s VS %s\n",i+1,s[i].name,s[n-1-i].name);
        else
        printf("Match %d:%s VS %s\n",i+1,s[i+1].name,s[n-1-i].name);
    }
    scanf("%d",&edit);
    if(n%2==0)
    {
    printf("Match %d:%s VS %s\n",edit,s[edit-1].name,s[n-edit].name);
    printf("Enter number of goals scored by %s:",s[edit-1].name);
    scanf("%d",&s[edit-1].g);
    }
    else
    {
    printf("Match %d:%s VS %s\n",edit,s[edit].name,s[n-edit].name);
    printf("Enter number of goals scored by %s:",s[edit].name);
    scanf("%d",&s[edit].g);
    }
    printf("Enter number of goals scored by %s:",s[n-edit].name);
    scanf("%d",&s[n-edit].g);
    goto editresult1a;
    }
    match=fopen("matches.txt","a");
    fprintf(match,"\nMatchday %d:\n",j+1);
    for(i=0;i<n/2;i++)
    {
        if(n%2==0)
        fprintf(match,"%s %d-%d %s\n",s[i].name,s[i].g,s[n-1-i].g,s[n-1-i].name);
        else
        fprintf(match,"%s %d-%d %s\n",s[i+1].name,s[i+1].g,s[n-1-i].g,s[n-1-i].name);
    }
    fclose(match);
    SetColor(13);
    printf("\nMatches have been recorded.\nYou can check the recorded matches by opening the text file matches.txt.\n");
    SetColor(14);
    printf("\nPress any key to continue.\n");
    SetColor(15);
    e=getch();
if(n%2==0)
{
       for(i=0;i<n;i++)
    {
        s[i].p=s[i].p+1;
        s[i].GS=s[i].GS+s[i].g;
        s[i].GA=s[i].GA+s[n-1-i].g;
        s[i].GD=s[i].GS-s[i].GA;
        if(s[i].g>s[n-1-i].g)
        s[i].pts=s[i].pts+3;
        else if(s[i].g==s[n-1-i].g)
        s[i].pts=s[i].pts+1;
        else
        s[i].pts=s[i].pts;
    }
}
else
{     for(i=0;i<n;i++)
    {
        s[i+1].p=s[i+1].p+1;
        s[i+1].GS=s[i+1].GS+s[i+1].g;
        s[i+1].GA=s[i+1].GA+s[n-1-i].g;
        s[i+1].GD=s[i+1].GS-s[i+1].GA;
        if(s[i+1].g>s[n-1-i].g)
        s[i+1].pts=s[i+1].pts+3;
        else if(s[i+1].g==s[n-1-i].g)
        s[i+1].pts=s[i+1].pts+1;
        else
        s[i+1].pts=s[i+1].pts;
    }
}
    {
    for(i=0;i<n;i++)
    {
        strcpy(t[i].name,s[i].name);
        t[i].p=s[i].p;
        t[i].GS=s[i].GS;
        t[i].GA=s[i].GA;
        t[i].GD=s[i].GD;
        t[i].pts=s[i].pts;
        t[i].len=s[i].len;
    }
    for(i=0;i<n;i++)
    {
        for(k=i+1;k<n;k++)
        {
            if(t[i].pts<t[k].pts)
            {
             temp=t[i];
             t[i]=t[k];
             t[k]=temp;
            }
            else if(t[i].pts==t[k].pts)
            {
                if(t[i].GD<t[k].GD)
                {
                    temp=t[i];
                    t[i]=t[k];
                    t[k]=temp;
                }
                else if(t[i].GD==t[k].GD)
                {
                    if(t[i].GS<t[k].GS)
                    {
                        temp=t[i];
                        t[i]=t[k];
                        t[k]=temp;
                    }
                }
            }
        }
    }
    system("CLS");
    stand=fopen("standings.txt","a");
    SetColor(14);
    printf("The standings at the end of matchday %d is as follows:\n",j+1);
    fprintf(stand,"\nThe standings at the end of matchday %d is as follows:\n",j+1);
    SetColor(15);
    printf("#\tTeam\t\t\tPlayed\tGS\tGA\tGD\tPoints\n");
    fprintf(stand,"#\tTeam\t\t\tPlayed\tGS\tGA\tGD\tPoints\n");
    SetColor(11);
    for(i=0;i<n;i++)
    {
        if(t[i].len<8)
        {
            if(t[i].GD>0)
            {
            printf("%d\t%s\t\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            fprintf(stand,"%d\t%s\t\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            }
            else
            {
            printf("%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            fprintf(stand,"%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            }
        }
        else if(t[i].len<16)
        {
            if(t[i].GD>0)
            {
            printf("%d\t%s\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            fprintf(stand,"%d\t%s\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            }
            else
            {
            printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            fprintf(stand,"%d\t%s\t\t%d\t%d\t%d\t%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            }
        }
        else
        {
            if(t[i].GD>0)
            {
            printf("%d\t%s\t%d\t%d\t%d\t+%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            fprintf(stand,"%d\t%s\t%d\t%d\t%d\t+%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            }
            else
            {
            printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            fprintf(stand,"%d\t%s\t%d\t%d\t%d\t%d\t%d\n",i+1,t[i].name,t[i].p,t[i].GS,t[i].GA,t[i].GD,t[i].pts);
            }
        }
    }
    fclose(stand);
    SetColor(13);
    printf("\nStandings have been recorded.\n");
    printf("You can check the text file standings.txt for viewing the standings at the end of the matchdays at any time.\n");
    SetColor(15);
    }
    if(l%2==0)
    {
    for(i=0;i<n/2;i++)
    {
        if(n%2==0)
        {
            temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
        }
        else
        {
            temp=s[i+1];
            s[i+1]=s[n-1-i];
            s[n-1-i]=temp;
        }
    }
    }
    if(n%2==0)
    {
    for(i=0;i<n-2;i++)
    {
        temp=s[i];
        s[i]=s[i+1];
        s[i+1]=temp;
    }
    }
    else
    {
    for(i=0;i<n-1;i++)
    {
        temp=s[i];
        s[i]=s[i+1];
        s[i+1]=temp;
    }
    }
    j++;
    }
    }
    fclose(rv);
    fclose(rr);
    SetColor(11);
    printf("\nCongratulations %s! You have won the %s.\n",t[0].name,tnmt);
    SetColor(14);
    printf("\t\t\t @       @\n");
    printf("\t\t\t@ @#####@ @\n");
    printf("\t\t\t@  #####  @\n");
    printf("\t\t\t @ ##### @\n");
    printf("\t\t\t  @#####@\n");
    printf("\t\t\t    ### \n");
    printf("\t\t\t     #\n");
    printf("\t\t\t     #\n");
    printf("\t\t\t    ###\n");
    printf("\t\t\t    ###\n");
    SetColor(15);
}
void knockout(int n,int nl,char tnmt[50])
{
    int i,j,k,l,legs,final,a,b,p,r,edit,sread=-1,lf,x,y,mid,end;
    FILE *kt,*kv,*match;
    struct teams s[100],temp;
    char e,random[100];
    srand(time(NULL));
    if(nl==2)
    {
    kv=fopen("knockout variables.txt","rb");
    while(!feof(kv))
    {
    fscanf(kv,"%d%d%d%d%d%d%d%d%d",&legs,&final,&b,&lf,&y,&n,&x,&mid,&end);
    }
    fclose(kv);
    kt=fopen("knockout teams.txt","rb");
    while(!feof(kt))
    {
    fread(&s[++sread],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    if(lf==1)
    goto load1;
    else if(lf==2)
    goto load2;
    }
    match=fopen("matches.txt","w");
    fclose(match);
    end=1;
    x=0;
    mid=0;
    printf("How many times do the teams play each other?\n");
    scanf("%d",&legs);
    printf("How many times do they play each other in the final?\n");
    scanf("%d",&final);
    system("CLS");
    for(i=0;i<n;i++)
    {
        s[i].check=1;
    }
    for(i=0;i<n;i++)
    {
        SetColor(i%5+10);
        printf("Enter the name of team %d:",i+1);
        scanf(" %[^\n]s ",s[i].name);
    }
    system("CLS");
    SetColor(15);
    printf("Would you like to randomize the order of the teams?\n");
    SetColor(14);
    printf("\nPress Y to randomize\n");
    SetColor(13);
    printf("Press any other key to continue without randomizing.\n");
    SetColor(14);
    e=getch();
    if(e=='Y'||e=='y')
    {
    for(i=0;i<n;i++)
    {
        j=(rand()%(n-1))+1;
        strcpy(random,s[i].name);
        strcpy(s[i].name,s[j].name);
        strcpy(s[j].name,random);
    }
    printf("Randomized!!!\n");
    SetColor(14);
    printf("Press any key to continue.\n");
    SetColor(15);
    e=getch();
    }
    for(i=0;i<=6;i++)
    {
        a=pow(2,i);
        if(n<=a)
        break;
    }
    b=a-n;
    for(i=0;i<n;i++)
    {
        s[i].agg=0;
    }
    y=0;
    load1:
    kt=fopen("knockout teams.txt","wb");
    kv=fopen("knockout variables.txt","wb");
    system("CLS");
    if(b!=0)
    printf("The following teams have received bye to the next round:\n");
    for(i=0;i<b;i++)
    {
        SetColor(i%5+10);
        printf("%s\n",s[i].name);
    }
    SetColor(10);
    printf("\n");
    match=fopen("matches.txt","w");
    if(n<=2)
    {
    printf("Final:\n");
    fprintf(match,"Final:\n");
    }
    else if(n<=4)
    {
    printf("Semi Finals:\n");
    fprintf(match,"Semi Finals:\n");
    }
    else if (n<=8)
    {
    printf("Quarter Finals:\n");
    fprintf(match,"Quarter Finals:\n");
    }
    else
    {
    printf("Round 1:\n");
    fprintf(match,"Round 1:\n");
    }
    fclose(match);
    SetColor(15);
    j=1;
    for(i=b;i<(n+b)/2;i++)
    {
        printf("%s VS %s\n",s[i].name,s[n-j].name);
        j++;
    }
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.\n");
    SetColor(11);
    printf("Press any other key to continue\n");
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=1;
     fprintf(kv,"%d%\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",legs,final,b,lf,y,n,x,mid,end);
     fclose(kv);
     exit(0);
    }
    system("CLS");
    if(n==2)
    legs=final;
    for(l=y;l<legs;l++)
    {
    j=0;
    if(l%2!=0&&mid!=1)
    {
        for(i=b;i<(n+b)/2;i++)
        {
            j++;
            temp=s[i];
            s[i]=s[n-j];
            s[n-j]=temp;
        }

    }
    mid=0;
    skippedk1:
    j=0;
    printf("\n");
    SetColor(14);
    match=fopen("matches.txt","a");
    printf("Leg %d\n",l+1);
    fprintf(match,"\nLeg %d:\n",l+1);
    fclose(match);
    SetColor(15);
    for(i=b;i<(n+b)/2;i++)
    {
        j++;
        if(s[i].check==1)
        {
        printf("\nMatch %d:%s VS %s\n",j,s[i].name,s[n-j].name);
        SetColor(12);
        printf("\nPress s to skip the match for now.\n");
        SetColor(14);
        printf("Press any other key to continue.\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        s[i].check=0;
        s[n-j].check=0;
        printf("\nEnter the number of goals scored by %s:",s[i].name);
        scanf("%d",&s[i].goals);
        printf("Enter the number of goals scored by %s:",s[n-j].name);
        scanf("%d",&s[n-j].goals);
        s[i].agg=s[i].agg+s[i].goals;
        s[n-j].agg=s[n-j].agg+s[n-j].goals;
        if(l==legs-1)
        {
        if(s[i].agg<s[n-j].agg)
        {
        temp=s[i];
        s[i]=s[n-j];
        s[n-j]=temp;
        }
        else if(s[i].agg==s[n-j].agg)
        {
            restart:
            SetColor(13);
            printf("\nWho won on penalties?\nEnter 1 for %s\nEnter 2 for %s\n",s[i].name,s[n-j].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            temp=s[i];
            s[i]=s[n-j];
            s[n-j]=temp;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!!!\n");
            SetColor(15);
            goto restart;
            }
        }
        }
        }
        }
    }
    j=0;
    system("CLS");
    SetColor(11);
    printf("\nRemaining matches:\n");
    SetColor(15);
    for(i=b;i<(n+b)/2;i++)
    {
        j++;
        if(s[i].check==1)
        {
            printf("%s VS %s\n",s[i].name,s[n-j].name);
        }
    }
    kt=fopen("knockout teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.\n");
    SetColor(14);
    printf("Press any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=1;
     y=l;
     mid=1;
     fprintf(kv,"%d%\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",legs,final,b,lf,y,n,x,mid,end);
     fclose(kv);
     exit(0);
    }
    for(i=b;i<(n+b)/2;i++)
    {
    if(s[i].check==1)
    goto skippedk1;
    }
    for(i=0;i<n;i++)
    {
        s[i].check=1;
    }
    editresultk1:
    printf("\n");
    j=0;
    for(i=b;i<(n+b)/2;i++)
    {
        j++;
        printf("%s %d-%d %s\n",s[i].name,s[i].goals,s[n-j].goals,s[n-j].name);
    }
    SetColor(11);
    printf("\nWould you like to change any result of the results?\n");
    SetColor(14);
    printf("\nPress Y to change\n");
    SetColor(12);
    printf("Press any other key to continue without changing any of the results.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    j=0;
    SetColor(10);
    printf("\nChoose the match number of the match whose outcome you want to change:\n");
    SetColor(15);
    for(i=b;i<(n+b)/2;i++)
    {
        j++;
        printf("Match %d:%s VS %s\n",j,s[i].name,s[n-j].name);
    }
    scanf("%d",&edit);
    s[b+edit-1].agg=s[b+edit-1].agg-s[b+edit-1].goals;
    s[n-edit].agg=s[n-edit].agg-s[n-edit].goals;
    printf("Match %d:%s VS %s\n",edit,s[b+edit-1].name,s[n-edit].name);
    printf("Enter number of goals scored by %s:",s[b+edit-1].name);
    scanf("%d",&s[b+edit-1].goals);
    printf("Enter number of goals scored by %s:",s[n-edit].name);
    scanf("%d",&s[n-edit].goals);
    s[b+edit-1].agg=s[b+edit-1].agg+s[b+edit-1].goals;
    s[n-edit].agg=s[n-edit].agg+s[n-edit].goals;
    if(l==legs-1)
    {
    if(s[b+edit-1].agg<s[n-edit].agg)
        {
        temp=s[b+edit-1];
        s[b+edit-1]=s[n-edit];
        s[n-edit]=temp;
        }
        else if(s[b+edit-1].agg==s[n-edit].agg)
        {
            erestart:
            printf("Who won on penalties?\nEnter 1 for %s\nEnter 2 for %s\n",s[b+edit-1].name,s[n-edit].name);
            scanf("%d",&p);
            if(p==2)
            {
            temp=s[b+edit-1];
            s[b+edit-1]=s[n-edit];
            s[n-edit]=temp;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            SetColor(15);
            goto erestart;
            }
        }
    }
        goto editresultk1;
    }
    match=fopen("matches.txt","a");
    j=0;
    for(i=b;i<(n+b)/2;i++)
    {
        j++;
        fprintf(match,"%s %d-%d %s\n",s[i].name,s[i].goals,s[n-j].goals,s[n-j].name);
    }
    fclose(match);
    SetColor(13);
    printf("\nThe matches have been recorded.\nYou can check the recorded matches by opening the text file matches.txt.\n");
    SetColor(14);
    printf("\nPress any key to continue.\n");
    SetColor(15);
    e=getch();
    if(l%2!=0&&l!=legs-1)
    {
    j=0;
    for(i=b;i<(n+b)/2;i++)
    {
            j++;
            temp=s[i];
            s[i]=s[n-j];
            s[n-j]=temp;
    }
    }
    kt=fopen("knockout teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.\n");
    SetColor(14);
    printf("Press any other key to continue\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=1;
     y=l+1;
     fprintf(kv,"%d%\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",legs,final,b,lf,y,n,x,mid,end);
     fclose(kv);
     exit(0);
    }
    system("CLS");
    }
    fclose(kv);
    j=0;
    system("CLS");
    SetColor(11);
    match=fopen("matches.txt","a");
    printf("The aggregate scores are:\n");
    fprintf(match,"\nThe aggregate scores are:\n");
    SetColor(15);
    for(i=b;i<(n+b)/2;i++)
    {
        j++;
        printf("%s %d-%d %s\n",s[i].name,s[i].agg,s[n-j].agg,s[n-j].name);
        fprintf(match,"%s %d-%d %s\n",s[i].name,s[i].agg,s[n-j].agg,s[n-j].name);
    }
    fclose(match);
    if(n/2!=1)
    {
        SetColor(11);
    printf("\nThe following teams have advanced to the next round:\n");
    for(i=b;i<(n+b)/2;i++)
    {
    SetColor(i%5+10);
    printf("%s\n",s[i].name);
    }
    }
    n=b+j;
    y=0;
    load2:
    SetColor(15);
    kv=fopen("knockout variables.txt","wb");
    for(k=x;n!=1;k++)
    {
    if(end==1)
    {
    for(i=0;i<n;i++)
    {
        s[i].agg=0;
    }
    }
    SetColor(14);
    printf("\n");
    match=fopen("matches.txt","a");
    if(n==2)
    {
    printf("Final:\n");
    fprintf(match,"\nFinal:\n");
    }
    else if(n==4)
    {
    printf("Semi Finals:\n");
    fprintf(match,"\nSemi Finals:\n");
    }
    else if (n==8)
    {
    printf("Quarter Finals:\n");
    fprintf(match,"\nQuarter Finals:\n");
    }
    else
    {
    printf("Round %d:\n",k+2);
    fprintf(match,"\nRound %d:\n",k+2);
    }
    fclose(match);
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        printf("%s VS %s\n",s[i].name,s[n-1-i].name);
    }
    kt=fopen("knockout teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     x=k;
     fprintf(kv,"%d%\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",legs,final,b,lf,y,n,x,mid,end);
     fclose(kv);
     exit(0);
    }
    if(n==2)
    legs=final;
    for(l=y;l<legs;l++)
    {
    system("CLS");
    if(l%2!=0&&mid!=1)
    {
        for(i=0;i<n/2;i++)
        {
        temp=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=temp;
        }
    }
    mid=0;
    skippedk2:
    printf("\n");
    SetColor(14);
    match=fopen("matches.txt","a");
    printf("Leg %d:\n",l+1);
    fprintf(match,"\nLeg %d:\n",l+1);
    fclose(match);
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        if(s[i].check==1)
        {
        printf("\nMatch %d:%s VS %s\n",i+1,s[i].name,s[n-1-i].name);
        SetColor(12);
        printf("\nPress s to skip the match for now.\n");
        SetColor(14);
        printf("Press any other key to continue.\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        s[i].check=0;
        s[n-1-i].check=0;
        printf("\nEnter the number of goals scored by %s:",s[i].name);
        scanf("%d",&s[i].goals);
        printf("Enter the number of goals scored by %s:",s[n-1-i].name);
        scanf("%d",&s[n-1-i].goals);
        s[i].agg=s[i].agg+s[i].goals;
        s[n-1-i].agg=s[n-1-i].agg+s[n-1-i].goals;
        if(l==legs-1)
        {
        if(s[i].agg<s[n-1-i].agg)
        {
        temp=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=temp;
        }
        else if(s[i].agg==s[n-1-i].agg)
        {
            restart1:
            SetColor(13);
            printf("Who won on penalties?\nEnter 1 for %s\nEnter 2 for %s\n",s[i].name,s[n-1-i].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            goto restart1;
            }
        }
        }
        }
        }
    }
    SetColor(11);
    printf("\nRemaining matches:\n");
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        if(s[i].check==1)
        {
            printf("%s VS %s\n",s[i].name,s[n-1-i].name);
        }
    }
    kt=fopen("knockout teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     y=l;
     mid=1;
     end=0;
     fprintf(kv,"%d%\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",legs,final,b,lf,y,n,x,mid,end);
     fclose(kv);
     exit(0);
    }
    for(i=0;i<n/2;i++)
    {
    if(s[i].check==1)
    goto skippedk2;
    }
    for(i=0;i<n;i++)
    {
        s[i].check=1;
    }
    editresultk2:
    printf("\n");
    for(i=0;i<n/2;i++)
    {
        printf("%s %d-%d %s\n",s[i].name,s[i].goals,s[n-1-i].goals,s[n-1-i].name);
    }
    SetColor(11);
    printf("\nWould you like to change any result of the results?\n");
    SetColor(14);
    printf("Press Y to change the result.\n");
    SetColor(12);
    printf("Press any other key to continue without changing any of the results.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    printf("\nChoose the match number of the match whose outcome you want to change:\n");
    for(i=0;i<n/2;i++)
    {
        printf("Match %d:%s VS %s\n",i+1,s[i].name,s[n-1-i].name);
    }
    scanf("%d",&edit);
    s[edit-1].agg=s[edit-1].agg-s[edit-1].goals;
    s[n-edit].agg=s[n-edit].agg-s[n-edit].goals;
    printf("Match %d:%s VS %s\n",edit,s[edit-1].name,s[n-edit].name);
    printf("Enter number of goals scored by %s:",s[edit-1].name);
    scanf("%d",&s[edit-1].goals);
    printf("Enter number of goals scored by %s:",s[n-edit].name);
    scanf("%d",&s[n-edit].goals);
    s[edit-1].agg=s[edit-1].agg+s[edit-1].goals;
    s[n-edit].agg=s[n-edit].agg+s[n-edit].goals;
    if(l==legs-1)
    {
    if(s[edit-1].agg<s[n-edit].agg)
        {
        temp=s[edit-1];
        s[edit-1]=s[n-edit];
        s[n-edit]=temp;
        }
        else if(s[edit-1].agg==s[n-edit].agg)
        {
            erestart2:
            SetColor(13);
            printf("\nWho won on penalties?\nEnter 1 for %s\nEnter 2 for %s\n",s[edit-1].name,s[n-edit].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            temp=s[edit-1];
            s[edit-1]=s[n-edit];
            s[n-edit]=temp;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            SetColor(15);
            goto erestart2;
            }
        }
    }
        goto editresultk2;
    }
    match=fopen("matches.txt","a");
    for(i=0;i<n/2;i++)
    {
        fprintf(match,"%s %d-%d %s\n",s[i].name,s[i].goals,s[n-1-i].goals,s[n-1-i].name);
    }
    fclose(match);
    SetColor(13);
    printf("\nThe matches have been recorded.\nYou can check the recorded matches by opening the text file matches.txt.\n");
    SetColor(14);
    printf("\nPress any key to continue:\n");
    SetColor(15);
    e=getch();
    if(l%2!=0&&l!=legs-1)
    {
    for(i=0;i<n/2;i++)
    {
            temp=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=temp;
    }
    }
    kt=fopen("knockout teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&s[i],sizeof(struct teams),1,kt);
    }
    fclose(kt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     y=l+1;
     fprintf(kv,"%d%\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",legs,final,b,lf,y,n,x,mid,end);
     fclose(kv);
     exit(0);
    }
    }
    end=1;
    system("CLS");
    SetColor(11);
    match=fopen("matches.txt","a");
    printf("The aggregate scores are:\n");
    fprintf(match,"\nThe aggregate scores are:\n");
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        printf("%s %d-%d %s\n",s[i].name,s[i].agg,s[n-1-i].agg,s[n-1-i].name);
        fprintf(match,"%s %d-%d %s\n",s[i].name,s[i].agg,s[n-1-i].agg,s[n-1-i].name);
    }
    fclose(match);
    if(n/2!=1)
    {
    printf("\nThe following teams have advanced to the next round:\n");
    for(i=0;i<n/2;i++)
    {
        SetColor(i%5+10);
    printf("%s\n",s[i].name);
    }
    }
    SetColor(15);
    n=n/2;
    }
    fclose(kv);
    SetColor(11);
    printf("\nCongratulations %s! You have won the %s.\n",s[0].name,tnmt);
    SetColor(14);
    printf("\t\t\t @       @\n");
    printf("\t\t\t@ @#####@ @\n");
    printf("\t\t\t@  #####  @\n");
    printf("\t\t\t @ ##### @\n");
    printf("\t\t\t  @#####@\n");
    printf("\t\t\t    ### \n");
    printf("\t\t\t     #\n");
    printf("\t\t\t     #\n");
    printf("\t\t\t    ###\n");
    printf("\t\t\t    ###\n");
    SetColor(15);
}
void hybrid(int n,int nl,char tnmt[50])
{
    int h,i,j,k,l,m,p,tpg,ng,sum,min,z,adv,editg,edit,bye,power,legs,final,rem,ko,lf,mid,rc,sread=-1,y,x,end,host,ran;
    FILE *gt,*gv,*lt,*lv,*hv,*stand,*match,*group,*rlt;
    char random[100],e;
    struct general gen[100],swap;
    struct groups a[100],b[100],c[100];
    srand(time(NULL));
    if(nl==2)
    {
    hv=fopen("hybrid variables.txt","rb");
    while(!feof(hv))
    {
    fscanf(hv,"%d%d%d%d%d%d%d%d%d%d",&tpg,&m,&legs,&final,&ng,&min,&adv,&rem,&rc,&ko);
    }
    fclose(hv);
    if(rc==0)
    {
    gv=fopen("group variables.txt","rb");
    while(!feof(gv))
    {
    fscanf(gv,"%d%d%d",&y,&k,&mid);
    }
    fclose(gv);
    gt=fopen("group teams.txt","rb");
    while(!feof(gt))
    {
    fread(&a[++sread],sizeof(struct groups),1,gt);
    }
    fclose(gt);
    goto load1;
    }
    else if(rc==1)
    {
    lv=fopen("latter stage variables.txt","rb");
    while(!feof(lv))
    {
    fscanf(lv,"%d%d%d%d%d%d%d",&bye,&y,&n,&x,&mid,&end,&lf);
    }
    fclose(lv);
    lt=fopen("latter stage teams.txt","rb");
    while(!feof(lt))
    {
    fread(&gen[++sread],sizeof(struct general),1,lt);
    }
    fclose(lt);
    sread=-1;
    rlt=fopen("redraw latter stage teams.txt","rb");
    while(!feof(rlt))
    {
    fread(&c[++sread],sizeof(struct groups),1,rlt);
    }
    fclose(rlt);
    if(lf=2)
    goto load2;
    else if(lf=3)
    goto load3;
    }
    }
    match=fopen("matches.txt","w");
    fclose(match);
    stand=fopen("standings.txt","w");
    fclose(stand);
    rc=0;
    lf=1;
    mid=0;
    k=0;
    y=1;
    end=1;
    teamspergroup:
    SetColor(15);
    printf("Enter the number of teams per group:\n");
    scanf("%d",&tpg);
    printf("How many times do the teams play each other?\n");
    scanf("%d",&m);
    printf("How many times do the teams play each other in the knockout stages?\n");
    scanf("%d",&legs);
    printf("How many times do they play each other in the final?\n");
    scanf("%d",&final);
    system("CLS");
    min=tpg-1;
    if(n%tpg==0)
    {
    ng=n/tpg;
    for(i=0;i<ng;i++)
    {
        a[i].teams=tpg;
    }
    goto input;
    }
    else
    ng=n/tpg+1;
    i=0;
    sum=0;
    while(1)
    {
        sum=sum+tpg;
        if(sum<n)
        a[i].teams=tpg;
        else
        {
        a[i].teams=n-i*tpg;
        break;
        }
        i++;
    }
    if(min-a[ng-1].teams>=(ng-1))
    {
        SetColor(12);
        printf("Almost Even distribution of teams cannot be done with %d teams per group.\nPlease choose a different number",tpg);
        SetColor(15);
        goto teamspergroup;
    }
    i=ng-2;
    j=0;
    while(j<min-a[ng-1].teams)
    {
        a[i].teams=a[i].teams-1;
        i--;
        j++;
    }
    a[ng-1].teams=min;
    input:
    for(i=0;i<n;i++)
    {
        SetColor(i%5+10);
        printf("Enter the name of Team%d:",i+1);
        scanf(" %[^\n]s ",gen[i].name);
    }
    system("CLS");
    SetColor(11);
    rerandomize:
    printf("Would you like to randomize the order of the teams?\n");
    SetColor(14);
    printf("Press Y to randomize.\n");
    SetColor(12);
    printf("Press any other key to continue without randomizing.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    printf("Choose:\n");
    SetColor(14);
    printf("1.All the teams will be randomized.\n");
    SetColor(11);
    printf("2.All the teams apart from the host will be randomized.\n(The first team you had entered is regarded as the host.)\n");
    SetColor(15);
    scanf("%d",&host);
    if(host==1)
    ran=0;
    else if(host==2)
    ran=1;
    else
    {
        SetColor(12);
        printf("Error!!!\n");
        SetColor(15);
        goto rerandomize;
    }
    for(i=ran;i<n;i++)
    {
        j=(rand()%(n-1))+1;
        strcpy(random,gen[i].name);
        strcpy(gen[i].name,gen[j].name);
        strcpy(gen[j].name,random);
    }
    SetColor(10);
    printf("Randomized!\n");
    SetColor(15);
    }
    system("CLS");
    z=0;
    for(i=0;i<ng;i++)
    {
        for(j=0;j<a[i].teams;j++)
        {
            strcpy(a[i].grp[j].name,gen[z].name);
            z++;
        }
    }

    for(j=0;j<ng;j++)
    {
        for(i=0;i<a[j].teams;i++)
        {
        a[j].grp[i].pts=0;
        a[j].grp[i].GS=0;
        a[j].grp[i].GA=0;
        a[j].grp[i].GD=0;
        a[j].grp[i].p=0;
        a[j].grp[i].len=strlen(a[j].grp[i].name);
        }
    }
    group=fopen("groups.txt","w");
    for(j=0;j<ng;j++)
    {
        printf("Group %d:\t\t",j+1);
        fprintf(group,"Group %d:\t\t",j+1);
    }
    for(j=0;j<tpg;j++)
    {
        printf("\n");
        fprintf(group,"\n");
        for(i=0;i<ng;i++)
        {
        if(a[i].grp[j].len<8)
        {
        printf("%s\t\t\t",a[i].grp[j].name);
        fprintf(group,"%s\t\t\t",a[i].grp[j].name);
        }
        else if(a[i].grp[j].len<16)
        {
        printf("%s\t\t",a[i].grp[j].name);
        fprintf(group,"%s\t\t",a[i].grp[j].name);
        }
        else
        {
        printf("%s\t",a[i].grp[j].name);
        fprintf(group,"%s\t",a[i].grp[j].name);
        }
        }
    }
    SetColor(13);
    printf("\n\nThe groups have been recorded.\nYou can check the groups by opening the text file groups.txt.\n");
    SetColor(15);
    printf("\nHow many teams from each group will advance to the next round?\n");
    scanf("%d",&adv);
    for(i=0;i<=6;i++)
    {
        power=pow(2,i);
        if((adv*ng)<=power)
        break;
    }
    rem=power-(adv*ng);
    if(rem!=0)
    {
    choose:
    SetColor(11);
    printf("Choose:\n");
    SetColor(15);
    printf("1)%d teams will qualify for the next round and some of the best placed teams will receive bye to the round after that.\n",adv*ng);
    SetColor(14);
    printf("2)%d next best placed teams out of %d groups will qualify for the next round along with the best %d teams of their groups\nand all the teams will take part in the 1st knockout round.\n",rem,ng,adv);
    SetColor(15);
    scanf("%d",&ko);
    if(ko!=1&&ko!=2)
    {
    SetColor(12);
    printf("Error!\n");
    SetColor(15);
    goto choose;
    }
    }
    for(i=0;i<ng;i++)
    {
        for(j=0;j<a[i].teams;j++)
        {
            a[i].check[j]=1;
        }
    }
    printf("\n");
    if(tpg%2!=0)
    tpg=tpg+1;
    hv=fopen("hybrid variables.txt","wb");
    fprintf(hv,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",tpg,m,legs,final,ng,min,adv,rem,rc,ko);
    fclose(hv);
    gt=fopen("group teams.txt","wb");
    for(i=0;i<ng;i++)
    {
    fwrite(&a[i],sizeof(struct groups),1,gt);
    }
    fclose(gt);
    SetColor(10);
    printf("\nData has been saved.\n");
    SetColor(15);
    gv=fopen("group variables.txt","wb");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     fprintf(gv,"%d%\n%d\n%d",y,k,mid);
     fclose(gv);
     exit(0);
    }
    fclose(gv);
    load1:
    system("CLS");
    //
    gv=fopen("group variables.txt","wb");
    for(l=y;l<=m;l++)
    {
    while(k<(l*tpg)-l)
    {
    gt=fopen("group teams.txt","wb");
    for(i=0;i<ng;i++)
    {
    fwrite(&a[i],sizeof(struct groups),1,gt);
    }
    fclose(gt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(15);
    if(l%2==0 && mid!=1)
    {
    for(i=0;i<ng;i++)
        {
            if(a[i].teams%2==0)
            {
            for(j=0;j<a[i].teams/2;j++)
            {
            a[i].temp=a[i].grp[j];
            a[i].grp[j]=a[i].grp[a[i].teams-1-j];
            a[i].grp[a[i].teams-1-j]=a[i].temp;
            }
            }
            else
            {
            for(j=0;j<a[i].teams/2;j++)
            {
            a[i].temp=a[i].grp[j+1];
            a[i].grp[j+1]=a[i].grp[a[i].teams-1-j];
            a[i].grp[a[i].teams-1-j]=a[i].temp;
            }
            }
        }
    }
    mid=0;
    match=fopen("matches.txt","a");
    printf("\nMatchday %d:\n",k+1);
    fprintf(match,"\nMatchday %d:\n",k+1);
    fclose(match);
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        printf("\n");
        printf("Group %d:\n",i+1);
        for(j=0;j<a[i].teams/2;j++)
        {
            if(a[i].teams%2==0)
            printf("%s VS %s\n",a[i].grp[j].name,a[i].grp[a[i].teams-1-j].name);
            else
            printf("%s VS %s\n",a[i].grp[j+1].name,a[i].grp[a[i].teams-1-j].name);
        }
    }
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(10);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     y=l;
     fprintf(gv,"%d%\n%d\n%d",y,k,mid);
     fclose(gv);
     exit(0);
    }
    skippedg1:
    for(i=0;i<ng;i++)
    {
    printf("\nGroup %d:\n",i+1);
    if(a[i].teams%2==0)
    {
    if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
    break;
    for(j=0;j<a[i].teams/2;j++)
    {
        if(a[i].check[j]==1)
        {
        printf("\n");
        printf("Match %d:%s VS %s\n",j+1,a[i].grp[j].name,a[i].grp[a[i].teams-1-j].name);
        SetColor(12);
        printf("\nPress s to skip the match for now.\n");
        SetColor(10);
        printf("Press any other key to continue.\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        a[i].check[j]=0;
        printf("\nEnter number of goals scored by %s:",a[i].grp[j].name);
        scanf("%d",&a[i].grp[j].g);
        printf("Enter number of goals scored by %s:",a[i].grp[a[i].teams-1-j].name);
        scanf("%d",&a[i].grp[a[i].teams-1-j].g);
        }
        }
    }
    }
    else
    {
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].check[j+1]==1)
        {
        printf("\n");
        printf("Match %d:%s VS %s\n",j+1,a[i].grp[j+1].name,a[i].grp[a[i].teams-1-j].name);
        SetColor(12);
        printf("\nPress s to skip the match for now\n");
        SetColor(10);
        printf("Press any other key to continue:\n\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        a[i].check[j+1]=0;
        printf("Enter number of goals scored by %s:",a[i].grp[j+1].name);
        scanf("%d",&a[i].grp[j+1].g);
        printf("Enter number of goals scored by %s:",a[i].grp[a[i].teams-1-j].name);
        scanf("%d",&a[i].grp[a[i].teams-1-j].g);
        }
        }
        }
    }
    }
    system("CLS");
    SetColor(11);
    printf("\nRemaining matches:\n");
    SetColor(15);
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        printf("\n");
        printf("Group %d:\n",i+1);
        if(a[i].teams%2==0)
        {
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].check[j]==1)
        {
            printf("%s VS %s\n",a[i].grp[j].name,a[i].grp[a[i].teams-1-j].name);
        }
        }
        }
        else
        {
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].check[j+1]==1)
        {
        printf("%s VS %s\n",a[i].grp[j+1].name,a[i].grp[a[i].teams-1-j].name);
        }
        }
        }
    }
    gt=fopen("group teams.txt","wb");
    for(i=0;i<ng;i++)
    {
    fwrite(&a[i],sizeof(struct groups),1,gt);
    }
    fclose(gt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     y=l;
     mid=1;
     fprintf(gv,"%d%\n%d\n%d",y,k,mid);
     fclose(gv);
     exit(0);
    }
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        if(a[i].teams%2==0)
        {
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].check[j]==1)
        {
        goto skippedg1;
        }
        }
        }
        else
        {
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].check[j+1]==1)
        {
        goto skippedg1;
        }
        }
        }
    }
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        for(j=0;j<a[i].teams;j++)
        {
        a[i].check[j]=1;
        }
    }
    printf("\n");
    editresultg1:
    printf("\n");
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        printf("Group %d:\n",i+1);
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].teams%2==0)
        printf("%s %d-%d %s\n",a[i].grp[j].name,a[i].grp[j].g,a[i].grp[a[i].teams-1-j].g,a[i].grp[a[i].teams-1-j].name);
        else
        printf("%s %d-%d %s\n",a[i].grp[j+1].name,a[i].grp[j+1].g,a[i].grp[a[i].teams-1-j].g,a[i].grp[a[i].teams-1-j].name);
        }
    }
    SetColor(11);
    printf("\nWould you like to change any result of Matchday %d?\n",k+1);
    SetColor(12);
    printf("\nPress Y to change the result.\n");
    SetColor(10);
    printf("Press any other key to continue without editing\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    printf("\nChoose the group number and then the match number of the match whose outcome you want to change:\n");
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        printf("Group %d:\n",i+1);
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].teams%2==0)
        printf("Match %d:%s VS %s\n",j+1,a[i].grp[j].name,a[i].grp[a[i].teams-1-j].name);
        else
        printf("Match %d:%s VS %s\n",j+1,a[i].grp[j+1].name,a[i].grp[a[i].teams-1-j].name);
        }
    }
    printf("Group:");
    scanf("%d",&editg);
    printf("Match:");
    scanf("%d",&edit);
    printf("Group %d:\n",editg);
    if(a[editg-1].teams%2==0)
    {
    printf("Match %d:%s VS %s\n",edit,a[editg-1].grp[edit-1].name,a[editg-1].grp[a[editg-1].teams-edit].name);
    printf("Enter number of goals scored by %s:",a[editg-1].grp[edit-1].name);
    scanf("%d",&a[editg-1].grp[edit-1].g);
    }
    else
    {
    printf("Match %d:%s VS %s\n",edit,a[editg-1].grp[edit].name,a[editg-1].grp[a[editg-1].teams-edit].name);
    printf("Enter number of goals scored by %s:",a[editg-1].grp[edit].name);
    scanf("%d",&a[editg-1].grp[edit].g);
    }
    printf("Enter number of goals scored by %s:",a[editg-1].grp[a[editg-1].teams-edit].name);
    scanf("%d",&a[editg-1].grp[a[editg-1].teams-edit].g);
    goto editresultg1;
    }
    match=fopen("matches.txt","a");
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        fprintf(match,"Group %d:\n",i+1);
        for(j=0;j<a[i].teams/2;j++)
        {
        if(a[i].teams%2==0)
        fprintf(match,"%s %d-%d %s\n",a[i].grp[j].name,a[i].grp[j].g,a[i].grp[a[i].teams-1-j].g,a[i].grp[a[i].teams-1-j].name);
        else
        fprintf(match,"%s %d-%d %s\n",a[i].grp[j+1].name,a[i].grp[j+1].g,a[i].grp[a[i].teams-1-j].g,a[i].grp[a[i].teams-1-j].name);
        }
    }
    fclose(match);
    SetColor(13);
    printf("\nThe matches have been recorded.\nYou can check the recorded matches by opening the text file matches.txt.\n");
    SetColor(14);
    printf("\nPress any key to continue.\n");
    SetColor(15);
    e=getch();
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        if(a[i].teams%2==0)
        {
        for(j=0;j<a[i].teams;j++)
        {
        a[i].grp[j].p=a[i].grp[j].p+1;
        a[i].grp[j].GS=a[i].grp[j].GS+a[i].grp[j].g;
        a[i].grp[j].GA=a[i].grp[j].GA+a[i].grp[a[i].teams-1-j].g;
        a[i].grp[j].GD=a[i].grp[j].GS-a[i].grp[j].GA;
        if(a[i].grp[j].g>a[i].grp[a[i].teams-1-j].g)
        a[i].grp[j].pts=a[i].grp[j].pts+3;
        else if(a[i].grp[j].g==a[i].grp[a[i].teams-1-j].g)
        a[i].grp[j].pts=a[i].grp[j].pts+1;
        else
        a[i].grp[j].pts=a[i].grp[j].pts;
        }
        }
        else
        {
        for(j=0;j<a[i].teams;j++)
        {
        a[i].grp[j+1].p=a[i].grp[j+1].p+1;
        a[i].grp[j+1].GS=a[i].grp[j+1].GS+a[i].grp[j+1].g;
        a[i].grp[j+1].GA=a[i].grp[j+1].GA+a[i].grp[a[i].teams-1-j].g;
        a[i].grp[j+1].GD=a[i].grp[j+1].GS-a[i].grp[j+1].GA;
        if(a[i].grp[j+1].g>a[i].grp[a[i].teams-1-j].g)
        a[i].grp[j+1].pts=a[i].grp[j+1].pts+3;
        else if(a[i].grp[j+1].g==a[i].grp[a[i].teams-1-j].g)
        a[i].grp[j+1].pts=a[i].grp[j+1].pts+1;
        else
        a[i].grp[j+1].pts=a[i].grp[j+1].pts;
        }
        }
    }
    {
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        b[i]=a[i];
    }
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        for(j=0;j<b[i].teams;j++)
        {
        for(h=j+1;h<b[i].teams;h++)
        {
            if(b[i].grp[j].pts<b[i].grp[h].pts)
            {
             b[i].temp=b[i].grp[j];
             b[i].grp[j]=b[i].grp[h];
             b[i].grp[h]=b[i].temp;
            }
            else if(b[i].grp[j].pts==b[i].grp[h].pts)
            {
                if(b[i].grp[j].GD<b[i].grp[h].GD)
                {
                b[i].temp=b[i].grp[j];
                b[i].grp[j]=b[i].grp[h];
                b[i].grp[h]=b[i].temp;
                }
                else if(b[i].grp[j].GD==b[i].grp[h].GD)
                {
                    if(b[i].grp[j].GS<b[i].grp[h].GS)
                    {
                    b[i].temp=b[i].grp[j];
                    b[i].grp[j]=b[i].grp[h];
                    b[i].grp[h]=b[i].temp;
                    }
                }
            }
        }
        }
    }
    system("CLS");
    stand=fopen("standings.txt","a");
    printf("The standings at the end of matchday %d is as follows:\n",k+1);
    fprintf(stand,"\nThe standings at the end of matchday %d is as follows:\n",k+1);
    for(i=0;i<ng;i++)
    {
    SetColor(10);
    printf("Group %d:\n",i+1);
    fprintf(stand,"Group %d:\n",i+1);
    SetColor(11);
    printf("#\tTeam\t\t\tPlayed\tGS\tGA\tGD\tPoints\n");
    fprintf(stand,"#\tTeam\t\t\tPlayed\tGS\tGA\tGD\tPoints\n");
    SetColor(15);
    for(j=0;j<a[i].teams;j++)
    {
        if(b[i].grp[j].len<8)
        {
            if(b[i].grp[j].GD>0)
            {
            printf("%d\t%s\t\t\t%d\t%d\t%d\t+%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t\t%d\t%d\t%d\t+%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
            else
            {
            printf("%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
        }
        else if(b[i].grp[j].len<16)
        {
            if(b[i].grp[j].GD>0)
            {
            printf("%d\t%s\t\t%d\t%d\t%d\t+%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t%d\t%d\t%d\t+%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
            else
            {
            printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t%d\t%d\t%d\t%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
        }
        else
        {
            if(b[i].grp[j].GD>0)
            {
            printf("%d\t%s\t%d\t%d\t%d\t+%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t%d\t%d\t%d\t+%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
            else
            {
            printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t%d\t%d\t%d\t%d\t%d\n",j+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
        }
    }
    }
    fclose(stand);
    SetColor(13);
    printf("\nStandings have been recorded.\n");
    printf("You can check the text file standings.txt for checking the standings at the end of matchdays at any time.\n");
    SetColor(15);
    }
    if(l%2==0)
    {
    for(i=0;i<ng;i++)
        {
            if(a[i].teams%2==0)
            {
            for(j=0;j<a[i].teams/2;j++)
            {
            a[i].temp=a[i].grp[j];
            a[i].grp[j]=a[i].grp[a[i].teams-1-j];
            a[i].grp[a[i].teams-1-j]=a[i].temp;
            }
            }
            else
            {
            for(j=0;j<a[i].teams/2;j++)
            {
            a[i].temp=a[i].grp[j+1];
            a[i].grp[j+1]=a[i].grp[a[i].teams-1-j];
            a[i].grp[a[i].teams-1-j]=a[i].temp;
            }
            }
        }
    }
    for(i=0;i<ng;i++)
    {
        if(a[i].teams%2==0&a[i].teams-1<=(k%(tpg-1)))
        break;
        if(a[i].teams%2==0)
        {
        for(j=0;j<a[i].teams-2;j++)
        {
        a[i].temp=a[i].grp[j];
        a[i].grp[j]=a[i].grp[j+1];
        a[i].grp[j+1]=a[i].temp;
        }
        }
        else
        {
        for(j=0;j<a[i].teams-1;j++)
        {
        a[i].temp=a[i].grp[j];
        a[i].grp[j]=a[i].grp[j+1];
        a[i].grp[j+1]=a[i].temp;
        }
        }
    }
    k++;
    }
    }
    fclose(gv);
    if(ko==2)
    {
    j=adv;
    for(i=0;i<ng;i++)
    {

        for(h=i+1;h<ng;h++)
        {
            if(b[h].teams==adv)
            break;
            if(b[i].grp[j].pts<b[h].grp[j].pts)
            {
             b[i].temp=b[i].grp[j];
             b[i].grp[j]=b[h].grp[j];
             b[h].grp[j]=b[i].temp;
            }
            else if(b[i].grp[j].pts==b[h].grp[j].pts)
            {
                if(b[i].grp[j].GD<b[h].grp[j].GD)
                {
                b[i].temp=b[i].grp[j];
                b[i].grp[j]=b[h].grp[j];
                b[h].grp[j]=b[i].temp;
                }
                else if(b[i].grp[j].GD==b[h].grp[j].GD)
                {
                    if(b[i].grp[j].GS<b[h].grp[j].GS)
                    {
                    b[i].temp=b[i].grp[j];
                    b[i].grp[j]=b[h].grp[j];
                    b[h].grp[j]=b[i].temp;
                    }
                }
            }
        }
    }
    stand=fopen("standings.txt","a");
    printf("\nRanking of the next best teams:\n");
    fprintf(stand,"\nRanking of the next best teams:\n");
    SetColor(11);
    printf("#\tTeam\t\t\tPlayed\tGS\tGA\tGD\tPoints\n");
    fprintf(stand,"#\tTeam\t\t\tPlayed\tGS\tGA\tGD\tPoints\n");
    SetColor(15);
    j=adv;
    for(i=0;i<ng;i++)
    {
        if(a[i].teams==adv)
        break;
        if(b[i].grp[j].len<8)
        {
            if(b[i].grp[j].GD>0)
            {
            printf("%d\t%s\t\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
            else
            {
            printf("%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
        }
        else if(b[i].grp[j].len<16)
        {
            if(b[i].grp[j].GD>0)
            {
            printf("%d\t%s\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t%d\t%d\t%d\t+%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
            else
            {
            printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
        }
        else
        {
            if(b[i].grp[j].GD>0)
            {
            printf("%d\t%s\t%d\t%d\t%d\t+%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t%d\t%d\t%d\t+%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
            else
            {
            printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            fprintf(stand,"%d\t%s\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i].grp[j].name,b[i].grp[j].p,b[i].grp[j].GS,b[i].grp[j].GA,b[i].grp[j].GD,b[i].grp[j].pts);
            }
        }
    }
    fclose(stand);
    SetColor(13);
    printf("\nThe ranking of the next best placed teams have been recorded.\nYou can see the ranking by opening the file standings.txt.\n");
    }
    SetColor(11);
    printf("\nThe following teams have advanced to the next round:\n");
    SetColor(15);
    for(i=0;i<ng;i++)
    {
        printf("Group %d:\n",i+1);
        for(j=0;j<adv;j++)
        {
            SetColor(j%5+10);
            printf("%s\n",b[i].grp[j].name);
        }
        SetColor(15);
    }
    if(ko==2)
    {
    SetColor(11);
    printf("\nThe following teams have advanced to the next round as the next best teams:\n");
    SetColor(15);
    j=adv;
    for(i=0;i<rem;i++)
    {
        SetColor(i%5+10);
        printf("%s\n",b[i].grp[j].name);
    }
    }
    SetColor(15);
    rc=1;
    hv=fopen("hybrid variables.txt","wb");
    fprintf(hv,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",tpg,m,legs,final,ng,min,adv,rem,rc,ko);
    fclose(hv);
    //knockout
    y=0;
    x=0;
    mid=0;
    end=1;
    if(ko==2)
    n=adv*ng+rem;
    else
    n=adv*ng;
    for(j=0;j<adv;j++)
    {
        for(i=0;i<ng;i++)
        {
            c[j].grp[i]=b[i].grp[j];
        }
    }
    if(ko==2)
    {
    j=adv;
    for(i=0;i<rem;i++)
    {
        c[j].grp[i]=b[i].grp[j];
    }
    }
    redraw:
    if(ng!=1)
    {
    for(j=0;j<adv;j++)
    {
        for(i=0;i<ng;i++)
        {
        k=(rand()%(ng-1))+1;
        c[j].temp=c[j].grp[i];
        c[j].grp[i]=c[j].grp[k];
        c[j].grp[k]=c[j].temp;
        }
    }
    }
    if(ko==2&&rem!=1)
    {
    j=adv;
        for(i=0;i<rem;i++)
        {
        k=(rand()%(rem-1))+1;
        c[j].temp=c[j].grp[i];
        c[j].grp[i]=c[j].grp[k];
        c[j].grp[k]=c[j].temp;
        }
    }
    k=0;
    for(j=0;j<adv;j++)
    {
        for(i=0;i<ng;i++)
            {
                strcpy(gen[k].name,c[j].grp[i].name);
                k++;
            }
    }
    if(ko==2)
    {
    j=adv;
    for(i=0;i<rem;i++)
        {
        strcpy(gen[k].name,c[j].grp[i].name);
        k++;
        }
    }
    for(i=0;i<n;i++)
    {
        gen[i].check=1;
    }
    for(i=0;i<=6;i++)
    {
        power=pow(2,i);
        if(n<=power)
        break;
    }
    bye=power-n;
    for(i=0;i<n;i++)
    {
        gen[i].agg=0;
    }
    load2:
    lv=fopen("latter stage variables.txt","wb");
    lt=fopen("latter stage teams.txt","wb");
    rlt=fopen("redraw latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    fwrite(&c[i],sizeof(struct groups),1,rlt);
    }
    fclose(lt);
    fclose(rlt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    if(bye!=0)
    printf("The following teams have received bye to the next round:\n");
    for(i=0;i<bye;i++)
    {
        SetColor(i%5+10);
        printf("%s\n",gen[i].name);
    }
    SetColor(15);
    system("CLS");
    printf("\n");
    match=fopen("matches.txt","a");
    fprintf(match,"\nKnockout Stage:\n");
    if(n<=2)
    {
    printf("Final:\n");
    fprintf(match,"\nFinal:\n");
    }
    else if(n<=4)
    {
    printf("Semi Finals:\n");
    fprintf(match,"\nSemi Finals:\n");
    }
    else if (n<=8)
    {
    printf("Quarter Finals:\n");
    fprintf(match,"\nQuarter Finals:\n");
    }
    else
    {
    printf("Round 2:\n");
    fprintf(match,"\nRound 2:\n");
    }
    fclose(match);
    SetColor(15);
    j=1;
    for(i=bye;i<(n+bye)/2;i++)
    {
        printf("%s VS %s\n",gen[i].name,gen[n-j].name);
        j++;
    }
    SetColor(12);
    printf("Press Y to redraw the matches.");
    SetColor(10);
    printf("\nPress any other key to continue without redrawing.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    fclose(lv);
    goto redraw;
    }
    lt=fopen("latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    }
    fclose(lt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    if(n==2)
    legs=final;
    for(l=y;l<legs;l++)
    {
    j=0;
    if(l%2!=0&&mid!=1)
    {
        for(i=bye;i<(n+bye)/2;i++)
        {
            j++;
            swap=gen[i];
            gen[i]=gen[n-j];
            gen[n-j]=swap;
        }

    }
    mid=0;
    skippedk1:
    j=0;
    system("CLS");
    printf("\n");
    match=fopen("matches.txt","a");
    SetColor(14);
    printf("Leg %d:\n",l+1);
    fprintf(match,"\nLeg %d:\n",l+1);
    fclose(match);
    SetColor(15);
    for(i=bye;i<(n+bye)/2;i++)
    {
        j++;
        if(gen[i].check==1)
        {
        printf("\nMatch %d:%s VS %s\n",j,gen[i].name,gen[n-j].name);
        SetColor(12);
        printf("\nPress s to skip the match for now\n");
        SetColor(10);
        printf("Press any other key to continue:\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        gen[i].check=0;
        gen[n-j].check=0;
        printf("\nEnter the number of goals scored by %s:",gen[i].name);
        scanf("%d",&gen[i].goals);
        printf("Enter the number of goals scored by %s:",gen[n-j].name);
        scanf("%d",&gen[n-j].goals);
        gen[i].agg=gen[i].agg+gen[i].goals;
        gen[n-j].agg=gen[n-j].agg+gen[n-j].goals;
        if(l==legs-1)
        {
        if(gen[i].agg<gen[n-j].agg)
        {
        swap=gen[i];
        gen[i]=gen[n-j];
        gen[n-j]=swap;
        }
        else if(gen[i].agg==gen[n-j].agg)
        {
            restart:
            SetColor(11);
            printf("Who won on penalties?");
            SetColor(10);
            printf("\nEnter 1 for %s",gen[i].name);
            SetColor(14);
            printf("\nEnter 2 for %s\n",gen[n-j].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            swap=gen[i];
            gen[i]=gen[n-j];
            gen[n-j]=swap;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            SetColor(15);
            goto restart;
            }
        }
        }
        }
        }
    }
    j=0;
    system("CLS");
    SetColor(11);
    printf("\nRemaining matches:\n");
    SetColor(15);
    for(i=bye;i<(n+bye)/2;i++)
    {
        j++;
        if(gen[i].check==1)
        {
            printf("%s VS %s\n",gen[i].name,gen[n-j].name);
        }
    }
    lt=fopen("latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    }
    fclose(lt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(10);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     y=l;
     mid=1;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    for(i=bye;i<(n+bye)/2;i++)
    {
    if(gen[i].check==1)
    goto skippedk1;
    }
    for(i=0;i<n;i++)
    {
        gen[i].check=1;
    }
    editresultk1:
    printf("\n");
    j=0;
    for(i=bye;i<(n+bye)/2;i++)
    {
        j++;
        printf("%s %d-%d %s\n",gen[i].name,gen[i].goals,gen[n-j].goals,gen[n-j].name);
    }
    SetColor(11);
    printf("\nWould you like to change any result of the results?");
    SetColor(14);
    printf("\nPress Y to change.\n");
    SetColor(10);
    printf("Press any other key to continue without editing.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    j=0;
    printf("\nChoose the match number of the match whose outcome you want to change:\n");
    SetColor(15);
    for(i=bye;i<(n+bye)/2;i++)
    {
        j++;
        printf("Match %d:%s VS %s\n",j,gen[i].name,gen[n-j].name);
    }
    scanf("%d",&edit);
    gen[bye+edit-1].agg=gen[bye+edit-1].agg-gen[bye+edit-1].goals;
    gen[n-edit].agg=gen[n-edit].agg-gen[n-edit].goals;
    printf("Match %d:%s VS %s\n",edit,gen[bye+edit-1].name,gen[n-edit].name);
    printf("Enter number of goals scored by %s:",gen[bye+edit-1].name);
    scanf("%d",&gen[bye+edit-1].goals);
    printf("Enter number of goals scored by %s:",gen[n-edit].name);
    scanf("%d",&gen[n-edit].goals);
    gen[bye+edit-1].agg=gen[bye+edit-1].agg+gen[bye+edit-1].goals;
    gen[n-edit].agg=gen[n-edit].agg+gen[n-edit].goals;
    if(l==legs-1)
    {
    if(gen[bye+edit-1].agg<gen[n-edit].agg)
        {
        swap=gen[bye+edit-1];
        gen[bye+edit-1]=gen[n-edit];
        gen[n-edit]=swap;
        }
        else if(gen[bye+edit-1].agg==gen[n-edit].agg)
        {
            erestart:
            SetColor(11);
            printf("\nWho won on penalties?");
            SetColor(10);
            printf("\nEnter 1 for %s",gen[bye+edit-1].name);
            SetColor(14);
            printf("Enter 2 for %s\n",gen[n-edit].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            swap=gen[bye+edit-1];
            gen[bye+edit-1]=gen[n-edit];
            gen[n-edit]=swap;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            SetColor(15);
            goto erestart;
            }
        }
    }
        goto editresultk1;
    }
    match=fopen("matches.txt","a");
    j=0;
    for(i=bye;i<(n+bye)/2;i++)
    {
        j++;
        fprintf(match,"%s %d-%d %s\n",gen[i].name,gen[i].goals,gen[n-j].goals,gen[n-j].name);
    }
    fclose(match);
    SetColor(13);
    printf("\nThe matches have been recorded.\nYou can check the recorded matches by opening the text file matches.txt.\n");
    SetColor(14);
    printf("\nPress any key to continue.\n");
    SetColor(15);
    e=getch();
    if(l%2!=0&&l!=legs-1)
    {
    j=0;
    for(i=bye;i<(n+bye)/2;i++)
    {
            j++;
            swap=gen[i];
            gen[i]=gen[n-j];
            gen[n-j]=swap;
    }
    }
    lt=fopen("latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    }
    fclose(lt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=2;
     y=l+1;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    }
    fclose(lv);
    j=0;
    system("CLS");
    SetColor(11);
    match=fopen("matches.txt","a");
    printf("The aggregate scores are:\n");
    fprintf(match,"\nThe aggregate scores are:\n");
    SetColor(15);
    for(i=bye;i<(n+bye)/2;i++)
    {
        j++;
        printf("%s %d-%d %s\n",gen[i].name,gen[i].agg,gen[n-j].agg,gen[n-j].name);
        fprintf(match,"%s %d-%d %s\n",gen[i].name,gen[i].agg,gen[n-j].agg,gen[n-j].name);
    }
    fclose(match);
    if(n/2!=1)
    {
    SetColor(11);
    printf("\nThe following teams have advanced to the next round:\n");
    for(i=bye;i<(n+bye)/2;i++)
    {
    SetColor(i%5+10);
    printf("%s\n",gen[i].name);
    }
    }
    SetColor(15);
    n=bye+j;
    y=0;
    load3:
    lv=fopen("latter stage variables.txt","wb");
    for(k=x;n!=1;k++)
    {
    if(end==1)
    {
    for(i=0;i<n;i++)
    {
        gen[i].agg=0;
    }
    }
    printf("\n");
    SetColor(11);
    match=fopen("matches.txt","a");
    if(n==2)
    {
    printf("Final:\n");
    fprintf(match,"\nFinal:\n");
    }
    else if(n==4)
    {
    printf("Semi Finals:\n");
    fprintf(match,"\nSemi Finals:\n");
    }
    else if (n==8)
    {
    printf("Quarter Finals:\n");
    fprintf(match,"\nQuarter Finals:\n");
    }
    else
    {
    printf("Round %d:\n",k+3);
    fprintf(match,"\nRound %d:\n",k+3);
    }
    fclose(match);
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        printf("%s VS %s\n",gen[i].name,gen[n-1-i].name);
    }
    lt=fopen("latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    }
    fclose(lt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue.\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=3;
     x=k;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    if(n==2)
    legs=final;
    for(l=0;l<legs;l++)
    {
    if(l%2!=0&&mid!=1)
    {
        for(i=0;i<n/2;i++)
        {
        swap=gen[i];
        gen[i]=gen[n-1-i];
        gen[n-1-i]=swap;
        }
    }
    mid=0;
    skippedk2:
    printf("\n");
    match=fopen("matches.txt","a");
    SetColor(14);
    printf("Leg %d:\n",l+1);
    fprintf(match,"\nLeg %d:\n",l+1);
    fclose(match);
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        if(gen[i].check==1)
        {
        printf("\nMatch %d:%s VS %s\n",i+1,gen[i].name,gen[n-1-i].name);
        SetColor(12);
        printf("\nPress s to skip the match for now.\n");
        SetColor(10);
        printf("Press any other key to continue.\n");
        SetColor(15);
        e=getch();
        if(e!='S'&&e!='s')
        {
        gen[i].check=0;
        gen[n-1-i].check=0;
        printf("\nEnter the number of goals scored by %s:",gen[i].name);
        scanf("%d",&gen[i].goals);
        printf("Enter the number of goals scored by %s:",gen[n-1-i].name);
        scanf("%d",&gen[n-1-i].goals);
        gen[i].agg=gen[i].agg+gen[i].goals;
        gen[n-1-i].agg=gen[n-1-i].agg+gen[n-1-i].goals;
        if(l==legs-1)
        {
        if(gen[i].agg<gen[n-1-i].agg)
        {
        swap=gen[i];
        gen[i]=gen[n-1-i];
        gen[n-1-i]=swap;
        }
        else if(gen[i].agg==gen[n-1-i].agg)
        {
            restart1:
            SetColor(11);
            printf("Who won on penalties?");
            SetColor(13);
            printf("\nEnter 1 for %s",gen[i].name);
            SetColor(14);
            printf("\nEnter 2 for %s\n",gen[n-1-i].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            swap=gen[i];
            gen[i]=gen[n-1-i];
            gen[n-1-i]=swap;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            goto restart1;
            }
        }
        }
        }
        }
    }
    system("CLS");
    SetColor(11);
    printf("\nRemaining matches:\n");
    SetColor(15);
    for(i=0;i<n/2;i++)
    {
        if(gen[i].check==1)
        {
            printf("%s VS %s\n",gen[i].name,gen[n-1-i].name);
        }
    }
    lt=fopen("latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    }
    fclose(lt);
    SetColor(10);
    printf("\nData has been saved.\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=3;
     y=l;
     mid=1;
     end=0;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    for(i=0;i<n/2;i++)
    {
    if(gen[i].check==1)
    goto skippedk2;
    }
    for(i=0;i<n;i++)
    {
        gen[i].check=1;
    }
    editresultk2:
    printf("\n");
    for(i=0;i<n/2;i++)
    {
        printf("%s %d-%d %s\n",gen[i].name,gen[i].goals,gen[n-1-i].goals,gen[n-1-i].name);
    }
    printf("\nWould you like to change any result of the results?\n");
    SetColor(12);
    printf("\nPress Y to change the result.\n");
    SetColor(10);
    printf("Press any other key to continue without editing.\n");
    SetColor(15);
    e=getch();
    if(e=='Y'||e=='y')
    {
    printf("\nChoose the match number of the match whose outcome you want to change:\n");
    for(i=0;i<n/2;i++)
    {
        printf("Match %d:%s VS %s\n",i+1,gen[i].name,gen[n-1-i].name);
    }
    scanf("%d",&edit);
    gen[edit-1].agg=gen[edit-1].agg-gen[edit-1].goals;
    gen[n-edit].agg=gen[n-edit].agg-gen[n-edit].goals;
    printf("Match %d:%s VS %s\n",edit,gen[edit-1].name,gen[n-edit].name);
    printf("Enter number of goals scored by %s:",gen[edit-1].name);
    scanf("%d",&gen[edit-1].goals);
    printf("Enter number of goals scored by %s:",gen[n-edit].name);
    scanf("%d",&gen[n-edit].goals);
    gen[edit-1].agg=gen[edit-1].agg+gen[edit-1].goals;
    gen[n-edit].agg=gen[n-edit].agg+gen[n-edit].goals;
    if(l==legs-1)
    {
    if(gen[edit-1].agg<gen[n-edit].agg)
        {
        swap=gen[edit-1];
        gen[edit-1]=gen[n-edit];
        gen[n-edit]=swap;
        }
        else if(gen[edit-1].agg==gen[n-edit].agg)
        {
            erestart2:
            SetColor(11);
            printf("Who won on penalties?");
            SetColor(10);
            printf("\nEnter 1 for %s",gen[edit-1].name);
            SetColor(14);
            printf("\nEnter 2 for %s\n",gen[n-edit].name);
            SetColor(15);
            scanf("%d",&p);
            if(p==2)
            {
            swap=gen[edit-1];
            gen[edit-1]=gen[n-edit];
            gen[n-edit]=swap;
            }
            else if(p!=1)
            {
            SetColor(12);
            printf("Error!\n");
            SetColor(15);
            goto erestart2;
            }
        }
    }
        goto editresultk2;
    }
    match=fopen("matches.txt","a");
    for(i=0;i<n/2;i++)
    {
        fprintf(match,"%s %d-%d %s\n",gen[i].name,gen[i].goals,gen[n-1-i].goals,gen[n-1-i].name);
    }
    fclose(match);
    SetColor(13);
    printf("\nThe matches have been recorded.\nYou can check the recorded matches by opening the text file matches.txt\n");
    SetColor(14);
    printf("\nPress any key to continue.\n");
    SetColor(15);
    e=getch();
    if(l%2!=0&&l!=legs-1)
    {
    for(i=0;i<n/2;i++)
    {
            swap=gen[i];
            gen[i]=gen[n-1-i];
            gen[n-1-i]=swap;
    }
    }
    lt=fopen("latter stage teams.txt","wb");
    for(i=0;i<n;i++)
    {
    fwrite(&gen[i],sizeof(struct general),1,lt);
    }
    fclose(lt);
    SetColor(10);
    printf("\nData has been saved!\n");
    SetColor(12);
    printf("\nPress e to end the program.");
    SetColor(14);
    printf("\nPress any other key to continue\n");
    SetColor(15);
    e=getch();
    if(e=='E'||e=='e')
    {
     lf=3;
     y=l+1;
     fprintf(lv,"%d\n%d\n%d\n%d\n%d\n%d\n%d",bye,y,n,x,mid,end,lf);
     fclose(lv);
     exit(0);
    }
    }
    end=1;
    system("CLS");
    SetColor(11);
    match=fopen("matches.txt","a");
    printf("The aggregate scores are:\n");
    fprintf(match,"\nThe aggregate scores are:\n");
    for(i=0;i<n/2;i++)
    {
        printf("%s %d-%d %s\n",gen[i].name,gen[i].agg,gen[n-1-i].agg,gen[n-1-i].name);
        fprintf(match,"%s %d-%d %s\n",gen[i].name,gen[i].agg,gen[n-1-i].agg,gen[n-1-i].name);
    }
    fclose(match);
    if(n/2!=1)
    {
    printf("\nThe following teams have advanced to the next round:\n");
    for(i=0;i<n/2;i++)
    {
        SetColor(i%5+10);
    printf("%s\n",gen[i].name);
    }
    }
    n=n/2;
    }
    fclose(lv);
    SetColor(15);
    printf("\nCongratulations %s! You have won the %s.\n",gen[0].name,tnmt);
    SetColor(14);
    printf("\t\t\t @       @\n");
    printf("\t\t\t@ @#####@ @\n");
    printf("\t\t\t@  #####  @\n");
    printf("\t\t\t @ ##### @\n");
    printf("\t\t\t  @#####@\n");
    printf("\t\t\t    ### \n");
    printf("\t\t\t     #\n");
    printf("\t\t\t     #\n");
    printf("\t\t\t    ###\n");
    printf("\t\t\t    ###\n");
    SetColor(15);
}
void timer()
{
    int minute,second;
    SetColor(14);
    printf("Enter the Starting Minute: ");
    scanf("%d",&minute);
    SetColor(11);
    printf("Enter the Starting Second: ");
    scanf("%d",&second);
  showtime(minute ,second);
}

void showtime(int minute, int second)
{
while(minute<100)
{
    while(second<60)
    {
        Sleep(1000);
        system("CLS");
        second++;
        SetColor(14);
  display(minute/10,45,10);
    display(minute%10,51,10);
    SetColor(15);
    colon(57,10);
    SetColor(11);
       display(second/10,63,10);
    display(second%10,69,10);
    }
    minute++;
    second=0;
}

}


void display(int digit, int x , int y)
{
    switch(digit)
    {
        case 1:
            one(x,y);
             break;
        case 2:
             two(x,y);
             break;
        case 3:
            three(x,y);
            break;
        case 4:
             four(x,y);
             break;
        case 5:
             five(x,y);
              break;
        case 6:
             six(x,y);
              break;
        case 7:
            seven(x,y);
             break;
        case 8:
            eight(x,y);
             break;
        case 9:
            nine(x,y);
             break;
        default:
            zero(x,y);
    }
}
void gotoxy(int x,int y)
{
  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

    void zero(int x ,int y)
    {
        for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=5;j++)
        {
            gotoxy(x,y);
            if(i==1||i==9||j==1||j==5)
            {
                printf("0");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x=x-5;
        printf("\n");
    }
    }

    void one(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
                if(j==3)
                {
                    printf("1");
                }
                else
                {
                    printf(" ");
                }
                x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void two(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || i==9 || (i<5&&j==5) || (j==1&&i>5))
               {
                   printf("2");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void three(int x,int y)
{
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || i==9 || j==5)
               {
                   printf("3");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void four(int x,int y)
{
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(j==5||i==5||(j==1&&i<5))
               {
                   printf("4");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }

    void five(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || i==9 || (i>5&&j==5) || (j==1&&i<5))
               {
                   printf("5");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
     void six(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || i==9 || j==1 ||(j==5&&i>5))
               {
                   printf("6");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            printf("\n");
            y++;
            x=x-5;
        }
    }
 void seven(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || j==5)
               {
                   printf("7");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
 void eight(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || i==9 || j==1 || j==5)
               {
                   printf("8");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
 void nine(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || i==9 || j==5 ||(j==1&&i<5))
               {
                   printf("9");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void colon(int x,int y)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if((i==3&&j==3) || (j==3&&i==7))
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
    }
}


void characterO(int x,int y)
{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || j==5 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void characterC(int x,int y)
{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==5 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void characterS(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==3 || i==5 || (i>3&&j==5) || (j==1&&i<3))
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void characterU(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if( i==5 || j==5 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void characterT(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || j==3 )
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void characterM(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=7;j++)
            {
                gotoxy(x,y);
               if(i==1 || j==1 || j==4 || j==7)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-7;
            printf("\n");
        }
    }
    void characterF(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==3 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void characterB(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==3 || i==5 || j==1 || j==5)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void characterA(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==3 || j==5 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void characterL(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(j==1 || i==5)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
void characterR(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==3 || j==1 || (i==4&&j==3) || (j==5&&i<3) || (i==5&&j>3))
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void characterN(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1|| j==5 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
    }
    void characterE(int x, int y)

{
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=5;j++)
            {
                gotoxy(x,y);
               if(i==1 || i==3 || i==5 || j==1)
               {
                   printf("#");
               }
               else
               {
                   printf(" ");
               }
               x++;
            }
            y++;
            x=x-5;
            printf("\n");
        }
}
