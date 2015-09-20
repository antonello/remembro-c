/* 
 * File:   Mean.cpp
 * Author: delio
 * 
 * Created on 13 September 2015, 23:46
 */

#include <cstdlib>
#include <list>
#include <iostream>

#include "Mean.h"

Mean::Mean(std::list<float> data) {
    serie = data;
}

Mean::Mean(const Mean& orig) {
}

Mean::~Mean() {
}

float Mean::getValue() {
    float result = 0;
    for (std::list<float>::iterator it=serie.begin(); it!=serie.end(); ++it)
        result += *it;
    return result/serie.size();
}

