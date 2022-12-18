#include <iostream>
using namespace std;

int main ()
{
    int horasC = 0;
    int minutesC = 0;
    int valFinal = 0;

    int values [2];
    for (int i=0;i<=2;i++){
        cin >> values[i];
    }

    horasC = values[0] * 3600;
    minutesC = values[1] * 60;
    valFinal = horasC + minutesC + values[2];

    cout << valFinal;
    return 0;
}