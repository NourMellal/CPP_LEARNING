#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
public:
        void setContact(const std::string& firstName, const std::string& lastName, 
                    const std::string& nickname, const std::string& phoneNumber, 
                    const std::string& darkestSecret);
    void displaySummary(int index) const;
    void displayDetails() const;
};


#endif