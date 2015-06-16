#ifndef _WHITE_BOARD_CONSOLE_
#define _WHITE_BOARD_CONSOLE_

#define KEY_DOWN 1
#define KEY_UP	 0

void ConsoleInit( const int nXSize, const int nYSize );
void ScreenClear();
void ScreenPrint( int nX, int nY, char *str );
void ScreenFlipping();
void SetColor(int color, int bgcolor);
void ConsoleRelease();

int GetKeyDownState( const int nkeyValue);
void PlayKeySoundEffect( const char* strFileName );
void PlaySoundEffect( const char* strFileName );

void AddTimer( void (*pTimerCallBackFunc)(void), const int nTime );
void DeleteTimer();

#endif /*_WHITE_BOARD_CONSOLE_*/