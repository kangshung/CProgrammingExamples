#include "func.h"

int main()
{
    float usd_eur = .85, usd_gbr = .76, eur_gbr = .89, input, converted;
    int choice_in, choice_out, known_own;

    printf("\nKnown exchange rates:\n");
    printf("\u0024 to \u20AC = %f\n", usd_eur);
    printf("\u0024 to \u00A3 = %f\n", usd_gbr);
    printf("\u20AC to \u00A3 = %f\n", eur_gbr);

    printf("Do you wish to use the above known rates (press 1) or to rather insert your own (press 2)?\n");
    scanf("%d", &known_own);

    if (known_own == 1)
    {
        printf("You have selected to use the pre-set rates\n\n");
        ask(&choice_in, &input, &choice_out);
        converted = convert(choice_in, choice_out, input, usd_eur, usd_gbr, eur_gbr);
        printf("Converted value is %f\n", converted);
    }
    else if (known_own == 2)
    {
        printf("You have selected to provide your own rates\n\n");
        printf("Please provide the exchange rate \u0024 to \u20AC\n");
        scanf("%f", &usd_eur);
        printf("Please provide the exchange rate \u0024 to \u00A3\n");
        scanf("%f", &usd_gbr);
        printf("Please provide the exchange rate \u20AC to \u00A3\n");
        scanf("%f", &eur_gbr);

        printf("\nNew exchange rates:\n");
        printf("\u0024 to \u20AC = %f\n", usd_eur);
        printf("\u0024 to \u00A3 = %f\n", usd_gbr);
        printf("\u20AC to \u00A3 = %f\n\n", eur_gbr);

        ask(&choice_in, &input, &choice_out);
        converted = convert(choice_in, choice_out, input, usd_eur, usd_gbr, eur_gbr);
        printf("Converted value is %f\n", converted);
    }
    else
    {
        printf("Closing...Wrong value.\n");
        return 0;
    }
}
