#include <iostream>
#include <limits>
#include <cstdlib>  // for abs
using namespace std;

void param_84();

void begin_16();
void calculateDistance();
void inputCoordinates();

void boolean_2();
void checkIfOdd();

int main() {
    int choice = 0;

    while (choice != 4) {

        cout << endl;
        cout << "Choose task: "
            "\n1 - Param84"
            "\n2 - Begin16"
            "\n3 - Boolean2"
            "\n4 - Exit"
            "\n" << endl;

        cin >> choice;

        switch (choice) {
        case 1: {
            param_84();
            break;
        }
        case 2: {
            begin_16();
            break;
        }
        case 3: {
            boolean_2();
            break;
        }
        case 4: {
            cout << "Exit";
            break;
        }
        default: {
            cout << "Wrong number,try again";
        }
        }
    }
}
//task selector

// task param84 start
struct TTime {
    int Hour;
    int Min;
    int Sec;
};

// Function for value check 
bool isValidTime(TTime t) {
    return (t.Hour >= 0 && t.Hour < 24 && t.Min >= 0 && t.Min < 60 && t.Sec >= 0 && t.Sec < 60);// value settings
}

// Function for entring values
TTime inputTime() {
    TTime t;
    cout << "Enter value (hour minutes seconds): " << endl;
    cin >> t.Hour >> t.Min >> t.Sec;

    // value check
    while (!isValidTime(t)) { 
        cout << "Incorrect value: " << endl;
        cin >> t.Hour >> t.Min >> t.Sec;
    }

    return t;
}

// function to change time
TTime SubHour(TTime t, int n) {
    if (!isValidTime(t)) {
        return t;  // return without changes if value incorrect
    }

    t.Hour -= n;

    // configure value of time if it goes out of 0 - 23
    while (t.Hour < 0) {
        t.Hour += 24;
    }
    while (t.Hour >= 24) {
        t.Hour -= 24;
    }

    return t;
}

//output function
void param_84() {
    TTime times[5];
    int n;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter " << i + 1 << " moment of time:" << endl;
        times[i] = inputTime();
    }

    cout << "Enter the time value for subtracting: " << endl;
    cin >> n;

    cout << "New moment of time:" << endl;
    for (int i = 0; i < 5; ++i) {
        TTime newTime = SubHour(times[i], n);
        cout << "New time " << i + 1 << ": " << newTime.Hour << ":" << newTime.Min << ":" << newTime.Sec << endl;
    }
}
// task param84 output

// task begin16 start
struct Point {
    int x1;
    int x2;
    int distance;
};

// Function for check correct values
bool validateInput(int& x) {
    cin >> x;
    if (cin.fail()) {
        cin.clear(); // restore flow state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore incorrect entrence 
        return false; // entering values incorrect 
    }
    return true;
}

// Function for calculate distance between coordinates
void calculateDistance(Point& p) {
    p.distance = abs(p.x2 - p.x1);
}

// function for enter coordinate and correct check
void inputCoordinates(Point& p) {
    cout << "Enter coordinate x1: ";
    while (!validateInput(p.x1)) {
        cout << "Invalid input. Enter an integer for coordinate x1: ";
    }

    cout << "Enter coordinate x2: ";
    while (!validateInput(p.x2)) {
        cout << "Invalid input. Enter an integer for coordinate x2: ";
    }
}

void begin_16() {
    Point p;

    inputCoordinates(p);
    calculateDistance(p);

    // output results
    cout << "Distance between points: " << p.distance << endl;
}
// task begin16 output

// task boolean_2 start
struct Data {
    int input;      
    bool isOdd;     
};

void checkIfOdd(Data& data) {
    data.isOdd = (data.input % 2 != 0);
}

bool inputData(Data& data) {
    cout << "enter the whole number : ";
    if (cin >> data.input) {
        return true;  // if entering data is correct
    }
    else {
        cin.clear(); // restore flow state 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore incorrect entrance
        return false; // entering values incorrect 
    }
}

void boolean_2() {
    Data data;
    if (inputData(data)) {
        checkIfOdd(data);
        cout << "value " << data.input << (data.isOdd ? " paired." : " unpaired.") << endl;
    }
    else {
        cout << "entered incorrect value." << endl;
    }
}
//task boolean_2 output