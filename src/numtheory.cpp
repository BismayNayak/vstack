#include "numtheory.h"

int64_t ext_gcd(int64_t a,int64_t b,int64_t& x,int64_t& y){
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    int64_t x1,y1;
    int64_t gcd= ext_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return gcd;
}

void test_bezout(){
    std::cout<<"Bezout's Identity";
    int64_t a=345,b=56;
    int64_t x,y;
    int64_t gcd = ext_gcd(a,b,x,y);

    std::cout<<"GCD ("<<a<<","<<b<<") = "<<gcd<<std::endl;

    int64_t combination=x*a+y*b;
    std::cout<<"Integer Linear Combination of"<<a<<" and "<<b<<" = "<<combination<<std::endl;

    if (gcd==combination) std::cout<<"GCD is a Integer Linear Combination of"<<a<<" and "<<b<<std::endl;

    int64_t min_positive=INT64_MAX;
    for (int64_t i=-500;i<=500;i++){
        for (int64_t j=-500;j<=500;j++){
            int64_t val=a*i+b*j;
            if (val>0 && val<min_positive){
                min_positive=val;
            }
        }
    }
    std::cout<<"Smallest Linear Combination within [-500,500] is "<<min_positive<<(min_positive==gcd ? " matches gcd.\n"
                                                                                                    : "FAILS. \n");
}
void test_modularInverse(){
    int64_t a=56, b=345,x,y ;
    int64_t g= ext_gcd(a,b,x,y);

    if(g!=1) {
        std::cout<<"As GCD of "<<a<<" and "<<b<<" is not 1 , therefore there is no modular inverse.\n";
        return;
    }

    int64_t inverse =(x%b+b)%b;
    int64_t check=(a*inverse)%b;
    std::cout<<((check==1) ?"Modular Inverse check passes\n"
                        :   "Modular Inverse check FAILS.\n");
}

int64_t binary_exp(int64_t base ,int64_t exp,int64_t mod){
    int64_t result=1;
    base =base % mod;
    while (exp!=0){
        if (exp%2==1){
            result=(result *base)% mod;
        } 
        base=(base*base)% mod;
        exp=exp/2;
    }
    return result;
}
void test_flt(){
    std::cout<<"Fermat's Little Theorem (FLT) "<<std::endl;
    int64_t p=1000000007;
    int64_t a=42;
    std::cout<<"Base = "<<a<<" and Prime = "<<p<<std::endl;
    int64_t flt = binary_exp(a,p-1,p);
    std::cout<<(flt==1 ? "Fermant Little Theorem Verfied.\n"
                    :   "Verification Failed.\n");
    int64_t inv_flt=binary_exp(a,p-2,p);
    std::cout<<"Modular Inverse of "<<a<<" mod "<<p<<" is (using FLT)"<<inv_flt<<std::endl;
    int64_t x,y;
    ext_gcd(a,p,x,y);
    int64_t inv_gcd=((x%p)+p)%p;
    std::cout<<"Modular Inverse of "<<a<<" mod "<<p<<" is (using Ext_GCD)"<<inv_gcd<<std::endl;
    std::cout<<(inv_flt==inv_gcd ? "Modular Inverse both by FLT and Ext_GCD are equal.\n"
                    :   "Verification Failed.\n");
}

int main(){
    test_bezout();
    test_modularInverse();
    test_flt();
    return 0;
}