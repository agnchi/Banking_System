#include "User.h"
#include "Administrator.h"

void User::Print_Acc_info(User u)
{
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "               ACCOUNT INFOTMATION               " << endl;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "*************************************************" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "ID:  " << u.get_id() << endl;
    std::cout << "NAME:  " << u.get_name() << endl;
    std::cout << "SURNAME:  " << u.get_surname() << endl;
    std::cout << "ACCOUNT NUMBER:  " << u.get_acc_num() << endl;
    std::cout << "BALANCE:  " << u.get_deposit() << endl;
    std::cout << "                                                 " << endl;
    std::cout << "*************************************************" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "         Click any key to stop viewing           " << endl;
    std::cout << "_________________________________________________" << endl;

    string key;
    while (1)
    {
        cin >> key;
        if (!key.empty())
        {
            break;
        }
    }

}
void User::Client_manu(User c)
{
    int option;
    Administrator a;
    string info;
    User ud, uw, ut;
    User u2;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "             WELCOME TO YOUR ACCOUNT             " << endl;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "********************** MANU *********************" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "1.Check your balance                             " << endl;
    std::cout << "2.Withdraw money                                 " << endl;
    std::cout << "3.Make a deposit                                 " << endl;
    std::cout << "4.Transfer money within our bank                 " << endl;
    std::cout << "5.Go back to the main manu                       " << endl;
    std::cout << "6.Exit                                            " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "*************************************************" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        cout << c.get_deposit() << endl;
        Print_Acc_info(c);
        system("cls");
        Client_manu(c);
        break;
    case 2:
        system("cls");
        double how_much_with;
        std::cout << "How much money do you want to withdraw?   ";
        cin >> how_much_with;
        uw = Withdraw(c, how_much_with);
        std::cout << "Your new balance is: " << uw.get_deposit() << endl;
        Client_manu(uw);
        break;
    case 3:
        system("cls");
        double how_much_dep;
        std::cout << "How much money do you want to deposit?   ";
        cin >> how_much_dep;
        ud = Deposit(c, how_much_dep);
        std::cout << "Your new balance is: " << ud.get_deposit() << endl;
        Client_manu(ud);
        break;
    case 4:
        system("cls");
        std::cout << "Enter account number of a user you want to transfer money to:  " << endl;
        cin >> info;
        u2 = a.findUser(info);
        double how_much_tran;
        std::cout << "How much money do you want to deposit?   ";
        cin >> how_much_tran;
        ut = Transfer(c, u2, how_much_tran);
        std::cout << "Your new balance is: " << ut.get_deposit() << endl;
        Client_manu(ut);
        break;
    case 5:
        system("cls");
        Bank b;
        b.Bank_manu();
        break;
    case 6:
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
        cin >> option;
        break;
    }
}
User User::Withdraw(User c, double how_much)
{
    Bank b;
    User u;
    u = c;
    int option;
    string key;
    double n_balance;
    double balance = std::stod(c.get_deposit());
    n_balance = balance - how_much;
    system("cls");
    while (n_balance < 0)
    {
        system("cls");
        std::cout << "                                        " << endl;
        std::cout << "**************** WARNING ***************" << endl;
        std::cout << "                                        " << endl;
        std::cout << "You were trying to withdraw more money  " << endl;
        std::cout << "than you have deposited on your account" << endl;
        std::cout << "                                        " << endl;
        std::cout << "****************************************" << endl;
        std::cout << "                                        " << endl;
        std::cout << "________________________________________" << endl;
        std::cout << "                                        " << endl;
        std::cout << "Choose one of the options:              " << endl;
        std::cout << "                                        " << endl;
        std::cout << "1.Withdraw all money                    " << endl;
        std::cout << "2.Specify a new amount                  " << endl;
        std::cout << "3.Go back to the menu                   " << endl;
        std::cout << "________________________________________" << endl;
        std::cout << "                                        " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            u.set_deposit("0");
            std::cout << "*************************************************" << endl;
            std::cout << "                                                 " << endl;
            std::cout << "         Your new balance is: " << u.get_deposit() << endl;
            std::cout << "                                                 " << endl;
            std::cout << "*************************************************" << endl;
            std::cout << "                                                 " << endl;
            std::cout << "_________________________________________________" << endl;
            std::cout << "                                                 " << endl;
            std::cout << "         Click any key to stop viewing           " << endl;
            std::cout << "_________________________________________________" << endl;
            ChangeFile(c, u);
            cin >> key;
            if (!key.empty())
            {
                system("cls");
                Client_manu(u);
            }
            break;
        case 2:
            system("cls");
            std::cout << "How much money do you want to withdraw?   ";
            cin >> how_much;
            n_balance = balance - how_much;
            if (n_balance >= 0)
            {
                system("cls");
                u.set_deposit(b.precision2(to_string(n_balance)));
                std::cout << "*************************************************" << endl;
                std::cout << "                                                 " << endl;
                std::cout << "         Your new balance is: " << u.get_deposit() << endl;
                std::cout << "                                                 " << endl;
                std::cout << "*************************************************" << endl;
                std::cout << "                                                 " << endl;
                std::cout << "_________________________________________________" << endl;
                std::cout << "                                                 " << endl;
                std::cout << "         Click any key to stop viewing           " << endl;
                std::cout << "_________________________________________________" << endl;
                ChangeFile(c, u);
                cin >> key;
                if (!key.empty())
                {
                    system("cls");
                    Client_manu(u);
                }
            }
            break;
        case 3:
            system("cls");
            Client_manu(c);
            break;
        default:
            system("cls");
            std::cout << "                                                 " << endl;
            std::cout << "*************************************************" << endl;
            std::cout << "************ ! Not a valid option ! *************" << endl;
            std::cout << "*************************************************" << endl;
            std::cout << "****************** TRY AGAIN ********************" << endl;
            std::cout << "*************************************************" << endl;
            std::cout << "                                                 " << endl;
            cin >> option;
            break;
        }
    }
    u.set_deposit(b.precision2(to_string(n_balance)));
    ChangeFile(c, u);
    return u;
}
void User::ChangeFile(User o, User n)
{
    string id, name, surname, pass, acc_num, deposit;
    fstream c_data("c_info.txt", ios::in);
    fstream temp_file("temp_file.txt", ios::out | ios::trunc);
    fstream c_login("c_login.txt", ios::in);
    fstream temp_login("temp_login.txt", ios::out | ios::trunc);
    if (c_data.is_open() && temp_file.is_open() && c_login.is_open() && temp_login.is_open())
    {
        while (c_data >> id >> name >> surname >> acc_num >> deposit)
        {
            if (id == o.get_id())
            {
                temp_file << n.get_id() << " " << n.get_name() << " " << n.get_surname() << " " << n.get_acc_num() << " " << n.get_deposit() << endl;
            }
            else
            {
                temp_file << id << " " << name << " " << surname << " " << acc_num << " " << deposit << endl;
            }
        }
        while (c_login >> id >> pass)
        {
            if (id == o.get_id())
            {
                temp_login << n.get_id() << " " << n.get_pass() << endl;
            }
            else
            {
                temp_login << id << " " << pass << endl;
            }
        }
        c_data.close();
        temp_file.close();
        c_login.close();
        temp_login.close();
        remove("c_info.txt");
        if (rename("temp_file.txt", "c_info.txt") != 0)
            perror("Error renaming file");
        remove("c_login.txt");
        if (rename("temp_login.txt", "c_login.txt") != 0)
            perror("Error renaming file");
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
}
User User::Deposit(User c, double how_much)
{
    Bank b;
    User u;
    u = c;
    string key;
    double n_balance;
    double balance = std::stod(c.get_deposit());
    n_balance = balance + how_much;
    u.set_deposit(b.precision2(to_string(n_balance)));
    ChangeFile(c, u);
    return u;
}
User User::Transfer(User u1, User u2, double how_much)
{
    User u;
    u = u1.Withdraw(u1, how_much);
    u2.Deposit(u2, how_much);
    return u;
}
