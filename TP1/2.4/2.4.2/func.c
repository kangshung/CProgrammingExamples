#include "func.h"

float convert(int choice_in, int choice_out, float input, float usd_eur, float usd_gbr, float eur_gbr)
{
    if (choice_in == 1 && choice_out == 1 ||
        choice_in == 2 && choice_out == 2 ||
        choice_in == 3 && choice_out == 3)
    {
        return input;
    }
    else if (choice_in == 1 && choice_out == 2)
    {
        return input * usd_eur;
    }
    else if (choice_in == 1 && choice_out == 3)
    {
        return input * usd_gbr;
    }
    else if (choice_in == 2 && choice_out == 3)
    {
        return input * eur_gbr;
    }
    else if (choice_in == 2 && choice_out == 1)
    {
        return input * (1 / usd_eur);
    }
    else if (choice_in == 3 && choice_out == 1)
    {
        return input * (1 / usd_gbr);
    }
    else if (choice_in == 3 && choice_out == 2)
    {
        return input * (1 / eur_gbr);
    }
}

void ask(int *choice_in, float *input, int *choice_out)
{
    printf("Choose the input currency:\n");
    printf("Press 1 for \u0024\n");
    printf("Press 2 for \u20AC\n");
    printf("Press 3 for \u00A3\n");
    scanf("%d", choice_in);
    printf("You selected %d\n\n", *choice_in);

    printf("Choose the input amount:\n");
    scanf("%f", input);

    printf("\nChoose the output currency:\n");
    printf("Press 1 for \u0024\n");
    printf("Press 2 for \u20AC\n");
    printf("Press 3 for \u00A3\n");
    scanf("%d", choice_out);
    printf("You selected %d\n\n", *choice_out);
}