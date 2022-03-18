#pragma once

// C++ Header
#include "include/TRTC/ITRTCCloud.h"
#include "include/Vod/ITXVodPlayer.h"

// C++/CLI Header
#include "cli/TRTC/TRTCCloudDef.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;

class ITXVodPlayerDataCallbackImpl;
class ITXVodPlayerEventCallbackImpl;


namespace ManageLiteAV
{

    public interface class  ITXVodPlayerDataCallback
    {
    public:
        /// <summary>
        /// Vod��Ƶ֡�ص�
        /// </summary>
        /// <param name="frame"></param>
        /// <returns>��Ƶ֡����</returns>
        Int32 onVodVideoFrame(TRTCVideoFrame^% frame);

        /// <summary>
        /// Vod��Ƶ֡�ص�
        /// </summary>
        /// <param name="frame"></param>
        /// <returns>��Ƶ֡����</returns>
        Int32 onVodAudioFrame(TRTCAudioFrame^% frame);
    };

    public interface class ITXVodPlayerEventCallback
    {
    public:
        /// <summary>
        /// ����ý���ļ����ſ�ʼʱ��SDK��ͨ���˻ص�֪ͨ
        /// </summary>
        /// <param name="msLength">��ý���ļ��ܳ��ȣ���λ����</param>
        void onVodPlayerStarted(UInt64 msLength);

        /// <summary>
        /// ����ý���ļ����Ž��ȸı�ʱ��SDK��ͨ���˻ص�֪ͨ
        /// </summary>
        /// <param name="msPos">��ý���ļ����Ž��ȣ���λ����</param>
        void onVodPlayerProgress(UInt64 msPos);

        /// <summary>
        /// ����ý���ļ�������ͣʱ��SDK��ͨ���˻ص�֪ͨ
        /// </summary>
        void onVodPlayerPaused();

        /// <summary>
        /// ����ý���ļ����Żָ�ʱ��SDK��ͨ���˻ص�֪ͨ
        /// </summary>
        void onVodPlayerResumed();

        /// <summary>
        /// ����ý���ļ�����ֹͣʱ��SDK��ͨ���˻ص�֪ͨ
        /// </summary>
        /// <param name="reason">ֹͣԭ��0��ʾ�û�����ֹͣ��1��ʾ�ļ������꣬2��ʾ��Ƶ����</param>
        void onVodPlayerStoped(Int32 reason);

        /// <summary>
        /// ����ý���ļ����ų���ʱ��SDK��ͨ���˻ص�֪ͨ
        /// </summary>
        /// <param name="error">������</param>
        void onVodPlayerError(Int32 error);
    };

    /// @defgroup VodPlayerController_csharp VodPlayerController
    /// ��Ѷ��Vod����������Ҫ�ӿ���
    /// @{
    /// <summary>
    /// Module:   VodPlayerController @ TXLiteAVSDK
    ///
    /// <para>Function: ��Ѷ��Vod����������Ҫ�ӿ���</para>
    /// </summary>
    /// <example>
    /// ����/ʹ��/���� VodPlayerController �����ʾ�����룺
    /// <code>
    /// VodPlayerController playerController = VodPlayerController.getVodPlayerControllerInstance();
    /// </code>
    ///	�����˳����ߺ����������̲���Ҫʹ�� VodPlayerController ����ʱ���ͷŵ������� VodPlayerController
    /// <code>
    /// VodPlayerController.destroyVodPlayerControllerInstance();
    /// playerController = null;
    /// </code>
    /// </example>
    public ref class ITXVodPlayer
    {
    public:
        /// <summary>
        /// ����һ��������
        /// </summary>
        /// <param name="mediaFile">����Ƶ�ļ���</param>
        /// <param name="repeat">�Ƿ�ѭ��</param>
        static ITXVodPlayer^ createTXVodPlayer(String^ mediaFile, bool repeat);

        /// <summary>
        /// ����һ��������
        /// </summary>
        static void destroyTXVodPlayer(ITXVodPlayer^);

        /// <summary>
        /// �� TRTC 
        /// </summary>
        /// <para>���ڸ������ͣ��󶨺���Ƶ������TRTC�ӹ�</para>
        void attachTRTC();

        /// <summary>
        /// ���TRTC
        /// </summary>
        void detachTRTC();

        /// <summary>
        /// ��ʼ��TRTC������·��Ƶ��
        /// </summary>
        void publishVideo();

        /// <summary>
        /// ��ʼ��TRTC������·��Ƶ��
        /// </summary>
        void publishAudio();

        /// <summary>
        /// ������TRTC������·��Ƶ��
        /// </summary>
        void unpublishVideo();

        /// <summary>
        /// ������TRTC������·��Ƶ��
        /// </summary>
        void unpublishAudio();

        /// <summary>
        /// ���ö�ý���¼��ص�
        /// </summary>
        /// <param name="callback">Ҫʹ�õĶ�ý���ļ����Żص�����ʵ��</param>
        void setEventCallback(ITXVodPlayerEventCallback^ callback);

        /// <summary>
        /// ���ö�ý���ļ����Żص�
        /// </summary>
        /// <param name="callback">Ҫʹ�õĶ�ý���ļ����Żص�����ʵ��</param>
        void setDataCallback(ITXVodPlayerDataCallback^ callback);

        /// <summary>
        /// ��ʼ��ý���ļ�����
        ///<para>֧�ֵ���Ƶ��ʽ������mp4��avi��mkv��wmv��m4v</para>
        ///<para>֧�ֵ���Ƶ��ʽ������mp3��wav��wma��aac</para>
        /// </summary>
        void start();

        /// <summary>
        /// ��ͣ��ý���ļ�����
        /// </summary>
        void pause();

        /// <summary>
        /// �ָ���ý���ļ�����
        /// </summary>
        void resume();

        /// <summary>
        /// ֹͣ��ý���ļ�����
        /// </summary>
        void stop();

        /// <summary>
        /// ���ö�ý���ļ����Ž���
        /// </summary>
        /// <param name="msPos">���Ž��ȣ���λ���룩</param>
        void seek(UInt64 msPos);

        /// <summary>
        /// ���ö�ý���ļ������ٶ�
        /// </summary>
        /// <param name="rate">�����ٶȣ�0.5-2.0��</param>
        void setRate(float rate);

        /// <summary>
        /// ���ò�����Ⱦ���
        /// </summary>
        /// <param name="hwnd">���ھ��</param>
        void setView(IntPtr hwnd);

        /// <summary>
        /// ��ȡ��ý���ļ���ʱ��
        /// </summary>
        Int32 getDuration();

        /// <summary>
        /// ��ȡ��Ƶ���
        /// </summary>
        Int32 getWidth();

        /// <summary>
        /// ��ȡ��Ƶ�߶�
        /// </summary>
        Int32 getHeight();

        /// <summary>
        /// ���ö�ý������
        /// </summary>
        /// <param name="volume">������С��100Ϊԭʼ��������Χ�ǣ�[0 ~ 150]��Ĭ��ֵΪ100</param>
        void setVolume(Int32 volume);

        /// <summary>
        /// ����/ȡ������
        /// </summary>
        /// <param name="mute">true��������false��ȡ������</param>
        void mute(bool mute);

        /// <summary>
        /// ���ñ���ͼ���˳ʱ����ת�Ƕ�
        /// <para>param rotation ֧�� TRTCVideoRotation90 �� TRTCVideoRotation180 �Լ� TRTCVideoRotation270</para>
        /// <para>��ת�Ƕȣ�Ĭ��ֵ��TRTCVideoRotation0</para>
        /// </summary>
        /// <param name="rotation">��Ƶ������ת����</param>
        void setRenderRotation(TRTCVideoRotation rotation);

        /// <summary>
        /// ���ñ���ͼ������ģʽ
        /// <para>��䣨������ܻᱻ����ü�������Ӧ��������ܻ��кڱߣ���Ĭ��ֵ��TRTCVideoFillMode_Fit</para>
        /// </summary>
        /// <param name="rotation">��Ƶ�������ģʽ</param>
        void setFillMode(TRTCVideoFillMode mode);

        /// <summary>
        /// ���ñ���ͼ��ľ���ģʽ
        /// </summary>
        /// <param name="mirror">����ģʽ��Ĭ��ֵ��false���Ǿ���ģʽ��</param>
        void setMirror(bool mirror);

    private:
        delegate int  VodVideoFrameDelegate(::TRTCVideoFrame& frame);
        delegate int  VodAudioFrameDelegate(::TRTCAudioFrame& frame);
        delegate void VodPlayerStartedDelegate(uint64_t msLength);
        delegate void VodPlayerProgressDelegate(uint64_t msPos);
        delegate void VodPlayerPausedDelegate();
        delegate void VodPlayerResumedDelegate();
        delegate void VodPlayerStopedDelegate(int reason);
        delegate void VodPlayerErrorDelegate(int error);


        int onVodVideoFrame(::TRTCVideoFrame& frame);
        int onVodAudioFrame(::TRTCAudioFrame& frame);
        void onVodPlayerStarted(uint64_t msLength);
        void onVodPlayerProgress(uint64_t msPos);
        void onVodPlayerPaused();
        void onVodPlayerResumed();
        void onVodPlayerStoped(int reason);
        void onVodPlayerError(int error);
    private:
        ITXVodPlayer(String^ mediaFile, bool repeat);
        ~ITXVodPlayer();

        ::ITXVodPlayer* m_player;
        
        Object ^ m_cb_locker_event;
        Object ^ m_cb_locker_data;

        ITXVodPlayerDataCallbackImpl* m_vodPlayerDataCallbackImpl;
        ITXVodPlayerEventCallbackImpl* m_vodPlayerEventCallbackImpl;

        ITXVodPlayerEventCallback^ m_vodPlayerEventCallback;
        ITXVodPlayerDataCallback^ m_vodPlayerDataCallback;

        //  VodPlayerDataCallback
        VodVideoFrameDelegate^ m_vodVideoFrameDeleate;
        VodAudioFrameDelegate^ m_vodAudioFrameDeleate;
        //  VodPlayerEventCallback
        VodPlayerStartedDelegate^ m_vodPlayerStartedDelegate;
        VodPlayerProgressDelegate^ m_vodPlayerProcessDelegate;
        VodPlayerPausedDelegate^ m_vodPlayerPausedDelegate;
        VodPlayerResumedDelegate^ m_vodPlayerResumedDelegate;
        VodPlayerStopedDelegate^ m_vodPlayerStopedDelegate;
        VodPlayerErrorDelegate^ m_vodPlayerErrorDelegate;
    };
}
