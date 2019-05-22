#include "hash.h"
#include "primitives/block.h"

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

    CBlockHeader qtmblock;
    qtmblock.nVersion = 1;
    qtmblock.nTime = 1504695029;
    qtmblock.nNonce = 8026361;
    qtmblock.nBits = std::stoi("1f00ffff",nullptr,16);
    qtmblock.hashPrevBlock = uint256S("000075aef83cf2853580f8ae8ce6f8c3096cfa21d98334d6e3f95e5582ed986c");
    qtmblock.hashMerkleRoot = uint256S("ed34050eb5909ee535fcb07af292ea55f3d2f291187617b44d3282231405b96d");
    qtmblock.hashStateRoot = uint256S("9514771014c9ae803d8cea2731b2063e83de44802b40dce2d06acd02d0ff65e9");
    qtmblock.hashUTXORoot = uint256S("21b463e3b52f6201c0ad6c991be0485b6ef8c092e64583ffa655cc1b171fe856");
    printf("expect: 000075aef83cf2853580f8ae8ce6f8c3096cfa21d98334d6e3f95e5582ed986c\nresult: %s\n", qtmblock.GetHash().ToString().c_str());

    return;
}
