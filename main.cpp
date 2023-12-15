#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string.h>
#include<sstream>
#include<time.h>
#include<ctime>
#include<SDL2/SDL_mixer.h>
#include <bits/stdc++.h>
#include<fstream>

using namespace std;


void textFont(SDL_Renderer *renderer,int x,int y,const char * text,const char * Font,int font_size,SDL_Color textColor);

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian);
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height);
void textColor1 (SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num);

void TextBox (SDL_Renderer* m_renderer,string name);

struct table{
string name="";
string power="";
 int win=0;
 int loss=0;
 int draw=0;
 int goal=-1;
};


typedef enum{
     NONE = 0,
     HORIZENTAL = 1,
     VERTICAL = 2,
     HORVER = 3
}short;

int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO );
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);

    Mix_Music *back1s = Mix_LoadMUS("back1S.mp3");
    Mix_Music *back2s = Mix_LoadMUS("back2S.mp3");
    Mix_Music *playcheer = Mix_LoadMUS("crowd.mp3");
    Mix_Music *clipmusic = Mix_LoadMUS("clipmusic.mp3");
    Mix_Chunk *clickSound = Mix_LoadWAV("click.WAV");
    Mix_Chunk *woodwork = Mix_LoadWAV("woodwork.WAV");
    Mix_Chunk *shootsound = Mix_LoadWAV("shoot.WAV");
    Mix_Chunk *goalCHeer = Mix_LoadWAV("cheer.WAV");


    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    int img_w, img_h;
    SDL_Rect img_rect;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 600, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    SDL_RenderPresent( m_renderer );
   // bool clicked=true;
    SDL_Texture* m_img = NULL;




      // Mix_FreeMusic(back1s);
      //Mix_PlayChannel(-1,clickSound,0);
      //Mix_PlayChannel(-1,shootsound,0);
      //Mix_PauseMusic();

              string filename5="";
              short int num5 =0;
              table I[20];
              table player1,player2;
             int stime;
             int etime;
              ///////////////////////////////////////
             while(true){
             filename5=to_string(num5);
             filename5+=".txt";
             ifstream f(filename5.c_str());
             while(!f.eof()){
             getline( f , I[num5].name);
             getline( f , I[num5].power);
             getline( f , filename5 ); //  win
             I[num5].win=stoi(filename5);
             getline( f , filename5 ); //  loss
             I[num5].loss=stoi(filename5);
             getline( f , filename5 ) ;//  draw
             I[num5].draw=stoi(filename5);
             f>>I[num5].goal;
             }
             f.close();
             cout<<num5<<endl;
             if(I[num5].goal==-1)
             break;
             num5++;
             }
             //////////////////////////////////////
           short int x3,y3;
           for ( x3 = 0 ; x3 < int(num5) ; x3++ )
           for ( y3 = 0 ; y3 < int(num5)-x3-1 ; y3++ )
           if (I[y3].goal < I[y3+1].goal)
             {
           swap(I[y3+1].goal,I[y3].goal);
           swap(I[y3+1].name,I[y3].name);
           swap(I[y3+1].power,I[y3].power);
           swap(I[y3+1].win,I[y3].win);
           swap(I[y3+1].draw,I[y3].draw);
           swap(I[y3+1].loss,I[y3].loss);
           }
           ///////////////////////////////////////
           for ( x3 = 0 ; x3 < int(num5) ; x3++ )
           {
           cout<<I[x3].name<<endl;
           cout<<I[x3].power<<endl;
           cout<<I[x3].win<<endl;
           cout<<I[x3].loss<<endl;
           cout<<I[x3].draw<<endl;
           cout<<I[x3].goal<<endl;
           }
     bool Pauseplay =true;
     bool Pausecheer =true;
     bool voiceOnOff =true;
     bool voiceCHange=true;
     bool matchResult=false;
     bool restartmatch=true;
    string settingstr="settingback1.jpg";
    string player1name="";
    string player2name="";
    string playerName1="";
    string playerName2="";
    bool enteringname1=false;
    bool enteringname2=false;
    bool exit1= false;
    //////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////// pic loading1
    SDL_Rect mainpicr;
    mainpicr.x = 0;
    mainpicr.y = 0;
    mainpicr.w = 1200;
    mainpicr.h = 600;
    string pplay="mainpicr.gif";
    SDL_Texture *mainrtexture;
    mainrtexture= IMG_LoadTexture( m_renderer,pplay.c_str());
    int wmainr=1200, hmainr=600;
    SDL_QueryTexture(mainrtexture, NULL, NULL, &wmainr, &hmainr);
    //////////////////////////////////////////////////////////////////////
    string pplay2="mainpicl.gif";
    SDL_Texture *mainltexture;
    mainltexture= IMG_LoadTexture( m_renderer,pplay2.c_str());
    SDL_QueryTexture(mainltexture, NULL, NULL, &wmainr, &hmainr);
    ////////////////////////////////////////////////////////////////////////
    int fps1=24;
              int td1=1000/24;
              int picnum=0;
              Mix_PlayMusic(clipmusic,-1);
               while (true){
                stime=SDL_GetTicks();
                string p66num;
                string picname="Outputpics\\";
                stringstream ss;
                ss << picnum;
                ss >> p66num;
                if (picnum<10 ){
                    p66num="00"+p66num;
                }
                if (picnum>=10 && picnum<100 ){
                    p66num="0"+p66num;
                }
                picname=picname+"Comp 1_1";
                picname=picname+p66num;
                picname=picname+".jpg";
                cout<<picname<<endl;
                texture(m_renderer,0,0,picname.c_str(),1200,600);
                if (picnum==358){
                    break;
                }
                picnum++;
                picname="";
              int etime=SDL_GetTicks();
              if ((etime-stime)<td1){
                SDL_Delay(td1+stime-etime);
              }
                SDL_RenderPresent(m_renderer);
                SDL_Delay(1);
                SDL_RenderClear(m_renderer);
            }
            Mix_PausedMusic();
            Mix_PlayMusic(back1s,-1);
            int t=41;

    //////////////////////////////////////////////////////////////////////////
    int fpsmenu=60;
    int tdmenu =16;
while (true){
     stime=SDL_GetTicks();
     player1name="";
     player2name="";
     playerName1="";
     playerName2="";
     enteringname1=false;
     enteringname2=false;
     exit1= false;
    texture (m_renderer,0,0,"mainpicr.gif",1200,600);

    const Uint8 *e2=SDL_GetKeyboardState(NULL);
    SDL_PumpEvents();
    int xmouse , ymouse;
    //SDL_RenderCopy( m_renderer, mainltexture, NULL, &mainpicr);
    ////////////////////////////////////////////////////////////////////////
    if ( e2[SDL_SCANCODE_ESCAPE]){
        break;
    }
    ////////////////////////////////////////////////////////////////////////
    if ( (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
            Mix_PlayChannel(-1,clickSound,0);
            cout<<xmouse<<endl;
            cout<< ymouse<<endl;
    }
             SDL_PumpEvents();
             SDL_GetMouseState(&xmouse,&ymouse);
             ///////////////////////////////////////////////////////////////////////////////////////////////////
                           if ((xmouse<131 && xmouse>65 && ymouse<107 && ymouse>45)){
                            texture(m_renderer,(-(t*t)/8+200),51,"playtext.gif",220,49);
                                 if (t==-1){
                                    t=0;
                                 }
                                 else {
                                    t --;
                                 }
                                 Mix_PlayChannel(-1,clickSound,0);
                                 }
                         if ((xmouse<130 && xmouse>50 && ymouse<218 && ymouse>158)){
                            texture(m_renderer,(-(t*t)/8+200),168,"tabletext.gif",220,49);
                                 if (t==-1){
                                    t=0;
                                 }
                                 else {
                                    t --;
                                 }
                                 Mix_PlayChannel(-1,clickSound,0);
                         }
                         if ((xmouse<131 && xmouse>61 && ymouse<334 && ymouse>275)){
                            texture(m_renderer,(-(t*t)/8+200),282,"helptext.gif",220,49);
                           if (t==-1){
                                    t=0;
                                 }
                                 else {
                                    t --;
                                 }
                                 Mix_PlayChannel(-1,clickSound,0);
                         }
                         if ((xmouse<135 && xmouse>60 && ymouse<448&& ymouse>387)){
                            texture(m_renderer,(-(t*t)/8+200),394,"setttext.gif",220,49);
                           if (t==-1){
                                    t=0;
                                 }
                                 else {
                                    t --;
                                 }
                                 Mix_PlayChannel(-1,clickSound,0);
                         }
                         if ((xmouse<128 && xmouse>60 && ymouse<562 && ymouse>498)){
                            texture(m_renderer,(-(t*t)/8+200),505,"exittext.gif",220,49);
                           if (t==-1){
                                    t=0;
                                 }
                                 else {
                                    t --;
                                 }
                                 Mix_PlayChannel(-1,clickSound,0);
                         }
                         if (!((xmouse<131 && xmouse>65 && ymouse<107 && ymouse>45) || (xmouse<115 && xmouse>45 && ymouse<218 && ymouse>158)|| (xmouse<131 && xmouse>61 && ymouse<334 && ymouse>275)||(xmouse<135 && xmouse>60 && ymouse<448&& ymouse>387)||(xmouse<128 && xmouse>60 && ymouse<562 && ymouse>498))){
                                t=41;
                         }
              SDL_RenderCopy( m_renderer, mainltexture, NULL, &mainpicr);
             ///////////////////////////////////////////////////////////////////////////////////////////////////
             if ((xmouse<115 && xmouse>45 && ymouse<120 && ymouse>60) && (SDL_GetMouseState(NULL,NULL)&& SDL_BUTTON_LMASK) !=0) {            // play
                    while (true){
                              Pauseplay=true;
                              int player1b=1;
                              int player2b=1;
                    ////////////////////////////////////////////////// play menu character chose
                              while(true){
                              SDL_PumpEvents();
                        ////////////////////////////////////////////////////////////
                              texture(m_renderer,0,0,"playmenu.jpg",1200,600);
                              texture(m_renderer,60,10,"back.jpg",50,50);
                              texture(m_renderer,550,250,"okbutton.jpg",100,100);
                        //////////////////////////////////////////////////////////////////////name
                        TTF_Init();
                        TTF_Font* Sans = TTF_OpenFont("arial.ttf", 30);
                        SDL_Color White = {255, 255, 255};
                                SDL_Surface *surfaceMessage;
                                    SDL_Rect Message_rect;
                                    Message_rect.x = 214;
                                    Message_rect.y = 145;
                                    SDL_Texture* Message;
                                    SDL_Surface *surfaceMessage2;
                                    SDL_Rect Message_rect2;
                                    Message_rect2.x = 214;
                                    Message_rect2.y = 145;
                                    SDL_Texture* Message2;

                                while (!enteringname1){
                                        cout<<"Salam";
                                        texture(m_renderer,0,0,"playmenu.jpg",1200,600);
                                            SDL_PumpEvents();
                                            const Uint8 *e2 = SDL_GetKeyboardState(NULL) ;
                                                if (e2 [SDL_SCANCODE_A]){
                                                   player1name+='a';
                                                    SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_B]){
                                                   player1name+='b';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_C]){
                                                   player1name+='c';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_D]){
                                                   player1name+='d';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_E]){
                                                   player1name+='e';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_F]){
                                                   player1name+='f';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_G]){
                                                   player1name+='g';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_H]){
                                                   player1name+='h';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_I]){
                                                   player1name+='i';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_J]){
                                                   player1name+='j';;
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_K]){
                                                   player1name+='k';
                                                   SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_L]){
                                                    player1name+='l';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_M]){
                                                    player1name+='m';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_N]){
                                                    player1name+='n';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_O]){
                                                    player1name+='o';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_P]){
                                                    player1name+='p';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_Q]){
                                                    player1name+='q';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_R]){
                                                    player1name+='r';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_S]){
                                                    player1name+='s';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_T]){
                                                    player1name+='t';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_U]){
                                                    player1name+='u';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_V]){
                                                    player1name+='v';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_X]){
                                                    player1name+='x';;
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_Y]){
                                                    player1name+='y';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_Z]){
                                                    player1name+='z';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_0]){
                                                    player1name+='0';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_1]){
                                                    player1name+='1';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_2]){
                                                    player1name+='2';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_3]){
                                                    player1name+='3';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_4]){
                                                    player1name+='4';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_5]){
                                                    player1name+='5';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_6]){
                                                    player1name+='6';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_7]){
                                                    player1name+='7';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_8]){
                                                    player1name+='8';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_9]){
                                                    player1name+='9';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_BACKSPACE]){
                                                    player1name=player1name.substr(0,player1name.length()-1);
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_INSERT]){
                                                    enteringname1=true;
                                                    SDL_Delay(150);
                                                    playerName1=player1name;
                                                    player1name="";
                                                    break;
                                                    SDL_RenderPresent(m_renderer);
                                                 }
                                                 if (player1b==1){
                                                        texture(m_renderer,280,288,"Chrisright1.gif",92,115);
                                                    }
                                                    if(player1b==2){
                                                        texture(m_renderer,280,288,"Ibraright1.gif",92,115);
                                                    }
                                                    if(player1b==3){
                                                        texture(m_renderer,280,288,"Dimaright1.gif",92,115);
                                                    }
                                                    if(player1b==4){
                                                        texture(m_renderer,280,288,"Juniright1.gif",92,115);
                                                    }
                                                    if(player1b==5){
                                                        texture(m_renderer,280,288,"Leoright1.gif",92,115);
                                                    }
                                                    if (player2b==1){
                                                        texture(m_renderer,824,288,"Chrisleft1.gif",92,115);
                                                    }
                                                    if(player2b==2){
                                                        texture(m_renderer,824,288,"Ibraleft1.gif",92,115);
                                                    }
                                                    if(player2b==3){
                                                        texture(m_renderer,824,288,"Dimaleft1.gif",92,115);
                                                    }
                                                    if(player2b==4){
                                                        texture(m_renderer,824,288,"Junileft1.gif",92,115);
                                                    }
                                                    if(player2b==5){
                                                        texture(m_renderer,824,288,"Leoleft1.gif",92,115);
                                                    }
                                                    if (xmouse>443 && xmouse<475 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player1b+= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if (xmouse>182 && xmouse<210 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player1b-= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if (xmouse>984 && xmouse<1016 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player2b+= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if (xmouse>723 && xmouse<755 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player2b-= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if ((SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        cout<< xmouse<<endl;
                                                        cout<< ymouse<<endl;
                                                    }
                                                    if ((xmouse<50 && xmouse>0 && ymouse<50 && ymouse>0) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        cout<< xmouse<<endl;
                                                        cout<< ymouse<<endl;
                                                        break;
                                                        SDL_RenderPresent(m_renderer);
                                                    }
                                                    if (player1b==6){
                                                            player1b=1;
                                                        }
                                                        if (player1b==0){
                                                            player1b=5;
                                                        }
                                                        if (player2b==6){
                                                            player2b=1;
                                                        }
                                                        if (player2b==0){
                                                            player2b=5;
                                                        }
                                                 texture(m_renderer,60,10,"back.jpg",50,50);
                                                texture(m_renderer,550,250,"okbutton.jpg",100,100);
                                                SDL_Surface *surfaceMessage =TTF_RenderText_Solid(Sans, player1name.c_str(), White);
                                                SDL_Rect Message_rect;
                                                SDL_GetClipRect(surfaceMessage,&Message_rect);
                                                Message_rect.x = 214;
                                                Message_rect.y = 145;
                                                SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
                                                SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
                                                SDL_RenderPresent(m_renderer);
                                                SDL_Delay(1);
                                                SDL_RenderClear(m_renderer);
                                                SDL_FreeSurface(surfaceMessage);
                                        }
                        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                while (!enteringname2){
                                            texture(m_renderer,0,0,"playmenu.jpg",1200,600);
                                            SDL_PumpEvents();
                                            const Uint8 *e2 = SDL_GetKeyboardState(NULL) ;
                                                if (e2 [SDL_SCANCODE_A]){
                                                   player2name+='a';
                                                    SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_B]){
                                                   player2name+='b';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_C]){
                                                   player2name+='c';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_D]){
                                                   player2name+='d';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_E]){
                                                   player2name+='e';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_F]){
                                                   player2name+='f';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_G]){
                                                   player2name+='g';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_H]){
                                                   player2name+='h';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_I]){
                                                   player2name+='i';
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_J]){
                                                   player2name+='j';;
                                                   SDL_Delay(100);
                                                }
                                                else if (e2 [SDL_SCANCODE_K]){
                                                   player2name+='k';
                                                   SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_L]){
                                                    player2name+='l';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_M]){
                                                    player2name+='m';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_N]){
                                                    player2name+='n';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_O]){
                                                    player2name+='o';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_P]){
                                                    player2name+='p';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_Q]){
                                                    player2name+='q';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_R]){
                                                    player2name+='r';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_S]){
                                                    player2name+='s';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_T]){
                                                    player2name+='t';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_U]){
                                                    player2name+='u';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_V]){
                                                    player2name+='v';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_X]){
                                                    player2name+='x';;
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_Y]){
                                                    player2name+='y';
                                                    SDL_Delay(100);
                                                }
                                                 else if (e2 [SDL_SCANCODE_Z]){
                                                    player2name+='z';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_0]){
                                                    player2name+='0';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_1]){
                                                    player2name+='1';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_2]){
                                                    player2name+='2';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_3]){
                                                    player2name+='3';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_4]){
                                                    player2name+='4';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2[SDL_SCANCODE_5]){
                                                    player2name+='5';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_6]){
                                                    player2name+='6';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_7]){
                                                    player2name+='7';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_8]){
                                                    player2name+='8';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_9]){
                                                    player2name+='9';
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_BACKSPACE]){
                                                    player2name=player2name.substr(0,player2name.length()-1);
                                                    SDL_Delay(100);
                                                 }
                                                 else if (e2 [SDL_SCANCODE_INSERT]){
                                                    enteringname2=true;
                                                    playerName2=player2name;
                                                    player2name="";
                                                    break;
                                                    SDL_RenderPresent(m_renderer);
                                                 }
                                                 if (player1b==1){
                                                        texture(m_renderer,280,288,"Chrisright1.gif",92,115);
                                                    }
                                                    if(player1b==2){
                                                        texture(m_renderer,280,288,"Ibraright1.gif",92,115);
                                                    }
                                                    if(player1b==3){
                                                        texture(m_renderer,280,288,"Dimaright1.gif",92,115);
                                                    }
                                                    if(player1b==4){
                                                        texture(m_renderer,280,288,"Juniright1.gif",92,115);
                                                    }
                                                    if(player1b==5){
                                                        texture(m_renderer,280,288,"Leoright1.gif",92,115);
                                                    }
                                                    if (player2b==1){
                                                        texture(m_renderer,824,288,"Chrisleft1.gif",92,115);
                                                    }
                                                    if(player2b==2){
                                                        texture(m_renderer,824,288,"Ibraleft1.gif",92,115);
                                                    }
                                                    if(player2b==3){
                                                        texture(m_renderer,824,288,"Dimaleft1.gif",92,115);
                                                    }
                                                    if(player2b==4){
                                                        texture(m_renderer,824,288,"Junileft1.gif",92,115);
                                                    }
                                                    if(player2b==5){
                                                        texture(m_renderer,824,288,"Leoleft1.gif",92,115);
                                                    }
                                                    if (xmouse>443 && xmouse<475 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player1b+= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if (xmouse>182 && xmouse<210 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player1b-= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if (xmouse>984 && xmouse<1016 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player2b+= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if (xmouse>723 && xmouse<755 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        player2b-= 1;
                                                        SDL_Delay(100);
                                                    }
                                                    if ((SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        cout<< xmouse<<endl;
                                                        cout<< ymouse<<endl;
                                                    }
                                                    if ((xmouse<50 && xmouse>0 && ymouse<50 && ymouse>0) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                                        Mix_PlayChannel(-1,clickSound,0);
                                                        cout<< xmouse<<endl;
                                                        cout<< ymouse<<endl;
                                                        break;
                                                    }
                                                    if (player1b==6){
                                                            player1b=1;
                                                        }
                                                        if (player1b==0){
                                                            player1b=5;
                                                        }
                                                        if (player2b==6){
                                                            player2b=1;
                                                        }
                                                        if (player2b==0){
                                                            player2b=5;
                                                        }
                                                 texture(m_renderer,60,10,"back.jpg",50,50);
                                                texture(m_renderer,550,250,"okbutton.jpg",100,100);
                                                SDL_Surface *surfaceMessage =TTF_RenderText_Solid(Sans, playerName1.c_str(), White);
                                                SDL_Rect Message_rect;
                                                SDL_GetClipRect(surfaceMessage,&Message_rect);
                                                Message_rect.x = 214;
                                                Message_rect.y = 145;
                                                SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
                                                SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
                                                SDL_FreeSurface(surfaceMessage);
                                                SDL_Surface *surfaceMessage2 =TTF_RenderText_Solid(Sans, player2name.c_str(), White);
                                                SDL_Rect Message_rect2;
                                                SDL_GetClipRect(surfaceMessage2,&Message_rect2);
                                                 Message_rect2.x = 755;
                                                Message_rect2.y = 145;
                                                SDL_Texture* Message2 = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage2);
                                                SDL_RenderCopy(m_renderer, Message2, NULL, &Message_rect2);
                                                SDL_RenderPresent(m_renderer);
                                                SDL_Delay(1);
                                                SDL_RenderClear(m_renderer);
                                                SDL_FreeSurface(surfaceMessage2);
                                        }
                        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                surfaceMessage =TTF_RenderText_Solid(Sans, playerName1.c_str(), White);
                                                SDL_GetClipRect(surfaceMessage,&Message_rect);
                                                Message_rect.x = 214;
                                                Message_rect.y = 145;
                                                Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
                                                SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
                                                SDL_FreeSurface(surfaceMessage);
                                                surfaceMessage2 =TTF_RenderText_Solid(Sans, playerName2.c_str(), White);
                                                SDL_GetClipRect(surfaceMessage2,&Message_rect2);
                                                 Message_rect2.x = 755;
                                                Message_rect2.y = 145;
                                                Message2 = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage2);
                                                SDL_RenderCopy(m_renderer, Message2, NULL, &Message_rect2);
                                                SDL_FreeSurface(surfaceMessage2);
                                                SDL_DestroyTexture(Message2);
                                               SDL_DestroyTexture(Message);
                                                texture(m_renderer,60,10,"back.jpg",50,50);
                                                texture(m_renderer,550,250,"okbutton.jpg",100,100);
                        //////////////////////////////////////////////////////////////////////char
                        if(player1b==1){
                            texture(m_renderer,280,288,"Chrisright1.gif",92,115);
                        }
                        if(player1b==2){
                            texture(m_renderer,280,288,"Ibraright1.gif",92,115);
                        }
                        if(player1b==3){
                            texture(m_renderer,280,288,"Dimaright1.gif",92,115);
                        }
                        if(player1b==4){
                            texture(m_renderer,280,288,"Juniright1.gif",92,115);
                        }
                        if(player1b==5){
                            texture(m_renderer,280,288,"Leoright1.gif",92,115);
                        }
                        if(player2b==1){
                            texture(m_renderer,824,288,"Chrisleft1.gif",92,115);
                        }
                        if(player2b==2){
                            texture(m_renderer,824,288,"Ibraleft1.gif",92,115);
                        }
                        if(player2b==3){
                            texture(m_renderer,824,288,"Dimaleft1.gif",92,115);
                        }
                        if(player2b==4){
                            texture(m_renderer,824,288,"Junileft1.gif",92,115);
                        }
                        if(player2b==5){
                            texture(m_renderer,824,288,"Leoleft1.gif",92,115);
                        }
                              ///////////////////////////////////////
                             SDL_RenderPresent(m_renderer);
                              matchResult=false;
                              //////////////////////
                            if((SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                                Mix_PlayChannel(-1,clickSound,0);
                             }
                             ////////////////////////////////////
                            if (xmouse>443 && xmouse<475 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                player1b+= 1;
                                SDL_Delay(100);
                            }
                            else if (xmouse>182 && xmouse<210 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                player1b-= 1;
                                SDL_Delay(100);
                            }
                            else if (xmouse>984 && xmouse<1016 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                player2b+= 1;
                                SDL_Delay(100);
                            }
                            else if (xmouse>723 && xmouse<755 && ymouse >341 && ymouse<382 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                player2b-= 1;
                                SDL_Delay(100);
                            }
                            else if ((xmouse<120 && xmouse>60 && ymouse<60&& ymouse>10) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                                Pauseplay=false;
                                player1name="";
                                player2name="";
                                playerName1="";
                                playerName2="";
                                enteringname1=false;
                                enteringname2=false;
                                SDL_Delay(100);
                                break;
                            }
                            /////////////////////////////////////////////////
                              if (player1b==6){
                              player1b=1;
                              }
                              if (player1b==0){
                              player1b=5;
                              }
                              if (player2b==6){
                              player2b=1;
                              }
                              if (player2b==0){
                              player2b=5;
                              }
                            ///////////////////////////////////////////////// play menu
                            else if(xmouse<650 && xmouse>550 && ymouse<350 && ymouse>250 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0  ){

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////// text
                                SDL_Color textco ={255,255,255};
                                SDL_Color textco1 ={0,0,0};
                    ///////////////////////////////////////////////// char search
                                ////  player name 1
                                short int x4,y4;
                                for(x4=0;x4<num5;x4++){
                                    if(playerName1==I[x4].name)
                                        break;
                                }
                                ////////////////////// create new
                            if(x4==num5){
                                 I[x4].name=playerName1;
                                 I[x4].draw=0;
                                 I[x4].goal=0;
                                 I[x4].win =0;
                                 I[x4].loss=0;
                                 if(player1b==1){
                                 I[x4].power="Chris";
                                 }
                                if(player1b==2){
                                 I[x4].power="Ibra";
                                 }
                                if(player1b==3){
                                 I[x4].power="Dima";
                                 }
                                if(player1b==4){
                                 I[x4].power="Juni";
                                 }
                                if(player1b==5){
                                 I[x4].power="Leo";
                                }
                                num5++;
                            }
                              ////  player name 2
                               for(y4=0;y4<num5;y4++){
                                    if(playerName2==I[y4].name)
                                        break;
                               }
                               ////////////////// create new
                               if(y4==num5){
                                 I[y4].name=playerName2;
                                 I[y4].draw=0;
                                 I[y4].goal=0;
                                 I[y4].win =0;
                                 I[y4].loss=0;
                                 if(player2b==1){
                                 I[y4].power="Chris";
                                 }
                                if(player2b==2){
                                 I[y4].power="Ibra";
                                 }
                                if(player2b==3){
                                 I[y4].power="Dima";
                                 }
                                if(player2b==4){
                                 I[y4].power="Juni";
                                 }
                                if(player2b==5){
                                 I[y4].power="Leo";
                                }
                                num5++;
                            }
                       //////////////////////////////////////////////
                             //player1.name= "ali" ,player1.power="messiright1.gif",player1.goal=29,player1.win=12,player1.loss=5,player1.draw=5;
                             //player2.name="zavar",player2.power="neymarleft1.gif",player2.goal=29,player2.win=12,player2.loss=5,player2.draw=5;

                       ///////////////////////////////////////////////
                             short int maxgoal=5;
                             short int maxtime=60;

                             string fieldplay="stadiumzir1.gif";
                             /////////////////////////////////////////  VAZIIYAT
                             while(true){
                      /////////////////////////////////////////////
                        texture (m_renderer,0,0,"condmenu.jpg",1200,600);
                        texture(m_renderer,10,10,"back.jpg",50,50);
                        texture(m_renderer,550,460,"okbutton.jpg",100,100);
                      /////////////////////////////////////////////
                             if((SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                                Mix_PlayChannel(-1,clickSound,0);
                             }
                      ////////////////////////////////////////////////////////// time
                            if ((xmouse<656 && xmouse>580 && ymouse<214 && ymouse>180) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                maxtime = 60;
                                    rect(m_renderer,580,214,76,20,255,255,255,1);
                            }
                            else if ((xmouse<790 && xmouse>720 && ymouse<214 && ymouse>180) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                maxtime = 75;
                                    rect(m_renderer,720,214,70,20,255,255,255,1);
                            }
                            else if ((xmouse<930 && xmouse>860 && ymouse<214 && ymouse>180) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                maxtime = 90;
                                    rect(m_renderer,860,214,70,20,255,255,255,1);
                            }
                            ///////////////////////////////////////////////////// goal
                            else if ((xmouse<620 && xmouse>590 && ymouse<314 && ymouse>285) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                maxgoal = 5;
                                    rect(m_renderer,590,314,30,20,255,255,255,1);
                            }
                            else if ((xmouse<770 && xmouse>740 && ymouse<314 && ymouse>285) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                maxgoal =7;
                                     rect(m_renderer,740,314,30,20,255,255,255,1);
                            }
                            else if ((xmouse<910 && xmouse>890 && ymouse<314 && ymouse>285) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                maxgoal = 9;
                                      rect(m_renderer,890,314,30,20,255,255,255,1);
                            }
                            ////////////////////////////////////////////////////// field
                            else if ((xmouse<730 && xmouse>580 && ymouse<420 && ymouse>396) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                fieldplay="stadiumzir1.gif";
                                      rect(m_renderer,580,420,150,20,255,255,255,1);
                            }
                            else if ((xmouse<980 && xmouse>820 && ymouse<420 && ymouse>396) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                fieldplay="stadiumzir2.gif";
                                      rect(m_renderer,820,420,160,20,255,255,255,1);
                            }
                            //////////////////////////////////////////////////////
                          SDL_RenderPresent(m_renderer);
                          SDL_RenderClear(m_renderer);
                            /////////////////////////////////////////////
                        SDL_PumpEvents();
                        SDL_GetMouseState(&xmouse,&ymouse);
                             if((SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                             }
                            if ((xmouse<60 && xmouse>10 && ymouse<60 && ymouse>10) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                                break;
                            }
                            if (((xmouse<650 && xmouse>550 && ymouse<560 && ymouse>460) &&  (SDL_GetMouseState(&xmouse,&ymouse)&&SDL_BUTTON_LMASK )  != 0)){
                                Mix_PlayChannel(-1,clickSound,0);


                               while(true){
                                ///////////////////////////////////////////////   copy information of player
                                player1=I[x4];
                                player2=I[y4];
                                player1.power+="right1.gif";
                                player2.power+="left1.gif";
                                ////////////////////////////////////////////////////////////////////////////////////////////////////PICS
                                SDL_Rect texr1;
                                texr1.x = 0;
                                texr1.y = 0;
                                texr1.w = 1200;
                                texr1.h = 600;
                                string p1=fieldplay;
                                SDL_Texture *myTexture1;
                                myTexture1 = IMG_LoadTexture( m_renderer,p1.c_str());
                                int w1=1200, h1=600;
                                SDL_QueryTexture(myTexture1, NULL, NULL, &w1, &h1);
                                //////////////////////////////////////////////////////////////////////
                                string p2="fans.gif";
                                SDL_Texture *myTexture2;
                                myTexture2 = IMG_LoadTexture( m_renderer,p2.c_str());
                                SDL_QueryTexture(myTexture2, NULL, NULL, &w1, &h1);
                                /////////////////////////////////////////////////////////////////////
                                string p6="field1ro.gif";
                                SDL_Texture *myTexture6;
                                myTexture6 = IMG_LoadTexture( m_renderer,p6.c_str());
                                SDL_QueryTexture(myTexture6, NULL, NULL, &w1, &h1);
                                ///////////////////////////////////////////////////////////////////
                                string p8="deepest.gif";
                                SDL_Texture *myTexture8;
                                myTexture8 = IMG_LoadTexture( m_renderer,p8.c_str());
                                SDL_QueryTexture(myTexture8, NULL, NULL, &w1, &h1);
                                ///////////////////////////////////////////////////////////////////
                                // texture(m_renderer,150,0,"scoreboard.gif",900,120);
                                ///////////////////////////////////////////////////////////////////
                                SDL_Texture *myTexture7;
                                myTexture7 = IMG_LoadTexture( m_renderer,"scoreboard.gif");
                                w1=300,h1=120;
                                SDL_QueryTexture(myTexture7, NULL, NULL, &w1, &h1);
                                SDL_Rect texr2;
                                texr2.x = 150;
                                texr2.y = 0;
                                texr2.w = 900;
                                texr2.h = 120;
                                ///////////////////////////////////////////////////////////////////////////////////////
                                short int powerOfplayer1=0;
                                short int powerOfplayer2=0;
                                int x=300,dx=0,y=100,dy=0;
                                int x1=0;
                                int y1=345;
                                int x2=1108;
                                int y2=345;
                                int dy1=0;
                                int dy2=0;
                                int dx1= 5;
                                int dx2=-5;
                                int dx1P=0;
                                int dx2P=0;
                                short int playergoal=0;
                                short int playergoa2=0;
                                int s=0,s1=0,s2=0,s3=0,s4=0,s5=0;

                                string time1;
                                string goalOfmacth;
                                restartmatch=true;
                                while(true){

                                texture(m_renderer,0,0,fieldplay.c_str(),1200,600);
                                texture(m_renderer,0,0,"fans.gif",1200,600);
                                texture(m_renderer,x1,y1,player1.power.c_str(),92,115);
                                texture(m_renderer,x2,y2,player2.power.c_str(),92,115);
                                texture(m_renderer,0,0,"field1ro.gif",1200,600);
                                ////////////////////////////////////////////////////////////// information of players
                                texture(m_renderer,0,0,"playinfo.gif",1200,600);
                                textFont(m_renderer,300,130 , player1.name.c_str ()            ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,300,170 ,to_string(player1.win)  .c_str () ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,300,210,to_string( player1.loss).c_str () ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,300,250,to_string(player1.draw) .c_str () ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,300,290,to_string( player1.goal).c_str () ,"digital-7.ttf",25,textco1);
                                ///////////////////
                                textFont(m_renderer,850,130 , player2.name.c_str ()            ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,850,170 , to_string(player2.win) .c_str () ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,850,210, to_string(player2.loss).c_str () ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,850,250, to_string(player2.draw).c_str () ,"digital-7.ttf",25,textco1);
                                textFont(m_renderer,850,290, to_string(player2.goal).c_str () ,"digital-7.ttf",25,textco1);
                                //////////////////////////////////////////////////////////////
                                SDL_RenderPresent(m_renderer);
                                if(x1==200 && dx1<0){
                                     break;
                                }
                                if(x2-x1<100){
                                    SDL_Delay(3000);
                                    dx1*=-1;
                                    dx2*=-1;
                                }
                                x1+=dx1;
                                x2+=dx2;
                                }
                                SDL_Delay(3000);
                                Mix_PauseMusic();
                                Mix_PlayMusic(playcheer,-1);
                                Mix_Volume( 2 , 50);
                                bool freazPlayer1=false;
                                bool freazPlayer2=false;
                                bool invisibleBall=false;
                                bool cloneOfplayer1=false;
                                bool cloneOfplayer2=false;
                                bool punchPlayer1=false;
                                bool punchPlayer2=false;
                                int xPunch,yPunch;
                                bool firefreez = false;
                                s = time(NULL);
                                int xc1, xc2;
                                int xd1, xd2;
                                short int dizz=0 ;
                                string dizzez="";
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////game
                                int timeOfsl,timeOfel;
                                //////////////////////////////////////////////////////       match start
                                while (true){

                                timeOfsl=SDL_GetTicks();
                                s1= time(NULL)-s ;
                                stringstream ss;
                                ss << (maxtime-s1);
                                ss >> time1;
                                if (s1>maxtime-10){
                                    time1="0"+time1;
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////// power increase
                                if(s1>s2){
                                   s2=s1;
                                   powerOfplayer1++;
                                   powerOfplayer2++;
                                }
                                else if(s1-s2>1){
                                    s1=s2;
                                    powerOfplayer1++;
                                    powerOfplayer2++;
                                }
                                ////////////////////////////////////////////////////////////////////////////////////////////////   end game
                                if(s1>maxtime){  ////
                                if(playergoal>playergoa2){    //// win1
                                   Mix_PauseMusic();
                                   player1.win++;
                                   player2.loss++;
                                   texture (m_renderer,300,150,"winner-1.png",600,300);
                                   SDL_RenderPresent(m_renderer);
                                   SDL_Delay(5000);
                                   Pauseplay=false;
                                   matchResult=true;
                                   break;
                                }
                                else if(playergoa2>playergoal){//// win2
                                   Mix_PauseMusic();
                                   player2.win++;
                                   player1.loss++;
                                   texture (m_renderer,300,150,"winner-2.png",600,300);
                                   SDL_RenderPresent(m_renderer);
                                   SDL_Delay(5000);
                                   Pauseplay=false;
                                   matchResult=true;
                                   break;
                                }
                                else{///// draw
                                     Mix_PauseMusic();
                                     player1.draw++;
                                     player2.draw++;
                                    // texture (m_renderer,300,150,"winner-1.png",600,300);
                                    // SDL_RenderPresent(m_renderer);
                                     SDL_Delay(5000);
                                     Pauseplay=false;
                                     matchResult=true;
                                    break;
                                 }
                                }
                                ///////////////////////////////////////////////////
                                if(playergoa2==maxgoal-1 && playergoal==maxgoal-1){   //// draw
                                  Mix_PauseMusic();
                                   player1.draw++;
                                   player2.draw++;
                                   //texture (m_renderer,300,150,"winner-1.png",600,300);
                                   //SDL_RenderPresent(m_renderer);
                                   SDL_Delay(5000);
                                   Pauseplay=false;
                                   matchResult=true;
                                    break;
                                }
                                ///////////////////////////////////////////////
                                else if(playergoa2==maxgoal || playergoal==maxgoal){  ///// win
                                if(playergoal>playergoa2){    //// win1
                                   Mix_PauseMusic();
                                    player1.win++;
                                    player2.loss++;
                                    texture (m_renderer,300,150,"winner-1.png",600,300);
                                    SDL_RenderPresent(m_renderer);
                                    SDL_Delay(5000);
                                    Pauseplay=false;
                                    matchResult=true;
                                    break;
                                }
                                else if(playergoa2>playergoal){//// win2
                                    Mix_PauseMusic();
                                    player2.win++;
                                    player1.loss++;
                                    texture (m_renderer,300,150,"winner-2.png",600,300);
                                    SDL_RenderPresent(m_renderer);
                                    SDL_Delay(5000);
                                    Pauseplay=false;
                                    matchResult=true;
                                    break;
                                }
                                ////
                                }
                                /////////////////////////////////////////////////////////////////////////////////////////////// goal *****
                                 if(x<=36 && y>300){
                                   Mix_PlayChannel(-1,goalCHeer,0);
                                     int jumpnumber=0;
                                     int dy3;
                                     y3=0;
                                     while (jumpnumber<21) {
                                        if (y3==0){
                                            dy3=-5;
                                            jumpnumber+=1;
                                        }
                                        SDL_Rect texr3;
                                        texr3.x = 0;
                                        texr3.y = y3;
                                        texr3.w = 1200;
                                        texr3.h = 600;
                                        SDL_RenderCopy( m_renderer, myTexture8, NULL, &texr1);
                                        SDL_RenderCopy( m_renderer, myTexture2, NULL, &texr3);
                                        SDL_RenderCopy( m_renderer, myTexture1, NULL, &texr1);
                                         texture(m_renderer,x1,y1,player1.power.c_str(),92,115);
                                         texture(m_renderer,x2,y2,player2.power.c_str(),92,115);
                                           texture(m_renderer,x,y,"ball1.gif",34,34);
                                        SDL_RenderCopy( m_renderer, myTexture6, NULL, &texr1);
                                        SDL_RenderCopy( m_renderer, myTexture7, NULL, &texr2);
                                        SDL_RenderPresent(m_renderer);
                                        SDL_Delay(25);
                                        SDL_RenderClear(m_renderer);
                                        dy3+=1;
                                        y3+=dy3;
                                    }
                                     x=300,dx=0,y=50,dy=0;
                                     powerOfplayer1+=30;
                                     x1=200;
                                     y1=345;
                                     x2=909;
                                     y2=345;
                                     dy1=0;
                                     dy2=0;
                                     dx1=0;
                                     dx2=0;
                                     playergoa2++;
                                     player2.goal++;
                                 }
                                 else if(x>=1130 && y>300){
                                     Mix_PlayChannel(-1,goalCHeer,0);
                                     powerOfplayer2+=30;
                                      int jumpnumber=0;
                                      y3=0;
                                     int dy3;
                                     while (jumpnumber<21) {
                                        if (y3==0){
                                            dy3=-5;
                                            jumpnumber+=1;
                                        }
                                        SDL_Rect texr3;
                                        texr3.x = 0;
                                        texr3.y = y3;
                                        texr3.w = 1200;
                                        texr3.h = 600;
                                        SDL_RenderCopy( m_renderer, myTexture8, NULL, &texr1);
                                        SDL_RenderCopy( m_renderer, myTexture2, NULL, &texr3);
                                        SDL_RenderCopy( m_renderer, myTexture1, NULL, &texr1);
                                         texture(m_renderer,x1,y1,player1.power.c_str(),92,115);
                                         texture(m_renderer,x2,y2,player2.power.c_str(),92,115);
                                         texture(m_renderer,x,y,"ball1.gif",34,34);
                                        SDL_RenderCopy( m_renderer, myTexture6, NULL, &texr1);
                                        SDL_RenderCopy( m_renderer, myTexture7, NULL, &texr2);
                                        SDL_RenderPresent(m_renderer);
                                        SDL_Delay(25);
                                        SDL_RenderClear(m_renderer);
                                        dy3+=1;
                                        y3+=dy3;
                                    }
                                     x=866,dx=0,y=50,dy=0;
                                     x1=200;
                                     y1=345;
                                     x2=909;
                                     y2=345;
                                     dy1=0;
                                     dy2=0;
                                     dx1=0;
                                     dx2=0;
                                     playergoal++;
                                     player1.goal++;
                                 }
                                 ////////////////////////////////////////////
                                 SDL_PumpEvents();
                                const Uint8 *e1=SDL_GetKeyboardState(NULL);
                                /////////////////////////////////////////////  cheat code
                                if (e1 [SDL_SCANCODE_F] ){
                                    powerOfplayer1+=10;
                                }
                                if (e1 [SDL_SCANCODE_H] ){
                                    powerOfplayer2+=10;
                                }
                                if (e1 [SDL_SCANCODE_G] ){
                                    s+=3;
                                }
//                                if (e1 [SDL_SCANCODE_R] ){
//                                   dx1P++;
//                                }
//                                if (e1 [SDL_SCANCODE_Y] ){
//                                   dx2P++;
//                                }
//                                if (e1 [SDL_SCANCODE_C] ){
//                                   dx1P--;
//                                }
//                                if (e1 [SDL_SCANCODE_B] ){
//                                   dx2P--;
//                                }
                                 ////////////////////////////////////////////////////////////////////////////////////////////// KEYS P1   ***
                                    dx1=0;
                              if(freazPlayer1==false){
                                if (e1 [SDL_SCANCODE_W] && y1==345){
                                    dy1=-28;
                                }
                                if (e1[SDL_SCANCODE_D]  && x2-x1>75 &&   cloneOfplayer2==false  &&  cloneOfplayer1==false) {
                                    x1 = x1 +10 +dx1P;
                                    dx1=10+dx1P;
                                }
                                else if (e1[SDL_SCANCODE_D] && x2-x1>287 && (cloneOfplayer2==true || cloneOfplayer1==true)) {
                                    x1 = x1 +10 +dx1P;
                                    dx1=10+dx1P;
                                }
                                if (e1[SDL_SCANCODE_A] && x1>30 ) {
                                    x1=x1 - 10 - dx1P;
                                    dx1=-10-dx1P;
                                }
                                if (e1[SDL_SCANCODE_E]){
                                    if(x-x1>=45 && x-x1<130)
                                         if(y-y1>30 && y-y1<140){
                                            dx+=12;
                                            dy-=15;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                    if(cloneOfplayer1==true){
                                       if(x-xc1>=45 && x-xc1<130)
                                         if(y-y1>30 && y-y1<140){
                                            dx+=12;
                                            dy-=15;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                       if(x-xc2>=45 && x-xc2<130)
                                         if(y-y1>30 && y-y1<140){
                                            dx+=12;
                                            dy-=15;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                     }
                                 }
                                if (e1[SDL_SCANCODE_Q]){
                                     if(x-x1>=45 && x-x1<130)
                                         if(y-y1>30 && y-y1<130){
                                            dx+=17;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                    if(cloneOfplayer1==true){
                                       if(x-xc1>=45 && x-xc1<130)
                                         if(y-y1>30 && y-y1<140){
                                            dx+=17;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                       if(x-xc2>=45 && x-xc2<130)
                                         if(y-y1>30 && y-y1<140){
                                            dx+=17;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                     }
                                 }
                                if (e1[SDL_SCANCODE_S] && powerOfplayer1==100){
                                    if(I[x4].power=="Chris")       {// kick fire ball
                                      if(x-x1>=45 && x-x1<130)
                                         if(y-y1>30 && y-y1<140){
                                          Mix_PlayChannel(-1,shootsound,0);
                                            dx=85;
                                           powerOfplayer1=0;
                                         }

                                    }
                                    else if(I[x4].power=="Leo")    {// invisible ball
                                         if(x-x1>=45 && x-x1<130)
                                         if(y-y1>30 && y-y1<140){
                                          Mix_PlayChannel(-1,shootsound,0);
                                          invisibleBall=true;
                                          s3=time(NULL);
                                         dx= 36;
                                         dy=-28;
                                         powerOfplayer1=0;
                                         }
                                    }
                                    else if(I[x4].power=="Juni")   {// Triple clone
                                         s4=time(NULL);
                                         cloneOfplayer1=true;
                                         s4=time(NULL);
                                         powerOfplayer1=0;
                                    }
                                    else if(I[x4].power=="Ibra")   {// Head fire ball
                                      if(x-x1>=45 && x-x1<200){
                                        Mix_PlayChannel(-1,shootsound,0);
                                        x1=x-120;
                                        y1=y+81;
                                        dx=(1130-x)/8;
                                        dy=(400-y) /8;
                                        powerOfplayer1=0;
                                      }
                                    }
                                    else if(I[x4].power=="Dima")   {// Punch
                                         punchPlayer1=true;
                                        xPunch=x1+46;
                                        yPunch=y1+40;
                                        powerOfplayer1=0;
                                    }

                                 }
                                }
                                 ///////////////////////////////////////////////////////////////////////////////////////////   KEYS P2  ***
                                 dx2=0;
                               if(freazPlayer2==false){
                                if (e1[SDL_SCANCODE_I] && y2==345 ) {
                                    dy2=-28;
                                }
                                if (e1[SDL_SCANCODE_L] && x2<1078 ) {
                                        x2+=10+dx2P;
                                        dx2=10+dx2P;
                                }
                                if (e1[SDL_SCANCODE_J] && x2-x1>75 && cloneOfplayer1==false && cloneOfplayer2==false){
                                        x2-=(10+dx2P);
                                        dx2=-10-dx2P;
                                }
                                if (e1[SDL_SCANCODE_J] && x2-x1>287&&  (cloneOfplayer1==true || cloneOfplayer2==true) ){
                                        x2-=(10+dx2P);
                                        dx2=-10-dx2P;
                                }
                                if (e1[SDL_SCANCODE_O]){
                                     if(x2-x>=0 && x2-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            dx-=12;
                                            dy-=15;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                     if(cloneOfplayer2==true){
                                        if(xd1-x>=0 && xd1-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            dx-=12;
                                            dy-=15;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                      if(xd2-x>=0 && xd2-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            dx-=12;
                                            dy-=15;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                     }
                                 }
                                if (e1[SDL_SCANCODE_U]){
                                     if(x2-x>=0 && x2-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            dx-=17;
                                            Mix_PlayChannel(-1,shootsound,0);
                                              }
                                    if(cloneOfplayer2==true){
                                        if(xd1-x>=0 && xd1-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            dx-=17;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                      if(xd2-x>=0 && xd2-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            dx-=17;
                                            Mix_PlayChannel(-1,shootsound,0);
                                         }
                                     }
                                 }
                                if (e1[SDL_SCANCODE_K] && powerOfplayer2 == 100){
                                    if(I[y4].power=="Chris")       {// kick fire ball
                                        if(x2-x>=0 && x2-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            Mix_PlayChannel(-1,shootsound,0);
                                            dx=-85;
                                            powerOfplayer2=0;
                                         }

                                    }
                                    else if(I[y4].power=="Leo")    {// invisible ball
                                        if(x2-x>=0 && x2-x<60)
                                         if(y-y2>30 && y-y2<130){
                                            Mix_PlayChannel(-1,shootsound,0);
                                            dx=-36;
                                            dy=-28;
                                            invisibleBall=true;
                                            s3=time(NULL);
                                            powerOfplayer2=0;
                                         }
                                    }
                                    else if(I[y4].power=="Juni")   {// Triple clone
                                        cloneOfplayer2=true;
                                        powerOfplayer2=0;
                                        s4=time(NULL);
                                    }
                                    else if(I[y4].power=="Ibra")   {// Head fire ball
                                            if(x2-x>=0 && x2-x<150){
                                            Mix_PlayChannel(-1,shootsound,0);
                                             x2=x+52;
                                             y2=y+81;
                                             dx=(70-x) /8;
                                             dy=(400-y)/8;
                                             powerOfplayer2=0;
                                         }

                                    }
                                    else if(I[y4].power=="Dima")   {// Punch
                                     punchPlayer2=true;
                                        xPunch=x2+46;
                                        yPunch=y2+40;
                                    powerOfplayer2=0;
                                    }
                                 }
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if ((SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                        cout<< xmouse<<endl;
                                        cout<< ymouse<<endl;
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                SDL_Rect texr3;
                                texr3.x = 0;
                                texr3.y = y3;
                                texr3.w = 1200;
                                texr3.h = 600;
                                SDL_RenderCopy( m_renderer, myTexture8, NULL, &texr1);
                                SDL_RenderCopy( m_renderer, myTexture2, NULL, &texr3);
                                SDL_RenderCopy( m_renderer, myTexture1, NULL, &texr1);
                                //////////////////////////////////////////////////////
                                texture(m_renderer,x1,y1,player1.power.c_str(),92,115);
                                if(cloneOfplayer1==true){
                                     xc1=x1+212;
                                     xc2=x1-212;
                                texture(m_renderer,xc1,y1,player1.power.c_str(),92,115);
                                texture(m_renderer,xc2,y1,player1.power.c_str(),92,115);
                                //cout<<"FUCKKKKKKKKKKKK"<<endl;
                                }
                                ////////////////////////
                                texture(m_renderer,x2,y2,player2.power.c_str(),92,115);
                                if(cloneOfplayer2==true){
                                     xd1=x2+212;
                                     xd2=x2-212;
                                texture(m_renderer,x2-212,y2,player2.power.c_str(),92,115);
                                texture(m_renderer,x2+212,y2,player2.power.c_str(),92,115);
                                 //cout<<"FUCKKKKKKKKKKKKb"<<endl;
                                }
                                //////////////////////////////////////////////////////
                                if(invisibleBall==false)
                                texture(m_renderer,x,y,"ball1.gif",34,34);
                                 //////////////////////////////////////////////////////
                                if(punchPlayer1==true){
                                 texture(m_renderer,xPunch,yPunch,"punchtoright.gif",60,50);
                                 xPunch+=15;
                                 if(xPunch>x2-30){
                                   s5=time(NULL);
                                   punchPlayer1=false;
                                   freazPlayer2=true;
                                 }
                                }
                                if(punchPlayer2==true){
                                 texture(m_renderer,xPunch,yPunch,"punchtoleft.gif",60,50);
                                 xPunch-=15;
                                 if(xPunch<x1+62){
                                  s5=time(NULL);
                                 punchPlayer2=false;
                                 freazPlayer1=true;
                                 }
                                }
                                //////////////////////////////////////////////////////
                                SDL_RenderCopy( m_renderer, myTexture6, NULL, &texr1);
                                SDL_RenderCopy( m_renderer, myTexture7, NULL, &texr2);
                                  /////////////////////////////////////////////////////////////////////////////////////////////// unfreezing
                                 if( freazPlayer1== true || freazPlayer2 == true ){
                                  dizz++;
                                  if(dizz<15){
                                    dizzez="dizz1.gif";
                                  }
                                  else if(dizz<30){
                                    dizzez="dizz2.gif";
                                  }
                                  else if(dizz<45){
                                    dizzez="dizz3.gif";
                                  }
                                  else if(dizz<60){
                                    dizzez="dizz2.gif";
                                  }
                                  else{
                                     dizz=0;
                                  }
                                  /////////////////////////////
                                  if(time(NULL)-s5>5){
                                   freazPlayer1=false;
                                   freazPlayer2=false;
                                  }
                                 ///////////////////////////////////////////////////// texture of freezing
                                 if(freazPlayer1== true){
                                  texture(m_renderer,x1,y1-25,dizzez.c_str(),92,30);
                                 }
                                 if(freazPlayer2== true){
                                  texture(m_renderer,x2,y2-25,dizzez.c_str(),92,30);
                                 }
                                 }
                                ///////////////////////////////////////////////////////
                                if(time(NULL)-s3==5){
                                 //cout<< "fuckyou" <<endl;
                                 freazPlayer1=false;
                                 freazPlayer2=false;
                                 invisibleBall=false;
                                }
                                if(time(NULL)-s4==8){
                                //cout<< "fuckyou555" <<endl;
                                cloneOfplayer1=false;
                                cloneOfplayer2=false;
                                }
                                /////////////////////////////////////////////////////////////////////////////////////////////////////
                                if(powerOfplayer1>100)
                                    powerOfplayer1=100;
                                if(powerOfplayer2>100)
                                    powerOfplayer2=100;
                                ///////////
                                rect(m_renderer,195,4,int(255.0*(double(powerOfplayer1)/100.0)),47,50,233,40,1);
                                rect(m_renderer,1005-int(255.0*double(powerOfplayer2)/100.0),4,int(255.0*double(powerOfplayer2)/100.0),47,50,233,40,1);
                                //////////
                                textFont(m_renderer,573,69,time1.c_str (),"digital-7.ttf",50,textco);
                                ///////
                                goalOfmacth="0";
                                goalOfmacth+=to_string(playergoal);
                                textFont(m_renderer,496,12, goalOfmacth.c_str () ,"digital-7.ttf",50,textco);
                                ////////
                                goalOfmacth="0";
                                goalOfmacth+=to_string(playergoa2);
                                textFont(m_renderer,654,12, goalOfmacth.c_str () ,"digital-7.ttf",50,textco);
                                /////////////
                                textFont(m_renderer,295,60, player1.name.c_str () ,"digital-7.ttf",50,textco);
                                textFont(m_renderer,750,60, player2.name.c_str () ,"digital-7.ttf",50,textco);

                               //////////////////////////////////////////////////////////////////////////////////////////////////player2 touch *********
                                if (abs(dx- dx2)>abs(x-x2-82) &&  y-y2<115 && y-y2>=20 && x-x2>82) {
                                    x=x2+82;
                                    cout<<"zarta"<<endl;
                                }
                                else if (abs(dx-dx2)>abs(x-x2-24) &&  y-y2<115 && y-y2>=20 && x-x2<-24) {
                                     if(dx>48)
                                        firefreez=true;
                                    x=x2-24;
                                    cout<<"zartd"<<endl;
                                }
                                if (x>=x2+29 && x<x2+82 &&  y-y2<115 && y-y2>=20) {
                                    x=x2+83;
                                    dx=12;
                                    Mix_PlayChannel(-1,shootsound,0);
                                    cout<<"zartb"<<endl;
                                }
                                else if (x-x2<29 && x-x2>-24 &&  y-y2<115 && y-y2>=20) {
                                   x=x2-25;
                                   dx=-12;
                                   Mix_PlayChannel(-1,shootsound,0);
                                   cout<<"zartc"<<endl;
                                }
                                if((x-x2)<=82 && (x-x2)>=-24) {
                                      if(y-y2<115 && y-y2>=20)
                                      {
                                        Mix_PlayChannel(-1,shootsound,0);
                                        if (dx2==0 && dx<0  && x2<= x-82 ) {
                                            dx=-3*(dx)/7;
                                            cout<<"zart"<<endl;
                                        }
                                        else if (dx2==0 && dx>0  && x2>=x+24 ){
                                            dx=-3*(dx)/7;

                                            cout<<"zart2"<<endl;
                                        }
                                        else if (dx*dx2>0) {
                                            dx =(dx+(dx2/5));
                                            cout<<"zart3"<<endl;
                                        }
                                        else if (dx2>0 && dx<0 && x2<=x-82 ) {
                                            dx=-4*(dx+(dx2/5))/7;
                                            cout<<"zart4"<<endl;
                                        }
                                        else if (dx>0 && dx2<0 && x2>=x+24 ) {
                                            dx=-4*(dx+(dx2/5))/7;
                                            cout<<"zart5"<<endl;
                                        }
                                        else if (dx==0 && dx2!=0 && (x2<=x-82 || x2>x+24 )) {
                                            dx=dx2;
                                            cout<<"zart6"<<endl;
                                        }
                                      }
                                }
                                if(firefreez==true){
                                 firefreez=false;
                                 freazPlayer2=true;
                                 s5=time(NULL);
                                 x2+=120;
                                }
                                 ///////////////////////////////////////////////////////////////////// clones
                                 if(cloneOfplayer2==true){
                                    ///////////////////////////////////////////
                                    if (abs(dx- dx2)>abs(x-xd1-82) &&  y-y2<115 && y-y2>=20 && x-xd1>82) {
                                    x=xd1+82;
                                    cout<<"zarta"<<endl;
                                }
                                else if (abs(dx-dx2)>abs(x-xd1-24) &&  y-y2<115 && y-y2>=20 && x-xd1<-24){
                                    x=xd1-24;
                                    cout<<"zartd"<<endl;
                                }
                                if (x>=xd1+29 && x<xd1+82 &&  y-y2<115 && y-y2>=20) {
                                    x=xd1+83;
                                    dx=12;
                                    Mix_PlayChannel(-1,shootsound,0);
                                    cout<<"zartb"<<endl;
                                }
                                else if (x-xd1<29 && x-xd1>-24 &&  y-y2<115 && y-y2>=20) {
                                   x=xd1-25;
                                   dx=-12;
                                   Mix_PlayChannel(-1,shootsound,0);
                                   cout<<"zartc"<<endl;
                                }
                                if((x-xd1)<=82 && (x-xd1)>=-24) {
                                      if(y-y2<115 && y-y2>=20)
                                      {
                                        Mix_PlayChannel(-1,shootsound,0);
                                        if (dx2==0 && dx<0  && xd1<= x-82 ) {
                                            dx=-3*(dx)/7;
                                            cout<<"zart"<<endl;
                                        }
                                        else if (dx2==0 && dx>0  && xd1>=x+24 ){
                                            dx=-3*(dx)/7;

                                            cout<<"zart2"<<endl;
                                        }
                                        else if (dx*dx2>0) {
                                            dx =(dx+(dx2/5));
                                            cout<<"zart3"<<endl;
                                        }
                                        else if (dx2>0 && dx<0 && xd1<=x-82 ) {
                                            dx=-4*(dx+(dx2/5))/7;
                                            cout<<"zart4"<<endl;
                                        }
                                        else if (dx>0 && dx2<0 && xd1>=x+24 ) {
                                            dx=-4*(dx+(dx2/5))/7;
                                            cout<<"zart5"<<endl;
                                        }
                                        else if (dx==0 && dx2!=0 && (xd1<=x-82 || xd1>x+24 )) {
                                            dx=dx2;
                                            cout<<"zart6"<<endl;
                                        }
                                      }
                                }
                                    //////////////////////////////////////////
                                     if (abs(dx- dx2)>abs(x-xd2-82) &&  y-y2<115 && y-y2>=20 && x-xd2>82) {
                                    x=xd2+82;
                                    cout<<"zarta"<<endl;
                                }
                                else if (abs(dx-dx2)>abs(x-xd2-24) &&  y-y2<115 && y-y2>=20 && x-xd2<-24) {
                                    x=xd2-24;
                                    cout<<"zartd"<<endl;
                                }
                                if (x>=xd2+29 && x<xd2+82 &&  y-y2<115 && y-y2>=20) {
                                    x=xd2+83;
                                    dx=12;
                                    Mix_PlayChannel(-1,shootsound,0);
                                    cout<<"zartb"<<endl;
                                }
                                else if (x-xd2<29 && x-xd2>-24 &&  y-y2<115 && y-y2>=20) {
                                   x=xd2-25;
                                   dx=-12;
                                   Mix_PlayChannel(-1,shootsound,0);
                                   cout<<"zartc"<<endl;
                                }
                                if((x-xd2)<=82 && (x-xd2)>=-24) {
                                      if(y-y2<115 && y-y2>=20)
                                      {
                                        Mix_PlayChannel(-1,shootsound,0);
                                        if (dx2==0 && dx<0  && xd2<= x-82 ) {
                                            dx=-3*(dx)/7;
                                            cout<<"zart"<<endl;
                                        }
                                        else if (dx2==0 && dx>0  && xd2>=x+24 ){
                                            dx=-3*(dx)/7;

                                            cout<<"zart2"<<endl;
                                        }
                                        else if (dx*dx2>0) {
                                            dx =(dx+(dx2/5));
                                            cout<<"zart3"<<endl;
                                        }
                                        else if (dx2>0 && dx<0 && xd2<=x-82 ) {
                                            dx=-4*(dx+(dx2/5))/7;
                                            cout<<"zart4"<<endl;
                                        }
                                        else if (dx>0 && dx2<0 && xd2>=x+24 ) {
                                            dx=-4*(dx+(dx2/5))/7;
                                            cout<<"zart5"<<endl;
                                        }
                                        else if (dx==0 && dx2!=0 && (xd2<=x-82 || xd2>x+24 )) {
                                            dx=dx2;
                                            cout<<"zart6"<<endl;
                                        }
                                      }
                                }
                                    //////////////////////////////////////////
                                 }
                                 ///////////////////////////////////////////////////////////////////////////////////////////////////player2 heading
                                if ((dy-dy2)>abs(y-y2-22) && (x-x2)<=70 && (x-x2)>=-12 && y != y2-22) {
                                    y=y2-22;
                                }
                                if(abs(y-y2)<=22 && (x-x2)<=70 && (x-x2)>=-12){
                                        Mix_PlayChannel(-1,shootsound,0);
                                    if (dy2==0){
                                            dy*=-1;
                                        }
                                        if (dy*dy1>0) {
                                            dy =-(dy-(dy1));
                                        }
                                        if (dy*dy2<0) {
                                            dy=-5*(dy-(dy2))/7;
                                        }
                                        if (dy==0) {
                                            dy=2*dy2;
                                        }
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////player1 touch ******
                                if (abs(dx- dx1)>abs(x-x1-82) &&  y-y1<115 && y-y1>=20 && x-x1>82) {
                                    if(dx<-48)
                                        firefreez=true;
                                    x=x1+82;
                                    cout<<"zarta"<<endl;
                                }
                                else if (abs(dx-dx1)>abs(x-x1-24) &&  y-y1<115 && y-y1>=20 && x-x1<-24) {
                                    x=x1-24;
                                    cout<<"zartd"<<endl;
                                }
                                if (x>=x1+29 && x<x1+82 &&  y-y1<115 && y-y1>=20) {
                                    x=x1+83;
                                    dx=12;
                                    Mix_PlayChannel(-1,shootsound,0);
                                    cout<<"zartb"<<endl;
                                }
                                else if (x-x1<29 && x-x1>-24 &&  y-y1<115 && y-y1>=20) {
                                   x=x1-25;
                                   dx=-12;
                                   Mix_PlayChannel(-1,shootsound,0);
                                   cout<<"zartc"<<endl;
                                }
                                if((x-x1)<=82 && (x-x1)>=-24) {
                                      if(y-y1<115 && y-y1>=20)
                                      {
                                        Mix_PlayChannel(-1,shootsound,0);
                                        if (dx1==0 && dx<0  && x1<= x-82 ) {
                                            dx=-3*(dx)/7;
                                            cout<<"zart"<<endl;
                                        }
                                        else if (dx1==0 && dx>0  && x1>=x+24 ){
                                            dx=-3*(dx)/7;
                                            cout<<"zart2"<<endl;
                                        }
                                        else if (dx*dx1>0) {
                                            dx =(dx+(dx1/5));
                                            cout<<"zart3"<<endl;
                                        }
                                        else if (dx1>0 && dx<0 && x1<=x-82 ) {
                                            dx=-4*(dx+(dx1/5))/7;
                                            cout<<"zart4"<<endl;
                                        }
                                        else if (dx>0 && dx1<0 && x1>=x+24 ) {
                                            dx=-4*(dx+(dx1/5))/7;
                                            cout<<"zart5"<<endl;
                                        }
                                        else if (dx==0 && dx1 !=0 && (x1<=x-82 || x1>x+24 )) {
                                            dx=dx1;
                                            cout<<"zart6"<<endl;
                                        }
                                      }
                                }
                                     if(firefreez==true){
                                      firefreez=false;
                                      freazPlayer1=true;
                                      s5=time(NULL);
                                      x1-=120;
                                      }
                                       //////////////////////////////////////////////////////////////////////////////////////////////////// clones
                        if(cloneOfplayer1==true){
                                       if (abs(dx- dx1)>abs(x-xc1-82) &&  y-y1<115 && y-y1>=20 && x-xc1>82) {
                                    x=xc1+82;
                                    cout<<"zarta"<<endl;
                                }
                                else if (abs(dx-dx1)>abs(x-xc1-24) &&  y-y1<115 && y-y1>=20 && x-xc1<-24) {
                                    x=xc1-24;
                                    cout<<"zartd"<<endl;
                                }
                                if (x>=xc1+29 && x<xc1+82 &&  y-y1<115 && y-y1>=20) {
                                    x=xc1+83;
                                    dx=12;
                                    Mix_PlayChannel(-1,shootsound,0);
                                    cout<<"zartb"<<endl;
                                }
                                else if (x-xc1<29 && x-xc1>-24 &&  y-y1<115 && y-y1>=20) {
                                   x=xc1-25;
                                   dx=-12;
                                   Mix_PlayChannel(-1,shootsound,0);
                                   cout<<"zartc"<<endl;
                                }
                                if((x-xc1)<=82 && (x-xc1)>=-24) {
                                      if(y-y1<115 && y-y1>=20)
                                      {
                                        Mix_PlayChannel(-1,shootsound,0);
                                        if (dx1==0 && dx<0  && xc1<= x-82 ) {
                                            dx=-3*(dx)/7;
                                            cout<<"zart"<<endl;
                                        }
                                        else if (dx1==0 && dx>0  && xc1>=x+24 ){
                                            dx=-3*(dx)/7;
                                            cout<<"zart2"<<endl;
                                        }
                                        else if (dx*dx1>0) {
                                            dx =(dx+(dx1/5));
                                            cout<<"zart3"<<endl;
                                        }
                                        else if (dx1>0 && dx<0 && xc1<=x-82 ) {
                                            dx=-4*(dx+(dx1/5))/7;
                                            cout<<"zart4"<<endl;
                                        }
                                        else if (dx>0 && dx1<0 && xc1>=x+24 ) {
                                            dx=-4*(dx+(dx1/5))/7;
                                            cout<<"zart5"<<endl;
                                        }
                                        else if (dx==0 && dx1 !=0 && (xc1<=x-82 || xc1>x+24 )) {
                                            dx=dx1;
                                            cout<<"zart6"<<endl;
                                        }
                                      }
                                }
                                /////////////////////////////////////////////////////////////////////////////////////////////////////////clone change
                                if (abs(dx- dx1)>abs(x-xc2-82) &&  y-y1<115 && y-y1>=20 && x-xc2>82) {
                                    x=xc2+82;
                                    cout<<"zarta"<<endl;
                                }
                                else if (abs(dx-dx1)>abs(x-xc2-24) &&  y-y1<115 && y-y1>=20 && x-xc2<-24) {
                                    x=xc2-24;
                                    cout<<"zartd"<<endl;
                                }
                                if (x>=xc2+29 && x<xc2+82 &&  y-y1<115 && y-y1>=20) {
                                    x=xc2+83;
                                    dx=12;
                                    Mix_PlayChannel(-1,shootsound,0);
                                    cout<<"zartb"<<endl;
                                }
                                else if (x-xc2<29 && x-xc2>-24 &&  y-y1<115 && y-y1>=20) {
                                   x=xc2-25;
                                   dx=-12;
                                   Mix_PlayChannel(-1,shootsound,0);
                                   cout<<"zartc"<<endl;
                                }
                                if((x-xc2)<=82 && (x-xc2)>=-24) {
                                      if(y-y1<115 && y-y1>=20)
                                      {
                                        Mix_PlayChannel(-1,shootsound,0);
                                        if (dx==0 && dx<0  && xc2<= x-82 ) {
                                            dx=-3*(dx)/7;
                                            cout<<"zart"<<endl;
                                        }
                                        else if (dx1==0 && dx>0  && xc2>=x+24 ){
                                            dx=-3*(dx)/7;
                                            cout<<"zart2"<<endl;
                                        }
                                        else if (dx*dx1>0) {
                                            dx =(dx+(dx1/5));
                                            cout<<"zart3"<<endl;
                                        }
                                        else if (dx1>0 && dx<0 && xc2<=x-82 ) {
                                            dx=-4*(dx+(dx1/5))/7;
                                            cout<<"zart4"<<endl;
                                        }
                                        else if (dx>0 && dx1<0 && xc2>=x+24 ) {
                                            dx=-4*(dx+(dx1/5))/7;
                                            cout<<"zart5"<<endl;
                                        }
                                        else if (dx==0 && dx1 !=0 && (xc2<=x-82 || xc2>x+24 )) {
                                            dx=dx1;
                                            cout<<"zart6"<<endl;
                                        }
                                      }
                                }
                                ////////////////////////////////////////////////////////////////////////////////////////////////////
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////// player 1 heading
                                if ((dy-dy1)>abs(y-y1-22) && (x-x1)<=70 && (x-x1)>=-12 && y != y1-22) {
                                    y=y1-22;
                                }
                                if(abs(y-y1-22)<=22 && (x-x1)<=70 && (x-x1)>=-12){
                                       if (dy1==0){
                                            dy*=-1;
                                        }
                                        if (dy*dy1>0) {
                                            dy =-(dy-(dy1));
                                        }
                                        if (dy*dy1<0) {
                                            dy=-5*(dy-(dy1))/7;
                                        }
                                        if (dy==0) {
                                            dy=2*dy1;
                                        }
                                         Mix_PlayChannel(-1,shootsound,0);
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////////////////// jump *****
                                y1=y1+dy1;
                                y2=y2+dy2;
                                if (y1<345){
                                    dy1=dy1+4;
                                }
                                else {
                                    dy1=0;
                                    y1=345;
                                }
                                if (y2<345){
                                    dy2=dy2+4;
                                }
                                else {
                                    dy2=0;
                                    y2=345;
                                }
                                /////////////////////////////////////////////////// WALL  ***
                                    if (y<=17){
                                        if ( (dy) < 0){
                                        y=0;
                                        dy=-6*dy/7;
                                    }
                                    }
                                    if (y>426){
                                        if ( (dy) >0){
                                            y=426;
                                          dy =-6*dy/7;
                                    }
                                    }
                                    if (x<=70){
                                        if (dx<0 && y<300 ){
                                            x=70;
                                            if(y>200)
                                               Mix_PlayChannel(-1,woodwork,0);
                                       cout<<"zooooort"<<endl;
                                      dx=-6*dx/7;
                                    }
                                    }
                                    if (x>=1096){
                                        if ((dx)>0 && y<300 ){
                                            x=1096;
                                            if(y>200)
                                             Mix_PlayChannel(-1,woodwork,0);
                                        cout<<"zooooort1"<<endl;
                                    dx =-6*dx/7;
                                    }
                                    }
                                    ///////////////////////////////////////////////////////////////////////// ball move    ***
                                    if((y>422)&&((dy<=8)&&(dy>=-8))) {
                                    if(dx<1 && dx>-1){
                                        dx=0;
                                        cout<<"zooort2"<<endl;
                                    }
                                    else if(dx>0) {
                                        dx =dx -1 ;
                                        x+=dx;
                                        cout<<"zooort3"<<endl;
                                    }
                                    else if (dx<0) {
                                        dx =dx +1 ;
                                         x+=dx;
                                         cout<<"zoooort4"<<endl;
                                    }
                                    }
                                    else {
                                    x+=dx;
                                    dy+=3;
                                    y+=dy;
                                   }
                                //////////////////////////////////////////////////////////////////////////////////////////////////  Prize   *****



                                //////////////////////////////////////////////////////////////////////////////////////////////////  Render  *****
                                cout<<endl;
                                cout<<dx<<"***"<<dy<<endl;
                                SDL_RenderPresent(m_renderer);
                                /////////////////////////////////////////////////////////////////////////////////////////////////// pause   *****
                                if (e1[SDL_SCANCODE_ESCAPE]) {
                                        Mix_PauseMusic();
                                        while (true){
                                texture(m_renderer,0,0,"pausemenu.gif",1200,600);
                                SDL_PumpEvents();
                                SDL_GetMouseState(&xmouse,&ymouse);
                                if ( (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                cout<<xmouse<<endl;
                                cout<< ymouse<<endl;
                                }
                                if ((xmouse<725 && xmouse>475 && ymouse<440 && ymouse>375)&& (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){        //exit
                                       Pauseplay=false;
                                       break;
                                }
                                else if ((xmouse<725 && xmouse>475 && ymouse<200 && ymouse>135)&& (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){   //resume
                                       if(Pausecheer==true)
                                       Mix_PlayMusic(playcheer,-1);
                                       s+=time(NULL)-s-s1;
                                       break;
                                }
                                else if ((xmouse<725 && xmouse>475 && ymouse<360 && ymouse>265)&& (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){   //mute
                                       if(Pausecheer==true){
                                        Pausecheer=false;
                                        s+=time(NULL)-s-s1;
                                       }
                                       else{
                                        Pausecheer=true;
                                        s+=time(NULL)-s-s1;
                                        Mix_PlayMusic(playcheer,-1);
                                       }
                                       cout<<"5555555"<<endl;
                                       break;
                                }
                                else if ((xmouse<725 && xmouse>475 && ymouse<280&& ymouse>215)&& (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){   // restart
                                      restartmatch=false;
                                       break;
                                  }
                                   SDL_RenderPresent(m_renderer);
                                   SDL_Delay(75);
                                  }
                                 //////////////////////////////////////////////////////////

                                 }
                                /////////////////////////////////////////////////////
                                if(restartmatch==false)
                                    break;
                                if(Pauseplay==false)
                                    break;
                                 /////////////////////////////////////////////////////
                                 timeOfel=SDL_GetTicks();
                                 if(timeOfel-timeOfsl<33)
                                    SDL_Delay(33-timeOfel+timeOfsl);
                                 /////////////////////////////////////////////////////
                                SDL_RenderClear(m_renderer);
                                }
                            /////////////////////////////////////////////////////////
                                if(matchResult==true){  ////////////////////  save information of match
                                 player1.power=player1.power.substr(0,player1.power.length()- 10 );
                                 player2.power=player2.power.substr(0,player2.power.length()- 9  );
                                I[x4]=player1;
                                I[y4]=player2;
                                }
                                if(Pauseplay==false){
                                  if(voiceOnOff==true){
                                    if(voiceCHange==true){
                                   Mix_PauseMusic();
                                   Mix_PlayMusic(back1s,-1);
                                 }
                                 else{
                                  Mix_PauseMusic();
                                  Mix_PlayMusic(back2s,-1);
                                 }
                                  }
                                  break;
                                }
                           ////////////////////////////////////////////////////////////

                ///////////////////////////////////////////////////////////////////////////////////////////////
                            if(Pauseplay==false)
                                    break;
                            }
                             ///////////////////////////////////////////////////
                                }
                                if(Pauseplay==false)
                                    break;
                             //////////////////////////////////////////////////// VAZIIYAT
                             }
                       /////////////////////////////////////////////// play menu
                            }
                            if(Pauseplay==false)
                                    break;
                       ///////////////////////////////////////////////player chose menu
                          }
                       ///////////////////////////////////////////////
                      if(Pauseplay==false)
                                    break;
                       ////////////////////////////////////////////////play
                    }
             }
             else if (xmouse<115 && xmouse>45 && ymouse<230 && ymouse>150 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {  // table *******
           ////////////////////////////////////////////
            for ( x3 = 0 ; x3 < int(num5+1) ; x3++ )
            for ( y3 = 0 ; y3 < int(num5+1)-x3-1 ; y3++ )
            if (I[y3].goal < I[y3+1].goal)
             {
            swap(I[y3+1].goal,I[y3].goal);
            swap(I[y3+1].name,I[y3].name);
            swap(I[y3+1].power,I[y3].power);
            swap(I[y3+1].win,I[y3].win);
            swap(I[y3+1].draw,I[y3].draw);
            swap(I[y3+1].loss,I[y3].loss);
            }
           //////////////////////////////////////////////
             SDL_Color txtocolor={0,0,0};
                bool loop=false;
                int dis1=27;
                int dis2=27;
                texture(m_renderer,0,0,"table.jpg",1200,600);
                texture(m_renderer,0,0,"back.jpg",50,50);
                SDL_RenderPresent(m_renderer);
                cout<<"2357"<<endl;
        while (true){
                SDL_PumpEvents();
                SDL_GetMouseState(&xmouse,&ymouse);
                if ((xmouse<50 && xmouse>0 && ymouse<50 && ymouse>0) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){    // back
                                Mix_PlayChannel(-1,clickSound,0);
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                                break;
                }
                if ( (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                    Mix_PlayChannel(-1,clickSound,0);
                    cout<< xmouse<<endl;
                    cout<< ymouse<<endl;
                }
                if(loop==false){
                    for ( x3 = 0 ; x3 < (num5) ; x3++ )
                    {
                        if (x3<=4){
                        dis1=dis1+84;
                        textFont(m_renderer,533,dis1,to_string(I[x3].goal).c_str(),"arial.ttf",40,txtocolor);
                        textFont(m_renderer,160,dis1,(I[x3].name).c_str(),"arial.ttf",40,txtocolor);
                        textFont(m_renderer,370,dis1,(I[x3].power).c_str(),"arial.ttf",40,txtocolor);
                        }
                        if (x3<=9 && x3>4) {
                        dis2=dis2+84;
                        textFont(m_renderer,1066,dis2,to_string(I[x3].goal).c_str(),"arial.ttf",40,txtocolor);
                        textFont(m_renderer,693,dis2,(I[x3].name).c_str(),"arial.ttf",40,txtocolor);
                        textFont(m_renderer,903,dis2,(I[x3].power).c_str(),"arial.ttf",40,txtocolor);
                        }
                    }
                    SDL_RenderPresent(m_renderer);
                    SDL_Delay(1);
                    SDL_RenderClear(m_renderer);
                    loop=true;
                    }
                }
            }
             else if (xmouse<115 && xmouse>45 && ymouse<345 && ymouse>260 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {  // help  *******
                int pagenum=1;
                while (true) {
                        SDL_PumpEvents();
                        SDL_GetMouseState(&xmouse,&ymouse);
                         if ( (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                          Mix_PlayChannel(-1,clickSound,0);
                          cout<<xmouse<<endl;
                          cout<< ymouse<<endl;
                         }
                        if ((xmouse<520 && xmouse>470 && ymouse<588 && ymouse>538) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                            pagenum=1;
                        }
                        else if ((xmouse<70 && xmouse>20 && ymouse<588 && ymouse>538) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                            pagenum=1;
                        }
                        else if ((xmouse<140  &&xmouse>90 && ymouse<588 && ymouse>538) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                            pagenum=2;
                        }
                        else if ((xmouse<210 && xmouse>160 && ymouse<588 && ymouse>538) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                            pagenum=3;
                        }
                        else if ((xmouse<300  && xmouse>230 && ymouse<588 && ymouse>538) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                            pagenum=4;
                        }
                        else if ((xmouse<60  && xmouse>10 && ymouse<60 && ymouse>10) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {
                            SDL_PumpEvents();
                            string page="HELP1";
                            string num1;
                            stringstream ss;
                            ss << pagenum;
                            ss >> num1;
                            cout<<pagenum;
                            page=page.substr(0,4)+num1+".jpg";
                            texture (m_renderer,0,0,page.c_str(),1200,600);
                            texture (m_renderer,20,538,"page1.gif",50,50);
                            texture (m_renderer , 90,538,"page2.gif",50,50);
                            texture (m_renderer ,160,538,"page3.gif",50,50);
                            texture (m_renderer ,230,538,"page4.gif",50,50);
                            texture(m_renderer,10,10,"back.jpg",50,50);
                            break;
                        }
                        string page="HELP1";
                        string num1;
                        stringstream ss;
                        ss << pagenum;
                        ss >> num1;
                        cout<<pagenum;
                        page=page.substr(0,4)+num1+".jpg";
                        texture (m_renderer,0,0,page.c_str(),1200,600);
                        texture (m_renderer,20,538,"page1.gif",50,50);
                        texture (m_renderer , 90,538,"page2.gif",50,50);
                        texture (m_renderer ,160,538,"page3.gif",50,50);
                        texture (m_renderer ,230,538,"page4.gif",50,50);
                        texture(m_renderer,10,10,"back.jpg",50,50);
                        SDL_RenderPresent(m_renderer);
                        SDL_Delay(1);
                        SDL_RenderClear(m_renderer);
                    }
            }
             else if (xmouse<115 && xmouse>45 && ymouse<460 && ymouse>370 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {  // set   *******


                   while (true) {
                        SDL_PumpEvents();
                        SDL_GetMouseState(&xmouse,&ymouse);


                        texture(m_renderer,0,0,settingstr.c_str(),1200,600);
                        texture(m_renderer,10,10,"back.jpg",50,50);
                        if ( (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                       Mix_PlayChannel(-1,clickSound,0);
                       cout<<xmouse<<endl;
                       cout<< ymouse<<endl;
                        }
                        if ((xmouse<60 && xmouse>10 && ymouse<60 && ymouse>10) && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){    // back
                                Mix_PlayChannel(-1,clickSound,0);
                                cout<< xmouse<<endl;
                                cout<< ymouse<<endl;
                                break;
                            }
                        else if (xmouse > 295 && xmouse<430 && ymouse<366 && ymouse>235 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {// mute
                                 if(voiceOnOff==true){  // mute
                                 settingstr="settingback2.jpg";
                                 voiceOnOff=false;
                                 Mix_PauseMusic();
                                     }
                                 else{                  // on
                                  voiceOnOff=true;
                                  settingstr="settingback1.jpg";
                                  if(voiceCHange==true)
                                  Mix_PlayMusic(back1s,-1);
                                  else
                                  Mix_PlayMusic(back2s,-1);
                                  }

                                break;
                        }
                        else if (xmouse > 735 && xmouse<870 && ymouse<366 && ymouse>235 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {// voice change
                        if(voiceCHange==true){
                                  voiceCHange=false;
                                   Mix_PauseMusic();
                                   Mix_PlayMusic(back2s,-1);
                                 }
                                 else{
                                 voiceCHange=true;
                                  Mix_PauseMusic();
                                  Mix_PlayMusic(back1s,-1);
                                 }

                                break;
                        }
                        SDL_RenderPresent(m_renderer);
                        SDL_Delay(1);
                        SDL_RenderClear(m_renderer);
                    }
             }
             else if (xmouse<115 && xmouse>45 && ymouse<565 && ymouse>485 && (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0) {  // exit  *******
                    while (true) {
                            //texture (m_renderer,0,0,"first back.jpg",1200,600);
                            texture(m_renderer,0,0,"exitpic.gif",1200,600);
                            SDL_PumpEvents();
                            SDL_GetMouseState(&xmouse,&ymouse);
                                if ( (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                Mix_PlayChannel(-1,clickSound,0);
                                cout<<xmouse<<endl;
                                cout<< ymouse<<endl;
                                }
                                if ((xmouse<495 && xmouse>435 && ymouse<346 && ymouse>309)&& (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                       exit1 = true;
                                       break;
                                }
                                else if ((xmouse<758 && xmouse>712 && ymouse<346 && ymouse>309)&& (SDL_GetMouseState(&xmouse,&ymouse)&& SDL_BUTTON_LMASK) !=0){
                                        //texture (m_renderer,0,0,"first back.jpg",1200,600);
                                       break;
                                }
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(1);
                                //SDL_RenderClear(m_renderer);
                    }
            }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SDL_RenderPresent( m_renderer );
        //SDL_RenderClear(m_renderer);
        if (exit1 == true){
            break;
        }
            etime=SDL_GetTicks();
            if ((etime-stime)<tdmenu){
            SDL_Delay(tdmenu+stime-etime);
            }

    }
 /////////////////////////////////////////////////////////////////////////  save information
              filename5="";
              short int num6 =0;
              ///////////////////////////////////////
             while(true){
             if(I[num6].goal==-1)
             break;
             filename5=to_string(num6);
             filename5+=".txt";
             ofstream f2(filename5.c_str());
             f2<<I[int(num6)].name<<endl;
             f2<<I[int(num6)].power<<endl;
             f2<<I[int(num6)].win<<endl;
             f2<<I[int(num6)].loss<<endl;
             f2<<I[int(num6)].draw<<endl;
             f2<<I[int(num6)].goal;
             f2.close();
             cout<<num6<<endl;
             num6++;
             }
   ///////////////////////////////////////////////////////////////////////

    SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;
}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian)
{

    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}

void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
        int n = addressOfImage.length();
        char char_array[n+1];

        strcpy(char_array, addressOfImage.c_str());
        SDL_Texture *myTexture;
        myTexture = IMG_LoadTexture( m_renderer, char_array);
        int w1, h1;
        SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = width;
        texr1.h = height;
        SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
            SDL_DestroyTexture(myTexture);
}

void textFont(SDL_Renderer *renderer,int x,int y,const char * text,const char * Font,int font_size,SDL_Color textColor)

{
    TTF_Init();

    int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    double angle = 0.0;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(Font, font_size );

    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont,text, textColor );

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
    SDL_FreeSurface( textSurface );


    SDL_Rect renderQuad = { x , y , mWidth, mHeight };
    SDL_RenderCopyEx( renderer, mTexture, clip, &renderQuad, angle, center, flip );

    SDL_DestroyTexture( mTexture );
    TTF_CloseFont(gFont);
    TTF_Quit();

}
void TextBox (SDL_Renderer* m_renderer,string name)
{
    SDL_Color col={255,255,255};
    bool caps_lock = false;
    int x_position=400;
    int y_position=300;
    int R=100;
    int G =100;
    int B=100;
    int A=0.5;
    int W = 370;
    int H = 200;
    bool quit = false ;
    char ch=0;
    textFont(m_renderer,x_position , y_position , "Enter your name :", "arial.ttf" , 24 , col);
    rectangleRGBA(m_renderer,x_position -10 , y_position -10 ,x_position +W+10 , y_position +H-10 ,R , G , B , 255);
    SDL_RenderPresent(m_renderer);
    y_position = 300;
    SDL_Event *event;
    while (!quit)
    {
        if(SDL_PollEvent(event))
        {
            if(event -> type == SDL_KEYUP)
            {
                switch(event->key.keysym.sym)
                {
                    case SDLK_SPACE:
                    quit = true;
                    break;
                    case SDLK_CAPSLOCK:
                    ch=0;
                    if(!caps_lock)
                    caps_lock = true;
                    else
                    caps_lock = false;
                    break;
                    case SDLK_BACKSPACE:
                    ch = 0;
                    if(name.length()!=0)
                    {
                    textFont (m_renderer,x_position +20 , y_position +H-105 , name.c_str(), "arial,ttf" , 24 , col);
                    name = name.substr(0,name.length()-1);
                    }
                    SDL_RenderPresent(m_renderer);
                    break;
                    default :
                    if(event->key.keysym.sym != SDLK_UP && event->key.keysym.sym != SDLK_DOWN && event->key.keysym.sym != SDLK_LEFT && event->key.keysym.sym != SDLK_RIGHT)
                    ch = event->key.keysym.sym;
                    break;
                }
                if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') && name.length()<25 && !quit)
                {
                    if(caps_lock )
                    name+=ch + 'A' - 'a';
                    else
                    name+=ch ;
                }
                if(name != "" && !quit)
                textFont(m_renderer,x_position +20 , y_position +H-105 , name.c_str(), "arial,ttf" , 24 , col);
            }
        }
    }
}



