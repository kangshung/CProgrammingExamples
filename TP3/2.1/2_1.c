#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    float mu = atof(argv[1]);
    float sigma = atof(argv[2]);
    int samples = atoi(argv[3]);

    float consts = 1 / sqrt(2 * acos(-1.0));
    float lower = mu - 3 * sigma;
    float upper = mu + 3 * sigma;

    char command[999];
    sprintf(command, "gnuplot -p -e ';\
    normal(x, mu, sigma) = sigma <= 0 ? 1 / 0 : %f / sigma * exp(-0.5 * ((x - mu) / sigma) ** 2);\
    set samples %d;\
    plot [%f:%f] normal(x, %f, %f) w p'",
            consts, samples, lower, upper, mu, sigma);

    system(command);
}