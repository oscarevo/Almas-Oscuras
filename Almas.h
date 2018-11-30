#pragma once  //______________________________________ Almas.h  
#include "Resource.h"
#include "resource.h"
class Almas: public Game::Window
{
public:
	Almas()
	{
	}
	~Almas()
	{
	}
	wstring texto = L"Este juego está hecho por Oscar Eduardo Vázquez Pérez.\nAlgunos recursos utilizados en este juego no pertenecen al propio creador y solo han sido utilizados con fines académicos.\n\nEl código fuente de este programa esta en la siguiente pagina de github:\nhttps://github.com/oscarevo/Almas-Oscuras";

	//VARIABLE PRINCIPAL (pantalla)
	int pnt = 0;

	//PAUSA
	bool canPause = true;
	bool isPPressed = false;
	bool Pause = false;
	int Prea = 0;

	//........................................Pantalla Principal.........................................
	int a = 0;
	int b = 2;
	int ran;
	bool uso = true;
	CG::DDBitmap inicio[15];

	//..............................................Juego................................................
	int n = 0;				//posicion
	int plataforma[5][2];	//Plataforma
	CG::DDBitmap bitmap[130];
	CG::DDBitmap fuego[8];
	CG::DDBitmap jefe[64];
	CG::DDBitmap bolon[4];
	CG::DDBitmap explo[7];

	int estado = 0; //... es complicado...
	int tuto = 0;	//tutorial ... es menos complicado... pero sigue siendo complicado
	int tutoTimer = 0;
	int marca;		//distincion teclas x, z, c (prioridad)
	int nmax;		//cuadros de animacion maximos

	int cuadro, StaTim = 0, MovTim = 0; //cuadro general 
	int orientacion = 0;				//0-ri, 1-le
	int escudo = 0;						//escudo activo o no

	const int Unity = 32;		//Unidad Minima del Juego
	const int AltPnt = 512;		//Alto Pantalla
	const int AncPnt = 960;		//Ancho Pantalla
	const int AltBar = 16;		//Alto Barra
	const int AncBar = 256;		//Ancho Barra
	const int AltB = 96+32;		//Alto Boss
	const int AncB = 96+32;		//Ancho Boss
	const int AltP = 64;		//Alto Player
	const int AncP = 64;		//Ancho Player

	//boolean keys
	bool isLPressed = false;
	bool isRPressed = false;
	bool isUPressed = false;
	bool isZPressed = false;
	bool isXPressed = false;
	bool isCPressed = false;
	int repite = 0;
	int xr, cr, zr;

	//................................................Jugador............................................
	//Estadisticas generales
	float dC[2];	//DownColider
	float pP[2];	//PainPoint
	float hP[2];	//HurtPoint
	float x;		//x Posicion
	float y;		//y Posicion
	float c = 0;	//Maximo Salto

	const float Suelo = 64.0f;
	bool ImDead = false;
	bool YouDead = false;

	const float vfot = 190.0f;	//velocidad con escudo
	const float vrun = 250.0f;	//velocidad sin escudo
	float v = vfot;

	const float defS = 0.7f;	//defensa con escudo (reduccion de daño)
	const float defWs = 0.9f;	//defensa sin escudo
	const float defSu = 0.0f;	//defensa usando el escudo
	float def = defS;

	//tiempos animaciones //1 seg = 1000
	int GenTim = 0;
	int GenNum = 0;
	const int StaticTimer	= 200;
	const int MovingTimerS	= 250;
	const int ShieldChange	= 200;
	const int ShieldUse		= 150;
	const int AttackS		= 150;
	const int AttackwS		= 130;
	const int MagicCharge	= 180;
	const int SwordCharge	= 200;
	const int MagicMantein	= 100;
	const int SwordMantein	= 100;
	const int MagicRelease	=  30;
	const int SwordRelease	=  30;

	//Movimiento
	bool isStatic = true;
	bool isMoving = false;

	//Salto
	bool Gravity = true;
	bool canJump = true;
	bool isJumping = false;
	bool isOnTheGround = true;

	//Proteccion
	bool isShieldActive = true;

	//Cooldown daño
	bool playerCooldown = false;
	bool bossCooldown = false;

	//Daño
	bool lech = false;
	bool yourPain = false;
	bool myPain = false;
	int MpTim = 0;
	int flicker = 0;
	const int TpL = 3000;	//Total Player Life (3000)
	const int TbL = 15000;	//Total Boss Life	(15000)
	int pL;					//PlayerLife
	int bL;					//BossLife

	//Magia
	int f;
	int ff[2];
	int m = 0;
	int MagTim = 0;
	bool mRelease = false;
	float magia[2][2];
	int mV[2];
	float mC[2][2];
	int mCmC[2][2];

	//...........................................Boss...................................................
	float xB;		//Boss x position
	float yB;		//Boss y position

	//BossSpriteReal
	int real = 16;
	float rxB;
	float ryB;
	int rAnchoB;
	int rAltoB;

	//BossAtaqueHitbox
	int ata = 88;
	float axB;
	float ayB;
	int aAnchoB;
	int aAltoB;

	//Boss Ataque 3
	float bola[4][2];

	//Boss
	bool isBIAactive = true;
	bool Desicion = false;		//Si se a tomado una desicion
	bool timeDesicion = true;	//Hay tiempo para decidir?
	int BIAb = 1;
	int IA;
	float dis;
	const int BFPS = 120;
	bool exp = false;

	int bossy = 0;
	int ori = 0;
	int bol = 0;

	int r;
	int k = 0;
	int kmax;

	//.........................................FUNCIONES...............................................
	//Gargador de los Sprites
	void LoadSprites(void);

	//Destructor y Constructor de Botones (Respectivamente)														(Los nombres son chistes internos, muy malos por cierto)
	void Defenestrador(int n);
	void Catalizador(int n);

	bool RenderScene(CG::Gdi& gdi);
	const wchar_t * GetClassName(){return L"Almas";}
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button bt7;
	Win::Button bt1;
	Win::Button bt2;
	Win::Button bt4;
	Win::Button bt5;
	Win::Button bt6;
	Win::Textbox tbx1;
	Win::LevelControl lc1;
	Win::LevelControl lc2;
	Win::Button bt3;
	Win::Label lb1;
protected:
	Win::Gdi::Font fontArial009A;
	Win::Gdi::Font fontBaskerville_Old_Face012C;
	Win::Gdi::Font fontCentury_Schoolbook012B;
	Win::Gdi::Font fontConstantia016A;
	Win::Gdi::Font fontFootlight_MT_Light016A;
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.cx=Sys::Convert::CentimetersToScreenPixels(25.77042);
		createStruct.cy=Sys::Convert::CentimetersToScreenPixels(14.55208);
		createStruct.x=Sys::Convert::CentimetersToScreenPixels(5.29167);
		createStruct.y=Sys::Convert::CentimetersToScreenPixels(2.64583);
		createStruct.style = WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW | WS_THICKFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"Almas";
		bt7.CreateX(NULL, L"Menú Principal", WS_CHILD | WS_DISABLED | WS_TABSTOP | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 11.21833, 7.51417, 3.36021, 0.68792, hWnd, 1000);
		bt1.CreateX(NULL, L"Tutorial", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 7.11729, 6.48229, 2.77812, 0.68792, hWnd, 1001);
		bt2.CreateX(NULL, L"Jugar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 7.11729, 7.51417, 2.77812, 0.68792, hWnd, 1002);
		bt4.CreateX(NULL, L"Salir", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 7.11729, 8.54604, 2.77812, 0.68792, hWnd, 1003);
		bt5.CreateX(NULL, L"Menú Principal", WS_CHILD | WS_DISABLED | WS_TABSTOP | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 8.81062, 7.51417, 3.36021, 0.68792, hWnd, 1004);
		bt6.CreateX(NULL, L"Volver", WS_CHILD | WS_DISABLED | WS_TABSTOP | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 13.54667, 7.51417, 3.36021, 0.68792, hWnd, 1005);
		tbx1.CreateX(WS_EX_CLIENTEDGE, L"Prueba", WS_CHILD | WS_TABSTOP | ES_AUTOHSCROLL | ES_READONLY | ES_CENTER | ES_WINNORMALCASE, 2.22250, 4.47146, 20.55813, 0.74083, hWnd, 1006);
		lc1.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD, 4.25979, 12.62062, 16.77458, 0.63500, hWnd, 1007);
		lc2.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD, 0.74083, 0.71437, 6.77333, 0.39688, hWnd, 1008);
		bt3.CreateX(NULL, L"?", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_OWNERDRAW | BS_CENTER | BS_VCENTER, 0.50271, 12.38250, 0.66146, 0.68792, hWnd, 1009);
		lb1.CreateX(NULL, L"Alexis, el defenestrador", WS_CHILD | SS_CENTER | SS_WINNORMAL, 4.25979, 12.11792, 4.57729, 0.50271, hWnd, 1010);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		fontBaskerville_Old_Face012C.CreateX(L"Baskerville Old Face", 0.423333, true, false, false, false);
		fontCentury_Schoolbook012B.CreateX(L"Century Schoolbook", 0.423333, false, true, false, false);
		fontConstantia016A.CreateX(L"Constantia", 0.564444, false, false, false, false);
		fontFootlight_MT_Light016A.CreateX(L"Footlight MT Light", 0.564444, false, false, false, false);
		bt7.Font = fontCentury_Schoolbook012B;
		bt1.Font = fontCentury_Schoolbook012B;
		bt2.Font = fontCentury_Schoolbook012B;
		bt4.Font = fontCentury_Schoolbook012B;
		bt5.Font = fontCentury_Schoolbook012B;
		bt6.Font = fontCentury_Schoolbook012B;
		tbx1.Font = fontFootlight_MT_Light016A;
		lc1.Font = fontArial009A;
		lc2.Font = fontArial009A;
		bt3.Font = fontConstantia016A;
		lb1.Font = fontBaskerville_Old_Face012C;
		bt7.BackColor = RGB(192, 192, 192);
		bt1.BackColor = RGB(192, 192, 192);
		bt2.BackColor = RGB(192, 192, 192);
		bt4.BackColor = RGB(192, 192, 192);
		bt5.BackColor = RGB(192, 192, 192);
		bt6.BackColor = RGB(192, 192, 192);
		bt3.BackColor = RGB(192, 192, 192);
	}
	//_________________________________________________
	void bt7_Click(Win::Event& e);
	void bt7_DrawItem(Win::Event& e);
	void bt1_Click(Win::Event& e);
	void bt1_DrawItem(Win::Event& e);
	void bt2_Click(Win::Event& e);
	void bt2_DrawItem(Win::Event& e);
	void bt4_Click(Win::Event& e);
	void bt4_DrawItem(Win::Event& e);
	void bt5_Click(Win::Event& e);
	void bt5_DrawItem(Win::Event& e);
	void bt6_Click(Win::Event& e);
	void bt6_DrawItem(Win::Event& e);
	void bt3_Click(Win::Event& e);
	void bt3_DrawItem(Win::Event& e);
	void Window_KeyDown(Win::Event& e);
	void Window_KeyUp(Win::Event& e);
	void Window_Open(Win::Event& e);
	void Window_Size(Win::Event& e);
	void Window_Timer(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (bt7.IsEvent(e, BN_CLICKED)) {bt7_Click(e); return true;}
		if (bt7.IsEvent(e, WM_DRAWITEM)) {bt7_DrawItem(e); return true;}
		if (bt1.IsEvent(e, BN_CLICKED)) {bt1_Click(e); return true;}
		if (bt1.IsEvent(e, WM_DRAWITEM)) {bt1_DrawItem(e); return true;}
		if (bt2.IsEvent(e, BN_CLICKED)) {bt2_Click(e); return true;}
		if (bt2.IsEvent(e, WM_DRAWITEM)) {bt2_DrawItem(e); return true;}
		if (bt4.IsEvent(e, BN_CLICKED)) {bt4_Click(e); return true;}
		if (bt4.IsEvent(e, WM_DRAWITEM)) {bt4_DrawItem(e); return true;}
		if (bt5.IsEvent(e, BN_CLICKED)) {bt5_Click(e); return true;}
		if (bt5.IsEvent(e, WM_DRAWITEM)) {bt5_DrawItem(e); return true;}
		if (bt6.IsEvent(e, BN_CLICKED)) {bt6_Click(e); return true;}
		if (bt6.IsEvent(e, WM_DRAWITEM)) {bt6_DrawItem(e); return true;}
		if (bt3.IsEvent(e, BN_CLICKED)) {bt3_Click(e); return true;}
		if (bt3.IsEvent(e, WM_DRAWITEM)) {bt3_DrawItem(e); return true;}
		return false;
	}
};
