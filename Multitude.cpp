//----------------------------------------------------------------------------//
//          *** БИБЛИОТЕКА ЛОГИЧЕСКИХ МАНИПУЛЯЦИЙ НАД МНОЖЕСТВАМИ ***         //
//                                                                            //
// Файл Multitude.cpp                                                         //
//                                                                            //
// Множества интерпретируются как контуры на поверхности Земли (в геодезичес- //
// ких координатах)                                                           //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей                                                      //
//                                                                            //
//                                                                     Москва //
//----------------------------------------------------------------------------//


#include "Multitude.h"


TMultitude::TMultitude()
{
  //--- ИНИЦИАЛИЗАЦИЯ КОНСТАНТ ---
  CONST_SCALE = 1000000;

  priznak = false;
  FA.clear();
  FB.clear();
  FFirstPolygons.clear();
  FSecondPolygons.clear();
  FResultPolygons.clear();
}


TMultitude::~TMultitude()
{
unsigned int i;
  priznak = false;
  FA.clear();

  for(i=0;i<FB.size();i++)
    FB[i].spot.clear();

  FB.clear();

  for(i=0;i<FFirstPolygons.size();i++)
    FFirstPolygons[i].clear();

  FFirstPolygons.clear();

  for(i=0;i<FSecondPolygons.size();i++)
    FSecondPolygons[i].clear();

  FSecondPolygons.clear();

  for(i=0;i<FResultPolygons.size();i++)
    FResultPolygons[i].clear();

  FResultPolygons.clear();
}


TMultitude::TArraySpot TMultitude::AMinusB(TSpot A, TMultitude::TArraySpot B)
{
unsigned int i, j;
TMultitude::TArraySpot Result;
  CopyData(A, B);
  Execute(ClipperLib::ctDifference, ClipperLib::pftNonZero, ClipperLib::pftNonZero);

  Result.clear();
  Result.resize(FResultPolygons.size());
  for(i=0;i<FResultPolygons.size();i++)
    Result[i].spot.resize(FResultPolygons[i].size());

  for(i=0;i<FResultPolygons.size();i++)
  {
    for(j=0;j<FResultPolygons[i].size();j++)
    {
      Result[i].spot[j].B = static_cast<double>(FResultPolygons[i][j].Y)/static_cast<double>(CONST_SCALE);
      Result[i].spot[j].L = static_cast<double>(FResultPolygons[i][j].X)/static_cast<double>(CONST_SCALE);
    }
  }

  if (priznak == true)
  {
    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
      Result[i].spot[j].L = Result[i].spot[j].L - M_PI/2.0;

    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
    if (Result[i].spot[j].L < 0.0)
      Result[i].spot[j].L = 2.0*M_PI+Result[i].spot[j].L;
  }

  return Result;
}


TMultitude::TArraySpot TMultitude::APlusB(TSpot A, TMultitude::TArraySpot B)
{
unsigned int i, j;
TMultitude::TArraySpot Result;
  CopyData(A, B);
  Execute(ClipperLib::ctUnion, ClipperLib::pftNonZero, ClipperLib::pftNonZero);

  Result.clear();
  Result.resize(FResultPolygons.size());
  for(i=0;i<FResultPolygons.size();i++)
    Result[i].spot.resize(FResultPolygons[i].size());

  for(i=0;i<FResultPolygons.size();i++)
  {
    for(j=0;j<FResultPolygons[i].size();j++)
    {
      Result[i].spot[j].B = static_cast<double>(FResultPolygons[i][j].Y)/static_cast<double>(CONST_SCALE);
      Result[i].spot[j].L = static_cast<double>(FResultPolygons[i][j].X)/static_cast<double>(CONST_SCALE);
    }
  }

  if (priznak == true)
  {
    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
      Result[i].spot[j].L = Result[i].spot[j].L - M_PI/2.0;

    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
    if (Result[i].spot[j].L < 0.0)
      Result[i].spot[j].L = 2.0*M_PI+Result[i].spot[j].L;
  }

  return Result;
}


TMultitude::TArraySpot TMultitude::AIntersectionB(TSpot A, TMultitude::TArraySpot B)
{
unsigned int i, j;
TMultitude::TArraySpot Result;
  CopyData(A, B);
  Execute(ClipperLib::ctIntersection, ClipperLib::pftNonZero, ClipperLib::pftNonZero);

  Result.clear();
  Result.resize(FResultPolygons.size());
  for(i=0;i<FResultPolygons.size();i++)
    Result[i].spot.resize(FResultPolygons[i].size());

  for(i=0;i<FResultPolygons.size();i++)
  {
    for(j=0;j<FResultPolygons[i].size();j++)
    {
      Result[i].spot[j].B = static_cast<double>(FResultPolygons[i][j].Y)/static_cast<double>(CONST_SCALE);
      Result[i].spot[j].L = static_cast<double>(FResultPolygons[i][j].X)/static_cast<double>(CONST_SCALE);
    }
  }

  if (priznak == true)
  {
    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
      Result[i].spot[j].L = Result[i].spot[j].L - M_PI/2.0;

    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
    if (Result[i].spot[j].L < 0.0)
      Result[i].spot[j].L = 2.0*M_PI+Result[i].spot[j].L;
  }

  return Result;
}


TMultitude::TArraySpot TMultitude::AXorB(TSpot A, TMultitude::TArraySpot B)
{
unsigned int i, j;
TMultitude::TArraySpot Result;
  CopyData(A, B);
  Execute(ClipperLib::ctXor, ClipperLib::pftNonZero, ClipperLib::pftNonZero);

  Result.clear();
  Result.resize(FResultPolygons.size());
  for(i=0;i<FResultPolygons.size();i++)
    Result[i].spot.resize(FResultPolygons[i].size());

  for(i=0;i<FResultPolygons.size();i++)
  {
    for(j=0;j<FResultPolygons[i].size();j++)
    {
      Result[i].spot[j].B = static_cast<double>(FResultPolygons[i][j].Y)/static_cast<double>(CONST_SCALE);
      Result[i].spot[j].L = static_cast<double>(FResultPolygons[i][j].X)/static_cast<double>(CONST_SCALE);
    }
  }

  if (priznak == true)
  {
    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
      Result[i].spot[j].L = Result[i].spot[j].L - M_PI/2.0;

    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
    if (Result[i].spot[j].L < 0.0)
      Result[i].spot[j].L = 2.0*M_PI+Result[i].spot[j].L;
  }

  return Result;
}


int TMultitude::AHoldB(TSpot A, TSpot B)
{
int res;
unsigned int j, k;
bool pr1;
TSpot FA, FB;
std::vector<bool> r;
TOnePoint Point;

  FA.clear();
  FB.clear();
  r.clear();
  //Очистил все массивы

  FA.resize(A.size());
  for(j=0;j<A.size();j++)
  {
    FA[j].B = A[j].B;
    FA[j].L = A[j].L;
  }

  FB.resize(B.size());
  for(j=0;j<B.size();j++)
  {
    FB[j].B = B[j].B;
    FB[j].L = B[j].L;
  }

  priznak = false;
  //Если хотя бы один абрис пересекает нулевой меридиан, тогда это вырожденный случай и его надо обработать отдельно

  for(j=0;j<FA.size()-1;j++)
    if (fabs(FA[j].L-FA[j+1].L) >= M_PI)
      priznak = true;

  for(j=0;j<FB.size()-1;j++)
    if (fabs(FB[j].L-FB[j+1].L) >= M_PI)
      priznak = true;

  if (priznak == false)
  {
    pr1 = false;

    for(j=0;j<FA.size();j++)
      if (FA[j].L < 0.0)
        pr1 = true;

    for(j=0;j<FB.size();j++)
      if (FB[j].L < 0.0)
        pr1 = true;

    if (pr1 == true)
      priznak = true;
  }

  if (priznak == true)
  {  //Виртуально сдвигаю абрисы, чтобы не мучиться с переходами через 0 меридиан
    for(j=0;j<FA.size();j++)
      if (FA[j].L > M_PI)
        FA[j].L = -1.0*(2.0*M_PI-FA[j].L);

    for(j=0;j<FA.size();j++)
      FA[j].L = FA[j].L + M_PI/2.0;

    for(j=0;j<FB.size();j++)
      if (FB[j].L > M_PI)
        FB[j].L = -1.0*(2.0*M_PI-FB[j].L);

    for(j=0;j<FB.size();j++)
        FB[j].L = FB[j].L + M_PI/2.0;
  }

  r.resize(FB.size());

  if ((fabs(FA[0].B - FA[FA.size()-1].B) > 0.000001) || (fabs(FA[0].L - FA[FA.size()-1].L) > 0.000001))
  {  //Проверка контура на замыкание. Если первая точка контура не равна последней, тогда вставка замыкающей точки
    Point.B = FA[0].B;
    Point.L = FA[0].L;
    FA.push_back(Point);
  }

  for(j=0;j<FB.size();j++)
    r[j] = PointInAnyPolygon(FB[j], FA);

  k=0;
  for(j=0;j<r.size();j++)
  if (r[j] == true)
    k=k+1;

  res = 2;

  if (k == 0)
    res = 0;

  if (k == r.size())
    res = 1;

  FA.clear();
  FB.clear();
  r.clear();
  return res;
}


double TMultitude::MiddleL(TSpot A)
{
unsigned int j;
bool pr1;
TSpot FA;
double res, MinL, MaxL;

  FA.clear();
  //Очистил массив

  FA.resize(A.size());
  for(j=0;j<A.size();j++)
  {
    FA[j].B = A[j].B;
    FA[j].L = A[j].L;
  }

  priznak = false;
  //Если абрис пересекает нулевой меридиан, тогда это вырожденный случай и его надо обработать отдельно

  for(j=0;j<FA.size()-1;j++)
    if (fabs(FA[j].L-FA[j+1].L) >= M_PI)
      priznak = true;

  if (priznak == false)
  {
    pr1 = false;

    for(j=0;j<FA.size();j++)
      if (FA[j].L < 0.0)
        pr1 = true;

    if (pr1 == true)
      priznak = true;
  }

  if (priznak == true)
  {  //Виртуально сдвигаю абрис, чтобы не мучиться с переходами через 0 меридиан
    for(j=0;j<FA.size();j++)
      if (FA[j].L > M_PI)
        FA[j].L = -1.0*(2.0*M_PI-FA[j].L);

    for(j=0;j<FA.size();j++)
      FA[j].L = FA[j].L + M_PI/2.0;
  }

  MinL = 100.0;
  MaxL = -100.0;

  for(j=0;j<FA.size();j++)
  {
    MinL = std::min(MinL, FA[j].L);
    MaxL = std::max(MaxL, FA[j].L);
  }

  res = MinL+(MaxL-MinL)/2.0;

  if (priznak == true)
  {
    res = res - M_PI/2.0;

    if (res < 0.0)
      res = 2.0*M_PI+res;
  }

  FA.clear();
  return res;
}


TMultitude::TArraySpot TMultitude::DivideA(double L, TSpot A)
{
TMultitude::TArraySpot Result, ResultLeft, ResultRight, Left, Right;
const double Epsilon = 0.000001;
unsigned int i;

  if (L > M_PI)
    L = L - 2.0*M_PI;
  //Привел L к одному диапазону, что и нижеприведенные константы, определяющие границы двух полупространств

  Result.clear();
  ResultLeft.clear();
  ResultRight.clear();
  Left.clear();
  Right.clear();

  //Левое полупространство геодезических координат
  Left.resize(1);
  Left[0].spot.resize(4);

  Left[0].spot[0].B = -90.0*M_PI/180.0+Epsilon;
  Left[0].spot[0].L = -180.0*M_PI/180.0+Epsilon;

  Left[0].spot[1].B = 90.0*M_PI/180.0-Epsilon;
  Left[0].spot[1].L = -180.0*M_PI/180.0+Epsilon;

  Left[0].spot[2].B = 90.0*M_PI/180.0-Epsilon;
  Left[0].spot[2].L = L;

  Left[0].spot[3].B = -90.0*M_PI/180.0+Epsilon;
  Left[0].spot[3].L = L;

  //Правое полупространство геодезических координат
  Right.resize(1);
  Right[0].spot.resize(4);

  Right[0].spot[0].B = -90.0*M_PI/180.0+Epsilon;
  Right[0].spot[0].L = L;

  Right[0].spot[1].B = 90.0*M_PI/180.0-Epsilon;
  Right[0].spot[1].L = L;

  Right[0].spot[2].B = 90.0*M_PI/180.0-Epsilon;
  Right[0].spot[2].L = 180.0*M_PI/180.0-Epsilon;

  Right[0].spot[3].B = -90.0*M_PI/180.0+Epsilon;
  Right[0].spot[3].L = 180.0*M_PI/180.0-Epsilon;

  //Пересекаю исходное множество с каждым полупространством
  ResultLeft = AIntersectionB(A, Left);
  ResultRight = AIntersectionB(A, Right);

  for(i=0;i<ResultLeft.size();i++)
    Result.push_back(ResultLeft[i]);

  for(i=0;i<ResultRight.size();i++)
    Result.push_back(ResultRight[i]);

  Left.clear();
  Right.clear();
  ResultLeft.clear();
  ResultRight.clear();

  return Result;
}


TMultitude::TArraySpot TMultitude::AMinusBSimpleResult(TSpot A, TSpot B)
{
int hold;
TMultitude::TArraySpot Result, ResultI, AA, BB;
unsigned int i, j;
double L;

  Result.clear();
  ResultI.clear();
  AA.clear();
  BB.clear();

  BB.resize(1);
  BB[0].spot.resize(B.size());
  for(i=0;i<B.size();i++)
  {
    BB[0].spot[i].B = B[i].B;
    BB[0].spot[i].L = B[i].L;
  }

  hold = AHoldB(A, B);
  switch (hold)
  {
    // множество B целиком лежит вне множества A
    case 0:
      Result = AMinusB(A, BB);
    break;

    // множество B входит в A целиком
    case 1:
      L = MiddleL(B);
      AA = DivideA(L, A);
      for(i=0;i<AA.size();i++)
      {
        ResultI = AMinusB(AA[i].spot, BB);

        for(j=0;j<ResultI.size();j++)
          Result.push_back(ResultI[j]);
      }
    break;

    // множество B пересекает множество A (часть B лежит внутри A, часть B лежит вне множества A)
    case 2:
      Result = AMinusB(A, BB);
    break;
  }

  ResultI.clear();
  AA.clear();
  BB.clear();
  return Result;
}


TMultitude::TArraySpot TMultitude::AMinusBSimpleResult(TSpot A, TMultitude::TArraySpot B)
{
TMultitude::TArraySpot Result, dummy;
unsigned int i, j, k;
  Result.clear();
  if (B.size() >= 1)
  {
    Result = AMinusBSimpleResult(A, B[0].spot);

    for(i=1;i<B.size();i++)
    {
      dummy = AMinusBSimpleResult(Result, B[i].spot);
      Result.clear();
      Result.resize(dummy.size());
      for(j=0;j<Result.size();j++)
      {
        Result[j].spot.clear();
        Result[j].spot.resize(dummy[j].spot.size());
        for(k=0;k<Result[j].spot.size();k++)
        {
          Result[j].spot[k].B = dummy[j].spot[k].B;
          Result[j].spot[k].L = dummy[j].spot[k].L;
        }
      }
      dummy.clear();
    }
  }
  else
  {
    Result.resize(1);
    Result[0].spot.clear();
    Result[0].spot.resize(A.size());
    for(i=0;i<A.size();i++)
    {
      Result[0].spot[i].B = A[i].B;
      Result[0].spot[i].L = A[i].L;
    }
  }
  dummy.clear();
  return Result;
}


TMultitude::TArraySpot TMultitude::AMinusBSimpleResult(TMultitude::TArraySpot A, TMultitude::TArraySpot B)
{
unsigned int i, j;
TMultitude::TArraySpot Result, C;
  Result.clear();

  for(i=0;i<A.size();i++)
  {
    C = AMinusBSimpleResult(A[i].spot, B);
    for(j=0;j<C.size();j++)
      Result.push_back(C[j]);
  }

  C.clear();
  return Result;
}


TMultitude::TArraySpot TMultitude::APlusBSimpleResult(TSpot A, TSpot B)
{
unsigned int i, j;
TMultitude::TArraySpot Result, BB1, BB2;
std::vector<bool> WhatOrientation;
  WhatOrientation.clear();
  BB1.clear();
  BB1.resize(1);
  BB1[0].spot.clear();
  BB1[0].spot.resize(B.size());
  for(i=0;i<B.size();i++)
  {
    BB1[0].spot[i].B = B[i].B;
    BB1[0].spot[i].L = B[i].L;
  }

  CopyData(A, BB1);
  Execute(ClipperLib::ctUnion, ClipperLib::pftNonZero, ClipperLib::pftNonZero);
  //Сложил контуры как в методе APlusB

  WhatOrientation.resize(FResultPolygons.size());

  for(i=0;i<FResultPolygons.size();i++)
    WhatOrientation[i] = ClipperLib::Orientation(FResultPolygons[i]);
  //Среди массива полученных контуров выделил "положительные" и "отрицательные" контуры.
  //Отрицательные контуры описывают "дырки" в полученном по итогам сложения множестве

  Result.clear();
  Result.resize(FResultPolygons.size());
  for(i=0;i<FResultPolygons.size();i++)
    Result[i].spot.resize(FResultPolygons[i].size());

  for(i=0;i<FResultPolygons.size();i++)
  {
    for(j=0;j<FResultPolygons[i].size();j++)
    {
      Result[i].spot[j].B = static_cast<double>(FResultPolygons[i][j].Y)/static_cast<double>(CONST_SCALE);
      Result[i].spot[j].L = static_cast<double>(FResultPolygons[i][j].X)/static_cast<double>(CONST_SCALE);
    }
  }

  if (priznak == true)
  {
    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
      Result[i].spot[j].L = Result[i].spot[j].L - M_PI/2.0;

    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
    if (Result[i].spot[j].L < 0.0)
      Result[i].spot[j].L = 2.0*M_PI+Result[i].spot[j].L;
  }
  //Получил результаты сложения в выходном массиве Result так, как это делается в методе APlusB

  BB1.clear();
  BB2.clear();

  for(i=0;i<Result.size();i++)
  if (WhatOrientation[i] == true)
  {
    BB1.push_back(Result[i]);
  }
  else
  {
    BB2.push_back(Result[i]);
  }
  //Массив BB1 содержит "положительные" контуры
  //Массив BB2 содержит "отрицательные" контуры (дырки)

  if (BB2.size() >= 1)
    Result = AMinusBSimpleResult(BB1, BB2);
  //Если массив "дырок" не пустой, тогда из "положительных" контуров корректно вычел все "отрицательные" и
  // получил результирующий массив контуров

  WhatOrientation.clear();
  BB1.clear();
  BB2.clear();
  return Result;
}


TMultitude::TArraySpot TMultitude::APlusASimpleResult(TMultitude::TArraySpot A)
{
unsigned int i, j;
TMultitude::TArraySpot Result, BB1, BB2;
std::vector<bool> WhatOrientation;
  WhatOrientation.clear();

  CopyData(A[0].spot, A);
  Execute(ClipperLib::ctUnion, ClipperLib::pftNonZero, ClipperLib::pftNonZero);
  //Сложил контуры как в методе APlusB

  WhatOrientation.resize(FResultPolygons.size());

  for(i=0;i<FResultPolygons.size();i++)
    WhatOrientation[i] = ClipperLib::Orientation(FResultPolygons[i]);
  //Среди массива полученных контуров выделил "положительные" и "отрицательные" контуры.
  //Отрицательные контуры описывают "дырки" в полученном по итогам сложения множестве

  Result.clear();
  Result.resize(FResultPolygons.size());
  for(i=0;i<FResultPolygons.size();i++)
    Result[i].spot.resize(FResultPolygons[i].size());

  for(i=0;i<FResultPolygons.size();i++)
  {
    for(j=0;j<FResultPolygons[i].size();j++)
    {
      Result[i].spot[j].B = static_cast<double>(FResultPolygons[i][j].Y)/static_cast<double>(CONST_SCALE);
      Result[i].spot[j].L = static_cast<double>(FResultPolygons[i][j].X)/static_cast<double>(CONST_SCALE);
    }
  }

  if (priznak == true)
  {
    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
      Result[i].spot[j].L = Result[i].spot[j].L - M_PI/2.0;

    for(i=0;i<Result.size();i++)
    for(j=0;j<Result[i].spot.size();j++)
    if (Result[i].spot[j].L < 0.0)
      Result[i].spot[j].L = 2.0*M_PI+Result[i].spot[j].L;
  }
  //Получил результаты сложения в выходном массиве Result так, как это делается в методе APlusB

  BB1.clear();
  BB2.clear();

  for(i=0;i<Result.size();i++)
  if (WhatOrientation[i] == true)
  {
    BB1.push_back(Result[i]);
  }
  else
  {
    BB2.push_back(Result[i]);
  }
  //Массив BB1 содержит "положительные" контуры
  //Массив BB2 содержит "отрицательные" контуры (дырки)

  if (BB2.size() >= 1)
    Result = AMinusBSimpleResult(BB1, BB2);
  //Если массив "дырок" не пустой, тогда из "положительных" контуров корректно вычел все "отрицательные" и
  // получил результирующий массив контуров

  WhatOrientation.clear();
  BB1.clear();
  BB2.clear();
  return Result;
}


double TMultitude::ArcCos(double Value)
{
double F;
  try
  {
    if (Value <= -1.0) Value = -1.0;
    if (Value >= 1.0) Value = 1.0;
    F = acos(Value);
  }
  catch(...)
  {
    F = 0.0;
  }
return F;
}


void TMultitude::CopyData(TSpot A, TMultitude::TArraySpot B)
{
unsigned int i, j;
bool pr1;

  FA.clear();

  for(i=0;i<FB.size();i++)
    FB[i].spot.clear();

  FB.clear();

  for(i=0;i<FFirstPolygons.size();i++)
    FFirstPolygons[i].clear();

  FFirstPolygons.clear();

  for(i=0;i<FSecondPolygons.size();i++)
    FSecondPolygons[i].clear();

  FSecondPolygons.clear();

  for(i=0;i<FResultPolygons.size();i++)
    FResultPolygons[i].clear();

  FResultPolygons.clear();
  //Очистил все массивы

  FA.resize(A.size());
  for(i=0;i<A.size();i++)
  {
    FA[i].B = A[i].B;
    FA[i].L = A[i].L;
  }

  FB.resize(B.size());
  for(i=0; i<FB.size(); i++)
    FB[i].spot.resize(B[i].spot.size());

  for(i=0; i<FB.size(); i++)
  for(j=0; j<FB[i].spot.size(); j++)
  {
    FB[i].spot[j].B = B[i].spot[j].B;
    FB[i].spot[j].L = B[i].spot[j].L;
  }

  priznak = false;
  //Если хотя бы один абрис пересекает нулевой меридиан, тогда это вырожденный случай и его надо обработать отдельно

  for(j=0;j<FA.size()-1;j++)
    if (fabs(FA[j].L-FA[j+1].L) >= M_PI)
      priznak = true;

  for(i=0;i<FB.size();i++)
  for(j=0;j<FB[i].spot.size()-1;j++)
    if (fabs(FB[i].spot[j].L-FB[i].spot[j+1].L) >= M_PI)
      priznak = true;

  if (priznak == false)
  {
    pr1 = false;

    for(j=0;j<FA.size();j++)
      if (FA[j].L < 0.0)
        pr1 = true;

    for(i=0;i<FB.size();i++)
    for(j=0;j<FB[i].spot.size();j++)
      if (FB[i].spot[j].L < 0.0)
        pr1 = true;

    if (pr1 == true)
      priznak = true;
  }

  if (priznak == true)
  {
    //Виртуально сдвигаю абрисы, чтобы не мучиться с переходами через 0 меридиан

    for(j=0;j<FA.size();j++)
      if (FA[j].L > M_PI)
        FA[j].L = -1.0*(2.0*M_PI-FA[j].L);

    for(j=0;j<FA.size();j++)
      FA[j].L = FA[j].L + M_PI/2.0;

    for(i=0;i<FB.size();i++)
    {
      for(j=0;j<FB[i].spot.size();j++)
        if (FB[i].spot[j].L > M_PI)
          FB[i].spot[j].L = -1.0*(2.0*M_PI-FB[i].spot[j].L);

      for(j=0;j<FB[i].spot.size();j++)
        FB[i].spot[j].L = FB[i].spot[j].L + M_PI/2.0;
    }
  }

  FFirstPolygons.resize(1);
  FFirstPolygons[0].resize(FA.size());

  for(j=0;j<FA.size();j++)
    FFirstPolygons[0][j] = ClipperLib::IntPoint(static_cast<int>(floor(CONST_SCALE*FA[j].L + 0.5)),
                                                static_cast<int>(floor(CONST_SCALE*FA[j].B + 0.5)));

  FSecondPolygons.resize(FB.size());
  for(i=0;i<FSecondPolygons.size();i++)
    FSecondPolygons[i].resize(FB[i].spot.size());

  for(i=0;i<FB.size();i++)
  {
    for(j=0;j<FB[i].spot.size();j++)
      FSecondPolygons[i][j] = ClipperLib::IntPoint(static_cast<int>(floor(CONST_SCALE*FB[i].spot[j].L + 0.5)),
                                                   static_cast<int>(floor(CONST_SCALE*FB[i].spot[j].B + 0.5)));
  }
}


void TMultitude::Execute(ClipperLib::ClipType clipType, ClipperLib::PolyFillType subjFillType, ClipperLib::PolyFillType clipFillType)
{
ClipperLib::PolyType lFirstType, lSecondType;
ClipperLib::Clipper* _Clipper;

  _Clipper = new ClipperLib::Clipper();

  lFirstType = ClipperLib::ptSubject;
  lSecondType = ClipperLib::ptClip;

  _Clipper->AddPaths(FFirstPolygons, lFirstType, true);
  _Clipper->AddPaths(FSecondPolygons, lSecondType, true);
  _Clipper->Execute(clipType, FResultPolygons, subjFillType, clipFillType);

  delete _Clipper;
}


double TMultitude::AngleBetweenVectors(TVector vA, TVector vB)
{
double res;
TVector v;
  try
  {
    v = vA^vB;
    res = TMultitude::ArcCos(vA*vB/(vA.getModul()*vB.getModul()));
    res = fabs(res);

    if (v.z <= 0)
      res = -1.0 * res;
  }
  catch(...)
  {
    res = 0.0;
  }
return res;
}


bool TMultitude::PointInAnyPolygon(TOnePoint Point, TSpot Spot)
{
const double Epsilon = 0.000001;
const double MATCH_FACTOR = 0.99;
unsigned int i;
double Angle;
TVector vA, vB;
bool Result;
  //Просматриваем все вершины. Получим вектор от точки до текущей вершины: вычитаем вектор точки из вектора текущей вершины.
  // Аналогично получим вектор от точки до следующей вершины. Затем находим угол между этими векторами (со знаком) и добавляем
  // его к текущему углу Angle. Нетрудно доказать, что после просмотра всех вершин значение Angle будет равно 2*pi (360 градусов)
  // только в том случае, если точка находится внутри полигона. В силу неточностей вычислений с плавающей точкой может быть, что
  // угол будет равен (2*pi – 0.00001), поэтому проверяем, если угол больше либо равен 2*pi*const (константа близкая к единице),
  // возвращаем true, точка находится внутри полигона, иначе возвращаем false.
  try
  {
    Angle = 0.0;

    for (i=0; i<=Spot.size()-1; i++)
    {
      if ((fabs(Point.L - Spot[i].L) <= Epsilon) && (fabs(Point.B - Spot[i].B) <= Epsilon))
      {
        Result = true;
        goto endd;
      }
    }

    for (i=0; i<=Spot.size()-2; i++)
    {
      vA.x = Spot[i].L - Point.L;
      vA.y = Spot[i].B - Point.B;
      vA.z = 0.0;

      vB.x = Spot[i+1].L - Point.L;
      vB.y = Spot[i+1].B - Point.B;
      vB.z = 0.0;

      Angle = Angle + AngleBetweenVectors(vA, vB);
    }

    Angle = fabs(Angle);

    if (Angle >= (MATCH_FACTOR * (2.0 * M_PI)))
      Result = true;
    else
      Result = false;

endd:
    ;
  }
  catch(...)
  {
    Result = false;
  }
  return Result;

}


TMultitude::TArraySpot TMultitude::AMinusBSimpleResult(TMultitude::TArraySpot A, TSpot B)
{
TMultitude::TArraySpot Result, ResultI;
TMultitude::OneSpot one;
unsigned int i, j, k;
  Result.clear();

  for(i=0;i<A.size();i++)
  {
    ResultI = AMinusBSimpleResult(A[i].spot, B);
    if (ResultI.size() >= 1)
    {
      for(j=0;j<ResultI.size();j++)
      {
        one.spot.clear();
        one.spot.resize(ResultI[j].spot.size());
        for(k=0;k<ResultI[j].spot.size();k++)
        {
          one.spot[k].B = ResultI[j].spot[k].B;
          one.spot[k].L = ResultI[j].spot[k].L;
        }
        Result.push_back(one);
      }
    }
  }
  ResultI.clear();
  one.spot.clear();
  return Result;
}
