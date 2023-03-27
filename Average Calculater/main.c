#include <stdio.h>
#include <stdlib.h>

float avg(int s1,int s2)
{

        return (float)(s1+s2)/2;

}
int main()
{
    int n1,n2;

    printf("Math Grades: ");
    scanf("%d %d",&n1,&n2);


    printf("Subject Average: %f",avg(n1,n2));

    return 0;
}
