#include <iostream>
#include <cstring>
using namespace std;

//cricketer(base class)
class Cricketer {
protected:
    char name[50];

public:
    void inputBasic() {
        cout << "Name: ";
        cin >> name;
    }
};

//batsman
class Batsman : virtual public Cricketer {
protected:
    int runs[10];
    char country[10][50];
    int matches;

public:
    void inputBatting() {
        cout << "Number of matches: ";
        cin >> matches;
        for (int i = 0; i < matches; i++) {
            cout << "Country & runs: ";
            cin >> country[i] >> runs[i];
        }
    }

    double battingAverage() {
        int sum = 0;
        for (int i = 0; i < matches; i++)
            sum += runs[i];
        return (double)sum / matches;
    }

    void highestRuns() {
        int max = runs[0], idx = 0;
        for (int i = 1; i < matches; i++) {
            if (runs[i] > max) {
                max = runs[i];
                idx = i;
            }
        }
        cout << "Highest runs vs " << country[idx] << ": " << max << endl;
    }
};

//bowler
class Bowler : virtual public Cricketer {
protected:
    int wickets[10];
    char countryW[10][50];

public:
    void inputBowling() {
        for (int i = 0; i < 10; i++) {
            cout << "Country & wickets: ";
            cin >> countryW[i] >> wickets[i];
        }
    }

    int totalWickets() {
        int sum = 0;
        for (int i = 0; i < 10; i++)
            sum += wickets[i];
        return sum;
    }

    void highestWickets() {
        int max = wickets[0], idx = 0;
        for (int i = 1; i < 10; i++) {
            if (wickets[i] > max) {
                max = wickets[i];
                idx = i;
            }
        }
        cout << "Highest wickets vs " << countryW[idx] << ": " << max << endl;
    }
};

//all rounder
class AllRounder : public Batsman, public Bowler {
public:
    void insertRecords() {
        inputBasic();
        inputBatting();
        inputBowling();
    }

    void displayStats() {
        cout << "\nPlayer: " << name << endl;
        cout << "Batting Avg: " << battingAverage() << endl;
        cout << "Total Wickets: " << totalWickets() << endl;
        highestRuns();
        highestWickets();
    }
};

int main() {
    AllRounder a;
    a.insertRecords();
    a.displayStats();

    return 0;
}