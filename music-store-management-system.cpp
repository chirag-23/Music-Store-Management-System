/*
<-----music store management system----->
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class music
{
    string genre, name, artist;
    int year, price, quantity;

public:
    void menu();
    void insert();
    void display_avl();
    void display_sold();
    void search();
    void modify();
    void delet(string);
    void sell(string);
};

void music::menu()
{
menustart: // label
    int choice;
    char x;
    system("cls"); // used to pause screen. clear screen
    cout << "\t\t\t<-----MUSIC STORE MANAGEMENT SYSTEM----->\n\n";
    cout << "\t\t\t\t1. Add new record\n";
    cout << "\t\t\t\t2. Display all available records\n";
    cout << "\t\t\t\t3. Display sold music records\n";
    cout << "\t\t\t\t4. Search music record\n";
    cout << "\t\t\t\t5. Modify music record details\n";
    cout << "\t\t\t\t6. Delete specific record from system\n";
    cout << "\t\t\t\t7. Selling the record\n";
    cout << "\t\t\t\t8. Exit\n";
    cout << endl;
    cout << "\t\t\t\tEnter your choice->";
    cin >> choice;
    cout << endl;
    string nam;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\t\t\tEnter another music(Y/N):";
            cin >> x;
        } while (x == 'Y');
        break;
    case 2:
        display_avl();
        break;
    case 3:
        display_sold();
        break;
    case 4:
        search();
        break;
    case 5:
        modify();
        break;
    case 6:
        cout << "\t\t\tEnter name of song:";
        cin >> nam;
        delet(nam);
        break;
    case 7:
        cout << "\t\tEnter name of song of which CD you want to sell:";
        cin >> nam;
        sell(nam);
        break;
    case 8:
            cout<<"Created by Chirag Chouhan (GitHub~Chirag-23) and Ankit Nain (GitHub~iankitnain)\n\n"<<endl;
        exit(0); // termination of program
    default:
        cout << "\t\t\tINVALID CHOICE!!!!";
        break;
    }
    goto menustart;
}

void music::insert()
{
    system("cls");
    fstream file;
    cout << "\t\t<--Music Record detail-->\n";
    cout << "\t\t\t1. Year:";
    cin >> year;
    cout << "\t\t\t2. Genre:";
    cin >> genre;
    cout << "\t\t\t3. Name:";
    cin >> name;
    cout << "\t\t\t4. Artist:";
    cin >> artist;
    cout << "\t\t\t5. Price:";
    cin >> price;
    cout << "\t\t\t6. Quantity:";
    cin >> quantity;
    file.open("MusicRecords.txt", ios::app | ios::out); // ios::app-> to add details at end of the file
    file << year << " " << genre << " " << name << " "
         << " " << artist << " " << price << " " << quantity << "\n";
    file.close();
}

void music::display_avl()
{
    int number = 1;
    system("cls");
    fstream file;
    file.open("MusicRecords.txt", ios::in);
    cout << "\t\t\t*****AVAILABLE MUSIC RECORD*****\n\n\n";
    if (file)
    {
        file >> year >> genre >> name >> artist >> price >> quantity;
        while (!file.eof()) // end of file
        {
            cout << "\t\t\t\tRecord No.         : " << number++ << "\n";
            cout << "\t\t\t\tYear of release    : " << year << "\n";
            cout << "\t\t\t\tRecord genre       : " << genre << "\n";
            cout << "\t\t\t\tName of record     : " << name << "\n";
            cout << "\t\t\t\tName of artist     : " << artist << "\n";
            cout << "\t\t\t\tPrice of 1 CD/DVD  : " << price << "\n";
            cout << "\t\t\t\tQuantity available : " << quantity << "\n\n";
            file >> year >> genre >> name >> artist >> price >> quantity;
        }
        file.close();
    }
    else
    {
        cout << "\t\t\tNo music record present at the time!!!";
        file.close();
    }
}

void music::display_sold()
{
    system("cls");
    cout << "\t\t\t*****SOLD MUSIC RECORD*****\n\n\n";
    int number = 1;
    fstream file;
    file.open("SoldRecords.txt", ios::in);
    if (file)
    {
        file >> year >> genre >> name >> artist >> price >> quantity;
        while (!file.eof()) // end of file
        {
            cout << "\t\t\t\tSold item        : " << number++ << "\n";
            cout << "\t\t\t\tYear of release  : " << year << "\n";
            cout << "\t\t\t\tRecord genre     : " << genre << "\n";
            cout << "\t\t\t\tName of record   : " << name << "\n";
            cout << "\t\t\t\tName of artist   : " << artist << "\n";
            cout << "\t\t\t\tPrice of 1 CD/DVD: " << price << "\n";
            cout << "\t\t\t\tQuantity sold    : " << quantity << "\n\n";
            file >> year >> genre >> name >> artist >> price >> quantity;
        }
        file.close();
    }
    else
    {
        cout << "\t\t\tNo music record present at the time!!!";
        file.close();
    }
}

void music::search()
{
    system("cls");
    fstream file;
    file.open("MusicRecords.txt", ios::in);
    string nm;
    bool flag = false;
    if (file)
    {
        cout << "\t\t\tEnter name of the record:";
        cin >> nm;
        cout << endl;
        file >> year >> genre >> name >> artist >> price >> quantity;
        while (!file.eof())
        {
            if (nm == name)
            {
                cout << "\t\t\t\tYear of release    : " << year << "\n";
                cout << "\t\t\t\tRecord genre       : " << genre << "\n";
                cout << "\t\t\t\tName of record     : " << name << "\n";
                cout << "\t\t\t\tName of artist     : " << artist << "\n";
                cout << "\t\t\t\tPrice of 1 CD/DVD  : " << price << "\n";
                cout << "\t\t\t\tQuantity available : " << quantity << "\n\n";
                flag = true;
            }
            file >> year >> genre >> name >> artist >> price >> quantity;
        }
        file.close();
        if (!flag)
        {
            cout << "\t\t\tNo record present of this name!!\n";
        }
    }
    else
    {
        cout << "\t\t\tNo music record present at the time!!!";
    }
}

void music::modify()
{
    system("cls");
    fstream file1, file2;
    string nm;
    bool flag = false;
    file1.open("MusicRecords.txt", ios::in);
    if (file1)
    {
        cout << "\t\t\tEnter name of the record:";
        cin >> nm;
        file2.open("Records.txt", ios::app | ios::out);
        file1 >> year >> genre >> name >> artist >> price >> quantity;
        char y;
        while (!file1.eof())
        {
            if (nm == name)
            {
                cout << "\t\t\t\tYear of release    : " << year << "\n";
                cout << "\t\t\t\tRecord genre       : " << genre << "\n";
                cout << "\t\t\t\tName of record     : " << name << "\n";
                cout << "\t\t\t\tName of artist     : " << artist << "\n";
                cout << "\t\t\t\tPrice of 1 CD/DVD  : " << price << "\n";
                cout << "\t\t\t\tQuantity available : " << quantity << "\n\n";
                cout << "\t\tDo you want to modify this song(Y/N):";
                cin >> y;
                if (y == 'Y')
                {
                    cout << "\t\t\t\t1. Year:";
                    cin >> year;
                    cout << "\t\t\t\t2. Genre:";
                    cin >> genre;
                    cout << "\t\t\t\t3. Name:";
                    cin >> name;
                    cout << "\t\t\t\t4. Artist:";
                    cin >> artist;
                    cout << "\t\t\t\t5. Price:";
                    cin >> price;
                    cout << "\t\t\t\t6. Quantity:";
                    cin >> quantity;
                    file2 << year << " " << genre << " " << name << " "
                          << " " << artist << " " << price << " " << quantity << "\n";
                }
                flag = true;
            }
            else
            {
                file2 << year << " " << genre << " " << name << " "
                      << " " << artist << " " << price << " " << quantity << "\n";
            }
            file1 >> year >> genre >> name >> artist >> price >> quantity;
        }
        file2.close();
        file1.close();
        remove("MusicRecords.txt");
        rename("Records.txt", "MusicRecords.txt");
        if (!flag)
        {
            cout << "\t\t\tNo record available of this name!!!\n";
        }
    }
    else
    {
        cout << "\t\t\tNo data is found!!!\n";
        file1.close();
    }
}

void music::delet(string nm)
{
    system("cls");
    fstream file1, file2;
    bool flag = false;
    file1.open("MusicRecords.txt", ios::in);
    if (file1)
    {
        file2.open("Records.txt", ios::app | ios::out);
        file1 >> year >> genre >> name >> artist >> price >> quantity;
        char y;
        while (!file1.eof())
        {
            if (nm == name)
            {
                cout << "\t\t\t\tYear of release    : " << year << "\n";
                cout << "\t\t\t\tRecord genre       : " << genre << "\n";
                cout << "\t\t\t\tName of record     : " << name << "\n";
                cout << "\t\t\t\tName of artist     : " << artist << "\n";
                cout << "\t\t\t\tPrice of 1 CD/DVD  : " << price << "\n";
                cout << "\t\t\t\tQuantity available : " << quantity << "\n\n";
                cout << "\t\tDo you want to delete this song(Y/N):";
                cin >> y;
                if (y == 'N')
                {
                    file2 << year << " " << genre << " " << name << " "
                          << " " << artist << " " << price << " " << quantity << "\n";
                }
                flag = true;
            }
            else
            {
                file2 << year << " " << genre << " " << name << " "
                      << " " << artist << " " << price << " " << quantity << "\n";
            }
            file1 >> year >> genre >> name >> artist >> price >> quantity;
        }
        file2.close();
        file1.close();
        remove("MusicRecords.txt");
        rename("Records.txt", "MusicRecords.txt");
        if (!flag)
        {
            cout << "\t\t\tNo song available of this name!!!\n";
        }
    }
    else
    {
        cout << "\t\t\tNo data is found!!!\n";
        file1.close();
    }
}

void music::sell(string nm)
{
    system("cls");
    fstream file1, file2, file3;
    bool flag = false;
    file1.open("MusicRecords.txt", ios::in);
    if (file1)
    {
        file3.open("SoldRecords.txt", ios::app | ios::out);
        file2.open("Records.txt", ios::app | ios::out);
        file1 >> year >> genre >> name >> artist >> price >> quantity;
        char y;
        while (!file1.eof())
        {
            if (nm == name)
            {
                cout << "\t\t\t\tYear of release    : " << year << "\n";
                cout << "\t\t\t\tRecord genre       : " << genre << "\n";
                cout << "\t\t\t\tName of record     : " << name << "\n";
                cout << "\t\t\t\tName of artist     : " << artist << "\n";
                cout << "\t\t\t\tPrice of 1 CD/DVD  : " << price << "\n";
                cout << "\t\t\t\tQuantity available : " << quantity << "\n\n";
                cout << "\t\tDo you want to sell CD of this song(Y/N):";
                cin >> y;
                if (y == 'Y')
                {
                    int z;
                    cout << "\t\tHow many CDs you want to sell:";
                    cin >> z;
                    int temp = quantity;
                    if (z < quantity)
                    {
                        quantity = quantity - z;
                        file2 << year << " " << genre << " " << name << " "
                              << " " << artist << " " << price << " " << quantity << "\n";
                    }
                    else
                        quantity = 0;
                    file3 << year << " " << genre << " " << name << " "
                          << " " << artist << " " << price << " " << (temp - quantity) << "\n";
                }
                flag = true;
            }
            else
            {
                file2 << year << " " << genre << " " << name << " "
                      << " " << artist << " " << price << " " << quantity << "\n";
            }
            file1 >> year >> genre >> name >> artist >> price >> quantity;
        }
        file3.close();
        file2.close();
        file1.close();
        remove("MusicRecords.txt");
        rename("Records.txt", "MusicRecords.txt");
        if (!flag)
        {
            cout << "\t\t\tNo song available of this name!!!\n";
        }
    }
    else
    {
        cout << "\t\t\tNo data is found!!!\n";
        file1.close();
    }
}

int main()
{
    music MTV;
    MTV.menu();
    return 0;
}
