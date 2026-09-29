#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <clocale>

using namespace std;

class Angle
{
private:
    int degrees;
    int minutes;

    int totalMinutes() const
    {
        return degrees * 60 + minutes;
    }

    void normalize()
    {
        int total = totalMinutes();
        const int fullCircle = 360 * 60;

        total %= fullCircle;

        if (total < 0)
            total += fullCircle;

        degrees = total / 60;
        minutes = total % 60;
    }

public:
    Angle()
    {
        degrees = 0;
        minutes = 0;
    }

    Angle(int d, int m)
    {
        degrees = d;
        minutes = m;
        normalize();
    }

    void Init(int d = 0, int m = 0)
    {
        degrees = d;
        minutes = m;
        normalize();
    }

    void Read()
    {
        cout << "Введіть градуси: ";
        cin >> degrees;

        cout << "Введіть хвилини: ";
        cin >> minutes;

        normalize();
    }

    void Display() const
    {
        cout << degrees << "° " << minutes << "'" << endl;
    }

    string toString() const
    {
        ostringstream out;

        out << degrees << "° " << minutes << "'";

        return out.str();
    }

    double toRadians() const
    {
        const double PI = 3.14159265358979323846;

        double angleInDegrees =
            degrees + minutes / 60.0;

        return angleInDegrees * PI / 180.0;
    }

    void normalizeAngle()
    {
        normalize();
    }

    void increase(int d, int m)
    {
        int total = totalMinutes() + d * 60 + m;

        degrees = total / 60;
        minutes = total % 60;

        normalize();
    }

    void decrease(int d, int m)
    {
        int total = totalMinutes() - d * 60 - m;

        degrees = total / 60;
        minutes = total % 60;

        normalize();
    }

    double sine() const
    {
        return sin(toRadians());
    }

    int compare(const Angle& other) const
    {
        int thisAngle = totalMinutes();
        int otherAngle = other.totalMinutes();

        if (thisAngle < otherAngle)
            return -1;

        if (thisAngle > otherAngle)
            return 1;

        return 0;
    }

    bool operator==(const Angle& other) const
    {
        return compare(other) == 0;
    }

    bool operator<(const Angle& other) const
    {
        return compare(other) < 0;
    }

    bool operator>(const Angle& other) const
    {
        return compare(other) > 0;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Angle angle1;

    cout << "=== Введення першого кута ===" << endl;
    angle1.Read();

    cout << endl;
    cout << "Перший кут: ";
    angle1.Display();

    cout << fixed << setprecision(6);

    cout << "Радіани: "
        << angle1.toRadians() << endl;

    cout << "Синус: "
        << angle1.sine() << endl;

    angle1.increase(10, 30);

    cout << endl;
    cout << "Після збільшення на 10° 30': ";
    angle1.Display();

    angle1.decrease(5, 15);

    cout << "Після зменшення на 5° 15': ";
    angle1.Display();

    Angle angle2;

    cout << endl;
    cout << "=== Введення другого кута ===" << endl;
    angle2.Read();

    cout << "Другий кут: ";
    angle2.Display();

    cout << endl;
    cout << "=== Порівняння кутів ===" << endl;

    if (angle1 == angle2)
    {
        cout << "Кути рівні." << endl;
    }
    else if (angle1 > angle2)
    {
        cout << "Перший кут більший за другий." << endl;
    }
    else
    {
        cout << "Перший кут менший за другий." << endl;
    }

    cout << endl;
    cout << "Результат toString() для першого кута: "
        << angle1.toString() << endl;

    return 0;
}