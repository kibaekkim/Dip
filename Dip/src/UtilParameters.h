//===========================================================================//
// This file is part of the DIP Solver Framework.                            //
//                                                                           //
// DIP is distributed under the Eclipse Public License as part of the        //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Author: Matthew Galati, SAS Institute Inc. (matthew.galati@sas.com)       //
//                                                                           //
// Conceptual Design: Matthew Galati, SAS Institute Inc.                     //
//                    Ted Ralphs, Lehigh University                          //
//                                                                           //
// Copyright (C) 2002-2009, Lehigh University, Matthew Galati, Ted Ralphs    //
// All Rights Reserved.                                                      //
//===========================================================================//

#ifndef UTIL_PARAMETERS_INCLUDED
#define UTIL_PARAMETERS_INCLUDED

//===========================================================================//
#include <map>
#include <string>
#include <fstream>
using namespace std;

//===========================================================================//
struct UtilParamT {
   //bad name for this string, really valueStr?
   string paramName;
   bool   isUsed;        //is used in code (a call to getSetting)?
};
typedef struct UtilParamT UtilParam;

//===========================================================================//
class UtilParameters 
{
private:
   map<string, UtilParam> m_paramMap;
    
public:
   UtilParameters() 
      : m_paramMap() {}

   UtilParameters(int  & argc, 
                  char * argv[]) :
      m_paramMap()
   {
      ScanCmdLineArgs(argc, argv);
   };

   ~UtilParameters() {};

   void ScanCmdLineArgs(int  & argc, 
                        char * argv[]);
   void   LoadParamFile(string & paramFileName);
   void   Add(string & section, 
              string & name, 
              string & value);
   void   Add(const char * section, 
              const char * name, 
              const char * value);
   string GetSetting(const char * name,
                     const char * defaultValue,
                     const char * section = NULL);
   int    GetSetting(const char * name,
                     const int    defaultValue,
                     const char * section = NULL);
   bool   GetSetting(const char * name,
                     const bool   defaultValue,
                     const char * section = NULL);
   long   GetSetting(const char * name,
                     const long   defaultValue,
                     const char * section = NULL);
   double GetSetting(const char * name,
                     const double defaultValue,
                     const char * section = NULL);
    
private:
   UtilParam * FindEntry(const char * section, 
                         const char * name);
   string    * Find(const char * section, 
                    const char * name);
};

#endif
