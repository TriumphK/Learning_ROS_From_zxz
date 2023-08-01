#ifndef DBX_BASE_H_
#define DBX_BASE_H_

namespace dbx_base_ns
{
    class Dbx_Base
    {
        protected:
            Dbx_Base(){}
        public:
            virtual double getlength() = 0;
            virtual void init(double side_length) = 0;
    };
};

#endif