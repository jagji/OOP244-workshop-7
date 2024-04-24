/*/////////////////////////////////////////////////////////////////////////
                          Workshop - 6
Full Name  : jagjit kaur
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       : 17 march 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/




#ifndef BANKACCOUNT_H

#define BANKACCOUNT_H



#include "DepositUtility.h"

#include <iostream>




namespace seneca {


    
    class BankAccount {
    
    private:
    
        char m_name[51];
        
        Date m_openDate;
        
        DepositInfo m_depInfo;
        
        double m_balance;

    
    protected:
    
        double getBalance() const { return m_balance; }
        
        void setBalance(double balance) { m_balance = balance; }
        
        void writeCurrency(std::ostream& out, double amount) const;


    
    public:
    
        BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
        
        virtual std::ostream& write(std::ostream& out) const;
        
        virtual std::istream& read(std::istream& in);
    };



    
    std::istream& operator>>(std::istream& in, BankAccount& acct);
    
    std::ostream& operator<<(std::ostream& out, const BankAccount& acct);


}


#endif
