#include <iostream>
#include <gmp.h>
int main(int argc, char* argv[]) {
    mpz_t l, r, p; /* working numbers */
    if (argc<3) { /* not enough arguments */
        printf("Please supply two numbers to multiply.\n");
        return 1;
    }
    mpz_init_set_str(l, argv[1], 10); /* Assume decimal integers */
    mpz_init_set_str(r, argv[2], 10); /* Assume decimal integers */
    mpz_init(p); /* initialize p and set its value to 0 */
    int len_l = mpz_sizeinbase(l, 10);
    int len = mpz_sizeinbase(l, 10) + mpz_sizeinbase(r, 10);
    printf("%.*s * %.*s \n", len_l, mpz_get_str(nullptr, 10, l),
           len, mpz_get_str(nullptr, 10, r));
    while(mpz_cmp_ui(l,0) > 0)  { // while the left hand side is not equal to zero
        gmp_printf("%-*Zd %*Zd\n", len_l, l, len - len_l, r); // format l and r
        if(mpz_odd_p(l) != 0) {
            mpz_add(p, p, r); // p = p + r
        }
        mpz_fdiv_q_ui(l,l,2); // l = l / 2; floor division rounds down to -infinity
        mpz_mul_ui(r, r, 2);    // r = r * 2
    }
    printf("Product = %s \n", mpz_get_str(nullptr, 10, p));
    return 0;
}