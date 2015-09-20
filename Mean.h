/* 
 * File:   Mean.h
 * Author: delio
 *
 * Created on 13 September 2015, 23:46
 */

#ifndef MEAN_H
#define	MEAN_H

class Mean {
public:
    Mean(std::list<float> data);
    Mean(const Mean& orig);
    virtual ~Mean();
    float getValue();
private:
    std::list<float> serie;
};

#endif	/* MEAN_H */

