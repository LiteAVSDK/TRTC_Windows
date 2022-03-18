#pragma once
// C++ Header
#include "include/Vod/ITXVodPlayer.h"	

// C++/CLI Header
#include "cli/TRTC/TRTCCloudDef.h"

// ITXVodPlayerDataCallbackImpl
typedef int (CALLBACK* PFN_VODVIDEOFRAME)(TRTCVideoFrame& frame);
typedef int (CALLBACK* PFN_VODAUDIOFRAME)(TRTCAudioFrame& frame);
// end ITXVodPlayerDataCallbackImpl

// ITXVodPlayerEventCallbackImpl
typedef void (CALLBACK* PFN_VODPLAYERSTARTED)(uint64_t msLength);
typedef void (CALLBACK* PFN_VODPLAYERPROCESS)(uint64_t msPos);
typedef void (CALLBACK* PFN_VODPLAYERPAUSED)();
typedef void (CALLBACK* PFN_VODPLAYERRESUMED)();
typedef void (CALLBACK* PFN_VODPLAYERSTOPED)(int reason);
typedef void (CALLBACK* PFN_VODPLAYERERROR)(int error);
// end ITXVodPlayerEventCallbackImpl

class ITXVodPlayerDataCallbackImpl
	: public ITXVodPlayerDataCallback
{
public:
	ITXVodPlayerDataCallbackImpl();
	virtual ~ITXVodPlayerDataCallbackImpl();
	void setVodVideoFrame(PFN_VODVIDEOFRAME pointer);

	void setVodAudioFrame(PFN_VODAUDIOFRAME pointer);

	/**
	 * Vod��Ƶ֡�ص�
	 * param frame ��Ƶ֡����
	 */
	virtual int onVodVideoFrame(TRTCVideoFrame& frame);

	/**
	 * Vod��Ƶ֡�ص�
	 * param frame ��Ƶ֡����
	 */
	virtual int onVodAudioFrame(TRTCAudioFrame& frame);
private:
	PFN_VODVIDEOFRAME m_vodVideoFrame;
	PFN_VODAUDIOFRAME m_vodAudioFrame;
};


///�����¼��ص�
class ITXVodPlayerEventCallbackImpl : public ITXVodPlayerEventCallback
{
public:
	ITXVodPlayerEventCallbackImpl();
	virtual ~ITXVodPlayerEventCallbackImpl();

	void setVodPlayerStarted(PFN_VODPLAYERSTARTED pointer);

	void setVodPlayerProcess(PFN_VODPLAYERPROCESS pointer);

	void setVodPlayerPaused(PFN_VODPLAYERPAUSED pointer);

	void setVodPlayerResumed(PFN_VODPLAYERRESUMED pointer);

	void setVodPlayerStoped(PFN_VODPLAYERSTOPED pointer);

	void setVodPlayerError(PFN_VODPLAYERERROR pointer);

	virtual void onVodPlayerStarted(uint64_t msLength);

	/**
	* ����ý���ļ����Ž��ȸı�ʱ��SDK��ͨ���˻ص�֪ͨ
	*
	* param msPos ��ý���ļ����Ž��ȣ���λ����
	*/
	virtual void onVodPlayerProgress(uint64_t msPos);

	/**
	* ����ý���ļ�������ͣʱ��SDK��ͨ���˻ص�֪ͨ
	*/
	virtual void onVodPlayerPaused();

	/**
	* ����ý���ļ����Żָ�ʱ��SDK��ͨ���˻ص�֪ͨ
	*/
	virtual void onVodPlayerResumed();

	/**
	* ����ý���ļ�����ֹͣʱ��SDK��ͨ���˻ص�֪ͨ
	*
	* param reason ֹͣԭ��0��ʾ�û�����ֹͣ��1��ʾ�ļ������꣬2��ʾ��Ƶ����
	*/
	virtual void onVodPlayerStoped(int reason);

	/**
	* ����ý���ļ����ų���ʱ��SDK��ͨ���˻ص�֪ͨ
	*
	* param error ������
	*/
	virtual void onVodPlayerError(int error);
private:

	PFN_VODPLAYERSTARTED m_vodPlayerStarted;
	PFN_VODPLAYERPROCESS m_vodPlayerProgress;
	PFN_VODPLAYERPAUSED  m_vodPlayerPaused;
	PFN_VODPLAYERRESUMED m_vodPlayerResumed;
	PFN_VODPLAYERSTOPED  m_vodPlayerStoped;
	PFN_VODPLAYERERROR   m_vodPlayerError;
};