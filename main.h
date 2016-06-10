#define NAME_OF_A_APPL "ChangedCode"
#define ENCODE 'e'
#define DECODE 'd'
#define WINDOW_SIZE "-w"
#define WINDOW_LEN "-l"
#define STARTING 0
#define NORMAL_OPERATION 1
#define LANGUAGE_CHANGING 2
#define OPERATION_CHANGING 1
#define TURNING_OFF 4
#define NUMBER_OF_LANGUAGES 10
#define ENGLISH_LANGUAGE 2
#define NUMBER_OF_SOUNDS 4
#define TURN_ON_SOUND 0
#define TURN_OFF_SOUND 1
#define ERROR_SOUND 2
#define CHANGE_SOUND 3

#define NUMBER_OF_IMAGES 8


//extern int mainHeatShrink(int argc, char **argv);
int loadDefaultLanguage( void );
void WriteTheDefaultLangToFile( int iLangIndexP );
void LanguageLoadMenu( const int iLangIndexP );
void EncodePreviousLangMenu( const int iLangIndexP );
void PlaySoundNow( const int soundId );
static void DispayImage( const int ImgIndexP );
static void EncodeDispayImage( const int ImgIndexP );
static int LanguageChangeProcess( const int LangIndexP );
static int OperationChangeProcess( const int OperIndexP );

const char DecodedImages[NUMBER_OF_IMAGES][6] =
{
    "1.bin",
    "2.bin",
    "3.bin",
    "4.bin",
    "5.bin",
    "6.bin",
    "7.bin",
    "8.bin"
};

const char OriginalImages[NUMBER_OF_IMAGES][6] =
{
    "1.bmp",
    "2.bmp",
    "3.bmp",
    "4.bmp",
    "5.bmp",
    "6.bmp",
    "7.bmp",
    "8.bmp"
};

const char DecodedSounds[NUMBER_OF_SOUNDS][9] =
{
    "TuOn.bin",
    "TOff.bin",
    "Erro.bin",
    "Chan.bin"
};

const char OriginalSounds[NUMBER_OF_SOUNDS][9] =
{
    "TuOn.wav",
    "TOff.wav",
    "Erro.wav",
    "Chan.wav"
};

const char languages[NUMBER_OF_LANGUAGES][8] =
{
    "bg.pak\0",
    "de.pak\0",
	"en.pak\0",
	"es.pak\0",
	"fr.pak\0",
	"it.pak\0",
	"kn.pak\0",
	"ru.pak\0",
	"ta.pak\0",
	"uk.pak\0"
};

const char OriginalLanguages[NUMBER_OF_LANGUAGES][9] =
{
    "Dbg.pak\0",
    "Dde.pak\0",
	"Den.pak\0",
	"Des.pak\0",
	"Dfr.pak\0",
	"Dit.pak\0",
	"Dkn.pak\0",
	"Dru.pak\0",
	"Dta.pak\0",
	"Duk.pak\0"
};
