#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#include "DException.h"

std::wstring a2w(const std::string& source);


#define DT_INTERFACE __declspec(dllexport)