/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:36:36 by nmellal           #+#    #+#             */
/*   Updated: 2025/01/22 16:07:50 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|";
    std::cout << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|";
    std::cout << std::setw(10) << (nick_name.length() > 10 ? nick_name.substr(0, 9) + "." : nick_name) << std::endl;
}

void Contact::displayDetails() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nick_name << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
