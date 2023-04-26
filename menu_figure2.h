#pragma once

#include "figure2/figure2.h"

#include <iostream>
#include <conio.h>
#include <cstdio>

namespace menu
{
	void text_menu();
	int get_key();

	figure2::Figure create_figure();
}