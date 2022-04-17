#include "interface.h"

interface::interface(service &srv) : srv(srv) {}

void interface::run() {
    menu();
    std::string command;

    while (true) {
        command.clear();

        std::cout << "Command:";
        std::getline(std::cin, command);

        if (command == "exit")
            break;
        else if (command == "add") {
            add();
        } else if (command == "delete") {
            del();
        } else if (command == "find") {
            find();
        } else if (command == "show") {
            show();
        } else if (command == "modify") {
            modify();
        } else if (command == "filter") {
            filter();
        } else if (command == "sort") {
            sort();
        } else if (command == "help") {
            menu();
        } else
            std::cout << "Invalid command!\n\n";
    }
}

void interface::filter() {
    std::string input, out;
    std::cout<<"1 for type filter,\n"
               "2 for area filter\n"
               "Input:";
    std::getline(std::cin, input);

    try {
        if (input == "1") {
            std::cout<<"Type:";
            std::string filter;
            std::getline(std::cin,filter);
            out = srv.filter_type(filter);

        } else if (input == "2") {
            std::cout<<"Area:";
            std::string filter;
            std::getline(std::cin,filter);
            int temp =std::stoi(filter);
            if(temp < 1)
                throw std::exception();
            out = srv.filter_area(temp);

        } else {
            throw std::exception();
        }
    }
    catch(...){
        std::cout<<"Argument is invalid";
        std::cout<<std::endl;
        return;
    }
    if(out.empty())
        std::cout<<"No items were found.\n";
    else
        std::cout<<out;
    std::cout<<std::endl;
}

void interface::add() {
    int apartment, area;
    std::string owner, type;

    try {
        std::string input;
        std::cout << "Apartment:";
        std::getline(std::cin, input);
        apartment = std::stoi(input);

        std::cout << "Owner:";
        std::getline(std::cin, input);
        owner = input;

        std::cout << "Type:";
        std::getline(std::cin, input);
        type = input;

        std::cout << "Area:";
        std::getline(std::cin, input);
        area = std::stoi(input);

        if (apartment < 1 || area < 1)
            throw std::exception();
    }
    catch (...) {
        std::cout << "One or more arguments are invalid!\n";
        std::cout<<std::endl;
        return;
    }

    try {
        srv.add(apartment, owner, type, area);
    }
    catch (...) {
        std::cout << "Tenant already exists!\n";
        std::cout<<std::endl;
        return;
    }
    std::cout << "Tenant added.\n";
    std::cout<<std::endl;
}

void interface::show() {

    auto out = srv.show();
    if (out.empty())
        std::cout << "No tenant was found.\n";
    else
        std::cout << out;

    std::cout<<std::endl;


}

void interface::del() {


    int apartment;

    try {
        std::string input;
        std::cout << "Apartment:";
        std::getline(std::cin, input);
        apartment = std::stoi(input);

        if (apartment < 1)
            throw std::exception();
    }
    catch (...) {
        std::cout << "One or more arguments are invalid!\n";
        std::cout<<std::endl;
        return;
    }

    try {
        srv.del(apartment);
    }
    catch (...) {
        std::cout << "Tenant doesn't exists!\n";
        std::cout<<std::endl;
        return;
    }
    std::cout << "Tenant deleted.\n";
    std::cout<<std::endl;
}

void interface::find() {

    int apartment;

    try {

        std::string input;
        std::cout << "Apartment:";
        std::getline(std::cin, input);
        apartment = std::stoi(input);

        if (apartment < 1)
            throw std::exception();
    }
    catch (...) {
        std::cout << "One or more arguments are invalid!\n";
        std::cout<<std::endl;
        return;
    }

    try {
        auto out = srv.find(apartment);

        if (out.empty())
            std::cout << "No tenant was found.\n";
        else
            std::cout << out;
        std::cout<<std::endl;
    }
    catch (...) {
        std::cout << "No tenant was found!\n";
        std::cout<<std::endl;
        return;
    }
}

void interface::modify() {

    int apartment, new_apartment, new_area;
    std::string new_owner, new_type;


    try {
        std::string input;
        std::cout << "Apartment:";
        std::getline(std::cin, input);
        apartment = std::stoi(input);

        std::cout << "New Apartment:";
        std::getline(std::cin, input);
        new_apartment = std::stoi(input);

        std::cout << "New Owner:";
        std::getline(std::cin, input);
        new_owner = input;

        std::cout << "New Type:";
        std::getline(std::cin, input);
        new_type = input;

        std::cout << "New Area:";
        std::getline(std::cin, input);
        new_area = std::stoi(input);

        if (apartment < 1 || new_apartment < 1 || new_area < 1)
            throw std::exception();
    }
    catch (...) {
        std::cout << "One or more arguments are invalid!\n";
        std::cout<<std::endl;
        return;
    }

    try {
        srv.modify(apartment, new_apartment, new_owner, new_type, new_area);
    }
    catch (...) {
        std::cout << "Tenant doesn't exists!\n";
        std::cout<<std::endl;
        return;
    }
    std::cout << "Tenant modified.\n";
    std::cout<<std::endl;
}

void interface::menu() {
    std::cout << "* Menu:\n"
                 "  - add\n"
                 "  - delete\n"
                 "  - modify\n"
                 "  - show\n"
                 "  - find\n"
                 "  - sort\n"
                 "  - filter\n"
                 "  - help\n"
                 "  - exit\n\n";

}

void interface::sort() {
    std::string input, out;
    std::cout<<"1 for owner sort,\n"
               "2 for area sort,\n"
               "3 for apartment + area sort\n"
               "Input:";
    std::getline(std::cin, input);

    try {
        if (input == "1") {
            std::cout<<"Reverse(y/n):";
            std::string sort;
            std::getline(std::cin,sort);
            if(sort == "y")
                out = srv.sort_owner(true);
            else if(sort == "n")
                out = srv.sort_owner(false);
            else
                throw std::exception();

        } else if (input == "2") {
            std::cout<<"Reverse(y/n):";
            std::string sort;
            std::getline(std::cin,sort);
            if(sort == "y")
                out =srv.sort_area(true);
            else if(sort == "n")
                out =srv.sort_area(false);
            else
                throw std::exception();

        } else if (input == "3") {
            std::cout<<"Reverse(y/n):";
            std::string sort;
            std::getline(std::cin,sort);
            if(sort == "y")
                out = srv.sort_apartment_area(true);
            else if(sort == "n")
                out = srv.sort_apartment_area(false);
            else
                throw std::exception();

        } else {
            throw std::exception();
        }
    }
    catch(...){
        std::cout<<"Argument is invalid";
        std::cout<<std::endl;
        return;
    }
    if(out.empty())
        std::cout<<"List is empty.\n";
    else
        std::cout<<out;
    std::cout<<std::endl;
}
