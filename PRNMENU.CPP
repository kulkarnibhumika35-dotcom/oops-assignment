#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

enum Gender {
    M, F, TG
};

enum Class {
    FY = 1,
    SY,
    TY,
    BTECH
};

class Dept {
private:
    int did;
    char sf[18];
    char ff[100];
    int seq;

public:
    Dept();
    Dept(char s[], char f[]);
    void display();
    int get_did();
    char* get_sf();
    char* get_ff();
    int get_seq();
};

class Student {
private:
    unsigned long prn;
    char name[100];
    int year;
    Gender gen;
    Class _class;
    Dept dept;
    int isCancelled;
    static int seq;

public:
    Student();
    unsigned long get_prn();
    int get_iscancelled();
    void cancel_admission();
    void display();
};

int Student::seq = 1;

Dept::Dept() {
    cout << "Enter the short form of dept: ";
    cin >> sf;
    cout << endl;
    cout << "Enter the full form of dept: ";
    cin >> ff;
    cout << endl;
    did = 1; 
}

Dept::Dept(char s[], char f[]) {
    strcpy(sf, s);
    strcpy(ff, f);
    did = 1;
}

void Dept::display() {
    cout << did << " | " << sf << " | " << ff << endl;
}

int Dept::get_did() { return did; }
char* Dept::get_sf() { return sf; }
char* Dept::get_ff() { return ff; }
int Dept::get_seq() { return seq; }

Student::Student() {
    clrscr();
    cout << "Enter name: ";
    cin >> name;
    cout << endl;
    cout << "Enter Year of Admission (ex: 2025) = ";
    cin >> year;
    cout << endl;
    
    int ch;
    while(1) {
        cout << "Gender (0:M | 1:F | 2:TG) = ";
        cin >> ch;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cout << endl;
        if(ch >= 0 && ch <= 2) {
            switch(ch) {
                case 0: gen = M; break;
                case 1: gen = F; break;
                case 2: gen = TG; break;
            }
            break;
        }
    }

    while(1) {
        cout << "Class (1:FY | 2:SY | 3:TY | 4:BTECH) = ";
        cin >> ch;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cout << endl;
        if(ch >= 1 && ch <= 4) {
            switch(ch) {
                case 1: _class = FY; break;
                case 2: _class = SY; break;
                case 3: _class = TY; break;
                case 4: _class = BTECH; break;
            }
            break;
        }
    }

    prn = 100000000L + (year % 100L) * 1000000L + (long)_class * 100000L + (long)dept.get_did() * 10000L + seq++;
    isCancelled = 0;
}

unsigned long Student::get_prn() { return prn; }
int Student::get_iscancelled() { return isCancelled; }
void Student::cancel_admission() { isCancelled = 1; }

void Student::display() {
    cout << prn << endl;
    cout << name << endl;
    cout << year << endl;
    
    switch(gen) {
        case M: cout << "Male"; break;
        case F: cout << "Female"; break;
        case TG: cout << "TG"; break;
    }
    cout << endl;

    switch(_class) {
        case FY: cout << "FY"; break;
        case SY: cout << "SY"; break;
        case TY: cout << "TY"; break;
        case BTECH: cout << "BTECH"; break;
    }
    cout << endl;

    dept.display();
    cout << endl;
}

void main() {
    int choice;
    Student *students[50];
    Dept *depts[10];
    int studentCount = 0;
    int deptCount = 0;
    int i;

    depts[deptCount++] = new Dept("COMP", "Computer Engineering");

    do {
        clrscr();
        cout << "=== MAIN MENU ===" << endl;
        cout << "1) Student" << endl;
        cout << "2) Dept" << endl;
        cout << "3) Exit" << endl;
        cout << "Choice = ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int studentChoice;
                do {
                    clrscr();
                    cout << "--- Student Menu ---" << endl;
                    cout << "1. Admission" << endl;
                    cout << "2. Search student" << endl;
                    cout << "3. List all adm" << endl;
                    cout << "4. Cancel adm" << endl;
                    cout << "5. Display cant dept-wise" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "Choice = ";
                    cin >> studentChoice;

                    switch(studentChoice) {
                        case 1:
                            if(studentCount < 50) {
                                students[studentCount++] = new Student();
                                cout << "Admission Successful!" << endl;
                            } else {
                                cout << "Student limit reached!" << endl;
                            }
                            getch();
                            break;
                        case 2: {
                            unsigned long targetPrn;
                            int found = 0;
                            cout << "Enter PRN to search: ";
                            cin >> targetPrn;
                            for(i = 0; i < studentCount; i++) {
                                if(students[i]->get_prn() == targetPrn) {
                                    students[i]->display();
                                    found = 1;
                                    break;
                                }
                            }
                            if(!found) cout << "Student not found!" << endl;
                            getch();
                            break;
                        }
                        case 3:
                            clrscr();
                            cout << "--- All Admissions ---" << endl;
                            for(i = 0; i < studentCount; i++) {
                                students[i]->display();
                            }
                            getch();
                            break;
                        case 4: {
                            unsigned long targetPrn;
                            int found = 0;
                            cout << "Enter PRN to cancel admission: ";
                            cin >> targetPrn;
                            for(i = 0; i < studentCount; i++) {
                                if(students[i]->get_prn() == targetPrn) {
                                    students[i]->cancel_admission();
                                    cout << "Admission cancelled successfully." << endl;
                                    found = 1;
                                    break;
                                }
                            }
                            if(!found) cout << "Student not found!" << endl;
                            getch();
                            break;
                        }
                        case 5:
                            clrscr();
                            cout << "--- Department-wise Cancelled/Active Summary ---" << endl;
                            for(i = 0; i < studentCount; i++) {
                                cout << "PRN: " << students[i]->get_prn() 
                                     << " | Status: " << (students[i]->get_iscancelled() ? "Cancelled" : "Active") << endl;
                            }
                            getch();
                            break;
                    }
                } while(studentChoice != 6);
                break;
            }
            case 2: {
                int deptChoice;
                do {
                    clrscr();
                    cout << "--- Dept Menu ---" << endl;
                    cout << "1) Add dept" << endl;
                    cout << "2) List all depts" << endl;
                    cout << "3) Back to Main Menu" << endl;
                    cout << "Choice = ";
                    cin >> deptChoice;

                    switch(deptChoice) {
                        case 1:
                            if(deptCount < 10) {
                                depts[deptCount++] = new Dept();
                                cout << "Department added successfully!" << endl;
                            } else {
                                cout << "Department limit reached!" << endl;
                            }
                            getch();
                            break;
                        case 2:
                            clrscr();
                            cout << "--- All Departments ---" << endl;
                            for(i = 0; i < deptCount; i++) {
                                depts[i]->display();
                            }
                            getch();
                            break;
                    }
                } while(deptChoice != 3);
                break;
            }
        }
    } while(choice != 3);
}