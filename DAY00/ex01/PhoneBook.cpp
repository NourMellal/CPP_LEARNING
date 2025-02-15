/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:36:17 by nmellal           #+#    #+#             */
/*   Updated: 2025/01/22 16:08:13 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contact_count(0), oldest_contact(0) {}

void PhoneBook:: addContact() {
    
    std::string first_name, last_name, nick_name, phone_number, darkest_secrete;
    
    std::cout << "Enter First name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter Last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter Nick name: ";
    std::getline(std::cin, nick_name);
    std::cout << "Enter Phone number: ";
    std::getline(std::cin, phone_number);
    for (int i = 0; phone_number[i]; i++) {
    if (!isdigit(phone_number[i])) {
        std::cout << "Phone number must be all digits (without white spaces)" << std::endl;
        return ;
    }
}
    std::cout << "Enter Darkest secret: ";
    std::getline(std::cin, darkest_secrete);

    if (first_name.empty() || last_name.empty() || nick_name.empty() ||
        phone_number.empty() || darkest_secrete.empty()) {
            std::cout << "Error: All fields must be filed!" << std::endl;
            return ;
        }
    
    contacts[oldest_contact].setContact(first_name, last_name, nick_name, phone_number, darkest_secrete);
    oldest_contact = (oldest_contact + 1) % 8;
    if (contact_count < 8) {
        contact_count++;
    }
    std::cout << "Contact is created" << std::endl ;
}

void PhoneBook::searchContacts() const 
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < contact_count; i++) {
        contacts[i].displaySummary(i + 1);
    }

    std::cout << "Enter the index of the contact for details: " ;
    int index;
    std::cin >> index;
    if (std::cin.fail() || index < 1 || index > contact_count) {
        // std::cout << "Enter the index of the contact for details: " << std::endl ;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        contacts[index - 1].displayDetails();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}