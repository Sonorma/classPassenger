#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;



void capitalize(string& s)
{
    bool cap = true;

    for (unsigned int i = 0; i <= s.length(); i++)
    {
        if (islower(s[i]) && cap == true)
        {
            s[i] = toupper(s[i]);
            cap = false;
        }
        else if (isspace(s[i]))
        {
            cap = true;
        }
    }
}

class passenger
{
private:
    string surname;
    string name;
    int age;
    string depart_city;
    string arrive_city;
    float cost;
public:
    passenger() {
        surname = "null";
        name = "null";
        age = 0;
        depart_city = "null";
        arrive_city = "null";
        cost = 0;
    }

    passenger(const passenger& x) {
        surname = x.surname;
        name = x.name;
        age = x.age;
        depart_city = x.depart_city;
        arrive_city = x.arrive_city;
        cost = x.cost;
    }


    friend string getSurname(const passenger& x) { return x.surname; }
    friend string getName(const passenger& x) { return x.name; }
    friend int getAge(const passenger& x) { return x.age; }
    friend string getDepartCity(const passenger& x) { return x.depart_city; }
    friend string getArriveCity(const passenger& x) { return x.arrive_city; }
    friend float getCost(const passenger& x) { return x.cost; }
    friend void changeSurname(passenger& x, string y);
    friend void changeName(passenger& x, string y);
    friend void changeAge(passenger& x, int y);
    friend void changeDepartCity(passenger& x, string y);
    friend void changeArriveCity(passenger& x, string y);
    friend void changeCost(passenger& x, int y);
    friend float sumCost(passenger arr[], int n, string city);
    friend int sumPassFromCity(passenger arr[], int n, string city);

    friend istream& operator>> (istream& is, passenger& x);
    friend ostream& operator<< (ostream& os, const passenger& x);
    bool operator> (const passenger& x)const {
        if (surname != x.surname)
        {
            return surname > x.surname;
        }
        else if (surname == x.surname)
        {
            return name > x.name;
        }
    }

    bool operator>= (const passenger& x)const {
        if (surname != x.surname)
        {
            return surname >= x.surname;
        }
        else if (surname == x.surname)
        {
            return name >= x.name;
        }
    }

    bool operator< (const passenger& x)const {
        if (surname != x.surname)
        {
            return surname < x.surname;
        }
        else if (surname == x.surname)
        {
            return name < x.name;
        }
    }

    bool operator<= (const passenger& x)const {
        if (surname != x.surname)
        {
            return surname <= x.surname;
        }
        else if (surname == x.surname)
        {
            return name <= x.name;
        }
    }

    passenger operator* (float y) {
        passenger costchange;
        cost = y;
        return costchange;
    }
};


istream& operator>> (istream& is, passenger& x) {
    is >> x.surname >> x.name >> x.age >> x.depart_city >> x.arrive_city >> x.cost;
    // is.ignore(1,'\n');
    // getline(is,x.depart_city);
    // getline(is,x.arrive_city);
    // is >> x.cost;
    capitalize(x.surname);
    capitalize(x.name);
    capitalize(x.depart_city);
    capitalize(x.arrive_city);
    return is;
}

ostream& operator<< (ostream& os, const passenger& x) {
    os << "Surname: " << x.surname << endl
        << "Name: " << x.name << endl
        << "Age: " << x.age << endl
        << "Depart city: " << x.depart_city << endl
        << "Arrive city: " << x.arrive_city << endl
        << "Cost of the ticket: " << x.cost << endl;
    return os;
}

void changeSurname(passenger& x, string y) {
    capitalize(y);
    x.surname = y;
}
void changeName(passenger& x, string y) {
    capitalize(y);
    x.name = y;
}
void changeAge(passenger& x, int y) { x.age = y; }
void changeDepartCity(passenger& x, string y) {
    capitalize(y);
    x.depart_city = y;
}
void changeArriveCity(passenger& x, string y) {
    capitalize(y);
    x.surname = y;
}
void changeCost(passenger& x, int y) { x.cost = y; }


void swap(passenger& xp, passenger& yp)
{
    passenger temp = xp;
    xp = yp;
    yp = temp;
}

void bubbleSort(passenger arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

float sumCost(passenger arr[], int n, string city)
{
    float sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (getArriveCity(arr[i]) == city)
        {
            sum += getCost(arr[i]);
        }
    }
    return sum;
}

int sumPassFromCity(passenger arr[], int n, string city)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (getDepartCity(arr[i]) == city)
        {
            count++;
        }
    }
    return count;
}




int main()
{
    ifstream file("db.txt");
    passenger passengerArray[25];
    for (int i = 0; i < 25; i++)
    {
        file >> passengerArray[i];
    }

    ifstream file2("db.txt");
    passenger alphabet[25];
    for (int i = 0; i < 25; i++)
    {
        file2 >> alphabet[i];
    }


    bubbleSort(alphabet, 25);

    for (int i = 0; i < 25; i++)
    {
        //cout << alphabet[i];
    }


    int n = 0;
    int age = getAge(passengerArray[0]);
    for (size_t i = 0; i < 25; i++)
    {
        if (getAge(passengerArray[i]) < age)
        {
            age = getAge(passengerArray[i]);
            n = i;
        }
    }
    cout << "Smallest boi: \n \n" << passengerArray[n];

    n = 0;
    float cost = getCost(passengerArray[0]);
    for (size_t i = 0; i < 25; i++)
    {
        if (getCost(passengerArray[i]) > cost)
        {
            cost = getCost(passengerArray[i]);
            n = i;
        }
    }

    cout << "4/10:" << getCost(passengerArray[n]) << endl;

    cout << "vvedit misto:";
    string cc;
    cin >> cc;
    capitalize(cc);
    cout << "overall cost for " << cc << ":" << sumCost(passengerArray, 25, cc) << endl;
    cout << "vvedit misto vidpravlennya:";
    string ccc;
    cin >> ccc;
    capitalize(ccc);
    cout << "Amount of passengers from " << ccc << ": " << sumPassFromCity(passengerArray, 25, ccc);
}

