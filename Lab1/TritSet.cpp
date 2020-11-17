//
// Created by dementor on 22.10.2020.
//

#include "TritSet.h"

uint32 convertUintToTrit(){
    uint32 numberOfTrit = (8 * sizeof(uint32))/2;
    return numberOfTrit;
}

ulli64 TritSet::getTritSize() {
    return counter;
}

void setBit(uint32 &uintNum, uint32 bin1, uint32 bin2, uint32 tritPlace){
    tritPlace*=2;
    if (bin1 == 1) uintNum |= 1u << tritPlace;
    else uintNum &= ~(1u << tritPlace);
    tritPlace += 1;
    if (bin2 == 1) uintNum |= 1u << tritPlace;
    else uintNum &= ~(1u << tritPlace);
}

uint32 getBit(uint32 uintNum, uint32 tritPlace){
    uintNum >>= tritPlace;
    uintNum &= 1u;
    return uintNum;
}

void TritSet::setTritValue(ulli64 tritPosition, trit value){

    ulli64 numOfUint = tritPosition / convertUintToTrit();
    uint32 numOfTritPosition = tritPosition % convertUintToTrit();

    uint32 saveValue;
    uint32 bin1, bin2;
    switch(value){
        case trit::False:
            saveValue = 0;
            bin1 = bin2 = 0;
            break;
        case trit::Unknown:
            saveValue = 1;
            bin1 = 1; bin2 = 0;
            break;
        case trit::True:
            saveValue = 3;
            bin1 = bin2 = 1;
            break;
    }

setBit(array[numOfUint], bin1, bin2, numOfTritPosition);

}

trit TritSet::getTritValue (ulli64 tritPosition) const{
    ulli64 numOfUint = tritPosition / convertUintToTrit();
    uint32 numTritPosition = tritPosition % convertUintToTrit();

 unsigned char saveValue = 0;
 numTritPosition *= 2;
 saveValue |= getBit(array[numOfUint], numTritPosition);
 numTritPosition += 1;
 saveValue |= getBit(array[numOfUint], numTritPosition) << 1u;

 switch(saveValue){
     case 0:
          return trit::False;
     case 1:
         return trit::Unknown;
     case 2:
         return trit::Unknown;
     case 3:
         return trit::True;
     default:
         return trit::False;
 }
}

 TritSet::TritSet(ulli64 quantity) {

    vector<uint32> unknownVector(ceil((2.0 * quantity)/(8.0 * sizeof(uint32))), UNKNOWN_INT);

    counter = quantity;
    array = unknownVector;
}

ulli64 TritSet::capacity(){
    return ceil((2.0 * counter) / (8.0 * sizeof(uint32)));
}

TritSet::tritProxy TritSet::operator[](ulli64 b){
    tritProxy a(b, *this);
    return a;
}

TritSet TritSet::operator|(TritSet &a){
    auto c = TritSet(a.capacity() > this->capacity() ? a.capacity() : this->capacity());
    size_t size;
    if (a.capacity() > this->capacity()){
        c.array = a.array;
        c.counter = a.counter;
        size = this->array.size();
    }
    else if (a.capacity() <= this->capacity())
    {
        c.array = this->array;
        c.counter = this->counter;
        size = a.array.size();
    }
    for(size_t i = 0; i < size; ++i)
        c.array[i] |= a.capacity() > this->capacity() ? this->array[i] : a.array[i];
    return move(c);
}

TritSet TritSet::operator&(TritSet& a){
    auto c = TritSet(a.capacity() > this->capacity() ? a.capacity() : this->capacity());
    size_t size;
    if (a.capacity() > this->capacity()){
        c.array = a.array;
        c.counter = a.counter;
        size = this->array.size();
    }
    else if (a.capacity() <= this->capacity())
    {
        c.array = this->array;
        c.counter = this->counter;
        size = a.array.size();
    }
    for(size_t i = 0; i < size; ++i)
        c.array[i] &= a.capacity() > this->capacity() ? this->array[i] : a.array[i];
    return move(c);
}

TritSet TritSet::operator!(){
    auto c = TritSet(this->capacity());
    c.array = this->array;
    c.counter = this->counter;
    for (uint32 &all : c.array){
     all = ~all;
        for(size_t i = 0; i < convertUintToTrit(); ++i)
            if (!(all >> (i * 2u) & 1u) && (all >> (i * 2u + 1u) & 1u))
                setBit(all, 1, 0, i);
    }
    return move(c);
}

void TritSet::shrink(){
    array.clear();
    counter = array.size();
}

void TritSet::trim(ulli64 lastIndex){
  ulli64 saveLastIndex = lastIndex;
  ulli64 localTritPosition = saveLastIndex % convertUintToTrit();
  for (localTritPosition; localTritPosition < convertUintToTrit(); localTritPosition++){
   setTritValue(saveLastIndex, trit::Unknown);
   saveLastIndex++;
  }
  ulli64 uintPosition = lastIndex / convertUintToTrit();
  while (uintPosition <= array.size()){
      array.pop_back();
      uintPosition++;
  }
}

ulli64 TritSet::logicalLength() {//поправить
 uint32 sizeOfArray = array.size();
 ulli64 lastTritPosition = (sizeOfArray * sizeof(uint32) * 8) / 2;
 ulli64 length = 0; uint32 counter = 0;
 for(uint32 i = 0; i < lastTritPosition; i++){
     counter++;
     if(getTritValue(i) != trit::Unknown){
         length+=counter;
         counter = 0;
     }
 }
 return length + 1;
}

ulli64 TritSet::cardinality(trit value){
ulli64 lastInstallTrit = logicalLength();
uint32 countTritValue = 0;
for(int i = 0; i <= lastInstallTrit; i++){
    if (getTritValue(i) == value) {
     countTritValue++;
    }
}
return countTritValue;
}

unordered_map<trit, int, TritSet::tritHash> TritSet::cardinality() {
    unordered_map<trit, int, TritSet::tritHash> tritValueCounter;
    tritValueCounter.insert(make_pair<trit, int>(trit::True, cardinality(trit::True)));
    tritValueCounter.insert(make_pair<trit, int>(trit::False, cardinality(trit::False)));
    tritValueCounter.insert(make_pair<trit, int>(trit::Unknown, cardinality(trit::Unknown)));
    return tritValueCounter;
}

