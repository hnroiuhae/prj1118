#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include "ConnA.hpp"

IPPacket::IPPacket() {
    pktdata = 0;
    nsec = sec = 0;
}

void IPPacket::SetSec(uint32_t _sec) {
    sec = _sec;
}

void IPPacket::SetNsec(uint32_t _nsec) {
    nsec = _nsec;
}

void IPPacket::SetDataPtr(const unsigned char *_pktdata) {
    pktdata = _pktdata;
}

uint32_t IPPacket::GetSec() const {
    return sec;
}

uint32_t IPPacket::GetNsec() const {
    return nsec;
}

const uchar* IPPacket::GetDataPtr() const {
    return pktdata;
}

const IPPacket IPPacketInput::NULL_PACKET = IPPacket();

IPPacketInput::IPPacketInput() {
    p = 0;
    n = c = 0;
}

const IPPacket& IPPacketInput::next(bool &more) {
    if(c >= n) {
        more = false;
        return NULL_PACKET;
    }
    else {
        more = true;
        return p[c++];
    }
}

void IPPacketInput::reset() {
    n = 0;
}

uint32_t IPPacketInput::cur() const {
    return c;
}

uint32_t IPPacketInput::N() const {
    return n;
}

uint32_t IPPacketInput::Count() const {
    return n;
}

uint32_t IPPacketInput::Length() const {
    return n;
}

const IPPacket& IPPacketInput::operator[](uint32_t index) const {
    if(index >= n) throw "Index out of bound";
    return p[index];
}

int File2DS(const char *filename, IPPacketInput &pkts) {

}
