#ifndef GETCH_H
#define GETCH_H

/*!
 * \file getch.h
 * \brief the getch function
 * \author Franck Daudet
 * \version 1.0
 * \date 07/01/21
 */


//https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux


/**
 * @brief getch
 * @return
 */

int getch(void);

// https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux

/**
 * @brief kbhit
 * @return
 */

bool kbhit();

#endif // GETCH_H
