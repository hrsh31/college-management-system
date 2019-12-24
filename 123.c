#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


struct sdetails
{
    int ids;
    char names[20],add[40],phnos[10],branch[20];
    struct sdetails *nexts;
}*temps=NULL,*firsts=NULL,*lasts=NULL,*temp1s=NULL;

struct tdetails
{
    int idt;
    char namet[20],qual[40],phnot[10],desg[20];
    struct tdetails *nextt;
}*tempt=NULL,*firstt=NULL,*lastt=NULL,*temp1t=NULL;

void detailsss()
{
    // printf("|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t|\n",temps->ids ,temps->names, temps->add , temps->phnos ,temps->branch );
     printf("id:%d\n",temps->ids);
     printf("name:%s\n",temps->names);
     printf("address:%s\n",temps->add);
     printf("contact:%s\n",temps->phnos);
     printf("branch:%s\n",temps->branch);

}
void detailstt()
{
   // printf("|\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t|\n",tempt->idt ,tempt->namet, tempt->qual , tempt->phnot ,tempt->desg );
    printf("id:%d\n",tempt->idt);
    printf("name:%s\n",tempt->namet);
    printf("qualification:%s\n",tempt->qual);
    printf("contact:%s\n",tempt->phnot);
    printf("designation:%s\n",tempt->desg);

}
void creates()
{
    temps=(struct sdetails *)malloc(sizeof(struct sdetails));
    temp1s=(struct sdetails *)malloc(sizeof(struct sdetails));
    printf("enter the details:\n ");
    printf("id:");
    scanf("%d",&temps->ids);
    printf("\nname:");
    scanf("%s",temps->names);
    printf("\naddress:");
    scanf("%s",temps->add);
    printf("\ncontact:");
    scanf("%s",temps->phnos);
    printf("\nbranch:");
    scanf("%s",temps->branch);
    temps->nexts=NULL;

}
void createt()
{
    tempt=(struct tdetails *)malloc(sizeof(struct tdetails));
    temp1t=(struct tdetails *)malloc(sizeof(struct tdetails));
    printf("enter the details:\n ");
    printf("id:");
    scanf("%d",&tempt->idt);
    printf("\nname:");
    scanf("%s",tempt->namet);
    printf("\nqualification:");
    scanf("%s",tempt->qual);
    printf("\ncontact:");
    scanf("%s",tempt->phnot);
    printf("\ndesignation:");
    scanf("%s",tempt->desg);
    tempt->nextt=NULL;

}

char key[10]="pass";
void mainmenu()
{  system("cls");
   int  ch;
   printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
   printf("\t\t\t\t\t\tMAIN MENU:\n");
   printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
   printf("1.insert record:\n 2.remove record \n 3.search record \n 4.view record \n 5.edit record \n 6.student attendance status \n 7.exit \n ") ;
   while(1)
   {
       printf("\n Enter your choice:\n");
       scanf("%d",&ch);
       switch(ch)
       {
               case 1:insert();
                      break;
               case 2:deleted();
                       break;
               case 3:search();
                        break;
               case 4:view();
                        break;
               case 5:edit();
                        break;
               case 6:attendance();
                        break;
               case 7:  printf("THANK YOU!! \n");
                        exit(0);
                        break;
                default:printf("INVALID CHOICE.");

       }

   }

}
void insert()
{   system("cls");
    int c;
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("\t\t\t\t\tINSERT:\n");
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    while(1)
    {
        printf("----------category:--------------\n 1.student \n 2.teacher \n  3.back to main menu\n");
        scanf("%d",&c);
        printf("---------------------------------\n");
        switch(c)
        {

            case 1:
                   creates();//insert at first
                   if(firsts==NULL)
                   {
                       firsts=temps;
                       lasts=firsts;

                   }
                   else{
                    temps->nexts=firsts;
                    firsts=temps;
                   }
                   break;

            case 2:
                   createt();//insert at first
                   if(firstt==NULL)
                   {
                       firstt=tempt;
                       lastt=firstt;

                   }
                   else{
                    tempt->nextt=firstt;
                    firstt=tempt;
                   }
                   break;
            case 3:mainmenu();
                  break;
        }
    }
}
void deleted()
{   system("cls");
    int d,ks,kt;
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("\t\t\t\t\t\tDELETE:\n");
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    while(1)
    {
        printf("----------category:--------------\n 1.student \n 2.teacher \n  3.back to main menu\n");
        scanf("%d",&d);
        printf("---------------------------------\n");
        switch(d)
        {

          case 1:
                    printf("enter id:\n");
                    scanf("%d",&ks);
                    temps=firsts;temp1s=firsts; //delete at first
                    if(firsts->ids==ks){
                        firsts=firsts->nexts;
                        free(temps);
                    }
                    else
                    {
                        while(temps->nexts!=NULL)
                        {
                            if(temps->ids==ks)
                            {
                                printf("details of deleted id:\n ");
                               // printf("|\tid\t|\tname\t|\taddress\t|\tcontact\t|\tbranch\t|\n");
                                detailsss(temps);
                                goto label;
                            }
                            temps=temps->nexts;
                        }
                        printf("ID NOT FOUND. PLEASE RE-ENTER IT AGAIN \n ");
                        deleted();
                        label:
                            while(temp1s->nexts!=temps)
                                temp1s=temp1s->nexts;
                            if(temps->nexts==NULL)
                                temp1s->nexts=NULL;
                            else
                                temp1s->nexts=temps->nexts;
                            free(temps);
                    }
                     break;

            case 2:
                    printf("enter id:\n");
                    scanf("%d",&kt);
                    tempt=firstt;temp1t=firstt;
                    if(firstt->idt==kt){
                        firstt=firstt->nextt;
                        free(tempt);
                    }
                    else
                    {
                        while(tempt->nextt!=NULL)
                        {
                            if(tempt->idt==kt)
                            {
                                printf("details of deleted id:\n ");
                               // printf("|\tid\t|\tname\t|\tqualification\t|\tcontact\t|\tdesignation\t|\n");
                                 detailstt(tempt);


                                goto labelt;
                            }
                            tempt=tempt->nextt;
                        }

                        printf("ID NOT FOUND. PLEASE RE-ENTER IT AGAIN \N ");
                        deleted();
                        labelt:
                            while(temp1t->nextt!=tempt)
                                temp1t=temp1t->nextt;
                            if(tempt->nextt==NULL)
                                temp1t->nextt=NULL;
                            else
                                temp1t->nextt=tempt->nextt;
                            free(tempt);
                    }
                    break;
            case 3:mainmenu();
                 break;
        }
    }

}
void view()
{   system("cls");
    int e,i=1;
    while(1)
    {
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("\t\t\t\t\tVIEW:\n");
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("----------category:--------------\n 1.student \n 2.teacher \n  3.back to main menu\n");
        scanf("%d",&e);
        printf("---------------------------------\n");
        switch(e)
        {

         case 1:
                    if(firsts==NULL)
                    {
                        printf("record is empty\n");
                        mainmenu();
                    }
                    else
                    {
                      temps=firsts;
                      printf("the record is:\n");
                     // printf("|\tid\t|\tname\t|\taddress\t|\tcontact\t|\tbranch\t|\n");
                      while(temps!=NULL)
                      {
                           printf("------------------details of record %d-----------------------\n ",i);
                           detailsss(temps);
                           temps=temps->nexts;
                           i+=1;

                      }

                    }
                    break;

          case 2:
                    if(firstt==NULL)
                    {
                        printf("record is empty\n");
                        mainmenu();
                    }
                    else
                    {
                      tempt=firstt;
                      printf("the record is:\n");
                     // printf("|\tid\t|\tname\t|\tqualification\t|\tcontact\t|\tdesignation\t|\n");
                      while(tempt!=NULL)
                      {

                           printf("------------------details of record %d-----------------------\n ",i);
                           detailstt(tempt);
                           tempt=tempt->nextt;
                           i+=1;


                      }

                    }
                    break;

            case 3:mainmenu();
                 break;
        }
    }

}
void search()
{   system("cls");
    int f,r,m;
    while(1)
    {
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("\t\t\t\t\tSEARCH:\n" );
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("----------category:--------------\n 1.student \n 2.teacher \n  3.back to main menu\n");
        scanf("%d",&f);
        printf("---------------------------------\n");
        switch(f)
        {

            case 1:
                   printf("enter id to search:\n");
                   scanf("%d",&r);
                   temps=firsts;
                   while(temps!=NULL)
                        {
                            if(temps->ids==r)
                            {
                                printf("details:\n ");
                               // printf("|\tid\t|\tname\t|\taddress\t|\tcontact\t|\tbranch\t|\n");
                                detailsss(temps);
                                goto label;
                            }
                            temps=temps->nexts;
                        }
                        printf("ID not found.\n ");

                    label:
                     break;



            case 2:
                   printf("enter id to search:\n");
                   scanf("%d",&m);
                   tempt=firstt;
                    while(tempt->nextt!=NULL)
                        {
                            if(tempt->idt==m)
                            {
                                printf("details:\n ");
                               // printf("|\tid\t|\tname\t|\tqualification\t|\tcontact\t|\tdesignation\t|\n");
                                detailstt(tempt);
                                goto labwl;
                            }
                            tempt=tempt->nextt;
                        }

                        printf("ID NOT FOUND.\n ");
                        labwl:
                            break;
            case 3:mainmenu();
                 break;
        }
    }

}

void edit()
{   system("cls");
    int g,r,m;
    while(1)
    {
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("\t\t\t\t\tEDIT:\n" );
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("----------category:--------------\n 1.student \n 2.teacher \n  3.back to main menu\n");
        scanf("%d",&g);
        printf("---------------------------------\n");
        switch(g)
        {

            case 1:
                   printf("enter id to edit:\n");
                   scanf("%d",&r);
                   temps=firsts;
                   while(temps!=NULL)
                        {
                            if(temps->ids==r)
                            {

                                printf("enter the new details:\n ");
                                printf("new id:");
                                scanf("%d",&temp1s->ids);
                                printf("\n new name:");
                                scanf("%s",temp1s->names);
                                printf("\n new address:");
                                scanf("%s",temp1s->add);
                                printf("\new contact:");
                                scanf("%s",temp1s->phnos);
                                printf("\nnew branch:");
                                scanf("%s",temp1s->branch);
                                temps->ids=temp1s->ids;
                                strcpy(temps->names,temp1s->names);
                                strcpy(temps->add,temp1s->add);
                                strcpy(temps->phnos,temp1s->phnos);
                                strcpy(temps->branch,temp1s->branch);
                                goto a;
                            }

                            temps=temps->nexts;
                        }
                        printf("INVALID ID\n");
                        a:
                        break;

            case 2:
                   printf("enter id to edit:\n");
                   scanf("%d",&m);
                   tempt=firstt;
                    while(tempt!=NULL)
                        {
                            if(tempt->idt==m)
                            {
                                printf("enter the new details:\n ");
                                printf("new id:");
                                scanf("%d",&temp1t->idt);
                                printf("\n new name:");
                                scanf("%s",temp1t->namet);
                                printf("\n new qualification:");
                                scanf("%s",temp1t->qual);
                                printf("\new contact:");
                                scanf("%s",temp1t->phnot);
                                printf("\nnew designation:");
                                scanf("%s",temp1t->desg);
                                tempt->idt=temp1t->idt;
                                strcpy(tempt->namet,temp1t->namet);
                                strcpy(tempt->qual,temp1t->qual);
                                strcpy(tempt->phnot,temp1t->phnot);
                                strcpy(tempt->desg,temp1t->desg);
                                goto b;
                            }
                            tempt=tempt->nextt;
                        }
                        printf("INVALID ID\n");
                        b:
                        break;
            case 3:mainmenu();
                 break;
        }
    }

}

void attendance()
{   system("cls");
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("\t\t\t\t\tSTUDENT ATTENDANCE STATUS:\n" );
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    int y,Ma,ADEa,SEa,COa,DSAa,DMSa;
    printf("enter MATHS attendance:\n ");
    scanf("%d",&Ma);
    printf("\n ADE attendance:");
    scanf("%d",&ADEa);
    printf("\n SE attendance:");
    scanf("%d",&SEa);
    printf("\nCO attendance:");
    scanf("%d",&COa);
    printf("\nDSA attendance:");
    scanf("%d",&DSAa);
    printf("\nDMS attendance");
    scanf("%d",&DMSa);

    y=(Ma+ADEa+SEa+COa+DSAa+DMSa)/6;
    if(y>=85)
    {
        printf("student have good attendance");
        printf("No fine");
    }
    else if(75<y<85)
    {
        printf("student have shortage of attendance\n");
        printf("student have to pay the fine of 500");
    }
    else if(65<y<75)
             {
                 printf("student have shortage of attendance\n");
             printf("student have to pay the fine of 1000");
             }
    else if(55<y<65)
             {
                 printf("student have shortage of attendance\n");
             printf("student have to pay the fine of 1500");
             }
    else
        {
            printf("student have shortage of attendance\n");
        printf("student have to pay the fine of 2000");
        }
}

void main()
{

    password1();


}
void password1()
{
  system("cls");
  char password[20];
  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("\t\t\t\t\tCOLLEGE MANAGEMENT SYSTEM:\n" );
  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
  printf("\t \n\n\n Enter Password:");
  scanf("%s",password);
  if(strcmp(password,key)==0)
  {
      printf("\n password matched .\n PRESS any key to continue\n");
      getch();
      mainmenu();
  }
  else
  {
      printf("\t\n\n\n INCORRECT PASSWORD.\n PRESS any key to continue");
      getch();
      password1();
  }
}





