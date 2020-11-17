//
// Created by dementor on 22.10.2020.
//

#include "Trit.h"

ostream& operator<<(ostream& out, trit a){
    switch(a){
        case trit::False:
            return out << "False";
        case trit::Unknown:
            return out << "Unknown";
        case trit::True:
            return out << "True";
    }
    return out << "Unknown";
}

trit operator!(trit a){
    switch(a){
        case trit::False:
            return trit::True;
        case trit::Unknown:
            return trit::Unknown;
        case trit::True:
            return trit::False;
    }
    return trit::Unknown;
}

trit operator|(trit a, trit b){
    switch(a){
        case trit::False:
            switch(b){
            case trit::False:
                return trit::True;
            case trit::Unknown:
                return trit::Unknown;
            case trit::True:
                return trit::True;
        }
        case trit::Unknown:
            switch(b){
                case trit::False:
                    return trit::Unknown;
                case trit::Unknown:
                    return trit::Unknown;
                case trit::True:
                    return trit::True;
            }
        case trit::True:
            switch(b){
                case trit::False:
                    return trit::True;
                case trit::Unknown:
                    return trit::True;
                case trit::True:
                    return trit::True;
            }
    }
    return trit::Unknown;
}

trit operator&(trit a, trit b){
    switch(a){
        case trit::False:
            switch(b){
                case trit::False:
                    return trit::False;
                case trit::Unknown:
                    return trit::False;
                case trit::True:
                    return trit::False;
            }
        case trit::Unknown:
            switch(b){
                case trit::False:
                    return trit::False;
                case trit::Unknown:
                    return trit::Unknown;
                case trit::True:
                    return trit::Unknown;
            }
        case trit::True:
            switch(b){
                case trit::False:
                    return trit::False;
                case trit::Unknown:
                    return trit::Unknown;
                case trit::True:
                    return trit::True;
            }
    }
    return trit::Unknown;
}
