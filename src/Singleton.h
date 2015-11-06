#ifndef __SINGLETON__
#define __SINGLETON__

template <class T> class Singleton
{

protected:
	static T* s_pInstance;
	Singleton() {};
   
public:
	static T* Instance()
		{
			if (!s_pInstance) 
				s_pInstance = new T();
			return s_pInstance;
		}
};
template <class T> T* Singleton<T>::s_pInstance = 0;

#endif
