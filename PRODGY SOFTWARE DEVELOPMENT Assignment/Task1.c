#include <stdio.h>

int main()
{
    double temperature;
    char unit;

    // Prompt user for input
    printf("Enter temperature value: ");
    scanf("%lf", &temperature);

    // Prompt user for unit of measurement
    printf("Enter unit of measurement (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &unit);

    // Perform conversions
    double convertedToFahrenheit, convertedToKelvin, convertedToCelsius;

    switch (unit)
    {
    case 'C':
    case 'c':
        convertedToFahrenheit = (temperature * 9 / 5) + 32;
        convertedToKelvin = temperature + 273.15;
        printf("%.2f Celsius is %.2f Fahrenheit and %.2f Kelvin\n", temperature, convertedToFahrenheit, convertedToKelvin);
        break;

    case 'F':
    case 'f':
        convertedToCelsius = (temperature - 32) * 5 / 9;
        convertedToKelvin = (temperature - 32) * 5 / 9 + 273.15;
        printf("%.2f Fahrenheit is %.2f Celsius and %.2f Kelvin\n", temperature, convertedToCelsius, convertedToKelvin);
        break;

    case 'K':
    case 'k':
        convertedToCelsius = temperature - 273.15;
        convertedToFahrenheit = (temperature - 273.15) * 9 / 5 + 32;
        printf("%.2f Kelvin is %.2f Celsius and %.2f Fahrenheit\n", temperature, convertedToCelsius, convertedToFahrenheit);
        break;

    default:
        printf("Invalid unit of measurement. Please enter C, F, or K.\n");
        break;
    }

    return 0;
}