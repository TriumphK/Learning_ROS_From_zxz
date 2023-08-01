#ifndef DBX_PLUGINS_H_
#define DBX_PLUGINS_H_

#include "plugin_test/dbx_base.h"

namespace dbx_plugins_ns
{
    class SanBian: public dbx_base_ns::Dbx_Base
    {
        private:
            double side_length;
        public:
            SanBian()
            {
                side_length = 0.0;
            }
            void init(double side_length)
            {
                this->side_length = side_length;
            }
            double getlength()
            {
                return side_length * 3;
            }
    };
    class SiBian: public dbx_base_ns::Dbx_Base
    {
        private:
            double side_length;
        public:
            SiBian()
            {
                side_length = 0.0;
            }
            void init(double side_length)
            {
                this->side_length = side_length;
            }
            double getlength()
            {
                return side_length * 4;
            }
    };
};

#endif