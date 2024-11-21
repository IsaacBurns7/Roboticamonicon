// wrapper.cpp
#include "MS5837.hpp"

// Since we're not using an Arduino environment, we need to handle the absence of TwoWire and Wire.
// For demonstration purposes, we'll assume that methods can be called without them or mock their functionality.

extern "C" {

    // Constructor wrapper
    void* MS5837_new() {
        return new MS5837();
    }

    // Destructor wrapper
    void MS5837_delete(void* instance) {
        delete static_cast<MS5837*>(instance);
    }

    bool MS5837_init(void* instance, TwoWire* wirePort){
        if(wirePort == nullptr){
            //if wireport was not passed, use default
            return static_cast<MS5837*>(instance) -> init();
        }else{
            return static_cast<MS5837*>(instance) -> init(*wirePort);
        }
    }
	bool MS5837_begin(void* instance, TwoWire* wirePort){
        if(wirePort == nullptr){
            return static_cast<MS5837*>(instance) -> begin();
        }else{
            return static_cast<MS5837*>(instance) -> begin(*wirePort);
        }
    }

    // setModel() wrapper
    void MS5837_setModel(void* instance, uint8_t model) {
        static_cast<MS5837*>(instance)->setModel(model);
    }

    // getModel() wrapper
    uint8_t MS5837_getModel(void* instance) {
        return static_cast<MS5837*>(instance)->getModel();
    }

    // setFluidDensity() wrapper
    void MS5837_setFluidDensity(void* instance, float density) {
        static_cast<MS5837*>(instance)->setFluidDensity(density);
    }

    // read() wrapper
    void MS5837_read(void* instance) {
        static_cast<MS5837*>(instance)->read();
    }

    // pressure() wrapper
    float MS5837_pressure(void* instance, float conversion) {
        return static_cast<MS5837*>(instance)->pressure(conversion);
    }

    // temperature() wrapper
    float MS5837_temperature(void* instance) {
        return static_cast<MS5837*>(instance)->temperature();
    }

    // depth() wrapper
    float MS5837_depth(void* instance) {
        return static_cast<MS5837*>(instance)->depth();
    }

    // altitude() wrapper
    float MS5837_altitude(void* instance) {
        return static_cast<MS5837*>(instance)->altitude();
    }

    // Access static constants (e.g., MS5837::Pa)
    float MS5837_get_Pa() {
        return MS5837::Pa;
    }

    float MS5837_get_bar() {
        return MS5837::bar;
    }

    float MS5837_get_mbar() {
        return MS5837::mbar;
    }

    uint8_t MS5837_get_MS5837_30BA() {
        return MS5837::MS5837_30BA;
    }

    uint8_t MS5837_get_MS5837_02BA() {
        return MS5837::MS5837_02BA;
    }

    uint8_t MS5837_get_MS5837_UNRECOGNISED() {
        return MS5837::MS5837_UNRECOGNISED;
    }
}
