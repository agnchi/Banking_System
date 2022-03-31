#include "Administrator.h"

void  Administrator::Admin_manu()
{
    int option_i;
    string option_s;
    string info;
    User u;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "              WELCOME ADMINISTRATOR              " << endl;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "********************** MANU *********************" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "1.Add new account                                " << endl;
    std::cout << "2.Modify an existing account                     " << endl;
    std::cout << "3.Delete an account                              " << endl;
    std::cout << "4.View account information                       " << endl;
    std::cout << "5.Go back to the main manu                       " << endl;
    std::cout << "6.Exit                                           " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "*************************************************" << endl;
    std::cout << "                                                 " << endl;
    cin >> option_s;
    option_i = atoi(option_s.c_str());
    switch (option_i)
    {
    case 1:
        system("cls");
        Add();
        break;
    case 2:
        system("cls");
        Modify();
        break;
    case 3:
        system("cls");
        Delete();
        break;
    case 4:
        system("cls");
        std::cout << "Client ID or account number:  ";
        cin >> info;
        u = findUser(info);
        u.Print_Acc_info(u);
        system("cls");
        Admin_manu();
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
        Admin_manu();
        break;
    }
}
void  Administrator::Add()
{
    User c;
    string id, name, surname, pass, acc_num, deposit;
    string ans;
    bool id_check;
    std::cout << "Enter new client's data" << endl;
    std::cout << "ID number:  ";
    cin >> id;
    id_check = ID_check(id);
    while (id_check)
    {
        id_check = false;
        std::cout << "            " << endl;
        std::cout << "ID number:  ";
        cin >> id;
        id_check = ID_check(id);
    }
    c.set_id(id);
    std::cout << "Name:  ";
    cin >> name;
    c.set_name(name);
    std::cout << "Surame:  ";
    cin >> surname;
    c.set_surname(surname);
    std::cout << "Deposit:  ";
    cin >> deposit;
    c.set_deposit(deposit);
    std::cout << "Password for your account:  ";
    cin >> pass;
    c.set_pass(pass);
    acc_num = Gen_CheckNum();
    c.set_acc_num(acc_num);
    ofstream c_data("c_info.txt", ios::app);
    ofstream c_login("c_login.txt", ios::app);
    if (c_data.is_open() && c_login.is_open())
    {
        c_data << c.get_id() << " " << c.get_name() << " " << c.get_surname() << " " << c.get_acc_num() << " " << c.get_deposit() << endl;
        c_login << c.get_id() << " " << c.get_pass() << endl;
        c_data.close();
        c_login.close();
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
    system("cls");
    c.Print_Acc_info(c);
    system("cls");
    Admin_manu();
}
int Administrator::Modify_menu()
{
    int option;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "             MODIFY CLIENT'S ACCOUNT             " << endl;
    std::cout << "_________________________________________________" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "********************** MENU *********************" << endl;
    std::cout << "                                                 " << endl;
    std::cout << "What information do you want to change?          " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "1.ID number                                      " << endl;
    std::cout << "2.Name                                           " << endl;
    std::cout << "3.Surname                                        " << endl;
    std::cout << "4.Password                                       " << endl;
    std::cout << "5.Go back to administrator menu                  " << endl;
    std::cout << "6.Exit                                           " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "                                                 " << endl;
    std::cout << "*************************************************" << endl;
    std::cout << "                                                 " << endl;
    cin >> option;
    if (option == 1 || option == 2 || option == 3 || option == 4)
    {
        return option;
    }
    if (option == 5)
    {
        system("cls");
        Admin_manu();
        return option;
    }
    if (option == 6)
    {
        return 0;
    }
    else
    {
        system("cls");
        std::cout << "                                                 " << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "************ ! Not a valid option ! *************" << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "****************** TRY AGAIN ********************" << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "                                                 " << endl;
        Modify_menu();
        return 0;
    }
}
void Administrator::Modify()
{
    string info;
    User c;
    User c_mod;
    string id, name, surname, pass, acc_num, deposit;
    string n_id, n_name, n_surname, n_pass, o_id;
    int what_mod;
    bool id_check;
    std::cout << "Input client's ID number or account number:  ";
    cin >> info;
    c = findUser(info);
    while (c.get_exists() == false)
    {
        std::cout << "                                                     " << endl;
        std::cout << "Input client's correct ID number or account number:  ";
        cin >> info;
        c = findUser(info);
    }
    system("cls");
    c.Print_Acc_info(c);
    system("cls");
    what_mod = Modify_menu();
    while (what_mod >= 1 && what_mod <= 4)
    {
        switch (what_mod)
        {
        case 1:
            std::cout << "Enter new ID:   ";
            cin >> n_id;
            id_check = ID_check(n_id);
            while (id_check)
            {
                id_check = false;
                std::cout << "                " << endl;
                std::cout << "Enter new ID:   ";
                cin >> n_id;
                id_check = ID_check(n_id);
            }
            c_mod = c;
            c_mod.set_id(n_id);
            c.ChangeFile(c, c_mod);
            c = c_mod;
            break;
        case 2:
            std::cout << "Enter new name:   ";
            cin >> n_name;
            c_mod = c;
            c_mod.set_name(n_name);
            c.ChangeFile(c, c_mod);
            c = c_mod;
            break;
        case 3:
            std::cout << "Enter new surname:   ";
            cin >> n_surname;
            c_mod = c;
            c_mod.set_surname(n_surname);
            c.ChangeFile(c, c_mod);
            c = c_mod;
            break;
        case 4:
            std::cout << "Enter new password:   ";
            cin >> n_pass;
            c_mod = c;
            c_mod.set_pass(n_pass);
            c.ChangeFile(c, c_mod);
            c = c_mod;
            break;
        default:
            break;
        }
        system("cls");
        c.Print_Acc_info(c);
        system("cls");
        what_mod = Modify_menu();
    }

}
void  Administrator::Delete()
{
    system("cls");
    User c;
    string info;
    string id, name, surname, pass;
    string acc_num, deposit, tell_id;
    std::cout << "Input client's ID number or account number:  ";
    cin >> info;
    system("cls");
    c = findUser(info);
    c.Print_Acc_info(c);
    system("cls");
    fstream c_data("c_info.txt", ios::in);
    fstream temp_file("temp_file.txt", ios::out | ios::trunc);
    fstream c_login("c_login.txt", ios::in);
    fstream temp_login("temp_login.txt", ios::out | ios::trunc);
    if (c_data.is_open() && temp_file.is_open() && c_login.is_open() && temp_login.is_open())
    {
        while (c_data >> id >> name >> surname >> acc_num >> deposit)
        {
            if (id != c.get_id())
            {
                temp_file << id << " " << name << " " << surname << " " << acc_num << " " << deposit << endl;
            }
            else
            {
                std::cout << "Deleting User  " << endl;
                std::cout << "                " << endl;
                c.Print_Acc_info(c);
            }
        }
        while (c_login >> id >> pass)
        {
            if (id != c.get_id())
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
    system("cls");
    Admin_manu();
}
string Administrator::GenerateNum()
{
    srand(time(NULL));
    int acc_num_int = 0;
    string acc_num_str;
    int rand_num;
    for (int i = 5; i >= 0; i--)
    {
        rand_num = (rand() % 9) + 1;
        acc_num_int = acc_num_int + (pow(10, i) * rand_num);
    }
    return acc_num_str = std::to_string(acc_num_int);
}
string Administrator::Gen_CheckNum()
{
    string acc_num_str = GenerateNum();
    int dup = 0;
    string id, name, surname, pass, acc_num, deposit;
    fstream c_data("c_info.txt", ios::in);
    if (c_data.is_open())
    {
        while (c_data >> id >> name >> surname >> acc_num >> deposit)
        {
            if (acc_num == acc_num_str)
            {
                dup = 1;
            }
        }
        c_data.close();
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
    while (dup == 1)
    {
        acc_num_str = GenerateNum();
        dup = 0;
        fstream c_data("c_info.txt", ios::in);
        if (c_data.is_open())
        {
            while (c_data >> id >> name >> surname >> acc_num >> deposit)
            {
                if (acc_num == acc_num_str)
                {
                    dup = 1;
                    acc_num_str = GenerateNum();
                }
                else
                {
                    dup = 0;
                }
            }
        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }
    }
    return acc_num_str;
}
bool Administrator::ID_check(string info)
{
    int dup = 0;
    string id, name, surname, pass, acc_num, deposit;
    fstream c_data("c_info.txt", ios::in);
    if (c_data.is_open())
    {
        while (c_data >> id >> name >> surname >> acc_num >> deposit)
        {
            if (id == info)
            {
                dup = 1;
            }
        }
        c_data.close();
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
    if (dup == 1)
    {
        std::cout << "                                                 " << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "                                                 " << endl;
        std::cout << "    Client with this ID is already registered    " << endl;
        std::cout << "                                                 " << endl;
        std::cout << "*************************************************" << endl;
        std::cout << "                                                 " << endl;
        return true;
    }
    else
    {
        return false;
    }
}
User Administrator::findUser(string info)
{
    User c;
    string id, name, surname, pass, acc_num, deposit;
    string tell_id = "";
    bool found = false;
    fstream c_data("c_info.txt", ios::in);
    fstream c_login("c_login.txt", ios::in);
    if (c_data.is_open() && c_login.is_open())
    {
        while (c_data >> id >> name >> surname >> acc_num >> deposit)
        {
            if (id == info || acc_num == info)
            {
                found = true;
                c.set_exists(found);
                tell_id = id;
                c.set_id(id);
                c.set_name(name);
                c.set_surname(surname);
                c.set_acc_num(acc_num);
                c.set_deposit(deposit);
                while (c_login >> id >> pass)
                {
                    if (id == tell_id)
                    {
                        c.set_pass(pass);
                    }
                }
            }
        }
        c_data.close();
        if (found == false)
        {
            c.set_exists(found);
            std::cout << "                                                     " << endl;
            std::cout << "*****************************************************" << endl;
            std::cout << "                                                     " << endl;
            std::cout << "     Client not found, input correct information     " << endl;
            std::cout << "                                                     " << endl;
            std::cout << "*****************************************************" << endl;
            std::cout << "                                                     " << endl;
        }
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
    return c;
}
