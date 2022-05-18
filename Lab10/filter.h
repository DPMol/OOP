#pragma once
#include <vector>
#include "tenant.h"
#include <algorithm>
#include <string>

class filter
{
public:
    filter();

    virtual void apply(std::vector<tenant>&) = 0;
};


class filter_type : public filter{
    filter_type(std::string type): type(type){};

    void apply(std::vector<tenant> &v) override{
        auto cpy = v;
        v.clear();
        std::copy_if(cpy.begin(), cpy.end(), std::back_inserter(v), [this](tenant& el) {
                return el.get_type() == this->type;
        });
    }

public:
    std::string type;
};

class filter_apartment : public filter{
    filter_apartment(int ap) : ap(ap) {};

    void apply(std::vector<tenant> &v) override{
        auto cpy = v;
        v.clear();
        std::copy_if(cpy.begin(), cpy.end(), std::back_inserter(v), [this](tenant& el) {
                return el.get_apartment() <= this->ap;
        });
    }
private:
    int ap;
};

class filter_area : public filter{
    filter_area(int area): area(area){};

    void apply(std::vector<tenant> &v) override{
        auto cpy = v;
        v.clear();
        std::copy_if(cpy.begin(), cpy.end(), std::back_inserter(v), [this](tenant& el) {
                return el.get_area() >= this->area;
        });
    }
private:
    int area;
};
