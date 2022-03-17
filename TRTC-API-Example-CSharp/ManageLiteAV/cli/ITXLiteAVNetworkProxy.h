// ITXLiteAVNetworkProxy.h

#pragma once

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;

// C++ Header
#include "include/ITXLiteAVNetworkProxy.h"

namespace ManageLiteAV
{
    public ref class ITXNetworkProxy
    {
    public:

        ~ITXNetworkProxy();

        static ITXNetworkProxy^ createTXNetworkProxy();

        static void destroyTXNetworkProxy(ITXNetworkProxy^ network_proxy);

        /// <summary>
        /// TRTCCloud ��������
        /// <para>socks5 ����ģʽ������ socks5 tcp/udp ��������� ip �� port</para>
        /// <para>���ô˽ӿں�������������������ʹ�ý�����������������Ƶ������Զ������Ƶ���˷��ȹ���</para>
        /// <para>ϸ����ο�TRTC ������<http://trtc-1252463788.file.myqcloud.com/proxy/proxy_server_deploy.zip></para>
        /// <para>���óɹ�����0����������ʧ�ܻ���ip�Ƿ�����-1</para>
        /// <para>���ӿ����������ƣ�</para>
        /// <para>- �����꣬�� destroy TRTCCloud ���»�ȡ TRTC ����</para>
        /// <para>- �����ֻ���� TRTCCloud����ֻ��Ҫ����Sock5����ӿڡ�</para>
        /// </summary>
        /// <param name="host">����������� ip ��ַ����������ַ</param>
        /// <param name="port">����������Ķ˿�</param>
        /// <param name="username">����������û���</param>
        /// <param name="password">�������������</param>
        int setSocks5Proxy(String^ host, UInt16 port, String^ username, String^ password);

    private:
        ::ITXNetworkProxy* m_network_proxy = nullptr;
        !ITXNetworkProxy();
        ITXNetworkProxy();

        static ITXNetworkProxy^ sInstance;
        static Object^ slocker = gcnew Object();
    };
}