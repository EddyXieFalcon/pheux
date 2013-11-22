#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <exception>
#include <memory>

#include "Poco/DateTime.h"
#include "Poco/Timespan.h"
#include "Poco/Format.h"
#include "Poco/AutoPtr.h"
//#include "Poco/Thread.h"

#include "Converter.h"
#include "Logger.h"


using std::string;
using std::vector;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::cin;

//typedef Poco::DateTime DateTime;
//typedef Poco::Timespan Timespan;

//#define ADDR        "tcp://ctpmn1-front1.citicsf.com:51205"
//#define    BROKER        "1017"
//#define USER        "00000069"
//#define PASSWORD    "123456"
//#define INSTRUMENT    "cu1305"
#define ADDR_MD "tcp://27.17.62.149:40213"
#define ADDR_TREDE "tcp://27.17.62.149:40205"
#define BROKER "1035"
#define USER "00000033"
#define PASSWORD "123456"
#define INSTRUMENT "cu1305"

#define _MOCK_

#endif
