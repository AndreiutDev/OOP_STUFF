#include "MedikamentUI.h"
#include "MedikamentController.h"
#include "MedikamentDomain.h"
#include "MedikamentRepo.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

#include "../Lab04Test/pch.h"
int main(void)
{
	MedikamentUI menu = MedikamentUI();
	menu.main_menu();
}