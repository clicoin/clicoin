// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Clicoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"

#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

#include "chainparamsseeds.h"

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 0x1e00ffff << CScriptNum(9999) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));////////////
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "SpaceX to fly two tourists around Moon in 2018";////////////
    const CScript genesisOutputScript = CScript() << ParseHex("0404ce9b5e05e4c53dd34742d7c31ba0a134974eda77f9284499e572b2ba702722315a34538690bcbd9d147729542776a731d0923ad3ce9bac53ab9579bc147146") << OP_CHECKSIG;////////////
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 210000;
        consensus.nMajorityEnforceBlockUpgrade = 1;////////////
        consensus.nMajorityRejectBlockOutdated = 2;////////////
        consensus.nMajorityWindow = 2;////////////
        consensus.BIP34Height = 0;////////////
        consensus.BIP34Hash = uint256S("0x000000fb5bdc8e654374980951a0d9e26eff78e301d878c7b6ad7737d9628c54");////////////
        consensus.powLimit = uint256S("000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");////////////
        consensus.nPowTargetTimespan = 3650*24*60*60; //////////// ten year
        consensus.nPowTargetSpacing = 1 * 60;////////////
        consensus.fPowAllowMinDifficultyBlocks = true;////////////
        consensus.fPowNoRetargeting = false;
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xb2;////////////
        pchMessageStart[1] = 0x3a;////////////
        pchMessageStart[2] = 0xaf;////////////
        pchMessageStart[3] = 0x25;////////////
        vAlertPubKey = ParseHex("04c0ab24a1e8c920820c322699e58064cf99bc41194721bd6d57929b0a0771fcbebdbb2a06430a418dce3c4f3f010c9331c4ebdc570fa6c6e94ce2af77356f4698");////////////
        nDefaultPort = 5227;////////////
        nMaxTipAge = 24 * 60 * 60;
        nPruneAfterHeight = 100000;

        genesis = CreateGenesisBlock(1488269311, 15190908, 0x1e00ffff, 1, 1 * COIN);///////////
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x000000fb5bdc8e654374980951a0d9e26eff78e301d878c7b6ad7737d9628c54"));////////////
        assert(genesis.hashMerkleRoot == uint256S("0xeac8a84f017e7888b65c35ec72d118ba72193b2703425abdc01d61b94fc5971b"));////////////

        vSeeds.push_back(CDNSSeedData("seed.clicoin.org", "dnsseed.clicoin.org"));////////////
	    //vSeeds.push_back(CDNSSeedData("seeda.clicoin.org", "dnsseeda.clicoin.org"));//////
        //vSeeds.push_back(CDNSSeedData("seedb.clicoin.org", "dnsseedb.clicoin.org"));//////
        //vSeeds.push_back(CDNSSeedData("seedc.clicoin.org", "dnsseedc.clicoin.org"));//////
        //vSeeds.push_back(CDNSSeedData("clicoinstats.com", "seed.clicoinstats.com")); // Christian Decker
        //vSeeds.push_back(CDNSSeedData("xf2.org", "bitseed.xf2.org")); // Jeff Garzik
        //vSeeds.push_back(CDNSSeedData("clicoin.jonasschnelli.ch", "seed.clicoin.jonasschnelli.ch")); // Jonas Schnelli


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,3);////////////
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,6);////////////
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,122);////////////
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x88)(0xB2)(0x1E)(0x04).convert_to_container<std::vector<unsigned char> >();////////////
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x88)(0xAD)(0xE4)(0x04).convert_to_container<std::vector<unsigned char> >();////////////

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = false;  ////////////true/false///////////
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            (0, uint256S("0x000000fb5bdc8e654374980951a0d9e26eff78e301d878c7b6ad7737d9628c54")),////////////
            1488269311, // * UNIX timestamp of last checkpoint block////////////
            0,   // * total number of transactions between genesis and last checkpoint////////////
                        //   (the tx=... number in the SetBestChain debug.log lines)
            0     // * estimated number of transactions per day after checkpoint////////////
        };
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 210000;
        consensus.nMajorityEnforceBlockUpgrade = 1;////////////
        consensus.nMajorityRejectBlockOutdated = 2;////////////
        consensus.nMajorityWindow = 2;////////////
        consensus.BIP34Height = 0;////////////
        consensus.BIP34Hash = uint256S("0x0000003dfc377701fbde66710d6137b35a636819092bc091ffcab66e3b2f2bf6");////////////
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");////////////
        consensus.nPowTargetTimespan = 3650*24*60*60; //////////// ten year
        consensus.nPowTargetSpacing = 1 * 60;////////////
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        pchMessageStart[0] = 0x05;////////////
        pchMessageStart[1] = 0x1c;////////////
        pchMessageStart[2] = 0x20;////////////
        pchMessageStart[3] = 0x1e;////////////
        vAlertPubKey = ParseHex("0462d401853f94fd81766c24025c54c8f5848e72c8ead6975277d55c35da92d9f680b369b1e847c581fd224d40e21567bd0d2bd207176e647eecb07b6397060296");////////////
        nDefaultPort = 15227;////////////
        nMaxTipAge = 0x7fffffff;////////////
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1488269365, 453563, 0x1e00ffff, 1, 1 * COIN);////////////
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x0000003dfc377701fbde66710d6137b35a636819092bc091ffcab66e3b2f2bf6"));////////////
        assert(genesis.hashMerkleRoot == uint256S("0xeac8a84f017e7888b65c35ec72d118ba72193b2703425abdc01d61b94fc5971b"));////////////

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testnet.clicoin.org", "testnet-seed.clicoin.org"));////////////
        vSeeds.push_back(CDNSSeedData("testneta.clicoin.org", "testnet-seeda.clicoin.org"));////////////

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,101);////////////
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,105);////////////
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,233);////////////
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x35)(0x04)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();////////////
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x35)(0x04)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();////////////

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = false;  ////////////true/false///////////
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            ( 546, uint256S("0000003dfc377701fbde66710d6137b35a636819092bc091ffcab66e3b2f2bf6")),////////////
            1488269365,// * UNIX timestamp of last checkpoint block////////////
            0,// * total number of transactions between genesis and last checkpoint////////////
                  //   (the tx=... number in the SetBestChain debug.log lines)
            0     // * estimated number of transactions per day after checkpoint////////////
        };

    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.nMajorityEnforceBlockUpgrade = 1;////////////
        consensus.nMajorityRejectBlockOutdated = 2;////////////
        consensus.nMajorityWindow = 2;////////////
        consensus.BIP34Height = -1; // BIP34 has not necessarily activated on regtest
        consensus.BIP34Hash = uint256();
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3650*24*60*60; //////////// ten year
        consensus.nPowTargetSpacing = 1 * 60;////////////
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;

        pchMessageStart[0] = 0xfc;////////////
        pchMessageStart[1] = 0xbe;////////////
        pchMessageStart[2] = 0xb6;////////////
        pchMessageStart[3] = 0xdc;////////////
        nMaxTipAge = 24 * 60 * 60;
        nDefaultPort = 15338;////////////
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1488288161, 0, 0x207fffff, 1, 1 * COIN);////////////
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x734a45346f7b5996434cedc3daa7df9b901168c202dfa5a1b41ab0fe77a77f81"));////////////
        assert(genesis.hashMerkleRoot == uint256S("0xeac8a84f017e7888b65c35ec72d118ba72193b2703425abdc01d61b94fc5971b"));////////////

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (CCheckpointData){
            boost::assign::map_list_of
            ( 0, uint256S("734a45346f7b5996434cedc3daa7df9b901168c202dfa5a1b41ab0fe77a77f81")),////////////
            1488269365,////////////
            0,////////////
            0
        };
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,101);////////////
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,105);////////////
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,233);////////////
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x35)(0x04)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();////////////
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x35)(0x04)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();////////////
    }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
            return mainParams;
    else if (chain == CBaseChainParams::TESTNET)
            return testNetParams;
    else if (chain == CBaseChainParams::REGTEST)
            return regTestParams;
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
