/*
 * Wire.h
 *
 *  Created on: Dec 12, 2022
 *      Author: steph
 */

#ifndef TwoWire_h
#define TwoWire_h
#include <inttypes.h>
#include "Stream.h"
#include <msp430.h>

#define BUFFER_LENGTH 16

class TwoWire : public Stream
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    TwoWire();
    TwoWire(uint8_t module);
    void begin();
    void begin(uint8_t);
    void begin(int);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
#define USCI_ERROR "\n*********\nI2C Slave is not implemented for this MSP430. \nConsider using using a MSP430 with USCI peripheral e.g. MSP430G2553.\n*********\n"
#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__)
    void onReceive( void (*)(int) );
    void onRequest( void (*)(void) );
#else
    void onReceive( void (*)(int) ) __attribute__ ((error(USCI_ERROR)));
    void onRequest( void (*)(void) ) __attribute__ ((error(USCI_ERROR)));
#endif

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;
    void setModule(uint8_t i2cModule);
};

extern TwoWire Wire;

#endif
/* WIRE_H_ */
