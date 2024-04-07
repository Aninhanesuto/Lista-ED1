typedef struct {
    double real;
    double img;
}complexo;

complexo complexo_novo(double real, double img);
complexo complexo_soma(complexo a, complexo b);
double complexo_absoluto(complexo a);

complexo complexo_le();
void complexo_imprime(complexo a);

int complexos_iguais(complexo a, complexo b);
complexo complexo_multiplicador(complexo a, complexo b);
complexo complexo_conjugado(complexo a);