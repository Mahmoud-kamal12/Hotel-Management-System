#include"Class.h"


int main(int argc, char* argv[])
{
    int op = 0 , d , f =0;
    user u;
    admin a;  //// object
    Human *hu;

    
    while (op !=3)
    {
        cout << "\t\t\t\t 1- Admin" << endl;
        cout << "\t\t\t\t 2- Customer" << endl;
        cout << "\t\t\t\t 3- to Exit" << endl;
        cout << "Enter Option (1-3) : ";
        cin >> op;

        if (op == 1)
        {
            do
            {
                if (f == 0) { cout << "\t\t\t\t\tUser Name = admin \n\t\t\t\t\tPasswor = 12345\n\n" << endl; }
                if (f == 1 || a.login())
                {
                    f = 1;
                    hu = &a;
                    cout << "\t\t\t\t 1- to DISPLAY ALL ROOMS ALLOTTED" << endl;
                    cout << "\t\t\t\t 2- to DISPLAY SPECIFIC CUSTOMER RECORD" << endl;
                    cout << "\t\t\t\t 3- to DELETE CUSTOMER RECORD" << endl;
                    cout << "\t\t\t\t 4- to Exit" << endl;
                    cout << "Enter Option (1-4) : ";
                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        a.showAllCust();
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 2:
                        hu->ShowCutomerInfo();    // polymorphism
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 3:
                        a.DeletCust();
                        cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                        cin >> d;
                        break;
                    case 4:
                        exit(0);
                    default:
                        cout << "Enter correct num ";
                        d = 0;
                        exit(0);
                        cout << "\a";
                        break;
                    }
                }
                else
                {
                    cout << "Enter correct user or pass ";
                    d = 1;
                    exit(0);
                }
            } while (d == 1);
        }
        else if (op == 2)
        {
            hu = &u;
            do
            {
                
                cout << "\t\t\t\t 1- to BOOK A ROOM" << endl;
                cout << "\t\t\t\t 2- to MODIFY CUSTOMER RECORD" << endl;
                cout << "\t\t\t\t 3- to SHOW CUSTOMER INFORMATION" << endl;
                cout << "\t\t\t\t 4- to Exit" << endl;
                cout << "Enter Option (1-3) : ";
                cin >> op;
                switch (op)
                {
                case 1:
                    u.Add();
                    cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                    cin >> d;
                    break;
                case 2:
                    u.Edit();
                    cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                    cin >> d;
                    break;
                case 3:
                    hu->ShowCutomerInfo();
                    cout << "\n\n\nTo Back Enter 1 To Main list Enter 0 : ";
                    cin >> d;
                    break;
                case 4:
                    d = 0;
                    exit(0);
                    break;
                default:
                    cout << "Enter correct num ";
                    d = 0;
                    exit(0);
                    cout << "\a";
                    break;
                }
            } while (d==1);
        }
        else if (op == 3) { break; }
        else
        {
            cout << "Enter correct num ";
            exit(0);
            cout << "\a";
        }

    }

    return 0;
}