#include <stdio.h>
#include <math.h>

double func(double x){
    return cos(x) + x;
}
double bfunc(double x){
    return (cos(x) + x)*10e20;
}

int main(){
    int i=0;
    double a[500],b[500],c[500];
    a[0]=-100;b[0]=50;

    for(i=0;i<400 && fabs(a[i]-b[i])>10e-20;i++){

        printf("a[%d]:%.20lf b[%d]:%.20lf f(b)-f(a) = %.25lf\n",i,a[i],i,b[i],b[i]-a[i]);
        c[i]=(a[i]+b[i])/2;
        printf("f(a)*f(c):%.20lf f(c)*f(b):%.20lf\n",bfunc(a[i])*bfunc(c[i]),bfunc(c[i])*bfunc(b[i]));
        if(bfunc(a[i])*bfunc(c[i])<0){
            a[i+1]=a[i];b[i+1]=c[i];
        }
        else if(bfunc(c[i])*bfunc(b[i])<0){
            a[i+1]=c[i];b[i+1]=b[i];
        }
        else{
            printf("error\n");
            break;
        }
    }
    printf("x = %.15lf,f(x) = %lf\n",a[i],func(a[i]));
}