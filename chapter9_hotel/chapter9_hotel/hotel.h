//
//  hotel.h
//  chapter9_hotel
//
//  Created by пупсик on 28.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISNOUNT 0.95
#define STARS "****************************************"


#ifndef hotel_h
#define hotel_h

//отображает список возможны вариантов
int menu(void);

//возвращает количество суток на которые бранируется номер
int getnights(void);

//вычисляет стоимость в зависимости от расценок и количества забронированных суток и отображает результат
void showprice(double rate, int nights);

#endif /* hotel_h */
