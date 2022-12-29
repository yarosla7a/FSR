#include <iostream>
#include <gmpxx.h>
#include <string>
#include <ctime>
#include <math.h>
#include <mpirxx.h>

using namespace std;


int main()
{
    //srand(time(NULL))
    mpz_t n, N, a, k, b, f, e, ans, i, gcd1, gcd2;
    int t = 0;
    mpz_inits(n, N, k, b, f, NULL, ans, gcd1, gcd2);
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(e, 1);
    string n1, N1;
    cin >> n1 >> N1;
    const char* nn = n1.c_str();
    const char* NN = N1.c_str();
    mpz_set_str(n, nn, 10);
    mpz_set_str(N, NN, 10);
    clock_t time = clock();
    

    
     while(mpz_cmp(n, a) > 0)
    {
        //cout << "here\n";
         gmp_randstate_t grt;
         gmp_randinit_default(grt);
         gmp_randseed_ui(grt, time);
        mpz_urandomm(k, grt, N);
        //k = rand() % (N + 1);
        mpz_init_set_ui(ans, 1);
        for (mpz_init_set_ui(i, 1); mpz_cmp(k + 1, i) > 0; mpz_add(i, i, e)) mpz_mul(ans, ans, i);
        mpz_set(f, ans);
        mpz_powm(b, a, f, a);
        mpz_sub(b, b, e);
        mpz_mod(b, b,  n);
        mpz_gcd(gcd1, b, n); mpz_gcd(gcd2, b, n);
        if (mpz_cmp(gcd1,e) && mpz_cmp(gcd2, n))
        {
            cout << "here\n";
            t = 1;
            mpz_set(a,n);
            mpz_out_str(stdout, 10, b); cout << endl;
        }
        mpz_add(a, a, e);
    }
     cout << "here";
    if (!t) cout << 1;
    mpz_clear(n);
    mpz_clear(N);
    mpz_clear(a);
    mpz_clear(k);
    mpz_clear(b);
    mpz_clear(f);
    mpz_clear(e);
    mpz_clear(ans);
    mpz_clear(i);
    mpz_clear(gcd1);
    mpz_clear(gcd2);
}