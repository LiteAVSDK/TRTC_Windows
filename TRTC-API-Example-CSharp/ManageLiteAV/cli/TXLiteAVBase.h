#pragma once

using namespace System;

namespace ManageLiteAV {
    public interface class NetworkTimeCallback
    {
        void onUpdateNetworkTime(int errCode, String^ errMsg);
    };

    public ref class TXLiteAVBase
    {
    public:
        /// <summary>
        /// ��ȡ ITRTCCloud ��������
        /// </summary>
        /// <returns>���� ITRTCCloud ��������</returns>
        static TXLiteAVBase^ getInstance();

        /// <summary>
        /// ��ȡ SDK �汾��
        /// </summary>
        /// <returns>���� UTF-8 ����İ汾��</returns>
        static String^ getLiteAvSDKVersion();

        /// <summary>
        /// ���� liteav SDK ����Ļ�����
        /// </summary>
        /// <param name="env_config">��Ҫ����Ļ�����SDK Ĭ�Ͻ���Ļ����ǣ�Ĭ����ʽ����</param>		
        /// <returns>0���ɹ�������������</returns>
        static int setGlobalEnv(String^ env_config);

        /// <summary>
        /// ���� NTP Уʱ����
        /// </summary>
        static int updateNetworkTime();

        /// <summary>
        /// ��ȡ NTP ʱ��������룩�������յ� onUpdateNetworkTime �ص���ʹ��
        /// </summary>
        /// <returns>NTP ʱ��������룩�������� 0��δ���� NTP Уʱ��Уʱʧ�ܣ�������Уʱ</returns>
        static Int64 getNetworkTimestamp();

        /// <summary>
        /// ���� NTP Уʱ�¼��ص���
        /// </summary>
        /// <param name="callback">NetworkTimeCallback�ص�ָ�롣</param>
        void setUpdateNetworkTimeCallback(NetworkTimeCallback^ callback);
    private:
        TXLiteAVBase();
        ~TXLiteAVBase();

        static TXLiteAVBase^ sInstance;
        static Object^ slocker = gcnew Object();

        delegate void UpdateNetworkTimeDelegate(int errCode, const char* errMsg);
        UpdateNetworkTimeDelegate ^ m_updateNetworkTimeDeleagate;
    
        void onUpdateNetworkTimeDeleagate(int errCode, const char* errMsg);

        NetworkTimeCallback ^ m_callback = nullptr;
    };
};