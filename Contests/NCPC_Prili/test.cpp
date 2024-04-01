#include <iostream>
using namespace std;

// Function to calculate the day of the week using Zeller's Congruence algorithm
int calculateDayOfWeek(int day, int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year--;
    }

    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;

    int h = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // h = 0 corresponds to Saturday, 1 corresponds to Sunday, ..., 6 corresponds to Friday
    // Mapping these values to the days of the week
    switch (h)
    {
    case 0:
        return 6; // Saturday
    case 1:
        return 0; // Sunday
    case 2:
        return 1; // Monday
    case 3:
        return 2; // Tuesday
    case 4:
        return 3; // Wednesday
    case 5:
        return 4; // Thursday
    case 6:
        return 5; // Friday
    default:
        return -1; // Invalid
    }
}

int main()
{
    int day =20;     // 1st of January
    int month = 2;   // January
    int year = 2024; // 2024

    int dayOfWeek = calculateDayOfWeek(day, month, year);

    cout << "January 1, " << year << " is a ";
    switch (dayOfWeek)
    {
    case 0:
        cout << "Sunday.";
        break;
    case 1:
        cout << "Monday.";
        break;
    case 2:
        cout << "Tuesday.";
        break;
    case 3:
        cout << "Wednesday.";
        break;
    case 4:
        cout << "Thursday.";
        break;
    case 5:
        cout << "Friday.";
        break;
    case 6:
        cout << "Saturday.";
        break;
    default:
        cout << "Invalid.";
        break;
    }
    cout << endl;

    return 0;
}
