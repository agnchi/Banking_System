#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bank.h"


using namespace std;

class User
{

    string m_id, m_name, m_surname, m_acc_num, m_deposit, m_pass;
    bool m_exists;
public:
    const string& get_id() const { return m_id; }
    const string& get_name() const { return m_name; }
    const string& get_surname() const { return m_surname; }
    const string& get_acc_num() const { return m_acc_num; }
    const string& get_deposit() const { return m_deposit; }
    const string& get_pass() const { return m_pass; }
    const bool& get_exists() const { return m_exists; }
    void set_id(const string& id) { m_id = id; }
    void set_name(const string& name) { m_name = name; }
    void set_surname(const string& surname) { m_surname = surname; }
    void set_acc_num(const string& acc_num) { m_acc_num = acc_num; }
    void set_deposit(const string& deposit) { m_deposit = deposit; }
    void set_pass(const string& pass) { m_pass = pass; }
    void set_exists(const bool& exists) { m_exists = exists; }
    void Print_Acc_info(User u);
    void Client_manu(User c);
    User Withdraw(User c, double how_much);
    User Deposit(User c, double how_much);
    void ChangeFile(User o, User n);
    User Transfer(User u1, User u2, double how_much);
};
