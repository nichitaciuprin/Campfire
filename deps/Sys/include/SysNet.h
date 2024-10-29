#ifndef SYSNET_H
#define SYSNET_H

#include <stdint.h>

void NetPrintAddr(uint64_t addr);
void NetPrintAddrAsHex(uint64_t addr);
uint64_t NetCreateAddr(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint16_t port);

void NetUseAnyPort();
void NetUsePort(int port);
void NetSend(uint64_t* addr, char* buffer, int* messageSize);
void NetRecv(uint64_t* addr, char* buffer, int* messageSize);

#endif
