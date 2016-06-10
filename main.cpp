#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
extern "C"
{
    #include "heatshrink.h"
}
//#include "heatshrink.h"
#include <time.h>
#include "main.h"




//============================================================================
//Name        : loadDefaultLanguage
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to read the latest language selection from file.
//============================================================================
int loadDefaultLanguage( void )
{
	FILE * fp = NULL;
	int langIndexL = 0;


	if( (fp = fopen("defaultLang.bin","rb")) == NULL )
	{
		printf("\nError opening file..");
		//Set the default language
		langIndexL = 0;
		//strcpy( pchFileNameP,"en.pak");
		//Set end of string symbol
		fclose(fp);
	}
	else
	{
		if( fread( &langIndexL,sizeof(int),1,fp) != 1 )
		{
			printf("\nError reading lang..");
			//Set the default language
			langIndexL = 0;
			//Set end of string symbol
			fclose(fp);
		}
	}


	//pchFileNameP[6]='\0';
	fclose(fp);
	return langIndexL;
}

//============================================================================
//Name        : WriteTheDefaultLangToFile
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to store the latest language selection in file.
//============================================================================
void WriteTheDefaultLangToFile( int iLangIndexP )
{
    FILE * fp = NULL;
    if( (fp = fopen("defaultLang.bin","wb")) == NULL )
	{
        printf("\nError opening file..");
        fclose(fp);
    }
    else
    {
        if( fwrite( &iLangIndexP,sizeof(int),1,fp) != 1 )
        {
            printf("\nError writing lang..");
            fclose(fp);
        }
    }

    fclose(fp);
    //Encode the file
    EncodePreviousLangMenu(iLangIndexP);

}

//============================================================================
//Name        : LanguageLoadMenu
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to decode the current language selection
//============================================================================
void LanguageLoadMenu( const int iLangIndexP )
{
    clock_t start = clock();
	//Save the output file to original lang file...
	(void)mainHeatShrink('d', languages[iLangIndexP], OriginalLanguages[iLangIndexP], 0, 0);
	 remove(languages[iLangIndexP]);
    clock_t end = clock();

    float seconds = (float)(end - start) ;
    //seconds = seconds*1000;
    printf("\nThe decoding elapsed time is %f ms", seconds);
	//(void)mainHeatShrink(4,choiceDecode);
}

//============================================================================
//Name        : EncodePreviousLangMenu
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to encode the previous language selection
//============================================================================
void EncodePreviousLangMenu( const int iLangIndexP )
{
    clock_t start = clock();
	//Save the output file to original lang file...
	(void)mainHeatShrink('e', OriginalLanguages[iLangIndexP], languages[iLangIndexP], 0, 0);
	remove(OriginalLanguages[iLangIndexP]);
    clock_t end = clock();

    float seconds = (float)(end - start) ;
    //seconds = seconds*1000;
    printf("\nThe encoding elapsed time is %f ms", seconds);
	//(void)mainHeatShrink(4,choiceDecode);
}

//============================================================================
//Name        : PlaySound
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to encode and play the desired sound.
//============================================================================
void PlaySound( const int soundId )
{
    clock_t start = clock();
	//Save the output file to original lang file...
	(void)mainHeatShrink('d', DecodedSounds[soundId], OriginalSounds[soundId], 0, 0);


    //remove(OriginalSounds[soundId]);
    clock_t end = clock();

    float seconds = (float)(end - start) ;
    //seconds = seconds*1000;
    printf("\nThe decoding of sound elapsed time is %f ms", seconds);
    system(OriginalSounds[soundId]);
    //Play the sound...
    Sleep(200);
    remove(OriginalSounds[soundId]);
	//(void)mainHeatShrink(4,choiceDecode);

}

//============================================================================
//Name        : DispayImage
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to decode and display the current
//              chosen program image.
//============================================================================
static void DispayImage( const int ImgIndexP )
{
    clock_t start = clock();
	//Save the output file to original lang file...
	(void)mainHeatShrink('d', DecodedImages[ImgIndexP], OriginalImages[ImgIndexP], 0, 0);
    remove(DecodedImages[ImgIndexP]);

    clock_t end = clock();

    float seconds = (float)(end - start) ;
    //seconds = seconds*1000;
    printf("\nThe decoding image elapsed time is %f ms", seconds);

    //Display the image...
    system(OriginalImages[ImgIndexP]);
}

//============================================================================
//Name        : EncodeDispayImage
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to encode back the unused image.
//============================================================================
static void EncodeDispayImage( const int ImgIndexP )
{
    clock_t start = clock();
	//Save the output file to original lang file...
	(void)mainHeatShrink('e', OriginalImages[ImgIndexP], DecodedImages[ImgIndexP], 0, 0);
	remove(OriginalImages[ImgIndexP]);
    clock_t end = clock();

    float seconds = (float)(end - start) ;
    //seconds = seconds*1000;
    printf("\nThe encoding image elapsed time is %f ms", seconds);
}

//============================================================================
//Name        : LanguageChangeProcess
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to handle language changing process
//============================================================================
static int LanguageChangeProcess( const int LangIndexP )
{
    int langChangeIndex = 0;

    printf("\n-----------------------------------------------");
    printf("\n-            0.BULGARIAN                      -");
    printf("\n-            1.GERMAN                         -");
    printf("\n-            2.ENGLISH                        -");
    printf("\n-            3.SPANISH                        -");
    printf("\n-            4.FRENCH                         -");
    printf("\n-            5.ITALIAN                        -");
    printf("\n-            6.GEORGIAN                       -");
    printf("\n-            7.RUSSIAN                        -");
    printf("\n-            8.TAMIL(INDIA)                   -");
    printf("\n-            9.UKRANIAN                       -");
    printf("\n-----------------------------------------------");
    printf("\nEnter your choice:  ");
    scanf("%d",&langChangeIndex);

    if( (langChangeIndex != LangIndexP) &&
        (langChangeIndex >= 0) &&
        (langChangeIndex <= 9) )
    {
        //Play change sound
        PlaySound(CHANGE_SOUND);
        //Decompress the new language..
        LanguageLoadMenu( langChangeIndex );
        //DO something to change the language
        EncodePreviousLangMenu( LangIndexP );
    }
    else
    {
        langChangeIndex = LangIndexP;
        PlaySound(ERROR_SOUND);
    }

    return langChangeIndex;
}

//============================================================================
//Name        : OperationChangeProcess
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The functions is used to handle operation changing process
//============================================================================
static int OperationChangeProcess( const int OperIndexP )
{
    int operChangeIndex = 0;
    printf("\n-----------------------------------------------");
    printf("\n-            0.DEFAULT OPERATION              -");
    printf("\n-            1.OPERATION 1                    -");
    printf("\n-            2.OPERATION 2                    -");
    printf("\n-            3.OPERATION 3                    -");
    printf("\n-            4.OPERATION 4                    -");
    printf("\n-            5.OPERATION 5                    -");
    printf("\n-            6.OPERATION 6                    -");
    printf("\n-            7.OPERATION 7                    -");
    printf("\n-----------------------------------------------");
    printf("\nEnter your choice:  ");
    scanf("%d",&operChangeIndex);
    if( (operChangeIndex != OperIndexP) &&
        (operChangeIndex >= 0) &&
        (operChangeIndex <= 7) )
    {
        PlaySound(CHANGE_SOUND);

        DispayImage( operChangeIndex );
        EncodeDispayImage( OperIndexP );
    }
    else
    {
        operChangeIndex = OperIndexP;
        PlaySound(ERROR_SOUND);
    }
    return operChangeIndex;
}


//============================================================================
//Name        : main
//Author      : P.Dimitrov
//Version     : 1.0
//Copyright   : All Rights Reserved
//Description : The main function of the system.
//============================================================================
int main()
{
    int SYSTEM_STATE = 0;
    int answerL = 0;
    int langIndexL = 0;
    int operIndexL = 0;

    langIndexL = loadDefaultLanguage( );
	printf("\nThe current language is %s ", languages[langIndexL]);
	for(;;)
    {
        if(SYSTEM_STATE == TURNING_OFF)
        {
            break;
        }
        else
        {
            switch( SYSTEM_STATE )
            {
                case STARTING :
                    PlaySound(TURN_ON_SOUND);
                    //Display the startup image..
                    DispayImage( operIndexL );
                    LanguageLoadMenu( langIndexL );
                    SYSTEM_STATE = NORMAL_OPERATION;
                    break;
                case NORMAL_OPERATION:
                    for(;;)
                    {
                        printf("\n-----------------------------------------------");
                        printf("\n-                  MENU                       -");
                        printf("\n-----------------------------------------------");
                        printf("\n-        1.Change the operation               -");
                        printf("\n-        2.Change the language                -");
                        printf("\n-        3.Turn off                           -");
                        printf("\n-----------------------------------------------");
                        printf("\n-----------------------------------------------");
                        printf("\nEnter your choice:  ");
                        scanf("%d",&answerL);
                        switch( answerL )
                        {
                            case OPERATION_CHANGING:
                                operIndexL = OperationChangeProcess( operIndexL );
                                break;
                            case LANGUAGE_CHANGING:
                                langIndexL = LanguageChangeProcess(langIndexL);
                                break;
                            default:
                                break;
                        }
                        if( answerL == 3)
                        {
                            SYSTEM_STATE = TURNING_OFF;
                            break;
                        }
                    }
                    break;
                default :
                    break;
            }
        }
    }
    //printf("\n The size of the stack is : %d bytes",sizeStack);
    WriteTheDefaultLangToFile(langIndexL);
    //Encode the image..
    EncodeDispayImage(operIndexL);
    //Play turnOff sound
    PlaySound(TURN_OFF_SOUND);
    return 0;
}
