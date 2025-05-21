#include <iostream>
#include <thread>
#include "../main/main.h"
#include "../driver/driver.h"

void main()
{
	printf("Waiting for game to run...");

	while (GameWnd == 0)
	{
		Sleep(1);
		sofmain1337::process_id = sofmain1337::find_process(L"FortniteClient-Win64-Shipping.exe");
		GameWnd = GetProcWindow(sofmain1337::process_id);
		Sleep(1);
	}

	system("cls");
	printf("We Love SofMain <3");

	if (!input::init())
	{
		printf("The input was not initialized :(");
		Sleep(3000);
		exit(0);
	}

	if (!gui::init())
	{
		printf("The gui was not initialized :("); 
		Sleep(3000);
		exit(0);
	}
	if (!sofmain1337::find_driver())
	{
		printf("The driver was not initialized :("); 
		Sleep(3000);
		exit(0);
	}

	sofmainisud = sofmain1337::find_image();
	auto cr3 = sofmain1337::fetch_cr3();

	if (!sofmain1337::driver_handle)
	{
		printf("The driver couldn't get the base address");
		Sleep(3000);
		exit(0);
	}
	CreateOverlay();
	DirectXInit();
	RenderLoop();

}


