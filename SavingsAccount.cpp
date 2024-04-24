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



#include "SavingsAccount.h"

#include <iostream>

#include <iomanip>



namespace seneca {


    
    SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)
    
        : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}


    
    void SavingsAccount::writeInterest(std::ostream& out) const {
    
        out << std::fixed << std::setprecision(3) << m_interest << '%';
    }



    
    std::ostream& SavingsAccount::write(std::ostream& out) const {
    
        BankAccount::write(out);
        
        out << " | ";
        
        writeInterest(out);
        
        out << " | ";
        
        m_interestDate.write(out);
        
        return out;
    }



    
    std::istream& SavingsAccount::read(std::istream& in) {
    
        BankAccount::read(in);


        
        std::cout << "Interest Date ";
        
        m_interestDate.read(in);


        
        std::cout << "Interest Rate: ";
        
        in >> m_interest;
        
        in.ignore(9999999, '\n');


        
        return in;
    }





    
    void SavingsAccount::applyInterest(const Date& newInterestDate) {
    
        double interestAmount = getBalance() * m_interest;
        
        double newBalance = getBalance() + interestAmount;


        
        std::cout << "   ";
        
        writeCurrency(std::cout, getBalance());
        
        std::cout << " + ";
        
        writeCurrency(std::cout, interestAmount);
        
        std::cout << " (";
        
        writeInterest(std::cout);
        
        std::cout << ") = ";
        
        writeCurrency(std::cout, newBalance);
        
        std::cout << " | ";
        
        m_interestDate.write(std::cout);
        
        std::cout << " => ";
        
        newInterestDate.write(std::cout);
        
        std::cout << std::endl;


        
        setBalance(newBalance);
        
        m_interestDate = newInterestDate;
    }





    
    std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
    
        return acct.read(in);
    }



    
    std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
    
        return acct.write(out);
    }

}







