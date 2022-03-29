#include "interface.h"

interface::interface(service& srv): srv(srv){}

void interface::run() {
    menu();
    std::string input;
    array<std::string> arg;
    size_t poz;
    std::string command;

    while(true){
        input.clear();
        arg.clear();

        std::cout<<"Command:";
        std::getline(std::cin, input);

        poz = input.find(' ');
        if(poz == std::string::npos){
            command = input;
        }
        else {
            command = input.substr(0, poz);

            input.erase(0, input.find(' ') + 1);

            while ((poz = input.find(", ")) != std::string::npos) {
                arg.push_back(input.substr(0, poz));
                input.erase(0, poz + 2);
            }
            arg.push_back(input);
        }
        if(command == "exit")
            break;
        else if(command.empty())
            continue;
        else if(command == "add"){
            add(arg);
        }
        else if(command == "delete"){
            del(arg);
        }
        else if(command == "find"){
            find(arg);
        }
        else if(command == "show"){
            show(arg);
        }
        else if(command == "modify"){
            modify(arg);
        }
        else if(command == "help"){
            menu();
        }
        else
            std::cout<<"Invalid command!\n";
    }
}

void interface::add(array<std::string>& arg){
      if(arg.size() < 4){
          std::cout<<"Too few arguments were given!\n";
      }
      else if(arg.size()>4){
          std::cout<<"Too many arguments were given!\n";
      }
      else{
          int apartment, area;
          std::string owner, type;
          try{
              apartment = std::stoi(arg[0]);
              owner = arg[1];
              type = arg[2];
              area = std::stoi(arg[3]);

              if(apartment < 1 || area < 1)
                  throw std::exception();
          }
          catch (...){
              std::cout<<"One or more arguments are invalid!\n";
              return;
          }

          try{
              srv.add(apartment, owner, type, area);
          }
          catch (...){
              std::cout<<"Tenant already exists!\n";
              return;
          }
          std::cout<<"Tenant added.\n";
      }
}

void interface::show(array<std::string> &arg) {
    if(arg.size() > 0){
        std::cout<<"Too many arguments were given!\n";
    }
    else{
        auto out = srv.show();
        if(out.empty())
            std::cout<<"No tenant was found.\n";
        else
            std::cout<<out;
    }

}

void interface::del(array<std::string>& arg){
    if(arg.size() < 4){
        std::cout<<"Too few arguments were given!\n";
    }
    else if(arg.size()>4){
        std::cout<<"Too many arguments were given!\n";
    }
    else{
        int apartment, area;
        std::string owner, type;
        try{
            apartment = std::stoi(arg[0]);
            owner = arg[1];
            type = arg[2];
            area = std::stoi(arg[3]);
            if(apartment < 1 || area < 1)
                throw std::exception();
        }
        catch (...){
            std::cout<<"One or more arguments are invalid!\n";
            return;
        }

        try{
            srv.del(apartment, owner, type, area);
        }
        catch (...){
            std::cout<<"Tenant doesn't exists!\n";
            return;
        }
        std::cout<<"Tenant deleted.\n";
    }
}

void interface::find(array<std::string>& arg){
    if(arg.size() < 1){
        std::cout<<"Too few arguments were given!\n";
    }
    else if(arg.size()>1){
        std::cout<<"Too many arguments were given!\n";
    }
    else{
        int apartment;
        try{
            apartment = std::stoi(arg[0]);
            if(apartment < 1)
                throw std::exception();
        }
        catch (...){
            std::cout<<"One or more arguments are invalid!\n";
            return;
        }

        try{
            auto out = srv.find(apartment);

            if(out.empty())
                std::cout<<"No tenant was found.\n";
            else
                std::cout<<out;
        }
        catch (...){
            std::cout<<"No tenant was found!\n";
            return;
        }
    }
}

void interface::modify(array<std::string>& arg){
    if(arg.size() < 8){
        std::cout<<"Too few arguments were given!\n";
    }
    else if(arg.size()>8){
        std::cout<<"Too many arguments were given!\n";
    }
    else{
        int apartment, area, new_apartment, new_area;
        std::string owner, type, new_owner, new_type;
        try{
            apartment = std::stoi(arg[0]);
            owner = arg[1];
            type = arg[2];
            area = std::stoi(arg[3]);
            new_apartment = std::stoi(arg[4]);
            new_owner = arg[5];
            new_type = arg[6];
            new_area = std::stoi(arg[7]);

            if(apartment < 1 || area < 1 || new_apartment < 1 || new_area < 1)
                throw std::exception();
        }
        catch (...){
            std::cout<<"One or more arguments are invalid!\n";
            return;
        }

        try{
            srv.modify(apartment, owner, type, area, new_apartment, new_owner, new_type, new_area);
        }
        catch (...){
            std::cout<<"Tenant doesn't exists!\n";
            return;
        }
        std::cout<<"Tenant modified.\n";
    }
}

void interface::menu() {
    std::cout<<"Menu:\n"
               "* add (int)apartment, (alpha)owner, (alpha)type, (int)area\n"
               "* del (int)apartment, (alpha)owner, (alpha)type, (int)area\n"
               "* modify (int)apartment, (alpha)owner, (alpha)type, (int)area,\n  (int)new_apartment, (alpha)new_owner, (alpha)new_type, (int)new_area\n"
               "* show\n"
               "* find (int)apartment\n"
               ;
}