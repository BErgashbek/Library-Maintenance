#include<iostream>
#include<string>
#include <sstream>
#include <dos.h>
#include <iomanip>
#include <fstream>
using namespace std;

void breaker()
{
    cout << "********************************" << endl;
    cout << endl;
}


int login()
{
    int i = 0;
    int g = 0;

    while (i != 3)
    {
        string login, password;
        cout << "Please enter your login: ";
        cin >> login;
        cout << "Enter the password: ";
        cin >> password;
        if (login == "Ergashbek" && password == "EDWARD0303" || login == "Akbarjon" && password == "AKBARJON" || login == "Isobek" && password == "ISOBEK" || login == "Odiljon" && password == "ODILJON")
        {
            cout << "Hello Mr." << login << endl;
            g = g + 1;
            break;
        }
        else
        {
            system("color 4");
            cout << "You have entered the login wrong or You have entered the password wrong.\n";
            i++;
            breaker();
        }
        if (g != 0)
        {
            break;
        }
    }
    return g;
}
void find_book(string a, string b, string c)
{
//*****************
    string massage;
    string p;
    ifstream file;

    file.open("data.txt");
    if (!file)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (file >> p)
    {
        massage = massage + p + " ";
    }
    file.close();

    string data[17][5];
    string ele = "";
    int len = massage.length();
    int x = 0, y = 0;

    for(int i=0; i < len-1; i++)
    {
        if(massage[i] == '*')
        {
            data[x][y] = ele;
            ele = "";
            y++;
        }
        else if(massage[i] == '#')
        {
            x++;
            y = 0;
            i++;
        }
        else
        {
            ele += massage[i];
        }
    }
//*******************************
    bool is_there = 0;
    for (int i = 0; i < 17; i++)
    {
        if (data[i][0] == a || a == "skip")
        {
            if (data[i][1] == b || b == "skip")
            {
                if (data[i][2] == c || c == "skip")
                {
                    if (data[i][4] != "0")
                    {
                        /*
                        return data[i][3];
                        break;
                        */
                        cout << data[i][4] << " books are available in the location: " << data[i][3] << endl;
                        is_there = 1;
                    }

                }

            }


        }


    }
    if(is_there == 0)
    {
        cout << "Book is not found :(" << endl;
    }

}
void get_book(string a, string b, string ID)
{

//*****************
    string massage;
    string p;
    ifstream file;

    file.open("data.txt");
    if (!file)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (file >> p)
    {
        massage = massage + p + " ";
    }
    file.close();

    string data[17][5];
    string ele = "";
    int len = massage.length();
    int x = 0, y = 0;

    for(int i=0; i < len-1; i++)
    {
        if(massage[i] == '*')
        {
            data[x][y] = ele;
            ele = "";
            y++;
        }
        else if(massage[i] == '#')
        {
            x++;
            y = 0;
            i++;
        }
        else
        {
            ele += massage[i];
        }
    }
//*******************************
    int m;
    bool is_it = 0;
    stringstream geek(b);
    geek >> m;
    for (int i = 0; i < 17; i++)
    {
        if (data[i][3] == a)
        {
            is_it = 1;
            int n;
            stringstream geek(data[i][4]);
            geek >> n;
            if (m > n)
            {
                cout << "Only " << n << " Books are available in the Library, cannot Order more than " << n << " :(" << endl;
            }
            else
            {
                int z = n - m;
                stringstream ss;
                ss<<z;
                string s;
                ss>>s;
                data[i][4] = s;
                fstream myfile;
                myfile.open("tooken.txt",ios::app);
                if(myfile.is_open())
                {
                    myfile<<"Student with ID "<<ID<<" has taken "<<b<<" of "<<data[i][0]<<" written by "<<data[i][1]<<"\n";
                }
                cout << "Ordered successfully!" << endl;
            }
        }
    }
    if (is_it == 0)
    {
        cout << "Location not found :( ";
    }
//############################################
    const int ar = 17, br = 5;
    ofstream yourfile("data.txt");

    if (yourfile.is_open())
    {
        for(int i = 0; i < ar; i ++)
        {
            for(int j = 0; j < br; j++)
            {
                yourfile << data[i][j] << "*";
            }
            yourfile << "#\n";
        }
        yourfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
//############################################
}

void put_book(string a, string b, string ID)
{

//*****************
    string massage;
    string p;
    ifstream file;

    file.open("data.txt");
    if (!file)
    {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (file >> p)
    {
        massage = massage + p + " ";
    }
    file.close();

    string data[17][5];
    string ele = "";
    int len = massage.length();
    int x = 0, y = 0;

    for(int i=0; i < len-1; i++)
    {
        if(massage[i] == '*')
        {
            data[x][y] = ele;
            ele = "";
            y++;
        }
        else if(massage[i] == '#')
        {
            x++;
            y = 0;
            i++;
        }
        else
        {
            ele += massage[i];
        }
    }
//*******************************
    int m;
    bool is_it = 0;
    stringstream geek(b);
    geek >> m;
    for (int i = 0; i < 17; i++)
    {
        if (data[i][3] == a)
        {
            is_it = 1;
            int n;
            stringstream geek(data[i][4]);
            geek >> n;
            int z = n + m;
            stringstream ss;
            ss<<z;
            string s;
            ss>>s;
            data[i][4] = s;
            fstream myfile;
            myfile.open("given.txt",ios::app);
            if(myfile.is_open())
            {
                myfile<<"Student with ID "<<ID<<" returned "<<b<<" of "<<data[i][0]<<" written by "<<data[i][1]<<"\n";
            }
            cout << "Put back successfully!" << endl;
        }
    }
    if (is_it == 0)
    {
        cout << "Location not found :( ";
    }
//############################################
    const int ar = 17, br = 5;
    ofstream yourfile("data.txt");

    if (yourfile.is_open())
    {
        for(int i = 0; i < ar; i ++)
        {
            for(int j = 0; j < br; j++)
            {
                yourfile << data[i][j] << "*";
            }
            yourfile << "#\n";
        }
        yourfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
//############################################
}

int main()
{

    system("color B1");
    int log = 0;
    log = login();
    while (true)
    {
        system("color A1");
        breaker();
        cout << "What do you want to do?\n";
        cout << "1. Find Book's location\n";
        cout << "2. Order a Book or Books\n";
        cout << "3. Put back a Book or Books\n";
        cout << "0. Quit\n";
        int a;
        cin >> a;

        breaker();
        if (a == 0)
        {
            system("color F1");
            cout << "The procces ended\n";
            cout << "Thanks for choosing our Library!!!\n";
            break;
        }
        switch (a)
        {
        case 1:
        {
            string book_name, book_writer, book_year;
            cout << "Enter the name of the book: ";
            cin.ignore();
            getline(cin, book_name);
            cout << "Enter writer of the book: ";
            getline(cin, book_writer);
            cout << "Enter the year of publishing: ";
            getline(cin, book_year);

            find_book(book_name,book_writer, book_year);
            break;
        }
        case 2:
        {
            string book_location, number,ID;
            cin.ignore();
            cout<<"Enter ID: ";
            getline(cin,ID);
            cout << "Enter Location of the book: ";

            getline(cin, book_location);
            cout << "How many books do you want to order?: ";
            getline(cin, number);
            get_book(book_location, number, ID);
            break;
        }
        case 3:
        {
            string book_location, number,ID;
            cin.ignore();
            cout<<"Enter ID: ";
            getline(cin,ID);
            cout << "Enter Location of the book: ";

            getline(cin, book_location);
            cout << "Enter number of book they should be back : ";
            getline(cin, number);
            put_book(book_location, number,ID);
            break;
        }


        default:
        {
            break;
        }
        }
    }
    system("pause");
    return 0;
}
