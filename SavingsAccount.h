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



#ifndef SAVINGSACCOUNT_H

#define SAVINGSACCOUNT_H



#include "BankAccount.h"



namespace seneca {


    
    class SavingsAccount : public BankAccount {
    
    private:
    
        double m_interest;
        
        Date m_interestDate;


        
        void writeInterest(std::ostream& out) const;


    
    public:
    
        SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
        
        void applyInterest(const Date& dt);
        
        std::ostream& write(std::ostream& out) const override;
        
        std::istream& read(std::istream& in) override;
    };



    
    std::istream& operator>>(std::istream& in, SavingsAccount& acct);
    
    std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);


}

#endif
