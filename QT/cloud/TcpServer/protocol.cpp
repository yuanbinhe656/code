#include "protocol.h"
PDU *mkPDU(uint uiMsglen)
{
    uint uiPUDLen = sizeof(PDU) + uiMsglen;
    PDU *pdu = (PDU*)malloc(sizeof(uiPUDLen));
    if( nullptr == pdu)
    {
        exit(EXIT_FAILURE);
    }
    memset(pdu, 0,uiPUDLen);
    pdu->uiPDULen = uiPUDLen;
    pdu->uiMsgLen = uiMsglen;
    return pdu;
}
