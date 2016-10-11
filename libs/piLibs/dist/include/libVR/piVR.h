#pragma once

#include <functional>

namespace piLibs {

class piVRHMD
{
public:
    typedef struct
    {
        bool  mStatePressed;
        bool  mEventDown;
        bool  mEventUp;
        bool  mEventDoubleClick;
        bool  mEventSingleClick;

        int   mInternal1;
        double mInternal2;
    }Button;

    typedef struct
    {
        bool  mEnabled;
        float mLocation[16];
        float mVelocity[3];
        bool  mIndexTriggerPressed;
        float mIndexTrigger; // Left and right finger trigger values, in the range 0.0 to 1.0f.
        float mHandTrigger; // Left and right hand trigger values , in the range 0.0 to 1.0f.
        float mThumbstick[2]; // Horizontal and vertical thumbstick axis values , in the range -1.0f to 1.0f.

        Button mUpButton;
        Button mDownButton;
		Button mJoystickButton;

        //void (*Vibrate)(int id, float frequency, float amplitude, float duration);
        std::function<void(int id, float frequency, float amplitude, float duration)> Vibrate;

    }Controller;

    typedef struct
    {
        float mCamera[16];
        float mProjection[4];
        Controller mController[2];
    }HeadInfo;

    typedef struct
    {
        int   mVP[4];
        float mProjection[4];
        float mCamera[16];
    }EyeInfo;

    typedef struct
    {
        int                 mNum;
        unsigned int        mTexID[64];
    }TextureChain;

    typedef struct
    {
        // init
        int          mXres;
        int          mYres;
        int          mVRXres;
        int          mVRYres;
        TextureChain mTexture[2];
        unsigned int mMirrorTexID;

        // per frame
        HeadInfo     mHead;
        EyeInfo      mEye[2];
    }HmdInfo;
    
    HmdInfo mInfo;

	typedef struct
	{
		bool mShouldQuit;
		bool mIsVisible;
	} HmdState;

	HmdState mState;

    virtual bool AttachToWindow( bool createMirrorTexture, int mirrorTextureSizeX, int mirrorTextureSizeY) = 0;
    virtual void BeginFrame( int *texIndexLeft, int *texIndexRight, bool *outNeedsMipMapping) = 0;
    virtual void EndFrame( void ) = 0;
	virtual void GetHmdState(HmdState * state) = 0;

    //virtual void Haptic(int id, float frequency, float amplitude, float duration) = 0;

};

class piVR
{
public:
    typedef enum
    {
        Oculus_Rift = 0,
        HTC_Vive = 1
    }HwType;

	

    static piVR *Create(HwType hw);
    static void  Destroy(piVR * me);

    virtual piVRHMD  *CreateHmd(int deviceID, float pixelDensity) = 0;
    virtual void      DestroyHmd(piVRHMD * me) = 0;
};



} // namespace piLibs
