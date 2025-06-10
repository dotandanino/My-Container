//dotandanino@gmail.com
#ifndef TEMPCLASS_HPP
#define TEMPCLASS_HPP
#include <iostream>
/**
 * @brief A temporary class for testing the container. 
 */
namespace containers {
    class TempClass {
private:
    int i;
    double d;
    std::string s;
public:

    /**
     * @brief Constructor for TempClass
     * @param i Integer value
     * @param d Double value
     * @param s String value
     */
    TempClass(int i, double d, const std::string& s);
    /**
     * @brief Get the integer value
     * @return Integer value
     */
    int getI() const;
    /**
     * @brief Get the double value
     * @return Double value
     */
    double getD() const;
    /**
     * @brief Get the string value
     * @return String value
     */
    const std::string& getS() const;
    /**
     * @brief Comparison operators for TempClass
     * @param other Another TempClass object
     * @return True if the objects are equal, false otherwise
     */
    bool operator==(const TempClass& other) const;
    /**
     * @brief Comparison operators for TempClass
     * @param other Another TempClass object
     * @return True if the objects are not equal, false otherwise
     */
    bool operator!=(const TempClass& other) const;
    /**
     * @brief Comparison operators for TempClass
     * @param other Another TempClass object
     * @return True if this object is less than the other, false otherwise
     */
    bool operator<(const TempClass& other) const;
    /**
     * @brief Comparison operators for TempClass
     * @param other Another TempClass object
     * @return True if this object is greater than the other, false otherwise
     */
    bool operator>(const TempClass& other) const;
    /**
     * @brief Comparison operators for TempClass
     * @param other Another TempClass object
     * @return True if this object is less than or equal to the other, false otherwise
     */
    bool operator<=(const TempClass& other) const;
    /**
     * @brief Comparison operators for TempClass
     * @param other Another TempClass object
     * @return True if this object is greater than or equal to the other, false otherwise
     */
    bool operator>=(const TempClass& other) const;

};
}
#endif // TEMPCLASS_HPP