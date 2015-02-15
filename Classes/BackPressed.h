#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

namespace cocos2d
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public interface class ICallback
	{
	public:
		 virtual void CallFunc(Platform::String ^mess);
	};

	public ref class PlatformCenter sealed
	{
	public:
		PlatformCenter();
		static void setCallback(ICallback ^callback);
		static void callFunc(Platform::String^ s);
	};	
};

class BackPressed
{
	public:
		BackPressed()
		{
			myptr = this;
		}

		virtual void backPressCalled()
		{

		}

		static BackPressed *getInstance()
		{
			return myptr;
		}

		static BackPressed *myptr;

};

class HelloWorld : public cocos2d::Layer, public BackPressed
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	void CallCSharp();
	void backPressCalled();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

