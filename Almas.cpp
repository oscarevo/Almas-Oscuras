#include "stdafx.h"  //________________________________________ Almas.cpp
#include "Almas.h"
#include "resource.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	Almas app;
	app.CreateMainWindow(L"Almas", cmdShow, IDI_Almas, NULL, (HBRUSH)::GetStockObject(NULL_BRUSH), hInstance);
	return app.MessageLoop(IDC_Almas);
}

//Este codigo ha sido programado por un novato de Visual Studio
//Por ende puede que alla codigo basura y varios errores logicos de por medio
//Por cierto, el programa carece de multithreading y oop

void Almas::Window_Open(Win::Event& e)
{
	LoadSprites();
	srand(::GetTickCount());

	::PlaySound(MAKEINTRESOURCE(IDR_TITLE), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC | SND_LOOP );

	//x									//y
	plataforma[0][0] = 2 * Unity;		plataforma[0][1] = 5.5 * Unity;
	plataforma[1][0] = 5 * Unity;		plataforma[1][1] = 11 * Unity;
	plataforma[2][0] = 11 * Unity;		plataforma[2][1] = 8 * Unity;
	plataforma[3][0] = 17 * Unity;		plataforma[3][1] = 11 * Unity;
	plataforma[4][0] = 20 * Unity;		plataforma[4][1] = 5.5 * Unity;

	x = 0.0f;
	y = AltPnt - AltP - Suelo;
	c = 0.0f;

	int i;
	for (i = 0;i < 2;i++) {
		magia[i][0] = 0.0f;
		magia[i][1] = -64.0f;
		mC[i][0] = 7.0f;
		mC[i][1] = 21.0f;
		mCmC[i][0] = 0;
		mCmC[i][1] = 0;
		mV[i] = 0;
		ff[i] = 0;
	}

	xB = 12 * Unity; //-1
	yB = 6 * Unity;

	for (i = 0;i < 4;i++) {
		bola[i][0] = xB + 48;
		bola[i][1] = yB + 48;
	}

	rxB = xB - real;
	ryB = yB - real;
	rAnchoB = AncB + 2 * real;
	rAltoB = AltB + 2 * real;

	axB = xB - ata;
	ayB = yB - ata;
	aAnchoB = AncB + 2 * ata;
	aAltoB = AltB + 2 * ata;

	pL = TpL;
	bL = TbL;

	this->timer.Set(10, 950);

	//________________________________________________________ lc1
	lc1.SetRange(0.0, 100.0);
	lc1.LineColor = RGB(0, 112, 158);
	lc1.WarningColor = RGB(0, 112, 158);
	lc1.ErrorColor = RGB(0, 112, 158);
	//lc1.WarningLevel = 75.0;
	//lc1.ErrorLevel = 95.0;
	lc1.Level = (bL * 100) / TbL;
	//________________________________________________________ lc2
	lc2.SetRange(0.0, 100.0);
	lc2.LineColor = RGB(0, 255, 0);
	lc2.WarningColor = RGB(0, 255, 0);
	lc2.ErrorColor = RGB(0, 255, 0);
	//lc2.WarningLevel = 75.0;
	//lc2.ErrorLevel = 95.0;
	lc2.Level = (pL * 100) / TpL;
}

void Almas::LoadSprites(void)
{
	//......................................PANTALLA DE INICIO...........................................
	inicio[0].CreateFromResource(this->hInstance, IDB_INICIO1);
	inicio[1].CreateFromResource(this->hInstance, IDB_INICIO2);
	inicio[2].CreateFromResource(this->hInstance, IDB_INICIO3);
	inicio[3].CreateFromResource(this->hInstance, IDB_INICIO4);
	inicio[4].CreateFromResource(this->hInstance, IDB_INICIO5);
	inicio[5].CreateFromResource(this->hInstance, IDB_INICIO6);
	inicio[6].CreateFromResource(this->hInstance, IDB_INICIO7);
	inicio[7].CreateFromResource(this->hInstance, IDB_INICIO8);
	inicio[8].CreateFromResource(this->hInstance, IDB_INICIO9);
	inicio[9].CreateFromResource(this->hInstance, IDB_INICIO10);
	inicio[10].CreateFromResource(this->hInstance, IDB_INICIO11);
	inicio[11].CreateFromResource(this->hInstance, IDB_INICIO12);
	inicio[12].CreateFromResource(this->hInstance, IDB_INICIO13);
	inicio[13].CreateFromResource(this->hInstance, IDB_INICIO14);
	inicio[14].CreateFromResource(this->hInstance, IDB_INICIO15);

	//...........................................PLAYER..................................................
	bitmap[0].CreateFromResource(this->hInstance, IDB_BITMAP1);
	bitmap[1].CreateFromResource(this->hInstance, IDB_BITMAP2);
	bitmap[2].CreateFromResource(this->hInstance, IDB_BITMAP3);
	bitmap[3].CreateFromResource(this->hInstance, IDB_BITMAP4);
	bitmap[4].CreateFromResource(this->hInstance, IDB_BITMAP5);
	bitmap[5].CreateFromResource(this->hInstance, IDB_BITMAP6);
	bitmap[6].CreateFromResource(this->hInstance, IDB_BITMAP7);
	bitmap[7].CreateFromResource(this->hInstance, IDB_BITMAP8);
	bitmap[8].CreateFromResource(this->hInstance, IDB_BITMAP9);
	bitmap[9].CreateFromResource(this->hInstance, IDB_BITMAP10);
	bitmap[10].CreateFromResource(this->hInstance, IDB_BITMAP11);
	bitmap[11].CreateFromResource(this->hInstance, IDB_BITMAP12);
	bitmap[12].CreateFromResource(this->hInstance, IDB_BITMAP13);
	bitmap[13].CreateFromResource(this->hInstance, IDB_BITMAP14);
	bitmap[14].CreateFromResource(this->hInstance, IDB_BITMAP15);
	bitmap[15].CreateFromResource(this->hInstance, IDB_BITMAP16);
	bitmap[16].CreateFromResource(this->hInstance, IDB_BITMAP17);
	bitmap[17].CreateFromResource(this->hInstance, IDB_BITMAP18);
	bitmap[18].CreateFromResource(this->hInstance, IDB_BITMAP19);
	bitmap[19].CreateFromResource(this->hInstance, IDB_BITMAP20);
	bitmap[20].CreateFromResource(this->hInstance, IDB_BITMAP21);
	bitmap[21].CreateFromResource(this->hInstance, IDB_BITMAP22);
	bitmap[22].CreateFromResource(this->hInstance, IDB_BITMAP23);
	bitmap[23].CreateFromResource(this->hInstance, IDB_BITMAP24);
	bitmap[24].CreateFromResource(this->hInstance, IDB_BITMAP25);
	bitmap[25].CreateFromResource(this->hInstance, IDB_BITMAP26);
	bitmap[26].CreateFromResource(this->hInstance, IDB_BITMAP27);
	bitmap[27].CreateFromResource(this->hInstance, IDB_BITMAP28);
	bitmap[28].CreateFromResource(this->hInstance, IDB_BITMAP29);
	bitmap[29].CreateFromResource(this->hInstance, IDB_BITMAP30);
	bitmap[30].CreateFromResource(this->hInstance, IDB_BITMAP31);
	bitmap[31].CreateFromResource(this->hInstance, IDB_BITMAP32);
	bitmap[32].CreateFromResource(this->hInstance, IDB_BITMAP33);
	bitmap[33].CreateFromResource(this->hInstance, IDB_BITMAP34);
	bitmap[34].CreateFromResource(this->hInstance, IDB_BITMAP35);
	bitmap[35].CreateFromResource(this->hInstance, IDB_BITMAP36);
	bitmap[36].CreateFromResource(this->hInstance, IDB_BITMAP37);
	bitmap[37].CreateFromResource(this->hInstance, IDB_BITMAP38);
	bitmap[38].CreateFromResource(this->hInstance, IDB_BITMAP39);
	bitmap[39].CreateFromResource(this->hInstance, IDB_BITMAP40);
	bitmap[40].CreateFromResource(this->hInstance, IDB_BITMAP41);
	bitmap[41].CreateFromResource(this->hInstance, IDB_BITMAP42);
	bitmap[42].CreateFromResource(this->hInstance, IDB_BITMAP43);
	bitmap[43].CreateFromResource(this->hInstance, IDB_BITMAP44);
	bitmap[44].CreateFromResource(this->hInstance, IDB_BITMAP45);
	bitmap[45].CreateFromResource(this->hInstance, IDB_BITMAP46);
	bitmap[46].CreateFromResource(this->hInstance, IDB_BITMAP47);
	bitmap[47].CreateFromResource(this->hInstance, IDB_BITMAP48);
	bitmap[48].CreateFromResource(this->hInstance, IDB_BITMAP49);
	bitmap[49].CreateFromResource(this->hInstance, IDB_BITMAP50);
	bitmap[50].CreateFromResource(this->hInstance, IDB_BITMAP51);
	bitmap[51].CreateFromResource(this->hInstance, IDB_BITMAP52);
	bitmap[52].CreateFromResource(this->hInstance, IDB_BITMAP53);
	bitmap[53].CreateFromResource(this->hInstance, IDB_BITMAP54);
	bitmap[54].CreateFromResource(this->hInstance, IDB_BITMAP55);
	bitmap[55].CreateFromResource(this->hInstance, IDB_BITMAP56);
	bitmap[56].CreateFromResource(this->hInstance, IDB_BITMAP57);
	bitmap[57].CreateFromResource(this->hInstance, IDB_BITMAP58);
	bitmap[58].CreateFromResource(this->hInstance, IDB_BITMAP59);
	bitmap[59].CreateFromResource(this->hInstance, IDB_BITMAP60);
	bitmap[60].CreateFromResource(this->hInstance, IDB_BITMAP61);
	bitmap[61].CreateFromResource(this->hInstance, IDB_BITMAP62);
	bitmap[62].CreateFromResource(this->hInstance, IDB_BITMAP63);
	bitmap[63].CreateFromResource(this->hInstance, IDB_BITMAP64);
	bitmap[64].CreateFromResource(this->hInstance, IDB_BITMAP65);
	bitmap[65].CreateFromResource(this->hInstance, IDB_BITMAP66);
	bitmap[66].CreateFromResource(this->hInstance, IDB_BITMAP67);
	bitmap[67].CreateFromResource(this->hInstance, IDB_BITMAP68);
	bitmap[68].CreateFromResource(this->hInstance, IDB_BITMAP69);
	bitmap[69].CreateFromResource(this->hInstance, IDB_BITMAP70);
	bitmap[70].CreateFromResource(this->hInstance, IDB_BITMAP71);
	bitmap[71].CreateFromResource(this->hInstance, IDB_BITMAP72);
	bitmap[72].CreateFromResource(this->hInstance, IDB_BITMAP73);
	bitmap[73].CreateFromResource(this->hInstance, IDB_BITMAP74);
	bitmap[74].CreateFromResource(this->hInstance, IDB_BITMAP75);
	bitmap[75].CreateFromResource(this->hInstance, IDB_BITMAP76);
	bitmap[76].CreateFromResource(this->hInstance, IDB_BITMAP77);
	bitmap[77].CreateFromResource(this->hInstance, IDB_BITMAP78);
	bitmap[78].CreateFromResource(this->hInstance, IDB_BITMAP79);
	bitmap[79].CreateFromResource(this->hInstance, IDB_BITMAP80);
	bitmap[80].CreateFromResource(this->hInstance, IDB_BITMAP81);
	bitmap[81].CreateFromResource(this->hInstance, IDB_BITMAP82);
	bitmap[82].CreateFromResource(this->hInstance, IDB_BITMAP83);
	bitmap[83].CreateFromResource(this->hInstance, IDB_BITMAP84);
	bitmap[84].CreateFromResource(this->hInstance, IDB_BITMAP85);
	bitmap[85].CreateFromResource(this->hInstance, IDB_BITMAP86);
	bitmap[86].CreateFromResource(this->hInstance, IDB_BITMAP87);
	bitmap[87].CreateFromResource(this->hInstance, IDB_BITMAP88);
	bitmap[88].CreateFromResource(this->hInstance, IDB_BITMAP89);
	bitmap[89].CreateFromResource(this->hInstance, IDB_BITMAP90);
	bitmap[90].CreateFromResource(this->hInstance, IDB_BITMAP91);
	bitmap[91].CreateFromResource(this->hInstance, IDB_BITMAP92);
	bitmap[92].CreateFromResource(this->hInstance, IDB_BITMAP93);
	bitmap[93].CreateFromResource(this->hInstance, IDB_BITMAP94);
	bitmap[94].CreateFromResource(this->hInstance, IDB_BITMAP95);
	bitmap[95].CreateFromResource(this->hInstance, IDB_BITMAP96);
	bitmap[96].CreateFromResource(this->hInstance, IDB_BITMAP97);
	bitmap[97].CreateFromResource(this->hInstance, IDB_BITMAP98);
	bitmap[98].CreateFromResource(this->hInstance, IDB_BITMAP99);
	bitmap[99].CreateFromResource(this->hInstance, IDB_BITMAP100);
	bitmap[100].CreateFromResource(this->hInstance, IDB_BITMAP101);
	bitmap[101].CreateFromResource(this->hInstance, IDB_BITMAP102);
	bitmap[102].CreateFromResource(this->hInstance, IDB_BITMAP103);
	bitmap[103].CreateFromResource(this->hInstance, IDB_BITMAP104);
	bitmap[104].CreateFromResource(this->hInstance, IDB_BITMAP105);
	bitmap[105].CreateFromResource(this->hInstance, IDB_BITMAP106);
	bitmap[106].CreateFromResource(this->hInstance, IDB_BITMAP107);
	bitmap[107].CreateFromResource(this->hInstance, IDB_BITMAP108);
	bitmap[108].CreateFromResource(this->hInstance, IDB_BITMAP109);
	bitmap[109].CreateFromResource(this->hInstance, IDB_BITMAP110);
	bitmap[110].CreateFromResource(this->hInstance, IDB_BITMAP111);
	bitmap[111].CreateFromResource(this->hInstance, IDB_BITMAP112);
	bitmap[112].CreateFromResource(this->hInstance, IDB_BITMAP113);
	bitmap[113].CreateFromResource(this->hInstance, IDB_BITMAP114);
	bitmap[114].CreateFromResource(this->hInstance, IDB_BITMAP115);
	bitmap[115].CreateFromResource(this->hInstance, IDB_BITMAP116);
	bitmap[116].CreateFromResource(this->hInstance, IDB_BITMAP117);
	bitmap[117].CreateFromResource(this->hInstance, IDB_BITMAP118);
	bitmap[118].CreateFromResource(this->hInstance, IDB_BITMAP119);
	bitmap[119].CreateFromResource(this->hInstance, IDB_BITMAP120);
	bitmap[120].CreateFromResource(this->hInstance, IDB_BITMAP121);
	bitmap[121].CreateFromResource(this->hInstance, IDB_BITMAP122);
	bitmap[122].CreateFromResource(this->hInstance, IDB_BITMAP123);
	bitmap[123].CreateFromResource(this->hInstance, IDB_BITMAP124);
	bitmap[124].CreateFromResource(this->hInstance, IDB_BITMAP125);
	bitmap[125].CreateFromResource(this->hInstance, IDB_BITMAP126);
	bitmap[126].CreateFromResource(this->hInstance, IDB_BITMAP127);
	bitmap[127].CreateFromResource(this->hInstance, IDB_BITMAP128);
	bitmap[128].CreateFromResource(this->hInstance, IDB_BITMAP129);
	bitmap[129].CreateFromResource(this->hInstance, IDB_BITMAP130);

	fuego[0].CreateFromResource(this->hInstance, IDB_BITMAP131);
	fuego[1].CreateFromResource(this->hInstance, IDB_BITMAP132);
	fuego[2].CreateFromResource(this->hInstance, IDB_BITMAP133);
	fuego[3].CreateFromResource(this->hInstance, IDB_BITMAP134);
	fuego[4].CreateFromResource(this->hInstance, IDB_BITMAP135);
	fuego[5].CreateFromResource(this->hInstance, IDB_BITMAP136);
	fuego[6].CreateFromResource(this->hInstance, IDB_BITMAP137);
	fuego[7].CreateFromResource(this->hInstance, IDB_BITMAP138);

	jefe[0].CreateFromResource(this->hInstance, IDB_BITMAP141);
	jefe[1].CreateFromResource(this->hInstance, IDB_BITMAP142);
	jefe[2].CreateFromResource(this->hInstance, IDB_BITMAP143);
	jefe[3].CreateFromResource(this->hInstance, IDB_BITMAP144);
	jefe[4].CreateFromResource(this->hInstance, IDB_BITMAP145);
	jefe[5].CreateFromResource(this->hInstance, IDB_BITMAP146);
	jefe[6].CreateFromResource(this->hInstance, IDB_BITMAP147);
	jefe[7].CreateFromResource(this->hInstance, IDB_BITMAP148);
	jefe[8].CreateFromResource(this->hInstance, IDB_BITMAP149);
	jefe[9].CreateFromResource(this->hInstance, IDB_BITMAP150);
	jefe[10].CreateFromResource(this->hInstance, IDB_BITMAP151);
	jefe[11].CreateFromResource(this->hInstance, IDB_BITMAP152);
	jefe[12].CreateFromResource(this->hInstance, IDB_BITMAP153);
	jefe[13].CreateFromResource(this->hInstance, IDB_BITMAP154);
	jefe[14].CreateFromResource(this->hInstance, IDB_BITMAP155);
	jefe[15].CreateFromResource(this->hInstance, IDB_BITMAP156);
	jefe[16].CreateFromResource(this->hInstance, IDB_BITMAP157);
	jefe[17].CreateFromResource(this->hInstance, IDB_BITMAP158);
	jefe[18].CreateFromResource(this->hInstance, IDB_BITMAP159);
	jefe[19].CreateFromResource(this->hInstance, IDB_BITMAP160);
	jefe[20].CreateFromResource(this->hInstance, IDB_BITMAP161);
	jefe[21].CreateFromResource(this->hInstance, IDB_BITMAP162);
	jefe[22].CreateFromResource(this->hInstance, IDB_BITMAP163);
	jefe[23].CreateFromResource(this->hInstance, IDB_BITMAP164);
	jefe[24].CreateFromResource(this->hInstance, IDB_BITMAP165);
	jefe[25].CreateFromResource(this->hInstance, IDB_BITMAP166);
	jefe[26].CreateFromResource(this->hInstance, IDB_BITMAP167);
	jefe[27].CreateFromResource(this->hInstance, IDB_BITMAP168);
	jefe[28].CreateFromResource(this->hInstance, IDB_BITMAP169);
	jefe[29].CreateFromResource(this->hInstance, IDB_BITMAP170);
	jefe[30].CreateFromResource(this->hInstance, IDB_BITMAP171);
	jefe[31].CreateFromResource(this->hInstance, IDB_BITMAP172);
	jefe[32].CreateFromResource(this->hInstance, IDB_BITMAP173);
	jefe[33].CreateFromResource(this->hInstance, IDB_BITMAP174);
	jefe[34].CreateFromResource(this->hInstance, IDB_BITMAP175);
	jefe[35].CreateFromResource(this->hInstance, IDB_BITMAP176);
	jefe[36].CreateFromResource(this->hInstance, IDB_BITMAP177);
	jefe[37].CreateFromResource(this->hInstance, IDB_BITMAP178);
	jefe[38].CreateFromResource(this->hInstance, IDB_BITMAP179);
	jefe[39].CreateFromResource(this->hInstance, IDB_BITMAP180);
	jefe[40].CreateFromResource(this->hInstance, IDB_BITMAP181);
	jefe[41].CreateFromResource(this->hInstance, IDB_BITMAP182);
	jefe[42].CreateFromResource(this->hInstance, IDB_BITMAP183);
	jefe[43].CreateFromResource(this->hInstance, IDB_BITMAP184);
	jefe[44].CreateFromResource(this->hInstance, IDB_BITMAP185);
	jefe[45].CreateFromResource(this->hInstance, IDB_BITMAP186);
	jefe[46].CreateFromResource(this->hInstance, IDB_BITMAP187);
	jefe[47].CreateFromResource(this->hInstance, IDB_BITMAP188);
	jefe[48].CreateFromResource(this->hInstance, IDB_BITMAP189);
	jefe[49].CreateFromResource(this->hInstance, IDB_BITMAP190);
	jefe[50].CreateFromResource(this->hInstance, IDB_BITMAP191);
	jefe[51].CreateFromResource(this->hInstance, IDB_BITMAP192);
	jefe[52].CreateFromResource(this->hInstance, IDB_BITMAP193);
	jefe[53].CreateFromResource(this->hInstance, IDB_BITMAP194);
	jefe[54].CreateFromResource(this->hInstance, IDB_BITMAP195);
	jefe[55].CreateFromResource(this->hInstance, IDB_BITMAP196);
	jefe[56].CreateFromResource(this->hInstance, IDB_BITMAP197);
	jefe[57].CreateFromResource(this->hInstance, IDB_BITMAP198);
	jefe[58].CreateFromResource(this->hInstance, IDB_BITMAP199);
	jefe[59].CreateFromResource(this->hInstance, IDB_BITMAP200);
	jefe[60].CreateFromResource(this->hInstance, IDB_BITMAP201);
	jefe[61].CreateFromResource(this->hInstance, IDB_BITMAP202);
	jefe[62].CreateFromResource(this->hInstance, IDB_BITMAP203);
	jefe[63].CreateFromResource(this->hInstance, IDB_BITMAP204);

	bolon[0].CreateFromResource(this->hInstance, IDB_BITMAP205);
	bolon[1].CreateFromResource(this->hInstance, IDB_BITMAP206);
	bolon[2].CreateFromResource(this->hInstance, IDB_BITMAP207);
	bolon[3].CreateFromResource(this->hInstance, IDB_BITMAP208);

	explo[0].CreateFromResource(this->hInstance, IDB_BITMAP209);
	explo[1].CreateFromResource(this->hInstance, IDB_BITMAP210);
	explo[2].CreateFromResource(this->hInstance, IDB_BITMAP211);
	explo[3].CreateFromResource(this->hInstance, IDB_BITMAP212);
	explo[4].CreateFromResource(this->hInstance, IDB_BITMAP213);
	explo[5].CreateFromResource(this->hInstance, IDB_BITMAP214);
	explo[6].CreateFromResource(this->hInstance, IDB_BITMAP215);
}

void Almas::Defenestrador(int n)
{
	bt1.SetEnabled(false);			bt1.SetVisible(false);
	bt2.SetEnabled(false);			bt2.SetVisible(false);
	bt3.SetEnabled(false);			bt3.SetVisible(false);
	bt4.SetEnabled(false);			bt4.SetVisible(false);

	bt5.SetEnabled(false);			bt5.SetVisible(false);
	bt6.SetEnabled(false);			bt6.SetVisible(false);

	if (n != 2) 
	{
		lc1.SetVisible(false);
		lc2.SetVisible(false);
		lb1.SetVisible(false);
	}

	if (n != 1)
		tbx1.SetVisible(false);

	if (n == 1 || n == 2)
	{
		if(pnt != 0)
		this->timer.Set(GenNum, GenTim);
	}

	if (n == 2)
	{
		this->timer.Set(0, BFPS);
	}
}

void Almas::Catalizador(int n)
{
	if (n == 0)
	{
		bt1.SetEnabled(true);			bt1.SetVisible(true);
		bt2.SetEnabled(true);			bt2.SetVisible(true);
		bt3.SetEnabled(true);			bt3.SetVisible(true);
		bt4.SetEnabled(true);			bt4.SetVisible(true);
	}
	else
	{
		bt5.SetEnabled(true);			bt5.SetVisible(true);
		bt6.SetEnabled(true);			bt6.SetVisible(true);
	}
}

bool Almas::RenderScene(CG::Gdi& gdi)
{
	if (canPause == true) {						//Si puedo pausar	
		if (pnt == 1 || pnt == 2) {				//Y la pantalla es de juego
			if (Prea == 0) {					//Y el indicador es inicial
				if (isPPressed == true) {		//Y se esta presionando "P"
					if (Pause == false) {		//Y el modo Pausa no esta activado
						Pause = true;				//Entonces se activa la Pausa
						this->timer.Kill(0);
						this->timer.Kill(1);
						this->timer.Kill(2);
						this->timer.Kill(3);
					}
					else {
						Pause = false;
						Defenestrador(pnt);
						this->SetFocus();
					}
					Prea = 1;
				}
			}
		}
	}

	switch (pnt)
	{
	case 0:	//...................................PANTALLA PRINCIPAL...................................

		//Imagen Pantalla Principal y Movimiento
		if (a > 1)
			a = 0;
		gdi.DrawBitmap(inicio[a], 0, 0, RGB(0, 255, 0));

		//Brillo Logo Wintempla
		if (uso == true){
			ran = (int)(250.0*rand() / RAND_MAX);

			if (ran == 0){
				this->timer.Set(11, 40);
				uso = false;
			}
		}

		if (b > 9){
			b = 2;
			uso = true;
			this->timer.Kill(11);
		}

		gdi.DrawBitmap(inicio[b], 0, 0, RGB(0, 255, 0));

		break;
	case 1:	//.........................................TUTORIAL...........................................

		gdi.DrawBitmap(inicio[10], 0, 0, RGB(0, 255, 0));

		if (Pause == false)///////////////////////////////////////////////////////////////////////////////
		{
			if (tutoTimer >= 1)
			{
				switch (tuto)
				{
				case 0:
					tbx1.Text = L"Puedes moverte de izquierda a derecha con las teclas direccionales";
					if (isRPressed == true)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 1:
					tbx1.Text = L"Presiona la tecla direccional arriba para saltar";
					if (isUPressed == true)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 2:
					tbx1.Text = L"Puedes atacar presionando la tecla Z";
					if (isZPressed == true)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 3:
					tbx1.Text = L"Con la tecla X realizarás un bloqueo con el escudo";
					if (isXPressed == true)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 4:
					tbx1.Text = L"Presionando la tecla C puedes equiparte y desequiparte el escudo";
					if (isCPressed == true)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 5:
					tbx1.Text = L"Mientras estés sin escudo puedes mantener la tecla Z para realizar un ataque cargado";
					if (estado == 4 && marca == 2)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 6:
					tbx1.Text = L"El ataque cargado drenará la vida de tus adversarios";
					if (tutoTimer > 1)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 7:
					tbx1.Text = L"También puedes mantener la tecla X para realizar un ataque mágico";
					if (estado == 4 && marca == 1)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 8:
					tbx1.Text = L"Éstos son los controles básicos del juego";
					if (tutoTimer > 1)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 9:
					tbx1.Text = L"Recuerda que puedes pulsar la tecla P para pausar el juego en cualquier momento";
					if (tutoTimer > 1)
					{
						tuto++;
						tutoTimer = 0;
						this->timer.Set(7, 2000);
					}
					break;
				case 10:
					tbx1.Text = L"Buena Suerte";
					if (tutoTimer > 1)
					{
						this->timer.Kill(7);
						tuto = 0;
						tutoTimer = 0;
						pnt = 0;
						Defenestrador(pnt);
						Catalizador(pnt);
						::PlaySound(MAKEINTRESOURCE(IDR_TITLE), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
					}
					break;
				}
			}

			{
			//Teclas y Gameplay
			//=======================================================================================================
			{isMoving = false;		//Suponemos que nunca se mueve

			if (isShieldActive == false)
			{
				switch (estado)
				{
				case 5:////////////////////////////////////////Soltar////////////////////////////////////
					//--------------------------------------------------------------------------------------------
					if (marca == 1 && n != nmax)
					{
						if (isXPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = (n + (orientacion * 6)) + 109;
					}
					else if (marca == 1 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;
						mRelease = true;
					}
					//--------------------------------------------------------------------------------------------
					if (marca == 2 && n != nmax)
					{
						if (isZPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = (n + (orientacion * 6)) + 77;
					}
					else if (marca == 2 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;
						lech = true;
					}
					//--------------------------------------------------------------------------------------------
					break;
				case 4: //////////////////////////////////Mantener/////////////////////////////////
					//-------------------------------------------------------------------------------------------
					if (marca == 1)
					{
						if (isXPressed == true)
						{
							if (n == nmax)
								n = 0;

							cuadro = 101 + (orientacion * 4) + n;
						}
						else if (isXPressed == false)
						{
							estado = 5;
							this->timer.Kill(2);
							n = 0;

							this->timer.Set(2, MagicRelease);	//*
							GenTim = MagicRelease;
							GenNum = 2;
							nmax = 6;
						}
					}
					//-------------------------------------------------------------------------------------------
					if (marca == 2)
					{
						if (isZPressed == true)
						{
							if (n == nmax)
								n = 0;

							cuadro = 69 + (orientacion * 4) + n;
						}
						else if (isZPressed == false)
						{
							estado = 5;
							this->timer.Kill(2);
							n = 0;

							this->timer.Set(2, SwordRelease);	//*
							GenTim = SwordRelease;
							GenNum = 2;
							nmax = 6;
						}
					}
					//-------------------------------------------------------------------------------------------
					break;
				case 3: /////////////////////////////////Con carga//////////////////////////////////
					//-------------------------------------------------------------------------------------------
					if (marca == 1 && n != nmax)
					{
						if (isXPressed == false)
						{
							estado = 0;
							this->timer.Kill(2);
							n = 0;
						}

						cuadro = 89 + (orientacion * 6) + n;
					}
					else if (marca == 1 && n == nmax)
					{
						if (isXPressed == true)
						{
							estado = 4;
							this->timer.Kill(2);
							n = 0;

							this->timer.Set(2, MagicMantein);	//*
							GenTim = MagicMantein;
							GenNum = 2;
							nmax = 4;
						}
					}
					//-------------------------------------------------------------------------------------------
					if (marca == 2 && n != nmax)
					{
						if (isZPressed == false)
						{
							estado = 0;
							this->timer.Kill(2);
							n = 0;
						}

						cuadro = 57 + (orientacion * 6) + n;
					}
					else if (marca == 2 && n == nmax)
					{
						if (isZPressed == true)
						{
							estado = 4;
							this->timer.Kill(2);
							n = 0;

							this->timer.Set(2, SwordMantein);	//*
							GenTim = SwordMantein;
							GenNum = 2;
							nmax = 4;
						}
					}
					//-------------------------------------------------------------------------------------------
					break;
				case 2: //////////////////////////////////Sin carga//////////////////////////////////
					//--------------------------------------------------------------------------------------------
					if (marca == 2 && n != nmax)
					{
						if (isZPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = (n + (orientacion * 8)) + 29;
						yourPain = true;
					}
					else if (marca == 2 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;
						yourPain = false;
					}
					//-------------------------------------------------------------------------------------------

					break;
				case 1: /////////////////////////////////Division///////////////////////////////////
					//-------------------------------------------------------------------------------------------
					if (marca == 1 && n != 1)
					{
						if (isXPressed == false)
						{
							estado = 0;
							this->timer.Kill(2);
							n = 0;
						}
					}
					else if (marca == 1 && n == 1)
					{
						if (isXPressed == true)
						{
							estado = 3;
							this->timer.Kill(2);
							n = 0;

							marca = 1;
							this->timer.Set(2, MagicCharge);	//*
							GenTim = MagicCharge;
							GenNum = 2;
							nmax = 6;
							//------------------------
							xr = 0;
							zr = -1;
							cr = -1;
							n = 0;
						}
					}
					//-------------------------------------------------------------------------------------------
					if (marca == 2 && n != 1)
					{
						if (isZPressed == false)
						{
							estado = 2;
							this->timer.Kill(2);
							n = 0;

							marca = 2;
							this->timer.Set(2, AttackwS);	//*
							GenTim = AttackwS;
							GenNum = 2;
							nmax = 4;
							//-------------------------
							xr = -1;
							zr = 0;
							cr = -1;
						}
					}
					else if (marca == 2 && n == 1)
					{
						if (isZPressed == true)
						{
							estado = 3;
							this->timer.Kill(2);
							n = 0;

							marca = 2;
							this->timer.Set(2, SwordCharge);	//*
							GenTim = SwordCharge;
							GenNum = 2;
							nmax = 6;
							//-------------------------
							xr = -1;
							zr = 0;
							cr = -1;
						}
					}
					//-------------------------------------------------------------------------------------------
					if (marca == 3 && n != nmax)
					{
						if (isCPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = (45 + (orientacion * 5)) - n;
					}
					else if (marca == 3 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;

						isShieldActive = true;
						v = vfot;
					}
					break;
				case 0:
					if (repite == 1) //&& isXStillPressed == false && isZStillPressed == false && isCStillPressed == false
					{
						//error con tecla levantada y los ceros
					}
					else if (repite == 0)
					{
						//-------------------------------------------------------------------------------------------
						if (isXPressed == true)
						{
							estado = 1;
							marca = 1;
							this->timer.Set(2, 200);	//*
							GenTim = 200;
							GenNum = 2;
							//------------------------
							xr = 0;
							zr = -1;
							cr = -1;
							n = 0;
						}
						//-------------------------------------------------------------------------------------------
						else if (isZPressed == true)
						{
							estado = 1;
							marca = 2;
							this->timer.Set(2, 200);	//*
							GenTim = 200;
							GenNum = 2;
							//-------------------------
							xr = -1;
							zr = 0;
							cr = -1;
							n = 0;
						}
						//-------------------------------------------------------------------------------------------
						else if (isCPressed == true)
						{
							escudo = 0;

							estado = 1;
							marca = 3;
							n = 0;
							this->timer.Set(2, ShieldChange);	//*
							GenTim = ShieldChange;
							GenNum = 2;
							nmax = 5;
							//------------------------
							xr = -1;
							zr = -1;
							cr = 0;
							n = 0;
						}
					}
					//--------------------------------------------------------------------------------------------------
					if (isRPressed == true)
					{
						isMoving = true;
						orientacion = 0;
						x += v * deltaSec; // 100 pixels/second
					}
					//-------------------------------------------------------------------------------------------
					if (isLPressed == true)
					{
						isMoving = true;
						orientacion = 1;
						x -= v * deltaSec;  // 100 pixels/second
					}
					break;
				}
			}
			else if (isShieldActive == true)//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
			{
				switch (estado)
				{
				case 1:
					//-------------------------------------------------------------------------------------------
					if (marca == 1 && n != nmax)
					{
						if (isXPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = (n + (orientacion * 3)) + 51;
					}
					else if (marca == 1 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;
					}
					//-------------------------------------------------------------------------------------------
					if (marca == 2 && n != nmax)
					{
						if (isZPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = (n + (orientacion * 8)) + 25;
						yourPain = true;
					}
					else if (marca == 2 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;
						yourPain = false;
					}
					//-------------------------------------------------------------------------------------------
					if (marca == 3 && n != nmax)
					{
						if (isCPressed == true)
							repite = 1;
						else
							repite = 0;

						cuadro = n + ((orientacion * 5) + 41);
					}
					else if (marca == 3 && n == nmax) {
						n = 0;
						this->timer.Kill(2);
						estado = 0;

						isShieldActive = false;
						v = vrun;
					}
					//-------------------------------------------------------------------------------------------
					break;
				case 0:
					if (repite == 1) //&& isXStillPressed == false && isZStillPressed == false && isCStillPressed == false
					{
						//error con tecla levantada y los ceros
					}
					else if (repite == 0)
					{
						//-------------------------------------------------------------------------------------------
						if (isXPressed == true)
						{
							estado = 1;
							marca = 1;
							this->timer.Set(2, ShieldUse);	//*
							GenTim = ShieldUse;
							GenNum = 2;
							nmax = 3;
							//------------------------
							xr = 0;
							zr = -1;
							cr = -1;
							n = 0;
						}
						//-------------------------------------------------------------------------------------------
						else if (isZPressed == true)
						{
							estado = 1;
							marca = 2;
							this->timer.Set(2, AttackS);	//*
							GenTim = AttackS;
							GenNum = 2;
							nmax = 4;
							//-------------------------
							xr = -1;
							zr = 0;
							cr = -1;
							n = 0;
						}
						//-------------------------------------------------------------------------------------------
						else if (isCPressed == true)
						{
							escudo = 1;

							estado = 1;
							marca = 3;
							n = 0;
							this->timer.Set(2, ShieldChange);	//*
							GenTim = ShieldChange;
							GenNum = 2;
							nmax = 5;
							//------------------------
							xr = -1;
							zr = -1;
							cr = 0;
							n = 0;
						}
					}
					//--------------------------------------------------------------------------------------------------
					if (isRPressed == true)
					{
						isMoving = true;
						orientacion = 0;
						x += v * deltaSec; // 100 pixels/second
					}
					//-------------------------------------------------------------------------------------------
					if (isLPressed == true)
					{
						isMoving = true;
						orientacion = 1;
						x -= v * deltaSec;  // 100 pixels/second
					}
					//-------------------------------------------------------------------------------------------
					break;
				}
			}

			//_________________________________________________________________________________________________
			if (isMoving == false && estado == 0) {
				isStatic = true;
				//StaTim = 0;
			}
			else {
				isStatic = false;
				//StaTim = -1;
			}
			//_________________________________________________________________________________________________
			if (isMoving == true && MovTim == 0)
			{
				this->timer.Set(3, MovingTimerS);	//*
				GenTim = MovingTimerS;
				GenNum = 3;
				MovTim = 1;
				n = 0;
			}
			else if (isMoving == true && MovTim == 1) {
				if (n > 3)
					n = 0;
				cuadro = (n + (orientacion * 8) + (escudo * 4)) + 9;
			}
			if (isMoving == false) {
				this->timer.Kill(3);
				MovTim = 0;
			}
			//_________________________________________________________________________________________________
			if (isStatic == true && StaTim == 0)
			{
				this->timer.Set(1, StaticTimer);	//*
				GenTim = StaticTimer;
				GenNum = 1;
				StaTim = 1;
				n = 0;
			}
			else if (isStatic == true && StaTim == 1) {
				if (n > 1)
					n = 0;
				cuadro = (n + (orientacion * 4) + (escudo * 2)) + 1;
			}
			if (isStatic == false) {
				this->timer.Kill(1);
				StaTim = 0;
			}
			}
			//=======================================================================================================

			//COLISIONES
			//========================================================================================================
			dC[0] = x + AncP / 2;		//Punto de Cilision
			dC[1] = y + AltP;

			Gravity = true;				//Suponemos que siempre esta cayendo
			isOnTheGround = false;

			//Comprobamos si en verdad esta cayendo

			if ((int)dC[1] >= height - Suelo) {
				Gravity = false;
				isOnTheGround = true;
				c = 0;
			}
			//========================================================================================================

			//GRAVEDAD
			//========================================================================================================
			if (estado == 0)
			{
				if (isUPressed == true)
				{
					if (isOnTheGround == true) {
						isJumping = true;
						if (framesPerSecond > 40)
							c = 420;
						else
							c = 300;
						isOnTheGround = false;
					}
					canJump = false;
				}
			}

			if (isJumping == true) {
				Gravity = true;
				isJumping = false;
			}

			if (isShieldActive == true)
				escudo = 0;
			else
				escudo = 1;

			if (Gravity == true) {
				y -= c * deltaSec;
				c = c - 15;

				if (estado == 0)
					cuadro = 121 + (orientacion * 2) + escudo;
			}
			//====================================================================================================

			//MAGIA
			//===================================================================================================
			if (m > 1)
				m = 0;

			if (f > 3)
				f = 0;

			if (mRelease == true)
			{
				if (orientacion == 0) 
				{
					magia[m][0] = x;	
					magia[m][1] = y;	
					mV[m] = 250;

					mCmC[m][0] = 54;
					mCmC[m][1] = 21;

					ff[m] = 0;
				}
				else 
				{
					magia[m][0] = x;	
					magia[m][1] = y;	
					mV[m] = -250;

					mCmC[m][0] = 14;	
					mCmC[m][1] = 21;

					ff[m] = 4;
				}

				mRelease = false;
				m++;
			}

			for (int i = 0;i < 2;i++) 
			{
				magia[i][0] += mV[i] * deltaSec;
				mC[i][0] = magia[i][0] + mCmC[i][0];
				mC[i][1] = magia[i][1] + mCmC[i][1];

				if (magia[i][0] > width + 64 || magia[i][0] < -64) 
				{
					magia[i][0] = 0.0f;
					magia[i][1] = -64.0f;	//Fuera de la Pantalla
					mV[i] = 0;
				}
	
				gdi.DrawBitmap(fuego[ff[i] + f], (int)magia[i][0], (int)magia[i][1], RGB(0, 255, 0));
			}
			//====================================================================================================

			//LIMITES DEL MAPA
			//====================================================================================================
			if (x < -10.0f) x = -10.0f;
			if (x > width - AncP) x = width - AncP;

			if (y < 0.0f) y = 0.0f;
			if (y > height - AltP) y = height - AltP;
			//====================================================================================================


			//DIBUJO DE PERSONAJES
			//===================================================================================================
			gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));//[cuadro - 1]);//, 64, 64, brush);	
			//===================================================================================================
			}
		}
		else//////////////////////////////////////////////////////////////////////////////////////////////
		{
			gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));//[cuadro - 1]);//, 64, 64, brush);

			if (f > 3)
				f = 0;

			gdi.DrawBitmap(fuego[ff[0] + f], (int)magia[0][0], (int)magia[0][1], RGB(0, 255, 0));
			gdi.DrawBitmap(fuego[ff[1] + f], (int)magia[1][0], (int)magia[1][1], RGB(0, 255, 0));

			gdi.DrawBitmap(inicio[12], 0, 0, RGB(0, 255, 0));
		
			Catalizador(pnt);
		}

		break;
	case 2:	//......................................JUEGO PRINCIPAL.......................................

		gdi.DrawBitmap(inicio[10], 0, 0, RGB(0, 255, 0));
		gdi.DrawBitmap(inicio[11], plataforma[0][0], plataforma[0][1], RGB(0, 255, 0));
		gdi.DrawBitmap(inicio[11], plataforma[1][0], plataforma[1][1], RGB(0, 255, 0));
		gdi.DrawBitmap(inicio[11], plataforma[2][0], plataforma[2][1], RGB(0, 255, 0));
		gdi.DrawBitmap(inicio[11], plataforma[3][0], plataforma[3][1], RGB(0, 255, 0));
		gdi.DrawBitmap(inicio[11], plataforma[4][0], plataforma[4][1], RGB(0, 255, 0));

		if (ImDead == false && YouDead == false)
		{
			if (Pause == false)///////////////////////////////////////////////////////////////////////////////
			{

				//Teclas y Gameplay
				//=======================================================================================================
				{isMoving = false;		//Suponemos que nunca se mueve

				if (isShieldActive == false)
				{
					switch (estado)
					{
					case 5:////////////////////////////////////////Soltar////////////////////////////////////
						//--------------------------------------------------------------------------------------------
						if (marca == 1 && n != nmax)
						{
							if (isXPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = (n + (orientacion * 6)) + 109;
						}
						else if (marca == 1 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;
							mRelease = true;
						}
						//--------------------------------------------------------------------------------------------
						if (marca == 2 && n != nmax)
						{
							if (isZPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = (n + (orientacion * 6)) + 77;
						}
						else if (marca == 2 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;
							lech = true;
						}
						//--------------------------------------------------------------------------------------------
						break;
					case 4: //////////////////////////////////Mantener/////////////////////////////////
						//-------------------------------------------------------------------------------------------
						if (marca == 1)
						{
							if (isXPressed == true)
							{
								if (n == nmax)
									n = 0;

								cuadro = 101 + (orientacion * 4) + n;
							}
							else if (isXPressed == false)
							{
								estado = 5;
								this->timer.Kill(2);
								n = 0;

								this->timer.Set(2, MagicRelease);	//*
								GenTim = MagicRelease;
								GenNum = 2;
								nmax = 6;
							}
						}
						//-------------------------------------------------------------------------------------------
						if (marca == 2)
						{
							if (isZPressed == true)
							{
								if (n == nmax)
									n = 0;

								cuadro = 69 + (orientacion * 4) + n;
							}
							else if (isZPressed == false)
							{
								estado = 5;
								this->timer.Kill(2);
								n = 0;

								this->timer.Set(2, SwordRelease);	//*
								GenTim = SwordRelease;
								GenNum = 2;
								nmax = 6;
							}
						}
						//-------------------------------------------------------------------------------------------
						break;
					case 3: /////////////////////////////////Con carga//////////////////////////////////
						//-------------------------------------------------------------------------------------------
						if (marca == 1 && n != nmax)
						{
							if (isXPressed == false)
							{
								estado = 0;
								this->timer.Kill(2);
								n = 0;
							}

							cuadro = 89 + (orientacion * 6) + n;
						}
						else if (marca == 1 && n == nmax)
						{
							if (isXPressed == true)
							{
								estado = 4;
								this->timer.Kill(2);
								n = 0;

								this->timer.Set(2, MagicMantein);	//*
								GenTim = MagicMantein;
								GenNum = 2;
								nmax = 4;
							}
						}
						//-------------------------------------------------------------------------------------------
						if (marca == 2 && n != nmax)
						{
							if (isZPressed == false)
							{
								estado = 0;
								this->timer.Kill(2);
								n = 0;
							}

							cuadro = 57 + (orientacion * 6) + n;
						}
						else if (marca == 2 && n == nmax)
						{
							if (isZPressed == true)
							{
								estado = 4;
								this->timer.Kill(2);
								n = 0;

								this->timer.Set(2, SwordMantein);	//*
								GenTim = SwordMantein;
								GenNum = 2;
								nmax = 4;
							}
						}
						//-------------------------------------------------------------------------------------------
						break;
					case 2: //////////////////////////////////Sin carga//////////////////////////////////
						//--------------------------------------------------------------------------------------------
						if (marca == 2 && n != nmax)
						{
							if (isZPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = (n + (orientacion * 8)) + 29;
							yourPain = true;
						}
						else if (marca == 2 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;
							yourPain = false;
						}
						//-------------------------------------------------------------------------------------------

						break;
					case 1: /////////////////////////////////Division///////////////////////////////////
						//-------------------------------------------------------------------------------------------
						if (marca == 1 && n != 1)
						{
							if (isXPressed == false)
							{
								estado = 0;
								this->timer.Kill(2);
								n = 0;
							}
						}
						else if (marca == 1 && n == 1)
						{
							if (isXPressed == true)
							{
								estado = 3;
								this->timer.Kill(2);
								n = 0;

								marca = 1;
								this->timer.Set(2, MagicCharge);	//*
								GenTim = MagicCharge;
								GenNum = 2;
								nmax = 6;
								//------------------------
								xr = 0;
								zr = -1;
								cr = -1;
								n = 0;
							}
						}
						//-------------------------------------------------------------------------------------------
						if (marca == 2 && n != 1)
						{
							if (isZPressed == false)
							{
								estado = 2;
								this->timer.Kill(2);
								n = 0;

								marca = 2;
								this->timer.Set(2, AttackwS);	//*
								GenTim = AttackwS;
								GenNum = 2;
								nmax = 4;
								//-------------------------
								xr = -1;
								zr = 0;
								cr = -1;
							}
						}
						else if (marca == 2 && n == 1)
						{
							if (isZPressed == true)
							{
								estado = 3;
								this->timer.Kill(2);
								n = 0;

								marca = 2;
								this->timer.Set(2, SwordCharge);	//*
								GenTim = SwordCharge;
								GenNum = 2;
								nmax = 6;
								//-------------------------
								xr = -1;
								zr = 0;
								cr = -1;
							}
						}
						//-------------------------------------------------------------------------------------------
						if (marca == 3 && n != nmax)
						{
							if (isCPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = (45 + (orientacion * 5)) - n;
						}
						else if (marca == 3 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;

							isShieldActive = true;
							v = vfot;
							def = defS;
						}
						break;
					case 0:
						if (repite == 1) //&& isXStillPressed == false && isZStillPressed == false && isCStillPressed == false
						{
							//error con tecla levantada y los ceros
						}
						else if (repite == 0)
						{
							//-------------------------------------------------------------------------------------------
							if (isXPressed == true)
							{
								estado = 1;
								marca = 1;
								this->timer.Set(2, 200);	//*
								GenTim = 200;
								GenNum = 2;
								//------------------------
								xr = 0;
								zr = -1;
								cr = -1;
								n = 0;
							}
							//-------------------------------------------------------------------------------------------
							else if (isZPressed == true)
							{
								estado = 1;
								marca = 2;
								this->timer.Set(2, 200);	//*
								GenTim = 200;
								GenNum = 2;
								//-------------------------
								xr = -1;
								zr = 0;
								cr = -1;
								n = 0;
							}
							//-------------------------------------------------------------------------------------------
							else if (isCPressed == true)
							{
								escudo = 0;

								estado = 1;
								marca = 3;
								n = 0;
								this->timer.Set(2, ShieldChange);	//*
								GenTim = ShieldChange;
								GenNum = 2;
								nmax = 5;
								//------------------------
								xr = -1;
								zr = -1;
								cr = 0;
								n = 0;
							}
						}
						//--------------------------------------------------------------------------------------------------
						if (isRPressed == true)
						{
							isMoving = true;
							orientacion = 0;
							x += v * deltaSec; // 100 pixels/second
						}
						//-------------------------------------------------------------------------------------------
						if (isLPressed == true)
						{
							isMoving = true;
							orientacion = 1;
							x -= v * deltaSec;  // 100 pixels/second
						}
						break;
					}
				}
				else if (isShieldActive == true)//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
				{
					switch (estado)
					{
					case 1:
						//-------------------------------------------------------------------------------------------
						if (marca == 1 && n != nmax)
						{
							if (isXPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = (n + (orientacion * 3)) + 51;
							def = defSu;
						}
						else if (marca == 1 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;
							def = defS;
						}
						//-------------------------------------------------------------------------------------------
						if (marca == 2 && n != nmax)
						{
							if (isZPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = (n + (orientacion * 8)) + 25;
							yourPain = true;
						}
						else if (marca == 2 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;
							yourPain = false;
						}
						//-------------------------------------------------------------------------------------------
						if (marca == 3 && n != nmax)
						{
							if (isCPressed == true)
								repite = 1;
							else
								repite = 0;

							cuadro = n + ((orientacion * 5) + 41);
						}
						else if (marca == 3 && n == nmax) {
							n = 0;
							this->timer.Kill(2);
							estado = 0;

							isShieldActive = false;
							v = vrun;
							def = defWs;
						}
						//-------------------------------------------------------------------------------------------
						break;
					case 0:
						if (repite == 1) //&& isXStillPressed == false && isZStillPressed == false && isCStillPressed == false
						{
							//error con tecla levantada y los ceros
						}
						else if (repite == 0)
						{
							//-------------------------------------------------------------------------------------------
							if (isXPressed == true)
							{
								estado = 1;
								marca = 1;
								this->timer.Set(2, ShieldUse);	//*
								GenTim = ShieldUse;
								GenNum = 2;
								nmax = 3;
								//------------------------
								xr = 0;
								zr = -1;
								cr = -1;
								n = 0;
							}
							//-------------------------------------------------------------------------------------------
							else if (isZPressed == true)
							{
								estado = 1;
								marca = 2;
								this->timer.Set(2, AttackS);	//*
								GenTim = AttackS;
								GenNum = 2;
								nmax = 4;
								//-------------------------
								xr = -1;
								zr = 0;
								cr = -1;
								n = 0;
							}
							//-------------------------------------------------------------------------------------------
							else if (isCPressed == true)
							{
								escudo = 1;

								estado = 1;
								marca = 3;
								n = 0;
								this->timer.Set(2, ShieldChange);	//*
								GenTim = ShieldChange;
								GenNum = 2;
								nmax = 5;
								//------------------------
								xr = -1;
								zr = -1;
								cr = 0;
								n = 0;
							}
						}
						//--------------------------------------------------------------------------------------------------
						if (isRPressed == true)
						{
							isMoving = true;
							orientacion = 0;
							x += v * deltaSec; // 100 pixels/second
						}
						//-------------------------------------------------------------------------------------------
						if (isLPressed == true)
						{
							isMoving = true;
							orientacion = 1;
							x -= v * deltaSec;  // 100 pixels/second
						}
						//-------------------------------------------------------------------------------------------
						break;
					}
				}

				//_________________________________________________________________________________________________
				if (isMoving == false && estado == 0) {
					isStatic = true;
					//StaTim = 0;
				}
				else {
					isStatic = false;
					//StaTim = -1;
				}
				//_________________________________________________________________________________________________
				if (isMoving == true && MovTim == 0)
				{
					this->timer.Set(3, MovingTimerS);	//*
					GenTim = MovingTimerS;
					GenNum = 3;
					MovTim = 1;
					n = 0;
				}
				else if (isMoving == true && MovTim == 1) {
					if (n > 3)
						n = 0;
					cuadro = (n + (orientacion * 8) + (escudo * 4)) + 9;
				}
				if (isMoving == false) {
					this->timer.Kill(3);
					MovTim = 0;
				}
				//_________________________________________________________________________________________________
				if (isStatic == true && StaTim == 0)
				{
					this->timer.Set(1, StaticTimer);	//*
					GenTim = StaticTimer;
					GenNum = 1;
					StaTim = 1;
					n = 0;
				}
				else if (isStatic == true && StaTim == 1) {
					if (n > 1)
						n = 0;
					cuadro = (n + (orientacion * 4) + (escudo * 2)) + 1;
				}
				if (isStatic == false) {
					this->timer.Kill(1);
					StaTim = 0;
				}
				}
				//=======================================================================================================

				//COLISIONES
				//========================================================================================================
				dC[0] = x + AncP / 2;		//Punto de Cilision
				dC[1] = y + AltP;

				Gravity = true;				//Suponemos que siempre esta cayendo
				isOnTheGround = false;

				//Comprobamos si en verdad esta cayendo

				if ((int)dC[1] >= height - Suelo) {
					Gravity = false;
					isOnTheGround = true;
					c = 0;
				}
				else if ((dC[0]<plataforma[0][0] + AncBar && dC[0]>plataforma[0][0]) && (dC[1]<plataforma[0][1] + AltBar && dC[1]>plataforma[0][1]) && c <= 0)
				{
					Gravity = false;
					isOnTheGround = true;
					c = 0;
				}
				else if ((dC[0]<plataforma[1][0] + AncBar && dC[0]>plataforma[1][0]) && (dC[1]<plataforma[1][1] + AltBar && dC[1]>plataforma[1][1]) && c <= 0)
				{
					Gravity = false;
					isOnTheGround = true;
					c = 0;
				}
				else if ((dC[0]<plataforma[2][0] + AncBar && dC[0]>plataforma[2][0]) && (dC[1]<plataforma[2][1] + AltBar && dC[1]>plataforma[2][1]) && c <= 0)
				{
					Gravity = false;
					isOnTheGround = true;
					c = 0;
				}
				else if ((dC[0]<plataforma[3][0] + AncBar && dC[0]>plataforma[3][0]) && (dC[1]<plataforma[3][1] + AltBar && dC[1]>plataforma[3][1]) && c <= 0)
				{
					Gravity = false;
					isOnTheGround = true;
					c = 0;
				}
				else if ((dC[0]<plataforma[4][0] + AncBar && dC[0]>plataforma[4][0]) && (dC[1]<plataforma[4][1] + AltBar && dC[1]>plataforma[4][1]) && c <= 0)
				{
					Gravity = false;
					isOnTheGround = true;
					c = 0;
				}
				//========================================================================================================

				//GRAVEDAD
				//========================================================================================================
				if (estado == 0)
				{
					if (isUPressed == true)
					{
						if (isOnTheGround == true) {
							isJumping = true;
							if (framesPerSecond > 40)
								c = 420;
							else
								c = 300;
							isOnTheGround = false;
						}
						canJump = false;
					}
				}

				if (isJumping == true) {
					Gravity = true;
					isJumping = false;
				}

				if (isShieldActive == true)
					escudo = 0;
				else
					escudo = 1;

				if (Gravity == true) {
					y -= c * deltaSec;
					c = c - 15;

					if (estado == 0)
						cuadro = 121 + (orientacion * 2) + escudo;
				}
				//====================================================================================================

				//BOSS IA
				//===================================================================================================
				dis = sqrt((((xB + 48) - (x + 32))*((xB + 48) - (x + 32))) + (((yB + 48) - (y + 32))*((yB + 48) - (y + 32))));



				if (isBIAactive == true)	//Por Pruebas
				{
					if (Desicion == false)
					{
						if (dis < 120) {
							IA = 1;
							r = (int)(40.0*rand() / RAND_MAX);
						}
						else if (dis > 120 && dis < 220) {
							IA = 2;
							r = (int)(130.0*rand() / RAND_MAX);
						}
						else if (dis > 220) {
							IA = 3;
							r = (int)(100.0*rand() / RAND_MAX);
						}

						if (r > 0)
						{
							yB -= (yB - y)*deltaSec * 2 / 3;
							xB -= (xB - x)*deltaSec * 2 / 3;

							if (k > 3)
								k = 0;

							bossy = k;
						}
						else if (r == 0)
						{
							if (IA == 1)
							{
								Desicion = true;
								this->timer.Set(0, BFPS);	//1600
								k = 0;
								kmax = 16;
								exp = true;
							}
							else if (IA == 2)
							{
								Desicion = true;
								this->timer.Set(0, BFPS);	//800
								k = 0;
								kmax = 8;
							}
							else if (IA == 3)
							{
								Desicion = true;
								this->timer.Set(0, BFPS);	//1600
								k = 0;
								kmax = 16;

								this->timer.Set(9, 50);
								for (int i = 0;i < 4;i++) {
									bola[i][0] = xB + 40;
									bola[i][1] = yB + 40;
								}
							}
						}
					}

					if (Desicion == true)//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
					{
						if (IA == 1 && k != kmax)
						{
							if (k > 7 && k < 16)
								bossy = k;	//+ 4 - 4
							else
								bossy = k + 4;

							if (k > 4 && k < 12)
							{
								axB = xB - ata;
								ayB = yB - ata;
							}
						}
						else if (IA == 1 && k == kmax)
						{
							this->timer.Set(0, BFPS);
							Desicion = false;
							k = 0;
							r = 1;
							exp = false;
						}
						//------------------------------------------------------------------------------------------
						if (IA == 2 && k != kmax)
						{
							if (k > 3 && k < 8)
								bossy = k + 16 - 4;	//+ 4 - 4
							else
								bossy = k + 16;

							yB -= (yB - y)*deltaSec * 2;
							xB -= (xB - x)*deltaSec * 2;
						}
						else if (IA == 2 && k == kmax)
						{
							this->timer.Set(0, BFPS);
							Desicion = false;
							k = 0;
							r = 1;
						}
						//-------------------------------------------------------------------------------------------
						if (IA == 3 && k != kmax)
						{
							if (k > 7 && k < 16)
								bossy = k + 20 - 4;	//+ 4 - 4
							else
								bossy = k + 20;

							bola[0][1] += 500 * deltaSec;
							bola[1][0] += 500 * deltaSec;
							bola[2][1] -= 500 * deltaSec;
							bola[3][0] -= 500 * deltaSec;


							bola[0][0] -= 40 * k * deltaSec;
							bola[1][1] += 40 * k * deltaSec;
							bola[2][0] += 40 * k * deltaSec;
							bola[3][1] -= 40 * k * deltaSec;

							if (bol > 3)
								bol = 0;

							for (int i = 0;i < 4;i++) {
								gdi.DrawBitmap(bolon[bol], (int)bola[i][0], (int)bola[i][1], RGB(0, 255, 0));
							}

						}
						else if (IA == 3 && k == kmax) {
							this->timer.Set(0, BFPS);
							this->timer.Kill(9);
							bol = 0;
							Desicion = false;
							k = 0;
							r = 1;
						}
					}
					rxB = xB - real;
					ryB = yB - real;
				}

				if (((rxB + 64) - (x + 32)) > 0)
					ori = 0;
				else
					ori = 32;

				gdi.DrawBitmap(jefe[bossy + ori], (int)rxB, (int)ryB, RGB(0, 255, 0));
				//===================================================================================================


				//MAGIA
				//===================================================================================================
				if (m > 1)
					m = 0;

				if (f > 3)
					f = 0;

				if (mRelease == true)
				{
					if (orientacion == 0)
					{
						magia[m][0] = x;
						magia[m][1] = y;
						mV[m] = 250;

						mCmC[m][0] = 54;
						mCmC[m][1] = 21;

						ff[m] = 0;
					}
					else
					{
						magia[m][0] = x;
						magia[m][1] = y;
						mV[m] = -250;

						mCmC[m][0] = 14;
						mCmC[m][1] = 21;

						ff[m] = 4;
					}

					mRelease = false;
					m++;
				}

				for (int i = 0;i < 2;i++)
				{
					magia[i][0] += mV[i] * deltaSec;
					mC[i][0] = magia[i][0] + mCmC[i][0];
					mC[i][1] = magia[i][1] + mCmC[i][1];

					if (magia[i][0] > width + 64 || magia[i][0] < -64)
					{
						magia[i][0] = 0.0f;
						magia[i][1] = -64.0f;	//Fuera de la Pantalla
						mV[i] = 0;
					}

					gdi.DrawBitmap(fuego[ff[i] + f], (int)magia[i][0], (int)magia[i][1], RGB(0, 255, 0));
				}
				//====================================================================================================

				//VIDA Y DAÑO
				//====================================================================================================
				pP[0] = x + AncP / 2;
				pP[1] = y + AltP / 2;

				if (orientacion == 1) {
					hP[0] = x - 5;
				}
				else if (orientacion == 0) {
					hP[0] = x + 69;
				}
				hP[1] = y + AltP / 2;

				if (bossCooldown == false)
				{
					this->timer.Kill(4);

					if ((hP[0]<xB + AncB && hP[0]>xB) && (hP[1]<yB + AltB && hP[1]>yB) && yourPain == true)

					{
						this->timer.Set(4, 800);		//Tiempo cooldown del boss (daño)
						bL = bL - (int)((((51.0*rand() / RAND_MAX) + 75) / 100) * 500);			//Daño del personaje (espada)

						bossCooldown = true;
					}
					else if ((hP[0]<xB + AncB && hP[0]>xB) && (hP[1]<yB + AltB && hP[1]>yB) && lech == true)
					{
						this->timer.Set(4, 800);		//Tiempo cooldown del boss (daño)
						pL = pL + 500;					//Daño del personaje (espada)

						bossCooldown = true;
						lech = false;
					}
					else if (((mC[0][0]<xB + AncB && mC[0][0]>xB) && (mC[0][1]<yB + AltB && mC[0][1]>yB)) ||
						((mC[1][0]<xB + AncB && mC[1][0]>xB) && (mC[1][1]<yB + AltB && mC[1][1]>yB)))
					{
						this->timer.Set(4, 800);		//Tiempo cooldown del boss (daño)
						bL = bL - (int)((((51.0*rand() / RAND_MAX) + 75) / 100) * 1500);		//Daño del personaje (magia)

						bossCooldown = true;
					}
				}

				if (playerCooldown == false)
				{
					this->timer.Kill(5);

					if ((pP[0]<xB + AncB && pP[0]>xB) && (pP[1]<yB + AltB && pP[1]>yB))
					{
						this->timer.Set(5, 1200);		//Tiempo cooldown del personaje (daño)
						pL = pL - (int)(((((71.0*rand() / RAND_MAX) + 80) / 100) * 150) * def);		//Daño del boss

						playerCooldown = true;
						myPain = true;
					}
					else if ((pP[0]<axB + aAnchoB && pP[0]>axB) && (pP[1]<ayB + aAnchoB && pP[1]>ayB) && IA == 1 && k > 5 && k < 10)
					{
						this->timer.Set(5, 1200);		//Tiempo cooldown del personaje (daño)
						pL = pL - (int)(((((71.0*rand() / RAND_MAX) + 80) / 100) * 500) * def);		//Daño del boss

						playerCooldown = true;
						myPain = true;
					}
					else if (IA == 3)
					{
						if ((pP[0] < bola[0][0] + 48 && pP[0] > bola[0][0]) && (pP[1] < bola[0][1] + 48 && pP[1] > bola[0][1]))
						{
							this->timer.Set(5, 1200);		//Tiempo cooldown del personaje (daño)
							pL = pL - (int)(((((71.0*rand() / RAND_MAX) + 80) / 100) * 250) * def);		//Daño del boss

							playerCooldown = true;
							myPain = true;
						}
						else if ((pP[0] < bola[1][0] + 48 && pP[0] > bola[1][0]) && (pP[1] < bola[1][1] + 48 && pP[1] > bola[1][1]))
						{
							this->timer.Set(5, 1200);		//Tiempo cooldown del personaje (daño)
							pL = pL - (int)(((((71.0*rand() / RAND_MAX) + 80) / 100) * 250) * def);		//Daño del boss

							playerCooldown = true;
							myPain = true;
						}
						else if ((pP[0] < bola[2][0] + 48 && pP[0] > bola[2][0]) && (pP[1] < bola[2][1] + 48 && pP[1] > bola[2][1]))
						{
							this->timer.Set(5, 1200);		//Tiempo cooldown del personaje (daño)
							pL = pL - (int)(((((71.0*rand() / RAND_MAX) + 80) / 100) * 250) * def);		//Daño del boss

							playerCooldown = true;
							myPain = true;
						}
						else if ((pP[0] < bola[3][0] + 48 && pP[0] > bola[3][0]) && (pP[1] < bola[3][1] + 48 && pP[1] > bola[3][1]))
						{
							this->timer.Set(5, 1200);		//Tiempo cooldown del personaje (daño)
							pL = pL - (int)(((((71.0*rand() / RAND_MAX) + 80) / 100) * 250) * def);		//Daño del boss

							playerCooldown = true;
							myPain = true;
						}
					}
				}
				//====================================================================================================


				//MUERTE Y CONTROL DE VIDA
				//====================================================================================================

				if (pL > 3000) pL = 3000;

				lc1.Level = (bL * 100) / TbL;
				lc2.Level = (pL * 100) / TpL;

				if (lc2.Level > 40) 
				{
					lc2.LineColor = RGB(0, 255, 0);
					lc2.WarningColor = RGB(0, 255, 0);
					lc2.ErrorColor = RGB(0, 255, 0);
				}
				else if (lc2.Level < 40 && lc2.Level > 15)
				{
					lc2.LineColor = RGB(255, 255, 0);
					lc2.WarningColor = RGB(255, 255, 0);
					lc2.ErrorColor = RGB(255, 255, 0);
				}
				else if (lc2.Level < 15)
				{
					lc2.LineColor = RGB(255, 0, 0);
					lc2.WarningColor = RGB(255, 0, 0);
					lc2.ErrorColor = RGB(255, 0, 0);
				}

				if (pL <= 0)
				{
					ImDead = true;
					canPause = false;
					bt7.SetEnabled(true);			bt7.SetVisible(true);
					this->timer.Kill(0);
					this->timer.Kill(1);
					this->timer.Kill(2);
					this->timer.Kill(3);

					::PlaySound(MAKEINTRESOURCE(IDR_DEAD), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC );
				}
				if (bL <= 0)
				{
					YouDead = true;
					canPause = false;
					bt7.SetEnabled(true);			bt7.SetVisible(true);
					this->timer.Kill(0);
					this->timer.Kill(1);
					this->timer.Kill(2);
					this->timer.Kill(3);

					::PlaySound(MAKEINTRESOURCE(IDR_VICT), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC );
				}

				//====================================================================================================

				//LIMITES DEL MAPA
				//====================================================================================================
				if (x < -10.0f) x = -10.0f;
				if (x > width - AncP) x = width - AncP;

				if (y < 0.0f) y = 0.0f;
				if (y > height - AltP) y = height - AltP;
				//====================================================================================================


				//DIBUJO DE PERSONAJES
				//===================================================================================================
				if (myPain == false)
				{
					gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));//[cuadro - 1]);//, 64, 64, brush);	
					this->timer.Kill(6);
					MpTim = 0;
				}
				else {

					if (myPain == true && MpTim == 0)
					{
						this->timer.Set(6, 100);
						MpTim = 1;
						flicker = 0;
					}
					else if (myPain == true && MpTim == 1) {
						if (flicker > 1)
							flicker = 0;

						if (flicker == 1)
							gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));
					}
				}

				if (exp == true)
				{
					if (k > 4 && k < 12)
					{
						gdi.DrawBitmap(explo[k - 5], (int)axB, (int)ayB, RGB(0, 255, 0));
					}
				}
				//====================================================================================================
			}
			else//////////////////////////////////////////////////////////////////////////////////////////////
			{
				gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));//[cuadro - 1]);//, 64, 64, brush);
				gdi.DrawBitmap(jefe[bossy + ori], (int)rxB, (int)ryB, RGB(0, 255, 0));

				if (f > 3)
					f = 0;

				gdi.DrawBitmap(fuego[ff[0] + f], (int)magia[0][0], (int)magia[0][1], RGB(0, 255, 0));
				gdi.DrawBitmap(fuego[ff[1] + f], (int)magia[1][0], (int)magia[1][1], RGB(0, 255, 0));

				if (bol > 3)
					bol = 0;

				if (IA == 3)
				{
					for (int i = 0;i < 4;i++)
					{
						gdi.DrawBitmap(bolon[bol], (int)bola[i][0], (int)bola[i][1], RGB(0, 255, 0));
					}
				}

				if (exp == true)
				{
					if (k > 4 && k < 12)
					{
						gdi.DrawBitmap(explo[k - 5], (int)axB, (int)ayB, RGB(0, 255, 0));
					}
				}

				gdi.DrawBitmap(inicio[12], 0, 0, RGB(0, 255, 0));

				Catalizador(pnt);
			}
		}
		else if (ImDead == false && YouDead == true)	//Muere el Boss
		{
			gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));//[cuadro - 1]);//, 64, 64, brush);
			gdi.DrawBitmap(jefe[bossy + ori], (int)rxB, (int)ryB, RGB(0, 255, 0));

			if (f > 3)
				f = 0;

			gdi.DrawBitmap(fuego[ff[0] + f], (int)magia[0][0], (int)magia[0][1], RGB(0, 255, 0));
			gdi.DrawBitmap(fuego[ff[1] + f], (int)magia[1][0], (int)magia[1][1], RGB(0, 255, 0));

			if (bol > 3)
				bol = 0;

			if (IA == 3)
			{
				for (int i = 0;i < 4;i++)
				{
					gdi.DrawBitmap(bolon[bol], (int)bola[i][0], (int)bola[i][1], RGB(0, 255, 0));
				}
			}

			if (exp == true)
			{
				if (k > 4 && k < 12)
				{
					gdi.DrawBitmap(explo[k - 5], (int)axB, (int)ayB, RGB(0, 255, 0));
				}
			}

			gdi.DrawBitmap(inicio[14], 0, 0, RGB(0, 255, 0));
		}
		else if (ImDead == true && (YouDead == false || YouDead == true)) //Muero Yo
		{
			gdi.DrawBitmap(bitmap[cuadro - 1], (int)x, (int)y, RGB(0, 255, 0));//[cuadro - 1]);//, 64, 64, brush);
			gdi.DrawBitmap(jefe[bossy + ori], (int)rxB, (int)ryB, RGB(0, 255, 0));

			if (f > 3)
				f = 0;

			gdi.DrawBitmap(fuego[ff[0] + f], (int)magia[0][0], (int)magia[0][1], RGB(0, 255, 0));
			gdi.DrawBitmap(fuego[ff[1] + f], (int)magia[1][0], (int)magia[1][1], RGB(0, 255, 0));

			if (bol > 3)
				bol = 0;

			if (IA == 3)
			{
				for (int i = 0;i < 4;i++)
				{
					gdi.DrawBitmap(bolon[bol], (int)bola[i][0], (int)bola[i][1], RGB(0, 255, 0));
				}
			}

			if (exp == true)
			{
				if (k > 4 && k < 12)
				{
					gdi.DrawBitmap(explo[k - 5], (int)axB, (int)ayB, RGB(0, 255, 0));
				}
			}

			gdi.DrawBitmap(inicio[13], 0, 0, RGB(0, 255, 0));
		}

		break;
	case 3:	//..........................................OPCIONES..........................................

		//gdi.FillRect(rect, brush3);					//guia

		break;
	}
	
	
	// /*____________________________________________ Display FPS
	wchar_t text[32];
	_snwprintf_s(text, 32, _TRUNCATE, L"%d", framesPerSecond);
	gdi.TextOut(0, 0, text);

	return true; // return false to stop
}

void Almas::Window_Size(Win::Event& e)
{
	Game::Window::Window_Size(e);
	this->width = 960;
	this->height = 512;
	// Use this->width and this->height
}

void Almas::Window_KeyDown(Win::Event& e)
{
	switch (e.wParam)
	{
	case 'X':
		isXPressed = true;
		break;
	case 'Z':
		isZPressed = true;
		break;
	case 'C':
		isCPressed = true;
		break;
	case VK_UP:
		if (canJump == true)
			isUPressed = true;
		else
			isUPressed = false;
		break;
	case VK_RIGHT:
		isRPressed = true;
		break;
	case VK_LEFT:
		isLPressed = true;
		break;
	case 'P':
		isPPressed = true;
	}
}

void Almas::Window_KeyUp(Win::Event& e)
{
	switch (e.wParam)
	{
	case 'X':
		isXPressed = false;
		repite = xr;
		break;
	case 'Z':
		isZPressed = false;
		repite = zr;
		break;
	case 'C':
		isCPressed = false;
		repite = cr;
		break;
	case VK_UP:
		canJump = true;
		isUPressed = false;
		break;
	case VK_RIGHT:
		isRPressed = false;
		break;
	case VK_LEFT:
		isLPressed = false;
		break;
	case 'P':
		isPPressed = false;
		Prea = 0;
		break;
	}
}

void Almas::Window_Timer(Win::Event& e)
{
	//this->timer.Set(1, 1000); // To set timer 1, call this function outside the timer event
	//this->timer.Kill(1); // To stop timer 1, call this function outside the timer event
	switch(e.wParam)
	{
	case 0: //________ Timer 0
		k++;
		break;
	case 1: //________ Timer 1
		n++;
		break;
	case 2:
		n++;
		break;
	case 3:
		n++;
		break;
	case 4: //________ Timer Vida Boss
		bossCooldown = false;
		break;
	case 5: //________ Timer Vida Player
		playerCooldown = false;
		myPain = false;
		break;
	case 6:
		flicker++;
		break;
	case 7:
		tutoTimer++;
		break;
	case 8:
		f++;
		break;
	case 9:
		bol++;
		break;
	case 10: //________ Timer 10
		a++;
		break;
	case 11: //________ Timer 11
		b++;
		break;
	}
}

void Almas::bt1_Click(Win::Event& e)	//TUTORIAL
{
	pnt = 1;
	Defenestrador(pnt);
	tbx1.SetVisible(true);

	tbx1.Text = L"Bienvenido al modo tutorial de Almas Oscuras";

	x = 448.0f;
	y = AltPnt - AltP - Suelo;

	::PlaySound(MAKEINTRESOURCE(IDR_TUTO), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC | SND_LOOP );

	this->timer.Kill(1);
	this->timer.Kill(2);
	this->timer.Kill(3);
	this->timer.Set(7, 5000);
	this->timer.Set(8, 100);
	this->SetFocus();
}

void Almas::bt2_Click(Win::Event& e)	//JUEGO
{
	pnt = 2;
	x = 0.0f;
	y = AltPnt - AltP - Suelo;

	::PlaySound(MAKEINTRESOURCE(IDR_GAME), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC | SND_LOOP );

	Defenestrador(pnt);
	lc1.SetVisible(true);
	lc2.SetVisible(true);
	lb1.SetVisible(true);

	this->timer.Kill(1);
	this->timer.Kill(2);
	this->timer.Kill(3);
	this->timer.Set(8, 100);
	this->timer.Set(0, 100);

	this->SetFocus();
}

void Almas::bt3_Click(Win::Event& e)	//INFO
{
	this->MessageBox(texto, L"Info", MB_OK | MB_ICONINFORMATION);
	
	this->SetFocus();
}

void Almas::bt4_Click(Win::Event& e)	//SALIR
{
	EndDialog(1);
}

void Almas::bt5_Click(Win::Event& e)	//MENU PRINCIPAL
{
	Pause = false;
	pnt = 0;
	Defenestrador(pnt);
	Catalizador(pnt);
	this->timer.Kill(7);
	this->timer.Kill(8);
	this->timer.Kill(0);
	this->timer.Kill(1);
	this->timer.Kill(2);
	this->timer.Kill(3);

	isShieldActive = true;
	isMoving = false;
	estado = 0;
	repite = 0;
	StaTim = 0;
	orientacion = 0;

	tuto = 0;
	tutoTimer = 0;
	magia[0][0] = 0.0f;		magia[0][1] = -64.0f;
	magia[1][0] = 0.0f;		magia[1][1] = -64.0f;

	xB = 13 * Unity;
	yB = 7 * Unity;

	::PlaySound(MAKEINTRESOURCE(IDR_TITLE), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC | SND_LOOP );

	bL = TbL;
	lc1.LineColor = RGB(0, 112, 158);
	lc1.WarningColor = RGB(0, 112, 158);
	lc1.ErrorColor = RGB(0, 112, 158);
	pL = TpL;
	lc2.LineColor = RGB(0, 255, 0);
	lc2.WarningColor = RGB(0, 255, 0);
	lc2.ErrorColor = RGB(0, 255, 0);

	Desicion = false;
	r = 1;

	this->SetFocus();
}

void Almas::bt6_Click(Win::Event& e)	//VOLVER
{
	Pause = false;
	Defenestrador(pnt);
	this->SetFocus();
}


void Almas::bt7_Click(Win::Event& e)	//MENU PRINCIPAL (MUERTE)
{
	bt7.SetEnabled(false);			bt7.SetVisible(false);
	canPause = true;
	ImDead = false;
	YouDead = false;
	yourPain = false;
	lech = false;
	exp = false;

	//---------------------------------------------------

	Pause = false;
	pnt = 0;
	Defenestrador(pnt);
	Catalizador(pnt);
	this->timer.Kill(7);
	this->timer.Kill(8);
	this->timer.Kill(0);
	this->timer.Kill(1);
	this->timer.Kill(2);
	this->timer.Kill(3);

	isShieldActive = true;
	isMoving = false;
	estado = 0;
	repite = 0;
	StaTim = 0;
	orientacion = 0;

	tuto = 0;
	tutoTimer = 0;
	magia[0][0] = 0.0f;		magia[0][1] = -64.0f;
	magia[1][0] = 0.0f;		magia[1][1] = -64.0f;

	xB = 13 * Unity;
	yB = 7 * Unity;

	::PlaySound(MAKEINTRESOURCE(IDR_TITLE), Win::Module::GetInstance(), SND_RESOURCE | SND_ASYNC | SND_LOOP );

	bL = TbL;
	lc1.LineColor = RGB(0, 112, 244);
	lc1.WarningColor = RGB(0, 112, 244);
	lc1.ErrorColor = RGB(0, 112, 244);
	pL = TpL;
	lc2.LineColor = RGB(0, 255, 0);
	lc2.WarningColor = RGB(0, 255, 0);
	lc2.ErrorColor = RGB(0, 255, 0);

	Desicion = false;
	r = 1;

	this->SetFocus();
}

void Almas::bt1_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt1.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void Almas::bt2_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt2.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void Almas::bt3_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt3.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void Almas::bt4_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt4.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void Almas::bt5_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt5.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void Almas::bt6_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt6.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

void Almas::bt7_DrawItem(Win::Event& e)
{
	DRAWITEMSTRUCT * pDrawItem = (DRAWITEMSTRUCT *)e.lParam;
	bt7.DrawButton(pDrawItem);
	e.returnValue = TRUE; 
}

