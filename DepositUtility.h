
/***********************************************************************
// OOP244 Workshop #7:
//
// File:    DepositUtility.h
// Version: 1.0
// Author:  Nick Romanidis
//
***********************************************************************/


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





#ifndef SENECA_DEPOSIT_UTILITY_H

#define SENECA_DEPOSIT_UTILITY_H



#include <iostream>



const unsigned int TRANSIT_NUM_LEN = 5;

const unsigned int INSTITUTION_NUM_LEN = 3;

const unsigned int ACCT_NUM_LEN = 7;



namespace seneca {


	
	class Date {
	
		int m_day{};
		
		int m_month{};
		
		int m_year{};


	
	public:
	
		Date();
		
		Date(int day, int month, int year);


		
		int getDay() const;
		
		int getMonth() const;
		
		int getYear() const;


		
		void write(std::ostream& out) const;
		
		void read(std::istream& in);
	};



	
	struct DepositInfo {
	
		char m_transit[TRANSIT_NUM_LEN + 1];
		
		char m_institution[INSTITUTION_NUM_LEN + 1];
		
		char m_account[ACCT_NUM_LEN + 1];


	
	public:
	
		DepositInfo();
		
		DepositInfo(const char* transit, const char* institution, const char* account);


		
		const char* getTransit() const;
		
		const char* getInstitution() const;
		
		const char* getAccount() const;


		void write(std::ostream& out) const;
		
		void read(std::istream& in);
	};



	
	std::ostream& operator<<(std::ostream& out, const Date& dt);
	
	std::istream& operator>>(std::istream& in, Date& dt);


	
	std::ostream& operator<<(std::ostream& out, const DepositInfo& info);
	
	std::istream& operator>>(std::istream& in, DepositInfo& info);
}



#endif
