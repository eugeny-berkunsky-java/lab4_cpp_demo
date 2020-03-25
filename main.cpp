#include <iostream>
#include <fstream>

using namespace std;

struct Person {
    int id{};
    string name;
    string city;
    int year{};
};

int menu();

void print(Person *p, int count);

Person *fillPeople(int &count);

void findByYear(int year, Person *p, int count);

void printOne(Person person);

void findByCity(string city, Person *people, int count);

Person *readFromTextFile(string filename, int &count);

void sort(Person * p, int count);

int main() {
    int count = 0;
    Person *people = fillPeople(count);
    int m;
    while ((m = menu())) {
        switch (m) {
            case 1: {
                print(people, count);
                break;
            }
            case 2: {
                cout << "Year:";
                int year;
                cin >> year;
                findByYear(year, people, count);
                break;
            }
            case 3: {
                cout << "City:";
                string city;
                cin >> city;
                findByCity(city, people, count);
                break;
            }
            case 4: {
                people = readFromTextFile("file.txt", count);
                break;
            }
            case 5: {
                sort(people, count);
                print(people, count);
                break;
            }
            default: {
                cout << "Error. Try again!\n";
            }
        }
    }
}

void sort(Person * p, int count) {
    for (int i = 0; i < count-1; i++) {
        int k = i;
        for (int j = i+1; j < count; j++) {
            if (p[j].name < p[k].name) {
                k = j;
            }
        }
        if (k!=i) {
            Person t = p[k];
            p[k] = p[i];
            p[i] = t;
        }
    }
}

Person *readFromTextFile(string filename, int &count) {
    ifstream fin(filename);
    fin >> count;
    Person * p = new Person[count];
    for (int i = 0; i < count; ++i) {
        fin >> p[i].id >> p[i].name >> p[i].city >> p[i].year;
    }
    return p;
}

void findByCity(string city, Person *people, int count) {
    for (int i = 0; i < count; i++) {
        if (people[i].city == city) {
            printOne(people[i]);
        }
    }
    cout << "-----------------------" << endl;
}

void findByYear(int year, Person *people, int count) {
    for (int i = 0; i < count; i++) {
        if (people[i].year > year) {
            printOne(people[i]);
        }
    }
    cout << "-----------------------" << endl;
}

void printOne(Person p) {
    cout << p.id << " " << p.name << " " << p.city << " " << p.year << endl;
}

Person *fillPeople(int &count) {
    count = 6;
    return new Person[count]{
            {1, "Ivan",  "Nikolaev", 2000},
            {2, "Alex",  "Kiev",     2001},
            {3, "Serg",  "Nikolaev", 2002},
            {4, "Petr",  "Odessa",   2001},
            {5, "Vasya", "Nikolaev", 2003},
            {6, "Nik",   "Kiev",     2002}
    };
}

int menu() {
    cout << "1. Print all" << endl;
    cout << "2. Find by year" << endl;
    cout << "3. Find by city" << endl;
    cout << "4. Read from file" << endl;
    cout << "5. Sort" << endl;
    cout << "0. Exit" << endl;
    int n;
    cin >> n;
    return n;
}

void print(Person *p, int count) {
    for (int i = 0; i < count; i++) {
        printOne(p[i]);
    }
    cout << "------------------------" << endl;
}
