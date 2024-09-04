#include <iostream>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
void displayASCIIArt(int);
void introScreen();

string CLS = "\033[2J\033[1;1H";
string Red = "\033[31;1m";
string Green = "\033[32;1m";
string Yellow = "\033[33;1m";
string Blue = "\033[34;1m";
string Purple = "\033[35;1m";
string Cyan = "\033[36;1m";
string White = "\033[37;1m";
string Default = "\033[0m"; // default gray color & reset background to black

string WhiteOnRed = "\033[41;1m";
string WhiteOnGreen = "\033[42;1m";
string WhiteOnYellow = "\033[43;1m";
string WhiteOnBlue = "\033[44;1m";
string WhiteOnPurple = "\033[45;1m";
string WhiteOnCyan = "\033[46;1m";

int main()
{

    srand(time(NULL));
    mciSendString("open venom.wav alias MY_SND3", NULL, 0, NULL);
    mciSendString("play MY_SND3", NULL, 0, NULL);
    introScreen();

    string Phrases[5] = {"peter parker", "everywhere i go i see his face","great power","weird things happen to me all the time","i am batman"};
    string SecretPhrase = Phrases[rand()%5];

    string GuessPhrase = SecretPhrase;
    for (int i=0; i<GuessPhrase.size(); i++)
    {
        if(GuessPhrase[i] != ' ')
           GuessPhrase[i] = '.';
    }

    string Letter;
    string LettersRemaining = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    int Found, BadGuesses = 0;

    while (GuessPhrase != SecretPhrase && BadGuesses < 7)
    {
        cout << CLS;

        displayASCIIArt(BadGuesses);

        cout << WhiteOnGreen<<"HP: " << 70 - BadGuesses*10 << Default << endl;
        cout << Blue << "Letters Remaining: " << LettersRemaining << Default << endl;
        cout << Green << "Phrase to Guess: " << GuessPhrase << Default <<endl;
        cout << Red << "Enter a letter: " << Default;
        cin >> Letter;

        Found = LettersRemaining.find(Letter,0);
        if (Found !=-1)
            LettersRemaining.replace(Found,1," ");

        Found = SecretPhrase.find(Letter,0);
        if (Found == -1)
            BadGuesses++;
        else
            while (Found != -1)
        {
            GuessPhrase.replace(Found,1,Letter);
            Found = SecretPhrase.find(Letter, Found + 1);
        }
    } // end game loop
    cout << CLS;
    cout << Blue << "Letters Remaining: " << LettersRemaining << Default << endl;
    cout << Red << "Phrase to Guess:   " << GuessPhrase << Default << endl;
    if (GuessPhrase == SecretPhrase)
    {
        cout << Cyan <<"AS USUAL, WIN FOR YOUR FRIENDLY NEIBOURHOOD SPIDER-MAN! \n" << Default;
        cout<<"                      \\$     \n";
        cout<<"                        $)   \n";
        cout<<"                       ($`   \n";
        cout<<"                        $_   \n";
        cout<< Blue <<"                     ,--\" l_ \n"<<Default;
        cout<< Blue <<"                     ;|    )l    \n"<<Default;
        cout<< Blue <<"                     :    _/         \n"<<Default;
        cout<< Blue <<"                     ;   : l`.           \n"<<Default;
        cout<< Blue <<"            .-----._ L_..; :  \\.-""""""-.    \n"<<Default;
        cout<< Blue <<"         _.'       -\"   :   ; `-.        `.     \n"<<Default;
        cout<< Blue <<"       .'/              :   :   :   `.     \\    \n"<<Default;
        cout<< Blue <<"      /    ,--,   ,     ; _, ;  :     \\     \\   \n"<<Default;
        cout<< Blue <<"     /    /   :   :  , :-\"   :   \\     \\     ;  \n"<<Default;
        cout<< Blue <<"    /   _:   /    ;-:  ;     :    \\     ;   \\:  \n"<<Default;
        cout<< Blue <<"   / .-/ ; ;:\\   /: :  :     ;_.   \\    :    \\; \n"<<Default;
        cout<< Blue <<"  /.'   : / :(.-\" ; ;   ;   :/`.    \\    ;    :  \n"<<Default;
        cout<< Blue <<" ::     ;    \\;  / /   /:   ; / \\    `.  :     ;  \n"<<Default;
        cout<< Blue <<" ;:    : .-   ; : :.-./  \\_/.'   \\     `-:     :                                      "<<White<<"Another Day, Another Win for SPIDEY!!!\n"<<Default;
        cout<< Blue <<" : \\   ;/     : ; ;  /`-   /      j       `.   ; \n"<<Default;
        cout<< Blue <<"  ; `-.:      ; ; ;.'   \\_g,     / ; ;      j :  \n"<<Default;
        cout<< Blue <<"  :     j    /  : :    ,-dP-'\"--:  ; :     / ;;  \n"<<Default;
        cout<< Blue <<"   \\__.' \\_.'    \\ \\  _ s\")    / \\ :._;_.-'  ::  \n"<<Default;
        cout<< Red <<"             bug  \\   ;:      :   ; \\ :      :: \n"<<Default;
        cout<< Red <<"            \\  ;;     /;   :  `.\\      ;     \n"<<Default;
        cout<< Red <<"                    ; ::\\__.'/;__.:---.\\     :  \n"<<Default;
        cout<< Red <<"                    : ;  -.-'/___       \\  _.;  \n"<<Default;
        cout<< Red <<"                    : :`-. )\",--\"     ,--\"\" /   \n"<<Default;
        cout<< Red <<"                    ; .;__T+'\"\"\"-._   :   .'    \n"<<Default;
        cout<< Red <<"                   :,'     ;       ""-^-""      \n"<<Default;
        cout<<"                   ;  _    :     \n"<<Default;
        cout<<"                  :  / \\   /;   \n"<<Default;
        cout<<"                  ; :   \\ / :    \n"<<Default;
        cout<< "                  : ;_.-' `.;    \n"<<Default;
        cout<< Red <<"                   \\       /     \n"<<Default;
        cout<< Red <<"                    `.___.'      \n"<<Default;
    }
    else
    {
        cout << Cyan <<"WITH GREAT POWER, COMES GREAT DUMBNESS... - SPOODERMAN (Probably)\n" << Default;
        cout<<Yellow<<"                                                                      /L'-, \n"<<Default;
        cout<<"                               ,'-.           "<<Yellow<<"/MM . .             /  L '-,    \n"<<Default;
        cout<<"     .                    _,--dMMMM\\         "<<Yellow<<"/MMM  `..           /       '-, \n"<<Default;
        cout<<"     :             _,--,  )MMMMMMMMM),.      "<<Yellow<<"`QMM   ,<>         /_      '-,'  \n"<<Default;
        cout<<"     ;     ___,--. \\MM(    `-'   )M//MM\\       "<<Yellow<<"`  ,',.;      .-'* ;     .'  \n"<<Default;
        cout<<"     |     \\MMMMMM) \\MM\\       ,dM//MMM/     ___ "<<Yellow<<"< ,; `.      )`--'    /   \n"<<Default;
        cout<<"     |      \\MM()M   MMM)__   /MM(/MP'  ___, \\  \\ "<<Yellow<<"`  `. `.   /__,    ,'    \n"<<Default;
        cout<<"     |       MMMM/   MMMMMM( /MMMMP'__, \\     | /      "<<Yellow<<"`. `-,_\\     /                                      "<<Red <<"HAHHH!! You're just SPOODERMAN!!!!!!\n"<<Default;
        cout<<"     |       MM     /MMM---' `--'_ \\     |-'  |/         "<<Yellow<<"`./ .\\----.___ \n"<<Default;
        cout<<"     |      /MM'   `--' __,-  \\""   |-'  |_,               "<<Yellow<<"`.__) . .F. )-.   \n"<<Default;
        cout<<"     |     `--'       \\   \\    |-'  |_,     _,-/            "<<Yellow<<"J . . . J-'-. `-.,  \n"<<Default;
        cout<<"     |         __  \\`. |   |   |         \\    / _           "<<Yellow<<"|. . . . \\   `-.  F    \n"<<Default;
        cout<<"     |   ___  /  \\  | `|   '      __  \\   |  /-'            "<<Yellow<<"F . . . . \\     '`    \n"<<Default;
        cout<<"     |   \\  \\ \\  /  |        __  /  \\  |  |,-'        __,"<<Yellow<<"- J . . . . . \\          \n"<<Default;
        cout<<"     |    | /  |/     __,-  \\  ) \\  /  |_,-     __,--'     "<<Yellow<<"|. .__.----,'           \n"<<Default;
        cout<<"     |    |/    ___     \\    |'.  |/      __,--'           "<<Yellow<<"`.-;;;;;;;;;\\         \n"<<Default;
        cout<<"     |     ___  \\  \\     |   |  `   __,--'                  "<<Yellow<<"/;;;;;;;;;;;;.     \n"<<Default;
        cout<<"     |     \\  \\  |-'\\    '    __,--'                       "<<Yellow<<"/;;;;;;;;;;;;;;\\   \n"<<Default;
        cout<<" \\   |      | /  |      __,--'                             "<<Yellow<<"`--;;/     \\;-'\\  \n"<<Default;
        cout<<"  \\  |      |/    __,--'                                   "<<Yellow<<"/  /         \\  \\  \n"<<Default;
        cout<<"   \\ |      __,--'                                        "<<Yellow<<"/  /           \\  \\    \n"<<Default;
        cout<<"    \\|__,--'                                          "<<Yellow<<"_,-;M-K,           ,;-;\\       \n"<<Default;
        cout<<"                                                     "<<Yellow<<"<;;;;;;;;           '-;;;;   \n"<<Default;
        cout<<"`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n";
    }
    cout << endl;
    cout << Green << "THANK YOU FOR PLAYING MY GAME - Aalvee.\n" << Default;
    return 0;
}

void introScreen()
{
    cout << Red <<"     _______  _______  _______  _______  ______   _______  _______  _______  _______  _        _  _  _  _               \n"<<Default;
    cout << Red <<"    (  ____ \\(  ____ )(  ___  )(  ___  )(  __  \\ (  ____ \\(  ____ )(       )(  ___  )( (    /|( )( )( )( )           \n"<<Default;
    cout << Red <<"    | (    \\/| (    )|| (   ) || (   ) || (  \\  )| (    \\/| (    )|| () () || (   ) ||  \\  ( || || || || |          \n"<<Default;
    cout << Red <<"    | (_____ | (____)|| |   | || |   | || |   ) || (__    | (____)|| || || || (___) ||   \\ | || || || || |             \n"<<Default;
    cout << Red <<"    (_____  )|  _____)| |   | || |   | || |   | ||  __)   |     __)| |(_)| ||  ___  || (\\ \\) || || || || |            \n"<<Default;
    cout << Red <<"          ) || (      | |   | || |   | || |   ) || (      | (\\ (   | |   | || (   ) || | \\   |(_)(_)(_)(_)            \n"<<Default;
    cout << Red <<"    /\\____) || )      | (___) || (___) || (__/  )| (____/\\| ) \\ \\__| )   ( || )   ( || )  \\  | _  _  _  _          \n"<<Default;
    cout << Red <<"    \\_______)|/       (_______)(_______)(______/ (_______/|/   \\__/|/     \\||/     \\||/    )_)(_)(_)(_)(_)          \n\n\n"<<Default;
    cout << Blue <<"                        By Aalvee Ahtav\n\n"<<Default;
    cout << Yellow <<"Obejctive:-    Get KID SIMPSON off his Skateboard before he HITS you and you Become a JOKE!!...\n"<<Default;
    cout << Cyan <<"Context:- On an Ordinary day, Kid Simpson was skating on his way to draw some graffiti art on a random wall and somehow landed on the Marvel universe right front of Spider-Man.\n"<<Default;
    cout << Cyan <<"Spider-Man being confused, tries to stop him but Kid Simpson isn't considering stopping as an Option.\n\n"<<Default;
    cout << Purple <<"Instructions:- Guess the phrase correctly to stop Simpson or see yourself being SPOODERMAN!!!\n"<<Default;
    cout << Yellow <<"TRY YOUR BEST TO NOT BECOME SPOODERMANNNNNN!!!!!!\n\n"<<Default;
    cout << Green <<"                Press <ENTER> to Begin\n"<<Default;
    cin.ignore();


}


void displayASCIIArt (int BadGuesses)
{

    if (BadGuesses == 0)
    {
        cout << Green <<"Another day, another wi..... Wait! What?! Who are you?\n" << Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\__                                                                                      "<< Yellow <<"I can ask you the same Spider face! Get out of my way... WOHOOOOOOO!!\n"<<Default;
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ \n";
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._                                                                                                                        "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_                                                                                                                     "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L                                                                                                                   "<<Green <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,                                                                                                              "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,                                                                                                            "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''                                                                                                             "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );                                                                                                                   "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/                                                                                                               "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,                                                                                                                       "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\                                                                                                                   "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]                                                                                                                 "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                                                                                                                         "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                                                                                                                          "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                                                                                                                            "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                                                                                                                                   "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                                                                                                                                  "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                                                                                                                           "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                                                                                                                               "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
    if (BadGuesses == 1)
    {
        cout << Green <<"Stop where you are Simpson looking GUY!\n" << Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\_                                                                                      "<< Yellow <<"I don't see me stopping Spidey....(continues skating)\n" << Default;
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ \n";
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._                                                                                                    "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_                                                                                                 "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L                                                                                               "<<Green <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,                                                                                          "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,                                                                                        "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''                                                                                         "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );                                                                                               "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/                                                                                           "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,                                                                                                   "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\                                                                                               "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]                                                                                             "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                                                                                                     "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                                                                                                      "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                                                                                                        "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                                                                                                               "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                                                                                                              "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                                                                                                       "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                                                                                                           "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
    if (BadGuesses == 2)
    {
        cout<< Green <<"(Sighs)This isn't looking good.....\n" << Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\__                                                                 "<< Yellow <<"Outta my way!! I got stuff to do(important)\n" << Default;
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ \n";
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._                                                                                "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_                                                                             "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L                                                                           "<<White <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,                                                                      "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,                                                                    "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''                                                                     "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );                                                                           "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/                                                                       "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,                                                                               "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\                                                                           "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]                                                                         "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                                                                                 "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                                                                                  "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                                                                                    "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                                                                                           "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                                                                                          "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                                                                                   "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                                                                                       "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
    if (BadGuesses == 3)
    {
        cout<< Green <<"*****(not audible)\n" << Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\__                                                                            "<< Yellow <<"*****(not audible)\n" << Default;
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ \n";
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._                                                                      "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_                                                                   "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L                                                                 "<<Yellow <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,                                                            "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,                                                          "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''                                                           "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );                                                                 "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/                                                             "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,                                                                     "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\                                                                 "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]                                                               "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                                                                       "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                                                                        "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                                                                          "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                                                                                 "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                                                                                "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                                                                         "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                                                                             "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
    if (BadGuesses == 4)
    {
        cout<< Green <<"Why I can't stop him?(Getting nervous)\n" << Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\__                                            "<< Yellow <<"I won't mind hitting you to be honest hahaha....\n" << Default;
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ \n";
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._                                                       "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_                                                    "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L                                                  "<<Yellow <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,                                             "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,                                           "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''                                            "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );                                                  "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/                                              "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,                                                      "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\                                                  "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]                                                "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                                                        "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                                                         "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                                                           "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                                                                  "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                                                                 "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                                                          "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                                                              "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
    if (BadGuesses == 5)
    {
        cout<< Green <<"Think SPIDEY! THINK!!)\n" << Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\__                       "<< Yellow <<"Whatchu thinking Webface?\n" << Default;
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ \n";
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._                         "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_                      "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L                    "<<Red <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,               "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,             "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''              "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );                    "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/                "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,                        "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\                    "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]                  "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                          "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                           "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                             "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                                    "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                                   "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                            "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                                "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
    if (BadGuesses == 6)
    {
        cout<< Green <<"No wait,,, can we Negotiate?!\n"<<Default;
        cout<< Red <<"                   ,,,,   \n";
        cout<< Red <<"              ,;) .';;;;',    \n";
        cout<< Red <<"  ;;,,_,-.-.,;;'_,|I\\;;;/),,_    \n";
        cout<< Red <<"   `';;/:|:);{ ;;;|| \\;/ /;;;\\__    \n";
        cout<< Red <<"       L;/-';/ \\;;\\',/;\\/;;;.') \\ "<<Purple <<"NOPE! Hasta La Vista SPIDEY!(1 sec before crashing into Spider-Man)\n"<<Default;
        cout<< Red <<"       .:`''` - \\;;'.__/;;;/  . _'-._               "<<Yellow<<"/\\/\\/\\/\\    \n"<<Default;
        cout<< Red <<"     .'/   \\     \\;;;;;;/.'_7:.  '). \\_            "<<Yellow<<"/       /    \n"<<Default;
        cout<< Red <<"   .''/     | '._ );}{;//.'    '-:  '.,L          "<<Red <<"(. (.  )  \n"<<Default;
        cout<< Red <<" .'. /       \\  ( |;;;/_/         \\._./;\\   _,     "<<Yellow<<"(      ] \n"<<Default;
        cout<< Red <<"  . /        |\\ ( /;;/_/             ';;;\\,;;_,   "<<Yellow<<"/____  /  \n"<<Default;
        cout<< Red <<" . /         )__(/;;/_/                (;;'''''    "<<Yellow<<"\\     | \n"<<Default;
        cout<< Blue <<"  /        _;:':;;;;:';-._             );          "<<Yellow<<"/-----\\ \n"<<Default;
        cout<< Blue <<" /        /   \\  `'`   --.'-._         \\/      "<<Yellow<<"/ /     /  \\  \n"<<Default;
        cout<< Blue <<"        .'     '.  ,'         '-,              "<<Yellow<<"/ \\/       \\/  \\  \n"<<Default;
        cout<< Blue <<"       /    /   r--,..__       '.\\          "<<Yellow<<"/ / /           \\  \\ \n"<<Default;
        cout<< Blue <<"     .'    '  .'        '--._     ]        "<<Yellow<<"((()  /__________\\ (/\\)))  \n"<<Default;
        cout<< Blue <<"     (     :.(;>        _ .' '- ;/                "<<Yellow<<"/         \\  \n"<<Default;
        cout<< Blue <<"     |      /:;(    ,_.';(   __.'                 "<<Yellow<<"|    /\\    \\    \n"<<Default;
        cout<< Blue <<"      '- -'\"|;:/    (;;;;-'--'                   "<<Yellow<<"----| |----   \n"<<Default;
        cout<< Blue <<"            |;/      ;;(                          "<<Yellow<<"|__ |  \\__ \\    \n"<<Default;
        cout<< Blue <<"  snd       ''      /;;|                         "<<Yellow<<"{____|   {___} \n"<<Default;
        cout<< Blue <<"                    \\;;|                  "<<Yellow<<"=======================/ \n"<<Default;
        cout<< Blue <<"                     \\/                      "<<Yellow<<"(o)           (o) \n"<<Default;
        cout<<"````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````` \n";
    }
}
