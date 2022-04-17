#pragma once
#include <string>
#include <iostream>

class tenant{
private:
    int apartment;
    std::string owner;
    std::string type;
    int area;

public:
    /**
     * Creates a tenant object with given parameters.
     * @param apartment Apartment number
     * @param owner Apartment owner
     * @param type Apartment type
     * @param area Apartment area
     */

    tenant(int apartment, std::string owner, std::string type, int area);

    tenant(const tenant& other);

    /**
     * Default destructor.
     */
    ~tenant()= default;

    /**
     * Returns apartment number.
     * @return Apartment
     */
    [[nodiscard]] int get_apartment() const;

    /**
     * Returns apartment owner.
     * @return Owner
     */
    [[nodiscard]] std::string get_owner() const;

    /**
     * Returns apartment type.
     * @return Type
     */
    [[nodiscard]] std::string get_type() const;

    /**
     * Returns apartment area.
     * @return Area
     */
    [[nodiscard]] int get_area() const;

    /**
     * Changes aparment value to given parameter.
     * @param new_aparment Apartment
     */
    void set_apartment(int new_apartment);

    /**
     * Changes owner value to given parameter.
     * @param new_owner Owner
     */
    void set_owner(const std::string& new_owner);

    /**
     * Changes type value to given parameter.
     * @param new_type Type
     */
    void set_type(const std::string& new_type);

    /**
     * Changes area value to given parameter.
     * @param new_area Area
     */
    void set_area(int new_area);

    bool operator!= (const tenant& other) const;

    bool operator == (const tenant& other) const;

    std::string str();
};

