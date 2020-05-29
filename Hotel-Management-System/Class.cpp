#include "Class.h"
user h;
admin a;
fstream fp;
void user::ShowCutomerInfo()
{
    system("cls");
    int id , i= 0;
    cout << "Enter ID :";
    cin >> id;
    system("cls");
    int check = 0;
    fp.open("User.dat", ios::in);
    while (fp.read((char*)&h, sizeof(user)))
    {
        if (h.ID == id)
        {
            h.show(i);
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
        cout << "\n\nCustomer does not exist";
}

void admin::ShowCutomerInfo()
{
    system("cls");
    int id, i = 0;
    cout << "Enter ID :";
    cin >> id;
    system("cls");
    int check = 0;
    fp.open("User.dat", ios::in);
    while (fp.read((char*)&h, sizeof(user)))
    {
        if (h.ID == id)
        {
            h.show(i);
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
        cout << "\n\nCustomer does not exist";
}
void user::show(int &i)
{
    while (i == 0)
    {
        cout << "Id\t" << setw(30) << "Name\t" << setw(50) << "Adress\t" << setw(10) << "Phone\t" << setw(11) << "Room Number\t" << setw(7) << "Balance\t\t" << setw(11) << "Num of days" << endl;
        i++;
    }
    cout << ID << "\t" << setw(30) << getName() << "\t" << setw(50) << getAddress() << "\t" << setw(10) << getPhone() << "\t" << setw(11) << getRoomNum() << "\t" << setw(7) << balance << "\t\t" << setw(11) << num_of_day << endl;
}

void user::Add()

{
    system("cls");

    int option;
    fp.open("User.dat", ios::out | ios::app);
    do
    {
        cout << "Enter ID : ";
        cin >> h.ID;
        h.setRoomNum();
        h.setname();
        h.setaddress();
        h.setphone();
        cout << "Enter Balance : ";
        cin >> h.balance;
        cout << "Enter Nuber of days that you will stay : ";
        cin >> h.num_of_day;
        cout << "\n\n\t\t\t\t\tCustomer added Successfully...\n" << endl;
        fp.write((char*)&h, sizeof(user));
        cout << "Press 1 to add more customers." << endl;
        cout << "Press 2 to return to main menu." << endl;
        cout << "Option: ";
        cin >> option;
    } while (option == 1);

    fp.close();
}

void user::Edit()

{
    system("cls");
    int found = 0;
    int id , i=0;
    cout << "Enter Your ID : ";
    cin >> id;
    fp.open("User.dat", ios::in | ios::out);
    while (fp.read((char*)&h, sizeof(user)) && found == 0)
    {
        if (h.ID == id)
        {
            h.show(i);
            cout << "\n\n\t\t\t\t\tEnter Your New Information" << endl;
            cout << "\nEnter ID : ";
            cin >> h.ID;
            h.setRoomNum();
            h.setname();
            h.setaddress();
            h.setphone();
            cout << "Enter Balance : ";
            cin >> h.balance;
            cout << "Enter Nuber of days that you will stay : ";
            cin >> h.num_of_day;
            long pos = sizeof(user);
            fp.seekp((-1 * pos), ios::cur);
            fp.write((char*)&h, sizeof(user));
            cout << "\n\n\t\t\t\t Information Updated Successfully...";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n\t\t\t\t Usrr Not Found ";
}

void admin::showAllCust()

{
    int i=0;
    system("cls");
    fp.open("User.dat", ios::in | ios::out);
    while (fp.read((char*)&h, sizeof(user)))
    {
        h.show(i);
    }
    fp.close();
}

void admin::DeletCust()

{
    fstream fp2;
    system("cls");
    int found = 0;
    a.showAllCust();
    int id;
    cout << "\n\nEnter  ID : ";
    cin >> id;
    fp.open("User.dat", ios::in | ios::out);
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)&h, sizeof(user)))
    {
        if (h.ID != id)
        {
            fp2.write((char*)&h, sizeof(user));
            found = 1;
        }
    }
    fp.close();
    fp2.close();
    remove("User.dat");
    rename("Temp.dat", "User.dat");
    if (found == 0)
        cout << "\n\n\t\t\t\t Usrr Not Found ";
    else
    {
        cout << "\n\t\t\t\t\t Customer Deleted .......\n";
    }
}

bool admin::login()

{
    cout << "Enter User Name : ";
    cin.ignore(); cin.getline(user_name, 20);
    cout << "Enter Password : ";
    cin >> pass;
    if (strcmp(user_name, "admin") == 0 && pass == 12345)
    {
        return true;
    }
    else
    {
        return false;
    }
}
