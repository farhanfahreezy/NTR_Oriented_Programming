#ifndef VALUE_HPP
#define VALUE_HPP

class Value{
    public:
        virtual float value() const = 0;
        virtual bool operator>(const Value& v){return value() > v.value();};
        virtual bool operator<(const Value& v){return value() < v.value();};
        virtual bool operator==(const Value& v){return value() == v.value();};
};
#endif