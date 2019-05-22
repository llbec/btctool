#include "hash.h"

template<typename T>
void write(CHashWriter &s, const T& obj){ s << obj; }

void ShowHash(int argc, char const * argv[])
{
    int32_t nVersion = 536870912;
    uint256 prevhash = uint256S("eeb757e2b2fb20bd22e1910fbf8ccef14dd866bda5c1f2eacdd3214cb8f4261e");
    uint256 merkleroot = uint256S("a1934077165942b9dab9f4b30f349450a8a74e9f1ab7e177a82f40068dcec8b5");
    uint32_t nTime = 1558503686;
    uint32_t nBits = std::stoi("1c103ead",nullptr,16);
    uint256 nonse = uint256S("429f6dcd000000000000000000000000000000000000000000000000ec160018");
    uint256 stateroot = uint256S("3434cd9fba2e5e9a3a494575317fb21f17012ca41087f771dd38007c6d9e81b4");
    uint256 utxiroot = uint256S("fe8923626249d66ad50ff0d7b07c526d1e3a89abe9ac89ad78299dc651e64d58");

    CHashWriter ss(SER_GETHASH, PROTOCOL_VERSION);
    write(ss, nVersion);
    write(ss, prevhash);
    write(ss, merkleroot);
    write(ss, nTime);
    write(ss, nBits);
    write(ss, nonse);
    write(ss, stateroot);
    write(ss, utxiroot);

    uint256 hs = ss.GetHash();
    printf("expect: f961a7a6399ea382a9c88f7f956d7446f04d4e4be4e0d6afdb117d0968654521\nresult: %s\n", hs.ToString().c_str());

    return;
}
