#include <stdio.h>
#include <math.h>

double det(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x33){
    return x11*x22*x33 + x12*x23*x31 + x13*x21*x32 - x13*x22*x31 - x12*x21*x33 - x11*x23*x32;
}

void print(double c, double d, double e, double h, double k, double r){
    char signC = (c>=0) ? '+' : '-';
    char signD = (d>=0) ? '+' : '-';
    char signE = (e>0) ? '+' : '-';
    char signH = (h>0) ? '+' : '-';
    char signK = (k>0) ? '+' : '-';
    printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\nx^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", signH, fabs(h), signK, fabs(k), fabs(r), signC, fabs(c), signD, fabs(d), signE, fabs(e));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&x2,&y2,&x3,&y3) == 6){
        double r1 = -x1*x1-y1*y1, r2 = -x2*x2-y2*y2, r3 = -x3*x3-y3*y3;
        double fm = det(x1,y1,1.0,x2,y2,1.0,x3,y3,1.0);
        double c,d,e,h,k,r;
        c = det(r1,y1,1.0,r2,y2,1.0,r3,y3,1.0)/fm;
        d = det(x1,r1,1.0,x2,r2,1.0,x3,r3,1.0)/fm;
        e = det(x1,y1,r1,x2,y2,r2,x3,y3,r3)/fm;
        h = c/2.0;
        k = d/2.0;
        r = sqrt(h*h+k*k-e);
        print(c,d,e,h,k,r);
    }
    return 0;
}
