/*4)Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto
superior esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido
por uma estrutura Ponto, a qual contém as posições X e Y. Faça um programa que
declare e leia uma estrutura Retângulo e exiba a área e o comprimento da diagonal
e o perímetro desse retângulo.
5) Usando a estrutura Retângulo do exercício anterior, faça um programa que declare
e leia uma estrutura Retângulo e um Ponto, e informe se esse ponto está ou não
dentro do retângulo.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct retangulo
{
    double x, y;
}p1,p2,pUser;// 3 estruturas que vão ser usadas
//protótipo das funções
void A_CD_P(struct retangulo *p1, struct retangulo *p2);
double area(struct retangulo *p1, struct retangulo *p2);
double comp_D(struct retangulo *p1, struct retangulo *p2);
double p2p(struct retangulo *p1, struct retangulo *p2);
void localiza_ponto(struct retangulo *p1, struct retangulo *p2);
//função main, principal
int main()
{
    int user;
    while (user != 0)
    {
        //usuário escolhe o que fazer
        printf("\n1)Area,comprimento da diagonal,perimetro\n2)Ponto esta ou nao dentro do retangulo\n0)Sair\n");
        scanf("%d", &user);
        switch (user)
        {
        case 1:
        A_CD_P(&p1, &p2);
         break;
        case 2: localiza_ponto(&p1,&p2);
        break;
        case 0:
         printf("fim");break;
        default:
        printf("\nOpcao invalida!\n");
        }
    }
    return 0;
}
//função que calcula a área, comprimento da diagonal e o perímetro. Foi dividida em outras funções para facilitar e tornar o código mais reutilizável
void A_CD_P(struct retangulo *p1, struct retangulo *p2)
{
    printf("\nP1: canto superior esquerdo,x,y  ");
    scanf("%lf%*c%lf%*c", &(*p1).x, &(*p1).y);
    printf("\nP2: canto inferior direito,x,y  ");
    scanf("%lf%*c%lf%*c", &(*p2).x, &(*p2).y);
    printf("\nAREA = %lf\n", area(&(*p1), &(*p2)));//é necessário passar a estrutura dessa forma, usando &p1 haverá erro
    printf("\nCOMPRIMENTO DA DIAGONAL = %lf\n", comp_D(&(*p1), &(*p2)));
    printf("\nPERIMETRO = %lf\n", p2p(&(*p1), &(*p2)));
}
//area
double area(struct retangulo *p1, struct retangulo *p2)
{
    double A = 0;
    return A = ((*p2).x - (*p1).x) * ((*p1).y - (*p2).y);
}
//comprimento da diagonal
double comp_D(struct retangulo *p1, struct retangulo *p2)
{
    double D = 0;
    return D = sqrt(pow(((*p2).x - (*p1).x), 2) + pow(((*p1).y - (*p2).y), 2));
}
//perimetro
double p2p(struct retangulo *p1, struct retangulo *p2)
{
    double pe = 0;
    return pe = 2 * ((*p2).x - (*p1).x) + 2 * ((*p1).y - (*p2).y);
}
//ponto esta ou nao no retângulo
void localiza_ponto(struct retangulo *p1, struct retangulo *p2)
{
    printf("\nP1: canto superior esquerdo,x,y  ");
    scanf("%lf%*c%lf%*c", &(*p1).x, &(*p1).y);
    printf("\nP2: canto inferior direito,x,y  ");
    scanf("%lf%*c%lf%*c", &(*p2).x, &(*p2).y);
    printf("\nPonto que deseja localizar:x,y ");
    scanf("%lf%*c%lf%*c",&pUser.x,&pUser.y);
    /*ponto p está no retângulo se p.x for maior ou igual ao x do canto superior esquerdo e menor ou igual o valor de x do canto inferior direito
    Já p.y deve ser menor ou igual que y do canto superior esquerdo e maior ou igual y do canto inferior direito*/
    if(pUser.x>=(*p1).x && pUser.x<=(*p2).x && pUser.y>=(*p2).y && pUser.y<=(*p1).y)
    {
      printf("\nPONTO ESTA NO RETANGULO\n");
    }
    else
    {
      printf("\nPONTO NAO ESTA NO RETANGULO\n");
    }

}
//Maria Vitória (GitHub @MaviMendes)