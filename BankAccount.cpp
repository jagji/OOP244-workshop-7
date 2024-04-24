/*/////////////////////////////////////////////////////////////////////////
                          Workshop - 6
Full Name  : jagjit kaur
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       :  march 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/



#include "BankAccount.h"


#define _CRT_SECURE_NO_WARNINGS



#include <cstring>

#include <iomanip>

#include <iostream>



using namespace std;

namespace seneca {



    
    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
    
        : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
        
        strcpy(m_name, name);
        
        m_name[50] = '\0';
    }



    
    void BankAccount::writeCurrency(std::ostream& out, double amount) const {
    
        out << '$' << std::fixed << std::setprecision(2) << amount;
    }



    
    std::ostream& BankAccount::write(std::ostream& out) const {
    
        out << ">> " << m_name << " | ";
        
        writeCurrency(out, m_balance);
        
        out << " | ";
        
        m_openDate.write(out);
        
        out << " | ";
        
        m_depInfo.write(out);
        
        return out;
    }





    
    std::istream& BankAccount::read(std::istream& in) {
    
        std::cout << "Name: ";
        
        in.get(m_name, 51);
        
        in.ignore(9999999, '\n');



        
        std::cout << "Opening Balance: ";
        
        in >> m_balance;
        
        in.ignore(9999999, '\n');


        
        std::cout << "Date Opened ";
        
        m_openDate.read(in);


        
        in >> m_depInfo;
        
        in.ignore(9999999, '\n');


        
        return in;
    }





    
    std::istream& operator>>(std::istream& in, BankAccount& acct) {
    
        return acct.read(in);
    }



    
    std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
    
        return acct.write(out);
    }

}





