/*
* aqua-sim-phy.cc
*
*  Created on: Nov 5, 2015
*      Author: robert
*/

#include "aqua-sim-phy.h"

#include "ns3/nstime.h"

namespace ns3
{

NS_OBJECT_ENSURE_REGISTERED (AquaSimPhy);

TypeId
AquaSimPhy::GetTypeId ()
{
  static TypeId tid = TypeId("ns3::AquaSimPhy")
    .SetParent<Object>
  ;
  return tid;
}

/**
 * calculate transmission time of a packet of size pktsize
 * we consider the preamble
 */
Time
AquaSimPhy::CalcTxTime (int pktSize, Ptr<std::string> modName)
{
  return Time::FromDouble (Modulation (modName)->TxTime (pktSize), Time::S)
      + Time::FromInteger (Preamble (), Time::S);
}

int
AquaSimPhy::CalcPktSize (double txTime, Ptr<std::string> modName)
{
  return Modulation (modName)->PktSize (txTime - Preamble ());
}

} //ns3 namespace
