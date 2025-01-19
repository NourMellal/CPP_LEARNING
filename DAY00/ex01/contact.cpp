#include "contact.hpp"
#include <iomanip>
#include <iostream>
void Contact::setContact(const std::string& firstName, const std::string& lastName, 
                const std::string& nickname, const std::string& phoneNumber, 
                const std::string& darkestSecret) {

                    this->first_name = firstName;
                    this->last_name = lastName;
                    this->nick_name = nickname;
                    this->phone_number = phoneNumber;
                    this->darkest_secret = darkestSecret;
    }

void Contact::displaySummary(int index) const
{
    ;
}

void Contact::displayDetails() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nick_name << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}