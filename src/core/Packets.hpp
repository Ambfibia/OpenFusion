#pragma once

#include <map>
#include <string>

#include "CNStructs.hpp"

// Packet Descriptor
struct PacketDesc {
        uint32_t val = 0;
        std::string name = "";
        size_t size = 0;
        bool variadic = false;
        size_t cntMembOfs = 0;
        size_t trailerSize = 0;

        PacketDesc() = default;
        PacketDesc(const PacketDesc& other) = default;
        PacketDesc(PacketDesc&& other) = default;
        PacketDesc& operator=(const PacketDesc& other) = default;
        PacketDesc& operator=(PacketDesc&& other) = default;

        // non-variadic constructor
        PacketDesc(uint32_t v, size_t s, std::string n) :
            val(v), name(n), size(s), variadic(false) {}

        // variadic constructor
        PacketDesc(uint32_t v, size_t s, std::string n, size_t ofs, size_t ts) :
            val(v), name(n), size(s), variadic(true), cntMembOfs(ofs), trailerSize(ts) {}
};

/*
 * Extra trailer structs for places where the client doesn't have any, but
 * really should.
 */
struct sGM_PVPTarget {
    uint32_t iID;
    uint32_t eCT;
};

struct sSkillResult_Leech {
    sSkillResult_Heal_HP Heal;
    sSkillResult_Damage Damage;
};

namespace Packets {
    extern std::map<uint32_t, PacketDesc> packets;

    void init();
    std::string p2str(int val);
}
