#pragma once
#include <Windows.h>
// C++ Header
#include "include/TRTC/ITXDeviceManager.h"

typedef void (CALLBACK* PFN_DEVICECHANGED)(const char* deviceId, TXMediaDeviceType type, TXMediaDeviceState state);

// ���й����޷�ֱ�������й��࣬�ʴ�ͨ������ָ�����Ž�
class TXDeviceObserverImpl :public ITXDeviceObserver
{
public:
    void setDeviceChanged(PFN_DEVICECHANGED pointer);

    void onDeviceChanged(const char* deviceId, TXMediaDeviceType type, TXMediaDeviceState state);
private:
    PFN_DEVICECHANGED m_deviceChanged;
};

