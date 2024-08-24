#include <stdio.h>

void convertTemperature(char scale, double temp) {
    double converted;
    if (scale == 'C') {
        converted = (temp * 9/5) + 32;
        printf("%.2lf°C = %.2lf°F\n", temp, converted);
    } else if (scale == 'F') {
        converted = (temp - 32) * 5/9;
        printf("%.2lf°F = %.2lf°C\n", temp, converted);
    } else if (scale == 'K') {
        converted = temp - 273.15;
        printf("%.2lfK = %.2lf°C\n", temp, converted);
    } else {
        printf("Invalid scale!\n");
    }
}

int main() {
    char scale;
    double temperature;

    printf("Enter the temperature scale (C/F/K): ");
    scanf(" %c", &scale);
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    convertTemperature(scale, temperature);

    return 0;
}
