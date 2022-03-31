#include "Bank.h"
#include "Administrator.h"

string Bank::precision2(string str_num)
{
    string new_str;
    string fdp, sdp;
    for (int i = 0; i < str_num.size(); i++)
    {
        new_str = new_str + str_num[i];
        if (str_num[i] == '.')
        {
            fdp = str_num[i + 1];
            sdp = str_num[i + 2];
            break;
        }
    }
    new_str = new_str + fdp + sdp;
    return new_str;
}
void Bank::login(int opt)
{
    User client;
    Administrator a;
    string id, pass, enr_id, enr_pass;
    int temp = 0;
    ifstream login_file;
    if (opt == 1)
    {
        login_file.open("a_login.txt");
        std::cout << "Welcome administrator" << endl;
    }
    if (opt == 2)
    {
        login_file.open("c_login.txt");
        std::cout << "Welcome client" << endl;
    }
    std::cout << "Enter your ID number:  ";
    cin >> enr_id;
    std::cout << "Enter your password:  ";
    cin >> enr_pass;

    if (login_file.is_open())
    {
        while (login_file >> id >> pass)
        {
            if (id == enr_id && pass == enr_pass)
            {
                temp = 1;
                client = a.findUser(id);
                break;
            }
        }
        login_file.close();
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
    if (temp == 1)
    {
        if (opt == 1)
        {
            system("cls");
            a.Admin_manu();
        }
        if (opt == 2)
        {
            system("cls");
            client.Client_manu(client);

        }
    }
    else
    {
        system("cls");
        std::cout << "                             " << endl;
        std::cout << "Login unsuccessful, try again" << endl;
        std::cout << "                             " << endl;
        Bank_manu();

    }
}
void Bank::Bank_manu()
{

    int option;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "              WELCOME TO OUR BANK!               " << endl;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "********************MAIN MANU********************" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "Login as:                                        " << endl;
    std::cout << "1.Administrator                                  " << endl;
    std::cout << "2.Client                                         " << endl;
    std::cout << "3.Exit                                           " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "*************************************************" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        login(option);
        break;
    case 2:
        system("cls");
        login(option);
        break;
    case 3:
        exit(0);
    default:
        system("cls");
        std::cout << "                                                 " << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "************ ! Not a valid option ! *************" << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "****************** TRY AGAIN ********************" << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "                                                 " << endl;
        Bank_manu();
        break;
    }
}