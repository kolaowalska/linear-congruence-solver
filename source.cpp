#include <iostream>
// for GMP big integers beyond the range of long long replace the type with bigInteger
// #include <gmpxx.h> 
// using bigInteger =  mpz_class;
using namespace std;
typedef long long ll;

struct Triple {
    ll d, x, y;
    Triple(ll D, ll X, ll Y) : d(D), x(X), y(Y) {}
    Triple() {}

    void display() {
        cout << "d, x, y: " << d << " " << x << " " << y << '\n';
    }
};

Triple extendedGCD(ll a, ll b) {
    Triple aux;
    if (b == 0)
        return Triple(a, 1, 0);
    else
        aux = extendedGCD(b, a % b);
    return Triple(aux.d, aux.y, aux.x - (a / b) * aux.y);
}

ll inverse(ll a, ll n) {
    Triple egcd = extendedGCD(a, n);
    if (egcd.d != 1)
        return -1; // no inverse exists in this ring
    return (egcd.x % n + n) % n; 
}

void linsolve(ll a, ll b, ll n) {
    Triple gcd = extendedGCD(a, n);
    if (b % gcd.d != 0) { 
        cout << "no solutions exist" << endl;
        return;
    }

    ll a_prim = a / gcd.d;
    ll b_prim = b / gcd.d;
    ll n_prim = n / gcd.d;

    ll x0 = (inverse(a_prim, n_prim) * b_prim) % n_prim;
    for (ll i = 0; i < gcd.d; ++i) {
        ll solution = (x0 + i * n_prim) % n;
        cout << "solution: " << solution << endl;
    }
}

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    linsolve(a, b, n);
    return 0;
}
