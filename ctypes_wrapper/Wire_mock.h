// Wire.h (Mock)
#ifndef WIRE_H
#define WIRE_H

class TwoWire {
public:
    void begin() {}
    void beginTransmission(uint8_t address) {}
    uint8_t endTransmission() { return 0; }
    uint8_t requestFrom(uint8_t address, uint8_t quantity) { return 0; }
    size_t write(uint8_t data) { return 0; }
    int read() { return 0; }
};

extern TwoWire Wire;

#endif // WIRE_H
