#include "../include/tempClass.hpp"
using namespace containers;
/**
 * @brief Constructor for TempClass
 * @param i Integer value
 * @param d Double value
 * @param s String value
 */
TempClass::TempClass(int i, double d, const std::string& s) : i(i), d(d), s(s) {}
/**
 * @brief Get the integer value
 * @return Integer value
 */
int TempClass::getI() const { 
    return i; 
}
/**
 * @brief Get the double value
 * @return Double value
 */
double TempClass::getD() const { 
    return d; 
}
/**
 * @brief Get the string value
 * @return String value
 */
const std::string& TempClass::getS() const { 
    return s; 
}
/**
 * @brief Comparison operators for TempClass
 * @param other Another TempClass object
 * @return True if the objects are equal, false otherwise
 */
bool TempClass::operator==(const TempClass& other) const {
    return i == other.i && d == other.d && s == other.s;
}
/**
 * @brief Comparison operators for TempClass
 * @param other Another TempClass object
 * @return True if the objects are not equal, false otherwise
 */
bool TempClass::operator!=(const TempClass& other) const {
    return !(*this == other);
}
/**
 * @brief Comparison operators for TempClass
 * @param other Another TempClass object
 * @return True if this object is less than the other, false otherwise
 */
bool TempClass::operator<(const TempClass& other) const {
    if(i<other.i) return true;
    if(i>other.i) return false;
    if(d<other.d) return true;
    if(d>other.d) return false;
    return s < other.s;
}
/**
 * @brief Comparison operators for TempClass
 * @param other Another TempClass object
 * @return True if this object is greater than the other, false otherwise
 */
bool TempClass::operator>(const TempClass& other) const {
    return other < *this;
}
/**
 * @brief Comparison operators for TempClass
 * @param other Another TempClass object
 * @return True if this object is less than or equal to the other, false otherwise
 */
bool TempClass::operator<=(const TempClass& other) const {
    return !(*this > other);
}
/**
 * @brief Comparison operators for TempClass
 * @param other Another TempClass object
 * @return True if this object is greater than or equal to the other, false otherwise
 */
bool TempClass::operator>=(const TempClass& other) const {
    return !(*this < other);
}