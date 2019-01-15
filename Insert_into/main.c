#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void typeDataFunction(){
        printf("0 : INTEGER\n"); //ok
        printf("1 : DOUBLE\n"); //ok
        printf("2 : CHAR\n"); //ok
        printf("3 : VARCHAR\n");
        printf("4 : DATE\n");//ok
        printf("5 : TEXT\n");//OK
}

int generateDataInteger(int min, int max){
    srand(time(NULL));
    return rand()%(max - min) + min;    //entre 1-9

    /*printf("%d\n",nbgen);
    return 0;*/
}

float generateDataDouble(){
    int max = 90;
    int min = 10;
    int bigratio;
    float proba;

    srand(time(NULL));
    bigratio =generateDataInteger(min, max);
    proba =  bigratio/10.0;

    return proba;
}

char * generateDataDate(char * date){

    //char date [255];
    int day = generateDataInteger(1,25);
    int month = generateDataInteger(1,12);
    int year = generateDataInteger(2000,2018);

    if(day>0 && day<10){
        if(month>0 && month<10){

            sprintf(date,"0%d/0%d/%d", day,month,year);
        }
        else{

            sprintf(date,"0%d/%d/%d", day,month,year);
        }
    }
    else{
        if(month>0 && month<10){

            sprintf(date,"%d/0%d/%d", day,month,year);
        }
    }
    return date;

}

char * generateDataText(char * text, int SIZE){
    //int SIZE= 50;
    unsigned char ar[SIZE];
    //char text[SIZE];
    char text_tempo[SIZE];
    int size;
    int i;

    strcpy(text,"\0");
    strcpy(text_tempo,"\0");
    srand(time(NULL));
    for(i=0;i<SIZE;i++){
         ar[i] = 'A'+rand()%26;
         //strcat(text,text_tempo);
         size=strlen(text);
         text[size]=ar[i];
         text[size+1]='\0';
    }
    //printf("%s", text);
    return text;

}
void readFic (char * Filename){ //correction
    char name [333];
    FILE * fp;
    fp = fopen("varchar.txt","r");
    if(fp == NULL){
        exit(EXIT_FAILURE);
    }
    while(fread(name, sizeof(char),288,fp), !feof(fp)){
        printf("\n%s",name);
    }
    fclose(fp);
}

char * generateDataVarchar(char * text, int SIZE){}



char * typecolonne(char * text, int nbColonne){
 char array [255] ={};
 int i;
 int typeData;
    for(i=0; i<nbColonne; i++){
        printf("De quelle type est la %d colonne  \n",i+1);
        typeDataFunction();
        scanf("%d", &typeData);

        switch(typeData) {
        case 0 :
             printf("INTEGER!\n" );
             if(i==0)
                strcat(array,"(");
             char valuesInt[250]={};
             srand(time(NULL));
             int integer = generateDataInteger(1,9);
             sprintf(valuesInt,"%d", integer);
             strcat(array,valuesInt);
             if(i!= (nbColonne-1))
                strcat(array,", ");
             if(i== (nbColonne-1))
                strcat(array,")");
             break;
        case 1 :
             printf("DOUBLE\n" );
             if(i==0)
                strcat(array,"(");
             char valuesDouble[250]={};
             srand(time(NULL));
             double valdouble = generateDataDouble();
             sprintf(valuesDouble,"%.2f", valdouble);
             strcat(array,valuesDouble);
             if(i!= (nbColonne-1))
                strcat(array,", ");
             if(i== (nbColonne-1))
                strcat(array,")");
             break;
        case 2 :
             printf("CHAR de combien ?\n" );
             if(i==0)
                strcat(array,"(");
             int nbChar;
                scanf("%d", &nbChar);
             char text[255];
             srand(time(NULL));
             generateDataText(text,nbChar);
             strcat(array,"'");
             strcat(array,text);
             strcat(array,"'");
             if(i!= (nbColonne-1))
                strcat(array,", ");
             if(i== (nbColonne-1))
                strcat(array,")");
             break;
        case 3 :
             printf("VARCHAR de combien ?\n" );
             if(i==0)
                strcat(array,"(");
             int nbVarchar;
             scanf("%d", &nbVarchar);
             char textVarchar[255]={};
             srand(time(NULL));
             generateDataText(textVarchar,nbVarchar);
             strcat(array,"'");
             strcat(array,textVarchar);
             strcat(array,"'");
             if(i!= (nbColonne-1))
                strcat(array,", ");
             if(i== (nbColonne-1))
                strcat(array,")");
             break;
        case 4 :
             printf("DATE\n" );
             if(i==0)
                strcat(array,"(");
                strcat(array,"TO_DATE(");
            char date[255];
             srand(time(NULL));
             generateDataDate(date);
             strcat(array,"'");
             strcat(array,date);
             strcat(array,"' , 'DD/MM/YYYY'");
             strcat(array,")");
             if(i!= (nbColonne-1))
                strcat(array,", ");
             if(i== (nbColonne-1))
                strcat(array,")");
             break;
        case 5 :
             printf("TEXT\n" );
             if(i==0)
                strcat(array,"(");
             char Datatext[255];
             srand(time(NULL));
             generateDataText(Datatext,50);
             strcat(array,Datatext);
             if(i!= (nbColonne-1))
                strcat(array,", ");
             if(i== (nbColonne-1))
                strcat(array,")");
             break;
        default :
             printf("Invalid TYPE\n" );
        }

    }
    strcpy(text,array);
    /*for(i=0; i<nbColonne; i++){
       // printf("Le type de la colonne est : %s \n",array[i]);
        text[i]=array[i];
        printf("Le type de la colonne est : %s \n",text[i]);
    }*/

    return(text);

}


char * colonneName(char * colname, int nbColonne){

    char colonne [255]={};
    char nameColonne[25]={};
    int i;
    for(i=0; i<nbColonne; i++){
        printf("Veuillez saisir le nom de la %d colonne  \n",i+1);
        scanf("%s",nameColonne);
        if(i==0)
        strcat(colonne," (");
        if(i>0){
            strcat(colonne,", ");
        }
        strcat(colonne,nameColonne);
        if(i == (nbColonne-1))
        strcat(colonne,")");

    }
    printf("Le nom des colonnes sont : %s \n\n",colonne);
    strcpy(colname,colonne);

    return colname;
}

void menu(){

    char tableName[25];
    char insert[25];
    char values[25];
    char colonne [255];
    int nbColonne;
    int i;
    strcpy(insert,"INSERT INTO");
    strcpy(insert,"VALUES");
    //printf("%d",strlen(insert));
    printf("-----------INSERT INTO----------------\n\n");

    printf("Veuillez saisir le nom de la table : ");
    scanf("%s",tableName);
    printf("Le nom de votre table est : %s \n\n",tableName);

    printf("Veuillez saisir le nombre de colonne : ");
    scanf("%d",&nbColonne);
    printf("Le nombre de colonne est : %d \n",nbColonne);


   // printf("Le nom des colonnes sont : %s \n\n",colonneName(nbColonne));


//    typecolonne(nbColonne);


}

int main()
{
    /*FILE *fp= fopen("varchar.txt","r");
    char line[37];
    char name[255];
    char mail[255];
    while(fgets(line,1000,fp)!= NULL){
            if(strstr(line,name)== line && line[strlen(name)]=='\n')
                strcpy(mail,strchr(line,'\n')+1);
            printf("%s",mail);
    }
    //readFic(fp);
    return 0;*/
    int nbcol=5;
    char InsertInto[1000]={};
    strcat(InsertInto,"INSERT INTO coucou");

    char colName[255]={};
    colonneName(colName,nbcol);
    strcat(InsertInto,colName);
    strcat(InsertInto," VALUES ");


    char col[255];
    typecolonne(col,nbcol);

    strcat(InsertInto,col);
    strcat(InsertInto,";");
    printf("%s",InsertInto);

    return 0;

    char text[255];
    printf("%s",generateDataText(text,50));
    return 0;
    char date [255];
    printf("%s",generateDataDate(date));
    return 0;
    menu();
    return 0;
}
