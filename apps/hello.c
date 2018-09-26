#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int global;
int hello(){
	int a=1+2;
    int b=10;
    int c=20;
    a=c+b;
   	return a;
}

float helloFloat(){
    float a=1+2;
    float b=10;
    float c=20;
    a=c+b;
    return  a;
}

double helloDouble(){
    double a=1+2;
    double b=17;
    double c=20;
    a=c+b;
    return  a;
}





void arrayTest(){
    int a[2][3][3]={{1,2,3},{1,2,3}};
    //a[1][1]=2;
    int i,j,k;




    for(i=0;i<2;i++) {
        for(j=0; j<3;j++){

                for(k=0;k<3;k++) {
                    printf("Data=%d\n", a[i][j][k]);
                }

            }

    }


}

void dynamicAllocationArrayTest(){

    // 1- D
    int *a = (int *)malloc(4*sizeof(int));
    //a[1][1]=2;
    int i,j,k;




    for(i=0;i<4;i++) {
       printf("%d\n",a[i]);

    }


}









int dependency(){
    int a; // declare varible a alloca in llvm
    a=10; // load 10 in %a
    int b=20;
    if(b==20){ // This will eliminate by compiler, but for testing only assume 20 is not constant
        a=a+1; // loading and storing re-  assigned a
    }
    else{
        a=a+2;
    }


return a;
}


int main(int argc, char const *argv[])
{

	int res=hello();
    dependency();
printf("\nResult =%d",res);
     res=hello();
    printf("\nResult =%d",res);
    float  fres=helloFloat();
    printf("\nFloat result =%f",fres);
    double  dres=helloDouble();
    printf("\nFloat result =%lf",dres);
    arrayTest();
    dynamicAllocationArrayTest();
    return 0;
}
