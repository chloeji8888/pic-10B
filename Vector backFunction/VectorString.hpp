//
//  VectorString.hpp
//  HW3
//
//  Created by Zhenyuxi Ji on 2022/1/15.
//

#ifndef VectorString_hpp
#define VectorString_hpp

#include <stdio.h>
#include <memory>
#include<string>
#include<array>
#include<iostream>

namespace pic10b{

class VectorString{
    
private:
    size_t vec_size;//the number of elements in the vector
    size_t vec_capacity;//the size of the underlying dynamic array in memory
    std::unique_ptr<std::string[]> Array;//smart pointer variable to the dynamic array
public:
    /**
     default constructor that allocates a dynamic array of std::string
     */
    VectorString();
    
    /**
     allocates a dynamic array of twice the input size
     @param vecSize is the input for the vec_size and vec_capacity is twice twice the input with all of the string variable set to the empty string
     */
    VectorString(size_t vecSize);
    
    /**
     a constructor accepting a size and input string value that does the same as above with input size and capcity, but which initialize
     all the string variables to the imput string.
     @param size is the input size of the array
     @param String is the input string of the array
     */
    VectorString(size_t size, std::string String);
    
    /**
     copy constructor
     @param copyVec The new object that is going to copy this old one
     */
    VectorString(const VectorString& copyVec);
    
    /**
     copy copy assignment
     @param copyVec The new object that is going to copy this old one
     @return the copied  new Array
     */
    VectorString& operator = (const VectorString& copyVec);

    /**
     move constructor
     @param moveVec the xvalue object that the Array may be
     */
    VectorString(VectorString&& moveVec);
    
    /**
     move assignment
     @param moveVec the xvalue object that the Array may be
     */
    VectorString& operator = (VectorString&& moveVec);
    
    
    /**
     member function that return the size of the vector
     @return size of the vector;
     */
    size_t size()const ;
    
    /**
     member function returning the capacity of the vector
     @return the capacity of the vector
     */
    size_t capacity()const;
    
    /**
     member function accepting a string that adds an elements to the end of the vector if the capacity allows and otherwise creates a new
     dynamic array of twice the former capacity, moving all the elements over and adding the new elements.
     @param addString the string that the vector wants to add
     */
    void push_back(const std::string& addString);
    
    /**
     member function that "remove" the last element of the vecotr by updating its vec_size value(the value will remain there in memory but by changing
     the size, you can logically overwrite it if there is another insertion.
     */
    void pop_back();
    
    /**
     member function accepting an index value that removes the element at the given index from the vector, shifting elements backwards as appropriate
     (the last value will still be there in memory but can be overwriiten
     @param index the index value from the vector that the user wants to remove
     */
    void deleteAt(const size_t& index);
    
    /**
     member function accepting an index and string value that inserts an elemts at the input position, moving elements forward and when
     this would push the vecotr size above the capacity then all the elements should be moved over to a new dynamic array of twice the
     former capacity before the process
     @param index the index value that the user wants to put the string
     @param String the string value that the user wants to put in the vector.
     */
    void insertAt(const size_t& index, const std::string& String);
    
    /**
     member function, overload on const, acceptinh an index value that return the element at the given index by reference /reference to const.
     @param index the index that the user wants the value to get from
     @return the element ar the given index by reference/reference to const
     */
    std::string& at(const size_t& index);
    
    std::string& at(const size_t& index)const;
    
};

}

#endif /* VectorString_hpp */
