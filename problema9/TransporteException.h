#ifndef TRANSPORTE_EXCEPTION_H
#define TRANSPORTE_EXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

namespace viajefeliz {
    class TransporteException : public runtime_error {
    public:
        TransporteException(const string& message) : runtime_error(message) {}
    };
}

#endif