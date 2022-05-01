#include <fstream>
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
            add();}
        else if (command == "undo") {
                undo();
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
        } else if (command == "cart") {
            cart();
        } else if (command == "bash") {
            bash();
        } else
            std::cout << "Invalid command!\n\n";
    }
}

//void interface::filter(std::istringstream* in) {
//
//    std::string input, out;
//    std::cout<<"1 for type filter,\n"
//               "2 for area filter\n"
//               "Input:";
//
//    if(in == nullptr)
//        std::getline(std::cin, input);
//    else
//        std::getline(*in, input);
//
//    try {
//        if (input == "1") {
//            std::cout<<"Type:";
//            std::string filter;
//            if(in == nullptr)
//                std::getline(std::cin, filter);
//            else
//                std::getline(*in, filter);
//            out = srv.filter_type(filter);
//
//        } else if (input == "2") {
//            std::cout<<"Area:";
//            std::string filter;
//            if(in == nullptr)
//                std::getline(std::cin, filter);
//            else
//                std::getline(*in, filter);
//            int temp =std::stoi(filter);
//            if(temp < 1)
//                throw std::exception();
//            out = srv.filter_area(temp);
//
//        } else {
//            throw std::exception();
//        }
//    }
//    catch(...){
//        std::cout<<"Argument is invalid";
//        std::cout<<std::endl;
//        return;
//    }
//    if(out.empty())
//        std::cout<<"No items were found.\n";
//    else
//        std::cout<<out;
//    std::cout<<std::endl;
//}

void interface::add(std::istringstream* in) {
    int apartment, area;
    std::string owner, type;

    try {
        std::string input;
        std::cout << "Apartment:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        apartment = std::stoi(input);

        std::cout << "Owner:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        owner = input;

        std::cout << "Type:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        type = input;

        std::cout << "Area:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
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
    try {
        auto out = srv.show();
        if (out.empty())
            std::cout << "No tenant was found.\n";
        else
            std::cout << out;

        std::cout << std::endl;
    }
    catch(...){
        std::cout<<"Nasol\n";
    }

}

void interface::del(std::istringstream* in) {


    int apartment;

    try {
        std::string input;
        std::cout << "Apartment:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
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

void interface::find(std::istringstream* in) {

    int apartment;

    try {

        std::string input;
        std::cout << "Apartment:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
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

void interface::modify(std::istringstream* in) {

    int apartment, new_apartment, new_area;
    std::string new_owner, new_type;


    try {
        std::string input;
        std::cout << "Apartment:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        apartment = std::stoi(input);

        std::cout << "New Apartment:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        new_apartment = std::stoi(input);

        std::cout << "New Owner:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        new_owner = input;

        std::cout << "New Type:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        new_type = input;

        std::cout << "New Area:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
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

//void interface::sort(std::istringstream* in){
//    std::string input, out;
//    std::cout<<"1 for owner sort,\n"
//               "2 for area sort,\n"
//               "3 for apartment + area sort\n"
//               "Input:";
//    if(in == nullptr)
//        std::getline(std::cin, input);
//    else
//        std::getline(*in, input);
//
//    try {
//        if (input == "1") {
//            std::cout<<"Reverse(y/n):";
//            std::string sort;
//            if(in == nullptr)
//                std::getline(std::cin, sort);
//            else
//                std::getline(*in, sort);
//            if(sort == "y")
//                out = srv.sort_owner(true);
//            else if(sort == "n")
//                out = srv.sort_owner(false);
//            else
//                throw std::exception();
//
//        } else if (input == "2") {
//            std::cout<<"Reverse(y/n):";
//            std::string sort;
//            if(in == nullptr)
//                std::getline(std::cin, sort);
//            else
//                std::getline(*in, sort);
//            if(sort == "y")
//                out =srv.sort_area(true);
//            else if(sort == "n")
//                out =srv.sort_area(false);
//            else
//                throw std::exception();
//
//        } else if (input == "3") {
//            std::cout<<"Reverse(y/n):";
//            std::string sort;
//            if(in == nullptr)
//                std::getline(std::cin, sort);
//            else
//                std::getline(*in, sort);
//            if(sort == "y")
//                out = srv.sort_apartment_area(true);
//            else if(sort == "n")
//                out = srv.sort_apartment_area(false);
//            else
//                throw std::exception();
//
//        } else {
//            throw std::exception();
//        }
//    }
//    catch(...){
//        std::cout<<"Argument is invalid";
//        std::cout<<std::endl;
//        return;
//    }
//    if(out.empty())
//        std::cout<<"List is empty.\n";
//    else
//        std::cout<<out;
//    std::cout<<std::endl;
//}

void interface::cart(std::istringstream* in) {
    menu_cart();

    std::string command;
    std::cout << "Command:";
    if(in == nullptr)
        std::getline(std::cin, command);
    else
        std::getline(*in, command);

    if (command == "exit" || command.empty())
        return;
    else if (command == "add") {
        add_cart(in);
    } else if (command == "empty") {
        empty_cart();
    }
    else if (command == "export") {
        export_cart(in);
    }
    else if (command == "random") {
        random_cart(in);
    }
    else {
        std::cout << "Invalid command!\n\n";
    }
}

void interface::add_cart(std::istringstream* in) {
    int apartment;

    try {
        std::string input;
        std::cout << "Apartment:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
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
        srv.add_cart(apartment);
    }
    catch (my_exception& e) {
        if(e.get_error() == "Not found"){
            std::cout << "Tenant not found!\n";
            std::cout << std::endl;
            return;
        }
        else {
            std::cout << "Tenant already exists!\n";
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Tenant added.\n";
    std::cout<<std::endl;
}

void interface::empty_cart() {
    srv.empty_cart();
    std::cout<<"Cart emptied.\n";
}

void interface::random_cart(std::istringstream* in) {

    int num;

    try {
        std::string input;
        std::cout << "Number of apartments:";
        if(in == nullptr)
            std::getline(std::cin, input);
        else
            std::getline(*in, input);
        num = std::stoi(input);


        if (num < 1)
            throw std::exception();
    }
    catch (...) {
        std::cout << "One or more arguments are invalid!\n";
        std::cout<<std::endl;
        return;
    }

    try {
        srv.random_cart(num);
    }
    catch (my_exception& e) {
        if(e.get_error() == "No tenants"){
            std::cout << "No tenants were found!\n";
            std::cout << std::endl;
            return;
        }
        else {
            std::cout << "Not enough tenants! Maximum number was added\n";
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Tenant added.\n";
    std::cout<<std::endl;
}

void interface::export_cart(std::istringstream* in) {
    std::string file;

    try {
        std::cout << "File name:";
        if(in == nullptr)
            std::getline(std::cin, file);
        else
            std::getline(*in, file);
    }
    catch (...) {
        std::cout << "One or more arguments are invalid!\n";
        std::cout<<std::endl;
        return;
    }

//    try {
        srv.export_cart(file);
//    }
//    catch (my_exception& e) {
//        if(e.get_error() == "No tenants"){
//            std::cout << "No tenants were found!\n";
//            std::cout << std::endl;
//            return;
//        }
//        else {
//            std::cout << "Not enough tenants! Maximum number was added\n";
//            std::cout << std::endl;
//            return;
//        }
//    }
    std::cout << "File exported.\n";
    std::cout<<std::endl;
}

void interface::menu_cart() {
    std::cout << "* Menu cart:\n"
                 "  - add\n"
                 "  - random\n"
                 "  - empty\n"
                 "  - export\n"
                 "  - help\n"
                 "  - exit\n\n";
}

void interface::bash() {
    std::fstream fin;

    std::string command, filename, temp, temp2;
    std::cout<<"Filename: ";
    std::getline(std::cin, filename);
    std::cout<<std::endl;
    fin.open(filename, std::ios_base::in);
    if(!fin.good()){
        std::cout<<"File doesn't exist!\n";
        return;
    }

    while (!fin.eof()) {

        command.clear();
        temp2.clear();

        std::getline(fin, command, ';');
        std::getline(fin, temp );
        std::istringstream ss(temp);
        while(std::getline(ss, temp, ';')){
            temp2+=temp+'\n';
        }
        std::istringstream f_in(temp2);

        if (command == "exit")
            break;
        else if (command == "add") {
            add(&f_in);
        } else if (command == "delete") {
            del(&f_in);
        } else if (command == "find") {
            find(&f_in);
        } else if (command == "show") {
            show();
        } else if (command == "modify") {
            modify(&f_in);
        } else if (command == "filter") {
            filter(&f_in);
        } else if (command == "sort") {
            sort(&f_in);
        } else if (command == "help") {
            menu();
        } else if (command == "cart") {
            cart(&f_in);
        } else
            std::cout << "Invalid command!\n\n";
    }
}

void interface::undo() {
    try{
        srv.undo();
    }
    catch(...){
        std::cout<<"No actions to undo\n";
        return;
    }

    std::cout<<"Undo successful\n\n";
}
