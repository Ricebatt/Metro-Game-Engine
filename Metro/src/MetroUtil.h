#pragma once

#ifdef METRO_WINDOWS
	#ifdef METRO_LIB
		#define METRO_API __declspec(dllexport)
	#else
		#define METRO_API __declspec(dllimport)
	#endif
#else
	#define METRO_API
#endif


#define METRO_GAME_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}

#if METRO_DEBUG==2
	#define METRO_LOG(x) std::clog<<"Log: "<<x<<std::endl;
	#define METRO_ERROR(x) std::cerr<<"Error: "<<x<<std::endl;
#elif METRO_DEBUG==1
	#define METRO_LOG(x) 
	#define METRO_ERROR(x) std::cerr<<"Error: "<<x<<std::endl;
#else
	#define METRO_LOG(x)
	#define METRO_ERROR(x)
#endif