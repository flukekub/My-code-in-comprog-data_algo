#include <iostream>
using namespace std;

int fac( int n ){
    if( n == 0 ){
        return 1;
    }
    if( n == 1 ){
        return 1;
    }
    if( n == 2  ){
        return 2 ;
    }
    return n*fac(n-1);
}

int S(int n, int k) {
    if( n == 0  && k == 0 ){
        return 1 ;
    }
    if( n > 0   && k == 0 || n == 0 && k != 0 ){
        return 0 ;
    }
    return k*S(n-1,k) + S(n-1,k-1) ;
}
int B(int n) {
    if( n == 0 ){
        return 1 ;
    }
    
    int sum = 0 ;
    for( int k = 0 ; k <= n-1 ; k++ ){
       sum +=  (fac(n-1)/(fac(k)*fac(n-1-k)))*B(k) ;
    }

    return sum ;

    
}
int T(int n, int x) {
    if( n == 0 ){
        return 1 ;
    }
    if( n == 1 ){
        return x ;
    }
    return 2*x*T(n-1,x) - T(n-2,x) ;
}
int main() {
string fn;
int i, j;
while (cin >> fn) {
if (fn == "S") {
cin >> i >> j;
printf("S(%d, %d) = %d\n", i, j, S(i,j));
} else if (fn == "B") {
cin >> i;
printf("B(%d) = %d\n", i, B(i));
} else if (fn == "T") {
cin >> i >> j;
printf("T(%d, %d) = %d\n", i, j, T(i,j));
}
}
return 0;
}
