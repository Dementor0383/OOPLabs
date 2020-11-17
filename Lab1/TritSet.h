//
// Created by dementor on 22.10.2020.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H
#include "Trit.h"
#include <vector>
#include <cmath>
#include <unordered_map>
#include <bitset>

#define uint32 unsigned int
#define ulli64 unsigned long long
#define UNKNOWN_INT 1431655765 // число unknown маски 01010101010101(16 тритов unknown)

uint32 convertUintToTrit();

class TritSet{
private:
    vector<uint32> array;
    ulli64 counter = 0;
    typedef struct tritHash{
        template <typename T>
        size_t operator()(T t) const
        {
            return static_cast<size_t>(t);
        }
    };
    void setTritValue(ulli64 tritPosition, trit value);
    trit getTritValue (ulli64 tritPosition) const;//const
public:
    TritSet(ulli64 quantity);
    ulli64 capacity();
    ulli64 getTritSize();
    void shrink();
    void trim(ulli64 lastIndex);
    ulli64 logicalLength();
    ulli64 cardinality(trit value);
    unordered_map<trit, int, tritHash> cardinality();

    typedef struct tritProxy{
    private:
        TritSet& tritPointer;
        ulli64 position;
    public:
        tritProxy(ulli64 pos, TritSet& t) : position(pos), tritPointer(t) {}
        ~tritProxy() = default;
        const TritSet& getTritPointer(){
            return tritPointer;
        }

        ulli64 getPosition(){
            return position;
        }

        operator trit() {
           if(position >= tritPointer.counter)
               return trit::Unknown;
           else{
               return tritPointer.getTritValue(position);
               }
        }

        trit operator|(const trit &trit){//[]=trit
            if (position >= tritPointer.counter)
                return trit::Unknown;
            else
                return this->tritPointer.getTritValue(this->position) | trit;
        }

        trit operator|(const tritProxy &trit){//[]=[]
            if (position >= tritPointer.counter)
                return trit::Unknown;
            else
                return this->tritPointer.getTritValue(this->position) | trit.tritPointer.getTritValue(trit.position);
        }

        trit operator&(const trit &trit){
            if (position >= tritPointer.counter)
                return trit::Unknown;
            else
                return this->tritPointer.getTritValue(this->position) & trit;
        }

        trit operator&(const tritProxy &trit){
            if (position >= tritPointer.counter)
                return trit::Unknown;
            else
                return this->tritPointer.getTritValue(this->position) & trit.tritPointer.getTritValue(trit.position);
        }

        trit operator!() {
            if (position >= tritPointer.counter)
                return trit::Unknown;
            else
                return !this->tritPointer.getTritValue(this->position);
        }

        bool operator==(const trit &trit){
            if (position >= tritPointer.counter)
                return trit::Unknown == trit;
            else
                return this->tritPointer.getTritValue(this->position) == trit;
        }

        bool operator==(const tritProxy &trit){
            if (position >= tritPointer.counter)
                return false;
            else
                return this->tritPointer.getTritValue(this->position) == trit.tritPointer.getTritValue(trit.position);
        }

        bool operator!=(const trit &trit){
            if (position >= tritPointer.counter)
                return false;
            else
                return this->tritPointer.getTritValue(this->position) != trit;
        }

        bool operator!=(const tritProxy &trit){
            if (position >= tritPointer.counter)
                return false;
            else
                return this->tritPointer.getTritValue(this->position) != trit.tritPointer.getTritValue(trit.position);
        }

        tritProxy& operator=(const trit &trit){
            if (trit != trit::Unknown && position >= tritPointer.counter){
                tritPointer.array.resize(ceil((2.0 * (1.0 + position)) / (8.0 * sizeof(uint32))), UNKNOWN_INT);
                tritPointer.counter = position + 1;
                tritPointer.setTritValue(position, trit);
            }
            else if (position < tritPointer.counter){
                this->tritPointer.setTritValue(position, trit);
            }
        return *this;
        }
    };

    friend ostream& operator<< (ostream &stream, TritSet::tritProxy trit){
        if(trit.getPosition() >= trit.getTritPointer().counter)
            return stream << trit::Unknown;
        else
            return stream << trit.getTritPointer().getTritValue(trit.getPosition());
    }

    tritProxy operator[](ulli64 b);
    TritSet operator&(TritSet &a);
    TritSet operator|(TritSet &a);
    TritSet operator!();
};

#endif //LAB1_TRITSET_H
