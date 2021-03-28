#include <stdio.h>

int flag = 0;

double diff (long n, double mid){
    
    if (n > mid*mid*mid)
        return (n - (mid*mid*mid));
    else 
        return ((mid * mid * mid) - n);

}

double cubicRoot(long n){
    if(n < 0){
        n = -n;
        flag = 1;
    }
    double start = 0,end = n;
    //maximum error value acceptable is e
    double e = 0.0000001;

    while(1){
        double mid = (start + end)/2;
        double error = diff(n, mid);

        if(error <= e){
            if(flag == 0)
                return mid;
            else
                return -mid;
        }

        if(mid*mid*mid < n){
            start = mid;
        }
        else{
            end = mid;
        }
    }
}

int main()
{
    long N = 0, final;
    scanf("%ld",&N);
    
    double result = cubicRoot(N);
    final = result;
    printf("%ld", final);

    return 0;
}