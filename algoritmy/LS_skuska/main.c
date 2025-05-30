#include "main.h"

int main()
{
    int l,c,w;
    scanf("%d %d %d",&l,&c,&w);
    char m[l][c];
    int i,j;
    getchar();
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%c",&m[i][j]);

        }
        getchar();
    }

    char slovo[w][l+c];
    for(i=0;i<w;i++){
        scanf("%s",slovo[i]);
    }

    hladanie(l,c,w,m,slovo);

    return 0;
}

void hladanie(int l,int c,int w,char m[l][c],char slovo[w][l+c])
{
    int i,j,k,s;
    char pom[l+c];
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            pom[j] = m[i][j];
        }
            pom[c] = '\0';

            for(k=0;k<w;k++){
                char *poz;
                if((poz = strstr(pom,slovo[k]))!=NULL){
                    for(s=0;s<strlen(pom);s++){
                        if(poz == &pom[s])
                            printf("%d %d A\n",i,s);
                    }
                }
            }
            strrev(pom);

            for(k=0;k<w;k++){
                char *poz;
                if((poz = strstr(pom,slovo[k]))!=NULL){
                     for(s=0;s<strlen(pom);s++){
                        if(poz == &pom[s])
                            printf("%d %d E\n",i,(int)strlen(pom)-s-1);}
                }
            }
        }
    for(j=0;j<c;j++){
        for(i=0;i<l;i++){
            pom[i] = m[i][j];
        }
        //printf("%s\n",pom);
        pom[c] = '\0';
        for(k=0;k<w;k++){
            char *poz;
            if((poz = strstr(pom,slovo[k]))!=NULL){
                    for(s=0;s<strlen(pom);s++){
                        if(poz == &pom[s])
                            printf("%d %d C\n",s,j);
                    }
                }
        }
        strrev(pom);

            for(k=0;k<w;k++){
                char *poz;
                if((poz = strstr(pom,slovo[k]))!=NULL){
                     for(s=0;s<strlen(pom);s++){
                        if(poz == &pom[s])
                            printf("%d %d G\n",(int)strlen(pom)-s-1,j);}
                }
            }
    }

}
